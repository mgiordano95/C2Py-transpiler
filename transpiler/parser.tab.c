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
#include <stdlib.h> //atoi()
#include "ast.h"
#include "symboltable.h"
#include "c2py.h"

int yylex(void);
int yyerror(char *s);
extern int yylineno;

FILE *fptr;

struct AstNodeStatements *root;
struct List *actualList = NULL;
char appoggio[100] = {};

char *typeToString(int);
int stringToType(char*);

void beginScope();
void endScope();


#line 100 "parser.tab.c"

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
  YYSYMBOL_REFOP = 14,                     /* REFOP  */
  YYSYMBOL_ADD = 15,                       /* ADD  */
  YYSYMBOL_SUB = 16,                       /* SUB  */
  YYSYMBOL_MUL = 17,                       /* MUL  */
  YYSYMBOL_DIV = 18,                       /* DIV  */
  YYSYMBOL_EQ = 19,                        /* EQ  */
  YYSYMBOL_EE = 20,                        /* EE  */
  YYSYMBOL_NE = 21,                        /* NE  */
  YYSYMBOL_GT = 22,                        /* GT  */
  YYSYMBOL_LT = 23,                        /* LT  */
  YYSYMBOL_GE = 24,                        /* GE  */
  YYSYMBOL_LE = 25,                        /* LE  */
  YYSYMBOL_AND = 26,                       /* AND  */
  YYSYMBOL_OR = 27,                        /* OR  */
  YYSYMBOL_NOT = 28,                       /* NOT  */
  YYSYMBOL_LPAR = 29,                      /* LPAR  */
  YYSYMBOL_RPAR = 30,                      /* RPAR  */
  YYSYMBOL_LSBRA = 31,                     /* LSBRA  */
  YYSYMBOL_RSBRA = 32,                     /* RSBRA  */
  YYSYMBOL_LBRA = 33,                      /* LBRA  */
  YYSYMBOL_RBRA = 34,                      /* RBRA  */
  YYSYMBOL_SEMICOL = 35,                   /* SEMICOL  */
  YYSYMBOL_COMMA = 36,                     /* COMMA  */
  YYSYMBOL_INT_VALUE = 37,                 /* INT_VALUE  */
  YYSYMBOL_FLOAT_VALUE = 38,               /* FLOAT_VALUE  */
  YYSYMBOL_ID = 39,                        /* ID  */
  YYSYMBOL_CHAR_VALUE = 40,                /* CHAR_VALUE  */
  YYSYMBOL_STRING_VALUE = 41,              /* STRING_VALUE  */
  YYSYMBOL_UNKNOWN = 42,                   /* UNKNOWN  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_program = 44,                   /* program  */
  YYSYMBOL_45_1 = 45,                      /* $@1  */
  YYSYMBOL_statements = 46,                /* statements  */
  YYSYMBOL_instruction = 47,               /* instruction  */
  YYSYMBOL_functionDecl = 48,              /* functionDecl  */
  YYSYMBOL_49_2 = 49,                      /* $@2  */
  YYSYMBOL_50_3 = 50,                      /* $@3  */
  YYSYMBOL_51_4 = 51,                      /* $@4  */
  YYSYMBOL_52_5 = 52,                      /* $@5  */
  YYSYMBOL_functionCall = 53,              /* functionCall  */
  YYSYMBOL_functionParams = 54,            /* functionParams  */
  YYSYMBOL_ifStatement = 55,               /* ifStatement  */
  YYSYMBOL_56_6 = 56,                      /* $@6  */
  YYSYMBOL_elseifStatement = 57,           /* elseifStatement  */
  YYSYMBOL_58_7 = 58,                      /* $@7  */
  YYSYMBOL_elseStatement = 59,             /* elseStatement  */
  YYSYMBOL_60_8 = 60,                      /* $@8  */
  YYSYMBOL_whileLoop = 61,                 /* whileLoop  */
  YYSYMBOL_62_9 = 62,                      /* $@9  */
  YYSYMBOL_body = 63,                      /* body  */
  YYSYMBOL_arrayInit = 64,                 /* arrayInit  */
  YYSYMBOL_arrayAssign = 65,               /* arrayAssign  */
  YYSYMBOL_arrayDecl = 66,                 /* arrayDecl  */
  YYSYMBOL_arrayCall = 67,                 /* arrayCall  */
  YYSYMBOL_arrayElements = 68,             /* arrayElements  */
  YYSYMBOL_outputFunction = 69,            /* outputFunction  */
  YYSYMBOL_inputFunction = 70,             /* inputFunction  */
  YYSYMBOL_outputElements = 71,            /* outputElements  */
  YYSYMBOL_inputElements = 72,             /* inputElements  */
  YYSYMBOL_initialization = 73,            /* initialization  */
  YYSYMBOL_assignment = 74,                /* assignment  */
  YYSYMBOL_expression = 75,                /* expression  */
  YYSYMBOL_content = 76,                   /* content  */
  YYSYMBOL_types = 77                      /* types  */
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
#define YYLAST   347

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  174

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   103,   103,   103,   112,   119,   128,   134,   140,   157,
     163,   169,   186,   192,   198,   204,   210,   216,   224,   224,
     245,   245,   265,   268,   265,   297,   309,   335,   344,   351,
     360,   369,   369,   381,   381,   393,   393,   404,   404,   416,
     422,   428,   436,   456,   472,   483,   509,   514,   527,   534,
     540,   548,   554,   571,   581,   593,   599,   607,   613,   621,
     627,   635,   641,   649,   657,   677,   697,   716,   735,   754,
     773,   784,   795,   812,   829,   846,   863,   880,   897,   916,
     928,   935,   942,   949,   956,   963,   975,   978,   981,   984
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
  "REFOP", "ADD", "SUB", "MUL", "DIV", "EQ", "EE", "NE", "GT", "LT", "GE",
  "LE", "AND", "OR", "NOT", "LPAR", "RPAR", "LSBRA", "RSBRA", "LBRA",
  "RBRA", "SEMICOL", "COMMA", "INT_VALUE", "FLOAT_VALUE", "ID",
  "CHAR_VALUE", "STRING_VALUE", "UNKNOWN", "$accept", "program", "$@1",
  "statements", "instruction", "functionDecl", "$@2", "$@3", "$@4", "$@5",
  "functionCall", "functionParams", "ifStatement", "$@6",
  "elseifStatement", "$@7", "elseStatement", "$@8", "whileLoop", "$@9",
  "body", "arrayInit", "arrayAssign", "arrayDecl", "arrayCall",
  "arrayElements", "outputFunction", "inputFunction", "outputElements",
  "inputElements", "initialization", "assignment", "expression", "content",
  "types", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-75)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -75,    23,   128,   -75,   -75,   -75,   -75,   -75,   -20,    25,
      18,    21,    50,     7,   -75,   128,   -75,    47,   -75,   -75,
     -75,   -75,    70,    77,    94,    88,    93,    -1,   109,    -9,
      87,   167,    83,    87,    76,   121,    87,    15,    52,   -75,
     -75,   -75,   -75,   245,   -75,   -75,   180,   -75,   -75,   183,
      -2,   192,    87,   -75,   -75,    11,   -75,   -75,   -75,   197,
     244,    87,    91,   -75,   198,     5,    45,   -75,   244,   -75,
     213,   125,   174,   -75,   231,   252,   -75,   148,   -75,    82,
     214,    87,    46,   260,   -75,   -75,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,   242,    87,
       3,   -75,   -75,    87,   -75,   261,   -75,    82,   193,   -75,
     -75,   211,    87,    83,   -75,   -75,   244,   -75,   247,   267,
     -75,    83,   292,   292,   302,   133,   309,   315,   320,   152,
     168,    81,   249,   -75,   -75,   199,    87,   -75,    83,   251,
     165,    87,   257,   -75,    82,   -75,   -75,   -75,   264,    83,
     -75,   -75,   240,   -75,    83,   243,   215,   -75,   -75,    87,
     182,   -75,   -75,    83,   -75,   -75,   -75,   -75,   262,   -75,
     261,   -75,   -75,   -75
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,    86,    87,    88,    89,     0,    35,
       0,     0,     0,     0,     3,     5,     6,     0,    14,    15,
      16,    17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     4,
       7,    10,    11,     0,    12,    13,    22,     8,     9,     0,
      63,    42,     0,    80,    81,    79,    82,    84,    85,    83,
       0,     0,     0,    36,    83,     0,     0,    83,    65,    25,
       0,    28,     0,    51,     0,     0,    47,    53,    20,     0,
       0,     0,     0,     0,    78,    31,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    83,     0,
       0,    37,    55,     0,    57,     0,    26,     0,    27,    52,
      46,     0,     0,     0,    23,    18,    64,    49,     0,     0,
      44,     0,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    33,     0,     0,    39,     0,     0,
      59,     0,     0,    30,     0,    48,    54,    21,     0,     0,
      50,    43,     0,    32,     0,     0,     0,    38,    56,     0,
      61,    58,    29,     0,    19,    45,    34,    41,     0,    60,
       0,    24,    40,    62
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -75,   -75,   -75,   -14,   -75,   -75,   -75,   -75,   -75,   -75,
       9,   -74,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,
     -45,   -75,   -75,   -75,    10,   -73,   -75,   -75,   143,   141,
     -75,   -75,   -17,   -30,    12
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    14,    15,    16,   149,   113,    79,   148,
      57,    70,    18,   121,    19,   154,    20,    32,    21,   138,
      63,    22,    23,    51,    58,    76,    25,    26,   139,   142,
      27,    28,    67,    77,    72
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      60,    39,   111,    60,    49,   114,    68,    71,    74,    30,
     120,    17,    24,    59,    29,   136,    64,    81,     4,     5,
       6,     7,    84,     3,    17,    24,    36,    29,    46,    82,
      50,    60,    31,   143,    47,   102,    37,   137,    38,   146,
      37,   103,    38,    52,    98,    69,   152,    33,   100,    71,
      34,   116,    53,    54,    55,    56,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   147,   135,
     162,    17,    24,   140,    29,   104,   153,    71,   117,    35,
      52,   105,    40,   118,    73,     4,     5,     6,     7,    53,
      54,    55,    56,   157,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    99,   164,    41,   156,    96,    97,   166,
      52,   160,    42,    43,    71,    52,    62,    65,   171,    53,
      54,    55,    56,    44,    53,    54,    55,    56,    45,   140,
      13,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      86,    87,    88,    89,    48,    90,    91,    92,    93,    94,
      95,    96,    97,    90,    91,    92,    93,    94,    95,    96,
      97,   107,    66,    86,    87,    88,    89,    13,    90,    91,
      92,    93,    94,    95,    96,    97,    94,    95,    96,    97,
      86,    87,    88,    89,   112,    90,    91,    92,    93,    94,
      95,    96,    97,    95,    96,    97,    61,    86,    87,    88,
      89,   159,    90,    91,    92,    93,    94,    95,    96,    97,
      78,    83,    80,   108,    86,    87,    88,    89,   170,    90,
      91,    92,    93,    94,    95,    96,    97,    85,   101,   144,
      86,    87,    88,    89,   155,    90,    91,    92,    93,    94,
      95,    96,    97,   106,   115,   145,    86,    87,    88,    89,
     168,    90,    91,    92,    93,    94,    95,    96,    97,    86,
      87,    88,    89,   109,    90,    91,    92,    93,    94,    95,
      96,    97,   134,    52,   165,   141,    97,   167,    75,   150,
      52,   158,    53,    54,    55,    56,   110,   161,    52,    53,
      54,    55,    56,   119,   163,    52,   172,    53,    54,    55,
      56,   151,   169,     0,    53,    54,    55,    56,    87,    88,
      89,   173,    90,    91,    92,    93,    94,    95,    96,    97,
      89,     0,    90,    91,    92,    93,    94,    95,    96,    97,
      91,    92,    93,    94,    95,    96,    97,    92,    93,    94,
      95,    96,    97,    93,    94,    95,    96,    97
};

