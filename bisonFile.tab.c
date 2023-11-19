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
#line 1 "bisonFile.y"

#include<stdio.h>
#include <string.h>
int yyerror(char *s);
extern int yylex();
extern int yyparse();
extern FILE *yyin;
extern FILE *yyout;

#define MAX_SYMBOLS 100

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
    printf("\nSymbol Table:\n");
    for (int i = 0; i < symbolCount; ++i) {
        if(!strcmp(symbolTable[i].type, "purno")){
            printf("Name: %s,Type: %s,Value: %d\n",
               symbolTable[i].name,symbolTable[i].type,
               symbolTable[i].intValue);
        }

        if(!strcmp(symbolTable[i].type, "vogno")){
            printf("Name: %s,Type: %s,Value: %f\n",
               symbolTable[i].name,symbolTable[i].type,
               symbolTable[i].doubleValue);
        }

        if(!strcmp(symbolTable[i].type, "shobdo")){
            printf("Name: %s,Type: %s,Value: %s\n",
               symbolTable[i].name,symbolTable[i].type,
               symbolTable[i].strValue);
        }
        
    }
}

int isPurno = 0;


#line 147 "bisonFile.tab.c"

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
  YYSYMBOL_isEqual = 16,                   /* isEqual  */
  YYSYMBOL_isLarge = 17,                   /* isLarge  */
  YYSYMBOL_isLargeEqual = 18,              /* isLargeEqual  */
  YYSYMBOL_isSmaller = 19,                 /* isSmaller  */
  YYSYMBOL_isSmallerEqual = 20,            /* isSmallerEqual  */
  YYSYMBOL_isNotEqual = 21,                /* isNotEqual  */
  YYSYMBOL_qt = 22,                        /* qt  */
  YYSYMBOL_LOOP = 23,                      /* LOOP  */
  YYSYMBOL_INC = 24,                       /* INC  */
  YYSYMBOL_DEC = 25,                       /* DEC  */
  YYSYMBOL_FUNC = 26,                      /* FUNC  */
  YYSYMBOL_headerName = 27,                /* headerName  */
  YYSYMBOL_varName = 28,                   /* varName  */
  YYSYMBOL_number = 29,                    /* number  */
  YYSYMBOL_numberd = 30,                   /* numberd  */
  YYSYMBOL_31_ = 31,                       /* '+'  */
  YYSYMBOL_32_ = 32,                       /* '-'  */
  YYSYMBOL_33_ = 33,                       /* '/'  */
  YYSYMBOL_34_ = 34,                       /* '*'  */
  YYSYMBOL_35_ = 35,                       /* '('  */
  YYSYMBOL_36_ = 36,                       /* ')'  */
  YYSYMBOL_37_ = 37,                       /* '{'  */
  YYSYMBOL_38_ = 38,                       /* '}'  */
  YYSYMBOL_39_ = 39,                       /* ','  */
  YYSYMBOL_40_ = 40,                       /* '='  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_input = 42,                     /* input  */
  YYSYMBOL_functions = 43,                 /* functions  */
  YYSYMBOL_func = 44,                      /* func  */
  YYSYMBOL_cmnt = 45,                      /* cmnt  */
  YYSYMBOL_headers = 46,                   /* headers  */
  YYSYMBOL_header = 47,                    /* header  */
  YYSYMBOL_program = 48,                   /* program  */
  YYSYMBOL_start = 49,                     /* start  */
  YYSYMBOL_end = 50,                       /* end  */
  YYSYMBOL_statements = 51,                /* statements  */
  YYSYMBOL_statement = 52,                 /* statement  */
  YYSYMBOL_changer = 53,                   /* changer  */
  YYSYMBOL_loopOP = 54,                    /* loopOP  */
  YYSYMBOL_ifshuru = 55,                   /* ifshuru  */
  YYSYMBOL_condition = 56,                 /* condition  */
  YYSYMBOL_value = 57,                     /* value  */
  YYSYMBOL_expr = 58,                      /* expr  */
  YYSYMBOL_val = 59,                       /* val  */
  YYSYMBOL_multiVariable = 60,             /* multiVariable  */
  YYSYMBOL_dataType = 61,                  /* dataType  */
  YYSYMBOL_varNames = 62,                  /* varNames  */
  YYSYMBOL_oneVar = 63,                    /* oneVar  */
  YYSYMBOL_variableValueAssign = 64        /* variableValueAssign  */
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
#define YYLAST   144

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  132

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   285


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
      35,    36,    34,    31,    39,    32,     2,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    40,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   100,   100,   101,   102,   104,   105,   106,   107,   109,
     110,   111,   113,   115,   116,   118,   119,   122,   123,   125,
     126,   127,   128,   129,   130,   131,   135,   179,   181,   182,
     184,   185,   186,   187,   190,   191,   199,   207,   215,   223,
     231,   242,   262,   263,   264,   265,   266,   267,   274,   275,
     276,   280,   300,   302,   303,   304,   306,   307,   309,   325,
     342,   360,   378,   393,   409,   427
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
  "shuru", "sesh", "IF", "ELSE", "isEqual", "isLarge", "isLargeEqual",
  "isSmaller", "isSmallerEqual", "isNotEqual", "qt", "LOOP", "INC", "DEC",
  "FUNC", "headerName", "varName", "number", "numberd", "'+'", "'-'",
  "'/'", "'*'", "'('", "')'", "'{'", "'}'", "','", "'='", "$accept",
  "input", "functions", "func", "cmnt", "headers", "header", "program",
  "start", "end", "statements", "statement", "changer", "loopOP",
  "ifshuru", "condition", "value", "expr", "val", "multiVariable",
  "dataType", "varNames", "oneVar", "variableValueAssign", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-46)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      19,   -19,   -46,    10,    19,    -8,    19,   -46,   -46,   -46,
     -46,    -1,    21,     9,   -46,    98,   -46,   -46,     2,   -46,
     -46,   -46,   -46,   -46,    52,    11,   -46,     8,   -14,   -46,
      27,    98,    12,   -46,    17,   -46,    18,    28,   -46,   -46,
     -46,    -3,   -46,   -46,    55,    34,    35,    89,   -46,   -46,
     -46,    52,    33,   -46,    -5,    53,    69,   -46,    52,    52,
      52,    52,    52,   -46,   105,    83,    65,    88,    91,    26,
      68,    67,   -10,   -46,    17,    98,   -46,   -46,    45,    45,
     100,   100,   -46,   -46,   -46,   -46,    52,   -46,    86,   -46,
     -46,   -46,    90,    52,    52,    52,    52,    52,    52,    92,
     -46,   -46,   -46,    93,    32,   122,    98,    82,    82,    82,
      82,    82,    82,   107,   -46,     0,   -46,    94,   -46,   -46,
     -46,    52,   115,    36,    96,    97,    98,    98,    99,   101,
     -46,   -46
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     8,     0,     0,    13,    10,    12,     1,     4,
      15,     0,    13,     6,     2,    19,    11,     9,     0,     3,
       5,    53,    54,    55,     0,     0,    34,     0,     0,    20,
       0,    18,     0,    21,     0,    22,     0,     0,    51,    48,
      49,     0,    42,    41,     0,     0,     0,     0,    16,    14,
      17,     0,    58,    52,     0,     0,     0,    23,     0,     0,
       0,     0,     0,    24,     0,     0,     0,    48,    49,     0,
       0,     0,     0,    57,     0,    19,    50,    47,    43,    44,
      46,    45,    30,    31,    32,    33,     0,    27,     0,    62,
      63,    64,     0,     0,     0,     0,     0,     0,     0,     0,
      59,    60,    56,     0,     0,    50,    19,    35,    36,    37,
      38,    39,    40,     0,     7,     0,    65,     0,    61,    28,
      29,     0,     0,     0,     0,     0,    19,    19,     0,     0,
      25,    26
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -46,   131,   123,   -46,     5,   132,   -46,   128,   -46,   -46,
     -31,   -46,   -46,   -46,   -46,   -46,   -46,   -45,   -46,   -46,
     -46,    70,   -46,   -46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,    12,    13,    29,     5,     6,    14,    15,    49,
      30,    31,   121,    86,    32,    70,    44,    41,    42,    33,
      34,    53,    54,    35
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      50,    73,    69,    57,    10,     4,    71,    58,     7,     4,
       8,    16,    99,    77,    78,    79,    80,    81,    11,   100,
     101,    46,     1,     2,   119,   120,    47,    18,    59,    60,
      61,    62,    91,    10,    74,    11,    58,    36,   115,    43,
      48,   104,    58,    45,   103,    52,    58,    51,   107,   108,
     109,   110,   111,   112,    55,    58,    56,    59,    60,    61,
      62,    63,    64,    59,    60,    61,    62,    59,    60,    61,
      62,    65,   125,    72,    37,   117,   123,    58,    61,    62,
      38,    39,    40,    93,    94,    95,    96,    97,    98,    87,
      75,    76,    58,    88,    89,   128,   129,    90,    59,    60,
      61,    62,     2,    21,    92,    22,    23,    24,   105,    25,
      58,    66,    26,    59,    60,    61,    62,    38,    67,    68,
     113,    27,    82,    83,    84,    85,    28,   106,   116,   118,
     124,   114,   122,   126,   127,     9,    20,   130,    17,   131,
      19,     0,     0,     0,   102
};

