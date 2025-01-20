/* A Bison parser, made by GNU Bison 3.8.2.45-25b3d-dirty.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2.45-25b3d-dirty"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Substitute the type names.  */
#define YYSTYPE         CONFIG_STYPE
/* Substitute the variable and function names.  */
#define yyparse         config_parse
#define yylex           config_lex
#define yyerror         config_error
#define yydebug         config_debug
#define yynerrs         config_nerrs

/* First part of user prologue.  */
#line 37 "parser.yy"


#include "libmemcached/csl/common.h"

class Context;

#line 60 "parser.yy"


#include "libmemcached/options.hpp"

#include "libmemcached/csl/context.h"
#include "libmemcached/csl/symbol.h"
#include "libmemcached/csl/scanner.h"

#ifndef __INTEL_COMPILER
# pragma GCC diagnostic ignored "-Wold-style-cast"
#endif

#ifndef __INTEL_COMPILER
# ifndef __clang__
#  pragma GCC diagnostic ignored "-Wlogical-op"
#  pragma GCC diagnostic ignored "-Wunsafe-loop-optimizations"
# endif
#endif

#define select_yychar(__context) yychar == UNKNOWN ? ( (__context)->previous_token == END ? UNKNOWN : (__context)->previous_token ) : yychar

#define stryytname(__yytokentype) ((__yytokentype) <  YYNTOKENS ) ? yytname[(__yytokentype)] : ""

#define parser_abort(__context, __error_message) do { (__context)->abort((__error_message), config_tokentype(select_yychar(__context)), stryytname(YYTRANSLATE(select_yychar(__context)))); YYABORT; } while (0)

// This is bison calling error.
inline void __config_error(Context *context, yyscan_t *scanner, const char *error, int last_token, const char *last_token_str)
{
  if (not context->end())
  {
    context->error(error, config_tokentype(last_token), last_token_str);
  }
  else
  {
    context->error(error, config_tokentype(last_token), last_token_str);
  }
}

#define config_error(__context, __scanner, __error_msg) do { __config_error((__context), (__scanner), (__error_msg), select_yychar(__context), stryytname(YYTRANSLATE(select_yychar(__context)))); } while (0)



