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

FILE *fptr;

struct AstNodeStatements *root;
struct List *actualList = NULL;
char appoggio[100] = {};

char *typeToString(int);
int stringToType(char*);

void beginScope();
void endScope();


#line 99 "parser.tab.c"

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
  YYSYMBOL_functionCall = 51,              /* functionCall  */
  YYSYMBOL_functionParams = 52,            /* functionParams  */
  YYSYMBOL_body = 53,                      /* body  */
  YYSYMBOL_ifStatement = 54,               /* ifStatement  */
  YYSYMBOL_elseifStatement = 55,           /* elseifStatement  */
  YYSYMBOL_elseStatement = 56,             /* elseStatement  */
  YYSYMBOL_whileLoop = 57,                 /* whileLoop  */
  YYSYMBOL_arrayInit = 58,                 /* arrayInit  */
  YYSYMBOL_arrayAssign = 59,               /* arrayAssign  */
  YYSYMBOL_arrayDecl = 60,                 /* arrayDecl  */
  YYSYMBOL_arrayCall = 61,                 /* arrayCall  */
  YYSYMBOL_arrayElements = 62,             /* arrayElements  */
  YYSYMBOL_outputFunction = 63,            /* outputFunction  */
  YYSYMBOL_inputFunction = 64,             /* inputFunction  */
  YYSYMBOL_outputElements = 65,            /* outputElements  */
  YYSYMBOL_inputElements = 66,             /* inputElements  */
  YYSYMBOL_initialization = 67,            /* initialization  */
  YYSYMBOL_assignment = 68,                /* assignment  */
  YYSYMBOL_expression = 69,                /* expression  */
  YYSYMBOL_content = 70,                   /* content  */
  YYSYMBOL_types = 71                      /* types  */
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
#define YYLAST   358

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  168

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
       0,   102,   102,   102,   111,   118,   127,   133,   152,   158,
     164,   170,   176,   182,   188,   201,   218,   224,   232,   251,
     270,   271,   270,   303,   315,   341,   356,   363,   378,   387,
     393,   399,   407,   415,   423,   430,   438,   452,   462,   467,
     488,   493,   507,   514,   520,   528,   534,   545,   555,   567,
     573,   581,   587,   595,   601,   609,   615,   623,   638,   658,
     678,   697,   716,   735,   754,   765,   776,   793,   810,   827,
     844,   861,   878,   897,   910,   917,   924,   931,   938,   945,
     957,   960,   963,   966
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
  "statements", "instruction", "functionDecl", "$@2", "$@3",
  "functionCall", "functionParams", "body", "ifStatement",
  "elseifStatement", "elseStatement", "whileLoop", "arrayInit",
  "arrayAssign", "arrayDecl", "arrayCall", "arrayElements",
  "outputFunction", "inputFunction", "outputElements", "inputElements",
  "initialization", "assignment", "expression", "content", "types", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-70)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -70,    19,   130,   -70,   -70,   -70,   -70,   -70,     1,    -4,
      20,    40,    43,    62,   -70,   130,   -70,   -18,   -70,   -70,
     -70,   -70,    -9,    42,    73,    59,    71,   -13,    78,    -3,
     118,    92,    93,   -70,   118,    67,    81,   118,    79,   247,
     -70,   -70,   -70,   -70,   255,   -70,   -70,   132,   -70,   -70,
     135,    55,   159,   118,   -70,   -70,    17,   -70,   -70,   -70,
     149,   246,   118,   118,    -7,   151,   -12,    11,   -70,   246,
     -70,   165,   127,   141,   -70,   233,    86,   -70,   150,   163,
      50,   168,   118,     7,   263,   -70,   163,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   182,
     201,   118,   -70,   163,   -70,   118,   -70,   183,   -70,    50,
     177,   -70,   -70,   180,   118,   -70,   -70,   163,   246,   -70,
     197,   270,   -70,   -70,   295,   295,   305,   313,   320,   326,
     331,   104,   134,    84,   188,   -70,   163,   196,   217,   -70,
     215,   167,   118,   216,   -70,    50,   -70,   -70,   244,   -70,
     -70,   -70,   213,   -70,   -70,   242,   -70,   118,   184,   -70,
     -70,   163,   -70,   -70,   -70,   183,   -70,   -70
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,    80,    81,    82,    83,     0,     0,
       0,     0,     0,     0,     3,     5,     8,     0,    10,    11,
      12,    13,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    34,     0,     0,     0,     0,     0,     0,
       4,     9,    14,    15,     0,    16,    17,    20,     7,     6,
       0,    57,    36,     0,    74,    75,    73,    76,    78,    79,
      77,     0,     0,     0,     0,    77,     0,     0,    77,    59,
      23,     0,    26,     0,    45,     0,     0,    41,    47,     0,
       0,     0,     0,     0,     0,    72,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    77,
       0,     0,    29,     0,    49,     0,    51,     0,    24,     0,
      25,    46,    40,     0,     0,    19,    21,     0,    58,    43,
       0,     0,    38,    32,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,     0,     0,    35,
       0,    53,     0,     0,    28,     0,    42,    48,     0,    18,
      44,    37,     0,    33,    31,     0,    50,     0,    55,    52,
      27,     0,    39,    30,    54,     0,    22,    56
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -70,   -70,   -70,     6,   -70,   -70,   -70,   -70,    -1,   -69,
     -66,   -70,   -70,   -70,   -70,   -70,   -70,   -70,    10,   -41,
     -70,   -70,    74,   112,   -70,   -70,   -28,   -30,    13
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    14,    15,    16,    80,   148,    58,    71,
      33,    18,    19,    20,    21,    22,    23,    52,    59,    77,
      25,    26,   140,   143,    27,    28,    68,    78,    73
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      61,    17,    60,    31,    61,   101,    65,    69,    72,    75,
      50,   116,    24,   115,    17,    29,    47,    41,   104,     3,
     123,    40,    48,    85,   105,    24,    42,   102,    29,    32,
      30,    17,    61,   100,    99,   113,    51,   139,    64,   119,
     144,   106,    24,   122,   120,    29,    38,   107,    39,    34,
      72,   149,   118,     4,     5,     6,     7,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,    35,
     153,   138,    36,   147,    82,   141,   160,    43,    53,    72,
     152,    37,     4,     5,     6,     7,    83,    54,    55,    56,
      57,    38,    44,    39,    45,   166,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    63,    46,    53,    66,    70,
      97,    98,   158,    49,    53,    72,    54,    55,    56,    57,
     112,    62,    67,    54,    55,    56,    57,   141,    95,    96,
      97,    98,    13,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    87,    88,    89,    90,    53,    91,    92,    93,
      94,    95,    96,    97,    98,    54,    55,    56,    57,    96,
      97,    98,    79,   109,    81,    87,    88,    89,    90,    13,
      91,    92,    93,    94,    95,    96,    97,    98,    84,    86,
     110,   103,    87,    88,    89,    90,   114,    91,    92,    93,
      94,    95,    96,    97,    98,   108,    32,   142,   117,    87,
      88,    89,    90,   157,    91,    92,    93,    94,    95,    96,
      97,    98,   136,   145,   146,    98,    87,    88,    89,    90,
     165,    91,    92,    93,    94,    95,    96,    97,    98,   150,
     154,   164,    87,    88,    89,    90,   137,    91,    92,    93,
      94,    95,    96,    97,    98,   156,   159,   162,    87,    88,
      89,    90,   155,    91,    92,    93,    94,    95,    96,    97,
      98,    87,    88,    89,    90,   111,    91,    92,    93,    94,
      95,    96,    97,    98,   161,    53,   163,   167,     0,    74,
       0,     0,     0,    53,    54,    55,    56,    57,    76,     0,
       0,    53,    54,    55,    56,    57,   121,     0,    53,     0,
      54,    55,    56,    57,   151,     0,     0,    54,    55,    56,
      57,    88,    89,    90,     0,    91,    92,    93,    94,    95,
      96,    97,    98,    90,     0,    91,    92,    93,    94,    95,
      96,    97,    98,    91,    92,    93,    94,    95,    96,    97,
      98,    92,    93,    94,    95,    96,    97,    98,    93,    94,
      95,    96,    97,    98,    94,    95,    96,    97,    98
};

