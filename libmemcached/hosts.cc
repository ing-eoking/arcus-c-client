/*
 * arcus-c-client : Arcus C client
 * Copyright 2010-2014 NAVER Corp.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
/*  vim:expandtab:shiftwidth=2:tabstop=2:smarttab:
 * 
 *  Libmemcached library
 *
 *  Copyright (C) 2011 Data Differential, http://datadifferential.com/
 *  Copyright (C) 2006-2010 Brian Aker All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are
 *  met:
 *
 *      * Redistributions of source code must retain the above copyright
 *  notice, this list of conditions and the following disclaimer.
 *
 *      * Redistributions in binary form must reproduce the above
 *  copyright notice, this list of conditions and the following disclaimer
 *  in the documentation and/or other materials provided with the
 *  distribution.
 *
 *      * The names of its contributors may not be used to endorse or
 *  promote products derived from this software without specific prior
 *  written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <libmemcached/common.h>

#include <cmath>
#include <sys/time.h>

/* Protoypes (static) */
static memcached_return_t update_continuum(memcached_st *ptr);

static int compare_servers(const void *p1, const void *p2)
{
  int return_value;
  memcached_server_instance_st a= (memcached_server_instance_st)p1;
  memcached_server_instance_st b= (memcached_server_instance_st)p2;

#ifdef ENABLE_REPLICATION
  // For 1.7 servers, compare only the group names.
  // hostname contains the group's master server, if any.
  if (a->is_1_7)
    return strcmp(a->groupname, b->groupname);
#endif

  return_value= strcmp(a->hostname, b->hostname);

  if (return_value == 0)
  {
    return_value= (int) (a->port - b->port);
  }

  return return_value;
}

static void sort_hosts(memcached_st *ptr)
{
  if (memcached_server_count(ptr))
  {
    memcached_server_write_instance_st instance;

    qsort(memcached_server_list(ptr), memcached_server_count(ptr), sizeof(memcached_server_st), compare_servers);
    instance= memcached_server_instance_fetch(ptr, 0);
    instance->number_of_hosts= memcached_server_count(ptr);
  }
}

#ifdef LIBMEMCACHED_WITH_ZK_INTEGRATION
/** Prune the redundant or not-available servers */
static void prune_hosts(memcached_st *ptr, bool all_flag)
{
  int i;
  int cursor = 0;
  int server_count = memcached_server_count(ptr);

  if (!server_count) return;

  if (all_flag) {
    memcached_servers_reset(ptr);
    server_count = 0;
  }

  for (i=0; i<server_count; i++) {
    if (ptr->servers[i].options.is_dead || all_flag) {
      /* free the dead servers. */
      //memcached_server_free(&ptr->servers[i]);
      __server_free(&ptr->servers[i]);
    } else {
      /* If this server is not dead and there's free space ahead,
       * move it there. */
      if (cursor < i) {
        /* !!! Need to adjust read_ptr !!! */
        int offset = -1;
        if (ptr->servers[i].read_ptr) {
            offset = ptr->servers[i].read_ptr - ptr->servers[i].read_buffer;
        }
        ptr->servers[cursor] = ptr->servers[i];
        if (offset == -1) {
            ptr->servers[cursor].read_ptr = NULL;  
        } else {
            ptr->servers[cursor].read_ptr = &ptr->servers[cursor].read_buffer[offset];
        }
      }
      cursor++;
    }
  }

  /* Change the number of hosts. */
  for (i=0; i<cursor; i++) {
    ptr->servers[i].number_of_hosts = cursor;
  }
  ptr->number_of_hosts = cursor;
}
#endif

memcached_return_t run_distribution(memcached_st *ptr)
{
  if (ptr->flags.use_sort_hosts)
  {
    sort_hosts(ptr);
  }

  switch (ptr->distribution)
  {
  case MEMCACHED_DISTRIBUTION_CONSISTENT:
  case MEMCACHED_DISTRIBUTION_CONSISTENT_KETAMA:
  case MEMCACHED_DISTRIBUTION_CONSISTENT_KETAMA_SPY:
  case MEMCACHED_DISTRIBUTION_CONSISTENT_WEIGHTED:
    return update_continuum(ptr);

  case MEMCACHED_DISTRIBUTION_VIRTUAL_BUCKET:
  case MEMCACHED_DISTRIBUTION_MODULA:
    break;

  case MEMCACHED_DISTRIBUTION_RANDOM:
    srandom((uint32_t) time(NULL));
    break;

  case MEMCACHED_DISTRIBUTION_CONSISTENT_MAX:
  default:
    assert_msg(0, "Invalid distribution type passed to run_distribution()");
  }

  return MEMCACHED_SUCCESS;
}

