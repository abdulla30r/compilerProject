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
#line 2 "bisonFile.y"

#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include<math.h>
int yyerror(char *s);
extern int yylex();
extern int yyparse();
extern FILE *yyin;
extern FILE *yyout;
extern int yylineno;
void yyexit(const char *message);

#define MAX_SYMBOLS 100

int funcVarCount = 0;

char *myArray[] = {"purno", "vogno","shobdo","if", "else", "addHeader", "func","loop","shuru","sesh","inc","dec","eval","show","tan","log","log10","pow","cos","sin","ceil","floor","gcd","len","compare","copy","concat"};
int isKeyword(const char *target) {
    int size = sizeof(myArray) / sizeof(myArray[0]);
    for (int i = 0; i < size; ++i) {
        if (strcmp(myArray[i], target) == 0) {
            return 1;
        }
    }
    return 0;
}

void printKeywords(){
    printf("-----KeyWord list-----\n");
    for (int i = 0; i < sizeof(myArray) / sizeof(myArray[0]); ++i) {
        printf("%s ", myArray[i]);
    }
}

typedef struct {
    char* name;
    char* type;
    int intValue;
    double doubleValue;
    char* strValue;
} SymbolEntry;

SymbolEntry symbolTable[MAX_SYMBOLS];
int symbolCount = 0;
int ifcount = 0;
int isPurno = 0;

void add(char* name,char* type,int a,double b,char* str) {
    SymbolEntry entry;
    entry.name = strdup(name);
    entry.type = strdup(type);
    entry.intValue = a;  
    entry.doubleValue = b;
    entry.strValue = str;
    symbolTable[symbolCount++] = entry;
}

void update(int i,int a,double b,char* str){    
        symbolTable[i].intValue = a;
        symbolTable[i].doubleValue = b;
        symbolTable[i].strValue = str;
}