static const yytype_int16 yycheck[] =
{
      30,    15,    75,    33,    13,    79,    36,    37,    38,    29,
      83,     2,     2,    30,     2,    12,    33,    19,     3,     4,
       5,     6,    52,     0,    15,    15,    19,    15,    29,    31,
      39,    61,     7,   107,    35,    30,    29,    34,    31,   112,
      29,    36,    31,    28,    61,    30,   119,    29,    62,    79,
      29,    81,    37,    38,    39,    40,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,   113,    99,
     144,    62,    62,   103,    62,    30,   121,   107,    32,    29,
      28,    36,    35,    37,    32,     3,     4,     5,     6,    37,
      38,    39,    40,   138,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,   149,    35,   136,    26,    27,   154,
      28,   141,    35,    19,   144,    28,    33,    41,   163,    37,
      38,    39,    40,    35,    37,    38,    39,    40,    35,   159,
      39,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      15,    16,    17,    18,    35,    20,    21,    22,    23,    24,
      25,    26,    27,    20,    21,    22,    23,    24,    25,    26,
      27,    36,    41,    15,    16,    17,    18,    39,    20,    21,
      22,    23,    24,    25,    26,    27,    24,    25,    26,    27,
      15,    16,    17,    18,    36,    20,    21,    22,    23,    24,
      25,    26,    27,    25,    26,    27,    29,    15,    16,    17,
      18,    36,    20,    21,    22,    23,    24,    25,    26,    27,
      30,    19,    29,    39,    15,    16,    17,    18,    36,    20,
      21,    22,    23,    24,    25,    26,    27,    30,    30,    36,
      15,    16,    17,    18,    35,    20,    21,    22,    23,    24,
      25,    26,    27,    30,    30,    34,    15,    16,    17,    18,
      35,    20,    21,    22,    23,    24,    25,    26,    27,    15,
      16,    17,    18,    32,    20,    21,    22,    23,    24,    25,
      26,    27,    30,    28,    34,    14,    27,    34,    33,    32,
      28,    30,    37,    38,    39,    40,    34,    30,    28,    37,
      38,    39,    40,    33,    30,    28,    34,    37,    38,    39,
      40,    34,   159,    -1,    37,    38,    39,    40,    16,    17,
      18,   170,    20,    21,    22,    23,    24,    25,    26,    27,
      18,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      21,    22,    23,    24,    25,    26,    27,    22,    23,    24,
      25,    26,    27,    23,    24,    25,    26,    27
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    44,    45,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    39,    46,    47,    48,    53,    55,    57,
      59,    61,    64,    65,    67,    69,    70,    73,    74,    77,
      29,     7,    60,    29,    29,    29,    19,    29,    31,    46,
      35,    35,    35,    19,    35,    35,    29,    35,    35,    13,
      39,    66,    28,    37,    38,    39,    40,    53,    67,    75,
      76,    29,    33,    63,    75,    41,    41,    75,    76,    30,
      54,    76,    77,    32,    76,    33,    68,    76,    30,    51,
      29,    19,    31,    19,    76,    30,    15,    16,    17,    18,
      20,    21,    22,    23,    24,    25,    26,    27,    75,    12,
      46,    30,    30,    36,    30,    36,    30,    36,    39,    32,
      34,    68,    36,    50,    54,    30,    76,    32,    37,    33,
      68,    56,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    30,    76,    12,    34,    62,    71,
      76,    14,    72,    54,    36,    34,    68,    63,    52,    49,
      32,    34,    68,    63,    58,    35,    76,    63,    30,    36,
      76,    30,    54,    30,    63,    34,    63,    34,    35,    71,
      36,    63,    34,    72
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    45,    44,    46,    46,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    49,    48,
      50,    48,    51,    52,    48,    53,    53,    54,    54,    54,
      54,    56,    55,    58,    57,    60,    59,    62,    61,    63,
      63,    63,    64,    64,    64,    64,    65,    65,    65,    66,
      66,    67,    67,    68,    68,    69,    69,    70,    70,    71,
      71,    72,    72,    73,    74,    74,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    76,
      76,    76,    76,    76,    76,    76,    77,    77,    77,    77
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     1,     2,     2,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     0,     6,
       0,     5,     0,     0,     7,     3,     4,     2,     1,     4,
       3,     0,     6,     0,     7,     0,     3,     0,     6,     3,
       6,     5,     2,     5,     4,     6,     4,     3,     5,     3,
       4,     3,     4,     1,     3,     4,     6,     4,     6,     1,
       3,     2,     4,     2,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
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
#line 103 "parser.y"
                                                        {
                                                            beginScope();
                                                        }
#line 1316 "parser.tab.c"
    break;

  case 3: /* program: $@1 statements  */
#line 106 "parser.y"
                                                        {
                                                            root = (yyvsp[0].statements);
                                                            endScope();
                                                        }
#line 1325 "parser.tab.c"
    break;

  case 4: /* statements: instruction statements  */
#line 112 "parser.y"
                                                        {
                                                            (yyval.statements) = malloc(sizeof(struct AstNodeStatements));
                                                            printf("AstNodeStatements allocated for 'instruction statements'\n");
                                                            (yyval.statements)->nodeType = STATEMENT_NODE;
                                                            (yyval.statements)->currentInstruction = (yyvsp[-1].instruction);
                                                            (yyval.statements)->nextStatement = (yyvsp[0].statements);
                                                        }
#line 1337 "parser.tab.c"
    break;

  case 5: /* statements: instruction  */
#line 119 "parser.y"
                                                        {
                                                            (yyval.statements) = malloc(sizeof(struct AstNodeStatements));
                                                            printf("AstNodeStatements allocated for 'instruction'\n");
                                                            (yyval.statements)->nodeType = STATEMENT_NODE;
                                                            (yyval.statements)->currentInstruction = (yyvsp[0].instruction);
                                                            (yyval.statements)->nextStatement = NULL;
                                                        }
#line 1349 "parser.tab.c"
    break;

  case 6: /* instruction: functionDecl  */
#line 128 "parser.y"
                                                        {
                                                            (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                            printf("AstNodeInstruction allocated for 'functionDecl SEMICOL'\n");
                                                            (yyval.instruction)->nodeType = FUNCTION_DECL_NODE;
                                                            (yyval.instruction)->value.functionDecl = (yyvsp[0].functionDecl);
                                                        }
#line 1360 "parser.tab.c"
    break;

  case 7: /* instruction: functionCall SEMICOL  */
#line 134 "parser.y"
                                                        {
                                                            (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                            printf("AstNodeInstruction allocated for 'functionCall SEMICOL'\n");
                                                            (yyval.instruction)->nodeType = FUNCTION_CALL_NODE;
                                                            (yyval.instruction)->value.functionCall = (yyvsp[-1].functionCall);
                                                        }
#line 1371 "parser.tab.c"
    break;

  case 8: /* instruction: initialization SEMICOL  */
#line 140 "parser.y"
                                                        {
                                                            (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                            struct SymTab *s = NULL;
                                                            s = findSym((yyvsp[-1].init)->variableName, actualList);
                                                            if (s == NULL) {
                                                                if((yyvsp[-1].init)->dataType == DATA_TYPE_VOID) {
                                                                    printf("\n\t***Line: %d - Error: You cannot initialize a variable of type void***\n\n", yylineno);
                                                                } else {
                                                                    printf("AstNodeInstruction allocated for 'initialization SEMICOL'\n");
                                                                    (yyval.instruction)->nodeType = INIT_NODE;
                                                                    (yyval.instruction)->value.init = (yyvsp[-1].init);
                                                                    s = createSym((yyvsp[-1].init)->variableName, actualList, SYMBOL_VARIABLE, (yyvsp[-1].init)->dataType, (yyvsp[-1].init)->dataType, NULL, NULL, NULL, nullValue);
                                                                }
                                                            } else {
                                                                printf("\n\t***Line: %d - Error: variable already declared.***\n\n", yylineno);
                                                            }
                                                        }
#line 1393 "parser.tab.c"
    break;

  case 9: /* instruction: assignment SEMICOL  */
#line 157 "parser.y"
                                                        {
                                                            (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                            printf("AstNodeInstruction allocated for 'assignment SEMICOL'\n");
                                                            (yyval.instruction)->nodeType = ASSIGN_NODE;
                                                            (yyval.instruction)->value.assign = (yyvsp[-1].assign);
                                                        }
#line 1404 "parser.tab.c"
    break;

  case 10: /* instruction: arrayInit SEMICOL  */
#line 163 "parser.y"
                                                        {
                                                            (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                            printf("AstNodeInstruction allocated for 'arrayInit'\n");
                                                            (yyval.instruction)->nodeType = ARRAY_INIT_NODE;
                                                            (yyval.instruction)->value.arrayInit = (yyvsp[-1].arrayInit);
                                                        }
#line 1415 "parser.tab.c"
    break;

  case 11: /* instruction: arrayAssign SEMICOL  */
#line 169 "parser.y"
                                                        {
                                                            struct SymTab *s = findSym((yyvsp[-1].arrayAssign)->arrayCall->arrayName, actualList);
                                                            if (s != NULL) {
                                                                if(s->dataType != (yyvsp[-1].arrayAssign)->arrayType) {
                                                                    printf("\n\t***Line: %d - Error: Array %s has been declared as a %s but type %s is assigned***\n\n", yylineno, (yyvsp[-1].arrayAssign)->arrayCall->arrayName, typeToString(s->dataType), typeToString((yyvsp[-1].arrayAssign)->arrayType));
                                                                } else if(atoi(s->arrayLength) <= atoi((yyvsp[-1].arrayAssign)->arrayCall->elementIndex->value.val)) {
                                                                    printf("\n\t***Line: %d - Error: the length of %s is %s***\n\n", yylineno,s->symbolName, s->arrayLength);
                                                                }else {
                                                                    (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                                    printf("AstNodeInstruction allocated for 'arrayAssign'\n");
                                                                    (yyval.instruction)->nodeType = ARRAY_ASSIGN_NODE;
                                                                    (yyval.instruction)->value.arrayAssign = (yyvsp[-1].arrayAssign);
                                                                }
                                                            } else {
                                                                printf("\n\t***Line: %d - Error: array %s not declared***\n\n", yylineno,(yyvsp[-1].arrayAssign)->arrayCall->arrayName);
                                                            }
                                                        }
#line 1437 "parser.tab.c"
    break;

  case 12: /* instruction: outputFunction SEMICOL  */
#line 186 "parser.y"
                                                        {
                                                            (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                            printf("AstNodeInstruction allocated for 'outputFunction SEMICOL'\n");
                                                            (yyval.instruction)->nodeType = OUTPUT_NODE;
                                                            (yyval.instruction)->value.outputFunction = (yyvsp[-1].outputFunction);
                                                        }
#line 1448 "parser.tab.c"
    break;

  case 13: /* instruction: inputFunction SEMICOL  */
#line 192 "parser.y"
                                                        {
                                                            (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                            printf("AstNodeInstruction allocated for 'inputFunction SEMICOL'\n");
                                                            (yyval.instruction)->nodeType = INPUT_NODE;
                                                            (yyval.instruction)->value.inputFunction = (yyvsp[-1].inputFunction);
                                                        }
#line 1459 "parser.tab.c"
    break;

  case 14: /* instruction: ifStatement  */
#line 198 "parser.y"
                                                        {
                                                            (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                            printf("AstNodeInstruction allocated for 'ifStatement'\n");
                                                            (yyval.instruction)->nodeType = IF_NODE;
                                                            (yyval.instruction)->value.ifStatement = (yyvsp[0].ifStatement);
                                                        }
#line 1470 "parser.tab.c"
    break;

  case 15: /* instruction: elseifStatement  */
#line 204 "parser.y"
                                                        {
                                                            (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                            printf("AstNodeInstruction allocated for 'elseifStatement'\n");
                                                            (yyval.instruction)->nodeType = ELSE_IF_NODE;
                                                            (yyval.instruction)->value.elseifStatement = (yyvsp[0].elseifStatement);
                                                        }
#line 1481 "parser.tab.c"
    break;

  case 16: /* instruction: elseStatement  */
#line 210 "parser.y"
                                                        {
                                                            (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                            printf("AstNodeInstruction allocated for 'elseStatement'\n");
                                                            (yyval.instruction)->nodeType = ELSE_NODE;
                                                            (yyval.instruction)->value.elseStatement = (yyvsp[0].elseStatement);
                                                        }
#line 1492 "parser.tab.c"
    break;

  case 17: /* instruction: whileLoop  */
#line 216 "parser.y"
                                                        {
                                                            (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                            printf("AstNodeInstruction allocated for 'whileLoop'\n");
                                                            (yyval.instruction)->nodeType = WHILE_NODE;
                                                            (yyval.instruction)->value.whileLoop = (yyvsp[0].whileLoop);
                                                        }
#line 1503 "parser.tab.c"
    break;

  case 18: /* $@2: %empty  */
#line 224 "parser.y"
                                                        {
                                                            beginScope();
                                                        }
#line 1511 "parser.tab.c"
    break;

  case 19: /* functionDecl: types MAIN LPAR RPAR $@2 body  */
#line 227 "parser.y"
                                                        {
                                                            struct SymTab *s = NULL;
                                                            char *main = "main";
                                                            s = findSymtab(main, actualList);
                                                            if (s == NULL) {
                                                                (yyval.functionDecl) = malloc(sizeof(struct AstNodeFunctionDecl));
                                                                printf("AstNodeFunctionDecl allocated for 'types MAIN LPAR RPAR body'\n");
                                                                (yyval.functionDecl)->functionName = (yyvsp[-4].string);
                                                                (yyval.functionDecl)->returnType = stringToType((yyvsp[-5].string));
                                                                (yyval.functionDecl)->functionParams = NULL;
                                                                (yyval.functionDecl)->functiontBody = (yyvsp[0].body);
                                                                endScope();
                                                                struct SymTab *s = createSym((yyval.functionDecl)->functionName, actualList, SYMBOL_FUNCTION, DATA_TYPE_NONE, (yyval.functionDecl)->returnType, (yyval.functionDecl)->functionName, NULL, NULL, nullValue);
                                                            } else {
                                                                printf("\n\t***Line: %d - Error: function MAIN already declared***\n\n", yylineno);
                                                                endScope();
                                                            } 
                                                        }
#line 1534 "parser.tab.c"
    break;

  case 20: /* $@3: %empty  */
#line 245 "parser.y"
                                                        {
                                                            beginScope();
                                                        }
#line 1542 "parser.tab.c"
    break;

  case 21: /* functionDecl: initialization LPAR RPAR $@3 body  */
#line 248 "parser.y"
                                                        {
                                                            struct SymTab *s = NULL;
                                                            s = findSymtab((yyvsp[-4].init)->variableName, actualList);
                                                            if (s == NULL) { 
                                                                (yyval.functionDecl) = malloc(sizeof(struct AstNodeFunctionDecl));
                                                                printf("AstNodeFunctionDecl allocated for 'initialization LPAR RPAR body'\n");
                                                                (yyval.functionDecl)->functionName = (yyvsp[-4].init)->variableName;
                                                                (yyval.functionDecl)->returnType = (yyvsp[-4].init)->dataType;
                                                                (yyval.functionDecl)->functionParams = NULL;
                                                                (yyval.functionDecl)->functiontBody = (yyvsp[0].body);
                                                                endScope();
                                                                struct SymTab *s = createSym((yyval.functionDecl)->functionName, actualList, SYMBOL_FUNCTION, DATA_TYPE_NONE, (yyval.functionDecl)->returnType, (yyval.functionDecl)->functionName, NULL, NULL, nullValue);
                                                            } else {
                                                                printf("\n\t***Line: %d - Error: function %s already declared***\n\n", yylineno,(yyvsp[-4].init)->variableName);
                                                                endScope();
                                                            } 
                                                        }
#line 1564 "parser.tab.c"
    break;

  case 22: /* $@4: %empty  */
#line 265 "parser.y"
                                                        {   
                                                            beginScope();
                                                        }
#line 1572 "parser.tab.c"
    break;

  case 23: /* $@5: %empty  */
#line 268 "parser.y"
                                                        {
                                                            for(int i=0; i<sizeof(appoggio);i++) {
                                                                appoggio[i] = '\0';
                                                            }
                                                            for(struct AstNodeFunctionParams *p = (yyvsp[0].functionParams); p != NULL; p = p->nextParams) {
                                                                struct SymTab *s = createSym(p->initParam->variableName, actualList, SYMBOL_FUNCTION, p->initParam->dataType, DATA_TYPE_NONE, (yyvsp[-3].init)->variableName, NULL, NULL, nullValue);
                                                                strcat(appoggio,typeToString(p->initParam->dataType));
                                                            } 
                                                            printf("Parameters of the declared function: %s\n",appoggio);
                                                        }
#line 1587 "parser.tab.c"
    break;

  case 24: /* functionDecl: initialization LPAR $@4 functionParams $@5 RPAR body  */
#line 278 "parser.y"
                                                        {
                                                            struct SymTab *s = NULL;
                                                            s = findSymtab((yyvsp[-6].init)->variableName, actualList);
                                                            if (s == NULL) { 
                                                                (yyval.functionDecl) = malloc(sizeof(struct AstNodeFunctionDecl));
                                                                printf("AstNodeFunctionDecl allocated for 'initialization LPAR functionParams RPAR body'\n");
                                                                (yyval.functionDecl)->functionName = (yyvsp[-6].init)->variableName;
                                                                (yyval.functionDecl)->returnType = (yyvsp[-6].init)->dataType;
                                                                (yyval.functionDecl)->functionParams = (yyvsp[-3].functionParams);
                                                                (yyval.functionDecl)->functiontBody = (yyvsp[0].body); 
                                                                endScope();
                                                                struct SymTab *q = createSym((yyval.functionDecl)->functionName, actualList, SYMBOL_FUNCTION, DATA_TYPE_NONE, (yyval.functionDecl)->returnType, (yyval.functionDecl)->functionName, appoggio, NULL, nullValue);
                                                            } else {
                                                                printf("\n\t***Line: %d - Error: function %s already declared***\n\n", yylineno,(yyvsp[-6].init)->variableName);
                                                                endScope();
                                                            }
                                                        }
#line 1609 "parser.tab.c"
    break;

  case 25: /* functionCall: ID LPAR RPAR  */
#line 297 "parser.y"
                                                        {
                                                            (yyval.functionCall) = malloc(sizeof(struct AstNodeFunctionCall));
                                                            printf("AstNodeFunctionCall allocated for 'ID LPAR RPAR'\n");
                                                            struct SymTab *s = findSymtab((yyvsp[-2].string), actualList);
                                                            if (s != NULL) { 
                                                                (yyval.functionCall)->functionName = (yyvsp[-2].string);
                                                                (yyval.functionCall)->returnType = s->returnType;
                                                                (yyval.functionCall)->functionParams = NULL;
                                                            } else {
                                                                printf("\n\t***Line: %d - Error: function %s not declared***\n\n", yylineno,(yyvsp[-2].string));
                                                            } 
                                                        }
#line 1626 "parser.tab.c"
    break;

  case 26: /* functionCall: ID LPAR functionParams RPAR  */
#line 309 "parser.y"
                                                        {
                                                            (yyval.functionCall) = malloc(sizeof(struct AstNodeFunctionCall));
                                                            printf("AstNodeFunctionCall allocated for 'ID LPAR functionParams RPAR'\n");
                                                            char calledParameters[100] = {};
                                                            struct SymTab *s = findSymtab((yyvsp[-3].string), actualList);
                                                            if (s != NULL) {
                                                                for(struct AstNodeFunctionParams *q = (yyvsp[-1].functionParams); q != NULL; q = q->nextParams) {
                                                                    strcat(calledParameters,typeToString(q->callParams->valueType));
                                                                }
                                                                printf("Parameters of the declared function: %s\n", s->funcParameters);
                                                                printf("Parameters of the called function: %s\n", calledParameters);
                                                                int boolean = strcmp(s->funcParameters,calledParameters);
                                                                if (boolean == 0) {
                                                                    printf("The parameters are correct\n");
                                                                    (yyval.functionCall)->functionName = (yyvsp[-3].string);
                                                                    (yyval.functionCall)->returnType = s->returnType;
                                                                    (yyval.functionCall)->functionParams = (yyvsp[-1].functionParams);
                                                                } else {
                                                                    printf("The parameters in the function call are incorrect\n");
                                                                }
                                                            } else {
                                                                printf("\n\t***Line: %d - Error: function %s not declared***\n\n", yylineno,(yyvsp[-3].string));
                                                            }
                                                        }
#line 1655 "parser.tab.c"
    break;

  case 27: /* functionParams: types ID  */
#line 335 "parser.y"
                                                        {
                                                            (yyval.functionParams) = malloc(sizeof(struct AstNodeFunctionParams));
                                                            printf("AstNodeFunctionParams allocated for 'types ID'\n");
                                                            (yyval.functionParams)->nextParams = NULL;
                                                            (yyval.functionParams)->callParams = NULL;
                                                            (yyval.functionParams)->initParam = malloc(sizeof(struct AstNodeInit));
                                                            (yyval.functionParams)->initParam->dataType = stringToType((yyvsp[-1].string));
                                                            (yyval.functionParams)->initParam->variableName = (yyvsp[0].string);
                                                        }
#line 1669 "parser.tab.c"
    break;

  case 28: /* functionParams: content  */
#line 344 "parser.y"
                                                        {
                                                            (yyval.functionParams) = malloc(sizeof(struct AstNodeFunctionParams));
                                                            printf("AstNodeFunctionParams allocated for 'content'\n");
                                                            (yyval.functionParams)->nextParams = NULL;
                                                            (yyval.functionParams)->callParams = (yyvsp[0].operand);
                                                            (yyval.functionParams)->initParam = NULL;
                                                        }
#line 1681 "parser.tab.c"
    break;

  case 29: /* functionParams: types ID COMMA functionParams  */
#line 351 "parser.y"
                                                        {
                                                            (yyval.functionParams) = malloc(sizeof(struct AstNodeFunctionParams));
                                                            printf("AstNodeFunctionParams allocated for 'types ID COMMA functionParams'\n");
                                                            (yyval.functionParams)->nextParams = (yyvsp[0].functionParams);
                                                            (yyval.functionParams)->callParams = NULL;
                                                            (yyval.functionParams)->initParam = malloc(sizeof(struct AstNodeInit));
                                                            (yyval.functionParams)->initParam->dataType = stringToType((yyvsp[-3].string));
                                                            (yyval.functionParams)->initParam->variableName = (yyvsp[-2].string);
                                                        }
#line 1695 "parser.tab.c"
    break;

  case 30: /* functionParams: content COMMA functionParams  */
#line 360 "parser.y"
                                                        {
                                                            (yyval.functionParams) = malloc(sizeof(struct AstNodeFunctionParams));
                                                            printf("AstNodeFunctionParams allocated for 'content COMMA functionParams'\n");
                                                            (yyval.functionParams)->nextParams = (yyvsp[0].functionParams);
                                                            (yyval.functionParams)->callParams = (yyvsp[-2].operand);
                                                            (yyval.functionParams)->initParam = NULL;
                                                        }
#line 1707 "parser.tab.c"
    break;

  case 31: /* $@6: %empty  */
#line 369 "parser.y"
                                                        {
                                                            beginScope();
                                                        }
#line 1715 "parser.tab.c"
    break;

  case 32: /* ifStatement: IF LPAR expression RPAR $@6 body  */
#line 372 "parser.y"
                                                        {
                                                            (yyval.ifStatement) = malloc(sizeof(struct AstNodeIf));
                                                            printf("AstNodeIf allocated for 'IF LPAR expression RPAR body'\n");
                                                            (yyval.ifStatement)->ifCondition = (yyvsp[-3].expression);
                                                            (yyval.ifStatement)->ifBody = (yyvsp[0].body);
                                                            endScope();
                                                        }
#line 1727 "parser.tab.c"
    break;

  case 33: /* $@7: %empty  */
#line 381 "parser.y"
                                                        {
                                                            beginScope();
                                                        }
#line 1735 "parser.tab.c"
    break;

  case 34: /* elseifStatement: ELSE IF LPAR expression RPAR $@7 body  */
#line 384 "parser.y"
                                                        {
                                                            (yyval.elseifStatement) = malloc(sizeof(struct AstNodeElseIf));
                                                            printf("AstNodeElseIf allocated for 'ELSE IF LPAR expression RPAR body'\n");
                                                            (yyval.elseifStatement)->elseifCondition = (yyvsp[-3].expression);
                                                            (yyval.elseifStatement)->elseifBody = (yyvsp[0].body);
                                                            endScope();
                                                        }
#line 1747 "parser.tab.c"
    break;

  case 35: /* $@8: %empty  */
#line 393 "parser.y"
                                                        {
                                                            beginScope();
                                                        }
#line 1755 "parser.tab.c"
    break;

  case 36: /* elseStatement: ELSE $@8 body  */
#line 396 "parser.y"
                                                        {
                                                            (yyval.elseStatement) = malloc(sizeof(struct AstNodeElse));
                                                            printf("AstNodeElse allocated for 'ELSE body'\n");
                                                            (yyval.elseStatement)->elseBody = (yyvsp[0].body);
                                                            endScope();
                                                        }
#line 1766 "parser.tab.c"
    break;

  case 37: /* $@9: %empty  */
#line 404 "parser.y"
                                                        {
                                                            beginScope();
                                                        }
#line 1774 "parser.tab.c"
    break;

  case 38: /* whileLoop: WHILE LPAR expression RPAR $@9 body  */
#line 407 "parser.y"
                                                        {
                                                            (yyval.whileLoop) = malloc(sizeof(struct AstNodeWhile));
                                                            printf("AstNodeWhile allocated for 'WHILE LPAR expression RPAR body'\n");
                                                            (yyval.whileLoop)->whileCondition = (yyvsp[-3].expression);
                                                            (yyval.whileLoop)->whileBody = (yyvsp[0].body);
                                                            endScope();
                                                        }
#line 1786 "parser.tab.c"
    break;

  case 39: /* body: LBRA statements RBRA  */
#line 416 "parser.y"
                                                        {
                                                            (yyval.body) = malloc(sizeof(struct AstNodeBody));
                                                            printf("AstNodeBody allocated for 'LBRA statements RBRA'\n");
                                                            (yyval.body)->bodyStatements = (yyvsp[-1].statements);
                                                            (yyval.body)->returnValue = NULL;
                                                        }
#line 1797 "parser.tab.c"
    break;

  case 40: /* body: LBRA statements RETURN content SEMICOL RBRA  */
#line 422 "parser.y"
                                                        {
                                                            (yyval.body) = malloc(sizeof(struct AstNodeBody));
                                                            printf("AstNodeBody allocated for 'LBRA statements RETURN content SEMICOL RBRA'\n");
                                                            (yyval.body)->bodyStatements = (yyvsp[-4].statements);
                                                            (yyval.body)->returnValue = (yyvsp[-2].operand);
                                                        }
#line 1808 "parser.tab.c"
    break;

  case 41: /* body: LBRA RETURN content SEMICOL RBRA  */
#line 428 "parser.y"
                                                        {
                                                            (yyval.body)=malloc(sizeof(struct AstNodeBody));
                                                            printf("AstNodeBody allocated for 'LBRA RETURN content SEMICOL RBRA'\n");
                                                            (yyval.body)->bodyStatements = NULL;
                                                            (yyval.body)->returnValue = (yyvsp[-2].operand);
                                                        }
#line 1819 "parser.tab.c"
    break;

  case 42: /* arrayInit: types arrayDecl  */
#line 436 "parser.y"
                                                        {
                                                            //int myArray[]; Error: array size missing in ‘myArray’ !!!
                                                            //int myArray[3]; Corretct
                                                            struct SymTab *s = findSym((yyvsp[0].arrayDecl)->arrayName, actualList);
                                                            if (s == NULL) {
                                                                (yyval.arrayInit)=malloc(sizeof(struct AstNodeArrayInit));
                                                                printf("AstNodeArrayInit allocated for 'types arrayDecl'\n");
                                                                (yyval.arrayInit)->arrayType = stringToType((yyvsp[-1].string));
                                                                (yyval.arrayInit)->arrayDecl = (yyvsp[0].arrayDecl);
                                                                (yyval.arrayInit)->elements = NULL;
                                                                (yyval.arrayInit)->arrayDecl->arrayType = stringToType((yyvsp[-1].string));
                                                                if((yyvsp[0].arrayDecl)->arrayLength == NULL) {
                                                                    printf("\n\t***Line: %d - Error: array size missing in %s***\n\n", yylineno,(yyvsp[0].arrayDecl)->arrayName);
                                                                } else {
                                                                    s = createSym((yyvsp[0].arrayDecl)->arrayName, actualList, SYMBOL_ARRAY, (yyval.arrayInit)->arrayType, (yyval.arrayInit)->arrayType, NULL, NULL, (yyvsp[0].arrayDecl)->arrayLength, nullValue);
                                                                }
                                                            } else {
                                                                printf("\n\t***Line: %d - Error: array %s already declared***\n\n", yylineno,(yyvsp[0].arrayDecl)->arrayName);
                                                            }
                                                        }
#line 1844 "parser.tab.c"
    break;

  case 43: /* arrayInit: types arrayDecl EQ LBRA RBRA  */
#line 456 "parser.y"
                                                        {
                                                            //int myArray[] = {};
                                                            //int myArray[3] = {};
                                                            struct SymTab *s = findSym((yyvsp[-3].arrayDecl)->arrayName, actualList);
                                                            if (s == NULL) {
                                                                (yyval.arrayInit)=malloc(sizeof(struct AstNodeArrayInit));
                                                                printf("AstNodeArrayInit allocated for 'types arrayDecl EQ LBRA RBRA'\n");
                                                                (yyval.arrayInit)->arrayType = stringToType((yyvsp[-4].string));
                                                                (yyval.arrayInit)->arrayDecl = (yyvsp[-3].arrayDecl);
                                                                (yyval.arrayInit)->elements = NULL;
                                                                (yyval.arrayInit)->arrayDecl->arrayType = stringToType((yyvsp[-4].string));
                                                                s = createSym((yyvsp[-3].arrayDecl)->arrayName, actualList, SYMBOL_ARRAY, (yyval.arrayInit)->arrayType, (yyval.arrayInit)->arrayType, NULL, NULL, (yyvsp[-3].arrayDecl)->arrayLength, nullValue);
                                                            } else {
                                                                printf("\n\t***Line: %d - Error: array %s already declared***\n\n", yylineno,(yyvsp[-3].arrayDecl)->arrayName);
                                                            }
                                                        }
#line 1865 "parser.tab.c"
    break;

  case 44: /* arrayInit: types arrayDecl EQ arrayElements  */
#line 472 "parser.y"
                                                        {
                                                            //int myArray[] = 24; Error: invalid initializer !!!
                                                            //int myArray[3] = 24; Error: invalid initializer !!!
                                                            (yyval.arrayInit)=malloc(sizeof(struct AstNodeArrayInit));
                                                            printf("AstNodeArrayInit allocated for 'types arrayDecl EQ arrayElements'\n");
                                                            (yyval.arrayInit)->arrayType = stringToType((yyvsp[-3].string));
                                                            (yyval.arrayInit)->arrayDecl = (yyvsp[-2].arrayDecl);
                                                            (yyval.arrayInit)->elements = (yyvsp[0].arrayElements);
                                                            (yyval.arrayInit)->arrayDecl->arrayType = stringToType((yyvsp[-3].string));
                                                            printf("\n\t***Line: %d - Error: invalid initializer of %s***\n\n", yylineno,(yyvsp[-2].arrayDecl)->arrayName);
                                                        }
#line 1881 "parser.tab.c"
    break;

  case 45: /* arrayInit: types arrayDecl EQ LBRA arrayElements RBRA  */
#line 483 "parser.y"
                                                        {
                                                            //int myArray[] = {24, 27, 29};
                                                            //int myArray[3] = {24, 27, 29};
                                                            struct SymTab *s = findSym((yyvsp[-4].arrayDecl)->arrayName, actualList);
                                                            if (s == NULL) {
                                                                (yyval.arrayInit)=malloc(sizeof(struct AstNodeArrayInit));
                                                                printf("AstNodeArrayInit allocated for 'types arrayDecl EQ LBRA arrayElements RBRA'\n");
                                                                (yyval.arrayInit)->arrayType = stringToType((yyvsp[-5].string));
                                                                (yyval.arrayInit)->arrayDecl = (yyvsp[-4].arrayDecl);
                                                                (yyval.arrayInit)->elements = (yyvsp[-1].arrayElements);
                                                                (yyval.arrayInit)->arrayDecl->arrayType = stringToType((yyvsp[-5].string));
                                                                int ele = 0;
                                                                for(struct AstNodeArrayElements *q = (yyvsp[-1].arrayElements); q != NULL; q = q->nextElement) {
                                                                    ele++;
                                                                }
                                                                char ch[3];
                                                                sprintf(ch,"%d",ele);
                                                                printf("Number of elements in the array %s\n",ch);
                                                                (yyval.arrayInit)->arrayDecl->arrayLength = ch;
                                                                s = createSym((yyvsp[-4].arrayDecl)->arrayName, actualList, SYMBOL_ARRAY, (yyval.arrayInit)->arrayType, (yyval.arrayInit)->arrayType, NULL, NULL, (yyvsp[-4].arrayDecl)->arrayLength, nullValue);
                                                            } else {
                                                                printf("\n\t***Line: %d - Error: array %s already declared***\n\n", yylineno,(yyvsp[-4].arrayDecl)->arrayName);
                                                            }
                                                        }
#line 1910 "parser.tab.c"
    break;

  case 46: /* arrayAssign: arrayCall EQ LBRA RBRA  */
#line 509 "parser.y"
                                                        {
                                                            // myArray[] = {}; Syntax Error
                                                            // myArray[3] = {}; Syntax Error
                                                            printf("\n\t***Line: %d - Syntax Error!!!***\n\n", yylineno);
                                                        }
#line 1920 "parser.tab.c"
    break;

  case 47: /* arrayAssign: arrayCall EQ arrayElements  */
#line 514 "parser.y"
                                                        {
                                                            // myArray[] = 24; Syntax Error
                                                            // myArray[2] = 24; Correct
                                                            (yyval.arrayAssign)=malloc(sizeof(struct AstNodeArrayAssign));
                                                            printf("AstNodeArrayAssign allocated for 'arrayCall EQ arrayElements'\n");
                                                            (yyval.arrayAssign)->arrayType = (yyvsp[0].arrayElements)->element->valueType;
                                                            (yyval.arrayAssign)->arrayCall = (yyvsp[-2].arrayCall);
                                                            (yyval.arrayAssign)->elements = (yyvsp[0].arrayElements);
                                                            (yyval.arrayAssign)->arrayCall->arrayType = (yyvsp[0].arrayElements)->element->valueType;
                                                            if((yyvsp[-2].arrayCall)->elementIndex == NULL) {
                                                                printf("\n\t***Line: %d - Syntax Error!!!***\n\n", yylineno);
                                                            }
                                                        }
#line 1938 "parser.tab.c"
    break;

  case 48: /* arrayAssign: arrayCall EQ LBRA arrayElements RBRA  */
#line 527 "parser.y"
                                                        {
                                                            //myArray[] = {24, 27, 29}; Syntax Error
                                                            //myArray[3] = {24, 27, 29}; Syntax Error
                                                            printf("\n\t***Line: %d - Syntax Error!!!***\n\n", yylineno);
                                                        }
#line 1948 "parser.tab.c"
    break;

  case 49: /* arrayDecl: ID LSBRA RSBRA  */
#line 534 "parser.y"
                                                        {
                                                            (yyval.arrayDecl)=malloc(sizeof(struct AstNodeArrayDecl));
                                                            printf("AstNodeArrayDecl allocated for 'ID LSBRA RSBRA'\n");
                                                            (yyval.arrayDecl)->arrayName = (yyvsp[-2].string);
                                                            (yyval.arrayDecl)->arrayLength = NULL;
                                                        }
#line 1959 "parser.tab.c"
    break;

  case 50: /* arrayDecl: ID LSBRA INT_VALUE RSBRA  */
#line 540 "parser.y"
                                                        {
                                                            (yyval.arrayDecl)=malloc(sizeof(struct AstNodeArrayDecl));
                                                            printf("AstNodeArrayDecl allocated for 'ID LSBRA INT_VALUE RSBRA'\n");
                                                            (yyval.arrayDecl)->arrayName = (yyvsp[-3].string);
                                                            (yyval.arrayDecl)->arrayLength = (yyvsp[-1].string);
                                                        }
#line 1970 "parser.tab.c"
    break;

  case 51: /* arrayCall: ID LSBRA RSBRA  */
#line 548 "parser.y"
                                                        {
                                                            (yyval.arrayCall)=malloc(sizeof(struct AstNodeArrayCall));
                                                            printf("AstNodeArrayCall allocated for 'ID LSBRA RSBRA'\n");
                                                            (yyval.arrayCall)->arrayName = (yyvsp[-2].string);
                                                            (yyval.arrayCall)->elementIndex = NULL;
                                                        }
#line 1981 "parser.tab.c"
    break;

  case 52: /* arrayCall: ID LSBRA content RSBRA  */
#line 554 "parser.y"
                                                        {
                                                            (yyval.arrayCall)=malloc(sizeof(struct AstNodeArrayCall));
                                                            printf("AstNodeArrayCall allocated for 'ID LSBRA content RSBRA'\n");
                                                            (yyval.arrayCall)->arrayName = (yyvsp[-3].string);
                                                            (yyval.arrayCall)->elementIndex = (yyvsp[-1].operand);
                                                            if ((yyval.arrayCall)->elementIndex->contentType == CONTENT_TYPE_INT_NUMBER) {
                                                                (yyval.arrayCall)->arrayName = (yyvsp[-3].string);
                                                                (yyval.arrayCall)->elementIndex = (yyvsp[-1].operand);
                                                            } else if ((yyval.arrayCall)->elementIndex->contentType == CONTENT_TYPE_ID) {
                                                                (yyval.arrayCall)->arrayName = (yyvsp[-3].string);
                                                                (yyval.arrayCall)->elementIndex = (yyvsp[-1].operand);
                                                            } else {
                                                                printf("\n\t***Line: %d - Error: invalid array index type***\n\n", yylineno);
                                                            }
                                                        }
#line 2001 "parser.tab.c"
    break;

  case 53: /* arrayElements: content  */
#line 571 "parser.y"
                                                        {
                                                            (yyval.arrayElements) = malloc(sizeof(struct AstNodeArrayElements)); // 4 -> single element in array
                                                            if((yyvsp[0].operand)->contentType == CONTENT_TYPE_EXPRESSION) {
                                                                printf("AstNodeArrayElements allocated for 'content': %s %s %s\n", (yyvsp[0].operand)->value.expression->leftOper->value.val, (yyvsp[0].operand)->value.expression->op, (yyvsp[0].operand)->value.expression->rightOper->value.val);
                                                            } else {
                                                                printf("AstNodeArrayElements allocated for 'content': %s\n", (yyvsp[0].operand)->value.val);
                                                            }
                                                            (yyval.arrayElements)->element = (yyvsp[0].operand);
                                                            (yyval.arrayElements)->nextElement = NULL;
                                                        }
#line 2016 "parser.tab.c"
    break;

  case 54: /* arrayElements: content COMMA arrayElements  */
#line 581 "parser.y"
                                                        {
                                                            (yyval.arrayElements) = malloc(sizeof(struct AstNodeArrayElements)); // 4, 5, 6 -> multiple elements in array
                                                            if((yyvsp[-2].operand)->contentType == CONTENT_TYPE_EXPRESSION) {
                                                                printf("AstNodeArrayElements allocated for 'content COMMA arrayElements': %s %s %s\n", (yyvsp[-2].operand)->value.expression->leftOper->value.val, (yyvsp[-2].operand)->value.expression->op, (yyvsp[-2].operand)->value.expression->rightOper->value.val);
                                                            } else {
                                                                printf("AstNodeArrayElements allocated for 'content COMMA arrayElements': %s\n", (yyvsp[-2].operand)->value.val);
                                                            }
                                                            (yyval.arrayElements)->element = (yyvsp[-2].operand);
                                                            (yyval.arrayElements)->nextElement = (yyvsp[0].arrayElements);
                                                        }
#line 2031 "parser.tab.c"
    break;

  case 55: /* outputFunction: PRINTF LPAR STRING_VALUE RPAR  */
#line 593 "parser.y"
                                                        {
                                                            (yyval.outputFunction) = malloc(sizeof(struct AstNodeFunctionOutput));
                                                            printf("AstNodeFunctionOutput allocated for 'PRINTF LPAR STRING_VALUE RPAR'\n");
                                                            (yyval.outputFunction)->string = (yyvsp[-1].string);
                                                            (yyval.outputFunction)->outputElements = NULL;
                                                        }
#line 2042 "parser.tab.c"
    break;

  case 56: /* outputFunction: PRINTF LPAR STRING_VALUE COMMA outputElements RPAR  */
#line 599 "parser.y"
                                                        {
                                                            (yyval.outputFunction) = malloc(sizeof(struct AstNodeFunctionOutput));
                                                            printf("AstNodeFunctionOutput allocated for 'PRINTF LPAR STRING_VALUE RPAR COMMA outputElements'\n");
                                                            (yyval.outputFunction)->string = (yyvsp[-3].string);
                                                            (yyval.outputFunction)->outputElements = (yyvsp[-1].outputElements);
                                                        }
#line 2053 "parser.tab.c"
    break;

  case 57: /* inputFunction: SCANF LPAR STRING_VALUE RPAR  */
#line 607 "parser.y"
                                                        {
                                                            (yyval.inputFunction) = malloc(sizeof(struct AstNodeFunctionInput));
                                                            printf("AstNodeFunctionInput allocated for 'SCANF LPAR STRING_VALUE RPAR'\n");
                                                            (yyval.inputFunction)->string = (yyvsp[-1].string);
                                                            (yyval.inputFunction)->inputElements = NULL;
                                                        }
#line 2064 "parser.tab.c"
    break;

  case 58: /* inputFunction: SCANF LPAR STRING_VALUE COMMA inputElements RPAR  */
#line 613 "parser.y"
                                                        {
                                                            (yyval.inputFunction) = malloc(sizeof(struct AstNodeFunctionInput));
                                                            printf("AstNodeFunctionInput allocated for 'SCANF LPAR STRING_VALUE RPAR COMMA inputElements'\n");
                                                            (yyval.inputFunction)->string = (yyvsp[-3].string);
                                                            (yyval.inputFunction)->inputElements = (yyvsp[-1].inputElements);
                                                        }
#line 2075 "parser.tab.c"
    break;

  case 59: /* outputElements: content  */
#line 621 "parser.y"
                                                        {
                                                            (yyval.outputElements) = malloc(sizeof(struct AstNodeOutputElements));
                                                            printf("AstNodeOutputElements allocated for 'content'\n");
                                                            (yyval.outputElements)->element = (yyvsp[0].operand);
                                                            (yyval.outputElements)->nextElement = NULL;
                                                        }
#line 2086 "parser.tab.c"
    break;

  case 60: /* outputElements: content COMMA outputElements  */
#line 627 "parser.y"
                                                        {
                                                            (yyval.outputElements) = malloc(sizeof(struct AstNodeOutputElements));
                                                            printf("AstNodeOutputElements allocated for 'content COMMA outputElements'\n");
                                                            (yyval.outputElements)->element = (yyvsp[-2].operand);
                                                            (yyval.outputElements)->nextElement = (yyvsp[0].outputElements);
                                                        }
#line 2097 "parser.tab.c"
    break;

  case 61: /* inputElements: REFOP content  */
#line 635 "parser.y"
                                                        {
                                                            (yyval.inputElements) = malloc(sizeof(struct AstNodeInputElements));
                                                            printf("AstNodeInputElements allocated for 'content'\n");
                                                            (yyval.inputElements)->element = (yyvsp[0].operand);
                                                            (yyval.inputElements)->nextElement = NULL;
                                                        }
#line 2108 "parser.tab.c"
    break;

  case 62: /* inputElements: REFOP content COMMA inputElements  */
#line 641 "parser.y"
                                                        {
                                                            (yyval.inputElements) = malloc(sizeof(struct AstNodeInputElements));
                                                            printf("AstNodeInputElements allocated for 'content COMMA inputElements'\n");
                                                            (yyval.inputElements)->element = (yyvsp[-2].operand);
                                                            (yyval.inputElements)->nextElement = (yyvsp[0].inputElements);
                                                        }
#line 2119 "parser.tab.c"
    break;

  case 63: /* initialization: types ID  */
#line 649 "parser.y"
                                                        {
                                                            (yyval.init) = malloc(sizeof(struct AstNodeInit));
                                                            printf("AstNodeInit allocated for 'types ID'\n");
                                                            (yyval.init)->variableName = (yyvsp[0].string);
                                                            (yyval.init)->dataType = stringToType((yyvsp[-1].string));
                                                        }
#line 2130 "parser.tab.c"
    break;

  case 64: /* assignment: types ID EQ content  */
#line 657 "parser.y"
                                                        {
                                                            struct SymTab *s = NULL;
                                                            s = findSym((yyvsp[-2].string), actualList);
                                                            if (s != NULL) {
                                                                printf("\n\t***Line: %d - Error: variable %s already declared***\n\n", yylineno,(yyvsp[-2].string));
                                                            } else if ((stringToType((yyvsp[-3].string)) != (yyvsp[0].operand)->valueType) || strcmp(typeToString((yyvsp[0].operand)->valueType), "Type none") == 0) {
                                                                printf("\n\t***Line: %d - Error: cannot assign type %s to type %s***\n\n", yylineno,typeToString((yyvsp[0].operand)->valueType), (yyvsp[-3].string));
                                                            } else if(stringToType((yyvsp[-3].string)) == DATA_TYPE_VOID) {
                                                                printf("\n\t***Line: %d - Error: cannot assign a variable of type void***\n\n", yylineno);
                                                            } else {
                                                                s = createSym((yyvsp[-2].string), actualList, SYMBOL_VARIABLE, stringToType((yyvsp[-3].string)), stringToType((yyvsp[-3].string)), NULL, NULL, NULL, (yyvsp[0].operand)->value);
                                                                (yyval.assign) = malloc(sizeof(struct AstNodeAssign));
                                                                printf("AstNodeAssign allocated for 'types ID EQ content'\n");
                                                                (yyval.assign)->variableName = (yyvsp[-2].string);
                                                                (yyval.assign)->variableType = stringToType((yyvsp[-3].string));
                                                                (yyval.assign)->assignValue = (yyvsp[0].operand)->value;
                                                                (yyval.assign)->assignType = (yyvsp[0].operand)->contentType;
                                                                //printf("'types ID EQ content': the variable %s has not already been declared and then I create the symbol table for this variable\n", $2);
                                                            }
                                                        }
#line 2155 "parser.tab.c"
    break;

  case 65: /* assignment: ID EQ content  */
#line 677 "parser.y"
                                                        {
                                                            (yyval.assign) = malloc(sizeof(struct AstNodeAssign));
                                                            printf("AstNodeAssign allocated for 'ID EQ content'\n");
                                                            struct SymTab *s = NULL;
                                                            s = findSymtab((yyvsp[-2].string), actualList); 
                                                            if (s == NULL) {
                                                                printf("\n\t***Line: %d - Error: variable %s not declared***\n\n", yylineno,(yyvsp[-2].string));
                                                            } else {
                                                                if (s->dataType != (yyvsp[0].operand)->valueType) {
                                                                    printf("\n\t***Line: %d - Error: cannot asign type %s to type %s***\n\n", yylineno,typeToString((yyvsp[0].operand)->valueType), typeToString(s->dataType));
                                                                } else {
                                                                    (yyval.assign)->variableName = (yyvsp[-2].string);
                                                                    (yyval.assign)->variableType = (yyvsp[0].operand)->valueType;
                                                                    (yyval.assign)->assignValue = (yyvsp[0].operand)->value;
                                                                    (yyval.assign)->assignType = (yyvsp[0].operand)->contentType;
                                                                }
                                                            }
                                                        }
#line 2178 "parser.tab.c"
    break;

  case 66: /* expression: content ADD content  */
#line 697 "parser.y"
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
                                                                printf("\n\t***Line: %d - Error: cannot add variables of type char***\n\n", yylineno);
                                                            } else if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_VOID || (yyvsp[0].operand)->valueType == DATA_TYPE_VOID) {
                                                                printf("\n\t***Line: %d - Error: cannot add variables of type void***\n\n", yylineno);
                                                            } else if ((yyvsp[-2].operand)->valueType != (yyvsp[0].operand)->valueType) {
                                                                printf("\n\t***Line: %d - Error: cannot add variables of different types***\n\n", yylineno);
                                                            } else {
                                                                printf("Expression of type Sum\n");
                                                            }
                                                        }
#line 2202 "parser.tab.c"
    break;

  case 67: /* expression: content SUB content  */
#line 716 "parser.y"
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
                                                                printf("\n\t***Line: %d - Error: cannot subtract variables of type char***\n\n", yylineno);
                                                            } else if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_VOID || (yyvsp[0].operand)->valueType == DATA_TYPE_VOID) {
                                                                printf("\n\t***Line: %d - Error: cannot subtract variables of type void***\n\n", yylineno);
                                                            } else if ((yyvsp[-2].operand)->valueType != (yyvsp[0].operand)->valueType) {
                                                                printf("\n\t***Line: %d - Error: cannot subtract variables of different types***\n\n", yylineno);
                                                            } else {
                                                                printf("Expression of type Subtraction\n");
                                                            }
                                                        }
#line 2226 "parser.tab.c"
    break;

  case 68: /* expression: content MUL content  */
#line 735 "parser.y"
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
                                                                printf("\n\t***Line: %d - Error: cannot multiply variables of type char***\n\n", yylineno);
                                                            } else if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_VOID || (yyvsp[0].operand)->valueType == DATA_TYPE_VOID) {
                                                                printf("\n\t***Line: %d - Error: cannot multiply variables of type void***\n\n", yylineno);
                                                            } else if ((yyvsp[-2].operand)->valueType != (yyvsp[0].operand)->valueType) {
                                                                printf("\n\t***Line: %d - Error: cannot multiply variables of different types***\n\n", yylineno);
                                                            } else {
                                                                printf("Expression of type Multiplication\n");
                                                            }
                                                        }
#line 2250 "parser.tab.c"
    break;

  case 69: /* expression: content DIV content  */
#line 754 "parser.y"
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
                                                                printf("\n\t***Line: %d - Error: cannot divide variables of type char***\n\n", yylineno);
                                                            } else if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_VOID || (yyvsp[0].operand)->valueType == DATA_TYPE_VOID) {
                                                                printf("\n\t***Line: %d - Error: cannot divide variables of type void***\n\n", yylineno);
                                                            } else if ((yyvsp[-2].operand)->valueType != (yyvsp[0].operand)->valueType) {
                                                                printf("\n\t***Line: %d - Error: cannot divide variables of different types***\n\n", yylineno);
                                                            } else {
                                                                printf("Expression of type Division\n");
                                                            }
                                                        }
#line 2274 "parser.tab.c"
    break;

  case 70: /* expression: content EE content  */
#line 773 "parser.y"
                                                        {
                                                            (yyval.expression) = malloc(sizeof(struct AstNodeExpression));
                                                            printf("AstNodeExpression allocated for 'content EE content'\n");
                                                            (yyval.expression)->leftOper = malloc(sizeof(struct AstNodeOperand));
                                                            (yyval.expression)->rightOper = malloc(sizeof(struct AstNodeOperand));
                                                            (yyval.expression)->leftOper = (yyvsp[-2].operand);
                                                            (yyval.expression)->op = (yyvsp[-1].string);
                                                            (yyval.expression)->rightOper = (yyvsp[0].operand);
                                                            (yyval.expression)->exprType = DATA_TYPE_INT;
                                                            printf("Expression of type Equal to\n");
                                                        }
#line 2290 "parser.tab.c"
    break;

  case 71: /* expression: content NE content  */
#line 784 "parser.y"
                                                        {
                                                            (yyval.expression) = malloc(sizeof(struct AstNodeExpression));
                                                            printf("AstNodeExpression allocated for 'content NE content'\n");
                                                            (yyval.expression)->leftOper = malloc(sizeof(struct AstNodeOperand));
                                                            (yyval.expression)->rightOper = malloc(sizeof(struct AstNodeOperand));
                                                            (yyval.expression)->leftOper = (yyvsp[-2].operand);
                                                            (yyval.expression)->op = (yyvsp[-1].string);
                                                            (yyval.expression)->rightOper = (yyvsp[0].operand);
                                                            (yyval.expression)->exprType = DATA_TYPE_INT;
                                                            printf("Expression of type Not Equal\n");
                                                        }
#line 2306 "parser.tab.c"
    break;

  case 72: /* expression: content GT content  */
#line 795 "parser.y"
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
                                                                printf("\n\t***Line: %d - Error: cannot compare variables of type char***\n\n", yylineno);
                                                            } else if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_VOID || (yyvsp[0].operand)->valueType == DATA_TYPE_VOID) {
                                                                printf("\n\t***Line: %d - Error: cannot compare variables of type void***\n\n", yylineno);
                                                            } else {
                                                                printf("Expression of type Greater than\n");
                                                            }
                                                        }