static const yytype_int16 yycheck[] =
{
      30,     2,    30,     7,    34,    12,    34,    37,    38,    39,
      13,    80,     2,    79,    15,     2,    29,    35,    30,     0,
      86,    15,    35,    53,    36,    15,    35,    34,    15,    33,
      29,    32,    62,    63,    62,    76,    39,   103,    32,    32,
     109,    30,    32,    84,    37,    32,    29,    36,    31,    29,
      80,   117,    82,     3,     4,     5,     6,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    29,
     136,   101,    29,   114,    19,   105,   145,    35,    28,   109,
     121,    19,     3,     4,     5,     6,    31,    37,    38,    39,
      40,    29,    19,    31,    35,   161,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    35,    28,    41,    30,
      26,    27,   142,    35,    28,   145,    37,    38,    39,    40,
      34,    29,    41,    37,    38,    39,    40,   157,    24,    25,
      26,    27,    39,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    15,    16,    17,    18,    28,    20,    21,    22,
      23,    24,    25,    26,    27,    37,    38,    39,    40,    25,
      26,    27,    30,    36,    29,    15,    16,    17,    18,    39,
      20,    21,    22,    23,    24,    25,    26,    27,    19,    30,
      39,    30,    15,    16,    17,    18,    36,    20,    21,    22,
      23,    24,    25,    26,    27,    30,    33,    14,    30,    15,
      16,    17,    18,    36,    20,    21,    22,    23,    24,    25,
      26,    27,    30,    36,    34,    27,    15,    16,    17,    18,
      36,    20,    21,    22,    23,    24,    25,    26,    27,    32,
      34,   157,    15,    16,    17,    18,    35,    20,    21,    22,
      23,    24,    25,    26,    27,    30,    30,    34,    15,    16,
      17,    18,    35,    20,    21,    22,    23,    24,    25,    26,
      27,    15,    16,    17,    18,    32,    20,    21,    22,    23,
      24,    25,    26,    27,    30,    28,    34,   165,    -1,    32,
      -1,    -1,    -1,    28,    37,    38,    39,    40,    33,    -1,
      -1,    28,    37,    38,    39,    40,    33,    -1,    28,    -1,
      37,    38,    39,    40,    34,    -1,    -1,    37,    38,    39,
      40,    16,    17,    18,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    18,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    20,    21,    22,    23,    24,    25,    26,
      27,    21,    22,    23,    24,    25,    26,    27,    22,    23,
      24,    25,    26,    27,    23,    24,    25,    26,    27
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    44,    45,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    39,    46,    47,    48,    51,    54,    55,
      56,    57,    58,    59,    61,    63,    64,    67,    68,    71,
      29,     7,    33,    53,    29,    29,    29,    19,    29,    31,
      46,    35,    35,    35,    19,    35,    35,    29,    35,    35,
      13,    39,    60,    28,    37,    38,    39,    40,    51,    61,
      69,    70,    29,    12,    46,    69,    41,    41,    69,    70,
      30,    52,    70,    71,    32,    70,    33,    62,    70,    30,
      49,    29,    19,    31,    19,    70,    30,    15,    16,    17,
      18,    20,    21,    22,    23,    24,    25,    26,    27,    69,
      70,    12,    34,    30,    30,    36,    30,    36,    30,    36,
      39,    32,    34,    62,    36,    53,    52,    30,    70,    32,
      37,    33,    62,    53,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    30,    35,    70,    53,
      65,    70,    14,    66,    52,    36,    34,    62,    50,    53,
      32,    34,    62,    53,    34,    35,    30,    36,    70,    30,
      52,    30,    34,    34,    65,    36,    53,    66
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    45,    44,    46,    46,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    48,    48,
      49,    50,    48,    51,    51,    52,    52,    52,    52,    53,
      53,    53,    54,    55,    56,    57,    58,    58,    58,    58,
      59,    59,    59,    60,    60,    61,    61,    62,    62,    63,
      63,    64,    64,    65,    65,    66,    66,    67,    68,    68,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    70,    70,    70,    70,    70,    70,    70,
      71,    71,    71,    71
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     2,     2,     1,     2,
       1,     1,     1,     1,     2,     2,     2,     2,     5,     4,
       0,     0,     7,     3,     4,     2,     1,     4,     3,     3,
       6,     5,     5,     6,     2,     5,     2,     5,     4,     6,
       4,     3,     5,     3,     4,     3,     4,     1,     3,     4,
       6,     4,     6,     1,     3,     2,     4,     2,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     1,     1,     1,     1,     1,     1,     1,
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
#line 102 "parser.y"
                                                        {
                                                            beginScope();
                                                        }
#line 1305 "parser.tab.c"
    break;

  case 3: /* program: $@1 statements  */
#line 105 "parser.y"
                                                        {
                                                            root = (yyvsp[0].statements);
                                                            endScope();
                                                        }
#line 1314 "parser.tab.c"
    break;

  case 4: /* statements: instruction statements  */
#line 111 "parser.y"
                                                        {
                                                            (yyval.statements) = malloc(sizeof(struct AstNodeStatements));
                                                            printf("AstNodeStatements allocated for 'instruction statements'\n");
                                                            (yyval.statements)->nodeType = STATEMENT_NODE;
                                                            (yyval.statements)->currentInstruction = (yyvsp[-1].instruction);
                                                            (yyval.statements)->nextStatement = (yyvsp[0].statements);
                                                        }
#line 1326 "parser.tab.c"
    break;

  case 5: /* statements: instruction  */
#line 118 "parser.y"
                                                        {
                                                            (yyval.statements) = malloc(sizeof(struct AstNodeStatements));
                                                            printf("AstNodeStatements allocated for 'instruction'\n");
                                                            (yyval.statements)->nodeType = STATEMENT_NODE;
                                                            (yyval.statements)->currentInstruction = (yyvsp[0].instruction);
                                                            (yyval.statements)->nextStatement = NULL;
                                                        }
#line 1338 "parser.tab.c"
    break;

  case 6: /* instruction: assignment SEMICOL  */
#line 127 "parser.y"
                                                        {
                                                            (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                            printf("AstNodeInstruction allocated for 'assignment SEMICOL'\n");
                                                            (yyval.instruction)->nodeType = ASSIGN_NODE;
                                                            (yyval.instruction)->value.assign = (yyvsp[-1].assign);
                                                        }
#line 1349 "parser.tab.c"
    break;

  case 7: /* instruction: initialization SEMICOL  */
#line 133 "parser.y"
                                                        {
                                                            (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                            struct SymTab *s = NULL;
                                                            //for (struct AstNodeInit *init = $1; init != NULL; init = init->nextInit) {
                                                                s = findSym((yyvsp[-1].init)->variableName, actualList);
                                                                if (s == NULL) {
                                                                    if((yyvsp[-1].init)->dataType == DATA_TYPE_VOID) {
                                                                        printf("You cannot initialize a variable of type void\n");
                                                                    } else {
                                                                        printf("AstNodeInstruction allocated for 'initialization SEMICOL'\n");
                                                                        (yyval.instruction)->nodeType = INIT_NODE;
                                                                        (yyval.instruction)->value.init = (yyvsp[-1].init);
                                                                        s = createSym((yyvsp[-1].init)->variableName, actualList, SYMBOL_VARIABLE, (yyvsp[-1].init)->dataType, (yyvsp[-1].init)->dataType, NULL, NULL, NULL, nullValue);
                                                                    }
                                                                } else {
                                                                    printf("Error: variable already declared.\n");
                                                                }
                                                            //}
                                                        }
#line 1373 "parser.tab.c"
    break;

  case 8: /* instruction: functionDecl  */
#line 152 "parser.y"
                                                        {
                                                            (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                            printf("AstNodeInstruction allocated for 'functionDecl SEMICOL'\n");
                                                            (yyval.instruction)->nodeType = FUNCTION_DECL_NODE;
                                                            (yyval.instruction)->value.functionDecl = (yyvsp[0].functionDecl);
                                                        }
#line 1384 "parser.tab.c"
    break;

  case 9: /* instruction: functionCall SEMICOL  */
#line 158 "parser.y"
                                                        {
                                                            (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                            printf("AstNodeInstruction allocated for 'functionCall SEMICOL'\n");
                                                            (yyval.instruction)->nodeType = FUNCTION_CALL_NODE;
                                                            (yyval.instruction)->value.functionCall = (yyvsp[-1].functionCall);
                                                        }
#line 1395 "parser.tab.c"
    break;

  case 10: /* instruction: ifStatement  */
#line 164 "parser.y"
                                                        {
                                                            (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                            printf("AstNodeInstruction allocated for 'ifStatement'\n");
                                                            (yyval.instruction)->nodeType = IF_NODE;
                                                            (yyval.instruction)->value.ifStatement = (yyvsp[0].ifStatement);
                                                        }
#line 1406 "parser.tab.c"
    break;

  case 11: /* instruction: elseifStatement  */
#line 170 "parser.y"
                                                        {
                                                            (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                            printf("AstNodeInstruction allocated for 'elseifStatement'\n");
                                                            (yyval.instruction)->nodeType = ELSE_IF_NODE;
                                                            (yyval.instruction)->value.elseifStatement = (yyvsp[0].elseifStatement);
                                                        }
#line 1417 "parser.tab.c"
    break;

  case 12: /* instruction: elseStatement  */
#line 176 "parser.y"
                                                        {
                                                            (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                            printf("AstNodeInstruction allocated for 'elseStatement'\n");
                                                            (yyval.instruction)->nodeType = ELSE_NODE;
                                                            (yyval.instruction)->value.elseStatement = (yyvsp[0].elseStatement);
                                                        }
#line 1428 "parser.tab.c"
    break;

  case 13: /* instruction: whileLoop  */
#line 182 "parser.y"
                                                        {
                                                            (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                            printf("AstNodeInstruction allocated for 'whileLoop'\n");
                                                            (yyval.instruction)->nodeType = WHILE_NODE;
                                                            (yyval.instruction)->value.whileLoop = (yyvsp[0].whileLoop);
                                                        }
#line 1439 "parser.tab.c"
    break;

  case 14: /* instruction: arrayInit SEMICOL  */
#line 188 "parser.y"
                                                        {
                                                            struct SymTab *s = findSym((yyvsp[-1].arrayInit)->arrayDecl->arrayName, actualList);
                                                            if (s == NULL) {
                                                                (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                                printf("AstNodeInstruction allocated for 'arrayInit'\n");
                                                                (yyval.instruction)->nodeType = ARRAY_INIT_NODE;
                                                                (yyval.instruction)->value.arrayInit = (yyvsp[-1].arrayInit);
                                                                s = createSym((yyvsp[-1].arrayInit)->arrayDecl->arrayName, actualList, SYMBOL_ARRAY, (yyvsp[-1].arrayInit)->arrayType, (yyvsp[-1].arrayInit)->arrayType, NULL, NULL, (yyvsp[-1].arrayInit)->arrayDecl->arrayLength, nullValue);
                                                                printf("Symbol created. symbolName %s\n",(yyvsp[-1].arrayInit)->arrayDecl->arrayName);
                                                            } else {
                                                                printf("Error: array %s already declared\n", (yyvsp[-1].arrayInit)->arrayDecl->arrayName);
                                                            }
                                                        }
#line 1457 "parser.tab.c"
    break;

  case 15: /* instruction: arrayAssign SEMICOL  */
#line 201 "parser.y"
                                                        {
                                                            struct SymTab *s = findSym((yyvsp[-1].arrayAssign)->arrayCall->arrayName, actualList);
                                                            if (s != NULL) {
                                                                if(s->dataType != (yyvsp[-1].arrayAssign)->arrayType) {
                                                                    printf("Error: Array %s has been declared as a %s but type %s is assigned.\n", (yyvsp[-1].arrayAssign)->arrayCall->arrayName, typeToString(s->dataType), typeToString((yyvsp[-1].arrayAssign)->arrayType));
                                                                } else if(atoi(s->arrayLength) <= atoi((yyvsp[-1].arrayAssign)->arrayCall->elementIndex->value.val)) {
                                                                    printf("OUT OF MEMORY: the length of %s is %s", s->symbolName, s->arrayLength);
                                                                }else {
                                                                    (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                                    printf("AstNodeInstruction allocated for 'arrayAssign'\n");
                                                                    (yyval.instruction)->nodeType = ARRAY_ASSIGN_NODE;
                                                                    (yyval.instruction)->value.arrayAssign = (yyvsp[-1].arrayAssign);
                                                                }
                                                            } else {
                                                                printf("Error: array %s not declared\n", (yyvsp[-1].arrayAssign)->arrayCall->arrayName);
                                                            }
                                                        }
#line 1479 "parser.tab.c"
    break;

  case 16: /* instruction: outputFunction SEMICOL  */
#line 218 "parser.y"
                                                        {
                                                            (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                            printf("AstNodeInstruction allocated for 'outputFunction SEMICOL'\n");
                                                            (yyval.instruction)->nodeType = OUTPUT_NODE;
                                                            (yyval.instruction)->value.outputFunction = (yyvsp[-1].outputFunction);
                                                        }
#line 1490 "parser.tab.c"
    break;

  case 17: /* instruction: inputFunction SEMICOL  */
#line 224 "parser.y"
                                                        {
                                                            (yyval.instruction) = malloc(sizeof(struct AstNodeInstruction));
                                                            printf("AstNodeInstruction allocated for 'inputFunction SEMICOL'\n");
                                                            (yyval.instruction)->nodeType = INPUT_NODE;
                                                            (yyval.instruction)->value.inputFunction = (yyvsp[-1].inputFunction);
                                                        }
#line 1501 "parser.tab.c"
    break;

  case 18: /* functionDecl: types MAIN LPAR RPAR body  */
#line 232 "parser.y"
                                                        {
                                                            struct SymTab *s = NULL;
                                                            char *main = "main";
                                                            s = findSymtab(main, actualList);
                                                            if (s == NULL) {
                                                                beginScope();
                                                                (yyval.functionDecl) = malloc(sizeof(struct AstNodeFunctionDecl));
                                                                printf("AstNodeFunctionDecl allocated for 'types MAIN LPAR RPAR body'\n");
                                                                (yyval.functionDecl)->functionName = (yyvsp[-3].string);
                                                                (yyval.functionDecl)->returnType = stringToType((yyvsp[-4].string));
                                                                (yyval.functionDecl)->functionParams = NULL;
                                                                (yyval.functionDecl)->functiontBody = (yyvsp[0].body);
                                                                endScope();
                                                                struct SymTab *s = createSym((yyval.functionDecl)->functionName, actualList, SYMBOL_FUNCTION, DATA_TYPE_NONE, (yyval.functionDecl)->returnType, (yyval.functionDecl)->functionName, NULL, NULL, nullValue);
                                                                printf("Funzione main inserita nella symtab \n");
                                                            } else {
                                                                printf("Error: function MAIN already declared \n");
                                                            } 
                                                        }
#line 1525 "parser.tab.c"
    break;

  case 19: /* functionDecl: initialization LPAR RPAR body  */
#line 251 "parser.y"
                                                        {
                                                            struct SymTab *s = NULL;
                                                            s = findSymtab((yyvsp[-3].init)->variableName, actualList);
                                                            if (s == NULL) { 
                                                                beginScope();
                                                                (yyval.functionDecl) = malloc(sizeof(struct AstNodeFunctionDecl));
                                                                printf("AstNodeFunctionDecl allocated for 'initialization LPAR RPAR body'\n");
                                                                (yyval.functionDecl)->functionName = (yyvsp[-3].init)->variableName;
                                                                (yyval.functionDecl)->returnType = (yyvsp[-3].init)->dataType;
                                                                printf("returnType assigned\n");
                                                                (yyval.functionDecl)->functionParams = NULL;
                                                                (yyval.functionDecl)->functiontBody = (yyvsp[0].body);
                                                                endScope();
                                                                struct SymTab *s = createSym((yyval.functionDecl)->functionName, actualList, SYMBOL_FUNCTION, DATA_TYPE_NONE, (yyval.functionDecl)->returnType, (yyval.functionDecl)->functionName, NULL, NULL, nullValue);
                                                                printf("Funzione inserita nella symtab \n");
                                                        } else {
                                                                printf("Error: function %s already declared \n",(yyvsp[-3].init)->variableName);
                                                            } 
                                                        }
#line 1549 "parser.tab.c"
    break;

  case 20: /* $@2: %empty  */
#line 270 "parser.y"
                                                        {   beginScope(); printf("scope aperto \n \n"); }
#line 1555 "parser.tab.c"
    break;

  case 21: /* $@3: %empty  */
#line 271 "parser.y"
                                                        {
                                                                for(int i=0; i<sizeof(appoggio);i++) {
                                                                    appoggio[i] = NULL;
                                                                }
                                                                for(struct AstNodeFunctionParams *p = (yyvsp[0].functionParams); p != NULL; p = p->nextParams) {
                                                                    printf("Sono entrato nel ciclo for \n \n");
                                                                    struct SymTab *s = createSym(p->initParam->variableName, actualList, SYMBOL_FUNCTION, p->initParam->dataType, DATA_TYPE_NONE, (yyvsp[-3].init)->variableName, NULL, NULL, nullValue);
                                                                    printf("Aggiunto parametro alla symbol table\n");
                                                                    strcat(appoggio,typeToString(p->initParam->dataType));
                                                                } 
                                                                printf("Appoggio alla fine vale: %s \n \n",appoggio);
                                                        }
#line 1572 "parser.tab.c"
    break;

  case 22: /* functionDecl: initialization LPAR $@2 functionParams $@3 RPAR body  */
#line 283 "parser.y"
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
                                                            } else {
                                                                printf("Error: function %s already declared \n",(yyvsp[-6].init)->variableName);
                                                            } 
                                                            endScope();
                                                            printf("Sto per entrare in symtab \n"); 
                                                            struct SymTab *q = createSym((yyval.functionDecl)->functionName, actualList, SYMBOL_FUNCTION, DATA_TYPE_NONE, (yyval.functionDecl)->returnType, (yyval.functionDecl)->functionName, appoggio, NULL, nullValue);
                                                            printf("Funzione inserita nella symtab \n");
                                                        }
#line 1595 "parser.tab.c"
    break;

  case 23: /* functionCall: ID LPAR RPAR  */
#line 303 "parser.y"
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
#line 1612 "parser.tab.c"
    break;

  case 24: /* functionCall: ID LPAR functionParams RPAR  */
#line 315 "parser.y"
                                                        {
                                                            (yyval.functionCall) = malloc(sizeof(struct AstNodeFunctionCall));
                                                            printf("AstNodeFunctionCall allocated for 'ID LPAR functionParams RPAR'\n");
                                                            char calledParameters[100] = {};
                                                            struct SymTab *s = findSymtab((yyvsp[-3].string), actualList);
                                                            if (s != NULL) {
                                                                for(struct AstNodeFunctionParams *q = (yyvsp[-1].functionParams); q != NULL; q = q->nextParams) {
                                                                    strcat(calledParameters,typeToString(q->callParams->valueType));
                                                                }
                                                                printf("Parameters of the declared function: %s \n", s->funcParameters);
                                                                printf("Parameters of the called function: %s \n", calledParameters);
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
                                                                printf("Error: function %s not declared\n", (yyvsp[-3].string));
                                                            }
                                                        }
#line 1641 "parser.tab.c"
    break;

  case 25: /* functionParams: types ID  */
#line 341 "parser.y"
                                                        {
                                                            (yyval.functionParams) = malloc(sizeof(struct AstNodeFunctionParams));
                                                            printf("AstNodeFunctionParams allocated for 'types ID'\n");
                                                            (yyval.functionParams)->nextParams = NULL;
                                                            (yyval.functionParams)->callParams = NULL;
                                                            (yyval.functionParams)->initParam = malloc(sizeof(struct AstNodeInit));
                                                            (yyval.functionParams)->initParam->dataType = stringToType((yyvsp[-1].string));
                                                            (yyval.functionParams)->initParam->variableName = (yyvsp[0].string);
                                                            //$$->initParam->nextInit = NULL;
                                                            //$$->initParam->assign = malloc(sizeof(struct AstNodeAssign));
                                                            //$$->initParam->assign->variableName = $2;
                                                            //$$->initParam->assign->variableType = stringToType($1);
                                                            //$$->initParam->assign->assignValue.val = NULL;
                                                            //$$->initParam->assign->assignType = CONTENT_TYPE_ID;
                                                        }
#line 1661 "parser.tab.c"
    break;

  case 26: /* functionParams: content  */
#line 356 "parser.y"
                                                        {
                                                            (yyval.functionParams) = malloc(sizeof(struct AstNodeFunctionParams));
                                                            printf("AstNodeFunctionParams allocated for 'content'\n");
                                                            (yyval.functionParams)->nextParams = NULL;
                                                            (yyval.functionParams)->callParams = (yyvsp[0].operand);
                                                            (yyval.functionParams)->initParam = NULL;
                                                        }
#line 1673 "parser.tab.c"
    break;

  case 27: /* functionParams: types ID COMMA functionParams  */
#line 363 "parser.y"
                                                        {
                                                            (yyval.functionParams) = malloc(sizeof(struct AstNodeFunctionParams));
                                                            printf("AstNodeFunctionParams allocated for 'types ID COMMA functionParams'\n");
                                                            (yyval.functionParams)->nextParams = (yyvsp[0].functionParams);
                                                            (yyval.functionParams)->callParams = NULL;
                                                            (yyval.functionParams)->initParam = malloc(sizeof(struct AstNodeInit));
                                                            (yyval.functionParams)->initParam->dataType = stringToType((yyvsp[-3].string));
                                                            (yyval.functionParams)->initParam->variableName = (yyvsp[-2].string);
                                                            //$$->initParam->nextInit = NULL;
                                                            //$$->initParam->assign = malloc(sizeof(struct AstNodeAssign));
                                                            //$$->initParam->assign->variableName = $2;
                                                            //$$->initParam->assign->variableType = stringToType($1);
                                                            //$$->initParam->assign->assignValue.val = NULL;
                                                            //$$->initParam->assign->assignType = CONTENT_TYPE_ID;
                                                        }
#line 1693 "parser.tab.c"
    break;

  case 28: /* functionParams: content COMMA functionParams  */
#line 378 "parser.y"
                                                        {
                                                            (yyval.functionParams) = malloc(sizeof(struct AstNodeFunctionParams));
                                                            printf("AstNodeFunctionParams allocated for 'content COMMA functionParams'\n");
                                                            (yyval.functionParams)->nextParams = (yyvsp[0].functionParams);
                                                            (yyval.functionParams)->callParams = (yyvsp[-2].operand);
                                                            (yyval.functionParams)->initParam = NULL;
                                                        }
#line 1705 "parser.tab.c"
    break;

  case 29: /* body: LBRA statements RBRA  */
#line 387 "parser.y"
                                                        {
                                                            (yyval.body) = malloc(sizeof(struct AstNodeBody));
                                                            printf("AstNodeBody allocated for 'LBRA statements RBRA'\n");
                                                            (yyval.body)->bodyStatements = (yyvsp[-1].statements);
                                                            (yyval.body)->returnValue = NULL;
                                                        }
#line 1716 "parser.tab.c"
    break;

  case 30: /* body: LBRA statements RETURN content SEMICOL RBRA  */
#line 393 "parser.y"
                                                        {
                                                            (yyval.body) = malloc(sizeof(struct AstNodeBody));
                                                            printf("AstNodeBody allocated for 'LBRA statements RETURN content SEMICOL RBRA'\n");
                                                            (yyval.body)->bodyStatements = (yyvsp[-4].statements);
                                                            (yyval.body)->returnValue = (yyvsp[-2].operand);
                                                        }
#line 1727 "parser.tab.c"
    break;

  case 31: /* body: LBRA RETURN content SEMICOL RBRA  */
#line 399 "parser.y"
                                                        {
                                                            (yyval.body)=malloc(sizeof(struct AstNodeBody));
                                                            printf("AstNodeBody allocated for 'LBRA RETURN content SEMICOL RBRA'\n");
                                                            (yyval.body)->bodyStatements = NULL;
                                                            (yyval.body)->returnValue = (yyvsp[-2].operand);
                                                            }
#line 1738 "parser.tab.c"
    break;

  case 32: /* ifStatement: IF LPAR expression RPAR body  */
#line 407 "parser.y"
                                                        {
                                                            (yyval.ifStatement) = malloc(sizeof(struct AstNodeIf));
                                                            printf("AstNodeIf allocated for 'IF LPAR expression RPAR body'\n");
                                                            (yyval.ifStatement)->ifCondition = (yyvsp[-2].expression);
                                                            (yyval.ifStatement)->ifBody = (yyvsp[0].body);
                                                        }
#line 1749 "parser.tab.c"
    break;

  case 33: /* elseifStatement: ELSE IF LPAR expression RPAR body  */
#line 415 "parser.y"
                                                        {
                                                            (yyval.elseifStatement) = malloc(sizeof(struct AstNodeElseIf));
                                                            printf("AstNodeElseIf allocated for 'ELSE IF LPAR expression RPAR body'\n");
                                                            (yyval.elseifStatement)->elseifCondition = (yyvsp[-2].expression);
                                                            (yyval.elseifStatement)->elseifBody = (yyvsp[0].body);
                                                        }
#line 1760 "parser.tab.c"
    break;

  case 34: /* elseStatement: ELSE body  */
#line 423 "parser.y"
                                                        {
                                                            (yyval.elseStatement) = malloc(sizeof(struct AstNodeElse));
                                                            printf("AstNodeElse allocated for 'ELSE body'\n");
                                                            (yyval.elseStatement)->elseBody = (yyvsp[0].body);
                                                        }
#line 1770 "parser.tab.c"
    break;

  case 35: /* whileLoop: WHILE LPAR expression RPAR body  */
#line 430 "parser.y"
                                                        {
                                                            (yyval.whileLoop) = malloc(sizeof(struct AstNodeWhile));
                                                            printf("AstNodeWhile allocated for 'WHILE LPAR expression RPAR body'\n");
                                                            (yyval.whileLoop)->whileCondition = (yyvsp[-2].expression);
                                                            (yyval.whileLoop)->whileBody = (yyvsp[0].body);
                                                        }
#line 1781 "parser.tab.c"
    break;

  case 36: /* arrayInit: types arrayDecl  */
#line 438 "parser.y"
                                                        {
                                                            //int myArray[]; Error: array size missing in ‘myArray’ !!!
                                                            //int myArray[3]; Corretct
                                                            if((yyvsp[0].arrayDecl)->arrayLength == NULL) {
                                                                printf("Error: array size missing in %s \n", (yyvsp[0].arrayDecl)->arrayName);
                                                            } else {
                                                                (yyval.arrayInit)=malloc(sizeof(struct AstNodeArrayInit));
                                                                printf("AstNodeArrayInit allocated for 'types arrayDecl'\n");
                                                                (yyval.arrayInit)->arrayType = stringToType((yyvsp[-1].string));
                                                                (yyval.arrayInit)->arrayDecl = (yyvsp[0].arrayDecl);
                                                                (yyval.arrayInit)->elements = NULL;
                                                                (yyval.arrayInit)->arrayDecl->arrayType = stringToType((yyvsp[-1].string));
                                                            }
                                                        }
#line 1800 "parser.tab.c"
    break;

  case 37: /* arrayInit: types arrayDecl EQ LBRA RBRA  */
#line 452 "parser.y"
                                                        {
                                                            //int myArray[] = {};
                                                            //int myArray[3] = {};
                                                            (yyval.arrayInit)=malloc(sizeof(struct AstNodeArrayInit));
                                                            printf("AstNodeArrayInit allocated for 'types arrayDecl EQ LBRA RBRA'\n");
                                                            (yyval.arrayInit)->arrayType = stringToType((yyvsp[-4].string));
                                                            (yyval.arrayInit)->arrayDecl = (yyvsp[-3].arrayDecl);
                                                            (yyval.arrayInit)->elements = NULL;
                                                            (yyval.arrayInit)->arrayDecl->arrayType = stringToType((yyvsp[-4].string));
                                                        }
#line 1815 "parser.tab.c"
    break;

  case 38: /* arrayInit: types arrayDecl EQ arrayElements  */
#line 462 "parser.y"
                                                        {
                                                            //int myArray[] = 24; Error: invalid initializer !!!
                                                            //int myArray[3] = 24; Error: invalid initializer !!!
                                                            printf("Error: invalid initializer of %s\n", (yyvsp[-2].arrayDecl)->arrayName);
                                                        }
#line 1825 "parser.tab.c"
    break;

  case 39: /* arrayInit: types arrayDecl EQ LBRA arrayElements RBRA  */
#line 467 "parser.y"
                                                        {
                                                            //int myArray[] = {24, 27, 29};
                                                            //int myArray[3] = {24, 27, 29};
                                                            (yyval.arrayInit)=malloc(sizeof(struct AstNodeArrayInit));
                                                            printf("AstNodeArrayInit allocated for 'types arrayDecl EQ LBRA arrayElements RBRA'\n");
                                                            (yyval.arrayInit)->arrayType = stringToType((yyvsp[-5].string));
                                                            (yyval.arrayInit)->arrayDecl = (yyvsp[-4].arrayDecl);
                                                            (yyval.arrayInit)->elements = (yyvsp[-1].arrayElements);
                                                            (yyval.arrayInit)->arrayDecl->arrayType = stringToType((yyvsp[-5].string));
                                                            int ele = 0;
                                                            for(struct AstNodeArrayElements *q = (yyvsp[-1].arrayElements); q != NULL; q = q->nextElement) {
                                                                    ele++;
                                                                    printf("Conto elemento %d del vettore \n",ele);
                                                                }
                                                            char ch[3];
                                                            sprintf(ch,"%d",ele);
                                                            printf("Numero elementi del vettore %s \n",ch);
                                                            (yyval.arrayInit)->arrayDecl->arrayLength = ch;
                                                        }
#line 1849 "parser.tab.c"
    break;

  case 40: /* arrayAssign: arrayCall EQ LBRA RBRA  */
#line 488 "parser.y"
                                                        {
                                                            // myArray[] = {}; Syntax Error
                                                            // myArray[3] = {}; Syntax Error
                                                            printf("Syntax Error!!!\n");
                                                        }
#line 1859 "parser.tab.c"
    break;

  case 41: /* arrayAssign: arrayCall EQ arrayElements  */
#line 493 "parser.y"
                                                        {
                                                            // myArray[] = 24; Synrtax Error
                                                            // myArray[2] = 24; Corret
                                                            if((yyvsp[-2].arrayCall)->elementIndex == NULL) {
                                                                printf("Syntax Error!!!\n");
                                                            } else {
                                                                (yyval.arrayAssign)=malloc(sizeof(struct AstNodeArrayAssign));
                                                                printf("AstNodeArrayAssign allocated for 'arrayCall EQ arrayElements'\n");
                                                                (yyval.arrayAssign)->arrayType = (yyvsp[0].arrayElements)->element->valueType;
                                                                (yyval.arrayAssign)->arrayCall = (yyvsp[-2].arrayCall);
                                                                (yyval.arrayAssign)->elements = (yyvsp[0].arrayElements);
                                                                (yyval.arrayAssign)->arrayCall->arrayType = (yyvsp[0].arrayElements)->element->valueType;
                                                            }
                                                        }
#line 1878 "parser.tab.c"
    break;

  case 42: /* arrayAssign: arrayCall EQ LBRA arrayElements RBRA  */
#line 507 "parser.y"
                                                        {
                                                            //myArray[] = {24, 27, 29}; Syntax Error
                                                            //myArray[3] = {24, 27, 29}; Syntax Error
                                                            printf("Syntax Error!!!\n");
                                                        }
#line 1888 "parser.tab.c"
    break;

  case 43: /* arrayDecl: ID LSBRA RSBRA  */
#line 514 "parser.y"
                                                        {
                                                            (yyval.arrayDecl)=malloc(sizeof(struct AstNodeArrayDecl));
                                                            printf("AstNodeArrayDecl allocated for 'ID LSBRA RSBRA'\n");
                                                            (yyval.arrayDecl)->arrayName = (yyvsp[-2].string);
                                                            (yyval.arrayDecl)->arrayLength = NULL;
                                                        }
#line 1899 "parser.tab.c"
    break;

  case 44: /* arrayDecl: ID LSBRA INT_VALUE RSBRA  */
#line 520 "parser.y"
                                                        {
                                                            (yyval.arrayDecl)=malloc(sizeof(struct AstNodeArrayDecl));
                                                            printf("AstNodeArrayDecl allocated for 'ID LSBRA INT_VALUE RSBRA'\n");
                                                            (yyval.arrayDecl)->arrayName = (yyvsp[-3].string);
                                                            (yyval.arrayDecl)->arrayLength = (yyvsp[-1].string);
                                                        }
#line 1910 "parser.tab.c"
    break;

  case 45: /* arrayCall: ID LSBRA RSBRA  */
#line 528 "parser.y"
                                                        {
                                                            (yyval.arrayCall)=malloc(sizeof(struct AstNodeArrayCall));
                                                            printf("AstNodeArrayCall allocated for 'ID LSBRA RSBRA'\n");
                                                            (yyval.arrayCall)->arrayName = (yyvsp[-2].string);
                                                            (yyval.arrayCall)->elementIndex = NULL;
                                                        }
#line 1921 "parser.tab.c"
    break;

  case 46: /* arrayCall: ID LSBRA content RSBRA  */
#line 534 "parser.y"
                                                        {
                                                            (yyval.arrayCall)=malloc(sizeof(struct AstNodeArrayCall));
                                                            printf("AstNodeArrayCall allocated for 'ID LSBRA content RSBRA'\n");
                                                            (yyval.arrayCall)->arrayName = (yyvsp[-3].string);
                                                            (yyval.arrayCall)->elementIndex = (yyvsp[-1].operand);
                                                            if((yyval.arrayCall)->elementIndex->contentType != CONTENT_TYPE_ID || (yyval.arrayCall)->elementIndex->contentType != CONTENT_TYPE_INT_NUMBER) {
                                                                printf("Error: invalid array index type \n");
                                                            }
                                                        }
#line 1935 "parser.tab.c"
    break;

  case 47: /* arrayElements: content  */
#line 545 "parser.y"
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
#line 1950 "parser.tab.c"
    break;

  case 48: /* arrayElements: content COMMA arrayElements  */
#line 555 "parser.y"
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
#line 1965 "parser.tab.c"
    break;

  case 49: /* outputFunction: PRINTF LPAR STRING_VALUE RPAR  */
#line 567 "parser.y"
                                                        {
                                                            (yyval.outputFunction) = malloc(sizeof(struct AstNodeFunctionOutput));
                                                            printf("AstNodeFunctionOutput allocated for 'PRINTF LPAR STRING_VALUE RPAR'\n");
                                                            (yyval.outputFunction)->string = (yyvsp[-1].string);
                                                            (yyval.outputFunction)->outputElements = NULL;
                                                        }
#line 1976 "parser.tab.c"
    break;

  case 50: /* outputFunction: PRINTF LPAR STRING_VALUE COMMA outputElements RPAR  */
#line 573 "parser.y"
                                                        {
                                                            (yyval.outputFunction) = malloc(sizeof(struct AstNodeFunctionOutput));
                                                            printf("AstNodeFunctionOutput allocated for 'PRINTF LPAR STRING_VALUE RPAR COMMA outputElements'\n");
                                                            (yyval.outputFunction)->string = (yyvsp[-3].string);
                                                            (yyval.outputFunction)->outputElements = (yyvsp[-1].outputElements);
                                                        }
#line 1987 "parser.tab.c"
    break;

  case 51: /* inputFunction: SCANF LPAR STRING_VALUE RPAR  */
#line 581 "parser.y"
                                                        {
                                                            (yyval.inputFunction) = malloc(sizeof(struct AstNodeFunctionInput));
                                                            printf("AstNodeFunctionInput allocated for 'SCANF LPAR STRING_VALUE RPAR'\n");
                                                            (yyval.inputFunction)->string = (yyvsp[-1].string);
                                                            (yyval.inputFunction)->inputElements = NULL;
                                                        }
#line 1998 "parser.tab.c"
    break;

  case 52: /* inputFunction: SCANF LPAR STRING_VALUE COMMA inputElements RPAR  */
#line 587 "parser.y"
                                                        {
                                                            (yyval.inputFunction) = malloc(sizeof(struct AstNodeFunctionInput));
                                                            printf("AstNodeFunctionInput allocated for 'SCANF LPAR STRING_VALUE RPAR COMMA inputElements'\n");
                                                            (yyval.inputFunction)->string = (yyvsp[-3].string);
                                                            (yyval.inputFunction)->inputElements = (yyvsp[-1].inputElements);
                                                        }
#line 2009 "parser.tab.c"
    break;

  case 53: /* outputElements: content  */
#line 595 "parser.y"
                                                        {
                                                            (yyval.outputElements) = malloc(sizeof(struct AstNodeOutputElements));
                                                            printf("AstNodeOutputElements allocated for 'content'\n");
                                                            (yyval.outputElements)->element = (yyvsp[0].operand);
                                                            (yyval.outputElements)->nextElement = NULL;
                                                        }
#line 2020 "parser.tab.c"
    break;

  case 54: /* outputElements: content COMMA outputElements  */
#line 601 "parser.y"
                                                        {
                                                            (yyval.outputElements) = malloc(sizeof(struct AstNodeOutputElements));
                                                            printf("AstNodeOutputElements allocated for 'content COMMA outputElements'\n");
                                                            (yyval.outputElements)->element = (yyvsp[-2].operand);
                                                            (yyval.outputElements)->nextElement = (yyvsp[0].outputElements);
                                                        }
#line 2031 "parser.tab.c"
    break;

  case 55: /* inputElements: REFOP content  */
#line 609 "parser.y"
                                                              {
                                                            (yyval.inputElements) = malloc(sizeof(struct AstNodeInputElements));
                                                            printf("AstNodeInputElements allocated for 'content'\n");
                                                            (yyval.inputElements)->element = (yyvsp[0].operand);
                                                            (yyval.inputElements)->nextElement = NULL;
                                                        }
#line 2042 "parser.tab.c"
    break;

  case 56: /* inputElements: REFOP content COMMA inputElements  */
#line 615 "parser.y"
                                                              {
                                                            (yyval.inputElements) = malloc(sizeof(struct AstNodeInputElements));
                                                            printf("AstNodeInputElements allocated for 'content COMMA inputElements'\n");
                                                            (yyval.inputElements)->element = (yyvsp[-2].operand);
                                                            (yyval.inputElements)->nextElement = (yyvsp[0].inputElements);
                                                        }
#line 2053 "parser.tab.c"
    break;

  case 57: /* initialization: types ID  */
#line 623 "parser.y"
                                                        {
                                                            (yyval.init) = malloc(sizeof(struct AstNodeInit));
                                                            printf("AstNodeInit allocated for 'types ID'\n");
                                                            (yyval.init)->variableName = (yyvsp[0].string);
                                                            (yyval.init)->dataType = stringToType((yyvsp[-1].string));
                                                            /* $$->nextInit = NULL;
                                                            $$->assign = malloc(sizeof(struct AstNodeAssign));
                                                            printf("AstNodeAssign allocated for 'types ID'\n");
                                                            $$->assign->variableName = $2;
                                                            $$->assign->variableType = stringToType($1);
                                                            $$->assign->assignValue.val = NULL;
                                                            $$->assign->assignType = CONTENT_TYPE_ID; */
                                                        }
#line 2071 "parser.tab.c"
    break;

  case 58: /* assignment: types ID EQ content  */
#line 638 "parser.y"
                                                        {
                                                            struct SymTab *s = NULL;  //sarà diverso da NULL solo se trova il simbolo
                                                            s = findSym((yyvsp[-2].string), actualList);  //controlla se il simbolo è stato già dichiarato
                                                            if (s != NULL) {
                                                                printf("Error: variable %s already declared\n", (yyvsp[-2].string));
                                                            } else if ((stringToType((yyvsp[-3].string)) != (yyvsp[0].operand)->valueType) || strcmp(typeToString((yyvsp[0].operand)->valueType), "Type none") == 0) {
                                                                printf("Error: Cannot assign type %s to type %s \n", typeToString((yyvsp[0].operand)->valueType), (yyvsp[-3].string));
                                                            } else if(stringToType((yyvsp[-3].string)) == DATA_TYPE_VOID) {
                                                                printf("You cannot assign a variable of type void\n");
                                                            } else
                                                                s = createSym((yyvsp[-2].string), actualList, SYMBOL_VARIABLE, stringToType((yyvsp[-3].string)), stringToType((yyvsp[-3].string)), NULL, NULL, NULL, (yyvsp[0].operand)->value);
                                                                printf("'types ID EQ content': the variable %s has not already been declared and then I create the symbol table for this variable\n", (yyvsp[-2].string));
                                                                (yyval.assign) = malloc(sizeof(struct AstNodeAssign));
                                                                printf("AstNodeAssign allocated for 'types ID EQ content'\n");
                                                                (yyval.assign)->variableName = (yyvsp[-2].string);
                                                                (yyval.assign)->variableType = stringToType((yyvsp[-3].string));
                                                                (yyval.assign)->assignValue = (yyvsp[0].operand)->value;
                                                                (yyval.assign)->assignType = (yyvsp[0].operand)->contentType;
                                                        }
#line 2095 "parser.tab.c"
    break;

  case 59: /* assignment: ID EQ content  */
#line 658 "parser.y"
                                                        {
                                                            (yyval.assign) = malloc(sizeof(struct AstNodeAssign)); //inserire qui la verifica che int a sia stato dichiarato prima di fare a = qualcosa
                                                            printf("AstNodeAssign allocated for 'ID EQ content'\n");
                                                            struct SymTab *s = NULL;
                                                            s = findSym((yyvsp[-2].string), actualList); 
                                                            if (s == NULL) {
                                                                printf("Error: variable %s not declared\n", (yyvsp[-2].string));
                                                            } else {
                                                                if (s->dataType != (yyvsp[0].operand)->valueType) {
                                                                    printf("Error: cannot asign type %s to type %s \n", typeToString((yyvsp[0].operand)->valueType), typeToString(s->dataType));
                                                                } else {
                                                            (yyval.assign)->variableName = (yyvsp[-2].string);
                                                            (yyval.assign)->variableType = (yyvsp[0].operand)->valueType;
                                                            (yyval.assign)->assignValue = (yyvsp[0].operand)->value;   //forse va- assignValue.val ma fors no perche- anche $3 e' generico
                                                            (yyval.assign)->assignType = (yyvsp[0].operand)->contentType;
                                                                }
                                                            }
                                                        }
#line 2118 "parser.tab.c"
    break;

  case 60: /* expression: content ADD content  */
#line 678 "parser.y"
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
                                                                printf("Error: cannot add variables of type char\n");
                                                            } else if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_VOID || (yyvsp[0].operand)->valueType == DATA_TYPE_VOID) {
                                                                printf("Error: cannot add variables of type void\n");
                                                            } else if ((yyvsp[-2].operand)->valueType != (yyvsp[0].operand)->valueType) {
                                                                printf("Error: cannot add variables of different types\n");
                                                            } else {
                                                                printf("Expression of type Sum\n");
                                                            }
                                                        }
#line 2142 "parser.tab.c"
    break;

  case 61: /* expression: content SUB content  */
#line 697 "parser.y"
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
                                                                printf("Error: cannot subtract variables of type char\n");
                                                            } else if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_VOID || (yyvsp[0].operand)->valueType == DATA_TYPE_VOID) {
                                                                printf("Error: cannot subtract variables of type void\n");
                                                            } else if ((yyvsp[-2].operand)->valueType != (yyvsp[0].operand)->valueType) {
                                                                printf("Error: cannot subtract variables of different types\n");
                                                            } else {
                                                                printf("Expression of type Subtraction\n");
                                                            }
                                                        }
#line 2166 "parser.tab.c"
    break;

  case 62: /* expression: content MUL content  */
#line 716 "parser.y"
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
                                                                printf("Error: cannot multiply variables of type char\n");
                                                            } else if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_VOID || (yyvsp[0].operand)->valueType == DATA_TYPE_VOID) {
                                                                printf("Error: cannot multiply variables of type void\n");
                                                            } else if ((yyvsp[-2].operand)->valueType != (yyvsp[0].operand)->valueType) {
                                                                printf("Error: cannot multiply variables of different types\n");
                                                            } else {
                                                                printf("Expression of type Multiplication\n");
                                                            }
                                                        }
#line 2190 "parser.tab.c"
    break;

  case 63: /* expression: content DIV content  */
#line 735 "parser.y"
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
                                                                printf("Error: cannot divide variables of type char\n");
                                                            } else if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_VOID || (yyvsp[0].operand)->valueType == DATA_TYPE_VOID) {
                                                                printf("Error: cannot divide variables of type void\n");
                                                            } else if ((yyvsp[-2].operand)->valueType != (yyvsp[0].operand)->valueType) {
                                                                printf("Error: cannot divide variables of different types\n");
                                                            } else {
                                                                printf("Expression of type Division\n");
                                                            }
                                                        }
