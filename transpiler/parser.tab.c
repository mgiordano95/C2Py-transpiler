/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h> //printf, scanf, ecc
#include <math.h>
#include <ctype.h>
#include <string.h> //strcmp, strdup
#include <stdbool.h> //true, false
#include "ast.h"
#include "symboltable.h"
#include "c2py.h"

int yylex(void);
int yyerror(char *s);

struct AstNodeStatements *root;
struct List *actualList = NULL;

char* type_to_str(int type);

void scope_enter();
void scope_exit();


#line 94 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_VOID = 3,                       /* VOID  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_FLOAT = 5,                      /* FLOAT  */
  YYSYMBOL_CHAR = 6,                       /* CHAR  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_WHILE = 9,                      /* WHILE  */
  YYSYMBOL_PRINTF = 10,                    /* PRINTF  */
  YYSYMBOL_SCANF = 11,                     /* SCANF  */
  YYSYMBOL_RETURN = 12,                    /* RETURN  */
  YYSYMBOL_MAIN = 13,                      /* MAIN  */
  YYSYMBOL_ADD = 14,                       /* ADD  */
  YYSYMBOL_SUB = 15,                       /* SUB  */
  YYSYMBOL_MUL = 16,                       /* MUL  */
  YYSYMBOL_DIV = 17,                       /* DIV  */
  YYSYMBOL_EQ = 18,                        /* EQ  */
  YYSYMBOL_EE = 19,                        /* EE  */
  YYSYMBOL_NE = 20,                        /* NE  */
  YYSYMBOL_GT = 21,                        /* GT  */
  YYSYMBOL_LT = 22,                        /* LT  */
  YYSYMBOL_GE = 23,                        /* GE  */
  YYSYMBOL_LE = 24,                        /* LE  */
  YYSYMBOL_AND = 25,                       /* AND  */
  YYSYMBOL_OR = 26,                        /* OR  */
  YYSYMBOL_NOT = 27,                       /* NOT  */
  YYSYMBOL_LPAR = 28,                      /* LPAR  */
  YYSYMBOL_RPAR = 29,                      /* RPAR  */
  YYSYMBOL_LSBRA = 30,                     /* LSBRA  */
  YYSYMBOL_RSBRA = 31,                     /* RSBRA  */
  YYSYMBOL_LBRA = 32,                      /* LBRA  */
  YYSYMBOL_RBRA = 33,                      /* RBRA  */
  YYSYMBOL_SEMICOL = 34,                   /* SEMICOL  */
  YYSYMBOL_COMMA = 35,                     /* COMMA  */
  YYSYMBOL_INT_VALUE = 36,                 /* INT_VALUE  */
  YYSYMBOL_FLOAT_VALUE = 37,               /* FLOAT_VALUE  */
  YYSYMBOL_ID = 38,                        /* ID  */
  YYSYMBOL_CHAR_VALUE = 39,                /* CHAR_VALUE  */
  YYSYMBOL_UNKNOWN = 40,                   /* UNKNOWN  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_program = 42,                   /* program  */
  YYSYMBOL_43_1 = 43,                      /* $@1  */
  YYSYMBOL_statements = 44,                /* statements  */
  YYSYMBOL_instruction = 45,               /* instruction  */
  YYSYMBOL_functionDecl = 46,              /* functionDecl  */
  YYSYMBOL_functionCall = 47,              /* functionCall  */
  YYSYMBOL_functionParams = 48,            /* functionParams  */
  YYSYMBOL_body = 49,                      /* body  */
  YYSYMBOL_ifStatement = 50,               /* ifStatement  */
  YYSYMBOL_elseifStatement = 51,           /* elseifStatement  */
  YYSYMBOL_elseStatement = 52,             /* elseStatement  */
  YYSYMBOL_arrayInit = 53,                 /* arrayInit  */
  YYSYMBOL_arrayAssign = 54,               /* arrayAssign  */
  YYSYMBOL_arrayElements = 55,             /* arrayElements  */
  YYSYMBOL_initialization = 56,            /* initialization  */
  YYSYMBOL_assignment = 57,                /* assignment  */
  YYSYMBOL_expression = 58,                /* expression  */
  YYSYMBOL_content = 59,                   /* content  */
  YYSYMBOL_types = 60                      /* types  */
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
typedef yytype_uint8 yy_state_t;

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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   272

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  137

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    88,    88,    88,    97,   104,   113,   125,   140,   154,
     160,   166,   172,   178,   184,   192,   202,   213,   229,   241,
     255,   269,   276,   290,   299,   305,   313,   321,   329,   336,
     347,   360,   368,   376,   384,   392,   400,   408,   416,   426,
     432,   440,   454,   469,   489,   499,   518,   537,   556,   575,
     586,   597,   614,   631,   648,   665,   682,   699,   718,   730,
     737,   744,   751,   758,   767,   771,   775,   779
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "VOID", "INT", "FLOAT",
  "CHAR", "IF", "ELSE", "WHILE", "PRINTF", "SCANF", "RETURN", "MAIN",
  "ADD", "SUB", "MUL", "DIV", "EQ", "EE", "NE", "GT", "LT", "GE", "LE",
  "AND", "OR", "NOT", "LPAR", "RPAR", "LSBRA", "RSBRA", "LBRA", "RBRA",
  "SEMICOL", "COMMA", "INT_VALUE", "FLOAT_VALUE", "ID", "CHAR_VALUE",
  "UNKNOWN", "$accept", "program", "$@1", "statements", "instruction",
  "functionDecl", "functionCall", "functionParams", "body", "ifStatement",
  "elseifStatement", "elseStatement", "arrayInit", "arrayAssign",
  "arrayElements", "initialization", "assignment", "expression", "content",
  "types", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-31)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-43)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -31,    25,   102,   -31,   -31,   -31,   -31,   -31,     9,    -6,
     -15,   -31,   102,   -31,    34,   -31,   -31,   -31,    47,    48,
     -14,    54,   -11,   118,    11,   102,   -31,   182,    56,     4,
     -31,   -31,   -31,   -31,    60,   -31,   -31,    62,    -1,   118,
     -31,   -31,    63,   -31,   -31,    86,   160,   118,     0,    41,
     -31,   160,   -31,    95,    97,   100,   115,   108,   139,   143,
     158,   118,     5,   -31,   139,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   165,   118,   -31,
     -31,    98,   138,   164,   184,   -31,   139,   139,   160,   192,
     180,   -31,   207,   207,   226,   234,   241,   105,   246,   166,
      46,    -4,   190,   -31,   139,   144,   -31,    98,    40,   161,
     -31,   -31,   185,   217,   -31,   204,   -31,   -31,   205,   127,
     118,   160,   168,   176,   -31,   -31,   118,   206,   -31,   208,
     118,   160,   -31,   -31,   -31,   209,   -31
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,    64,    65,    66,    67,     0,     0,
       0,     3,     5,     8,     0,    10,    11,    12,     0,     0,
       0,     0,     0,     0,     0,     0,    28,     0,     0,     0,
       4,     9,    13,    14,     0,     7,     6,     0,    41,     0,
      59,    60,    58,    61,    63,    62,     0,     0,     0,    58,
      62,    44,    18,     0,    21,     0,     0,     0,     0,     0,
       0,     0,     0,    57,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    62,     0,    24,
      19,     0,    20,     0,     0,    16,     0,     0,    43,    29,
       0,    26,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,     0,     0,    23,     0,     0,     0,
      17,    15,     0,    30,    27,     0,    22,    35,     0,    39,
       0,    36,     0,     0,    25,    37,     0,     0,    31,     0,
       0,    32,    40,    38,    33,     0,    34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -31,   -31,   -31,    -2,   -31,   -31,     6,   -27,   -30,   -31,
     -31,   -31,   -31,   -31,   114,   -31,   -31,   -17,   -23,     7
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,    11,    12,    13,    44,    53,    26,    15,
      16,    17,    18,    19,   118,    20,    21,    50,   119,    55
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      46,    24,    37,    27,    51,    54,    45,    59,    14,    22,
      30,    54,    78,    28,    34,    29,    63,    61,    14,    22,
      35,    75,    76,    48,    46,     3,    25,    38,    85,    62,
      77,    14,    22,    79,    91,    56,    89,    23,    88,    47,
      57,    90,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   106,   105,   110,   111,    54,     4,
       5,     6,     7,     4,     5,     6,     7,    39,    31,    28,
      74,    75,    76,   117,   114,   -42,    40,    41,    42,    43,
     116,    32,    33,    39,    54,    52,   121,    39,    36,    58,
      60,    28,    40,    41,    42,    43,    40,    41,    42,    43,
     131,     4,     5,     6,     7,     4,     5,     6,     7,     8,
       9,    65,    66,    67,    68,    64,    69,    70,    71,    72,
      73,    74,    75,    76,    80,    39,    71,    72,    73,    74,
      75,    76,    81,    83,    40,    41,    42,    43,    82,    84,
      10,    65,    66,    67,    68,    39,    69,    70,    71,    72,
      73,    74,    75,    76,    40,    41,    42,    43,    65,    66,
      67,    68,   126,    69,    70,    71,    72,    73,    74,    75,
      76,    25,    86,   107,    65,    66,    67,    68,   115,    69,
      70,    71,    72,    73,    74,    75,    76,    87,    39,    73,
      74,    75,    76,   120,   104,    39,   108,    40,    41,    42,
      43,   128,   109,    39,    40,    41,    42,    43,   130,    39,
     112,   113,    40,    41,    42,    43,    76,   122,    40,    41,
      49,    43,    66,    67,    68,     0,    69,    70,    71,    72,
      73,    74,    75,    76,   127,   123,   129,   124,   125,   133,
     132,   134,   136,    68,   135,    69,    70,    71,    72,    73,
      74,    75,    76,    69,    70,    71,    72,    73,    74,    75,
      76,    70,    71,    72,    73,    74,    75,    76,    72,    73,
      74,    75,    76
};