int find(char* name) {
    for (int i = 0; i < symbolCount; ++i) {
        if (symbolTable[i].name != NULL && strcmp(symbolTable[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void printSymbolTable() {
    printf("\n-----Symbol Table-----\n");
    for (int i = 0; i < symbolCount; ++i) {
        if(!strcmp(symbolTable[i].type, "purno")){
            printf("Name: %s,Type: %s, Value: %d\n",
               symbolTable[i].name,symbolTable[i].type,
               symbolTable[i].intValue);
        }

        if(!strcmp(symbolTable[i].type, "vogno")){
            printf("Name: %s,Type: %s, Value: %f\n",
               symbolTable[i].name,symbolTable[i].type,
               symbolTable[i].doubleValue);
        }

        if(!strcmp(symbolTable[i].type, "shobdo")){
            printf("Name: %s,Type: %s,Value: %s\n",
               symbolTable[i].name,symbolTable[i].type,
               symbolTable[i].strValue);
        }
        if(!strcmp(symbolTable[i].type, "funcType")){
            printf("Name: %s,Type: Function, Parameter: %d\n",symbolTable[i].name, symbolTable[i].intValue);
        }
        
    }
}


#line 173 "bisonFile.tab.c"

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

#include "bisonFile.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_headerStart = 3,                /* headerStart  */
  YYSYMBOL_comment = 4,                    /* comment  */
  YYSYMBOL_purno = 5,                      /* purno  */
  YYSYMBOL_EOL = 6,                        /* EOL  */
  YYSYMBOL_vogno = 7,                      /* vogno  */
  YYSYMBOL_shobdo = 8,                     /* shobdo  */
  YYSYMBOL_eval = 9,                       /* eval  */
  YYSYMBOL_mod = 10,                       /* mod  */
  YYSYMBOL_show = 11,                      /* show  */
  YYSYMBOL_shuru = 12,                     /* shuru  */
  YYSYMBOL_sesh = 13,                      /* sesh  */
  YYSYMBOL_IF = 14,                        /* IF  */
  YYSYMBOL_ELSE = 15,                      /* ELSE  */
  YYSYMBOL_concat = 16,                    /* concat  */
  YYSYMBOL_isEqual = 17,                   /* isEqual  */
  YYSYMBOL_isLarge = 18,                   /* isLarge  */
  YYSYMBOL_isLargeEqual = 19,              /* isLargeEqual  */
  YYSYMBOL_isSmaller = 20,                 /* isSmaller  */
  YYSYMBOL_isSmallerEqual = 21,            /* isSmallerEqual  */
  YYSYMBOL_isNotEqual = 22,                /* isNotEqual  */
  YYSYMBOL_qt = 23,                        /* qt  */
  YYSYMBOL_compare = 24,                   /* compare  */
  YYSYMBOL_LOOP = 25,                      /* LOOP  */
  YYSYMBOL_INC = 26,                       /* INC  */
  YYSYMBOL_DEC = 27,                       /* DEC  */
  YYSYMBOL_FUNC = 28,                      /* FUNC  */
  YYSYMBOL_copy = 29,                      /* copy  */
  YYSYMBOL_len = 30,                       /* len  */
  YYSYMBOL_FLOOR = 31,                     /* FLOOR  */
  YYSYMBOL_CEIL = 32,                      /* CEIL  */
  YYSYMBOL_SIN = 33,                       /* SIN  */
  YYSYMBOL_COS = 34,                       /* COS  */
  YYSYMBOL_TAN = 35,                       /* TAN  */
  YYSYMBOL_LOG = 36,                       /* LOG  */
  YYSYMBOL_POW = 37,                       /* POW  */
  YYSYMBOL_LOG10 = 38,                     /* LOG10  */
  YYSYMBOL_scan = 39,                      /* scan  */
  YYSYMBOL_GCD = 40,                       /* GCD  */
  YYSYMBOL_headerName = 41,                /* headerName  */
  YYSYMBOL_varName = 42,                   /* varName  */
  YYSYMBOL_number = 43,                    /* number  */
  YYSYMBOL_numberd = 44,                   /* numberd  */
  YYSYMBOL_45_ = 45,                       /* '+'  */
  YYSYMBOL_46_ = 46,                       /* '-'  */
  YYSYMBOL_47_ = 47,                       /* '/'  */
  YYSYMBOL_48_ = 48,                       /* '*'  */
  YYSYMBOL_49_ = 49,                       /* '('  */
  YYSYMBOL_50_ = 50,                       /* ')'  */
  YYSYMBOL_51_ = 51,                       /* '='  */
  YYSYMBOL_52_ = 52,                       /* '{'  */
  YYSYMBOL_53_ = 53,                       /* '}'  */
  YYSYMBOL_54_ = 54,                       /* ','  */
  YYSYMBOL_YYACCEPT = 55,                  /* $accept  */
  YYSYMBOL_input = 56,                     /* input  */
  YYSYMBOL_functions = 57,                 /* functions  */
  YYSYMBOL_function = 58,                  /* function  */
  YYSYMBOL_parameters = 59,                /* parameters  */
  YYSYMBOL_Ret = 60,                       /* Ret  */
  YYSYMBOL_onePar = 61,                    /* onePar  */
  YYSYMBOL_funcShuru = 62,                 /* funcShuru  */
  YYSYMBOL_cmnt = 63,                      /* cmnt  */
  YYSYMBOL_headers = 64,                   /* headers  */
  YYSYMBOL_header = 65,                    /* header  */
  YYSYMBOL_program = 66,                   /* program  */
  YYSYMBOL_start = 67,                     /* start  */
  YYSYMBOL_end = 68,                       /* end  */
  YYSYMBOL_statements = 69,                /* statements  */
  YYSYMBOL_statement = 70,                 /* statement  */
  YYSYMBOL_numberParameter = 71,           /* numberParameter  */
  YYSYMBOL_stringParameter = 72,           /* stringParameter  */
  YYSYMBOL_callPar = 73,                   /* callPar  */
  YYSYMBOL_oneCall = 74,                   /* oneCall  */
  YYSYMBOL_changer = 75,                   /* changer  */
  YYSYMBOL_loopOP = 76,                    /* loopOP  */
  YYSYMBOL_ifshuru = 77,                   /* ifshuru  */
  YYSYMBOL_condition = 78,                 /* condition  */
  YYSYMBOL_value = 79,                     /* value  */
  YYSYMBOL_expr = 80,                      /* expr  */
  YYSYMBOL_val = 81,                       /* val  */
  YYSYMBOL_multiVariable = 82,             /* multiVariable  */
  YYSYMBOL_dataType = 83,                  /* dataType  */
  YYSYMBOL_varNames = 84,                  /* varNames  */
  YYSYMBOL_oneVar = 85,                    /* oneVar  */
  YYSYMBOL_variableValueAssign = 86        /* variableValueAssign  */
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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   257

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  237

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


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
      49,    50,    48,    45,    54,    46,     2,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    51,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,     2,    53,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   125,   125,   126,   127,   129,   130,   132,   143,   144,
     145,   147,   151,   155,   160,   175,   177,   178,   179,   181,
     186,   188,   191,   195,   196,   198,   199,   207,   208,   209,
     210,   211,   212,   216,   260,   269,   286,   304,   320,   342,
     358,   382,   406,   432,   458,   484,   509,   534,   558,   591,
     592,   593,   611,   612,   632,   633,   635,   639,   640,   642,
     643,   644,   645,   648,   649,   658,   666,   674,   682,   690,
     698,   709,   730,   731,   732,   733,   734,   735,   743,   744,
     745,   750,   771,   773,   774,   775,   777,   778,   780,   801,
     818,   836,   854,   870,   886,   904
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
  "\"end of file\"", "error", "\"invalid token\"", "headerStart",
  "comment", "purno", "EOL", "vogno", "shobdo", "eval", "mod", "show",
  "shuru", "sesh", "IF", "ELSE", "concat", "isEqual", "isLarge",
  "isLargeEqual", "isSmaller", "isSmallerEqual", "isNotEqual", "qt",
  "compare", "LOOP", "INC", "DEC", "FUNC", "copy", "len", "FLOOR", "CEIL",
  "SIN", "COS", "TAN", "LOG", "POW", "LOG10", "scan", "GCD", "headerName",
  "varName", "number", "numberd", "'+'", "'-'", "'/'", "'*'", "'('", "')'",
  "'='", "'{'", "'}'", "','", "$accept", "input", "functions", "function",
  "parameters", "Ret", "onePar", "funcShuru", "cmnt", "headers", "header",
  "program", "start", "end", "statements", "statement", "numberParameter",
  "stringParameter", "callPar", "oneCall", "changer", "loopOP", "ifshuru",
  "condition", "value", "expr", "val", "multiVariable", "dataType",
  "varNames", "oneVar", "variableValueAssign", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-117)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      32,   -37,  -117,    49,    32,    17,    32,  -117,  -117,  -117,
    -117,   -10,    40,    26,    14,  -117,    39,  -117,  -117,  -117,
    -117,  -117,   128,  -117,  -117,  -117,    15,    23,  -117,    28,
      25,    -9,  -117,    62,    39,    30,  -117,    57,  -117,    81,
      46,    64,    70,  -117,  -117,  -117,    24,  -117,  -117,   126,
      95,   132,    18,   130,  -117,  -117,  -117,    15,    88,  -117,
      -3,    89,   128,  -117,   118,  -117,    15,    15,    15,    15,
      15,  -117,   109,  -117,   141,    99,    96,   110,   102,   114,
     108,   120,   122,   127,   129,   131,   133,   134,   135,   136,
     137,   138,   152,   169,    50,   140,    97,    82,  -117,    57,
     159,  -117,  -117,  -117,    73,    73,   171,   171,  -117,  -117,
    -117,  -117,    15,  -117,   173,   128,  -117,   -18,   165,   -18,
     -18,   -18,    80,    80,    80,    80,    80,    80,    80,    80,
      80,  -117,  -117,  -117,   139,    15,    15,    15,    15,    15,
      15,   150,  -117,  -117,  -117,   144,    56,  -117,  -117,   154,
    -117,   145,   188,   146,   148,   151,  -117,  -117,  -117,   153,
     155,   156,   157,   158,   160,   161,   162,   163,    39,    45,
      45,    45,    45,    45,    45,   179,   128,     1,   181,   -18,
    -117,   -18,   203,   205,   207,   208,   210,   212,   213,   214,
      80,   215,    80,   170,  -117,   172,   182,  -117,  -117,    15,
    -117,   175,   176,  -117,  -117,  -117,  -117,  -117,  -117,  -117,
    -117,   177,  -117,   178,   216,   180,  -117,    63,   223,   224,
     227,   228,   183,    39,   184,  -117,  -117,  -117,  -117,    39,
     185,    39,   186,  -117,   187,  -117,  -117
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    15,     0,     0,     0,    17,    19,     1,     4,
      21,     0,     0,     6,     0,     2,    25,    18,    16,    14,
       3,     5,     8,    83,    84,    85,     0,     0,    63,     0,
       0,     0,    27,     0,    24,     0,    28,     0,    29,     0,
       9,     0,     0,    81,    78,    79,     0,    72,    71,     0,
       0,     0,     0,     0,    22,    20,    23,     0,    88,    82,
       0,     0,     8,    13,     0,    30,     0,     0,     0,     0,
       0,    31,     0,    26,     0,     0,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    78,    79,     0,     0,    70,     0,    87,     0,
       0,    10,    80,    77,    73,    74,    76,    75,    59,    60,
      61,    62,     0,    34,     0,     0,    56,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    92,    93,    94,     0,     0,     0,     0,     0,     0,
       0,     0,    89,    90,    86,     0,     0,    35,    55,     0,
      53,     0,    80,     0,     0,     0,    51,    49,    50,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    25,    64,
      65,    66,    67,    68,    69,     0,    11,     0,     0,     0,
      95,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    91,     0,     0,    57,    58,     0,
      52,     0,     0,    37,    39,    40,    41,    42,    43,    44,
      45,     0,    46,     0,     0,     0,    12,     0,     0,     0,
       0,     0,     0,    25,     0,    36,    38,    47,    48,    25,
       0,    25,     0,     7,     0,    32,    33
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -117,   233,   229,  -117,   189,  -117,  -117,  -117,    33,   235,
    -117,   231,  -117,  -117,   -34,  -117,  -116,   -99,   142,  -117,
    -117,  -117,  -117,  -117,  -117,   -51,  -117,  -117,   -21,   147,
    -117,  -117
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,    12,    13,    39,   195,    40,    14,    32,     5,
       6,    15,    16,    55,    33,    34,   159,   151,    75,    76,
     199,   112,    35,    95,    49,    46,    47,    36,    37,    59,
      60,    38
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      56,    41,    94,    98,     7,   149,    96,   160,   161,   162,
     163,   164,   165,   166,   167,   103,   104,   105,   106,   107,
     153,   154,   155,    23,   150,    24,    25,   197,   198,    10,
      65,    77,    19,     4,    66,     1,     2,     4,    42,    17,
      52,    41,    53,     2,    23,    11,    24,    25,    26,     8,
      27,    99,    10,    28,    11,    66,   133,    43,    44,    45,
      66,   146,   177,    22,    29,    48,    66,    51,    74,    67,
      68,    69,    70,    66,   211,    54,   213,    50,    30,    57,
     201,    31,   202,    66,   169,   170,   171,   172,   173,   174,
      67,    68,    69,    70,    77,    67,    68,    69,    70,    58,
      62,    67,    68,    69,    70,   141,    63,    66,    67,    68,
      69,    70,    64,   224,   135,   136,   137,   138,   139,   140,
      69,    70,   156,   157,   158,   142,   143,   108,   109,   110,
     111,    61,    71,    23,   193,    24,    25,    72,    73,    97,
     100,   102,    67,    68,    69,    70,    78,   113,   217,   114,
     115,   117,   116,    79,    80,   196,   118,   119,   131,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,   120,
      91,   121,    43,    92,    93,   132,   122,   145,   123,   147,
     124,    66,   125,   126,   127,   128,   129,   130,   152,   230,
     134,   168,   175,   176,   180,   232,   178,   234,   182,   179,
     181,   183,   194,   184,   200,   185,   186,   187,   188,   203,
     189,   204,   191,   205,   206,   190,   207,   192,   208,   209,
     210,   212,   215,   214,   216,   218,   219,   220,   221,   225,
     226,   222,   223,   227,   228,   229,   231,     9,   233,   235,
     236,    18,    21,    20,     0,     0,   144,     0,     0,     0,
       0,   101,     0,     0,     0,     0,     0,   148
};

static const yytype_int16 yycheck[] =
{
      34,    22,    53,     6,    41,    23,    57,   123,   124,   125,
     126,   127,   128,   129,   130,    66,    67,    68,    69,    70,
     119,   120,   121,     5,    42,     7,     8,    26,    27,    12,
       6,    52,    42,     0,    10,     3,     4,     4,    23,     6,
      49,    62,    51,     4,     5,    28,     7,     8,     9,     0,
      11,    54,    12,    14,    28,    10,     6,    42,    43,    44,
      10,   112,     6,    49,    25,    42,    10,    42,    50,    45,
      46,    47,    48,    10,   190,    13,   192,    49,    39,    49,
     179,    42,   181,    10,   135,   136,   137,   138,   139,   140,
      45,    46,    47,    48,   115,    45,    46,    47,    48,    42,
      54,    45,    46,    47,    48,    23,    42,    10,    45,    46,
      47,    48,    42,    50,    17,    18,    19,    20,    21,    22,
      47,    48,    42,    43,    44,    43,    44,    18,    19,    20,
      21,    50,     6,     5,   168,     7,     8,    42,     6,    51,
      51,    23,    45,    46,    47,    48,    16,     6,   199,    50,
      54,    49,    42,    23,    24,   176,    42,    49,     6,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    49,
      40,    49,    42,    43,    44,     6,    49,    18,    49,     6,
      49,    10,    49,    49,    49,    49,    49,    49,    23,   223,
      50,    52,    42,    49,     6,   229,    42,   231,    50,    54,
      54,    50,    23,    50,    23,    50,    50,    50,    50,     6,
      50,     6,    50,     6,     6,    54,     6,    54,     6,     6,
       6,     6,    50,    53,    42,    50,    50,    50,    50,     6,
       6,    15,    52,     6,     6,    52,    52,     4,    53,    53,
      53,     6,    13,    12,    -1,    -1,    99,    -1,    -1,    -1,
      -1,    62,    -1,    -1,    -1,    -1,    -1,   115
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,    56,    63,    64,    65,    41,     0,    56,
      12,    28,    57,    58,    62,    66,    67,    63,    64,    42,
      66,    57,    49,     5,     7,     8,     9,    11,    14,    25,
      39,    42,    63,    69,    70,    77,    82,    83,    86,    59,
      61,    83,    23,    42,    43,    44,    80,    81,    42,    79,
      49,    42,    49,    51,    13,    68,    69,    49,    42,    84,
      85,    50,    54,    42,    42,     6,    10,    45,    46,    47,
      48,     6,    42,     6,    50,    73,    74,    83,    16,    23,
      24,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    40,    43,    44,    80,    78,    80,    51,     6,    54,
      51,    59,    23,    80,    80,    80,    80,    80,    18,    19,
      20,    21,    76,     6,    50,    54,    42,    49,    42,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,     6,     6,     6,    50,    17,    18,    19,    20,    21,
      22,    23,    43,    44,    84,    18,    80,     6,    73,    23,
      42,    72,    23,    72,    72,    72,    42,    43,    44,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    52,    80,
      80,    80,    80,    80,    80,    42,    49,     6,    42,    54,
       6,    54,    50,    50,    50,    50,    50,    50,    50,    50,
      54,    50,    54,    69,    23,    60,    83,    26,    27,    75,
      23,    72,    72,     6,     6,     6,     6,     6,     6,     6,
       6,    71,     6,    71,    53,    50,    42,    80,    50,    50,
      50,    50,    15,    52,    50,     6,     6,     6,     6,    52,
      69,    52,    69,    53,    69,    53,    53
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    55,    56,    56,    56,    57,    57,    58,    59,    59,
      59,    60,    60,    61,    62,    63,    64,    64,    64,    65,
      66,    67,    68,    69,    69,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    71,
      71,    71,    72,    72,    73,    73,    74,    75,    75,    76,
      76,    76,    76,    77,    78,    78,    78,    78,    78,    78,
      78,    79,    80,    80,    80,    80,    80,    80,    81,    81,
      81,    81,    82,    83,    83,    83,    84,    84,    85,    85,
      85,    85,    86,    86,    86,    86
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     2,     2,     1,    12,     0,     1,
       3,     0,     2,     2,     2,     1,     2,     1,     2,     2,
       3,     1,     1,     2,     1,     0,     3,     1,     1,     1,
       3,     3,    11,    12,     4,     5,     9,     7,     9,     7,
       7,     7,     7,     7,     7,     7,     7,     9,     9,     1,
       1,     1,     3,     1,     1,     3,     2,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     3,     3,     3,     3,     3,     1,     1,
       3,     1,     2,     1,     1,     1,     3,     2,     1,     3,
       3,     5,     4,     4,     4,     6
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
  case 7: /* function: funcShuru '(' parameters ')' '=' isLarge '(' Ret ')' '{' statements '}'  */
#line 132 "bisonFile.y"
                                                                                {

                                int i = find((yyvsp[-11].txt));
                                if(i!=-1){  
                                    update(i,funcVarCount,0.0,"");

                                }
                                funcVarCount = 0;
                                printf("-------------Ended:%s Declaration-------------\n\n",(yyvsp[-11].txt));
                            }
#line 1408 "bisonFile.tab.c"
    break;

  case 8: /* parameters: %empty  */
#line 143 "bisonFile.y"
            {printf("No parameters");}
#line 1414 "bisonFile.tab.c"
    break;

  case 11: /* Ret: %empty  */
#line 147 "bisonFile.y"
        {
            printf("\nReturn: No Return\n");
            printf("--Statements inside function--\n");
        }
#line 1423 "bisonFile.tab.c"
    break;

  case 12: /* Ret: dataType varName  */
#line 151 "bisonFile.y"
                       {
        printf("\nReturn: %s %s\n",(yyvsp[-1].txt),(yyvsp[0].txt));
        printf("--Statements inside function--\n");
        }
#line 1432 "bisonFile.tab.c"
    break;

  case 13: /* onePar: dataType varName  */
#line 155 "bisonFile.y"
                            {
    funcVarCount++;
    printf("%s %s ,",(yyvsp[-1].txt),(yyvsp[0].txt));
    }
#line 1441 "bisonFile.tab.c"
    break;

  case 14: /* funcShuru: FUNC varName  */
#line 160 "bisonFile.y"
                       {
            if (find((yyvsp[0].txt)) != -1) {
                printf("line %d => Already declared:  %s \n",yylineno, (yyvsp[0].txt));
                yyexit("Error occured");
            } 
            else{
                add((yyvsp[0].txt),"funcType",0,0.0,"");
                printf("\n-------------Started: %s Declaration-------------\n",(yyvsp[0].txt));
                printf("Parameters: ");
                (yyval.txt) = (yyvsp[0].txt);

            }       
        
    }
#line 1460 "bisonFile.tab.c"
    break;

  case 15: /* cmnt: comment  */
#line 175 "bisonFile.y"
              {printf("This is a comment\n");}
#line 1466 "bisonFile.tab.c"
    break;

  case 19: /* header: headerStart headerName  */
#line 182 "bisonFile.y"
{
   
    printf("Included: %s\n",(yyvsp[0].txt));}
#line 1474 "bisonFile.tab.c"
    break;

  case 21: /* start: shuru  */
#line 189 "bisonFile.y"
{
    printf("\n-------------Started: Main--------------\n\n");}
#line 1481 "bisonFile.tab.c"
    break;

  case 22: /* end: sesh  */
#line 192 "bisonFile.y"
{
    printf("\n-------------Ended: Main--------------\n");}
#line 1488 "bisonFile.tab.c"
    break;

  case 26: /* statement: scan varName EOL  */
#line 199 "bisonFile.y"
                          {
            if (find((yyvsp[-1].txt)) != -1) {
                    printf("Waiting: User input in %s",(yyvsp[-1].txt));
            } 
            else{
                printf("line %d => Not exist: %s variable",yylineno,(yyvsp[-1].txt));
            }
        }
#line 1501 "bisonFile.tab.c"
    break;

  case 30: /* statement: eval expr EOL  */
#line 210 "bisonFile.y"
                        {printf("Evaluated result is : %f\n",(yyvsp[-1].numd));}
#line 1507 "bisonFile.tab.c"
    break;

  case 32: /* statement: ifshuru '(' condition ')' '{' statements '}' ELSE '{' statements '}'  */
#line 212 "bisonFile.y"
                                                                               {
                ifcount++;
                printf("Finished: %d.IF-ELSE - %s \n",ifcount,(yyvsp[-8].txt));
            }
#line 1516 "bisonFile.tab.c"
    break;

  case 33: /* statement: LOOP '(' varName loopOP expr EOL changer expr ')' '{' statements '}'  */
#line 216 "bisonFile.y"
                                                                                {
                                int i = find((yyvsp[-9].txt));
                                int x;
                                int incSize;
                                int y = (int)(yyvsp[-7].numd);
                                if(!strcmp((yyvsp[-5].txt),"dec")){
                                    incSize = -1 * (int)(yyvsp[-4].numd);
                                }
                                else{
                                    incSize = (int)(yyvsp[-4].numd);
                                }
                                if(i!=-1){
                                    if(!strcmp(symbolTable[i].type, "purno")){    
                                        x = symbolTable[i].intValue;
                                    }
                                    else if(!strcmp(symbolTable[i].type, "vogno")){    
                                        x =(int) symbolTable[i].doubleValue;
                                    }
                                    else{
                                        x =0;
                                    }

                                    if(!strcmp((yyvsp[-8].txt),"<=")){
                                        for(int m = x;m<=y;m+=incSize){
                                            printf("Loop: Executed for %d\n",m);
                                        }
                                    }
                                    if(!strcmp((yyvsp[-8].txt),">=")){
                                        for(int m = x;m>=y;m+=incSize){
                                            printf("Loop: Executed for %d\n",m);
                                        }
                                    }
                                    if(!strcmp((yyvsp[-8].txt),">")){
                                        for(int m = x;m>y;m+=incSize){
                                            printf("Loop: Executed for %d\n",m);
                                        }
                                    }
                                    if(!strcmp((yyvsp[-8].txt),"<")){
                                        for(int m = x;m<y;m+=incSize){
                                            printf("Loop: Executed for %d\n",m);
                                        }
                                    }
                                }
                            }
#line 1565 "bisonFile.tab.c"
    break;

  case 34: /* statement: varName '(' ')' EOL  */
#line 260 "bisonFile.y"
                              {
                        int i = find((yyvsp[-3].txt));
                        if(i!=-1 && symbolTable[i].intValue == 0 && !strcmp(symbolTable[i].type, "funcType")){
                            printf("Call: %s Function called with 0 parameters.\n",symbolTable[i].name);
                        }
                        else{
                            printf("line %d => No Function Found for %s\n",yylineno,(yyvsp[-3].txt));
                        }                       
                    }
#line 1579 "bisonFile.tab.c"
    break;

  case 35: /* statement: varName '(' callPar ')' EOL  */
#line 269 "bisonFile.y"
                                      {
                        int i = find((yyvsp[-4].txt));
                        if(i!=-1 && !strcmp(symbolTable[i].type, "funcType")){
                            if(symbolTable[i].intValue == funcVarCount){
                                printf("Call: %s Function called with %d parameters.\n",symbolTable[i].name,funcVarCount);
                            }
                            else{
                                printf("line %d => Mismatch: Parameter Count =>%s has %d , called with %d\n",yylineno,(yyvsp[-4].txt),symbolTable[i].intValue,funcVarCount);
                            }
                        }
                        else{
                            printf("line %d => Not exist: Function %s\n",yylineno,(yyvsp[-4].txt));
                        }   

                        funcVarCount = 0;                    
                    }
#line 1600 "bisonFile.tab.c"
    break;

  case 36: /* statement: varName '=' concat '(' stringParameter ',' stringParameter ')' EOL  */
#line 286 "bisonFile.y"
                                                                                 {
                    int i = find((yyvsp[-8].txt));
                    if(i==-1){
                        printf("line %d => Not Exist: variable %s\n",yylineno,(yyvsp[-8].txt));
                    }
                    else{
                        if(strcmp(symbolTable[i].type, "shobdo")){    
                            printf("line %d => Mismatch: %s is not shobdo.\n",yylineno,symbolTable[i].name);
                        }
                        else{
                            char tmp[1000] = "";    
                            strcpy(tmp, (yyvsp[-4].txt));
                            strcat(tmp,(yyvsp[-2].txt));
                            symbolTable[i].strValue = tmp;
                            printf("Concatenation: %s => %s\n",symbolTable[i].name,symbolTable[i].strValue);
                        }
                    }
                }
#line 1623 "bisonFile.tab.c"
    break;

  case 37: /* statement: varName '=' copy '(' stringParameter ')' EOL  */
#line 304 "bisonFile.y"
                                                           {
                    int i = find((yyvsp[-6].txt));
                    if(i==-1){
                        printf("line %d => Not Exist: variable %s\n",yylineno,(yyvsp[-6].txt));
                    }
                    else{
                        if(strcmp(symbolTable[i].type, "shobdo")){    
                            printf("line %d => Mismatch: %s is not shobdo.\n",yylineno,symbolTable[i].name);
                        }
                        else{
                            symbolTable[i].strValue = (yyvsp[-2].txt);
                            printf("Copy: %s => %s\n",symbolTable[i].name,symbolTable[i].strValue);
                        }
                    }
                }
#line 1643 "bisonFile.tab.c"
    break;

  case 38: /* statement: varName '=' compare '(' stringParameter ',' stringParameter ')' EOL  */
#line 320 "bisonFile.y"
                                                                                  {
                    int i = find((yyvsp[-8].txt));
                    if(i==-1){
                        printf("line %d => Not Exist: variable %s\n",yylineno,(yyvsp[-8].txt));
                    }
                    else{
                        if(strcmp(symbolTable[i].type, "shobdo")){    
                            printf("line %d => Mismatch: %s is not shobdo.\n",yylineno,symbolTable[i].name);
                        }
                        else{
                            if(strcmp((yyvsp[-4].txt),(yyvsp[-2].txt))){
                                symbolTable[i].strValue = "false";
                            }
                            else{
                                symbolTable[i].strValue = "true";
                            }
                            
                            printf("Compare: %s and %s => %s\n",(yyvsp[-4].txt),(yyvsp[-2].txt),symbolTable[i].strValue);
                        }
                    }
                }
#line 1669 "bisonFile.tab.c"
    break;

  case 39: /* statement: varName '=' len '(' stringParameter ')' EOL  */
#line 342 "bisonFile.y"
                                                           {
                int i = find((yyvsp[-6].txt));
                if(i==-1){
                    printf("line %d => Not Exist: variable %s\n",yylineno,(yyvsp[-6].txt));
                }
                else{
                    if(strcmp(symbolTable[i].type, "purno")){    
                        printf("line %d => Mismatch: %s is not purno.\n",yylineno,symbolTable[i].name);
                    }
                    else{
                        symbolTable[i].intValue = strlen((yyvsp[-2].txt));
                        printf("Length: %s  => %d\n",(yyvsp[-2].txt),symbolTable[i].intValue);
                    }
                }
            }
#line 1689 "bisonFile.tab.c"
    break;

  case 40: /* statement: varName '=' FLOOR '(' numberParameter ')' EOL  */
#line 358 "bisonFile.y"
                                                        {
                    int i = find((yyvsp[-6].txt));
                    if(i==-1){
                        printf("line %d => Not Exist: variable %s\n",yylineno,(yyvsp[-6].txt));
                    }
                    else{
                        double result;
                        if(!strcmp(symbolTable[i].type, "shobdo")){    
                            printf("line %d => Mismatch: %s , type: Shobdo.\n",yylineno,symbolTable[i].name);
                        }
                        else{
                            result = floor((yyvsp[-2].numd));
                            if(!strcmp(symbolTable[i].type, "purno")){
                                symbolTable[i].intValue = (int) result;
                                printf("Floor: %0.2f  => %d\n",(yyvsp[-2].numd),symbolTable[i].intValue);
                            }

                            if(!strcmp(symbolTable[i].type, "vogno")){
                                symbolTable[i].doubleValue = result;
                                printf("Floor: %f  => %0.0f\n",(yyvsp[-2].numd),symbolTable[i].doubleValue);
                            }
                        }
                    }
                }
#line 1718 "bisonFile.tab.c"
    break;

  case 41: /* statement: varName '=' CEIL '(' numberParameter ')' EOL  */
#line 382 "bisonFile.y"
                                                       {
                int i = find((yyvsp[-6].txt));
                if(i==-1){
                    printf("line %d => Not Exist: variable %s\n",yylineno,(yyvsp[-6].txt));
                }
                else{
                    double result;
                    if(!strcmp(symbolTable[i].type, "shobdo")){    
                        printf("line %d => Mismatch: %s , type: Shobdo.\n",yylineno,symbolTable[i].name);
                    }
                    else{
                        result = ceil((yyvsp[-2].numd));
                        if(!strcmp(symbolTable[i].type, "purno")){
                            symbolTable[i].intValue = (int) result;
                            printf("Ceil: %0.2f  => %d\n",(yyvsp[-2].numd),symbolTable[i].intValue);
                        }

                        if(!strcmp(symbolTable[i].type, "vogno")){
                            symbolTable[i].doubleValue = result;
                            printf("Ceil: %f  => %0.0f\n",(yyvsp[-2].numd),symbolTable[i].doubleValue);
                        }
                    }
                }
            }
#line 1747 "bisonFile.tab.c"
    break;

  case 42: /* statement: varName '=' SIN '(' numberParameter ')' EOL  */
#line 406 "bisonFile.y"
                                                      {
            int i = find((yyvsp[-6].txt));
            if(i==-1){
                printf("line %d => Not Exist: variable %s\n",yylineno,(yyvsp[-6].txt));
            }
            else{
                double result;
                if(!strcmp(symbolTable[i].type, "shobdo")){    
                    printf("line %d => Mismatch: %s , type: Shobdo.\n",yylineno,symbolTable[i].name);
                }
                else{
                    float ab = (yyvsp[-2].numd) * 3.1416/180;
                    result = sin(ab);
                    if(!strcmp(symbolTable[i].type, "purno")){
                        symbolTable[i].intValue = (int) result;
                        printf("Sine: %0.2f  => %d\n",(yyvsp[-2].numd),symbolTable[i].intValue);
                    }

                    if(!strcmp(symbolTable[i].type, "vogno")){
                        symbolTable[i].doubleValue = result;
                        printf("Sine: %f  => %f\n",(yyvsp[-2].numd),symbolTable[i].doubleValue);
                    }
                }
            }
            }
#line 1777 "bisonFile.tab.c"
    break;

  case 43: /* statement: varName '=' COS '(' numberParameter ')' EOL  */
#line 432 "bisonFile.y"
                                                      {
            int i = find((yyvsp[-6].txt));
            if(i==-1){
                printf("line %d => Not Exist: variable %s\n",yylineno,(yyvsp[-6].txt));
            }
            else{
                double result;
                if(!strcmp(symbolTable[i].type, "shobdo")){    
                    printf("line %d => Mismatch: %s , type: Shobdo.\n",yylineno,symbolTable[i].name);
                }
                else{
                    float ab = (yyvsp[-2].numd) * 3.1416/180;
                    result = cos(ab);
                    if(!strcmp(symbolTable[i].type, "purno")){
                        symbolTable[i].intValue = (int) result;
                        printf("Cos: %0.2f  => %d\n",(yyvsp[-2].numd),symbolTable[i].intValue);
                    }

                    if(!strcmp(symbolTable[i].type, "vogno")){
                        symbolTable[i].doubleValue = result;
                        printf("Cos: %f  => %f\n",(yyvsp[-2].numd),symbolTable[i].doubleValue);
                    }
                }
            }
            }
#line 1807 "bisonFile.tab.c"
    break;

  case 44: /* statement: varName '=' TAN '(' numberParameter ')' EOL  */
#line 458 "bisonFile.y"
                                                      {
            int i = find((yyvsp[-6].txt));
            if(i==-1){
                printf("line %d => Not Exist: variable %s\n",yylineno,(yyvsp[-6].txt));
            }
            else{
                double result;
                if(!strcmp(symbolTable[i].type, "shobdo")){    
                    printf("line %d => Mismatch: %s , type: Shobdo.\n",yylineno,symbolTable[i].name);
                }
                else{
                    float ab = (yyvsp[-2].numd) * 3.1416/180;
                    result = tan(ab);
                    if(!strcmp(symbolTable[i].type, "purno")){
                        symbolTable[i].intValue = (int) result;
                        printf("Tan: %0.2f  => %d\n",(yyvsp[-2].numd),symbolTable[i].intValue);
                    }

                    if(!strcmp(symbolTable[i].type, "vogno")){
                        symbolTable[i].doubleValue = result;
                        printf("Tan: %f  => %f\n",(yyvsp[-2].numd),symbolTable[i].doubleValue);
                    }
                }
            }
            }
#line 1837 "bisonFile.tab.c"
    break;

  case 45: /* statement: varName '=' LOG '(' numberParameter ')' EOL  */
#line 484 "bisonFile.y"
                                                      {
            int i = find((yyvsp[-6].txt));
            if(i==-1){
                printf("line %d => Not Exist: variable %s\n",yylineno,(yyvsp[-6].txt));
            }
            else{
                double result;
                if(!strcmp(symbolTable[i].type, "shobdo")){    
                    printf("line %d => Mismatch: %s , type: Shobdo.\n",yylineno,symbolTable[i].name);
                }
                else{
                    result = log((yyvsp[-2].numd));
                    if(!strcmp(symbolTable[i].type, "purno")){
                        symbolTable[i].intValue = (int) result;
                        printf("Log: %0.2f  => %d\n",(yyvsp[-2].numd),symbolTable[i].intValue);
                    }

                    if(!strcmp(symbolTable[i].type, "vogno")){
                        symbolTable[i].doubleValue = result;
                        printf("Log: %f  => %f\n",(yyvsp[-2].numd),symbolTable[i].doubleValue);
                    }
                }
            }
            }
#line 1866 "bisonFile.tab.c"
    break;

  case 46: /* statement: varName '=' LOG10 '(' numberParameter ')' EOL  */
#line 509 "bisonFile.y"
                                                        {
            int i = find((yyvsp[-6].txt));
            if(i==-1){
                printf("line %d => Not Exist: variable %s\n",yylineno,(yyvsp[-6].txt));
            }
            else{
                double result;
                if(!strcmp(symbolTable[i].type, "shobdo")){    
                    printf("line %d => Mismatch: %s , type: Shobdo.\n",yylineno,symbolTable[i].name);
                }
                else{
                    result = log10((yyvsp[-2].numd));
                    if(!strcmp(symbolTable[i].type, "purno")){
                        symbolTable[i].intValue = (int) result;
                        printf("Log10: %0.2f  => %d\n",(yyvsp[-2].numd),symbolTable[i].intValue);
                    }

                    if(!strcmp(symbolTable[i].type, "vogno")){
                        symbolTable[i].doubleValue = result;
                        printf("Log10: %f  => %f\n",(yyvsp[-2].numd),symbolTable[i].doubleValue);
                    }
                }
            }
            }
#line 1895 "bisonFile.tab.c"
    break;

  case 47: /* statement: varName '=' POW '(' numberParameter ',' numberParameter ')' EOL  */
#line 534 "bisonFile.y"
                                                                         {
                int i = find((yyvsp[-8].txt));
                if(i==-1){
                    printf("line %d => Not Exist: variable %s\n",yylineno,(yyvsp[-8].txt));
                }
                else{
                    double result;
                    if(!strcmp(symbolTable[i].type, "shobdo")){    
                        printf("line %d => Mismatch: %s , type: Shobdo.\n",yylineno,symbolTable[i].name);
                    }
                    else{
                        result = pow((yyvsp[-4].numd),(yyvsp[-2].numd));
                        if(!strcmp(symbolTable[i].type, "purno")){
                            symbolTable[i].intValue = (int) result;
                            printf("Power: %f  ^ %f => %d\n",(yyvsp[-4].numd),(yyvsp[-2].numd),symbolTable[i].intValue);
                        }

                        if(!strcmp(symbolTable[i].type, "vogno")){
                            symbolTable[i].doubleValue = result;
                            printf("Power: %f  ^ %f => %f\n",(yyvsp[-4].numd),(yyvsp[-2].numd),symbolTable[i].doubleValue);
                        }
                    }
                }
            }
#line 1924 "bisonFile.tab.c"
    break;

  case 48: /* statement: varName '=' GCD '(' numberParameter ',' numberParameter ')' EOL  */
#line 558 "bisonFile.y"
                                                                         {
            int i = find((yyvsp[-8].txt));
            if(i==-1){
                printf("line %d => Not Exist: variable %s\n",yylineno,(yyvsp[-8].txt));
            }
            else{
                int result;
                if(!strcmp(symbolTable[i].type, "shobdo")){    
                    printf("line %d => Mismatch: %s , type: Shobdo.\n",yylineno,symbolTable[i].name);
                }
                else{
                    int b = (int)(yyvsp[-2].numd);
                    int a = (int)(yyvsp[-4].numd);
                    while (b != 0) {
                        int temp = b;
                        b = a % b;
                        a = temp;
                    }

                    result = a;

                    if(!strcmp(symbolTable[i].type, "purno")){
                        symbolTable[i].intValue = (int) result;
                        printf("GCD: %d and %d => %d\n",(int)(yyvsp[-4].numd),(int)(yyvsp[-2].numd),symbolTable[i].intValue);
                    }

                    if(!strcmp(symbolTable[i].type, "vogno")){
                        printf("line %d => Mismatch: Datatype => GCD can only be purno\n",yylineno);
                    }
                }
            }
        }
#line 1961 "bisonFile.tab.c"
    break;

  case 49: /* numberParameter: number  */
#line 591 "bisonFile.y"
                         {(yyval.numd) = (yyvsp[0].num)*1.0;}
#line 1967 "bisonFile.tab.c"
    break;

  case 50: /* numberParameter: numberd  */
#line 592 "bisonFile.y"
                          {(yyval.numd) = (yyvsp[0].numd);}
#line 1973 "bisonFile.tab.c"
    break;

  case 51: /* numberParameter: varName  */
#line 593 "bisonFile.y"
                            {
                    int i = find((yyvsp[0].txt));
                    if(i==-1){
                        printf("line %d => Not Exist: variable %s\n",yylineno,(yyvsp[0].txt));
                    }
                    else{
                        if(!strcmp(symbolTable[i].type, "shobdo")){    
                            printf("line %d => Mismatch: %s is not number.\n",yylineno,symbolTable[i].name);
                        }
                        else if(!strcmp(symbolTable[i].type, "purno")){
                            (yyval.numd) = symbolTable[i].intValue * 1.0 ;
                        }
                        else if(!strcmp(symbolTable[i].type, "vogno")){
                            (yyval.numd) = symbolTable[i].doubleValue ;
                        }
                    }
                }
#line 1995 "bisonFile.tab.c"
    break;

  case 52: /* stringParameter: qt varName qt  */
#line 611 "bisonFile.y"
                                {(yyval.txt) = (yyvsp[-1].txt);}
#line 2001 "bisonFile.tab.c"
    break;

  case 53: /* stringParameter: varName  */
#line 612 "bisonFile.y"
                            {
                    int i = find((yyvsp[0].txt));
                    if(i==-1){
                        printf("line %d => Not Exist: variable %s\n",yylineno,(yyvsp[0].txt));
                    }
                    else{
                        if(strcmp(symbolTable[i].type, "shobdo")){    
                            printf("line %d => Mismatch: %s is not shobdo.\n",yylineno,symbolTable[i].name);
                        }

                        else{
                            if(!strcmp(symbolTable[i].strValue,"")){
                                printf("line %d => Missing value: %s is empty\n",yylineno,symbolTable[i].name);
                            }
                            else{
                                (yyval.txt) = symbolTable[i].strValue;
                            }
                        }
                    }
                }
#line 2026 "bisonFile.tab.c"
    break;

  case 56: /* oneCall: dataType varName  */
#line 635 "bisonFile.y"
                           {
    funcVarCount++;
    }
#line 2034 "bisonFile.tab.c"
    break;

  case 57: /* changer: INC  */
#line 639 "bisonFile.y"
             {(yyval.txt) = "inc";}
#line 2040 "bisonFile.tab.c"
    break;

  case 58: /* changer: DEC  */
#line 640 "bisonFile.y"
             {(yyval.txt) = "dec";}
#line 2046 "bisonFile.tab.c"
    break;

  case 59: /* loopOP: isLarge  */
#line 642 "bisonFile.y"
                {(yyval.txt) = ">";}
#line 2052 "bisonFile.tab.c"
    break;

  case 60: /* loopOP: isLargeEqual  */
#line 643 "bisonFile.y"
                   {(yyval.txt) = ">=";}
#line 2058 "bisonFile.tab.c"
    break;

  case 61: /* loopOP: isSmaller  */
#line 644 "bisonFile.y"
                {(yyval.txt) = "<";}
#line 2064 "bisonFile.tab.c"
    break;

  case 62: /* loopOP: isSmallerEqual  */
#line 645 "bisonFile.y"
                     {(yyval.txt) = "<=";}
#line 2070 "bisonFile.tab.c"
    break;

  case 63: /* ifshuru: IF  */
#line 648 "bisonFile.y"
            {printf("Started: IF BLOCK\n");}
#line 2076 "bisonFile.tab.c"
    break;

  case 64: /* condition: expr isEqual expr  */
#line 650 "bisonFile.y"
    {
        if((yyvsp[-2].numd) == (yyvsp[0].numd)){
            (yyval.txt) = "true";  
        }
        else{
            (yyval.txt) = "false";
        }
    }
#line 2089 "bisonFile.tab.c"
    break;

  case 65: /* condition: expr isLarge expr  */
#line 658 "bisonFile.y"
                        {
        if((yyvsp[-2].numd) > (yyvsp[0].numd)){
            (yyval.txt) = "true";  
        }
        else{
            (yyval.txt) = "false";
        }
    }
#line 2102 "bisonFile.tab.c"
    break;

  case 66: /* condition: expr isLargeEqual expr  */
#line 666 "bisonFile.y"
                             {
        if((yyvsp[-2].numd) >= (yyvsp[0].numd)){
            (yyval.txt) = "true";  
        }
        else{
            (yyval.txt) = "false";
        }
    }
#line 2115 "bisonFile.tab.c"
    break;

  case 67: /* condition: expr isSmaller expr  */
#line 674 "bisonFile.y"
                          {
        if((yyvsp[-2].numd) < (yyvsp[0].numd)){
            (yyval.txt) = "true";  
        }
        else{
            (yyval.txt) = "false";
        }
    }
#line 2128 "bisonFile.tab.c"
    break;

  case 68: /* condition: expr isSmallerEqual expr  */
#line 682 "bisonFile.y"
                               {
        if((yyvsp[-2].numd) <= (yyvsp[0].numd)){
            (yyval.txt) = "true";  
        }
        else{
            (yyval.txt) = "false";
        }
    }
#line 2141 "bisonFile.tab.c"
    break;

  case 69: /* condition: expr isNotEqual expr  */
#line 690 "bisonFile.y"
                           {
        if((yyvsp[-2].numd) != (yyvsp[0].numd)){
            (yyval.txt) = "true";  
        }
        else{
            (yyval.txt) = "false";
        }
    }
#line 2154 "bisonFile.tab.c"
    break;

  case 70: /* condition: expr  */
#line 698 "bisonFile.y"
          {
        if((yyvsp[0].numd)>0){
            (yyval.txt) = "true";
        }
        else{
            (yyval.txt) = "false";
        }
    }
#line 2167 "bisonFile.tab.c"
    break;

  case 71: /* value: varName  */
#line 710 "bisonFile.y"
    {
            int i = find((yyvsp[0].txt));
            if(i!=-1){
                if(!strcmp(symbolTable[i].type, "purno")){    
                    printf("SHOW: %s => %d\n",(yyvsp[0].txt),symbolTable[i].intValue);
                }
                else if(!strcmp(symbolTable[i].type, "shobdo")){    
                    printf("SHOW: %s => %s\n",(yyvsp[0].txt),symbolTable[i].strValue);
                }
                if(!strcmp(symbolTable[i].type, "vogno")){    
                    printf("SHOW: %s => %f\n",(yyvsp[0].txt),symbolTable[i].doubleValue);
                }
            
            }

            else{
                printf("line %d => Not Exist: Variable %s\n",yylineno,(yyvsp[0].txt));
            }
    }
#line 2191 "bisonFile.tab.c"
    break;

  case 72: /* expr: val  */
#line 730 "bisonFile.y"
          {(yyval.numd) = (yyvsp[0].numd);}
#line 2197 "bisonFile.tab.c"
    break;

  case 73: /* expr: expr '+' expr  */
#line 731 "bisonFile.y"
                    {(yyval.numd) = (yyvsp[-2].numd) + (yyvsp[0].numd);}
#line 2203 "bisonFile.tab.c"
    break;

  case 74: /* expr: expr '-' expr  */
#line 732 "bisonFile.y"
                    {(yyval.numd) = (yyvsp[-2].numd) - (yyvsp[0].numd);}
#line 2209 "bisonFile.tab.c"
    break;

  case 75: /* expr: expr '*' expr  */
#line 733 "bisonFile.y"
                    {(yyval.numd) = (yyvsp[-2].numd) * (yyvsp[0].numd);}
#line 2215 "bisonFile.tab.c"
    break;

  case 76: /* expr: expr '/' expr  */
#line 734 "bisonFile.y"
                    {(yyval.numd) = (yyvsp[-2].numd) / (yyvsp[0].numd);}
#line 2221 "bisonFile.tab.c"
    break;

  case 77: /* expr: expr mod expr  */
#line 736 "bisonFile.y"
        {
            int val1 = (int)(yyvsp[-2].numd);
            int val2 = (int)(yyvsp[0].numd);
            float val3 = (val1%val2)*1.0;
            (yyval.numd) = val3;
        }
#line 2232 "bisonFile.tab.c"
    break;

  case 78: /* val: number  */
#line 743 "bisonFile.y"
            {(yyval.numd) = (yyvsp[0].num)*1.0;}
#line 2238 "bisonFile.tab.c"
    break;

  case 79: /* val: numberd  */
#line 744 "bisonFile.y"
              {(yyval.numd) = (yyvsp[0].numd);}
#line 2244 "bisonFile.tab.c"
    break;

  case 80: /* val: qt varName qt  */
#line 746 "bisonFile.y"
        {
                printf("line %d => Not a number: %s => shobdo\n",yylineno, (yyvsp[-1].txt));
                (yyval.numd) = 0.0;
            }
#line 2253 "bisonFile.tab.c"
    break;

  case 81: /* val: varName  */
#line 751 "bisonFile.y"
        {
            int i = find((yyvsp[0].txt));
            if(i!=-1){
                if(!strcmp(symbolTable[i].type, "purno")){    
                    (yyval.numd) = symbolTable[i].intValue * 1.0;
                }
                if(!strcmp(symbolTable[i].type, "vogno")){    
                    (yyval.numd) = symbolTable[i].doubleValue;
                }
                else{
                    printf("line %d => Not a number: %s => shobdo \n",yylineno, (yyvsp[0].txt));
                    (yyval.numd) = 0.0;
                }           
            }
            else{
                printf("line %d => Not Declared: Variable %s\n",yylineno,(yyvsp[0].txt));
            }
        }
#line 2276 "bisonFile.tab.c"
    break;

  case 83: /* dataType: purno  */
#line 773 "bisonFile.y"
                 {isPurno = 1; (yyval.txt) = "purno";}
#line 2282 "bisonFile.tab.c"
    break;

  case 84: /* dataType: vogno  */
#line 774 "bisonFile.y"
                {isPurno = 0;(yyval.txt) = "vogno";}
#line 2288 "bisonFile.tab.c"
    break;

  case 85: /* dataType: shobdo  */
#line 775 "bisonFile.y"
                 {isPurno = -1;(yyval.txt) = "shobdo";}
#line 2294 "bisonFile.tab.c"
    break;

  case 88: /* oneVar: varName  */
#line 781 "bisonFile.y"
        {
            if (find((yyvsp[0].txt)) != -1) {
                    printf("line %d => Already declared: Variable %s \n",yylineno, (yyvsp[0].txt));
            } 
            else{
                if(isPurno==1){
                    add((yyvsp[0].txt),"purno",0,0.0,"");
                    printf("Created: %s => purno\n", (yyvsp[0].txt));
                }
                else if(isPurno==0){
                    add((yyvsp[0].txt),"vogno",0,0.0,"");
                    printf("Created : %s =>  vogno\n",(yyvsp[0].txt));
                }
                else if(isPurno==-1){
                    add((yyvsp[0].txt),"shobdo",0,0.0,"");
                    printf("Created : %s =>  shobdo\n",(yyvsp[0].txt));
                }
            }
        }
#line 2318 "bisonFile.tab.c"
    break;

  case 89: /* oneVar: varName '=' number  */
#line 801 "bisonFile.y"
                             {
                    if (find((yyvsp[-2].txt)) != -1) {
                        printf("line %d => Already declared: Variable %s \n",yylineno, (yyvsp[-2].txt));
                    } 
                    else{
                        if(isPurno==1){
                            add((yyvsp[-2].txt),"purno",(yyvsp[0].num),0.0,"");
                            printf("Created: %s: %d => purno\n", (yyvsp[-2].txt),(yyvsp[0].num));
                        }
                        else if(isPurno==0){
                            printf("line %d => Mismatch: %s => vogno , value %d: purno\n",yylineno,(yyvsp[-2].txt), (yyvsp[0].num));
                        }
                        else if(isPurno==-1){
                            printf("line %d => Mismatch: %s => shobdo , value %d: purno\n",yylineno,(yyvsp[-2].txt), (yyvsp[0].num));
                        }
                    }
                }
#line 2340 "bisonFile.tab.c"
    break;

  case 90: /* oneVar: varName '=' numberd  */
#line 818 "bisonFile.y"
                              {
                    if (find((yyvsp[-2].txt)) != -1) {
                        printf("line %d => Already declared: Variable %s \n",yylineno, (yyvsp[-2].txt));
                    } 
                    else{
                        if(isPurno==0){
                            add((yyvsp[-2].txt),"vogno",0,(yyvsp[0].numd),"");
                            printf("Created: %s: %f => vogno\n", (yyvsp[-2].txt),(yyvsp[0].numd));
                        }
                        else if(isPurno == 1){
                            printf("line %d => Mismatch: %s => purno , value %f: vogno\n",yylineno,(yyvsp[-2].txt),(yyvsp[0].numd));
                        }
                        else if(isPurno ==-1) {
                            printf("line %d => Mismatch: %s => shobdo , value %f: vogno\n",yylineno,(yyvsp[-2].txt),(yyvsp[0].numd));
                        }
                    }
            }
#line 2362 "bisonFile.tab.c"
    break;

  case 91: /* oneVar: varName '=' qt varName qt  */
#line 836 "bisonFile.y"
                                    {
                    if (find((yyvsp[-4].txt)) != -1) {
                        printf("line %d => Already declared: Variable %s \n",yylineno, (yyvsp[-4].txt));
                    } 
                    else{
                        if(isPurno==-1){
                            add((yyvsp[-4].txt),"shobdo",0,0.0,(yyvsp[-1].txt));
                            printf("Created: %s: %s => shobdo\n", (yyvsp[-4].txt),(yyvsp[-1].txt));
                        }
                        else if (isPurno==1){
                            printf("line %d => Mismatch: %s => purno , value %s: shobdo\n",yylineno,(yyvsp[-4].txt),(yyvsp[-1].txt));
                        }
                        else if (isPurno==0){
                            printf("line %d => Mismatch: %s => vogno , value %s: shobdo\n",yylineno,(yyvsp[-4].txt),(yyvsp[-1].txt));
                        }
                    }
        }
#line 2384 "bisonFile.tab.c"
    break;

  case 92: /* variableValueAssign: varName '=' number EOL  */
#line 855 "bisonFile.y"
                        {
                                        int i = find((yyvsp[-3].txt));
                                        if(i!=-1){
                                            if(!strcmp(symbolTable[i].type, "purno")){
                                                update(i,(yyvsp[-1].num),0.0,"");
                                                printf("Assign: %d => variable %s\n",(yyvsp[-1].num),(yyvsp[-3].txt));
                                            }
                                            else{
                                                printf("line %d => Mismatch: %d is purno =>variable %s is %s\n",yylineno,(yyvsp[-1].num),(yyvsp[-3].txt),symbolTable[i].type);
                                            }
                                        }
                                        else{
                                            printf("line %d => Not Declared : variable %s\n",yylineno,(yyvsp[-3].txt));
                                        }
                                    }
#line 2404 "bisonFile.tab.c"
    break;

  case 93: /* variableValueAssign: varName '=' numberd EOL  */
#line 870 "bisonFile.y"
                                             {
                                        int i = find((yyvsp[-3].txt));
                                        if(i!=-1){
                                            if(!strcmp(symbolTable[i].type, "vogno")){
                                                update(i,0,(yyvsp[-1].numd),"");                                                    
                                                printf("Assign: %f => variable %s\n",(yyvsp[-1].numd),(yyvsp[-3].txt));
                                            }
                                            else{
                                                printf("line %d => Mismatch: %f is vogno =>variable %s is %s\n",yylineno,(yyvsp[-1].numd),(yyvsp[-3].txt),symbolTable[i].type);
                                            }
                                        }
                                        else{
                                            printf("line %d => Not Declared : variable %s\n",yylineno,(yyvsp[-3].txt));
                                        }
                                    }
#line 2424 "bisonFile.tab.c"
    break;

  case 94: /* variableValueAssign: varName '=' expr EOL  */
#line 886 "bisonFile.y"
                                          {
                                        int i = find((yyvsp[-3].txt));
                                        if(i!=-1){
                                            if(!strcmp(symbolTable[i].type, "vogno")){
                                                update(i,0,(yyvsp[-1].numd),"");
                                                printf("Assign: %f => variable %s\n",(yyvsp[-1].numd),(yyvsp[-3].txt));
                                            }
                                            else {
                                                int val = (int)(yyvsp[-1].numd);
                                                update(i,val,0.0,"");
                                                printf("Assign: %d => variable %s\n",val,(yyvsp[-3].txt));
                                            }
                                        }
                                        else{
                                            printf("line %d => Not Declared : variable %s\n",yylineno,(yyvsp[-3].txt));
                                        }
                                    }
#line 2446 "bisonFile.tab.c"
    break;

  case 95: /* variableValueAssign: varName '=' qt varName qt EOL  */
#line 904 "bisonFile.y"
                                                  {
                                    int i = find((yyvsp[-5].txt));
                                    if(i!=-1){
                                        if(!strcmp(symbolTable[i].type, "shobdo")){
                                            update(i,0,0.0,(yyvsp[-2].txt));
                                            printf("Assign: %s => variable %s\n",(yyvsp[-2].txt),(yyvsp[-5].txt));
                                        }
                                        else {
                                            printf("line %d => Mismatch: %s is shobdo =>variable %s is %s\n",yylineno,(yyvsp[-2].txt),(yyvsp[-5].txt),symbolTable[i].type);
                                        }
                                        
                                    }
                                    else{
                                        printf("line %d => Not Declared : variable %s\n",yylineno,(yyvsp[-5].txt));
                                    }
                    }
#line 2467 "bisonFile.tab.c"
    break;


#line 2471 "bisonFile.tab.c"

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

#line 921 "bisonFile.y"


int yyerror(char *s) {
    printf("Error at line %d: => %s\n",yylineno,s);
    return 0;
}

void yyexit(const char *message) {
    fprintf(stderr, "Exit: %s\n", message);
    exit(EXIT_SUCCESS);
}

int main(void) {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    yyparse();

    printSymbolTable();
    printKeywords();
}