static uint32_t ketama_server_hash(const char *key, size_t key_length, uint32_t alignment)
{
  unsigned char results[16];

  libhashkit_md5_signature((unsigned char*)key, key_length, results);

  return ((uint32_t) (results[3 + alignment * 4] & 0xFF) << 24)
    | ((uint32_t) (results[2 + alignment * 4] & 0xFF) << 16)
    | ((uint32_t) (results[1 + alignment * 4] & 0xFF) << 8)
    | (results[0 + alignment * 4] & 0xFF);
}

static int continuum_item_cmp(const void *t1, const void *t2)
{
  memcached_continuum_item_st *ct1= (memcached_continuum_item_st *)t1;
  memcached_continuum_item_st *ct2= (memcached_continuum_item_st *)t2;

  /* Why 153? Hmmm... */
  WATCHPOINT_ASSERT(ct1->value != 153);
  if (ct1->value == ct2->value)
    return 0;
  else if (ct1->value > ct2->value)
    return 1;
  else
    return -1;
}

static memcached_return_t update_continuum(memcached_st *ptr)
{
  uint32_t continuum_index= 0;
  memcached_server_st *list;
  uint32_t pointer_counter= 0;
  uint32_t pointer_per_server= MEMCACHED_POINTS_PER_SERVER;
  uint32_t pointer_per_hash= 1;
  uint32_t live_servers= 0;
  struct timeval now;

  if (gettimeofday(&now, NULL))
  {
    return memcached_set_errno(*ptr, errno, MEMCACHED_AT);
  }

  list= memcached_server_list(ptr);

  /* count live servers (those without a retry delay set) */
  bool is_auto_ejecting= _is_auto_eject_host(ptr);
  if (is_auto_ejecting)
  {
    live_servers= 0;
    ptr->ketama.next_distribution_rebuild= 0;
    for (uint32_t host_index= 0; host_index < memcached_server_count(ptr); ++host_index)
    {
      if (list[host_index].next_retry <= now.tv_sec)
      {
        live_servers++;
      }
      else
      {
        if (ptr->ketama.next_distribution_rebuild == 0 or list[host_index].next_retry < ptr->ketama.next_distribution_rebuild)
        {
          ptr->ketama.next_distribution_rebuild= list[host_index].next_retry;
        }
      }
    }
  }
  else
  {
    live_servers= memcached_server_count(ptr);
  }

  uint64_t is_ketama_weighted= memcached_behavior_get(ptr, MEMCACHED_BEHAVIOR_KETAMA_WEIGHTED);
  uint32_t points_per_server= (uint32_t) (is_ketama_weighted ? MEMCACHED_POINTS_PER_SERVER_KETAMA : MEMCACHED_POINTS_PER_SERVER);

  if (not live_servers)
  {
    return MEMCACHED_SUCCESS;
  }

  if (live_servers > ptr->ketama.continuum_count)
  {
    memcached_continuum_item_st *new_ptr;

    new_ptr= static_cast<memcached_continuum_item_st*>(libmemcached_realloc(ptr, ptr->ketama.continuum,
                                                                            sizeof(memcached_continuum_item_st) * (live_servers + MEMCACHED_CONTINUUM_ADDITION) * points_per_server));

    if (new_ptr == 0)
    {
      return MEMCACHED_MEMORY_ALLOCATION_FAILURE;
    }

    ptr->ketama.continuum= new_ptr;
    ptr->ketama.continuum_count= live_servers + MEMCACHED_CONTINUUM_ADDITION;
  }

  uint64_t total_weight= 0;
  uint32_t total_server= 0;
  uint32_t first_weight;
  bool all_weights_same= true;
  if (is_ketama_weighted)
  {
    for (uint32_t host_index = 0; host_index < memcached_server_count(ptr); ++host_index)
    {
      if (is_auto_ejecting == false or list[host_index].next_retry <= now.tv_sec)
      {
        total_weight += list[host_index].weight;
        /* Check if all weights are same */
        if ((++total_server) == 1) {
          first_weight = list[host_index].weight;
        } else {
          if (first_weight != list[host_index].weight)
            all_weights_same= false;
        }
      }
    }
  }

  for (uint32_t host_index= 0; host_index < memcached_server_count(ptr); ++host_index)
  {
    if (is_auto_ejecting and list[host_index].next_retry > now.tv_sec)
    {
      continue;
    }

    if (is_ketama_weighted)
    {
        if (all_weights_same) {
          pointer_per_server= MEMCACHED_POINTS_PER_SERVER_KETAMA;
        } else {
          float pct= (float)list[host_index].weight / (float)total_weight;
          pointer_per_server= (uint32_t) ((floor((float) (pct * MEMCACHED_POINTS_PER_SERVER_KETAMA / 4 * (float)live_servers + 0.0000000001))) * 4);
        }
        pointer_per_hash= 4;
        if (DEBUG)
        {
          printf("ketama_weighted:%s|%d|%llu|%u\n",
                 list[host_index].hostname,
                 list[host_index].port,
                 (unsigned long long)list[host_index].weight,
                 pointer_per_server);
        }
    }


    if (ptr->distribution == MEMCACHED_DISTRIBUTION_CONSISTENT_KETAMA_SPY)
    {
      for (uint32_t pointer_index= 0;
           pointer_index < pointer_per_server / pointer_per_hash;
           pointer_index++)
      {
        char sort_host[MEMCACHED_MAX_HOST_SORT_LENGTH]= "";
        int sort_host_length;

#ifdef LIBMEMCACHED_WITH_ZK_INTEGRATION
#ifdef ENABLE_REPLICATION
        if (list[host_index].is_1_7) {
          // For 1.7 clusters, use group names, not host names, appear
          // in the hash ring.
          sort_host_length= snprintf(sort_host, MEMCACHED_MAX_HOST_SORT_LENGTH,
                                     "%s-%u",
                                     list[host_index].groupname,
                                     pointer_index);
        }
        else
#endif
        // Spymemcached ketema key format is: hostname/ip:port-index
        // If hostname is not available then: ip:port-index
        sort_host_length= snprintf(sort_host, MEMCACHED_MAX_HOST_SORT_LENGTH,
                                   "%s:%u-%u",
                                   list[host_index].hostname,
                                   (uint32_t)list[host_index].port,
                                   pointer_index);
#else
        // Spymemcached ketema key format is: hostname/ip:port-index
        // If hostname is not available then: /ip:port-index
        sort_host_length= snprintf(sort_host, MEMCACHED_MAX_HOST_SORT_LENGTH,
                                   "/%s:%u-%u",
                                   list[host_index].hostname,
                                   (uint32_t)list[host_index].port,
                                   pointer_index);
#endif

        if (sort_host_length >= MEMCACHED_MAX_HOST_SORT_LENGTH || sort_host_length < 0)
        {
          return memcached_set_error(*ptr, MEMCACHED_MEMORY_ALLOCATION_FAILURE, MEMCACHED_AT, 
                                     memcached_literal_param("snprintf(MEMCACHED_DEFAULT_COMMAND_SIZE)"));
        }

        if (DEBUG)
        {
          fprintf(stdout, "update_continuum: key is %s\n", sort_host);
        }

        if (is_ketama_weighted)
        {
          for (uint32_t x= 0; x < pointer_per_hash; x++)
          {
            uint32_t value= ketama_server_hash(sort_host, (size_t)sort_host_length, x);
            ptr->ketama.continuum[continuum_index].index= host_index;
            ptr->ketama.continuum[continuum_index++].value= value;
          }
        }
        else
        {
          uint32_t value= hashkit_digest(&ptr->hashkit, sort_host, (size_t)sort_host_length);
          ptr->ketama.continuum[continuum_index].index= host_index;
          ptr->ketama.continuum[continuum_index++].value= value;
        }
      }
    }
    else
    {
#ifdef ENABLE_REPLICATION
      // Arcus does not use this hash.  So do not bother supporting
      // 1.7 group names.
#endif
      for (uint32_t pointer_index= 1;
           pointer_index <= pointer_per_server / pointer_per_hash;
           pointer_index++)
      {
        char sort_host[MEMCACHED_MAX_HOST_SORT_LENGTH]= "";
        int sort_host_length;

        if (list[host_index].port == MEMCACHED_DEFAULT_PORT)
        {
          sort_host_length= snprintf(sort_host, MEMCACHED_MAX_HOST_SORT_LENGTH,
                                     "%s-%u",
                                     list[host_index].hostname,
                                     pointer_index - 1);
        }
        else
        {
          sort_host_length= snprintf(sort_host, MEMCACHED_MAX_HOST_SORT_LENGTH,
                                     "%s:%u-%u",
                                     list[host_index].hostname,
                                     (uint32_t)list[host_index].port,
                                     pointer_index - 1);
        }

        if (sort_host_length >= MEMCACHED_MAX_HOST_SORT_LENGTH || sort_host_length < 0)
        {
          return memcached_set_error(*ptr, MEMCACHED_MEMORY_ALLOCATION_FAILURE, MEMCACHED_AT, 
                                     memcached_literal_param("snprintf(MEMCACHED_DEFAULT_COMMAND_SIZE)"));
        }

        if (is_ketama_weighted)
        {
          for (uint32_t x = 0; x < pointer_per_hash; x++)
          {
            uint32_t value= ketama_server_hash(sort_host, (size_t)sort_host_length, x);
            ptr->ketama.continuum[continuum_index].index= host_index;
            ptr->ketama.continuum[continuum_index++].value= value;
          }
        }
        else
        {
          uint32_t value= hashkit_digest(&ptr->hashkit, sort_host, (size_t)sort_host_length);
          ptr->ketama.continuum[continuum_index].index= host_index;
          ptr->ketama.continuum[continuum_index++].value= value;
        }
      }
    }

    pointer_counter+= pointer_per_server;
  }

  WATCHPOINT_ASSERT(ptr);
  WATCHPOINT_ASSERT(ptr->ketama.continuum);
  WATCHPOINT_ASSERT(memcached_server_count(ptr) * MEMCACHED_POINTS_PER_SERVER <= MEMCACHED_CONTINUUM_SIZE);
  ptr->ketama.continuum_points_counter= pointer_counter;
  qsort(ptr->ketama.continuum, ptr->ketama.continuum_points_counter, sizeof(memcached_continuum_item_st), continuum_item_cmp);

  if (DEBUG)
  {
    for (uint32_t pointer_index= 0; memcached_server_count(ptr) && pointer_index < ((live_servers * MEMCACHED_POINTS_PER_SERVER) - 1); pointer_index++)
    {
      WATCHPOINT_ASSERT(ptr->ketama.continuum[pointer_index].value <= ptr->ketama.continuum[pointer_index + 1].value);
    }
  }
#if 0 /* Print hash continuum */
  if (1) {
    uint32_t pointer_index;
    fprintf(stderr, "update_continuum: node_count=%d hash_count=%d\n",
            live_servers, ptr->ketama.continuum_points_counter);
    for (pointer_index= 0; pointer_index < ptr->ketama.continuum_points_counter; pointer_index++) {
      if (pointer_index > 0 &&
          ptr->ketama.continuum[pointer_index].value <= ptr->ketama.continuum[pointer_index - 1].value) {
          break;
      }
      fprintf(stderr, "continuum[%d]: hash=%08x, server=%s:%d\n",
              pointer_index, ptr->ketama.continuum[pointer_index].value,
              list[ptr->ketama.continuum[pointer_index].index].hostname,
              list[ptr->ketama.continuum[pointer_index].index].port);
    }
    if (pointer_index < ptr->ketama.continuum_points_counter)
        fprintf(stderr, "update_continuum fails.n");
    else
        fprintf(stderr, "update_continuum success.\n");
  }
#endif

  return MEMCACHED_SUCCESS;
}