static const yytype_int16 yycheck[] =
{
      23,     7,    13,    18,    27,    28,    23,    34,     2,     2,
      12,    34,    12,    28,    28,    30,    39,    18,    12,    12,
      34,    25,    26,    25,    47,     0,    32,    38,    58,    30,
      47,    25,    25,    33,    64,    31,    31,    28,    61,    28,
      36,    36,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    81,    78,    86,    87,    81,     3,
       4,     5,     6,     3,     4,     5,     6,    27,    34,    28,
      24,    25,    26,    33,   104,    34,    36,    37,    38,    39,
     107,    34,    34,    27,   107,    29,   109,    27,    34,    29,
      28,    28,    36,    37,    38,    39,    36,    37,    38,    39,
     123,     3,     4,     5,     6,     3,     4,     5,     6,     7,
       8,    14,    15,    16,    17,    29,    19,    20,    21,    22,
      23,    24,    25,    26,    29,    27,    21,    22,    23,    24,
      25,    26,    35,    18,    36,    37,    38,    39,    38,    31,
      38,    14,    15,    16,    17,    27,    19,    20,    21,    22,
      23,    24,    25,    26,    36,    37,    38,    39,    14,    15,
      16,    17,    35,    19,    20,    21,    22,    23,    24,    25,
      26,    32,    29,    35,    14,    15,    16,    17,    34,    19,
      20,    21,    22,    23,    24,    25,    26,    29,    27,    23,
      24,    25,    26,    32,    29,    27,    32,    36,    37,    38,
      39,    33,    18,    27,    36,    37,    38,    39,    32,    27,
      18,    31,    36,    37,    38,    39,    26,    32,    36,    37,
      38,    39,    15,    16,    17,    -1,    19,    20,    21,    22,
      23,    24,    25,    26,   120,    18,   122,    33,    33,    33,
     126,    33,    33,    17,   130,    19,    20,    21,    22,    23,
      24,    25,    26,    19,    20,    21,    22,    23,    24,    25,
      26,    20,    21,    22,    23,    24,    25,    26,    22,    23,
      24,    25,    26
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    42,    43,     0,     3,     4,     5,     6,     7,     8,
      38,    44,    45,    46,    47,    50,    51,    52,    53,    54,
      56,    57,    60,    28,     7,    32,    49,    18,    28,    30,
      44,    34,    34,    34,    28,    34,    34,    13,    38,    27,
      36,    37,    38,    39,    47,    58,    59,    28,    44,    38,
      58,    59,    29,    48,    59,    60,    31,    36,    29,    48,
      28,    18,    30,    59,    29,    14,    15,    16,    17,    19,
      20,    21,    22,    23,    24,    25,    26,    58,    12,    33,
      29,    35,    38,    18,    31,    49,    29,    29,    59,    31,
      36,    49,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    29,    59,    48,    35,    32,    18,
      49,    49,    18,    31,    49,    34,    48,    33,    55,    59,
      32,    59,    32,    18,    33,    33,    35,    55,    33,    55,
      32,    59,    55,    33,    33,    55,    33
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    43,    42,    44,    44,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    46,    46,    46,    47,    47,
      48,    48,    48,    48,    49,    49,    50,    51,    52,    53,
      53,    54,    54,    54,    54,    54,    54,    54,    54,    55,
      55,    56,    57,    57,    57,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    59,    59,
      59,    59,    59,    59,    60,    60,    60,    60
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     2,     2,     1,     2,
       1,     1,     1,     2,     2,     5,     4,     5,     3,     4,
       2,     1,     4,     3,     3,     6,     5,     6,     2,     4,
       5,     7,     7,     8,     9,     6,     6,     7,     8,     1,
       3,     2,     3,     4,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

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
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
                 int yyrule)
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
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



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

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
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
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
  yychar = YYEMPTY;
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
  case 2: /* $@1: %empty  */
#line 88 "parser.y"
                                                    {
                                                        scope_enter();
                                                    }
#line 1254 "parser.tab.c"
    break;

  case 3: /* program: $@1 statements  */
#line 91 "parser.y"
                                                    {
                                                        root = (yyvsp[0].statements);
                                                        scope_exit();
                                                    }
#line 1263 "parser.tab.c"
    break;

  case 4: /* statements: instruction statements  */
#line 97 "parser.y"
                                                    {
                                                        (yyval.statements) = malloc(sizeof(struct AstNodeStatements));
                                                        printf("AstNodeStatements allocated for 'instruction statements'\n");
                                                        (yyval.statements)->nodeType = STATEMENT_NODE;
                                                        (yyval.statements)->currentInstruction = (yyvsp[-1].instruction);
                                                        (yyval.statements)->nextStatement = (yyvsp[0].statements);
                                                    }
#line 1275 "parser.tab.c"
    break;

  case 5: /* statements: instruction  */
#line 104 "parser.y"
                                                    {
                                                        (yyval.statements) = malloc(sizeof(struct AstNodeStatements));
                                                        printf("AstNodeStatements allocated for 'instruction'\n");
                                                        (yyval.statements)->nodeType = STATEMENT_NODE;
                                                        (yyval.statements)->currentInstruction = (yyvsp[0].instruction);
                                                        (yyval.statements)->nextStatement = NULL;
                                                    }
#line 1287 "parser.tab.c"
    break;

  case 6: /* instruction: assignment SEMICOL  */
