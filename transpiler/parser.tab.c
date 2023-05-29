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
int numberError = 0;
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
#define YYLAST   380

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  180

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
       0,   103,   103,   103,   112,   119,   128,   134,   140,   159,
     165,   171,   191,   197,   203,   209,   215,   221,   229,   229,
     251,   251,   272,   275,   272,   305,   317,   345,   354,   361,
     370,   379,   379,   389,   396,   396,   406,   413,   413,   424,
     424,   434,   441,   447,   453,   461,   483,   500,   512,   539,
     548,   562,   576,   582,   590,   596,   614,   624,   636,   642,
     650,   656,   664,   670,   678,   684,   692,   700,   723,   745,
     767,   789,   811,   833,   844,   855,   874,   893,   912,   931,
     950,   969,   990,  1003,  1010,  1017,  1024,  1031,  1038,  1050,
    1053,  1056,  1059
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

#define YYPACT_NINF (-80)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -80,     5,   152,   -80,   -80,   -80,   -80,   -80,    26,    24,
      27,    51,    77,    -8,   -80,   152,   -80,   -15,   -80,   -80,
     -80,   -80,    76,    79,    21,    81,    84,   -10,    86,    -9,
       7,   101,    95,    53,    92,    93,   140,    99,   269,   -80,
     -80,   -80,   -80,    85,   -80,   -80,   153,   -80,   -80,   155,
      -2,   163,   140,    95,   -80,   -80,    48,   -80,   -80,   -80,
     156,   268,   274,   142,   -80,    95,   170,    18,    22,   -80,
     268,   -80,   171,   149,   164,   -80,   255,   282,   -80,   172,
     -80,   104,   187,   140,     2,   290,   -80,   -80,   -80,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140,    95,   188,   140,     4,   -80,   -80,   -80,   140,   -80,
     205,   -80,   104,   166,   -80,   -80,   186,   140,    95,   -80,
     -80,   268,   -80,   202,   297,   -80,    95,   322,   322,   332,
     340,   347,   353,    61,    74,    69,    16,   208,   -80,   -80,
     -80,   223,   140,   -80,    95,   207,   189,   140,   221,   -80,
     104,   -80,   -80,   -80,   222,    95,   -80,   -80,   219,   -80,
      95,   233,   239,   -80,   -80,   140,   206,   -80,   -80,    95,
     -80,   -80,   -80,   -80,   234,   -80,   205,   -80,   -80,   -80
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,    89,    90,    91,    92,     0,    37,
       0,     0,     0,     0,     3,     5,     6,     0,    14,    15,
      16,    17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     4,
       7,    10,    11,     0,    12,    13,    22,     8,     9,     0,
      66,    45,     0,     0,    83,    84,    82,    85,    87,    88,
      86,     0,     0,     0,    38,     0,    86,     0,     0,    86,
      68,    25,     0,    28,     0,    54,     0,     0,    50,    56,
      20,     0,     0,     0,     0,     0,    81,    33,    31,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    86,     0,     0,    41,    39,    58,     0,    60,
       0,    26,     0,    27,    55,    49,     0,     0,     0,    23,
      18,    67,    52,     0,     0,    47,     0,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    36,
      34,     0,     0,    42,     0,     0,    62,     0,     0,    30,
       0,    51,    57,    21,     0,     0,    53,    46,     0,    32,
       0,     0,     0,    40,    59,     0,    64,    61,    29,     0,
      19,    48,    35,    44,     0,    63,     0,    24,    43,    65
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -80,   -80,   -80,   -14,   -80,   -80,   -80,   -80,   -80,   -80,
      11,   -79,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     -29,   -80,   -80,   -80,    12,   -67,   -80,   -80,    71,   120,
     -80,   -80,   -21,   -30,    13
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    14,    15,    16,   155,   118,    81,   154,
      58,    72,    18,   126,    19,   160,    20,    32,    21,   144,
      64,    22,    23,    51,    59,    78,    25,    26,   145,   148,
      27,    28,    69,    79,    74
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      61,    39,   119,    61,    49,     3,    70,    73,    76,    60,
     116,    36,    66,    17,    24,    29,   142,    83,   125,    46,
      40,    37,    86,    38,    87,    47,    17,    24,    29,    84,
      50,    31,    61,   149,   122,    52,   105,    53,   143,   123,
      43,   102,    99,   100,    54,    55,    56,    57,   107,   104,
     152,    73,   109,   121,   108,    30,    33,   158,   110,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   168,   139,   141,    17,    24,    29,    37,   146,    38,
      34,    52,    73,    65,    96,    97,    98,    99,   100,   153,
      54,    55,    56,    57,    98,    99,   100,   159,    97,    98,
      99,   100,     4,     5,     6,     7,    35,     4,     5,     6,
       7,    41,   162,    52,    42,   163,    44,   166,    77,    45,
      73,    48,    54,    55,    56,    57,   170,    52,    63,    71,
      62,   172,    52,    67,    68,   146,    54,    55,    56,    57,
     177,    54,    55,    56,    57,     4,     5,     6,     7,     8,
       9,    10,    11,    12,   103,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    89,    90,    91,    92,    52,    93,
      94,    95,    96,    97,    98,    99,   100,    54,    55,    56,
      57,    13,    85,    80,    82,   112,    88,    89,    90,    91,
      92,    13,    93,    94,    95,    96,    97,    98,    99,   100,
     106,   111,   150,   113,    89,    90,    91,    92,   117,    93,
      94,    95,    96,    97,    98,    99,   100,   120,   140,   147,
     151,    89,    90,    91,    92,   165,    93,    94,    95,    96,
      97,    98,    99,   100,   156,   100,   175,   164,    89,    90,
      91,    92,   176,    93,    94,    95,    96,    97,    98,    99,
     100,   167,   169,   171,    89,    90,    91,    92,   161,    93,
      94,    95,    96,    97,    98,    99,   100,   173,   178,     0,
      89,    90,    91,    92,   174,    93,    94,    95,    96,    97,
      98,    99,   100,    89,    90,    91,    92,   114,    93,    94,
      95,    96,    97,    98,    99,   100,   179,    52,     0,     0,
       0,    75,    52,     0,   101,     0,    54,    55,    56,    57,
      52,    54,    55,    56,    57,     0,   115,     0,    52,    54,
      55,    56,    57,   124,     0,    52,     0,    54,    55,    56,
      57,   157,     0,     0,    54,    55,    56,    57,    90,    91,
      92,     0,    93,    94,    95,    96,    97,    98,    99,   100,
      92,     0,    93,    94,    95,    96,    97,    98,    99,   100,
      93,    94,    95,    96,    97,    98,    99,   100,    94,    95,
      96,    97,    98,    99,   100,    95,    96,    97,    98,    99,
     100
};