static memcached_return_t server_add(memcached_st *ptr, 
                                     const memcached_string_t& hostname,
                                     in_port_t port,
                                     uint32_t weight,
                                     memcached_connection_t type)
{
  assert_msg(ptr, "Programmer mistake, somehow server_add() was passed a NULL memcached_st");
  if ( (ptr->flags.use_udp and type != MEMCACHED_CONNECTION_UDP)
      or ( (type == MEMCACHED_CONNECTION_UDP) and (not ptr->flags.use_udp) ) )
  {
    return memcached_set_error(*ptr, MEMCACHED_INVALID_HOST_PROTOCOL, MEMCACHED_AT);
  }

  memcached_server_st *new_host_list= static_cast<memcached_server_st*>(libmemcached_realloc(ptr, memcached_server_list(ptr),
                                                                                             sizeof(memcached_server_st) * (ptr->number_of_hosts + 1)));

  if (not new_host_list)
  {
    return MEMCACHED_MEMORY_ALLOCATION_FAILURE;
  }

  memcached_server_list_set(ptr, new_host_list);

  /* TODO: Check return type */
  memcached_server_write_instance_st instance= memcached_server_instance_fetch(ptr, memcached_server_count(ptr));

#ifdef ENABLE_REPLICATION
  /* Arcus (both 1.6 and 1.7) does not use this function.  So, use a fake
   * groupname.
   */
  memcached_string_t groupname= { memcached_string_make_from_cstr("invalid") };
  if (not __server_create_with(ptr, instance, groupname, hostname, port, weight, type, false))
#else
  if (not __server_create_with(ptr, instance, hostname, port, weight, type))
#endif
  {
    return memcached_set_error(*ptr, MEMCACHED_MEMORY_ALLOCATION_FAILURE, MEMCACHED_AT);
  }

  if (weight > 1)
  {
    ptr->ketama.weighted= true;
  }

  ptr->number_of_hosts++;

  // @note we place the count in the bottom of the server list
  instance= memcached_server_instance_fetch(ptr, 0);
  memcached_servers_set_count(instance, memcached_server_count(ptr));

  return run_distribution(ptr);
}