#line 127 "parser.cc"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_COMMENT = 3,                    /* COMMENT  */
  YYSYMBOL_END = 4,                        /* END  */
  YYSYMBOL_CSL_ERROR = 5,                  /* CSL_ERROR  */
  YYSYMBOL_RESET = 6,                      /* RESET  */
  YYSYMBOL_PARSER_DEBUG = 7,               /* PARSER_DEBUG  */
  YYSYMBOL_INCLUDE = 8,                    /* INCLUDE  */
  YYSYMBOL_CONFIGURE_FILE = 9,             /* CONFIGURE_FILE  */
  YYSYMBOL_EMPTY_LINE = 10,                /* EMPTY_LINE  */
  YYSYMBOL_SERVER = 11,                    /* SERVER  */
  YYSYMBOL_CSL_SOCKET = 12,                /* CSL_SOCKET  */
  YYSYMBOL_SERVERS = 13,                   /* SERVERS  */
  YYSYMBOL_SERVERS_OPTION = 14,            /* SERVERS_OPTION  */
  YYSYMBOL_UNKNOWN_OPTION = 15,            /* UNKNOWN_OPTION  */
  YYSYMBOL_UNKNOWN = 16,                   /* UNKNOWN  */
  YYSYMBOL_BINARY_PROTOCOL = 17,           /* BINARY_PROTOCOL  */
  YYSYMBOL_BUFFER_REQUESTS = 18,           /* BUFFER_REQUESTS  */
  YYSYMBOL_CONNECT_TIMEOUT = 19,           /* CONNECT_TIMEOUT  */
  YYSYMBOL_DISTRIBUTION = 20,              /* DISTRIBUTION  */
  YYSYMBOL_HASH = 21,                      /* HASH  */
  YYSYMBOL_HASH_WITH_NAMESPACE = 22,       /* HASH_WITH_NAMESPACE  */
  YYSYMBOL_IO_BYTES_WATERMARK = 23,        /* IO_BYTES_WATERMARK  */
  YYSYMBOL_IO_KEY_PREFETCH = 24,           /* IO_KEY_PREFETCH  */
  YYSYMBOL_IO_MSG_WATERMARK = 25,          /* IO_MSG_WATERMARK  */
  YYSYMBOL_KETAMA_HASH = 26,               /* KETAMA_HASH  */
  YYSYMBOL_KETAMA_WEIGHTED = 27,           /* KETAMA_WEIGHTED  */
  YYSYMBOL_NOREPLY = 28,                   /* NOREPLY  */
  YYSYMBOL_NUMBER_OF_REPLICAS = 29,        /* NUMBER_OF_REPLICAS  */
  YYSYMBOL_POLL_TIMEOUT = 30,              /* POLL_TIMEOUT  */
  YYSYMBOL_RANDOMIZE_REPLICA_READ = 31,    /* RANDOMIZE_REPLICA_READ  */
  YYSYMBOL_RCV_TIMEOUT = 32,               /* RCV_TIMEOUT  */
  YYSYMBOL_REMOVE_FAILED_SERVERS = 33,     /* REMOVE_FAILED_SERVERS  */
  YYSYMBOL_RETRY_TIMEOUT = 34,             /* RETRY_TIMEOUT  */
  YYSYMBOL_SND_TIMEOUT = 35,               /* SND_TIMEOUT  */
  YYSYMBOL_SOCKET_RECV_SIZE = 36,          /* SOCKET_RECV_SIZE  */
  YYSYMBOL_SOCKET_SEND_SIZE = 37,          /* SOCKET_SEND_SIZE  */
  YYSYMBOL_SORT_HOSTS = 38,                /* SORT_HOSTS  */
  YYSYMBOL_SUPPORT_CAS = 39,               /* SUPPORT_CAS  */
  YYSYMBOL_USER_DATA = 40,                 /* USER_DATA  */
  YYSYMBOL_USE_UDP = 41,                   /* USE_UDP  */
  YYSYMBOL_VERIFY_KEY = 42,                /* VERIFY_KEY  */
  YYSYMBOL__TCP_KEEPALIVE = 43,            /* _TCP_KEEPALIVE  */
  YYSYMBOL__TCP_KEEPIDLE = 44,             /* _TCP_KEEPIDLE  */
  YYSYMBOL__TCP_NODELAY = 45,              /* _TCP_NODELAY  */
  YYSYMBOL_FETCH_VERSION = 46,             /* FETCH_VERSION  */
  YYSYMBOL_NAMESPACE = 47,                 /* NAMESPACE  */
  YYSYMBOL_POOL_MIN = 48,                  /* POOL_MIN  */
  YYSYMBOL_POOL_MAX = 49,                  /* POOL_MAX  */
  YYSYMBOL_MD5 = 50,                       /* MD5  */
  YYSYMBOL_CRC = 51,                       /* CRC  */
  YYSYMBOL_FNV1_64 = 52,                   /* FNV1_64  */
  YYSYMBOL_FNV1A_64 = 53,                  /* FNV1A_64  */
  YYSYMBOL_FNV1_32 = 54,                   /* FNV1_32  */
  YYSYMBOL_FNV1A_32 = 55,                  /* FNV1A_32  */
  YYSYMBOL_HSIEH = 56,                     /* HSIEH  */
  YYSYMBOL_MURMUR = 57,                    /* MURMUR  */
  YYSYMBOL_JENKINS = 58,                   /* JENKINS  */
  YYSYMBOL_CONSISTENT = 59,                /* CONSISTENT  */
  YYSYMBOL_MODULA = 60,                    /* MODULA  */
  YYSYMBOL_RANDOM = 61,                    /* RANDOM  */
  YYSYMBOL_CSL_TRUE = 62,                  /* CSL_TRUE  */
  YYSYMBOL_CSL_FALSE = 63,                 /* CSL_FALSE  */
  YYSYMBOL_64_ = 64,                       /* ','  */
  YYSYMBOL_65_ = 65,                       /* '='  */
  YYSYMBOL_CSL_FLOAT = 66,                 /* CSL_FLOAT  */
  YYSYMBOL_NUMBER = 67,                    /* NUMBER  */
  YYSYMBOL_PORT = 68,                      /* PORT  */
  YYSYMBOL_WEIGHT_START = 69,              /* WEIGHT_START  */
  YYSYMBOL_IPADDRESS = 70,                 /* IPADDRESS  */
  YYSYMBOL_HOSTNAME = 71,                  /* HOSTNAME  */
  YYSYMBOL_STRING = 72,                    /* STRING  */
  YYSYMBOL_QUOTED_STRING = 73,             /* QUOTED_STRING  */
  YYSYMBOL_FILE_PATH = 74,                 /* FILE_PATH  */
  YYSYMBOL_75_ = 75,                       /* ' '  */
  YYSYMBOL_YYACCEPT = 76,                  /* $accept  */
  YYSYMBOL_begin = 77,                     /* begin  */
  YYSYMBOL_statement = 78,                 /* statement  */
  YYSYMBOL_expression = 79,                /* expression  */
  YYSYMBOL_behaviors = 80,                 /* behaviors  */
  YYSYMBOL_behavior_number = 81,           /* behavior_number  */
  YYSYMBOL_behavior_boolean = 82,          /* behavior_boolean  */
  YYSYMBOL_optional_port = 83,             /* optional_port  */
  YYSYMBOL_optional_weight = 84,           /* optional_weight  */
  YYSYMBOL_hash = 85,                      /* hash  */
  YYSYMBOL_string = 86,                    /* string  */
  YYSYMBOL_distribution = 87               /* distribution  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined CONFIG_STYPE_IS_TRIVIAL && CONFIG_STYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  71
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   75

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  76
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  12
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  85

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   327


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    75,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    64,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    65,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    66,
      67,    68,    69,    70,    71,    72,    73,    74
};

#if CONFIG_DEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   201,   201,   202,   206,   208,   210,   212,   217,   222,
     226,   230,   241,   251,   261,   270,   274,   278,   282,   286,
     298,   311,   324,   331,   338,   347,   353,   357,   361,   365,
     369,   373,   377,   381,   385,   389,   393,   397,   404,   408,
     412,   416,   420,   424,   428,   432,   436,   440,   444,   448,
     455,   456,   461,   462,   467,   471,   475,   479,   483,   487,
     491,   495,   499,   506,   510,   517,   521,   525
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "COMMENT", "END",
  "CSL_ERROR", "RESET", "PARSER_DEBUG", "INCLUDE", "CONFIGURE_FILE",
  "EMPTY_LINE", "SERVER", "CSL_SOCKET", "SERVERS", "SERVERS_OPTION",
  "UNKNOWN_OPTION", "UNKNOWN", "BINARY_PROTOCOL", "BUFFER_REQUESTS",
  "CONNECT_TIMEOUT", "DISTRIBUTION", "HASH", "HASH_WITH_NAMESPACE",
  "IO_BYTES_WATERMARK", "IO_KEY_PREFETCH", "IO_MSG_WATERMARK",
  "KETAMA_HASH", "KETAMA_WEIGHTED", "NOREPLY", "NUMBER_OF_REPLICAS",
  "POLL_TIMEOUT", "RANDOMIZE_REPLICA_READ", "RCV_TIMEOUT",
  "REMOVE_FAILED_SERVERS", "RETRY_TIMEOUT", "SND_TIMEOUT",
  "SOCKET_RECV_SIZE", "SOCKET_SEND_SIZE", "SORT_HOSTS", "SUPPORT_CAS",
  "USER_DATA", "USE_UDP", "VERIFY_KEY", "_TCP_KEEPALIVE", "_TCP_KEEPIDLE",
  "_TCP_NODELAY", "FETCH_VERSION", "NAMESPACE", "POOL_MIN", "POOL_MAX",
  "MD5", "CRC", "FNV1_64", "FNV1A_64", "FNV1_32", "FNV1A_32", "HSIEH",
  "MURMUR", "JENKINS", "CONSISTENT", "MODULA", "RANDOM", "CSL_TRUE",
  "CSL_FALSE", "','", "'='", "CSL_FLOAT", "NUMBER", "PORT", "WEIGHT_START",
  "IPADDRESS", "HOSTNAME", "STRING", "QUOTED_STRING", "FILE_PATH", "' '",
  "$accept", "begin", "statement", "expression", "behaviors",
  "behavior_number", "behavior_boolean", "optional_port",
  "optional_weight", "hash", "string", "distribution", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-62)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -2,   -62,   -62,   -62,   -62,   -62,   -61,   -24,   -62,   -20,
     -24,   -62,   -62,   -62,   -48,    12,   -62,   -62,   -62,   -62,
     -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,
     -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -24,   -42,
     -12,     0,   -62,   -62,   -62,   -11,   -62,   -24,   -62,   -62,
     -62,   -10,   -10,   -25,   -62,   -62,   -62,    -7,   -62,   -62,
     -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,
     -62,   -62,    -2,   -62,   -62,   -62,   -25,   -25,   -62,   -62,
      12,   -62,   -62,   -62,   -62
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     5,     7,     8,     9,    10,     0,     0,     6,     0,
       0,    38,    39,    27,     0,     0,    40,    29,    30,    28,
      41,    31,    32,    42,    33,    26,    34,    35,    36,    37,
      43,    44,    25,    48,    49,    46,    47,    45,     0,     0,
       0,     0,     2,     4,    18,     0,    24,     0,    63,    64,
      15,    50,    50,    52,    65,    66,    67,    20,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    22,    19,    16,
      17,     1,     0,    23,    11,    51,    52,    52,    53,    14,
       0,     3,    13,    12,    21
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -62,   -62,   -13,   -62,   -62,   -62,   -62,     8,   -23,    -9,
      14,   -62
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    41,    42,    43,    44,    45,    46,    76,    79,    67,
      50,    57
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      71,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    54,    55,    56,    47,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    53,    69,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    78,    38,    39,    40,    48,    49,
      51,    52,    68,    82,    83,    70,    73,    80,    75,    81,
      77,    74,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    84,     0,     0,     0,    72
};

static const yytype_int8 yycheck[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    59,    60,    61,    75,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    10,    67,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    69,    47,    48,    49,    72,    73,
      70,    71,    38,    76,    77,    67,    67,    64,    68,    72,
      52,    47,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    80,    -1,    -1,    -1,    75
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    47,    48,
      49,    77,    78,    79,    80,    81,    82,    75,    72,    73,
      86,    70,    71,    86,    59,    60,    61,    87,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    85,    86,    67,
      67,     0,    75,    67,    86,    68,    83,    83,    69,    84,
      64,    78,    84,    84,    85
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    76,    77,    77,    78,    78,    78,    78,    78,    78,
      78,    78,    79,    79,    79,    79,    79,    79,    79,    80,
      80,    80,    80,    80,    80,    80,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      83,    83,    84,    84,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    86,    86,    87,    87,    87
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     4,     4,     3,     2,     2,     2,     1,     2,
       2,     4,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     1,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = CONFIG_EMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == CONFIG_EMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (context, scanner, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use CONFIG_error or CONFIG_UNDEF. */
