/* A Bison parser, made by GNU Bison 3.8.2.45-25b3d-dirty.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2022 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_CONFIG_PARSER_H_INCLUDED
# define YY_CONFIG_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef CONFIG_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define CONFIG_DEBUG 1
#  else
#   define CONFIG_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define CONFIG_DEBUG 1
# endif /* ! defined YYDEBUG */
#endif  /* ! defined CONFIG_DEBUG */
#if CONFIG_DEBUG
extern int config_debug;
#endif

/* Token kinds.  */
#ifndef CONFIG_TOKENTYPE
# define CONFIG_TOKENTYPE
  enum config_tokentype
  {
    CONFIG_EMPTY = -2,
    CONFIG_EOF = 0,                /* "end of file"  */
    CONFIG_error = 256,            /* error  */
    CONFIG_UNDEF = 257,            /* "invalid token"  */
    COMMENT = 258,                 /* COMMENT  */
    END = 259,                     /* END  */
    CSL_ERROR = 260,               /* CSL_ERROR  */
    RESET = 261,                   /* RESET  */
    PARSER_DEBUG = 262,            /* PARSER_DEBUG  */
    INCLUDE = 263,                 /* INCLUDE  */
    CONFIGURE_FILE = 264,          /* CONFIGURE_FILE  */
    EMPTY_LINE = 265,              /* EMPTY_LINE  */
    SERVER = 266,                  /* SERVER  */
    CSL_SOCKET = 267,              /* CSL_SOCKET  */
    SERVERS = 268,                 /* SERVERS  */
    SERVERS_OPTION = 269,          /* SERVERS_OPTION  */
    UNKNOWN_OPTION = 270,          /* UNKNOWN_OPTION  */
    UNKNOWN = 271,                 /* UNKNOWN  */
    BINARY_PROTOCOL = 272,         /* BINARY_PROTOCOL  */
    BUFFER_REQUESTS = 273,         /* BUFFER_REQUESTS  */
    CONNECT_TIMEOUT = 274,         /* CONNECT_TIMEOUT  */
    DISTRIBUTION = 275,            /* DISTRIBUTION  */
    HASH = 276,                    /* HASH  */
    HASH_WITH_NAMESPACE = 277,     /* HASH_WITH_NAMESPACE  */
    IO_BYTES_WATERMARK = 278,      /* IO_BYTES_WATERMARK  */
    IO_KEY_PREFETCH = 279,         /* IO_KEY_PREFETCH  */
    IO_MSG_WATERMARK = 280,        /* IO_MSG_WATERMARK  */
    KETAMA_HASH = 281,             /* KETAMA_HASH  */
    KETAMA_WEIGHTED = 282,         /* KETAMA_WEIGHTED  */
    NOREPLY = 283,                 /* NOREPLY  */
    NUMBER_OF_REPLICAS = 284,      /* NUMBER_OF_REPLICAS  */
    POLL_TIMEOUT = 285,            /* POLL_TIMEOUT  */
    RANDOMIZE_REPLICA_READ = 286,  /* RANDOMIZE_REPLICA_READ  */
    RCV_TIMEOUT = 287,             /* RCV_TIMEOUT  */
    REMOVE_FAILED_SERVERS = 288,   /* REMOVE_FAILED_SERVERS  */
    RETRY_TIMEOUT = 289,           /* RETRY_TIMEOUT  */
    SND_TIMEOUT = 290,             /* SND_TIMEOUT  */
    SOCKET_RECV_SIZE = 291,        /* SOCKET_RECV_SIZE  */
    SOCKET_SEND_SIZE = 292,        /* SOCKET_SEND_SIZE  */
    SORT_HOSTS = 293,              /* SORT_HOSTS  */
    SUPPORT_CAS = 294,             /* SUPPORT_CAS  */
    USER_DATA = 295,               /* USER_DATA  */
    USE_UDP = 296,                 /* USE_UDP  */
    VERIFY_KEY = 297,              /* VERIFY_KEY  */
    _TCP_KEEPALIVE = 298,          /* _TCP_KEEPALIVE  */
    _TCP_KEEPIDLE = 299,           /* _TCP_KEEPIDLE  */
    _TCP_NODELAY = 300,            /* _TCP_NODELAY  */
    FETCH_VERSION = 301,           /* FETCH_VERSION  */
    NAMESPACE = 302,               /* NAMESPACE  */
    POOL_MIN = 303,                /* POOL_MIN  */
    POOL_MAX = 304,                /* POOL_MAX  */
    MD5 = 305,                     /* MD5  */
    CRC = 306,                     /* CRC  */
    FNV1_64 = 307,                 /* FNV1_64  */
    FNV1A_64 = 308,                /* FNV1A_64  */
    FNV1_32 = 309,                 /* FNV1_32  */
    FNV1A_32 = 310,                /* FNV1A_32  */
    HSIEH = 311,                   /* HSIEH  */
    MURMUR = 312,                  /* MURMUR  */
    JENKINS = 313,                 /* JENKINS  */
    CONSISTENT = 314,              /* CONSISTENT  */
    MODULA = 315,                  /* MODULA  */
    RANDOM = 316,                  /* RANDOM  */
    CSL_TRUE = 317,                /* CSL_TRUE  */
    CSL_FALSE = 318,               /* CSL_FALSE  */
    CSL_FLOAT = 319,               /* CSL_FLOAT  */
    NUMBER = 320,                  /* NUMBER  */
    PORT = 321,                    /* PORT  */
    WEIGHT_START = 322,            /* WEIGHT_START  */
    IPADDRESS = 323,               /* IPADDRESS  */
    HOSTNAME = 324,                /* HOSTNAME  */
    STRING = 325,                  /* STRING  */
    QUOTED_STRING = 326,           /* QUOTED_STRING  */
    FILE_PATH = 327                /* FILE_PATH  */
  };
  typedef enum config_tokentype config_token_kind_t;
#endif

/* Value type.  */




int config_parse (class Context *context, yyscan_t *scanner);


#endif /* !YY_CONFIG_PARSER_H_INCLUDED  */