static const yytype_int16 yycheck[] =
{
      30,    15,    81,    33,    13,     0,    36,    37,    38,    30,
      77,    19,    33,     2,     2,     2,    12,    19,    85,    29,
      35,    29,    52,    31,    53,    35,    15,    15,    15,    31,
      39,     7,    62,   112,    32,    28,    65,    30,    34,    37,
      19,    62,    26,    27,    37,    38,    39,    40,    30,    63,
     117,    81,    30,    83,    36,    29,    29,   124,    36,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   150,   101,   103,    63,    63,    63,    29,   108,    31,
      29,    28,   112,    30,    23,    24,    25,    26,    27,   118,
      37,    38,    39,    40,    25,    26,    27,   126,    24,    25,
      26,    27,     3,     4,     5,     6,    29,     3,     4,     5,
       6,    35,   142,    28,    35,   144,    35,   147,    33,    35,
     150,    35,    37,    38,    39,    40,   155,    28,    33,    30,
      29,   160,    28,    41,    41,   165,    37,    38,    39,    40,
     169,    37,    38,    39,    40,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    15,    16,    17,    18,    28,    20,
      21,    22,    23,    24,    25,    26,    27,    37,    38,    39,
      40,    39,    19,    30,    29,    36,    30,    15,    16,    17,
      18,    39,    20,    21,    22,    23,    24,    25,    26,    27,
      30,    30,    36,    39,    15,    16,    17,    18,    36,    20,
      21,    22,    23,    24,    25,    26,    27,    30,    30,    14,
      34,    15,    16,    17,    18,    36,    20,    21,    22,    23,
      24,    25,    26,    27,    32,    27,   165,    30,    15,    16,
      17,    18,    36,    20,    21,    22,    23,    24,    25,    26,
      27,    30,    30,    34,    15,    16,    17,    18,    35,    20,
      21,    22,    23,    24,    25,    26,    27,    34,    34,    -1,
      15,    16,    17,    18,    35,    20,    21,    22,    23,    24,
      25,    26,    27,    15,    16,    17,    18,    32,    20,    21,
      22,    23,    24,    25,    26,    27,   176,    28,    -1,    -1,
      -1,    32,    28,    -1,    30,    -1,    37,    38,    39,    40,
      28,    37,    38,    39,    40,    -1,    34,    -1,    28,    37,
      38,    39,    40,    33,    -1,    28,    -1,    37,    38,    39,
      40,    34,    -1,    -1,    37,    38,    39,    40,    16,    17,
      18,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      18,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      20,    21,    22,    23,    24,    25,    26,    27,    21,    22,
      23,    24,    25,    26,    27,    22,    23,    24,    25,    26,
      27
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
      39,    66,    28,    30,    37,    38,    39,    40,    53,    67,
      75,    76,    29,    33,    63,    30,    75,    41,    41,    75,
      76,    30,    54,    76,    77,    32,    76,    33,    68,    76,
      30,    51,    29,    19,    31,    19,    76,    63,    30,    15,
      16,    17,    18,    20,    21,    22,    23,    24,    25,    26,
      27,    30,    75,    12,    46,    63,    30,    30,    36,    30,
      36,    30,    36,    39,    32,    34,    68,    36,    50,    54,
      30,    76,    32,    37,    33,    68,    56,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    63,
      30,    76,    12,    34,    62,    71,    76,    14,    72,    54,
      36,    34,    68,    63,    52,    49,    32,    34,    68,    63,
      58,    35,    76,    63,    30,    36,    76,    30,    54,    30,
      63,    34,    63,    34,    35,    71,    36,    63,    34,    72
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    45,    44,    46,    46,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    49,    48,
      50,    48,    51,    52,    48,    53,    53,    54,    54,    54,
      54,    56,    55,    55,    58,    57,    57,    60,    59,    62,
      61,    61,    63,    63,    63,    64,    64,    64,    64,    65,
      65,    65,    66,    66,    67,    67,    68,    68,    69,    69,
      70,    70,    71,    71,    72,    72,    73,    74,    74,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    76,    76,    76,    76,    76,    76,    76,    77,
      77,    77,    77
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     1,     2,     2,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     0,     6,
       0,     5,     0,     0,     7,     3,     4,     2,     1,     4,
       3,     0,     6,     4,     0,     7,     5,     0,     3,     0,
       6,     4,     3,     6,     5,     2,     5,     4,     6,     4,
       3,     5,     3,     4,     3,     4,     1,     3,     4,     6,
       4,     6,     1,     3,     2,     4,     2,     4,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
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
#line 1327 "parser.tab.c"
    break;

  case 3: /* program: $@1 statements  */
#line 106 "parser.y"
                                                        {
                                                            root = (yyvsp[0].statements);
                                                            endScope();
                                                        }
#line 1336 "parser.tab.c"
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
#line 1348 "parser.tab.c"
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
#line 1360 "parser.tab.c"
    break;

  case 6: /* instruction: functionDecl  */
#line 128 "parser.y"
                                                        {
                                                            (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                            printf("AstNodeInstruction allocated for 'functionDecl SEMICOL'\n");
                                                            (yyval.instruction)->nodeType = FUNCTION_DECL_NODE;
                                                            (yyval.instruction)->value.functionDecl = (yyvsp[0].functionDecl);
                                                        }
#line 1371 "parser.tab.c"
    break;

  case 7: /* instruction: functionCall SEMICOL  */
#line 134 "parser.y"
                                                        {
                                                            (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                            printf("AstNodeInstruction allocated for 'functionCall SEMICOL'\n");
                                                            (yyval.instruction)->nodeType = FUNCTION_CALL_NODE;
                                                            (yyval.instruction)->value.functionCall = (yyvsp[-1].functionCall);
                                                        }
#line 1382 "parser.tab.c"
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
                                                                    numberError++;
                                                                } else {
                                                                    printf("AstNodeInstruction allocated for 'initialization SEMICOL'\n");
                                                                    (yyval.instruction)->nodeType = INIT_NODE;
                                                                    (yyval.instruction)->value.init = (yyvsp[-1].init);
                                                                    s = createSym((yyvsp[-1].init)->variableName, actualList, SYMBOL_VARIABLE, (yyvsp[-1].init)->dataType, (yyvsp[-1].init)->dataType, NULL, NULL, NULL, nullValue);
                                                                }
                                                            } else {
                                                                printf("\n\t***Line: %d - Error: variable already declared.***\n\n", yylineno);
                                                                numberError++;
                                                            }
                                                        }
#line 1406 "parser.tab.c"
    break;

  case 9: /* instruction: assignment SEMICOL  */
