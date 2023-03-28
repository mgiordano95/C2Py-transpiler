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
//int str_to_type(int type);

void scope_enter();
void scope_exit();


#line 95 "parser.tab.c"

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
  YYSYMBOL_initialization = 53,            /* initialization  */
  YYSYMBOL_assignment = 54,                /* assignment  */
  YYSYMBOL_expression = 55,                /* expression  */
  YYSYMBOL_content = 56,                   /* content  */
  YYSYMBOL_types = 57                      /* types  */
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
#define YYLAST   160

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  53
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  102

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
       0,    89,    89,    89,    98,   105,   114,   126,   141,   155,
     161,   167,   173,   181,   191,   202,   218,   230,   244,   258,
     265,   279,   288,   294,   302,   310,   318,   325,   339,   354,
     374,   384,   403,   422,   441,   460,   471,   482,   499,   516,
     533,   550,   567,   584,   603,   615,   622,   629,   636,   643,
     652,   656,   660,   664
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
  "elseifStatement", "elseStatement", "initialization", "assignment",
  "expression", "content", "types", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-50)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-29)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -50,    18,    76,   -50,   -50,   -50,   -50,   -50,    -5,    -6,
      39,   -50,    76,   -50,   -28,   -50,   -50,   -50,     6,     5,
      -9,   -22,    -3,    76,   -50,    64,    32,   -50,   -50,    59,
     -50,   -50,    13,    42,   -22,   -50,   -50,    44,   -50,   -50,
      45,   134,   -22,     0,    78,   -50,   134,   -50,    56,   101,
      35,    55,    60,    61,   -22,   134,    55,   -22,   -22,   -22,
     -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,    63,
     -22,   -50,   -50,    72,    58,   -50,    55,    55,   134,   -50,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,    55,   118,   -50,    72,   -50,   -50,   -50,    71,
     -50,   -50
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,    50,    51,    52,    53,     0,     0,
       0,     3,     5,     8,     0,    10,    11,    12,     0,     0,
       0,     0,     0,     0,    26,     0,     0,     4,     9,     0,
       7,     6,     0,    27,     0,    45,    46,    44,    47,    49,
      48,     0,     0,     0,    44,    48,    30,    16,     0,    19,
       0,     0,     0,     0,     0,    43,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
       0,    22,    17,     0,    18,    14,     0,     0,    29,    24,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,     0,     0,    21,     0,    15,    13,    25,     0,
      20,    23
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -50,   -50,   -50,    -4,   -50,   -50,     8,   -29,   -49,   -50,
     -50,   -50,   -50,   -50,   -18,   -12,     9
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,    11,    12,    13,    39,    48,    24,    15,
      16,    17,    18,    19,    45,    49,    50
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      52,    22,    75,    40,    32,    34,    28,    79,    27,    41,
      14,    20,    70,    46,    35,    36,    37,    38,     3,    43,
      14,    20,    55,    21,    69,    42,    23,    96,    97,    33,
      41,    14,    20,    71,    29,     4,     5,     6,     7,    31,
      30,    53,    78,    98,    94,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    25,    93,    34,
      54,    47,     4,     5,     6,     7,   100,    26,    35,    36,
      37,    38,    26,    74,    56,     4,     5,     6,     7,     4,
       5,     6,     7,     8,     9,    72,    34,    23,    51,    76,
      77,    34,    92,    95,     0,    35,    36,    37,    38,    34,
      35,    36,    44,    38,   101,     0,    26,     0,    35,    36,
      37,    38,   -28,     0,    10,    57,    58,    59,    60,     0,
      61,    62,    63,    64,    65,    66,    67,    68,     0,     0,
       0,     0,    57,    58,    59,    60,    73,    61,    62,    63,
      64,    65,    66,    67,    68,     0,     0,     0,    57,    58,
      59,    60,    99,    61,    62,    63,    64,    65,    66,    67,
      68
};