#line 2328 "parser.tab.c"
    break;

  case 73: /* expression: content LT content  */
#line 812 "parser.y"
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
                                                                printf("\n\t***Line: %d - Error: cannot compare variables of type char***\n\n", yylineno);
                                                            } else if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_VOID || (yyvsp[0].operand)->valueType == DATA_TYPE_VOID) {
                                                                printf("\n\t***Line: %d - Error: cannot compare variables of type void***\n\n", yylineno);
                                                            } else {
                                                                printf("Expression of type Less than\n");
                                                            }
                                                        }
#line 2350 "parser.tab.c"
    break;

  case 74: /* expression: content GE content  */
#line 829 "parser.y"
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
                                                                printf("\n\t***Line: %d - Error: cannot compare variables of type char***\n\n", yylineno);
                                                            } else if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_VOID || (yyvsp[0].operand)->valueType == DATA_TYPE_VOID) {
                                                                printf("\n\t***Line: %d - Error: cannot compare variables of type void***\n\n", yylineno);
                                                            } else {
                                                                printf("Expression of type Greater than or equal to\n");
                                                            }
                                                        }
#line 2372 "parser.tab.c"
    break;

  case 75: /* expression: content LE content  */
#line 846 "parser.y"
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
                                                                printf("\n\t***Line: %d - Error: cannot compare variables of type char***\n\n", yylineno);
                                                            } else if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_VOID || (yyvsp[0].operand)->valueType == DATA_TYPE_VOID) {
                                                                printf("\n\t***Line: %d - Error: cannot compare variables of type void***\n\n", yylineno);
                                                            } else {
                                                                printf("Expression of type Less than or equal to\n");
                                                            }
                                                        }