#define YYERRCODE CONFIG_UNDEF


/* Enable debugging if requested.  */
#if CONFIG_DEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, context, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, class Context *context, yyscan_t *scanner)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (context);
  YY_USE (scanner);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, class Context *context, yyscan_t *scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, context, scanner);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, class Context *context, yyscan_t *scanner)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)], context, scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, context, scanner); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !CONFIG_DEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !CONFIG_DEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, class Context *context, yyscan_t *scanner)
{
  YY_USE (yyvaluep);
  YY_USE (context);
  YY_USE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (class Context *context, yyscan_t *scanner)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs YY_ATTRIBUTE_UNUSED = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = CONFIG_EMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == CONFIG_EMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, scanner);
    }

  if (yychar <= CONFIG_EOF)
    {
      yychar = CONFIG_EOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == CONFIG_error)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = CONFIG_UNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = CONFIG_EMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 4: /* statement: expression  */
#line 207 "parser.yy"
          { }
#line 1549 "parser.cc"
    break;

  case 5: /* statement: COMMENT  */
#line 209 "parser.yy"
          { }
#line 1555 "parser.cc"
    break;

  case 6: /* statement: EMPTY_LINE  */
#line 211 "parser.yy"
          { }
#line 1561 "parser.cc"
    break;

  case 7: /* statement: END  */