static const yytype_int8 yycheck[] =
{
      31,     6,    47,     6,    12,     0,    51,    10,    27,     4,
       0,     6,    22,    58,    59,    60,    61,    62,    26,    29,
      30,    35,     3,     4,    24,    25,    40,    28,    31,    32,
      33,    34,     6,    12,    39,    26,    10,    35,     6,    28,
      13,    86,    10,    35,    75,    28,    10,    35,    93,    94,
      95,    96,    97,    98,    36,    10,    28,    31,    32,    33,
      34,     6,    28,    31,    32,    33,    34,    31,    32,    33,
      34,    36,    36,    40,    22,   106,   121,    10,    33,    34,
      28,    29,    30,    16,    17,    18,    19,    20,    21,     6,
      37,    22,    10,    28,     6,   126,   127,     6,    31,    32,
      33,    34,     4,     5,    36,     7,     8,     9,    22,    11,
      10,    22,    14,    31,    32,    33,    34,    28,    29,    30,
      28,    23,    17,    18,    19,    20,    28,    37,     6,    22,
      15,    38,    38,    37,    37,     4,    13,    38,     6,    38,
      12,    -1,    -1,    -1,    74
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,    42,    45,    46,    47,    27,     0,    42,
      12,    26,    43,    44,    48,    49,    45,    46,    28,    48,
      43,     5,     7,     8,     9,    11,    14,    23,    28,    45,
      51,    52,    55,    60,    61,    64,    35,    22,    28,    29,
      30,    58,    59,    28,    57,    35,    35,    40,    13,    50,
      51,    35,    28,    62,    63,    36,    28,     6,    10,    31,
      32,    33,    34,     6,    28,    36,    22,    29,    30,    58,
      56,    58,    40,     6,    39,    37,    22,    58,    58,    58,
      58,    58,    17,    18,    19,    20,    54,     6,    28,     6,
       6,     6,    36,    16,    17,    18,    19,    20,    21,    22,
      29,    30,    62,    51,    58,    22,    37,    58,    58,    58,
      58,    58,    58,    28,    38,     6,     6,    51,    22,    24,
      25,    53,    38,    58,    15,    36,    37,    37,    51,    51,
      38,    38
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    42,    42,    43,    43,    44,    45,    46,
      46,    46,    47,    48,    48,    49,    50,    51,    51,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    53,    53,
      54,    54,    54,    54,    55,    56,    56,    56,    56,    56,
      56,    57,    58,    58,    58,    58,    58,    58,    59,    59,
      59,    59,    60,    61,    61,    61,    62,    62,    63,    63,
      63,    63,    64,    64,    64,    64
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     2,     2,     1,     7,     1,     2,
       1,     2,     2,     0,     3,     1,     1,     2,     1,     0,
       1,     1,     1,     3,     3,    11,    12,     4,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     1,     1,     3,     3,     3,     3,     3,     1,     1,
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
  case 7: /* func: FUNC varName '(' ')' '{' statements '}'  */
#line 106 "bisonFile.y"
                                            {printf("%s Function declared\n",(yyvsp[-5].txt));}
#line 1284 "bisonFile.tab.c"
    break;

  case 8: /* cmnt: comment  */
#line 107 "bisonFile.y"
              {printf("This is a comment\n");}
#line 1290 "bisonFile.tab.c"
    break;

  case 12: /* header: headerStart headerName  */
#line 113 "bisonFile.y"
                               {{printf("Included: %s\n",(yyvsp[0].txt));}}
#line 1296 "bisonFile.tab.c"
    break;

  case 15: /* start: shuru  */
#line 118 "bisonFile.y"
              {printf("-------------Program started--------------\n");}
#line 1302 "bisonFile.tab.c"
    break;

  case 16: /* end: sesh  */
#line 119 "bisonFile.y"
           {printf("-------------Program Ended--------------\n");}
#line 1308 "bisonFile.tab.c"
    break;

  case 23: /* statement: eval expr EOL  */
#line 129 "bisonFile.y"
                        {printf("Evaluated result is : %f\n",(yyvsp[-1].numd));}
#line 1314 "bisonFile.tab.c"
    break;

  case 25: /* statement: ifshuru '(' condition ')' '{' statements '}' ELSE '{' statements '}'  */
#line 131 "bisonFile.y"
                                                                               {
                ifcount++;
                printf("Finished: %d.IF-ELSE - %s \n",ifcount,(yyvsp[-8].txt));
        }
#line 1323 "bisonFile.tab.c"
    break;

  case 26: /* statement: LOOP '(' varName loopOP expr EOL changer expr ')' '{' statements '}'  */
#line 135 "bisonFile.y"
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
                                            printf("Loop executed for %d\n",m);
                                        }
                                    }
                                    if(!strcmp((yyvsp[-8].txt),">=")){
                                        for(int m = x;m>=y;m+=incSize){
                                            printf("Loop executed for %d\n",m);
                                        }
                                    }
                                    if(!strcmp((yyvsp[-8].txt),">")){
                                        for(int m = x;m>y;m+=incSize){
                                            printf("Loop executed for %d\n",m);
                                        }
                                    }
                                    if(!strcmp((yyvsp[-8].txt),"<")){
                                        for(int m = x;m<y;m+=incSize){
                                            printf("Loop executed for %d\n",m);
                                        }
                                    }
                                }
                            }