#line 159 "parser.y"
                                                        {
                                                            (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                            printf("AstNodeInstruction allocated for 'assignment SEMICOL'\n");
                                                            (yyval.instruction)->nodeType = ASSIGN_NODE;
                                                            (yyval.instruction)->value.assign = (yyvsp[-1].assign);
                                                        }
#line 1417 "parser.tab.c"
    break;

  case 10: /* instruction: arrayInit SEMICOL  */
#line 165 "parser.y"
                                                        {
                                                            (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                            printf("AstNodeInstruction allocated for 'arrayInit'\n");
                                                            (yyval.instruction)->nodeType = ARRAY_INIT_NODE;
                                                            (yyval.instruction)->value.arrayInit = (yyvsp[-1].arrayInit);
                                                        }
#line 1428 "parser.tab.c"
    break;

  case 11: /* instruction: arrayAssign SEMICOL  */
#line 171 "parser.y"
                                                        {
                                                            struct SymTab *s = findSym((yyvsp[-1].arrayAssign)->arrayCall->arrayName, actualList);
                                                            if (s != NULL) {
                                                                if(s->dataType != (yyvsp[-1].arrayAssign)->arrayType) {
                                                                    printf("\n\t***Line: %d - Error: Array %s has been declared as a %s but type %s is assigned***\n\n", yylineno, (yyvsp[-1].arrayAssign)->arrayCall->arrayName, typeToString(s->dataType), typeToString((yyvsp[-1].arrayAssign)->arrayType));
                                                                    numberError++;
                                                                } else if((yyvsp[-1].arrayAssign)->arrayCall->elementIndex != NULL && (atoi(s->arrayLength) <= atoi((yyvsp[-1].arrayAssign)->arrayCall->elementIndex->value.val))) {
                                                                    printf("\n\t***Line: %d - Error: the length of '%s' is %s***\n\n", yylineno,s->symbolName, s->arrayLength);
                                                                    numberError++;
                                                                }else {
                                                                    (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                                    printf("AstNodeInstruction allocated for 'arrayAssign'\n");
                                                                    (yyval.instruction)->nodeType = ARRAY_ASSIGN_NODE;
                                                                    (yyval.instruction)->value.arrayAssign = (yyvsp[-1].arrayAssign);
                                                                }
                                                            } else {
                                                                printf("\n\t***Line: %d - Error: array '%s' not declared***\n\n", yylineno,(yyvsp[-1].arrayAssign)->arrayCall->arrayName);
                                                                numberError++;
                                                            }
                                                        }
#line 1453 "parser.tab.c"
    break;

  case 12: /* instruction: outputFunction SEMICOL  */
#line 191 "parser.y"
                                                        {
                                                            (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                            printf("AstNodeInstruction allocated for 'outputFunction SEMICOL'\n");
                                                            (yyval.instruction)->nodeType = OUTPUT_NODE;
                                                            (yyval.instruction)->value.outputFunction = (yyvsp[-1].outputFunction);
                                                        }
#line 1464 "parser.tab.c"
    break;

  case 13: /* instruction: inputFunction SEMICOL  */
#line 197 "parser.y"
                                                        {
                                                            (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                            printf("AstNodeInstruction allocated for 'inputFunction SEMICOL'\n");
                                                            (yyval.instruction)->nodeType = INPUT_NODE;
                                                            (yyval.instruction)->value.inputFunction = (yyvsp[-1].inputFunction);
                                                        }
#line 1475 "parser.tab.c"
    break;

  case 14: /* instruction: ifStatement  */
#line 203 "parser.y"
                                                        {
                                                            (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                            printf("AstNodeInstruction allocated for 'ifStatement'\n");
                                                            (yyval.instruction)->nodeType = IF_NODE;
                                                            (yyval.instruction)->value.ifStatement = (yyvsp[0].ifStatement);
                                                        }
#line 1486 "parser.tab.c"
    break;

  case 15: /* instruction: elseifStatement  */
#line 209 "parser.y"
                                                        {
                                                            (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                            printf("AstNodeInstruction allocated for 'elseifStatement'\n");
                                                            (yyval.instruction)->nodeType = ELSE_IF_NODE;
                                                            (yyval.instruction)->value.elseifStatement = (yyvsp[0].elseifStatement);
                                                        }
#line 1497 "parser.tab.c"
    break;

  case 16: /* instruction: elseStatement  */
#line 215 "parser.y"
                                                        {
                                                            (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                            printf("AstNodeInstruction allocated for 'elseStatement'\n");
                                                            (yyval.instruction)->nodeType = ELSE_NODE;
                                                            (yyval.instruction)->value.elseStatement = (yyvsp[0].elseStatement);
                                                        }
#line 1508 "parser.tab.c"
    break;

  case 17: /* instruction: whileLoop  */
#line 221 "parser.y"
                                                        {
                                                            (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                            printf("AstNodeInstruction allocated for 'whileLoop'\n");
                                                            (yyval.instruction)->nodeType = WHILE_NODE;
                                                            (yyval.instruction)->value.whileLoop = (yyvsp[0].whileLoop);
                                                        }
#line 1519 "parser.tab.c"
    break;

  case 18: /* $@2: %empty  */
#line 229 "parser.y"
                                                        {
                                                            beginScope();
                                                        }
#line 1527 "parser.tab.c"
    break;

  case 19: /* functionDecl: types MAIN LPAR RPAR $@2 body  */
#line 232 "parser.y"
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
                                                                printf("\n\t***Line: %d - Error: function 'MAIN' already declared***\n\n", yylineno);
                                                                numberError++;
                                                                endScope();
                                                            } 
                                                        }
#line 1551 "parser.tab.c"
    break;

  case 20: /* $@3: %empty  */
#line 251 "parser.y"
                                                        {
                                                            beginScope();
                                                        }
#line 1559 "parser.tab.c"
    break;

  case 21: /* functionDecl: initialization LPAR RPAR $@3 body  */
#line 254 "parser.y"
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
                                                                printf("\n\t***Line: %d - Error: function '%s' already declared***\n\n", yylineno,(yyvsp[-4].init)->variableName);
                                                                numberError++;
                                                                endScope();
                                                            } 
                                                        }
#line 1582 "parser.tab.c"
    break;

  case 22: /* $@4: %empty  */
#line 272 "parser.y"
                                                        {   
                                                            beginScope();
                                                        }
#line 1590 "parser.tab.c"
    break;

  case 23: /* $@5: %empty  */
#line 275 "parser.y"
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
#line 1605 "parser.tab.c"
    break;

  case 24: /* functionDecl: initialization LPAR $@4 functionParams $@5 RPAR body  */
#line 285 "parser.y"
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
                                                                printf("\n\t***Line: %d - Error: function '%s' already declared***\n\n", yylineno,(yyvsp[-6].init)->variableName);
                                                                numberError++;
                                                                endScope();
                                                            }
                                                        }
#line 1628 "parser.tab.c"
    break;

  case 25: /* functionCall: ID LPAR RPAR  */
#line 305 "parser.y"
                                                        {
                                                            (yyval.functionCall) = malloc(sizeof(struct AstNodeFunctionCall));
                                                            printf("AstNodeFunctionCall allocated for 'ID LPAR RPAR'\n");
                                                            struct SymTab *s = findSymtab((yyvsp[-2].string), actualList);
                                                            if (s != NULL) { 
                                                                (yyval.functionCall)->functionName = (yyvsp[-2].string);
                                                                (yyval.functionCall)->returnType = s->returnType;
                                                                (yyval.functionCall)->functionParams = NULL;
                                                            } else {
                                                                printf("\n\t***Line: %d - Error: function '%s' not declared***\n\n", yylineno,(yyvsp[-2].string));
                                                            } 
                                                        }
#line 1645 "parser.tab.c"
    break;

  case 26: /* functionCall: ID LPAR functionParams RPAR  */
#line 317 "parser.y"
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
                                                                } else {
                                                                    printf("\n\t***Line: %d - Error: the parameters in the function call are incorrect***\n\n", yylineno);
                                                                    numberError++;
                                                                }
                                                                (yyval.functionCall)->functionName = (yyvsp[-3].string);
                                                                (yyval.functionCall)->returnType = s->returnType;
                                                                (yyval.functionCall)->functionParams = (yyvsp[-1].functionParams);
                                                            } else {
                                                                printf("\n\t***Line: %d - Error: function '%s' not declared***\n\n", yylineno,(yyvsp[-3].string));
                                                                numberError++;
                                                            }
                                                        }