#line 113 "parser.y"
                                                    {
                                                        (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                        printf("AstNodeInstruction allocated for 'assignment SEMICOL'\n");
                                                        (yyval.instruction)->nodeType = ASSIGN_NODE;
                                                        struct SymTab *s = findSym((yyvsp[-1].assign)->variableName, actualList);
                                                        if((s->dataType != (yyvsp[-1].assign)->variableType) || strcmp(type_to_str(s->dataType), "none") == 0) {
                                                            printf("Error\n");
                                                        } else {
                                                            (yyval.instruction)->value.assign = (yyvsp[-1].assign);
                                                            s->valueOper = (yyvsp[-1].assign)->assignValue;
                                                        }
                                                    }
#line 1304 "parser.tab.c"
    break;

  case 7: /* instruction: initialization SEMICOL  */
#line 125 "parser.y"
                                                    {
                                                        (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                        struct SymTab *s = NULL;
                                                        for (struct AstNodeInit *init = (yyvsp[-1].init); init != NULL; init = init->nextInit) {
                                                            s = findSym(init->assign->variableName, actualList);
                                                            if (s == NULL) {
                                                                printf("AstNodeInstruction allocated for 'initialization SEMICOL'\n");
                                                                (yyval.instruction)->nodeType = INIT_NODE;
                                                                (yyval.instruction)->value.init = (yyvsp[-1].init);
                                                                s = createSym(init->assign->variableName, actualList, SYMBOL_VARIABLE, str_to_type((yyvsp[-1].init)), str_to_type((yyvsp[-1].init)), NULL, nullValue);
                                                            } else {
                                                                printf("Error: variable already declared.\n");
                                                            }
                                                        }
                                                    }
#line 1324 "parser.tab.c"
    break;

  case 8: /* instruction: functionDecl  */
#line 140 "parser.y"
                                                    {
                                                        (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                        printf("AstNodeInstruction allocated for 'functionDecl SEMICOL'\n");
                                                        (yyval.instruction)->nodeType = FUNCTION_DECL_NODE;
                                                        (yyval.instruction)->value.functionDecl = (yyvsp[0].functionDecl);
                                                        struct SymTab *s = NULL;
                                                        s = findSymtab((yyvsp[0].functionDecl)->functionName, actualList);
                                                        if (s == NULL) {
                                                            struct SymTab *s = createSym((yyvsp[0].functionDecl)->functionName, actualList, SYMBOL_FUNCTION, DATA_TYPE_NONE, (yyvsp[0].functionDecl)->returnType, (yyvsp[0].functionDecl)->functionName, nullValue);
                                                            printf("Funzione inserita nella symtab \n");
                                                        } else {
                                                            printf("Error: function %s already declared \n", (yyvsp[0].functionDecl)->functionName);
                                                        }
                                                    }
#line 1343 "parser.tab.c"
    break;

  case 9: /* instruction: functionCall SEMICOL  */
#line 154 "parser.y"
                                                    {
                                                        (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                        printf("AstNodeInstruction allocated for 'functionCall SEMICOL'\n");
                                                        (yyval.instruction)->nodeType = FUNCTION_CALL_NODE;
                                                        (yyval.instruction)->value.functionCall = (yyvsp[-1].functionCall);
                                                    }
#line 1354 "parser.tab.c"
    break;

  case 10: /* instruction: ifStatement  */
#line 160 "parser.y"
                                                    {
                                                        (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                        printf("AstNodeInstruction allocated for 'ifStatement'\n");
                                                        (yyval.instruction)->nodeType = IF_NODE;
                                                        (yyval.instruction)->value.ifStatement = (yyvsp[0].ifStatement);
                                                    }
#line 1365 "parser.tab.c"
    break;

  case 11: /* instruction: elseifStatement  */
#line 166 "parser.y"
                                                    {
                                                        (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                        printf("AstNodeInstruction allocated for 'ifStatement'\n");
                                                        (yyval.instruction)->nodeType = ELSE_IF_NODE;
                                                        (yyval.instruction)->value.elseifStatement = (yyvsp[0].elseifStatement);
                                                    }
#line 1376 "parser.tab.c"
    break;

  case 12: /* instruction: elseStatement  */
#line 172 "parser.y"
                                                    {
                                                        (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                        printf("AstNodeInstruction allocated for 'ifStatement'\n");
                                                        (yyval.instruction)->nodeType = ELSE_NODE;
                                                        (yyval.instruction)->value.elseStatement = (yyvsp[0].elseStatement);
                                                    }
#line 1387 "parser.tab.c"
    break;

  case 13: /* instruction: arrayInit SEMICOL  */
#line 178 "parser.y"
                                                    {
                                                        (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                        printf("AstNodeInstruction allocated for 'arrayInit'\n");
                                                        (yyval.instruction)->nodeType = ARRAY_INIT_NODE;
                                                        (yyval.instruction)->value.arrayInit = (yyvsp[-1].arrayInit);
                                                    }
#line 1398 "parser.tab.c"
    break;

  case 14: /* instruction: arrayAssign SEMICOL  */
#line 184 "parser.y"
                                                    {
                                                        (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                        printf("AstNodeInstruction allocated for 'arrayAssign'\n");
                                                        (yyval.instruction)->nodeType = ARRAY_ASSIGN_NODE;
                                                        (yyval.instruction)->value.arrayAssign = (yyvsp[-1].arrayAssign);
                                                    }
#line 1409 "parser.tab.c"
    break;

  case 15: /* functionDecl: types MAIN LPAR RPAR body  */
#line 192 "parser.y"
                                                    {
                                                        scope_enter();
                                                        (yyval.functionDecl) = malloc(sizeof(struct AstNodeFunctionDecl));
                                                        printf("AstNodeFunctionDecl allocated for 'types MAIN LPAR RPAR body'\n");
                                                        (yyval.functionDecl)->functionName = "main";
                                                        (yyval.functionDecl)->returnType = str_to_type((yyvsp[-4].string));
                                                        (yyval.functionDecl)->functionParams = NULL;
                                                        (yyval.functionDecl)->functiontBody = (yyvsp[0].body);
                                                        scope_exit();
                                                    }
#line 1424 "parser.tab.c"
    break;

  case 16: /* functionDecl: initialization LPAR RPAR body  */
#line 202 "parser.y"
                                                    {
                                                        scope_enter();
                                                        (yyval.functionDecl) = malloc(sizeof(struct AstNodeFunctionDecl));
                                                        printf("AstNodeFunctionDecl allocated for 'initialization LPAR RPAR body'\n");
                                                        (yyval.functionDecl)->functionName = (yyvsp[-3].init)->assign->variableName;
                                                        (yyval.functionDecl)->returnType = (yyvsp[-3].init)->dataType;
                                                        printf("returnType assigned\n");
                                                        (yyval.functionDecl)->functionParams = NULL;
                                                        (yyval.functionDecl)->functiontBody = (yyvsp[0].body);
                                                        scope_exit();
                                                    }
#line 1440 "parser.tab.c"
    break;

  case 17: /* functionDecl: initialization LPAR functionParams RPAR body  */
#line 213 "parser.y"
                                                    {
                                                        scope_enter();
                                                        for(struct AstNodeFunctionParams *p = (yyvsp[-2].functionParams); p != NULL; p = p->nextParams) {
                                                            struct SymTab *s = createSym(p->initParam->assign->variableName, actualList, SYMBOL_FUNCTION, p->initParam->dataType, DATA_TYPE_NONE, (yyvsp[-4].init)->assign->variableName, p->initParam->assign->assignValue);
                                                            printf("Added function parameter in the symbol table\n");
                                                        }
                                                        (yyval.functionDecl) = malloc(sizeof(struct AstNodeFunctionDecl));
                                                        printf("AstNodeFunctionDecl allocated for 'initialization LPAR functionParams RPAR body'\n");
                                                        (yyval.functionDecl)->functionName = (yyvsp[-4].init)->assign->variableName;
                                                        (yyval.functionDecl)->returnType = (yyvsp[-4].init)->dataType;
                                                        (yyval.functionDecl)->functionParams = (yyvsp[-2].functionParams);
                                                        (yyval.functionDecl)->functiontBody = (yyvsp[0].body);
                                                        scope_exit();
                                                    }
#line 1459 "parser.tab.c"
    break;

  case 18: /* functionCall: ID LPAR RPAR  */
#line 229 "parser.y"
                                                    {
                                                        (yyval.functionCall) = malloc(sizeof(struct AstNodeFunctionCall));
                                                        printf("AstNodeFunctionCall allocated for 'ID LPAR RPAR'\n");
                                                        struct SymTab *s = findSymtab((yyvsp[-2].string), actualList);
                                                        if (s != NULL) {
                                                            (yyval.functionCall)->functionName = (yyvsp[-2].string);
                                                            (yyval.functionCall)->returnType = s->returnType;
                                                            (yyval.functionCall)->functionParams = NULL;
                                                        } else {
                                                            printf("Error: function %s not declared\n", (yyvsp[-2].string));
                                                        }
                                                    }
#line 1476 "parser.tab.c"
    break;

  case 19: /* functionCall: ID LPAR functionParams RPAR  */
#line 241 "parser.y"
                                                    {
                                                        (yyval.functionCall) = malloc(sizeof(struct AstNodeFunctionCall));
                                                        printf("AstNodeFunctionCall allocated for 'ID LPAR functionParams RPAR'\n");
                                                        struct SymTab *s = findSymtab((yyvsp[-3].string), actualList);
                                                        if (s != NULL) {
                                                            (yyval.functionCall)->functionName = (yyvsp[-3].string);
                                                            (yyval.functionCall)->returnType = s->returnType;
                                                            (yyval.functionCall)->functionParams = NULL;
                                                        } else {
                                                            printf("Error: function %s not declared\n", (yyvsp[-3].string));
                                                        }
                                                    }
#line 1493 "parser.tab.c"
    break;

  case 20: /* functionParams: types ID  */
#line 255 "parser.y"
                                                    {
                                                        (yyval.functionParams) = malloc(sizeof(struct AstNodeFunctionParams));
                                                        printf("AstNodeFunctionParams allocated for 'types ID'\n");
                                                        (yyval.functionParams)->nextParams = NULL;
                                                        (yyval.functionParams)->callParams = NULL;
                                                        (yyval.functionParams)->initParam = malloc(sizeof(struct AstNodeInit));
                                                        (yyval.functionParams)->initParam->dataType = str_to_type((yyvsp[-1].string));
                                                        (yyval.functionParams)->initParam->nextInit = NULL;
                                                        (yyval.functionParams)->initParam->assign = malloc(sizeof(struct AstNodeAssign));
                                                        (yyval.functionParams)->initParam->assign->variableName = (yyvsp[0].string);
                                                        (yyval.functionParams)->initParam->assign->variableType = str_to_type((yyvsp[-1].string));
                                                        (yyval.functionParams)->initParam->assign->assignValue.val = NULL;
                                                        (yyval.functionParams)->initParam->assign->assignType = CONTENT_TYPE_ID;
                                                    }
#line 1512 "parser.tab.c"
    break;

  case 21: /* functionParams: content  */
#line 269 "parser.y"
                                                    {
                                                        (yyval.functionParams) = malloc(sizeof(struct AstNodeFunctionParams));
                                                        printf("AstNodeFunctionParams allocated for 'content'\n");
                                                        (yyval.functionParams)->nextParams = NULL;
                                                        (yyval.functionParams)->callParams = (yyvsp[0].operand);
                                                        (yyval.functionParams)->initParam = NULL;
                                                    }
#line 1524 "parser.tab.c"
    break;

  case 22: /* functionParams: types ID COMMA functionParams  */
#line 276 "parser.y"
                                                    {
                                                        (yyval.functionParams) = malloc(sizeof(struct AstNodeFunctionParams));
                                                        printf("AstNodeFunctionParams allocated for 'types ID COMMA functionParams'\n");
                                                        (yyval.functionParams)->nextParams = (yyvsp[0].functionParams);
                                                        (yyval.functionParams)->callParams = NULL;
                                                        (yyval.functionParams)->initParam = malloc(sizeof(struct AstNodeInit));
                                                        (yyval.functionParams)->initParam->dataType = str_to_type((yyvsp[-3].string));
                                                        (yyval.functionParams)->initParam->nextInit = NULL;
                                                        (yyval.functionParams)->initParam->assign = malloc(sizeof(struct AstNodeAssign));
                                                        (yyval.functionParams)->initParam->assign->variableName = (yyvsp[-2].string);
                                                        (yyval.functionParams)->initParam->assign->variableType = str_to_type((yyvsp[-3].string));
                                                        (yyval.functionParams)->initParam->assign->assignValue.val = NULL;
                                                        (yyval.functionParams)->initParam->assign->assignType = CONTENT_TYPE_ID;
                                                    }
#line 1543 "parser.tab.c"
    break;

  case 23: /* functionParams: content COMMA functionParams  */
#line 290 "parser.y"
                                                    {
                                                        (yyval.functionParams) = malloc(sizeof(struct AstNodeFunctionParams));
                                                        printf("AstNodeFunctionParams allocated for 'content COMMA functionParams'\n");
                                                        (yyval.functionParams)->nextParams = (yyvsp[0].functionParams);
                                                        (yyval.functionParams)->callParams = (yyvsp[-2].operand);
                                                        (yyval.functionParams)->initParam = NULL;
                                                    }
#line 1555 "parser.tab.c"
    break;

  case 24: /* body: LBRA statements RBRA  */
#line 299 "parser.y"
                                                    {
                                                        (yyval.body) = malloc(sizeof(struct AstNodeBody));
                                                        printf("AstNodeBody allocated for 'LBRA statements RBRA'\n");
                                                        (yyval.body)->bodyStatements = (yyvsp[-1].statements);
                                                        (yyval.body)->returnValue = NULL;
                                                    }
#line 1566 "parser.tab.c"
    break;

  case 25: /* body: LBRA statements RETURN content SEMICOL RBRA  */
#line 305 "parser.y"
                                                    {
                                                        (yyval.body) = malloc(sizeof(struct AstNodeBody));
                                                        printf("AstNodeBody allocated for 'LBRA statements RETURN content SEMICOL RBRA'\n");
                                                        (yyval.body)->bodyStatements = (yyvsp[-4].statements);
                                                        (yyval.body)->returnValue = (yyvsp[-2].operand);
                                                    }
#line 1577 "parser.tab.c"
    break;

  case 26: /* ifStatement: IF LPAR expression RPAR body  */
#line 313 "parser.y"
                                                    {
                                                        (yyval.ifStatement) = malloc(sizeof(struct AstNodeIf));
                                                        printf("AstNodeIf allocated for 'IF LPAR expression RPAR body'\n");
                                                        (yyval.ifStatement)->ifCondition = (yyvsp[-2].expression);
                                                        (yyval.ifStatement)->ifBody = (yyvsp[0].body);
                                                    }
#line 1588 "parser.tab.c"
    break;

  case 27: /* elseifStatement: ELSE IF LPAR expression RPAR body  */
#line 321 "parser.y"
                                                    {
                                                        (yyval.elseifStatement) = malloc(sizeof(struct AstNodeElseIf));
                                                        printf("AstNodeElseIf allocated for 'ELSE IF LPAR expression RPAR body'\n");
                                                        (yyval.elseifStatement)->elseifCondition = (yyvsp[-2].expression);
                                                        (yyval.elseifStatement)->elseifBody = (yyvsp[0].body);
                                                    }
#line 1599 "parser.tab.c"
    break;

  case 28: /* elseStatement: ELSE body  */
#line 329 "parser.y"
                                                    {
                                                        (yyval.elseStatement) = malloc(sizeof(struct AstNodeElse));
                                                        printf("AstNodeElse allocated for 'ELSE body'\n");
                                                        (yyval.elseStatement)->elseBody = (yyvsp[0].body);
                                                    }
#line 1609 "parser.tab.c"
    break;

  case 29: /* arrayInit: types ID LSBRA RSBRA  */
#line 336 "parser.y"
                                                    {
                                                        (yyval.arrayInit) = malloc(sizeof(struct AstNodeArrayInit)); //Error: array size missing in ‘myArray’ !!!
                                                        printf("AstNodeArrayInit allocated for 'types ID LSBRA RSBRA'\n"); //int myArray[];
                                                        (yyval.arrayInit)->arrayType = str_to_type((yyvsp[-3].string));
                                                        (yyval.arrayInit)->assignArray = malloc(sizeof(struct AstNodeArrayAssign));
                                                        printf("AstNodeArrayAssign allocated for 'types ID LSBRA RSBRA'\n");
                                                        (yyval.arrayInit)->assignArray->arrayName = (yyvsp[-2].string);
                                                        (yyval.arrayInit)->assignArray->index = NULL;
                                                        (yyval.arrayInit)->assignArray->arrayType = str_to_type((yyvsp[-3].string));
                                                        (yyval.arrayInit)->assignArray->elements = NULL;
                                                    }
#line 1625 "parser.tab.c"
    break;

  case 30: /* arrayInit: types ID LSBRA INT_VALUE RSBRA  */
#line 347 "parser.y"
                                                    {
                                                        (yyval.arrayInit) = malloc(sizeof(struct AstNodeArrayInit));
                                                        printf("AstNodeArrayInit allocated for 'types ID LSBRA INT_VALUE RSBRA'\n"); //int myArray[4];
                                                        (yyval.arrayInit)->arrayType = str_to_type((yyvsp[-4].string));
                                                        (yyval.arrayInit)->assignArray = malloc(sizeof(struct AstNodeArrayAssign));
                                                        printf("AstNodeArrayAssign allocated for 'types ID LSBRA INT_VALUE RSBRA'\n");
                                                        (yyval.arrayInit)->assignArray->arrayName = str_to_type((yyvsp[-4].string));
                                                        (yyval.arrayInit)->assignArray->index = (yyvsp[-1].string);
                                                        (yyval.arrayInit)->assignArray->arrayType = str_to_type((yyvsp[-4].string));
                                                        (yyval.arrayInit)->assignArray->elements = NULL;
                                                    }
#line 1641 "parser.tab.c"
    break;

  case 31: /* arrayAssign: types ID LSBRA RSBRA EQ LBRA RBRA  */
#line 360 "parser.y"
                                                                {
                                                                    (yyval.arrayAssign) = malloc(sizeof(struct AstNodeArrayAssign));
                                                                    printf("AstNodeArrayAssign allocated for 'types ID LSBRA RSBRA EQ LBRA RBRA'\n"); //int myArray[] = {};
                                                                    (yyval.arrayAssign)->arrayName = (yyvsp[-5].string); 
                                                                    (yyval.arrayAssign)->index = NULL;
                                                                    (yyval.arrayAssign)->arrayType = str_to_type((yyvsp[-6].string));
                                                                    (yyval.arrayAssign)->elements = NULL; //Outuput: array[0]: 0, array[1]: memoryAddress
                                                                }
#line 1654 "parser.tab.c"
    break;

  case 32: /* arrayAssign: types ID LSBRA INT_VALUE RSBRA EQ content  */
#line 368 "parser.y"
                                                                {
                                                                    (yyval.arrayAssign) = malloc(sizeof(struct AstNodeArrayAssign));
                                                                    printf("AstNodeArrayAssign allocated for 'types ID LSBRA INT_VALUE RSBRA EQ content'\n"); //int myArray[2] = 24;
                                                                    (yyval.arrayAssign)->arrayName = (yyvsp[-5].string); 
                                                                    (yyval.arrayAssign)->index = (yyvsp[-3].string);
                                                                    (yyval.arrayAssign)->arrayType = str_to_type((yyvsp[-6].string));
                                                                    (yyval.arrayAssign)->elements = (yyvsp[-3].string);
                                                                }
#line 1667 "parser.tab.c"
    break;

  case 33: /* arrayAssign: types ID LSBRA RSBRA EQ LBRA arrayElements RBRA  */
#line 376 "parser.y"
                                                                {
                                                                    (yyval.arrayAssign) = malloc(sizeof(struct AstNodeArrayAssign));
                                                                    printf("AstNodeArrayAssign allocated for 'types ID LSBRA RSBRA EQ LBRA elements RBRA'\n"); //int myArray[] = {24, 27, 29};
                                                                    (yyval.arrayAssign)->arrayName = (yyvsp[-6].string); 
                                                                    (yyval.arrayAssign)->index = NULL; //TO-DO: compute index as # of elements
                                                                    (yyval.arrayAssign)->arrayType = str_to_type((yyvsp[-7].string));
                                                                    (yyval.arrayAssign)->elements = (yyvsp[-1].arrayElements);
                                                                }
#line 1680 "parser.tab.c"
    break;

  case 34: /* arrayAssign: types ID LSBRA INT_VALUE RSBRA EQ LBRA arrayElements RBRA  */
#line 384 "parser.y"
                                                                {
                                                                    (yyval.arrayAssign) = malloc(sizeof(struct AstNodeArrayAssign));
                                                                    printf("AstNodeArrayAssign allocated for 'types ID LSBRA INT_VALUE RSBRA EQ LBRA elements RBRA'\n"); //int myArray[3] = {24, 27, 29};
                                                                    (yyval.arrayAssign)->arrayName = (yyvsp[-7].string); 
                                                                    (yyval.arrayAssign)->index = (yyvsp[-5].string);
                                                                    (yyval.arrayAssign)->arrayType = str_to_type((yyvsp[-8].string));
                                                                    (yyval.arrayAssign)->elements = (yyvsp[-1].arrayElements);
                                                                }
#line 1693 "parser.tab.c"
    break;

  case 35: /* arrayAssign: ID LSBRA RSBRA EQ LBRA RBRA  */
#line 392 "parser.y"
                                                                {
                                                                    (yyval.arrayAssign) = malloc(sizeof(struct AstNodeArrayAssign)); //Syntax Error !!!
                                                                    printf("AstNodeArrayAssign allocated for 'ID LSBRA RSBRA EQ LBRA RBRA'\n"); //myArray[] = {};
                                                                    (yyval.arrayAssign)->arrayName = (yyvsp[-5].string); 
                                                                    (yyval.arrayAssign)->index = NULL;
                                                                    (yyval.arrayAssign)->arrayType = str_to_type((yyvsp[-5].string));
                                                                    (yyval.arrayAssign)->elements = NULL;
                                                                }
#line 1706 "parser.tab.c"
    break;

  case 36: /* arrayAssign: ID LSBRA INT_VALUE RSBRA EQ content  */
#line 400 "parser.y"
                                                                {
                                                                    (yyval.arrayAssign) = malloc(sizeof(struct AstNodeArrayAssign));
                                                                    printf("AstNodeArrayAssign allocated for 'ID LSBRA INT_VALUE RSBRA EQ content'\n"); // myArray[2] = 24;
                                                                    (yyval.arrayAssign)->arrayName = (yyvsp[-5].string); 
                                                                    (yyval.arrayAssign)->index = (yyvsp[-3].string);
                                                                    (yyval.arrayAssign)->arrayType = (yyvsp[0].operand)->valueType;
                                                                    (yyval.arrayAssign)->elements = (yyvsp[0].operand);
                                                                }
#line 1719 "parser.tab.c"
    break;

  case 37: /* arrayAssign: ID LSBRA RSBRA EQ LBRA arrayElements RBRA  */
#line 408 "parser.y"
                                                                 {
                                                                    (yyval.arrayAssign) = malloc(sizeof(struct AstNodeArrayAssign));
                                                                    printf("AstNodeArrayAssign allocated for 'ID LSBRA RSBRA EQ LBRA elements RBRA'\n"); //myArray[] = {24, 27, 29};
                                                                    (yyval.arrayAssign)->arrayName = (yyvsp[-6].string); 
                                                                    (yyval.arrayAssign)->index = NULL; //TO-DO: compute index as # of elements
                                                                    (yyval.arrayAssign)->arrayType = (yyvsp[-1].arrayElements)->element->valueType; //TO-DO: accedere ai tipi di element e non di content, tipo $7->element->valueType
                                                                    (yyval.arrayAssign)->elements = (yyvsp[-1].arrayElements);
                                                                }
#line 1732 "parser.tab.c"
    break;

  case 38: /* arrayAssign: ID LSBRA INT_VALUE RSBRA EQ LBRA arrayElements RBRA  */
#line 416 "parser.y"
                                                                {
                                                                    (yyval.arrayAssign) = malloc(sizeof(struct AstNodeArrayAssign));
                                                                    printf("AstNodeArrayAssign allocated for 'ID LSBRA INT_VALUE RSBRA EQ LBRA elements RBRA'\n"); //myArray[3] = {24, 27, 29};
                                                                    (yyval.arrayAssign)->arrayName = (yyvsp[-7].string); 
                                                                    (yyval.arrayAssign)->index = (yyvsp[-5].string);
                                                                    (yyval.arrayAssign)->arrayType = (yyvsp[-1].arrayElements)->element->valueType; //TO-DO: accedere ai tipi di element e non di content, tipo $7->element->valueType
                                                                    (yyval.arrayAssign)->elements = (yyvsp[-1].arrayElements);
                                                                }
#line 1745 "parser.tab.c"
    break;

  case 39: /* arrayElements: content  */
#line 426 "parser.y"
                                                                {
                                                                    (yyval.arrayElements) = malloc(sizeof(struct AstNodeArrayElements));
                                                                    printf("AstNodeArrayElements allocated for 'content': %s\n", (yyvsp[0].operand)->value.val); // 4 -> single element in array
                                                                    (yyval.arrayElements)->element = (yyvsp[0].operand);
                                                                    (yyval.arrayElements)->nextElement = NULL;
                                                                }
#line 1756 "parser.tab.c"
    break;

  case 40: /* arrayElements: content COMMA arrayElements  */
#line 432 "parser.y"
                                                                {
                                                                    (yyval.arrayElements) = malloc(sizeof(struct AstNodeArrayElements)); // 4, 5, 6 -> multiple elements in array
                                                                    printf("AstNodeArrayElements allocated for 'content COMMA elements': %s\n", (yyvsp[-2].operand)->value.val);
                                                                    (yyval.arrayElements)->element = (yyvsp[-2].operand);
                                                                    (yyval.arrayElements)->nextElement = (yyvsp[0].arrayElements);
                                                                }
#line 1767 "parser.tab.c"
    break;

  case 41: /* initialization: types ID  */
#line 440 "parser.y"
                                                    {
                                                        (yyval.init) = malloc(sizeof(struct AstNodeInit));
                                                        printf("AstNodeInit allocated for 'types ID'\n");
                                                        (yyval.init)->dataType = str_to_type((yyvsp[-1].string));
                                                        (yyval.init)->nextInit = NULL;
                                                        (yyval.init)->assign = malloc(sizeof(struct AstNodeAssign));
                                                        printf("AstNodeAssign allocated for 'types ID'\n");
                                                        (yyval.init)->assign->variableName = (yyvsp[0].string);
                                                        (yyval.init)->assign->variableType = str_to_type((yyvsp[-1].string));
                                                        (yyval.init)->assign->assignValue.val = NULL;   
                                                        (yyval.init)->assign->assignType = CONTENT_TYPE_ID;  
                                                    }
#line 1784 "parser.tab.c"
    break;

  case 42: /* assignment: ID EQ ID  */
#line 454 "parser.y"
                                                    {
                                                        (yyval.assign) = malloc(sizeof(struct AstNodeAssign));
                                                        printf("AstNodeAssign allocated for 'ID EQ ID'\n");
                                                        (yyval.assign)->variableName = (yyvsp[-2].string);
                                                        (yyval.assign)->assignType = CONTENT_TYPE_ID;
                                                        (yyval.assign)->assignValue.val = (yyvsp[0].string);
                                                        struct SymTab *s = findSym((yyvsp[0].string), actualList);
                                                        if (s == NULL) {
                                                            (yyval.assign)->variableType = DATA_TYPE_NONE; 
                                                            printf("ID EQ ID non esiste dollaro3 nella symtab\n");
                                                        } else {
                                                            (yyval.assign)->variableType = s->dataType;
                                                            printf("ID EQ ID esiste dollaro3 nella symtab\n");
                                                        }
                                                    }
#line 1804 "parser.tab.c"
    break;

  case 43: /* assignment: types ID EQ content  */
#line 469 "parser.y"
                                                    {
                                                        struct SymTab *s = NULL;  //sarà diverso da NULL solo se trova il simbolo
                                                        s = findSym((yyvsp[-2].string), actualList);  //controlla se il simbolo è stato già dichiarato
                                                        if (s==NULL) {
                                                            s = createSym((yyvsp[-2].string), actualList, SYMBOL_VARIABLE, str_to_type((yyvsp[-3].string)), str_to_type((yyvsp[-3].string)), NULL, (yyvsp[0].operand)->value);
                                                            printf("'types ID EQ content': the variable %s has not already been declared and then I create the symbol table for this variable\n", (yyvsp[-2].string));
                                                        } else {
                                                            printf("Error: variable %s already declared\n", (yyvsp[-2].string));
                                                        }
                                                        if ((str_to_type((yyvsp[-3].string)) != (yyvsp[0].operand)->valueType)) {
                                                            printf("Error: Cannot assign type %s to type %s \n", type_to_str((yyvsp[0].operand)->valueType), type_to_str((yyvsp[-3].string)));
                                                        } else {
                                                            (yyval.assign) = malloc(sizeof(struct AstNodeAssign));
                                                            printf("AstNodeAssign allocated for 'types ID EQ content'\n");
                                                            (yyval.assign)->variableName = (yyvsp[-2].string);
                                                            (yyval.assign)->variableType = str_to_type((yyvsp[-3].string));
                                                            (yyval.assign)->assignValue.val = (yyvsp[0].operand)->value.val; 
                                                            (yyval.assign)->assignType = (yyvsp[0].operand)->contentType;
                                                        }
                                                    }
#line 1829 "parser.tab.c"
    break;

  case 44: /* assignment: ID EQ content  */
#line 489 "parser.y"
                                                    {
                                                        (yyval.assign) = malloc(sizeof(struct AstNodeAssign)); //inserire qui la verifica che int a sia stato dichiarato prima di fare a = qualcosa
                                                        printf("AstNodeAssign allocated for 'ID EQ content'\n");
                                                        (yyval.assign)->variableName = (yyvsp[-2].string);
                                                        (yyval.assign)->variableType = (yyvsp[0].operand)->valueType;
                                                        (yyval.assign)->assignValue = (yyvsp[0].operand)->value;   //forse va- assignValue.val ma fors no perche- anche $3 e' generico
                                                        (yyval.assign)->assignType = (yyvsp[0].operand)->contentType;
                                                    }
#line 1842 "parser.tab.c"
    break;

  case 45: /* expression: content ADD content  */
#line 499 "parser.y"
                                                    {
                                                        (yyval.expression) = malloc(sizeof(struct AstNodeExpression));
                                                        printf("AstNodeExpression allocated for 'content ADD content'\n");
                                                        (yyval.expression)->leftOper = malloc(sizeof(struct AstNodeOperand));
                                                        (yyval.expression)->rightOper = malloc(sizeof(struct AstNodeOperand)); 
                                                        (yyval.expression)->leftOper = (yyvsp[-2].operand);   
                                                        (yyval.expression)->op = (yyvsp[-1].string);  
                                                        (yyval.expression)->rightOper = (yyvsp[0].operand); 
                                                        (yyval.expression)->exprType = (yyvsp[-2].operand)->valueType;    
                                                        if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_CHAR || (yyvsp[0].operand)->valueType == DATA_TYPE_CHAR) {
                                                            printf("\n Errore! Impossibile sommare variabili di tipo char");
                                                        } else if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_VOID || (yyvsp[0].operand)->valueType == DATA_TYPE_VOID) { 
                                                            printf("\n Errore! Impossibile sommare variabili di tipo void");
                                                        } else if ((yyvsp[-2].operand)->valueType != (yyvsp[0].operand)->valueType) { 
                                                            printf("\n Errore! Impossibile sommare variabili di tipi diversi"); 
                                                        } else {
                                                            printf("Expression di tipo somma \n");
                                                        }                
                                                    }
#line 1866 "parser.tab.c"
    break;

  case 46: /* expression: content SUB content  */
#line 518 "parser.y"
                                                    {
                                                        (yyval.expression) = malloc(sizeof(struct AstNodeExpression));
                                                        printf("AstNodeExpression allocated for 'content SUB content'\n");
                                                        (yyval.expression)->leftOper = malloc(sizeof(struct AstNodeOperand));
                                                        (yyval.expression)->rightOper = malloc(sizeof(struct AstNodeOperand));
                                                        (yyval.expression)->leftOper = (yyvsp[-2].operand);
                                                        (yyval.expression)->op = (yyvsp[-1].string);
                                                        (yyval.expression)->rightOper = (yyvsp[0].operand);
                                                        (yyval.expression)->exprType = (yyvsp[-2].operand)->valueType;
                                                        if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_CHAR || (yyvsp[0].operand)->valueType == DATA_TYPE_CHAR) {
                                                            printf("\n Errore! Impossibile sottrarre variabili di tipo char");
                                                        } else if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_VOID || (yyvsp[0].operand)->valueType == DATA_TYPE_VOID) { 
                                                            printf("\n Errore! Impossibile sottrare variabili di tipo void");
                                                        } else if ((yyvsp[-2].operand)->valueType != (yyvsp[0].operand)->valueType) { 
                                                            printf("\n Errore! Impossibile sottrarre variabili di tipi diversi"); 
                                                        } else {
                                                            printf("Expression di tipo sottrazione \n");
                                                        }
                                                    }
#line 1890 "parser.tab.c"
    break;

  case 47: /* expression: content MUL content  */
#line 537 "parser.y"
                                                    {
                                                        (yyval.expression) = malloc(sizeof(struct AstNodeExpression));
                                                        printf("AstNodeExpression allocated for 'content MUL content'\n");
                                                        (yyval.expression)->leftOper = malloc(sizeof(struct AstNodeOperand));
                                                        (yyval.expression)->rightOper = malloc(sizeof(struct AstNodeOperand));
                                                        (yyval.expression)->leftOper = (yyvsp[-2].operand);
                                                        (yyval.expression)->op = (yyvsp[-1].string);
                                                        (yyval.expression)->rightOper = (yyvsp[0].operand);
                                                        (yyval.expression)->exprType = (yyvsp[-2].operand)->valueType;
                                                        if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_CHAR || (yyvsp[0].operand)->valueType == DATA_TYPE_CHAR) {
                                                            printf("\n Errore! Impossibile moltiplicare variabili di tipo char");
                                                        } else if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_VOID || (yyvsp[0].operand)->valueType == DATA_TYPE_VOID) { 
                                                            printf("\n Errore! Impossibile moltiplicare variabili di tipo void");
                                                        } else if ((yyvsp[-2].operand)->valueType != (yyvsp[0].operand)->valueType) { 
                                                            printf("\n Errore! Impossibile moltiplicare variabili di tipi diversi"); 
                                                        } else {
                                                            printf("Expression di tipo moltiplicazione \n");
                                                        }
                                                    }
#line 1914 "parser.tab.c"
    break;

  case 48: /* expression: content DIV content  */
#line 556 "parser.y"
                                                    {
                                                        (yyval.expression) = malloc(sizeof(struct AstNodeExpression));
                                                        printf("AstNodeExpression allocated for 'content DIV content'\n");
                                                        (yyval.expression)->leftOper = malloc(sizeof(struct AstNodeOperand));
                                                        (yyval.expression)->rightOper = malloc(sizeof(struct AstNodeOperand));
                                                        (yyval.expression)->leftOper = (yyvsp[-2].operand);
                                                        (yyval.expression)->op = (yyvsp[-1].string);
                                                        (yyval.expression)->rightOper = (yyvsp[0].operand);
                                                        (yyval.expression)->exprType = DATA_TYPE_FLOAT; //forziamo il tipo a Float essendo una divisione
                                                        if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_CHAR || (yyvsp[0].operand)->valueType == DATA_TYPE_CHAR) {
                                                            printf("\n Errore! Impossibile dividere variabili di tipo char");
                                                        } else if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_VOID || (yyvsp[0].operand)->valueType == DATA_TYPE_VOID) { 
                                                            printf("\n Errore! Impossibile dividere variabili di tipo void");
                                                        } else if ((yyvsp[-2].operand)->valueType != (yyvsp[0].operand)->valueType) { 
                                                            printf("\n Errore! Impossibile dividere variabili di tipi diversi"); 
                                                        } else {
                                                            printf("Expression di tipo divisione \n");
                                                        }
                                                    }
#line 1938 "parser.tab.c"
    break;

  case 49: /* expression: content EE content  */
#line 575 "parser.y"
                                                    {
                                                        (yyval.expression) = malloc(sizeof(struct AstNodeExpression));
                                                        printf("AstNodeExpression allocated for 'content EE content'\n");
                                                        (yyval.expression)->leftOper = malloc(sizeof(struct AstNodeOperand));
                                                        (yyval.expression)->rightOper = malloc(sizeof(struct AstNodeOperand));
                                                        (yyval.expression)->leftOper = (yyvsp[-2].operand);
                                                        (yyval.expression)->op = (yyvsp[-1].string);
                                                        (yyval.expression)->rightOper = (yyvsp[0].operand);
                                                        (yyval.expression)->exprType = DATA_TYPE_INT;
                                                        printf("Expression di tipo Equal to \n");
                                                    }
#line 1954 "parser.tab.c"
    break;

  case 50: /* expression: content NE content  */
#line 586 "parser.y"
                                                    {
                                                        (yyval.expression) = malloc(sizeof(struct AstNodeExpression));
                                                        printf("AstNodeExpression allocated for 'content NE content'\n");
                                                        (yyval.expression)->leftOper = malloc(sizeof(struct AstNodeOperand));
                                                        (yyval.expression)->rightOper = malloc(sizeof(struct AstNodeOperand));
                                                        (yyval.expression)->leftOper = (yyvsp[-2].operand);
                                                        (yyval.expression)->op = (yyvsp[-1].string);
                                                        (yyval.expression)->rightOper = (yyvsp[0].operand);
                                                        (yyval.expression)->exprType = DATA_TYPE_INT;
                                                        printf("Expression di tipo Not Equal \n");
                                                    }
#line 1970 "parser.tab.c"
    break;

  case 51: /* expression: content GT content  */
#line 597 "parser.y"
                                                    {
                                                        (yyval.expression) = malloc(sizeof(struct AstNodeExpression));
                                                        printf("AstNodeExpression allocated for 'content GT content'\n");
                                                        (yyval.expression)->leftOper = malloc(sizeof(struct AstNodeOperand));
                                                        (yyval.expression)->rightOper = malloc(sizeof(struct AstNodeOperand));
                                                        (yyval.expression)->leftOper = (yyvsp[-2].operand);
                                                        (yyval.expression)->op = (yyvsp[-1].string);
                                                        (yyval.expression)->rightOper = (yyvsp[0].operand);
                                                        (yyval.expression)->exprType = DATA_TYPE_INT;
                                                        if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_CHAR || (yyvsp[0].operand)->valueType == DATA_TYPE_CHAR) {
                                                            printf("\n Errore! Impossibile confrontare variabili di tipo char");
                                                        } else if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_VOID || (yyvsp[0].operand)->valueType == DATA_TYPE_VOID) { 
                                                            printf("\n Errore! Impossibile confrontare variabili di tipo void");
                                                        } else {
                                                            printf("Expression di tipo Greater than \n");
                                                        }
                                                    }