#line 213 "parser.yy"
          {
            context->set_end();
            YYACCEPT;
          }
#line 1570 "parser.cc"
    break;

  case 8: /* statement: CSL_ERROR  */
#line 218 "parser.yy"
          {
            context->rc= MEMCACHED_PARSE_USER_ERROR;
            parser_abort(context, "ERROR called directly");
          }
#line 1579 "parser.cc"
    break;

  case 9: /* statement: RESET  */
#line 223 "parser.yy"
          {
            memcached_reset(context->memc);
          }
#line 1587 "parser.cc"
    break;

  case 10: /* statement: PARSER_DEBUG  */
#line 227 "parser.yy"
          {
            yydebug= 1;
          }
#line 1595 "parser.cc"
    break;

  case 11: /* statement: INCLUDE ' ' string  */
#line 231 "parser.yy"
          {
            if ((context->rc= memcached_parse_configure_file(*context->memc, (yyvsp[0].string).c_str, (yyvsp[0].string).size)) != MEMCACHED_SUCCESS)
            {
              parser_abort(context, "Failed to parse configuration file");
            }
          }
#line 1606 "parser.cc"
    break;

  case 12: /* expression: SERVER HOSTNAME optional_port optional_weight  */
#line 242 "parser.yy"
          {
            if (memcached_failed(context->rc= memcached_server_add_with_weight(context->memc, (yyvsp[-2].server).c_str, (yyvsp[-1].number), uint32_t((yyvsp[0].number)))))
            {
              char buffer[1024];
              snprintf(buffer, sizeof(buffer), "Failed to add server: %s:%u", (yyvsp[-2].server).c_str, uint32_t((yyvsp[-1].number)));
              parser_abort(context, buffer);
            }
            context->unset_server();
          }