#line 2214 "parser.tab.c"
    break;

  case 64: /* expression: content EE content  */
#line 754 "parser.y"
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
#line 2230 "parser.tab.c"
    break;

  case 65: /* expression: content NE content  */
#line 765 "parser.y"
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
#line 2246 "parser.tab.c"
    break;

  case 66: /* expression: content GT content  */
#line 776 "parser.y"
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
                                                                printf("Error: cannot compare variables of type char\n");
                                                            } else if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_VOID || (yyvsp[0].operand)->valueType == DATA_TYPE_VOID) {
                                                                printf("Error: cannot compare variables of type void\n");
                                                            } else {
                                                                printf("Expression of type Greater than\n");
                                                            }
                                                        }
#line 2268 "parser.tab.c"
    break;

  case 67: /* expression: content LT content  */
#line 793 "parser.y"
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
                                                                printf("Error: cannot compare variables of type char\n");
                                                            } else if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_VOID || (yyvsp[0].operand)->valueType == DATA_TYPE_VOID) {
                                                                printf("Error: cannot compare variables of type void\n");
                                                            } else {
                                                                printf("Expression of type Less than\n");
                                                            }
                                                        }
#line 2290 "parser.tab.c"
    break;

  case 68: /* expression: content GE content  */
#line 810 "parser.y"
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
                                                                printf("Error: cannot compare variables of type char\n");
                                                            } else if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_VOID || (yyvsp[0].operand)->valueType == DATA_TYPE_VOID) {
                                                                printf("Error: cannot compare variables of type void\n");
                                                            } else {
                                                                printf("Expression of type Greater than or equal to\n");
                                                            }
                                                        }