#line 2394 "parser.tab.c"
    break;

  case 76: /* expression: content AND content  */
#line 863 "parser.y"
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
                                                                printf("\n\t***Line: %d - Error: cannot compare variables of type char***\n\n", yylineno);
                                                            } else if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_VOID || (yyvsp[0].operand)->valueType == DATA_TYPE_VOID) {
                                                                printf("\n\t***Line: %d - Error: cannot compare variables of type void***\n\n", yylineno);
                                                            } else {
                                                                printf("Expression of type AND\n");
                                                            }
                                                        }
#line 2416 "parser.tab.c"
    break;

  case 77: /* expression: content OR content  */
#line 880 "parser.y"
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
                                                                printf("\n\t***Line: %d - Error: cannot compare variables of type char***\n\n", yylineno);
                                                            } else if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_VOID || (yyvsp[0].operand)->valueType == DATA_TYPE_VOID) {
                                                                printf("\n\t***Line: %d - Error: cannot compare variables of type void***\n\n", yylineno);
                                                            } else {
                                                                printf("Expression of type OR\n");
                                                            }
                                                        }
#line 2438 "parser.tab.c"
    break;

  case 78: /* expression: NOT content  */
#line 897 "parser.y"
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
                                                                printf("\n\t***Line: %d - Error: cannot compare variables of type char***\n\n", yylineno);
                                                            } else if  ((yyvsp[0].operand)->valueType == DATA_TYPE_VOID) {
                                                                printf("\n\t***Line: %d - Error: cannot compare variables of type void***\n\n", yylineno);
                                                            } else {
                                                                printf("Expression of type NOT\n");
                                                            }
                                                        }