#line 1620 "parser.cc"
    break;

  case 13: /* expression: SERVER IPADDRESS optional_port optional_weight  */
#line 252 "parser.yy"
          {
            if (memcached_failed(context->rc= memcached_server_add_with_weight(context->memc, (yyvsp[-2].server).c_str, (yyvsp[-1].number), uint32_t((yyvsp[0].number)))))
            {
              char buffer[1024];
              snprintf(buffer, sizeof(buffer), "Failed to add server: %s:%u", (yyvsp[-2].server).c_str, uint32_t((yyvsp[-1].number)));
              parser_abort(context, buffer);
            }
            context->unset_server();
          }
#line 1634 "parser.cc"
    break;

  case 14: /* expression: CSL_SOCKET string optional_weight  */
#line 262 "parser.yy"
          {
            if (memcached_failed(context->rc= memcached_server_add_unix_socket_with_weight(context->memc, (yyvsp[-1].string).c_str, uint32_t((yyvsp[0].number)))))
            {
              char buffer[1024];
              snprintf(buffer, sizeof(buffer), "Failed to add socket: %s", (yyvsp[-1].string).c_str);
              parser_abort(context, buffer);
            }
          }
#line 1647 "parser.cc"
    break;

  case 15: /* expression: CONFIGURE_FILE string  */
#line 271 "parser.yy"
          {
            memcached_set_configuration_file(context->memc, (yyvsp[0].string).c_str, (yyvsp[0].string).size);
          }
#line 1655 "parser.cc"
    break;

  case 16: /* expression: POOL_MIN NUMBER  */
#line 275 "parser.yy"
          {
            context->memc->configure.initial_pool_size= uint32_t((yyvsp[0].number));
          }
#line 1663 "parser.cc"
    break;

  case 17: /* expression: POOL_MAX NUMBER  */
#line 279 "parser.yy"
          {
            context->memc->configure.max_pool_size= uint32_t((yyvsp[0].number));
          }
#line 1671 "parser.cc"
    break;

  case 19: /* behaviors: NAMESPACE string  */
#line 287 "parser.yy"
          {
            if (memcached_callback_get(context->memc, MEMCACHED_CALLBACK_PREFIX_KEY, NULL))
            {
              parser_abort(context, "--NAMESPACE can only be called once");
            }

            if ((context->rc= memcached_set_namespace(context->memc, (yyvsp[0].string).c_str, (yyvsp[0].string).size)) != MEMCACHED_SUCCESS)
            {
              parser_abort(context, memcached_last_error_message(context->memc));
            }
          }
#line 1687 "parser.cc"
    break;

  case 20: /* behaviors: DISTRIBUTION distribution  */
#line 299 "parser.yy"
          {
            // Check to see if DISTRIBUTION has already been set
            if ((context->rc= memcached_behavior_set(context->memc, MEMCACHED_BEHAVIOR_DISTRIBUTION, (yyvsp[0].distribution))) != MEMCACHED_SUCCESS)
            {
              parser_abort(context, "--DISTRIBUTION can only be called once");
            }

            if ((context->rc= memcached_behavior_set(context->memc, MEMCACHED_BEHAVIOR_DISTRIBUTION, (yyvsp[0].distribution))) != MEMCACHED_SUCCESS)
            {
              parser_abort(context, memcached_last_error_message(context->memc));;
            }
          }