#line 1992 "parser.tab.c"
    break;

  case 52: /* expression: content LT content  */
#line 614 "parser.y"
                                                    {
                                                        (yyval.expression) = malloc(sizeof(struct AstNodeExpression));
                                                        printf("AstNodeExpression allocated for 'content LT content'\n");
                                                        (yyval.expression)->leftOper = malloc(sizeof(struct AstNodeOperand));
                                                        (yyval.expression)->rightOper = malloc(sizeof(struct AstNodeOperand));
                                                        (yyval.expression)->leftOper = (yyvsp[-2].operand);
                                                        (yyval.expression)->op = (yyvsp[-1].string);
                                                        (yyval.expression)->rightOper = (yyvsp[0].operand);
                                                        (yyval.expression)->exprType = DATA_TYPE_INT;
                                                        if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_CHAR || (yyvsp[0].operand)->valueType == DATA_TYPE_CHAR) {
                                                            printf("\n Errore! Impossibile confrontare variabili di tipo char");
                                                        } else if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_VOID || (yyvsp[0].operand)->valueType == DATA_TYPE_VOID) { 
                                                            printf("\n Errore! Impossibile confrontare variabili di tipo void");
                                                        } else {
                                                            printf("Expression di tipo Less than \n");
                                                        }
                                                    }