#line 2460 "parser.tab.c"
    break;

  case 79: /* content: ID  */
#line 916 "parser.y"
                                                        {
                                                            (yyval.operand) = malloc(sizeof(struct AstNodeOperand));
                                                            printf("AstNodeOperand allocated for 'ID'\n"); //Ci troviamo nel caso in cui abbiamo int a = b
                                                            struct SymTab *s = findSymtab((yyvsp[0].string),actualList);
                                                            if(s == NULL) {
                                                                printf("\n\t***Line: %d - Error: The variable %s does not exist***\n\n", yylineno,(yyvsp[0].string));
                                                            } else {
                                                                (yyval.operand)->value.val = (yyvsp[0].string);
                                                                (yyval.operand)->valueType = s->dataType;
                                                                (yyval.operand)->contentType = CONTENT_TYPE_ID;
                                                            }
                                                        }
#line 2477 "parser.tab.c"
    break;

  case 80: /* content: INT_VALUE  */
#line 928 "parser.y"
                                                        {
                                                            (yyval.operand) = malloc(sizeof(struct AstNodeOperand));
                                                            printf("AstNodeOperand allocated for 'INT_VALUE'\n");
                                                            (yyval.operand)->value.val = (yyvsp[0].string);
                                                            (yyval.operand)->valueType = DATA_TYPE_INT;
                                                            (yyval.operand)->contentType = CONTENT_TYPE_INT_NUMBER;
                                                        }