#line 1704 "parser.cc"
    break;

  case 21: /* behaviors: DISTRIBUTION distribution ',' hash  */
#line 312 "parser.yy"
          {
            // Check to see if DISTRIBUTION has already been set
            if ((context->rc= memcached_behavior_set(context->memc, MEMCACHED_BEHAVIOR_DISTRIBUTION, (yyvsp[-2].distribution))) != MEMCACHED_SUCCESS)
            {
              parser_abort(context, "--DISTRIBUTION can only be called once");
            }

            if ((context->rc= memcached_behavior_set_distribution_hash(context->memc, (yyvsp[0].hash))) != MEMCACHED_SUCCESS)
            {
              parser_abort(context, "Unable to set the hash for the DISTRIBUTION requested");
            }
          }
#line 1721 "parser.cc"
    break;

  case 22: /* behaviors: HASH hash  */
#line 325 "parser.yy"
          {
            if ((context->rc= memcached_behavior_set(context->memc, MEMCACHED_BEHAVIOR_HASH, (yyvsp[0].hash))) != MEMCACHED_SUCCESS)
            {
              parser_abort(context, NULL);;
            }
          }
#line 1732 "parser.cc"
    break;

  case 23: /* behaviors: behavior_number NUMBER  */
#line 332 "parser.yy"
          {
            if ((context->rc= memcached_behavior_set(context->memc, (yyvsp[-1].behavior), (yyvsp[0].number))) != MEMCACHED_SUCCESS)
            {
              parser_abort(context, "Unable to set behavior");
            }
          }
#line 1743 "parser.cc"
    break;

  case 24: /* behaviors: behavior_boolean  */
#line 339 "parser.yy"
          {
            if ((context->rc= memcached_behavior_set(context->memc, (yyvsp[0].behavior), true)) != MEMCACHED_SUCCESS)
            {
              char buffer[1024];
              snprintf(buffer, sizeof(buffer), "Could not set: %s", libmemcached_string_behavior((yyvsp[0].behavior)));
              parser_abort(context, buffer);
            }
          }
#line 1756 "parser.cc"
    break;

  case 25: /* behaviors: USER_DATA  */
#line 348 "parser.yy"
          {
          }
#line 1763 "parser.cc"
    break;

  case 26: /* behavior_number: REMOVE_FAILED_SERVERS  */
#line 354 "parser.yy"
          {
            (yyval.behavior)= MEMCACHED_BEHAVIOR_REMOVE_FAILED_SERVERS;
          }
#line 1771 "parser.cc"
    break;

  case 27: /* behavior_number: CONNECT_TIMEOUT  */
#line 358 "parser.yy"
          {
            (yyval.behavior)= MEMCACHED_BEHAVIOR_CONNECT_TIMEOUT;
          }
#line 1779 "parser.cc"
    break;

  case 28: /* behavior_number: IO_MSG_WATERMARK  */
#line 362 "parser.yy"
          {
            (yyval.behavior)= MEMCACHED_BEHAVIOR_IO_MSG_WATERMARK;
          }
#line 1787 "parser.cc"
    break;

  case 29: /* behavior_number: IO_BYTES_WATERMARK  */
#line 366 "parser.yy"
          {
            (yyval.behavior)= MEMCACHED_BEHAVIOR_IO_BYTES_WATERMARK;
          }
#line 1795 "parser.cc"
    break;

  case 30: /* behavior_number: IO_KEY_PREFETCH  */
#line 370 "parser.yy"
          {
            (yyval.behavior)= MEMCACHED_BEHAVIOR_IO_KEY_PREFETCH;
          }
#line 1803 "parser.cc"
    break;

  case 31: /* behavior_number: NUMBER_OF_REPLICAS  */
#line 374 "parser.yy"
          {
            (yyval.behavior)= MEMCACHED_BEHAVIOR_NUMBER_OF_REPLICAS;
          }
#line 1811 "parser.cc"
    break;

  case 32: /* behavior_number: POLL_TIMEOUT  */
#line 378 "parser.yy"
          {
            (yyval.behavior)= MEMCACHED_BEHAVIOR_POLL_TIMEOUT;
          }