#line 2312 "parser.tab.c"
    break;

  case 69: /* expression: content LE content  */
#line 827 "parser.y"
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
                                                                printf("Error: cannot compare variables of type char\n");
                                                            } else if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_VOID || (yyvsp[0].operand)->valueType == DATA_TYPE_VOID) {
                                                                printf("Error: cannot compare variables of type void\n");
                                                            } else {
                                                                printf("Expression of type Less than or equal to\n");
                                                            }
                                                        }
#line 2334 "parser.tab.c"
    break;

  case 70: /* expression: content AND content  */
#line 844 "parser.y"
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
                                                                printf("Error: cannot compare variables of type char\n");
                                                            } else if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_VOID || (yyvsp[0].operand)->valueType == DATA_TYPE_VOID) {
                                                                printf("Error: cannot compare variables of type void\n");
                                                            } else {
                                                                printf("Expression of type AND\n");
                                                            }
                                                        }
#line 2356 "parser.tab.c"
    break;

  case 71: /* expression: content OR content  */
#line 861 "parser.y"
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
                                                                printf("Error: cannot compare variables of type char\n");
                                                            } else if  ((yyvsp[-2].operand)->valueType == DATA_TYPE_VOID || (yyvsp[0].operand)->valueType == DATA_TYPE_VOID) {
                                                                printf("Error: cannot compare variables of type void\n");
                                                            } else {
                                                                printf("Expression of type OR\n");
                                                            }
                                                        }