memcached_return_t memcached_server_push(memcached_st *ptr, const memcached_server_list_st list)
{
  if (not list)
  {
    return MEMCACHED_SUCCESS;
  }

  uint32_t count= memcached_server_list_count(list);

  memcached_server_st *new_host_list;
  new_host_list= static_cast<memcached_server_st*>(libmemcached_realloc(ptr, memcached_server_list(ptr),
									sizeof(memcached_server_st) * (count + memcached_server_count(ptr))));

  if (not new_host_list)
    return MEMCACHED_MEMORY_ALLOCATION_FAILURE;

  memcached_server_list_set(ptr, new_host_list);

  for (uint32_t x= 0; x < count; x++)
  {
    memcached_server_write_instance_st instance;

    if ((ptr->flags.use_udp && list[x].type != MEMCACHED_CONNECTION_UDP)
        or ((list[x].type == MEMCACHED_CONNECTION_UDP) and not (ptr->flags.use_udp)) )
    {
      return MEMCACHED_INVALID_HOST_PROTOCOL;
    }

    WATCHPOINT_ASSERT(list[x].hostname[0] != 0);

    // We have extended the array, and now we will find it, and use it.
    instance= memcached_server_instance_fetch(ptr, memcached_server_count(ptr));
    WATCHPOINT_ASSERT(instance);

    memcached_string_t hostname= { memcached_string_make_from_cstr(list[x].hostname) };
#ifdef ENABLE_REPLICATION
    memcached_string_t groupname= { memcached_string_make_from_cstr(list[x].groupname) };
    if (__server_create_with(ptr, instance,
                             groupname, hostname,
                             list[x].port, list[x].weight, list[x].type,
                             list[x].is_1_7) == NULL)
#else
    if (__server_create_with(ptr, instance, 
                             hostname,
                             list[x].port, list[x].weight, list[x].type) == NULL)
#endif
    {
      return memcached_set_error(*ptr, MEMCACHED_MEMORY_ALLOCATION_FAILURE, MEMCACHED_AT);
    }

    if (list[x].weight > 1)
    {
      ptr->ketama.weighted= true;
    }

    ptr->number_of_hosts++;
  }

  // Provides backwards compatibility with server list.
  {
    memcached_server_write_instance_st instance;
    instance= memcached_server_instance_fetch(ptr, 0);
    instance->number_of_hosts= memcached_server_count(ptr);
  }

  return run_distribution(ptr);
}