#line 1676 "parser.tab.c"
    break;

  case 27: /* functionParams: types ID  */
#line 345 "parser.y"
                                                        {
                                                            (yyval.functionParams) = malloc(sizeof(struct AstNodeFunctionParams));
                                                            printf("AstNodeFunctionParams allocated for 'types ID'\n");
                                                            (yyval.functionParams)->nextParams = NULL;
                                                            (yyval.functionParams)->callParams = NULL;
                                                            (yyval.functionParams)->initParam = malloc(sizeof(struct AstNodeInit));
                                                            (yyval.functionParams)->initParam->dataType = stringToType((yyvsp[-1].string));
                                                            (yyval.functionParams)->initParam->variableName = (yyvsp[0].string);
                                                        }
#line 1690 "parser.tab.c"
    break;

  case 28: /* functionParams: content  */
#line 354 "parser.y"
                                                        {
                                                            (yyval.functionParams) = malloc(sizeof(struct AstNodeFunctionParams));
                                                            printf("AstNodeFunctionParams allocated for 'content'\n");
                                                            (yyval.functionParams)->nextParams = NULL;
                                                            (yyval.functionParams)->callParams = (yyvsp[0].operand);
                                                            (yyval.functionParams)->initParam = NULL;
                                                        }
#line 1702 "parser.tab.c"
    break;

  case 29: /* functionParams: types ID COMMA functionParams  */
#line 361 "parser.y"
                                                        {
                                                            (yyval.functionParams) = malloc(sizeof(struct AstNodeFunctionParams));
                                                            printf("AstNodeFunctionParams allocated for 'types ID COMMA functionParams'\n");
                                                            (yyval.functionParams)->nextParams = (yyvsp[0].functionParams);
                                                            (yyval.functionParams)->callParams = NULL;
                                                            (yyval.functionParams)->initParam = malloc(sizeof(struct AstNodeInit));
                                                            (yyval.functionParams)->initParam->dataType = stringToType((yyvsp[-3].string));
                                                            (yyval.functionParams)->initParam->variableName = (yyvsp[-2].string);
                                                        }
#line 1716 "parser.tab.c"
    break;

  case 30: /* functionParams: content COMMA functionParams  */
#line 370 "parser.y"
                                                        {
                                                            (yyval.functionParams) = malloc(sizeof(struct AstNodeFunctionParams));
                                                            printf("AstNodeFunctionParams allocated for 'content COMMA functionParams'\n");
                                                            (yyval.functionParams)->nextParams = (yyvsp[0].functionParams);
                                                            (yyval.functionParams)->callParams = (yyvsp[-2].operand);
                                                            (yyval.functionParams)->initParam = NULL;
                                                        }
#line 1728 "parser.tab.c"
    break;

  case 31: /* $@6: %empty  */
#line 379 "parser.y"
                                                        {
                                                            beginScope();
                                                        }
#line 1736 "parser.tab.c"
    break;

  case 32: /* ifStatement: IF LPAR expression RPAR $@6 body  */
#line 382 "parser.y"
                                                        {
                                                            (yyval.ifStatement) = malloc(sizeof(struct AstNodeIf));
                                                            printf("AstNodeIf allocated for 'IF LPAR expression RPAR body'\n");
                                                            (yyval.ifStatement)->ifCondition = (yyvsp[-3].expression);
                                                            (yyval.ifStatement)->ifBody = (yyvsp[0].body);
                                                            endScope();
                                                        }
#line 1748 "parser.tab.c"
    break;

  case 33: /* ifStatement: IF LPAR RPAR body  */
#line 389 "parser.y"
                                                        {
                                                            (yyval.ifStatement) = malloc(sizeof(struct AstNodeIf));
                                                            printf("AstNodeIf allocated for 'IF LPAR expression RPAR body'\n");
                                                            printf("\n\t***Line: %d - Error: missing condition in 'if statement'***\n\n", yylineno);
                                                        }
#line 1758 "parser.tab.c"
    break;

  case 34: /* $@7: %empty  */
#line 396 "parser.y"
                                                        {
                                                            beginScope();
                                                        }
#line 1766 "parser.tab.c"
    break;

  case 35: /* elseifStatement: ELSE IF LPAR expression RPAR $@7 body  */
#line 399 "parser.y"
                                                        {
                                                            (yyval.elseifStatement) = malloc(sizeof(struct AstNodeElseIf));
                                                            printf("AstNodeElseIf allocated for 'ELSE IF LPAR expression RPAR body'\n");
                                                            (yyval.elseifStatement)->elseifCondition = (yyvsp[-3].expression);
                                                            (yyval.elseifStatement)->elseifBody = (yyvsp[0].body);
                                                            endScope();
                                                        }
#line 1778 "parser.tab.c"
    break;

  case 36: /* elseifStatement: ELSE IF LPAR RPAR body  */
#line 406 "parser.y"
                                                        {
                                                            (yyval.elseifStatement) = malloc(sizeof(struct AstNodeIf));
                                                            printf("AstNodeIf allocated for 'IF LPAR expression RPAR body'\n");
                                                            printf("\n\t***Line: %d - Error: missing condition in 'else if statement'***\n\n", yylineno);
                                                        }
#line 1788 "parser.tab.c"
    break;

  case 37: /* $@8: %empty  */
#line 413 "parser.y"
                                                        {
                                                            beginScope();
                                                        }
#line 1796 "parser.tab.c"
    break;

  case 38: /* elseStatement: ELSE $@8 body  */
#line 416 "parser.y"
                                                        {
                                                            (yyval.elseStatement) = malloc(sizeof(struct AstNodeElse));
                                                            printf("AstNodeElse allocated for 'ELSE body'\n");
                                                            (yyval.elseStatement)->elseBody = (yyvsp[0].body);
                                                            endScope();
                                                        }
#line 1807 "parser.tab.c"
    break;

  case 39: /* $@9: %empty  */
#line 424 "parser.y"
                                                        {
                                                            beginScope();
                                                        }
#line 1815 "parser.tab.c"
    break;

  case 40: /* whileLoop: WHILE LPAR expression RPAR $@9 body  */
#line 427 "parser.y"
                                                        {
                                                            (yyval.whileLoop) = malloc(sizeof(struct AstNodeWhile));
                                                            printf("AstNodeWhile allocated for 'WHILE LPAR expression RPAR body'\n");
                                                            (yyval.whileLoop)->whileCondition = (yyvsp[-3].expression);
                                                            (yyval.whileLoop)->whileBody = (yyvsp[0].body);
                                                            endScope();
                                                        }
#line 1827 "parser.tab.c"
    break;

  case 41: /* whileLoop: WHILE LPAR RPAR body  */