#line 2378 "parser.tab.c"
    break;

  case 72: /* expression: NOT content  */
#line 878 "parser.y"
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
                                                                printf("Error: cannot compare variables of type char\n");
                                                            } else if  ((yyvsp[0].operand)->valueType == DATA_TYPE_VOID) {
                                                                printf("Error: cannot compare variables of type void\n");
                                                            } else {
                                                                printf("Expression of type NOT \n");
                                                            }
                                                        }
#line 2400 "parser.tab.c"
    break;

  case 73: /* content: ID  */
#line 897 "parser.y"
                                                        {
                                                            (yyval.operand) = malloc(sizeof(struct AstNodeOperand));
                                                            printf("AstNodeOperand allocated for 'ID'\n"); //Ci troviamo nel caso in cui abbiamo int a = b
                                                            struct SymTab *s = findSymtab((yyvsp[0].string),actualList);
                                                            if(s == NULL) {
                                                                //TODO print error because ID does not exist
                                                                (yyval.operand)->valueType = DATA_TYPE_NONE;
                                                            } else {
                                                                (yyval.operand)->value.val = (yyvsp[0].string);
                                                                (yyval.operand)->valueType = s->dataType;
                                                                (yyval.operand)->contentType = CONTENT_TYPE_ID;
                                                            }
                                                        }