#line 1819 "parser.cc"
    break;

  case 33: /* behavior_number: RCV_TIMEOUT  */
#line 382 "parser.yy"
          {
            (yyval.behavior)= MEMCACHED_BEHAVIOR_RCV_TIMEOUT;
          }
#line 1827 "parser.cc"
    break;

  case 34: /* behavior_number: RETRY_TIMEOUT  */
#line 386 "parser.yy"
          {
            (yyval.behavior)= MEMCACHED_BEHAVIOR_RETRY_TIMEOUT;
          }
#line 1835 "parser.cc"
    break;

  case 35: /* behavior_number: SND_TIMEOUT  */
#line 390 "parser.yy"
          {
            (yyval.behavior)= MEMCACHED_BEHAVIOR_SND_TIMEOUT;
          }
#line 1843 "parser.cc"
    break;

  case 36: /* behavior_number: SOCKET_RECV_SIZE  */
#line 394 "parser.yy"
          {
            (yyval.behavior)= MEMCACHED_BEHAVIOR_SOCKET_RECV_SIZE;
          }
#line 1851 "parser.cc"
    break;

  case 37: /* behavior_number: SOCKET_SEND_SIZE  */
#line 398 "parser.yy"
          {
            (yyval.behavior)= MEMCACHED_BEHAVIOR_SOCKET_SEND_SIZE;
          }
#line 1859 "parser.cc"
    break;

  case 38: /* behavior_boolean: BINARY_PROTOCOL  */
#line 405 "parser.yy"
          {
            (yyval.behavior)= MEMCACHED_BEHAVIOR_BINARY_PROTOCOL;
          }
#line 1867 "parser.cc"
    break;

  case 39: /* behavior_boolean: BUFFER_REQUESTS  */
#line 409 "parser.yy"
          {
            (yyval.behavior)= MEMCACHED_BEHAVIOR_BUFFER_REQUESTS;
          }
#line 1875 "parser.cc"
    break;

  case 40: /* behavior_boolean: HASH_WITH_NAMESPACE  */
#line 413 "parser.yy"
          {
            (yyval.behavior)= MEMCACHED_BEHAVIOR_HASH_WITH_PREFIX_KEY;
          }
#line 1883 "parser.cc"
    break;

  case 41: /* behavior_boolean: NOREPLY  */
#line 417 "parser.yy"
          {
            (yyval.behavior)= MEMCACHED_BEHAVIOR_NOREPLY;
          }
#line 1891 "parser.cc"
    break;

  case 42: /* behavior_boolean: RANDOMIZE_REPLICA_READ  */
#line 421 "parser.yy"
          {
            (yyval.behavior)= MEMCACHED_BEHAVIOR_RANDOMIZE_REPLICA_READ;
          }
#line 1899 "parser.cc"
    break;

  case 43: /* behavior_boolean: SORT_HOSTS  */
#line 425 "parser.yy"
          {
            (yyval.behavior)= MEMCACHED_BEHAVIOR_SORT_HOSTS;
          }
#line 1907 "parser.cc"
    break;

  case 44: /* behavior_boolean: SUPPORT_CAS  */
#line 429 "parser.yy"
          {
            (yyval.behavior)= MEMCACHED_BEHAVIOR_SUPPORT_CAS;
          }
#line 1915 "parser.cc"
    break;

  case 45: /* behavior_boolean: _TCP_NODELAY  */
#line 433 "parser.yy"
          {
            (yyval.behavior)= MEMCACHED_BEHAVIOR_TCP_NODELAY;
          }
#line 1923 "parser.cc"
    break;

  case 46: /* behavior_boolean: _TCP_KEEPALIVE  */
#line 437 "parser.yy"
          {
            (yyval.behavior)= MEMCACHED_BEHAVIOR_TCP_KEEPALIVE;
          }
#line 1931 "parser.cc"
    break;

  case 47: /* behavior_boolean: _TCP_KEEPIDLE  */
#line 441 "parser.yy"
          {
            (yyval.behavior)= MEMCACHED_BEHAVIOR_TCP_KEEPIDLE;
          }
#line 1939 "parser.cc"
    break;

  case 48: /* behavior_boolean: USE_UDP  */
#line 445 "parser.yy"
          {
            (yyval.behavior)= MEMCACHED_BEHAVIOR_USE_UDP;
          }