#line 434 "parser.y"
                                                        {
                                                            (yyval.whileLoop) = malloc(sizeof(struct AstNodeIf));
                                                            printf("AstNodeIf allocated for 'IF LPAR expression RPAR body'\n");
                                                            printf("\n\t***Line: %d - Error: missing condition in 'while statement'***\n\n", yylineno);
                                                        }
#line 1837 "parser.tab.c"
    break;

  case 42: /* body: LBRA statements RBRA  */
#line 441 "parser.y"
                                                        {
                                                            (yyval.body) = malloc(sizeof(struct AstNodeBody));
                                                            printf("AstNodeBody allocated for 'LBRA statements RBRA'\n");
                                                            (yyval.body)->bodyStatements = (yyvsp[-1].statements);
                                                            (yyval.body)->returnValue = NULL;
                                                        }
#line 1848 "parser.tab.c"
    break;

  case 43: /* body: LBRA statements RETURN content SEMICOL RBRA  */
#line 447 "parser.y"
                                                        {
                                                            (yyval.body) = malloc(sizeof(struct AstNodeBody));
                                                            printf("AstNodeBody allocated for 'LBRA statements RETURN content SEMICOL RBRA'\n");
                                                            (yyval.body)->bodyStatements = (yyvsp[-4].statements);
                                                            (yyval.body)->returnValue = (yyvsp[-2].operand);
                                                        }
#line 1859 "parser.tab.c"
    break;

  case 44: /* body: LBRA RETURN content SEMICOL RBRA  */
#line 453 "parser.y"
                                                        {
                                                            (yyval.body)=malloc(sizeof(struct AstNodeBody));
                                                            printf("AstNodeBody allocated for 'LBRA RETURN content SEMICOL RBRA'\n");
                                                            (yyval.body)->bodyStatements = NULL;
                                                            (yyval.body)->returnValue = (yyvsp[-2].operand);
                                                        }
#line 1870 "parser.tab.c"
    break;

  case 45: /* arrayInit: types arrayDecl  */
#line 461 "parser.y"
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
                                                                    printf("\n\t***Line: %d - Error: array size missing in '%s'***\n\n", yylineno,(yyvsp[0].arrayDecl)->arrayName);
                                                                    numberError++;
                                                                } else {
                                                                    s = createSym((yyvsp[0].arrayDecl)->arrayName, actualList, SYMBOL_ARRAY, (yyval.arrayInit)->arrayType, (yyval.arrayInit)->arrayType, NULL, NULL, (yyvsp[0].arrayDecl)->arrayLength, nullValue);
                                                                }
                                                            } else {
                                                                printf("\n\t***Line: %d - Error: array '%s' already declared***\n\n", yylineno,(yyvsp[0].arrayDecl)->arrayName);
                                                                numberError++;
                                                            }
                                                        }
#line 1897 "parser.tab.c"
    break;

  case 46: /* arrayInit: types arrayDecl EQ LBRA RBRA  */
#line 483 "parser.y"
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
                                                                printf("\n\t***Line: %d - Error: array '%s' already declared***\n\n", yylineno,(yyvsp[-3].arrayDecl)->arrayName);
                                                                numberError++;
                                                            }
                                                        }
#line 1919 "parser.tab.c"
    break;

  case 47: /* arrayInit: types arrayDecl EQ arrayElements  */
#line 500 "parser.y"
                                                        {
                                                            //int myArray[] = 24; Error: invalid initializer !!!
                                                            //int myArray[3] = 24; Error: invalid initializer !!!
                                                            (yyval.arrayInit)=malloc(sizeof(struct AstNodeArrayInit));
                                                            printf("AstNodeArrayInit allocated for 'types arrayDecl EQ arrayElements'\n");
                                                            (yyval.arrayInit)->arrayType = stringToType((yyvsp[-3].string));
                                                            (yyval.arrayInit)->arrayDecl = (yyvsp[-2].arrayDecl);
                                                            (yyval.arrayInit)->elements = (yyvsp[0].arrayElements);
                                                            (yyval.arrayInit)->arrayDecl->arrayType = stringToType((yyvsp[-3].string));
                                                            printf("\n\t***Line: %d - Error: invalid initializer of '%s'***\n\n", yylineno,(yyvsp[-2].arrayDecl)->arrayName);
                                                            numberError++;
                                                        }
#line 1936 "parser.tab.c"
    break;

  case 48: /* arrayInit: types arrayDecl EQ LBRA arrayElements RBRA  */
#line 512 "parser.y"
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
                                                                printf("Number of elements in the array '%s'\n",ch);
                                                                (yyval.arrayInit)->arrayDecl->arrayLength = ch;
                                                                s = createSym((yyvsp[-4].arrayDecl)->arrayName, actualList, SYMBOL_ARRAY, (yyval.arrayInit)->arrayType, (yyval.arrayInit)->arrayType, NULL, NULL, (yyvsp[-4].arrayDecl)->arrayLength, nullValue);
                                                            } else {
                                                                printf("\n\t***Line: %d - Error: array '%s' already declared***\n\n", yylineno,(yyvsp[-4].arrayDecl)->arrayName);
                                                                numberError++;
                                                            }
                                                        }
#line 1966 "parser.tab.c"
    break;

  case 49: /* arrayAssign: arrayCall EQ LBRA RBRA  */
#line 539 "parser.y"
                                                        {
                                                            // myArray[] = {}; Syntax Error
                                                            // myArray[3] = {}; Syntax Error
                                                            (yyval.arrayAssign)=malloc(sizeof(struct AstNodeArrayAssign));
                                                            printf("AstNodeArrayAssign allocated for 'arrayCall EQ LBRA RBRA'\n");
                                                            (yyval.arrayAssign)->arrayCall = (yyvsp[-3].arrayCall);
                                                            printf("\n\t***Line: %d - Syntax Error***\n\n", yylineno);
                                                            numberError++;
                                                        }
#line 1980 "parser.tab.c"
    break;

  case 50: /* arrayAssign: arrayCall EQ arrayElements  */
#line 548 "parser.y"
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
                                                                printf("\n\t***Line: %d - Error: element index not specified***\n\n", yylineno);
                                                                numberError++;
                                                            }
                                                        }
#line 1999 "parser.tab.c"
    break;

  case 51: /* arrayAssign: arrayCall EQ LBRA arrayElements RBRA  */
#line 562 "parser.y"
                                                        {
                                                            //myArray[] = {24, 27, 29}; Syntax Error
                                                            //myArray[3] = {24, 27, 29}; Syntax Error
                                                            (yyval.arrayAssign)=malloc(sizeof(struct AstNodeArrayAssign));
                                                            printf("AstNodeArrayAssign allocated for 'arrayCall EQ LBRA arrayElements RBRA'\n");
                                                            (yyval.arrayAssign)->arrayType = (yyvsp[-1].arrayElements)->element->valueType;
                                                            (yyval.arrayAssign)->arrayCall = (yyvsp[-4].arrayCall);
                                                            (yyval.arrayAssign)->elements = (yyvsp[-1].arrayElements);
                                                            (yyval.arrayAssign)->arrayCall->arrayType = (yyvsp[-1].arrayElements)->element->valueType;
                                                            printf("\n\t***Line: %d - Syntax Error***\n\n", yylineno);
                                                            numberError++;
                                                        }