#line 2014 "parser.tab.c"
    break;

  case 53: /* expression: content GE content  */
#line 631 "parser.y"
                                                    {
                                                        (yyval.expression) = malloc(sizeof(struct AstNodeExpression));
                                                        printf("AstNodeExpression allocated for 'content GE content'\n");
                                                        (yyval.expression)->leftOper = malloc(sizeof(struct AstNodeOperand));
                                                        (yyval.expression)->rightOper = malloc(sizeof(struct AstNodeOperand));
                                                        (yyval.expression)->leftOper = (yyvsp[-2].operand);
                                                        (yyval.expression)->op = (yyvsp[-1].string);
                                                        (yyval.expression)->rightOper = (yyvsp[0].operand);
                                                        (yyval.expression)->exprType = DATA_TYPE_INT;
                                                        if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_CHAR || (yyvsp[0].operand)->valueType == DATA_TYPE_CHAR) {
                                                            printf("\n Errore! Impossibile confrontare variabili di tipo char");
                                                        } else if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_VOID || (yyvsp[0].operand)->valueType == DATA_TYPE_VOID) { 
                                                            printf("\n Errore! Impossibile confrontare variabili di tipo void");
                                                        } else {
                                                            printf("Expression di tipo Greater than or equal to \n");
                                                        }
                                                    }