#line 1372 "bisonFile.tab.c"
    break;

  case 27: /* statement: varName '(' ')' EOL  */
#line 179 "bisonFile.y"
                              {printf("%s Function Called\n",(yyvsp[-3].txt));}
#line 1378 "bisonFile.tab.c"
    break;

  case 28: /* changer: INC  */
#line 181 "bisonFile.y"
                     {(yyval.txt) = "inc";}
#line 1384 "bisonFile.tab.c"
    break;

  case 29: /* changer: DEC  */
#line 182 "bisonFile.y"
                     {(yyval.txt) = "dec";}
#line 1390 "bisonFile.tab.c"
    break;

  case 30: /* loopOP: isLarge  */
#line 184 "bisonFile.y"
                        {(yyval.txt) = ">";}
#line 1396 "bisonFile.tab.c"
    break;

  case 31: /* loopOP: isLargeEqual  */
#line 185 "bisonFile.y"
                           {(yyval.txt) = ">=";}
#line 1402 "bisonFile.tab.c"
    break;

  case 32: /* loopOP: isSmaller  */
#line 186 "bisonFile.y"
                        {(yyval.txt) = "<";}
#line 1408 "bisonFile.tab.c"
    break;

  case 33: /* loopOP: isSmallerEqual  */
#line 187 "bisonFile.y"
                             {(yyval.txt) = "<=";}