#line 2489 "parser.tab.c"
    break;

  case 81: /* content: FLOAT_VALUE  */
#line 935 "parser.y"
                                                        {
                                                            (yyval.operand) = malloc(sizeof(struct AstNodeOperand));
                                                            printf("AstNodeOperand allocated for 'FLOAT_VALUE'\n");
                                                            (yyval.operand)->value.val = (yyvsp[0].string);
                                                            (yyval.operand)->valueType = DATA_TYPE_FLOAT;
                                                            (yyval.operand)->contentType = CONTENT_TYPE_FLOAT_NUMBER;
                                                        }
#line 2501 "parser.tab.c"
    break;

  case 82: /* content: CHAR_VALUE  */
#line 942 "parser.y"
                                                        {
                                                            (yyval.operand) = malloc(sizeof(struct AstNodeOperand));
                                                            printf("AstNodeOperand allocated for 'CHAR_VALUE'\n");
                                                            (yyval.operand)->value.val = (yyvsp[0].string);
                                                            (yyval.operand)->valueType = DATA_TYPE_CHAR;
                                                            (yyval.operand)->contentType = CONTENT_TYPE_CHAR;
                                                        }
#line 2513 "parser.tab.c"
    break;

  case 83: /* content: expression  */
#line 949 "parser.y"
                                                        {
                                                            (yyval.operand) = malloc(sizeof(struct AstNodeOperand));
                                                            printf("AstNodeOperand allocated for 'expression'\n");
                                                            (yyval.operand)->value.expression = (yyvsp[0].expression);
                                                            (yyval.operand)->valueType = (yyvsp[0].expression)->exprType;
                                                            (yyval.operand)->contentType = CONTENT_TYPE_EXPRESSION;
                                                        }