#line 2036 "parser.tab.c"
    break;

  case 54: /* expression: content LE content  */
#line 648 "parser.y"
                                                    {
                                                        (yyval.expression) = malloc(sizeof(struct AstNodeExpression));
                                                        printf("AstNodeExpression allocated for 'content LE content'\n");
                                                        (yyval.expression)->leftOper = malloc(sizeof(struct AstNodeOperand));
                                                        (yyval.expression)->rightOper = malloc(sizeof(struct AstNodeOperand));
                                                        (yyval.expression)->leftOper = (yyvsp[-2].operand);
                                                        (yyval.expression)->op = (yyvsp[-1].string);
                                                        (yyval.expression)->rightOper = (yyvsp[0].operand);
                                                        (yyval.expression)->exprType = DATA_TYPE_INT;
                                                        if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_CHAR || (yyvsp[0].operand)->valueType == DATA_TYPE_CHAR) {
                                                            printf("\n Errore! Impossibile confrontare variabili di tipo char");
                                                        } else if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_VOID || (yyvsp[0].operand)->valueType == DATA_TYPE_VOID) { 
                                                            printf("\n Errore! Impossibile confrontare variabili di tipo void");
                                                        } else {
                                                            printf("Expression di tipo Less than or equal to \n");
                                                        }
                                                    }