#line 2418 "parser.tab.c"
    break;

  case 74: /* content: INT_VALUE  */
#line 910 "parser.y"
                                                        {
                                                            (yyval.operand) = malloc(sizeof(struct AstNodeOperand));
                                                            printf("AstNodeOperand allocated for 'INT_VALUE'\n");
                                                            (yyval.operand)->value.val = (yyvsp[0].string);
                                                            (yyval.operand)->valueType = DATA_TYPE_INT;
                                                            (yyval.operand)->contentType = CONTENT_TYPE_INT_NUMBER;
                                                        }
#line 2430 "parser.tab.c"
    break;

  case 75: /* content: FLOAT_VALUE  */
#line 917 "parser.y"
                                                        {
                                                            (yyval.operand) = malloc(sizeof(struct AstNodeOperand));
                                                            printf("AstNodeOperand allocated for 'FLOAT_VALUE'\n");
                                                            (yyval.operand)->value.val = (yyvsp[0].string);
                                                            (yyval.operand)->valueType = DATA_TYPE_FLOAT;
                                                            (yyval.operand)->contentType = CONTENT_TYPE_FLOAT_NUMBER;
                                                        }
#line 2442 "parser.tab.c"
    break;

  case 76: /* content: CHAR_VALUE  */
#line 924 "parser.y"
                                                        {
                                                            (yyval.operand) = malloc(sizeof(struct AstNodeOperand));
                                                            printf("AstNodeOperand allocated for 'CHAR_VALUE'\n");
                                                            (yyval.operand)->value.val = (yyvsp[0].string);
                                                            (yyval.operand)->valueType = DATA_TYPE_CHAR;
                                                            (yyval.operand)->contentType = CONTENT_TYPE_CHAR;
                                                        }