#line 2525 "parser.tab.c"
    break;

  case 84: /* content: functionCall  */
#line 956 "parser.y"
                                                        {
                                                            (yyval.operand) = malloc(sizeof(struct AstNodeOperand));
                                                            printf("AstNodeOperand allocated for 'functionCall'\n");
                                                            (yyval.operand)->value.funtionCall = (yyvsp[0].functionCall);
                                                            (yyval.operand)->valueType = (yyvsp[0].functionCall)->returnType;
                                                            (yyval.operand)->contentType = CONTENT_TYPE_FUNCTION;
                                                        }
#line 2537 "parser.tab.c"
    break;

  case 85: /* content: arrayCall  */
#line 963 "parser.y"
                                                        {
                                                            (yyval.operand) = malloc(sizeof(struct AstNodeOperand));
                                                            printf("AstNodeOperand allocated for 'arrayCall'\n");
                                                            struct SymTab *s = findSymtab((yyvsp[0].arrayCall)->arrayName,actualList);
                                                            if (s != NULL) {
                                                                (yyval.operand)->value.arrayCall = (yyvsp[0].arrayCall);
                                                                (yyval.operand)->valueType = s->dataType;
                                                                (yyval.operand)->contentType = CONTENT_TYPE_ARRAY;
                                                            }
                                                        }