#line 2016 "parser.tab.c"
    break;

  case 52: /* arrayDecl: ID LSBRA RSBRA  */
#line 576 "parser.y"
                                                        {
                                                            (yyval.arrayDecl)=malloc(sizeof(struct AstNodeArrayDecl));
                                                            printf("AstNodeArrayDecl allocated for 'ID LSBRA RSBRA'\n");
                                                            (yyval.arrayDecl)->arrayName = (yyvsp[-2].string);
                                                            (yyval.arrayDecl)->arrayLength = NULL;
                                                        }
#line 2027 "parser.tab.c"
    break;

  case 53: /* arrayDecl: ID LSBRA INT_VALUE RSBRA  */
#line 582 "parser.y"
                                                        {
                                                            (yyval.arrayDecl)=malloc(sizeof(struct AstNodeArrayDecl));
                                                            printf("AstNodeArrayDecl allocated for 'ID LSBRA INT_VALUE RSBRA'\n");
                                                            (yyval.arrayDecl)->arrayName = (yyvsp[-3].string);
                                                            (yyval.arrayDecl)->arrayLength = (yyvsp[-1].string);
                                                        }
#line 2038 "parser.tab.c"
    break;

  case 54: /* arrayCall: ID LSBRA RSBRA  */
#line 590 "parser.y"
                                                        {
                                                            (yyval.arrayCall)=malloc(sizeof(struct AstNodeArrayCall));
                                                            printf("AstNodeArrayCall allocated for 'ID LSBRA RSBRA'\n");
                                                            (yyval.arrayCall)->arrayName = (yyvsp[-2].string);
                                                            (yyval.arrayCall)->elementIndex = NULL;
                                                        }
#line 2049 "parser.tab.c"
    break;

  case 55: /* arrayCall: ID LSBRA content RSBRA  */
#line 596 "parser.y"
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
                                                                numberError++;
                                                            }
                                                        }
#line 2070 "parser.tab.c"
    break;

  case 56: /* arrayElements: content  */
#line 614 "parser.y"
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
#line 2085 "parser.tab.c"
    break;

  case 57: /* arrayElements: content COMMA arrayElements  */
#line 624 "parser.y"
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
#line 2100 "parser.tab.c"
    break;

  case 58: /* outputFunction: PRINTF LPAR STRING_VALUE RPAR  */
#line 636 "parser.y"
                                                        {
                                                            (yyval.outputFunction) = malloc(sizeof(struct AstNodeFunctionOutput));
                                                            printf("AstNodeFunctionOutput allocated for 'PRINTF LPAR STRING_VALUE RPAR'\n");
                                                            (yyval.outputFunction)->string = (yyvsp[-1].string);
                                                            (yyval.outputFunction)->outputElements = NULL;
                                                        }
#line 2111 "parser.tab.c"
    break;

  case 59: /* outputFunction: PRINTF LPAR STRING_VALUE COMMA outputElements RPAR  */
#line 642 "parser.y"
                                                        {
                                                            (yyval.outputFunction) = malloc(sizeof(struct AstNodeFunctionOutput));
                                                            printf("AstNodeFunctionOutput allocated for 'PRINTF LPAR STRING_VALUE RPAR COMMA outputElements'\n");
                                                            (yyval.outputFunction)->string = (yyvsp[-3].string);
                                                            (yyval.outputFunction)->outputElements = (yyvsp[-1].outputElements);
                                                        }
#line 2122 "parser.tab.c"
    break;

  case 60: /* inputFunction: SCANF LPAR STRING_VALUE RPAR  */
#line 650 "parser.y"
                                                        {
                                                            (yyval.inputFunction) = malloc(sizeof(struct AstNodeFunctionInput));
                                                            printf("AstNodeFunctionInput allocated for 'SCANF LPAR STRING_VALUE RPAR'\n");
                                                            (yyval.inputFunction)->string = (yyvsp[-1].string);
                                                            (yyval.inputFunction)->inputElements = NULL;
                                                        }
#line 2133 "parser.tab.c"
    break;

  case 61: /* inputFunction: SCANF LPAR STRING_VALUE COMMA inputElements RPAR  */
#line 656 "parser.y"
                                                        {
                                                            (yyval.inputFunction) = malloc(sizeof(struct AstNodeFunctionInput));
                                                            printf("AstNodeFunctionInput allocated for 'SCANF LPAR STRING_VALUE RPAR COMMA inputElements'\n");
                                                            (yyval.inputFunction)->string = (yyvsp[-3].string);
                                                            (yyval.inputFunction)->inputElements = (yyvsp[-1].inputElements);
                                                        }
#line 2144 "parser.tab.c"
    break;

  case 62: /* outputElements: content  */
#line 664 "parser.y"
                                                        {
                                                            (yyval.outputElements) = malloc(sizeof(struct AstNodeOutputElements));
                                                            printf("AstNodeOutputElements allocated for 'content'\n");
                                                            (yyval.outputElements)->element = (yyvsp[0].operand);
                                                            (yyval.outputElements)->nextElement = NULL;
                                                        }
#line 2155 "parser.tab.c"
    break;

  case 63: /* outputElements: content COMMA outputElements  */
#line 670 "parser.y"
                                                        {
                                                            (yyval.outputElements) = malloc(sizeof(struct AstNodeOutputElements));
                                                            printf("AstNodeOutputElements allocated for 'content COMMA outputElements'\n");
                                                            (yyval.outputElements)->element = (yyvsp[-2].operand);
                                                            (yyval.outputElements)->nextElement = (yyvsp[0].outputElements);
                                                        }
#line 2166 "parser.tab.c"
    break;

  case 64: /* inputElements: REFOP content  */
#line 678 "parser.y"
                                                        {
                                                            (yyval.inputElements) = malloc(sizeof(struct AstNodeInputElements));
                                                            printf("AstNodeInputElements allocated for 'content'\n");
                                                            (yyval.inputElements)->element = (yyvsp[0].operand);
                                                            (yyval.inputElements)->nextElement = NULL;
                                                        }
#line 2177 "parser.tab.c"
    break;

  case 65: /* inputElements: REFOP content COMMA inputElements  */
#line 684 "parser.y"
                                                        {
                                                            (yyval.inputElements) = malloc(sizeof(struct AstNodeInputElements));
                                                            printf("AstNodeInputElements allocated for 'content COMMA inputElements'\n");
                                                            (yyval.inputElements)->element = (yyvsp[-2].operand);
                                                            (yyval.inputElements)->nextElement = (yyvsp[0].inputElements);
                                                        }
#line 2188 "parser.tab.c"
    break;

  case 66: /* initialization: types ID  */
#line 692 "parser.y"
                                                        {
                                                            (yyval.init) = malloc(sizeof(struct AstNodeInit));
                                                            printf("AstNodeInit allocated for 'types ID'\n");
                                                            (yyval.init)->variableName = (yyvsp[0].string);
                                                            (yyval.init)->dataType = stringToType((yyvsp[-1].string));
                                                        }
#line 2199 "parser.tab.c"
    break;

  case 67: /* assignment: types ID EQ content  */