#line 2058 "parser.tab.c"
    break;

  case 55: /* expression: content AND content  */
#line 665 "parser.y"
                                                    {
                                                        (yyval.expression) = malloc(sizeof(struct AstNodeExpression));
                                                        printf("AstNodeExpression allocated for 'content AND content'\n");
                                                        (yyval.expression)->leftOper = malloc(sizeof(struct AstNodeOperand));
                                                        (yyval.expression)->rightOper = malloc(sizeof(struct AstNodeOperand));
                                                        (yyval.expression)->leftOper = (yyvsp[-2].operand);
                                                        (yyval.expression)->op = (yyvsp[-1].string);
                                                        (yyval.expression)->rightOper = (yyvsp[0].operand);
                                                        (yyval.expression)->exprType = DATA_TYPE_INT;
                                                        if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_CHAR || (yyvsp[0].operand)->valueType == DATA_TYPE_CHAR) {
                                                            printf("\n Errore! Impossibile confrontare variabili di tipo char");
                                                        } else if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_VOID || (yyvsp[0].operand)->valueType == DATA_TYPE_VOID) { 
                                                            printf("\n Errore! Impossibile confrontare variabili di tipo void");
                                                        } else {
                                                            printf("Expression di tipo AND \n");
                                                        }
                                                    }