#line 1414 "bisonFile.tab.c"
    break;

  case 34: /* ifshuru: IF  */
#line 190 "bisonFile.y"
            {printf("Started: IF BLOCK\n");}
#line 1420 "bisonFile.tab.c"
    break;

  case 35: /* condition: expr isEqual expr  */
#line 191 "bisonFile.y"
                              {
        if((yyvsp[-2].numd) == (yyvsp[0].numd)){
            (yyval.txt) = "true";  
        }
        else{
            (yyval.txt) = "false";
        }
    }
#line 1433 "bisonFile.tab.c"
    break;

  case 36: /* condition: expr isLarge expr  */
#line 199 "bisonFile.y"
                        {
        if((yyvsp[-2].numd) > (yyvsp[0].numd)){
            (yyval.txt) = "true";  
        }
        else{
            (yyval.txt) = "false";
        }
    }
#line 1446 "bisonFile.tab.c"
    break;

  case 37: /* condition: expr isLargeEqual expr  */
#line 207 "bisonFile.y"
                             {
        if((yyvsp[-2].numd) >= (yyvsp[0].numd)){
            (yyval.txt) = "true";  
        }
        else{
            (yyval.txt) = "false";
        }
    }
#line 1459 "bisonFile.tab.c"
    break;

  case 38: /* condition: expr isSmaller expr  */