static const yytype_int8 yycheck[] =
{
      29,     7,    51,    21,    13,    27,    34,    56,    12,    21,
       2,     2,    12,    25,    36,    37,    38,    39,     0,    23,
      12,    12,    34,    28,    42,    28,    32,    76,    77,    38,
      42,    23,    23,    33,    28,     3,     4,     5,     6,    34,
      34,    28,    54,    92,    73,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    18,    70,    27,
      18,    29,     3,     4,     5,     6,    95,    28,    36,    37,
      38,    39,    28,    38,    29,     3,     4,     5,     6,     3,
       4,     5,     6,     7,     8,    29,    27,    32,    29,    29,
      29,    27,    29,    35,    -1,    36,    37,    38,    39,    27,
      36,    37,    38,    39,    33,    -1,    28,    -1,    36,    37,
      38,    39,    34,    -1,    38,    14,    15,    16,    17,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    -1,    14,    15,    16,    17,    35,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    14,    15,
      16,    17,    34,    19,    20,    21,    22,    23,    24,    25,
      26
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    42,    43,     0,     3,     4,     5,     6,     7,     8,
      38,    44,    45,    46,    47,    50,    51,    52,    53,    54,
      57,    28,     7,    32,    49,    18,    28,    44,    34,    28,
      34,    34,    13,    38,    27,    36,    37,    38,    39,    47,
      55,    56,    28,    44,    38,    55,    56,    29,    48,    56,
      57,    29,    48,    28,    18,    56,    29,    14,    15,    16,
      17,    19,    20,    21,    22,    23,    24,    25,    26,    55,
      12,    33,    29,    35,    38,    49,    29,    29,    56,    49,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    29,    56,    48,    35,    49,    49,    49,    34,
      48,    33
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    43,    42,    44,    44,    45,    45,    45,    45,
      45,    45,    45,    46,    46,    46,    47,    47,    48,    48,
      48,    48,    49,    49,    50,    51,    52,    53,    54,    54,
      54,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    56,    56,    56,    56,    56,    56,
      57,    57,    57,    57
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     2,     2,     1,     2,
       1,     1,     1,     5,     4,     5,     3,     4,     2,     1,
       4,     3,     3,     6,     5,     6,     2,     2,     3,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
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
#line 89 "parser.y"
                                                    {
                                                        scope_enter();
                                                    }
#line 1217 "parser.tab.c"
    break;

  case 3: /* program: $@1 statements  */
#line 92 "parser.y"
                                                    {
                                                        root = (yyvsp[0].statements);
                                                        scope_exit();
                                                    }
#line 1226 "parser.tab.c"
    break;

  case 4: /* statements: instruction statements  */
#line 98 "parser.y"
                                                    {
                                                        (yyval.statements) = malloc(sizeof(struct AstNodeStatements));
                                                        printf("AstNodeStatements allocated for 'instruction statements'\n");
                                                        (yyval.statements)->nodeType = STATEMENT_NODE;
                                                        (yyval.statements)->currentInstruction = (yyvsp[-1].instruction);
                                                        (yyval.statements)->nextStatement = (yyvsp[0].statements);
                                                    }
#line 1238 "parser.tab.c"
    break;

  case 5: /* statements: instruction  */
#line 105 "parser.y"
                                                    {
                                                        (yyval.statements) = malloc(sizeof(struct AstNodeStatements));
                                                        printf("AstNodeStatements allocated for 'instruction'\n");
                                                        (yyval.statements)->nodeType = STATEMENT_NODE;
                                                        (yyval.statements)->currentInstruction = (yyvsp[0].instruction);
                                                        (yyval.statements)->nextStatement = NULL;
                                                    }
#line 1250 "parser.tab.c"
    break;

  case 6: /* instruction: assignment SEMICOL  */
#line 114 "parser.y"
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
#line 1267 "parser.tab.c"
    break;

  case 7: /* instruction: initialization SEMICOL  */
#line 126 "parser.y"
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
#line 1287 "parser.tab.c"
    break;

  case 8: /* instruction: functionDecl  */
#line 141 "parser.y"
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
#line 1306 "parser.tab.c"
    break;

  case 9: /* instruction: functionCall SEMICOL  */
#line 155 "parser.y"
                                                    {
                                                        (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                        printf("AstNodeInstruction allocated for 'functionCall SEMICOL'\n");
                                                        (yyval.instruction)->nodeType = FUNCTION_CALL_NODE;
                                                        (yyval.instruction)->value.functionCall = (yyvsp[-1].functionCall);
                                                    }
#line 1317 "parser.tab.c"
    break;

  case 10: /* instruction: ifStatement  */
#line 161 "parser.y"
                                                    {
                                                        (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                        printf("AstNodeInstruction allocated for 'ifStatement'\n");
                                                        (yyval.instruction)->nodeType = IF_NODE;
                                                        (yyval.instruction)->value.ifStatement = (yyvsp[0].ifStatement);
                                                    }
#line 1328 "parser.tab.c"
    break;

  case 11: /* instruction: elseifStatement  */
#line 167 "parser.y"
                                                    {
                                                        (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                        printf("AstNodeInstruction allocated for 'ifStatement'\n");
                                                        (yyval.instruction)->nodeType = ELSE_IF_NODE;
                                                        (yyval.instruction)->value.elseifStatement = (yyvsp[0].elseifStatement);
                                                    }
#line 1339 "parser.tab.c"
    break;

  case 12: /* instruction: elseStatement  */
#line 173 "parser.y"
                                                    {
                                                        (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                        printf("AstNodeInstruction allocated for 'ifStatement'\n");
                                                        (yyval.instruction)->nodeType = ELSE_NODE;
                                                        (yyval.instruction)->value.elseStatement = (yyvsp[0].elseStatement);
                                                    }
#line 1350 "parser.tab.c"
    break;

  case 13: /* functionDecl: types MAIN LPAR RPAR body  */
#line 181 "parser.y"
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
#line 1365 "parser.tab.c"
    break;

  case 14: /* functionDecl: initialization LPAR RPAR body  */
#line 191 "parser.y"
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
#line 1381 "parser.tab.c"
    break;

  case 15: /* functionDecl: initialization LPAR functionParams RPAR body  */
#line 202 "parser.y"
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
#line 1400 "parser.tab.c"
    break;

  case 16: /* functionCall: ID LPAR RPAR  */
#line 218 "parser.y"
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
#line 1417 "parser.tab.c"
    break;

  case 17: /* functionCall: ID LPAR functionParams RPAR  */
#line 230 "parser.y"
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
#line 1434 "parser.tab.c"
    break;

  case 18: /* functionParams: types ID  */
#line 244 "parser.y"
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
#line 1453 "parser.tab.c"
    break;

  case 19: /* functionParams: content  */
#line 258 "parser.y"
                                                    {
                                                        (yyval.functionParams) = malloc(sizeof(struct AstNodeFunctionParams));
                                                        printf("AstNodeFunctionParams allocated for 'content'\n");
                                                        (yyval.functionParams)->nextParams = NULL;
                                                        (yyval.functionParams)->callParams = (yyvsp[0].operand);
                                                        (yyval.functionParams)->initParam = NULL;
                                                    }
#line 1465 "parser.tab.c"
    break;

  case 20: /* functionParams: types ID COMMA functionParams  */
#line 265 "parser.y"
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
#line 1484 "parser.tab.c"
    break;

  case 21: /* functionParams: content COMMA functionParams  */
#line 279 "parser.y"
                                                    {
                                                        (yyval.functionParams) = malloc(sizeof(struct AstNodeFunctionParams));
                                                        printf("AstNodeFunctionParams allocated for 'content COMMA functionParams'\n");
                                                        (yyval.functionParams)->nextParams = (yyvsp[0].functionParams);
                                                        (yyval.functionParams)->callParams = (yyvsp[-2].operand);
                                                        (yyval.functionParams)->initParam = NULL;
                                                    }
#line 1496 "parser.tab.c"
    break;

  case 22: /* body: LBRA statements RBRA  */
#line 288 "parser.y"
                                                    {
                                                        (yyval.body) = malloc(sizeof(struct AstNodeBody));
                                                        printf("AstNodeBody allocated for 'LBRA statements RBRA'\n");
                                                        (yyval.body)->bodyStatements = (yyvsp[-1].statements);
                                                        (yyval.body)->returnValue = NULL;
                                                    }
#line 1507 "parser.tab.c"
    break;

  case 23: /* body: LBRA statements RETURN content SEMICOL RBRA  */
#line 294 "parser.y"
                                                    {
                                                        (yyval.body) = malloc(sizeof(struct AstNodeBody));
                                                        printf("AstNodeBody allocated for 'LBRA statements RETURN content SEMICOL RBRA'\n");
                                                        (yyval.body)->bodyStatements = (yyvsp[-4].statements);
                                                        (yyval.body)->returnValue = (yyvsp[-2].operand);
                                                    }
#line 1518 "parser.tab.c"
    break;

  case 24: /* ifStatement: IF LPAR expression RPAR body  */
#line 302 "parser.y"
                                                    {
                                                        (yyval.ifStatement) = malloc(sizeof(struct AstNodeIf));
                                                        printf("AstNodeIf allocated for 'IF LPAR expression RPAR body'\n");
                                                        (yyval.ifStatement)->ifCondition = (yyvsp[-2].expression);
                                                        (yyval.ifStatement)->ifBody = (yyvsp[0].body);
                                                    }
#line 1529 "parser.tab.c"
    break;

  case 25: /* elseifStatement: ELSE IF LPAR expression RPAR body  */
#line 310 "parser.y"
                                                    {
                                                        (yyval.elseifStatement) = malloc(sizeof(struct AstNodeElseIf));
                                                        printf("AstNodeElseIf allocated for 'ELSE IF LPAR expression RPAR body'\n");
                                                        (yyval.elseifStatement)->elseifCondition = (yyvsp[-2].expression);
                                                        (yyval.elseifStatement)->elseifBody = (yyvsp[0].body);
                                                    }
#line 1540 "parser.tab.c"
    break;

  case 26: /* elseStatement: ELSE body  */
#line 318 "parser.y"
                            {
                                                        (yyval.elseStatement) = malloc(sizeof(struct AstNodeElse));
                                                        printf("AstNodeElse allocated for 'ELSE body'\n");
                                                        (yyval.elseStatement)->elseBody = (yyvsp[0].body);
                                                    }
#line 1550 "parser.tab.c"
    break;

  case 27: /* initialization: types ID  */
#line 325 "parser.y"
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
#line 1567 "parser.tab.c"
    break;

  case 28: /* assignment: ID EQ ID  */
#line 339 "parser.y"
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
#line 1587 "parser.tab.c"
    break;

  case 29: /* assignment: types ID EQ content  */
#line 354 "parser.y"
                                                    {
                                                        struct SymTab *s = NULL;  //sarà diverso da NULL solo se trova il simbolo
                                                        s = findSym((yyvsp[-2].string), actualList);  //controlla se il simbolo è stato già dichiarato
                                                        if (s==NULL) {
                                                            s = createSym((yyvsp[-2].string), actualList, SYMBOL_VARIABLE, str_to_type((yyvsp[-3].string)), str_to_type((yyvsp[-3].string)), NULL, (yyvsp[0].operand)->value);
                                                            printf("types ID EQ content non esiste dollaro2 nella symtab e la creo\n");
                                                        } else {
                                                            printf("\n Errore: variabile %s gia' dichiarata \n", (yyvsp[-2].string));
                                                        }
                                                        if ((str_to_type((yyvsp[-3].string)) != (yyvsp[0].operand)->valueType)) {
                                                            //printf("Errore: impossibile assegnare un tipo %s ad un tipo %s \n", type_to_str($4->valueType), type_to_str($1));
                                                        } else {
                                                            (yyval.assign) = malloc(sizeof(struct AstNodeAssign));
                                                            printf("AstNodeAssign allocated for 'types ID EQ content'\n");
                                                            (yyval.assign)->variableName = (yyvsp[-2].string);
                                                            (yyval.assign)->variableType = str_to_type((yyvsp[-3].string));
                                                            (yyval.assign)->assignValue.val = (yyvsp[0].operand)->value.val; 
                                                            (yyval.assign)->assignType = (yyvsp[0].operand)->contentType;
                                                        }
                                                    }
#line 1612 "parser.tab.c"
    break;

  case 30: /* assignment: ID EQ content  */
#line 374 "parser.y"
                                                    {
                                                        (yyval.assign) = malloc(sizeof(struct AstNodeAssign)); //inserire qui la verifica che int a sia stato dichiarato prima di fare a = qualcosa
                                                        printf("AstNodeAssign allocated for 'ID EQ content'\n");
                                                        (yyval.assign)->variableName = (yyvsp[-2].string);
                                                        (yyval.assign)->variableType = (yyvsp[0].operand)->valueType;
                                                        (yyval.assign)->assignValue = (yyvsp[0].operand)->value;   //forse va- assignValue.val ma fors no perche- anche $3 e' generico
                                                        (yyval.assign)->assignType = (yyvsp[0].operand)->contentType;
                                                    }
#line 1625 "parser.tab.c"
    break;

  case 31: /* expression: content ADD content  */
#line 384 "parser.y"
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
#line 1649 "parser.tab.c"
    break;

  case 32: /* expression: content SUB content  */
#line 403 "parser.y"
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
#line 1673 "parser.tab.c"
    break;

  case 33: /* expression: content MUL content  */
#line 422 "parser.y"
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
#line 1697 "parser.tab.c"
    break;

  case 34: /* expression: content DIV content  */
#line 441 "parser.y"
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
#line 1721 "parser.tab.c"
    break;

  case 35: /* expression: content EE content  */
#line 460 "parser.y"
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
#line 1737 "parser.tab.c"
    break;

  case 36: /* expression: content NE content  */
#line 471 "parser.y"
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
#line 1753 "parser.tab.c"
    break;

  case 37: /* expression: content GT content  */
#line 482 "parser.y"
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
#line 1775 "parser.tab.c"
    break;

  case 38: /* expression: content LT content  */
#line 499 "parser.y"
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
#line 1797 "parser.tab.c"
    break;

  case 39: /* expression: content GE content  */
#line 516 "parser.y"
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
#line 1819 "parser.tab.c"
    break;

  case 40: /* expression: content LE content  */
#line 533 "parser.y"
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
#line 1841 "parser.tab.c"
    break;

  case 41: /* expression: content AND content  */
#line 550 "parser.y"
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
#line 1863 "parser.tab.c"
    break;

  case 42: /* expression: content OR content  */
#line 567 "parser.y"
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
#line 1885 "parser.tab.c"
    break;

  case 43: /* expression: NOT content  */
#line 584 "parser.y"
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
#line 1907 "parser.tab.c"
    break;

  case 44: /* content: ID  */
#line 603 "parser.y"
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
#line 1924 "parser.tab.c"
    break;

  case 45: /* content: INT_VALUE  */
#line 615 "parser.y"
                                                    {       
                                                        (yyval.operand) = malloc(sizeof(struct AstNodeOperand));
                                                        printf("AstNodeOperand allocated for 'INT_VALUE'\n");
                                                        (yyval.operand)->value.val = (yyvsp[0].string);
                                                        (yyval.operand)->valueType = DATA_TYPE_INT; 
                                                        (yyval.operand)->contentType = CONTENT_TYPE_INT_NUMBER;
                                                    }
#line 1936 "parser.tab.c"
    break;

  case 46: /* content: FLOAT_VALUE  */
#line 622 "parser.y"
                                                    {
                                                        (yyval.operand) = malloc(sizeof(struct AstNodeOperand));
                                                        printf("AstNodeOperand allocated for 'FLOAT_VALUE'\n");
                                                        (yyval.operand)->value.val = (yyvsp[0].string);
                                                        (yyval.operand)->valueType = DATA_TYPE_FLOAT; 
                                                        (yyval.operand)->contentType = CONTENT_TYPE_FLOAT_NUMBER;
                                                    }
#line 1948 "parser.tab.c"
    break;

  case 47: /* content: CHAR_VALUE  */
#line 629 "parser.y"
                                                    {
                                                        (yyval.operand) = malloc(sizeof(struct AstNodeOperand));
                                                        printf("AstNodeOperand allocated for 'CHAR_VALUE'\n");
                                                        (yyval.operand)->value.val = (yyvsp[0].string);
                                                        (yyval.operand)->valueType = DATA_TYPE_CHAR;  
                                                        (yyval.operand)->contentType = CONTENT_TYPE_CHAR;
                                                    }
#line 1960 "parser.tab.c"
    break;

  case 48: /* content: expression  */
#line 636 "parser.y"
                                                    {
                                                        (yyval.operand) = malloc(sizeof(struct AstNodeOperand));
                                                        printf("AstNodeOperand allocated for 'expression'\n");
                                                        (yyval.operand)->value.expression = (yyvsp[0].expression);
                                                        (yyval.operand)->valueType = (yyvsp[0].expression)->exprType;  
                                                        (yyval.operand)->contentType = CONTENT_TYPE_EXPRESSION;
                                                    }
#line 1972 "parser.tab.c"
    break;

  case 49: /* content: functionCall  */
#line 643 "parser.y"
                                                    {
                                                        (yyval.operand) = malloc(sizeof(struct AstNodeOperand));
                                                        printf("AstNodeOperand allocated for 'functionCall'\n");
                                                        (yyval.operand)->value.funtionCall = (yyvsp[0].functionCall);
                                                        (yyval.operand)->valueType = (yyvsp[0].functionCall)->returnType;  
                                                        (yyval.operand)->contentType = CONTENT_TYPE_FUNCTION;
                                                    }
#line 1984 "parser.tab.c"
    break;

  case 50: /* types: VOID  */
#line 652 "parser.y"
                                                    {
                                                        (yyval.string) = DATA_TYPE_VOID;
                                                        printf("Defined 'type: VOID'\n");
                                                    }
#line 1993 "parser.tab.c"
    break;

  case 51: /* types: INT  */
#line 656 "parser.y"
                                                    {
                                                        (yyval.string) = DATA_TYPE_INT;
                                                        printf("Defined 'type: INT'\n");
                                                    }
#line 2002 "parser.tab.c"
    break;

  case 52: /* types: FLOAT  */
#line 660 "parser.y"
                                                    {
                                                        (yyval.string) = DATA_TYPE_FLOAT;
                                                        printf("Defined 'type: FLOAT'\n");
                                                    }
#line 2011 "parser.tab.c"
    break;

  case 53: /* types: CHAR  */
#line 664 "parser.y"
                                                    {
                                                        (yyval.string) = DATA_TYPE_CHAR;
                                                        printf("Defined 'type: CHAR'\n");
                                                    }
#line 2020 "parser.tab.c"
    break;


#line 2024 "parser.tab.c"

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

#line 669 "parser.y"


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
            return "Type not defined";
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