#ifdef LIBMEMCACHED_WITH_ZK_INTEGRATION
memcached_return_t memcached_server_push_with_prune(memcached_st *ptr, const memcached_server_list_st list,
                                                    bool prune_flag)
{
  if (list) {
    if (prune_flag)
      prune_hosts(ptr, false);
    return memcached_server_push(ptr, list);
  } else {
    if (prune_flag) {
      prune_hosts(ptr, false);
      return run_distribution(ptr);
    } else {
      /* This case cannot be occurred */
      return MEMCACHED_SUCCESS;
    }
  }
}

memcached_return_t memcached_server_redistribute_with_prune(memcached_st *ptr)
{
  bool prune_all_hosts = true;
  prune_hosts(ptr, prune_all_hosts);
  return run_distribution(ptr);
}
#endif

memcached_return_t memcached_server_add_unix_socket(memcached_st *ptr,
                                                    const char *filename)
{
  return memcached_server_add_unix_socket_with_weight(ptr, filename, 0);
}

memcached_return_t memcached_server_add_unix_socket_with_weight(memcached_st *ptr,
                                                                const char *filename,
                                                                uint32_t weight)
{
  if (ptr == NULL)
  {
    return MEMCACHED_FAILURE;
  }

  memcached_string_t _filename= { memcached_string_make_from_cstr(filename) };
  if (memcached_is_valid_servername(_filename) == false)
  {
    memcached_set_error(*ptr, MEMCACHED_INVALID_ARGUMENTS, MEMCACHED_AT, memcached_literal_param("Invalid filename for socket provided"));
  }

  return server_add(ptr, _filename, 0, weight, MEMCACHED_CONNECTION_UNIX_SOCKET);
}