#line 215 "bisonFile.y"
                          {
        if((yyvsp[-2].numd) < (yyvsp[0].numd)){
            (yyval.txt) = "true";  
        }
        else{
            (yyval.txt) = "false";
        }
    }
#line 1472 "bisonFile.tab.c"
    break;

  case 39: /* condition: expr isSmallerEqual expr  */
#line 223 "bisonFile.y"
                               {
        if((yyvsp[-2].numd) <= (yyvsp[0].numd)){
            (yyval.txt) = "true";  
        }
        else{
            (yyval.txt) = "false";
        }
    }
#line 1485 "bisonFile.tab.c"
    break;

  case 40: /* condition: expr isNotEqual expr  */
#line 231 "bisonFile.y"
                           {
        if((yyvsp[-2].numd) != (yyvsp[0].numd)){
            (yyval.txt) = "true";  
        }
        else{
            (yyval.txt) = "false";
        }
    }
#line 1498 "bisonFile.tab.c"
    break;

  case 41: /* value: varName  */
#line 242 "bisonFile.y"
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
                printf("Not Exist: Variable %s\n",(yyvsp[0].txt));
            }
}
#line 1522 "bisonFile.tab.c"
    break;

  case 42: /* expr: val  */
#line 262 "bisonFile.y"
          {(yyval.numd) = (yyvsp[0].numd);}
#line 1528 "bisonFile.tab.c"
    break;

  case 43: /* expr: expr '+' expr  */
#line 263 "bisonFile.y"
                    {(yyval.numd) = (yyvsp[-2].numd) + (yyvsp[0].numd);}
#line 1534 "bisonFile.tab.c"
    break;

  case 44: /* expr: expr '-' expr  */
#line 264 "bisonFile.y"
                    {(yyval.numd) = (yyvsp[-2].numd) - (yyvsp[0].numd);}
#line 1540 "bisonFile.tab.c"
    break;

  case 45: /* expr: expr '*' expr  */
#line 265 "bisonFile.y"
                    {(yyval.numd) = (yyvsp[-2].numd) * (yyvsp[0].numd);}
#line 1546 "bisonFile.tab.c"
    break;

  case 46: /* expr: expr '/' expr  */
#line 266 "bisonFile.y"
                    {(yyval.numd) = (yyvsp[-2].numd) / (yyvsp[0].numd);}
#line 1552 "bisonFile.tab.c"
    break;

  case 47: /* expr: expr mod expr  */
#line 267 "bisonFile.y"
                    {
        int val1 = (int)(yyvsp[-2].numd);
        int val2 = (int)(yyvsp[0].numd);
        float val3 = (val1%val2)*1.0;
        (yyval.numd) = val3;
    }
#line 1563 "bisonFile.tab.c"
    break;

  case 48: /* val: number  */
#line 274 "bisonFile.y"
            {(yyval.numd) = (yyvsp[0].num)*1.0;}