#line 700 "parser.y"
                                                        {
                                                            struct SymTab *s = NULL;
                                                            s = findSym((yyvsp[-2].string), actualList);
                                                            if (s != NULL) {
                                                                printf("\n\t***Line: %d - Error: variable %s already declared***\n\n", yylineno,(yyvsp[-2].string));
                                                                numberError++;
                                                            } else if ((stringToType((yyvsp[-3].string)) != (yyvsp[0].operand)->valueType) || strcmp(typeToString((yyvsp[0].operand)->valueType), "Type none") == 0) {
                                                                printf("\n\t***Line: %d - Error: cannot assign type %s to type %s***\n\n", yylineno,typeToString((yyvsp[0].operand)->valueType), (yyvsp[-3].string));
                                                                numberError++;
                                                            } else if(stringToType((yyvsp[-3].string)) == DATA_TYPE_VOID) {
                                                                printf("\n\t***Line: %d - Error: cannot assign a variable of type void***\n\n", yylineno);
                                                                numberError++;
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
#line 2227 "parser.tab.c"
    break;

  case 68: /* assignment: ID EQ content  */
#line 723 "parser.y"
                                                        {
                                                            (yyval.assign) = malloc(sizeof(struct AstNodeAssign));
                                                            printf("AstNodeAssign allocated for 'ID EQ content'\n");
                                                            struct SymTab *s = NULL;
                                                            s = findSymtab((yyvsp[-2].string), actualList); 
                                                            if (s == NULL) {
                                                                printf("\n\t***Line: %d - Error: variable %s not declared***\n\n", yylineno,(yyvsp[-2].string));
                                                                numberError++;
                                                            } else {
                                                                if (s->dataType != (yyvsp[0].operand)->valueType) {
                                                                    printf("\n\t***Line: %d - Error: cannot asign type %s to type %s***\n\n", yylineno,typeToString((yyvsp[0].operand)->valueType), typeToString(s->dataType));
                                                                    numberError++;
                                                                } else {
                                                                    (yyval.assign)->variableName = (yyvsp[-2].string);
                                                                    (yyval.assign)->variableType = (yyvsp[0].operand)->valueType;
                                                                    (yyval.assign)->assignValue = (yyvsp[0].operand)->value;
                                                                    (yyval.assign)->assignType = (yyvsp[0].operand)->contentType;
                                                                }
                                                            }
                                                        }
#line 2252 "parser.tab.c"
    break;

  case 69: /* expression: content ADD content  */
#line 745 "parser.y"
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
                                                                numberError++;
                                                            } else if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_VOID || (yyvsp[0].operand)->valueType == DATA_TYPE_VOID) {
                                                                printf("\n\t***Line: %d - Error: cannot add variables of type void***\n\n", yylineno);
                                                                numberError++;
                                                            } else if ((yyvsp[-2].operand)->valueType != (yyvsp[0].operand)->valueType) {
                                                                printf("\n\t***Line: %d - Error: cannot add variables of different types***\n\n", yylineno);
                                                                numberError++;
                                                            } else {
                                                                printf("Expression of type Sum\n");
                                                            }
                                                        }
#line 2279 "parser.tab.c"
    break;

  case 70: /* expression: content SUB content  */
#line 767 "parser.y"
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
                                                                numberError++;
                                                            } else if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_VOID || (yyvsp[0].operand)->valueType == DATA_TYPE_VOID) {
                                                                printf("\n\t***Line: %d - Error: cannot subtract variables of type void***\n\n", yylineno);
                                                                numberError++;
                                                            } else if ((yyvsp[-2].operand)->valueType != (yyvsp[0].operand)->valueType) {
                                                                printf("\n\t***Line: %d - Error: cannot subtract variables of different types***\n\n", yylineno);
                                                                numberError++;
                                                            } else {
                                                                printf("Expression of type Subtraction\n");
                                                            }
                                                        }
#line 2306 "parser.tab.c"
    break;

  case 71: /* expression: content MUL content  */
#line 789 "parser.y"
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
                                                                numberError++;
                                                            } else if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_VOID || (yyvsp[0].operand)->valueType == DATA_TYPE_VOID) {
                                                                printf("\n\t***Line: %d - Error: cannot multiply variables of type void***\n\n", yylineno);
                                                                numberError++;
                                                            } else if ((yyvsp[-2].operand)->valueType != (yyvsp[0].operand)->valueType) {
                                                                printf("\n\t***Line: %d - Error: cannot multiply variables of different types***\n\n", yylineno);
                                                                numberError++;
                                                            } else {
                                                                printf("Expression of type Multiplication\n");
                                                            }
                                                        }
#line 2333 "parser.tab.c"
    break;

  case 72: /* expression: content DIV content  */
#line 811 "parser.y"
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
                                                                numberError++;
                                                            } else if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_VOID || (yyvsp[0].operand)->valueType == DATA_TYPE_VOID) {
                                                                printf("\n\t***Line: %d - Error: cannot divide variables of type void***\n\n", yylineno);
                                                                numberError++;
                                                            } else if ((yyvsp[-2].operand)->valueType != (yyvsp[0].operand)->valueType) {
                                                                printf("\n\t***Line: %d - Error: cannot divide variables of different types***\n\n", yylineno);
                                                                numberError++;
                                                            } else {
                                                                printf("Expression of type Division\n");
                                                            }
                                                        }
#line 2360 "parser.tab.c"
    break;

  case 73: /* expression: content EE content  */
#line 833 "parser.y"
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
#line 2376 "parser.tab.c"
    break;

  case 74: /* expression: content NE content  */
#line 844 "parser.y"
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
#line 2392 "parser.tab.c"
    break;

  case 75: /* expression: content GT content  */
#line 855 "parser.y"
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
                                                                numberError++;
                                                            } else if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_VOID || (yyvsp[0].operand)->valueType == DATA_TYPE_VOID) {
                                                                printf("\n\t***Line: %d - Error: cannot compare variables of type void***\n\n", yylineno);
                                                                numberError++;
                                                            } else {
                                                                printf("Expression of type Greater than\n");
                                                            }
                                                        }
#line 2416 "parser.tab.c"
    break;

  case 76: /* expression: content LT content  */
#line 874 "parser.y"
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
                                                                numberError++;
                                                            } else if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_VOID || (yyvsp[0].operand)->valueType == DATA_TYPE_VOID) {
                                                                printf("\n\t***Line: %d - Error: cannot compare variables of type void***\n\n", yylineno);
                                                                numberError++;
                                                            } else {
                                                                printf("Expression of type Less than\n");
                                                            }
                                                        }
#line 2440 "parser.tab.c"
    break;

  case 77: /* expression: content GE content  */
#line 893 "parser.y"
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
                                                                numberError++;
                                                            } else if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_VOID || (yyvsp[0].operand)->valueType == DATA_TYPE_VOID) {
                                                                printf("\n\t***Line: %d - Error: cannot compare variables of type void***\n\n", yylineno);
                                                                numberError++;
                                                            } else {
                                                                printf("Expression of type Greater than or equal to\n");
                                                            }
                                                        }
#line 2464 "parser.tab.c"
    break;

  case 78: /* expression: content LE content  */