#line 2552 "parser.tab.c"
    break;

  case 86: /* types: VOID  */
#line 975 "parser.y"
                                                        {
                                                            printf("Defined 'type: VOID'\n");
                                                        }
#line 2560 "parser.tab.c"
    break;

  case 87: /* types: INT  */
#line 978 "parser.y"
                                                        {
                                                            printf("Defined 'type: INT'\n");
                                                        }
#line 2568 "parser.tab.c"
    break;

  case 88: /* types: FLOAT  */
#line 981 "parser.y"
                                                        {
                                                            printf("Defined 'type: FLOAT'\n");
                                                        }
#line 2576 "parser.tab.c"
    break;

  case 89: /* types: CHAR  */
#line 984 "parser.y"
                                                        {
                                                            printf("Defined 'type: CHAR'\n");
                                                        }
#line 2584 "parser.tab.c"
    break;


#line 2588 "parser.tab.c"

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

#line 988 "parser.y"


int main() {
    yyparse();
    nullValue.val = NULL;
    counter = 0;
    fptr = fopen("test.py", "w");
    translate(root);
    fclose(fptr);
    printf("Translation completed!\n");
    
    return 0;
}

int yyerror(char *s) {
    printf("Line: %d - %s\n", yylineno,s);
}

void beginScope() {
    actualList = createList(counter, actualList);
    counter++;
}

void endScope() {
    deleteList(actualList);
    counter--;
}

char *typeToString(int type) {
    switch(type) {
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
        case DATA_TYPE_NONE:
            return "Type none";
        default:
            return "Type not defined";
        break;
    }
}

int stringToType(char *type) {
    if (strcmp(type, "void") == 0) {
        return DATA_TYPE_VOID;
    } else if (strcmp(type, "int") == 0) {
        return DATA_TYPE_INT;
    } else if (strcmp(type, "float") == 0) {
        return DATA_TYPE_FLOAT;
    } else if (strcmp(type, "char") == 0) {
        return DATA_TYPE_CHAR;
    } else {
        return DATA_TYPE_NONE;
    }
}