#line 1569 "bisonFile.tab.c"
    break;

  case 49: /* val: numberd  */
#line 275 "bisonFile.y"
              {(yyval.numd) = (yyvsp[0].numd);}
#line 1575 "bisonFile.tab.c"
    break;

  case 50: /* val: qt varName qt  */
#line 276 "bisonFile.y"
                    {
                printf("Not a number: %s => shobdo\n",(yyvsp[-1].txt));
                (yyval.numd) = 0.0;
            }
#line 1584 "bisonFile.tab.c"
    break;

  case 51: /* val: varName  */
#line 280 "bisonFile.y"
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
                    printf("Not a number: %s => shobdo \n",(yyvsp[0].txt));
                    (yyval.numd) = 0.0;
                }           
            }
            else{
                printf("Not Declared: Variable %s\n",(yyvsp[0].txt));
            }
        }
#line 1607 "bisonFile.tab.c"
    break;

  case 53: /* dataType: purno  */
#line 302 "bisonFile.y"
                 {isPurno = 1;}
#line 1613 "bisonFile.tab.c"
    break;

  case 54: /* dataType: vogno  */
#line 303 "bisonFile.y"
                {isPurno = 0;}
#line 1619 "bisonFile.tab.c"
    break;

  case 55: /* dataType: shobdo  */
#line 304 "bisonFile.y"
                 {isPurno = -1;}
#line 1625 "bisonFile.tab.c"
    break;

  case 58: /* oneVar: varName  */
#line 309 "bisonFile.y"
                {
            if (find((yyvsp[0].txt)) != -1) {
                    printf("Already declared: Variable %s \n", (yyvsp[0].txt));
            } 
            else{
                if(isPurno){
                    add((yyvsp[0].txt),"purno",0,0.0,"");
                    printf("Created: %s => purno\n", (yyvsp[0].txt));
                }
                else{
                    add((yyvsp[0].txt),"vogno",0,0.0,"");
                    printf("Created : %s =>  vogno\n",(yyvsp[0].txt));
                }
            }
        }
#line 1645 "bisonFile.tab.c"
    break;

  case 59: /* oneVar: varName '=' number  */
#line 325 "bisonFile.y"
                             {
                    if (find((yyvsp[-2].txt)) != -1) {
                        printf("Already declared: Variable %s \n", (yyvsp[-2].txt));
                    } 
                    else{
                        if(isPurno==1){
                            add((yyvsp[-2].txt),"purno",(yyvsp[0].num),0.0,"");
                            printf("Created: %s: %d => purno\n", (yyvsp[-2].txt),(yyvsp[0].num));
                        }
                        else if(isPurno==0){
                            printf("Mismatch: %s => vogno , value %d: purno\n",(yyvsp[-2].txt), (yyvsp[0].num));
                        }
                        else if(isPurno==-1){
                            printf("Mismatch: %s => shobdo , value %d: purno\n",(yyvsp[-2].txt), (yyvsp[0].num));
                        }
                    }
                }
#line 1667 "bisonFile.tab.c"
    break;

  case 60: /* oneVar: varName '=' numberd  */
#line 342 "bisonFile.y"
                              {
                    if (find((yyvsp[-2].txt)) != -1) {
                        printf("Already declared: Variable %s \n", (yyvsp[-2].txt));
                    } 
                    else{
                        if(isPurno==0){
                            add((yyvsp[-2].txt),"vogno",0,(yyvsp[0].numd),"");
                            printf("Created: %s: %f => vogno\n", (yyvsp[-2].txt),(yyvsp[0].numd));
                        }
                        else if(isPurno == 1){
                            printf("Mismatch: %s => purno , value %f: vogno\n",(yyvsp[-2].txt),(yyvsp[0].numd));
                        }
                        else if(isPurno ==-1) {
                            printf("Mismatch: %s => shobdo , value %f: vogno\n",(yyvsp[-2].txt),(yyvsp[0].numd));
                        }
                    }
            }
#line 1689 "bisonFile.tab.c"
    break;

  case 61: /* oneVar: varName '=' qt varName qt  */