#line 912 "parser.y"
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
                                                                numberError++;
                                                            } else if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_VOID || (yyvsp[0].operand)->valueType == DATA_TYPE_VOID) {
                                                                printf("\n\t***Line: %d - Error: cannot compare variables of type void***\n\n", yylineno);
                                                                numberError++;
                                                            } else {
                                                                printf("Expression of type Less than or equal to\n");
                                                            }
                                                        }
#line 2488 "parser.tab.c"
    break;

  case 79: /* expression: content AND content  */
#line 931 "parser.y"
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
                                                                numberError++;
                                                            } else if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_VOID || (yyvsp[0].operand)->valueType == DATA_TYPE_VOID) {
                                                                printf("\n\t***Line: %d - Error: cannot compare variables of type void***\n\n", yylineno);
                                                                numberError++;
                                                            } else {
                                                                printf("Expression of type AND\n");
                                                            }
                                                        }
#line 2512 "parser.tab.c"
    break;

  case 80: /* expression: content OR content  */
#line 950 "parser.y"
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
                                                                numberError++;
                                                            } else if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_VOID || (yyvsp[0].operand)->valueType == DATA_TYPE_VOID) {
                                                                printf("\n\t***Line: %d - Error: cannot compare variables of type void***\n\n", yylineno);
                                                                numberError++;
                                                            } else {
                                                                printf("Expression of type OR\n");
                                                            }
                                                        }
#line 2536 "parser.tab.c"
    break;

  case 81: /* expression: NOT content  */
#line 969 "parser.y"
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
                                                                numberError++;
                                                            } else if  ((yyvsp[0].operand)->valueType == DATA_TYPE_VOID) {
                                                                printf("\n\t***Line: %d - Error: cannot compare variables of type void***\n\n", yylineno);
                                                                numberError++;
                                                            } else {
                                                                printf("Expression of type NOT\n");
                                                            }
                                                        }
#line 2560 "parser.tab.c"
    break;

  case 82: /* content: ID  */
#line 990 "parser.y"
                                                        {
                                                            (yyval.operand) = malloc(sizeof(struct AstNodeOperand));
                                                            printf("AstNodeOperand allocated for 'ID'\n"); //Ci troviamo nel caso in cui abbiamo int a = b
                                                            struct SymTab *s = findSymtab((yyvsp[0].string),actualList);
                                                            if(s == NULL) {
                                                                printf("\n\t***Line: %d - Error: The variable %s does not exist***\n\n", yylineno,(yyvsp[0].string));
                                                                numberError++;
                                                            } else {
                                                                (yyval.operand)->value.val = (yyvsp[0].string);
                                                                (yyval.operand)->valueType = s->dataType;
                                                                (yyval.operand)->contentType = CONTENT_TYPE_ID;
                                                            }
                                                        }
#line 2578 "parser.tab.c"
    break;

  case 83: /* content: INT_VALUE  */
#line 1003 "parser.y"
                                                        {
                                                            (yyval.operand) = malloc(sizeof(struct AstNodeOperand));
                                                            printf("AstNodeOperand allocated for 'INT_VALUE'\n");
                                                            (yyval.operand)->value.val = (yyvsp[0].string);
                                                            (yyval.operand)->valueType = DATA_TYPE_INT;
                                                            (yyval.operand)->contentType = CONTENT_TYPE_INT_NUMBER;
                                                        }
#line 2590 "parser.tab.c"
    break;

  case 84: /* content: FLOAT_VALUE  */
#line 1010 "parser.y"
                                                        {
                                                            (yyval.operand) = malloc(sizeof(struct AstNodeOperand));
                                                            printf("AstNodeOperand allocated for 'FLOAT_VALUE'\n");
                                                            (yyval.operand)->value.val = (yyvsp[0].string);
                                                            (yyval.operand)->valueType = DATA_TYPE_FLOAT;
                                                            (yyval.operand)->contentType = CONTENT_TYPE_FLOAT_NUMBER;
                                                        }
#line 2602 "parser.tab.c"
    break;

  case 85: /* content: CHAR_VALUE  */
#line 1017 "parser.y"
                                                        {
                                                            (yyval.operand) = malloc(sizeof(struct AstNodeOperand));
                                                            printf("AstNodeOperand allocated for 'CHAR_VALUE'\n");
                                                            (yyval.operand)->value.val = (yyvsp[0].string);
                                                            (yyval.operand)->valueType = DATA_TYPE_CHAR;
                                                            (yyval.operand)->contentType = CONTENT_TYPE_CHAR;
                                                        }
#line 2614 "parser.tab.c"
    break;

  case 86: /* content: expression  */
#line 1024 "parser.y"
                                                        {
                                                            (yyval.operand) = malloc(sizeof(struct AstNodeOperand));
                                                            printf("AstNodeOperand allocated for 'expression'\n");
                                                            (yyval.operand)->value.expression = (yyvsp[0].expression);
                                                            (yyval.operand)->valueType = (yyvsp[0].expression)->exprType;
                                                            (yyval.operand)->contentType = CONTENT_TYPE_EXPRESSION;
                                                        }
#line 2626 "parser.tab.c"
    break;

  case 87: /* content: functionCall  */
#line 1031 "parser.y"
                                                        {
                                                            (yyval.operand) = malloc(sizeof(struct AstNodeOperand));
                                                            printf("AstNodeOperand allocated for 'functionCall'\n");
                                                            (yyval.operand)->value.funtionCall = (yyvsp[0].functionCall);
                                                            (yyval.operand)->valueType = (yyvsp[0].functionCall)->returnType;
                                                            (yyval.operand)->contentType = CONTENT_TYPE_FUNCTION;
                                                        }
#line 2638 "parser.tab.c"
    break;

  case 88: /* content: arrayCall  */
#line 1038 "parser.y"
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
#line 2653 "parser.tab.c"
    break;

  case 89: /* types: VOID  */
#line 1050 "parser.y"
                                                        {
                                                            printf("Defined 'type: VOID'\n");
                                                        }
#line 2661 "parser.tab.c"
    break;

  case 90: /* types: INT  */
#line 1053 "parser.y"
                                                        {
                                                            printf("Defined 'type: INT'\n");
                                                        }
#line 2669 "parser.tab.c"
    break;

  case 91: /* types: FLOAT  */
#line 1056 "parser.y"
                                                        {
                                                            printf("Defined 'type: FLOAT'\n");
                                                        }
#line 2677 "parser.tab.c"
    break;

  case 92: /* types: CHAR  */
#line 1059 "parser.y"
                                                        {
                                                            printf("Defined 'type: CHAR'\n");
                                                        }
#line 2685 "parser.tab.c"
    break;


#line 2689 "parser.tab.c"

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

#line 1063 "parser.y"


int main() {
    yyparse();
    nullValue.val = NULL;
    counter = 0;

    if(numberError == 0) {
        fptr = fopen("test.py", "w");
        translate(root);
        fclose(fptr);
        printf("Translation completed!\n");
    } else {
        printf("Translation failed with %d errors\n", numberError);
    }
    
    return 0;
}

int yyerror(char *s) {
    printf("\n\t***Line: %d - %s***\n\n", yylineno,s);
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