memcached_return_t memcached_server_add_udp(memcached_st *ptr,
                                            const char *hostname,
                                            in_port_t port)
{
  return memcached_server_add_udp_with_weight(ptr, hostname, port, 0);
}

memcached_return_t memcached_server_add_udp_with_weight(memcached_st *ptr,
                                                        const char *hostname,
                                                        in_port_t port,
                                                        uint32_t weight)
{
  if (ptr == NULL)
  {
    return MEMCACHED_INVALID_ARGUMENTS;
  }

  if (not port)
  {
    port= MEMCACHED_DEFAULT_PORT;
  }

  if (not hostname)
  {
    hostname= "localhost";
  }

  memcached_string_t _hostname= { memcached_string_make_from_cstr(hostname) };
  if (memcached_is_valid_servername(_hostname) == false)
  {
    memcached_set_error(*ptr, MEMCACHED_INVALID_ARGUMENTS, MEMCACHED_AT, memcached_literal_param("Invalid hostname provided"));
  }

  return server_add(ptr, _hostname, port, weight, MEMCACHED_CONNECTION_UDP);
}

memcached_return_t memcached_server_add(memcached_st *ptr,
                                        const char *hostname,
                                        in_port_t port)
{
  return memcached_server_add_with_weight(ptr, hostname, port, 0);
}

memcached_return_t memcached_server_add_with_weight(memcached_st *ptr,
                                                    const char *hostname,
                                                    in_port_t port,
                                                    uint32_t weight)
{
  if (ptr == NULL)
  {
    return MEMCACHED_INVALID_ARGUMENTS;
  }

  if (port == 0)
  {
    port= MEMCACHED_DEFAULT_PORT;
  }

  size_t hostname_length= hostname ? strlen(hostname) : 0;
  if (hostname_length == 0)
  {
    hostname= "localhost";
    hostname_length= sizeof("localhost") -1;
  }

  memcached_string_t _hostname= { hostname, hostname_length };

  if (memcached_is_valid_servername(_hostname) == false)
  {
    return memcached_set_error(*ptr, MEMCACHED_INVALID_ARGUMENTS, MEMCACHED_AT, memcached_literal_param("Invalid hostname provided"));
  }

  return server_add(ptr, _hostname, port, weight, _hostname.c_str[0] == '/' ? MEMCACHED_CONNECTION_UNIX_SOCKET  : MEMCACHED_CONNECTION_TCP);
}

memcached_return_t memcached_server_add_parsed(memcached_st *ptr,
                                               const char *hostname,
                                               size_t hostname_length,
                                               in_port_t port,
                                               uint32_t weight)
{
  char buffer[NI_MAXHOST];

  memcpy(buffer, hostname, hostname_length);
  buffer[hostname_length]= 0;

  memcached_string_t _hostname= { buffer, hostname_length };

  return server_add(ptr, _hostname,
                    port,
                    weight,
                    MEMCACHED_CONNECTION_TCP);
}