#line 2454 "parser.tab.c"
    break;

  case 77: /* content: expression  */
#line 931 "parser.y"
                                                        {
                                                            (yyval.operand) = malloc(sizeof(struct AstNodeOperand));
                                                            printf("AstNodeOperand allocated for 'expression'\n");
                                                            (yyval.operand)->value.expression = (yyvsp[0].expression);
                                                            (yyval.operand)->valueType = (yyvsp[0].expression)->exprType;
                                                            (yyval.operand)->contentType = CONTENT_TYPE_EXPRESSION;
                                                        }
#line 2466 "parser.tab.c"
    break;

  case 78: /* content: functionCall  */
#line 938 "parser.y"
                                                        {
                                                            (yyval.operand) = malloc(sizeof(struct AstNodeOperand));
                                                            printf("AstNodeOperand allocated for 'functionCall'\n");
                                                            (yyval.operand)->value.funtionCall = (yyvsp[0].functionCall);
                                                            (yyval.operand)->valueType = (yyvsp[0].functionCall)->returnType;
                                                            (yyval.operand)->contentType = CONTENT_TYPE_FUNCTION;
                                                        }
#line 2478 "parser.tab.c"
    break;

  case 79: /* content: arrayCall  */
#line 945 "parser.y"
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
#line 2493 "parser.tab.c"
    break;

  case 80: /* types: VOID  */