#line 1947 "parser.cc"
    break;

  case 49: /* behavior_boolean: VERIFY_KEY  */
#line 449 "parser.yy"
          {
            (yyval.behavior)= MEMCACHED_BEHAVIOR_VERIFY_KEY;
          }
#line 1955 "parser.cc"
    break;

  case 50: /* optional_port: %empty  */
#line 455 "parser.yy"
          { (yyval.number)= MEMCACHED_DEFAULT_PORT;}
#line 1961 "parser.cc"
    break;

  case 51: /* optional_port: PORT  */
#line 457 "parser.yy"
          { }
#line 1967 "parser.cc"
    break;

  case 52: /* optional_weight: %empty  */
#line 461 "parser.yy"
          { (yyval.number)= 1; }
#line 1973 "parser.cc"
    break;

  case 53: /* optional_weight: WEIGHT_START  */
#line 463 "parser.yy"
          { }
#line 1979 "parser.cc"
    break;

  case 54: /* hash: MD5  */
#line 468 "parser.yy"
          {
            (yyval.hash)= MEMCACHED_HASH_MD5;
          }
#line 1987 "parser.cc"
    break;

  case 55: /* hash: CRC  */
#line 472 "parser.yy"
          {
            (yyval.hash)= MEMCACHED_HASH_CRC;
          }
#line 1995 "parser.cc"
    break;

  case 56: /* hash: FNV1_64  */
#line 476 "parser.yy"
          {
            (yyval.hash)= MEMCACHED_HASH_FNV1_64;
          }
#line 2003 "parser.cc"
    break;

  case 57: /* hash: FNV1A_64  */
#line 480 "parser.yy"
          {
            (yyval.hash)= MEMCACHED_HASH_FNV1A_64;
          }
#line 2011 "parser.cc"
    break;

  case 58: /* hash: FNV1_32  */
#line 484 "parser.yy"
          {
            (yyval.hash)= MEMCACHED_HASH_FNV1_32;
          }
#line 2019 "parser.cc"
    break;

  case 59: /* hash: FNV1A_32  */
#line 488 "parser.yy"
          {
            (yyval.hash)= MEMCACHED_HASH_FNV1A_32;
          }
#line 2027 "parser.cc"
    break;

  case 60: /* hash: HSIEH  */
#line 492 "parser.yy"
          {
            (yyval.hash)= MEMCACHED_HASH_HSIEH;
          }
#line 2035 "parser.cc"
    break;

  case 61: /* hash: MURMUR  */
#line 496 "parser.yy"
          {
            (yyval.hash)= MEMCACHED_HASH_MURMUR;
          }
#line 2043 "parser.cc"
    break;

  case 62: /* hash: JENKINS  */
#line 500 "parser.yy"
          {
            (yyval.hash)= MEMCACHED_HASH_JENKINS;
          }
#line 2051 "parser.cc"
    break;

  case 63: /* string: STRING  */
#line 507 "parser.yy"
          {
            (yyval.string)= (yyvsp[0].string);
          }
#line 2059 "parser.cc"
    break;

  case 64: /* string: QUOTED_STRING  */
#line 511 "parser.yy"
          {
            (yyval.string)= (yyvsp[0].string);
          }
#line 2067 "parser.cc"
    break;

  case 65: /* distribution: CONSISTENT  */
#line 518 "parser.yy"
          {
            (yyval.distribution)= MEMCACHED_DISTRIBUTION_CONSISTENT;
          }
#line 2075 "parser.cc"
    break;

  case 66: /* distribution: MODULA  */
#line 522 "parser.yy"
          {
            (yyval.distribution)= MEMCACHED_DISTRIBUTION_MODULA;
          }
#line 2083 "parser.cc"
    break;

  case 67: /* distribution: RANDOM  */
#line 526 "parser.yy"
          {
            (yyval.distribution)= MEMCACHED_DISTRIBUTION_RANDOM;
          }
#line 2091 "parser.cc"
    break;


#line 2095 "parser.cc"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == CONFIG_EMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (context, scanner, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= CONFIG_EOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == CONFIG_EOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, context, scanner);
          yychar = CONFIG_EMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, context, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (context, scanner, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != CONFIG_EMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, context, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, context, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 531 "parser.yy"


void Context::start()
{
  config_parse(this, (void **)scanner);
}