#line 2080 "parser.tab.c"
    break;

  case 56: /* expression: content OR content  */
#line 682 "parser.y"
                                                    {
                                                        (yyval.expression) = malloc(sizeof(struct AstNodeExpression));
                                                        printf("AstNodeExpression allocated for 'content OR content'\n");
                                                        (yyval.expression)->leftOper = malloc(sizeof(struct AstNodeOperand));
                                                        (yyval.expression)->rightOper = malloc(sizeof(struct AstNodeOperand));
                                                        (yyval.expression)->leftOper = (yyvsp[-2].operand);
                                                        (yyval.expression)->op = (yyvsp[-1].string);
                                                        (yyval.expression)->rightOper = (yyvsp[0].operand);
                                                        (yyval.expression)->exprType = DATA_TYPE_INT;
                                                        if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_CHAR || (yyvsp[0].operand)->valueType == DATA_TYPE_CHAR) {
                                                            printf("\n Errore! Impossibile confrontare variabili di tipo char");
                                                        } else if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_VOID || (yyvsp[0].operand)->valueType == DATA_TYPE_VOID) { 
                                                            printf("\n Errore! Impossibile confrontare variabili di tipo void");
                                                        } else {
                                                            printf("Expression di tipo OR \n");
                                                        }
                                                    }
#line 2102 "parser.tab.c"
    break;

  case 57: /* expression: NOT content  */
#line 699 "parser.y"
                                                    {
                                                        (yyval.expression) = malloc(sizeof(struct AstNodeExpression));
                                                        printf("AstNodeExpression allocated for 'NOT content'\n");
                                                        (yyval.expression)->leftOper = malloc(sizeof(struct AstNodeOperand));
                                                        (yyval.expression)->rightOper = malloc(sizeof(struct AstNodeOperand));
                                                        (yyval.expression)->op = (yyvsp[-1].string);
                                                        (yyval.expression)->leftOper = (yyvsp[0].operand);
                                                        (yyval.expression)->rightOper = NULL;
                                                        (yyval.expression)->exprType = DATA_TYPE_INT;
                                                        if  ((yyvsp[0].operand)->valueType == DATA_TYPE_CHAR) {
                                                            printf("\n Errore! Impossibile confrontare variabili di tipo char");
                                                        } else if  ((yyvsp[0].operand)->valueType == DATA_TYPE_VOID) { 
                                                            printf("\n Errore! Impossibile confrontare variabili di tipo void");
                                                        } else {
                                                            printf("Expression di tipo NOT \n");
                                                        }
                                                    }
#line 2124 "parser.tab.c"
    break;

  case 58: /* content: ID  */
#line 718 "parser.y"
                                                    {
                                                        (yyval.operand) = malloc(sizeof(struct AstNodeOperand));
                                                        printf("AstNodeOperand allocated for 'ID'\n"); //Ci troviamo nel caso in cui abbiamo int a = b
                                                        struct SymTab *s = findSymtab((yyvsp[0].string),actualList);
                                                        if(s == NULL) { 
                                                            (yyval.operand)->valueType = DATA_TYPE_NONE; 
                                                        } else {
                                                            (yyval.operand)->value.val = (yyvsp[0].string);
                                                            (yyval.operand)->valueType = s->dataType;
                                                            (yyval.operand)->contentType = CONTENT_TYPE_ID;
                                                        }
                                                    }
#line 2141 "parser.tab.c"
    break;

  case 59: /* content: INT_VALUE  */
#line 730 "parser.y"
                                                    {       
                                                        (yyval.operand) = malloc(sizeof(struct AstNodeOperand));
                                                        printf("AstNodeOperand allocated for 'INT_VALUE'\n");
                                                        (yyval.operand)->value.val = (yyvsp[0].string);
                                                        (yyval.operand)->valueType = DATA_TYPE_INT; 
                                                        (yyval.operand)->contentType = CONTENT_TYPE_INT_NUMBER;
                                                    }
#line 2153 "parser.tab.c"
    break;

  case 60: /* content: FLOAT_VALUE  */
#line 737 "parser.y"
                                                    {
                                                        (yyval.operand) = malloc(sizeof(struct AstNodeOperand));
                                                        printf("AstNodeOperand allocated for 'FLOAT_VALUE'\n");
                                                        (yyval.operand)->value.val = (yyvsp[0].string);
                                                        (yyval.operand)->valueType = DATA_TYPE_FLOAT; 
                                                        (yyval.operand)->contentType = CONTENT_TYPE_FLOAT_NUMBER;
                                                    }
#line 2165 "parser.tab.c"
    break;

  case 61: /* content: CHAR_VALUE  */
#line 744 "parser.y"
                                                    {
                                                        (yyval.operand) = malloc(sizeof(struct AstNodeOperand));
                                                        printf("AstNodeOperand allocated for 'CHAR_VALUE'\n");
                                                        (yyval.operand)->value.val = (yyvsp[0].string);
                                                        (yyval.operand)->valueType = DATA_TYPE_CHAR;  
                                                        (yyval.operand)->contentType = CONTENT_TYPE_CHAR;
                                                    }
#line 2177 "parser.tab.c"
    break;

  case 62: /* content: expression  */
#line 751 "parser.y"
                                                    {
                                                        (yyval.operand) = malloc(sizeof(struct AstNodeOperand));
                                                        printf("AstNodeOperand allocated for 'expression'\n");
                                                        (yyval.operand)->value.expression = (yyvsp[0].expression);
                                                        (yyval.operand)->valueType = (yyvsp[0].expression)->exprType;  
                                                        (yyval.operand)->contentType = CONTENT_TYPE_EXPRESSION;
                                                    }
#line 2189 "parser.tab.c"
    break;

  case 63: /* content: functionCall  */
#line 758 "parser.y"
                                                    {
                                                        (yyval.operand) = malloc(sizeof(struct AstNodeOperand));
                                                        printf("AstNodeOperand allocated for 'functionCall'\n");
                                                        (yyval.operand)->value.funtionCall = (yyvsp[0].functionCall);
                                                        (yyval.operand)->valueType = (yyvsp[0].functionCall)->returnType;  
                                                        (yyval.operand)->contentType = CONTENT_TYPE_FUNCTION;
                                                    }
#line 2201 "parser.tab.c"
    break;

  case 64: /* types: VOID  */
#line 767 "parser.y"
                                                    {
                                                        (yyval.string) = DATA_TYPE_VOID;
                                                        printf("Defined 'type: VOID'\n");
                                                    }
#line 2210 "parser.tab.c"
    break;

  case 65: /* types: INT  */
#line 771 "parser.y"
                                                    {
                                                        (yyval.string) = DATA_TYPE_INT;
                                                        printf("Defined 'type: INT'\n");
                                                    }
#line 2219 "parser.tab.c"
    break;

  case 66: /* types: FLOAT  */
#line 775 "parser.y"
                                                    {
                                                        (yyval.string) = DATA_TYPE_FLOAT;
                                                        printf("Defined 'type: FLOAT'\n");
                                                    }
#line 2228 "parser.tab.c"
    break;

  case 67: /* types: CHAR  */
#line 779 "parser.y"
                                                    {
                                                        (yyval.string) = DATA_TYPE_CHAR;
                                                        printf("Defined 'type: CHAR'\n");
                                                    }
#line 2237 "parser.tab.c"
    break;


#line 2241 "parser.tab.c"

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
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
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 784 "parser.y"


int main() {
    yyparse();
    nullValue.val = NULL;
    counter = 0;

    return 0;
}

int yyerror(char *s) {
    printf("%s\n", s);
}

void scope_enter() {
    actualList = createList(counter, actualList);
    counter++;
}

void scope_exit() {
    deleteList(actualList);
    counter--;
}

char* type_to_str(int type) {
    switch(type) {
        case DATA_TYPE_NONE:
            return "none";
        break;
        case DATA_TYPE_VOID:
            return "void";
        break;
        case DATA_TYPE_INT:
            return "int";
        break;
        case DATA_TYPE_FLOAT:
            return "float";
        break;
        case DATA_TYPE_CHAR:
            return "char";
        break;
        default:
            return "undefined";
        break;
    }
}

int str_to_type(int type) {
    if (strcmp(type_to_str(type), "void") == 0) {
        return DATA_TYPE_VOID;
    } else if (strcmp(type_to_str(type), "int") == 0) {
        return DATA_TYPE_INT;
    } else if (strcmp(type_to_str(type), "float") == 0) {
        return DATA_TYPE_FLOAT;
    } else if (strcmp(type_to_str(type), "char") == 0) {
        return DATA_TYPE_CHAR;
    } else {
        return DATA_TYPE_NONE;
    }
}