#line 957 "parser.y"
                                                        {
                                                            printf("Defined 'type: VOID'\n");
                                                        }
#line 2501 "parser.tab.c"
    break;

  case 81: /* types: INT  */
#line 960 "parser.y"
                                                        {
                                                            printf("Defined 'type: INT'\n");
                                                        }
#line 2509 "parser.tab.c"
    break;

  case 82: /* types: FLOAT  */
#line 963 "parser.y"
                                                        {
                                                            printf("Defined 'type: FLOAT'\n");
                                                        }
#line 2517 "parser.tab.c"
    break;

  case 83: /* types: CHAR  */
#line 966 "parser.y"
                                                        {
                                                            printf("Defined 'type: CHAR'\n");
                                                        }
#line 2525 "parser.tab.c"
    break;


#line 2529 "parser.tab.c"

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

#line 970 "parser.y"


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
    printf("%s\n", s);
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

/* int compareStrings(char *one, char *two) {
    while (*one == *two) {
    printf("Le stringhe sono uguali \n");
    if ( *one == '\0' || *two == '\0' ) {
        printf("Nooooo "); break;
    }
    one++; two++; 
    }
    if( *one == '\0' && *two == '\0' )
    printf("Le stringhe sono le stesse \n");
    else
    printf("Le stringhe non sono affatto le stesse \n");
} */