#line 360 "bisonFile.y"
                                    {
                    if (find((yyvsp[-4].txt)) != -1) {
                        printf("Already declared: Variable %s \n", (yyvsp[-4].txt));
                    } 
                    else{
                        if(isPurno==-1){
                            add((yyvsp[-4].txt),"shobdo",0,0.0,(yyvsp[-1].txt));
                            printf("Created: %s: %s => shobdo\n", (yyvsp[-4].txt),(yyvsp[-1].txt));
                        }
                        else if (isPurno==1){
                            printf("Mismatch: %s => purno , value %s: shobdo\n",(yyvsp[-4].txt),(yyvsp[-1].txt));
                        }
                        else if (isPurno==0){
                            printf("Mismatch: %s => vogno , value %s: shobdo\n",(yyvsp[-4].txt),(yyvsp[-1].txt));
                        }
                    }
        }
#line 1711 "bisonFile.tab.c"
    break;

  case 62: /* variableValueAssign: varName '=' number EOL  */
#line 378 "bisonFile.y"
                                             {
                                        int i = find((yyvsp[-3].txt));
                                        if(i!=-1){
                                            if(!strcmp(symbolTable[i].type, "purno")){
                                                update(i,(yyvsp[-1].num),0.0,"");
                                                printf("Assign: %d => variable %s\n",(yyvsp[-1].num),(yyvsp[-3].txt));
                                            }
                                            else{
                                                printf("Mismatch: %d is purno =>variable %s is %s\n",(yyvsp[-1].num),(yyvsp[-3].txt),symbolTable[i].type);
                                            }
                                        }
                                        else{
                                            printf("Not Declared : variable %s\n",(yyvsp[-3].txt));
                                        }
                                    }
#line 1731 "bisonFile.tab.c"
    break;

  case 63: /* variableValueAssign: varName '=' numberd EOL  */
#line 393 "bisonFile.y"
                                             {
                                        int i = find((yyvsp[-3].txt));
                                        if(i!=-1){
                                            if(!strcmp(symbolTable[i].type, "vogno")){
                                                update(i,0,(yyvsp[-1].numd),"");                                                    
                                                printf("Assign: %f => variable %s\n",(yyvsp[-1].numd),(yyvsp[-3].txt));
                                            }
                                            else{
                                                printf("Mismatch: %f is vogno =>variable %s is %s\n",(yyvsp[-1].numd),(yyvsp[-3].txt),symbolTable[i].type);
                                            }
                                        }
                                        else{
                                            printf("Not Declared : variable %s\n",(yyvsp[-3].txt));
                                        }
                                    }
#line 1751 "bisonFile.tab.c"
    break;

  case 64: /* variableValueAssign: varName '=' expr EOL  */
#line 409 "bisonFile.y"
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
                                            printf("Not Declared : variable %s\n",(yyvsp[-3].txt));
                                        }
                                    }
#line 1773 "bisonFile.tab.c"
    break;

  case 65: /* variableValueAssign: varName '=' qt varName qt EOL  */
#line 427 "bisonFile.y"
                                                  {
                                    int i = find((yyvsp[-5].txt));
                                    if(i!=-1){
                                        if(!strcmp(symbolTable[i].type, "shobdo")){
                                            update(i,0,0.0,(yyvsp[-2].txt));
                                            printf("Assign: %s => variable %s\n",(yyvsp[-2].txt),(yyvsp[-5].txt));
                                        }
                                        else {
                                            printf("Mismatch: %s is shobdo =>variable %s is %s\n",(yyvsp[-2].txt),(yyvsp[-5].txt),symbolTable[i].type);
                                        }
                                        
                                    }
                                    else{
                                        printf("Not Declared : variable %s\n",(yyvsp[-5].txt));
                                    }
                    }
#line 1794 "bisonFile.tab.c"
    break;


#line 1798 "bisonFile.tab.c"

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

#line 444 "bisonFile.y"



int yyerror(char *s) {
    printf("%s\n", s);
    return 0;
}

int main(void) {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    yyparse();

    printSymbolTable();
}
