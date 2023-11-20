/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_BISONFILE_TAB_H_INCLUDED
# define YY_YY_BISONFILE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    headerStart = 258,             /* headerStart  */
    comment = 259,                 /* comment  */
    purno = 260,                   /* purno  */
    EOL = 261,                     /* EOL  */
    vogno = 262,                   /* vogno  */
    shobdo = 263,                  /* shobdo  */
    eval = 264,                    /* eval  */
    mod = 265,                     /* mod  */
    show = 266,                    /* show  */
    shuru = 267,                   /* shuru  */
    sesh = 268,                    /* sesh  */
    IF = 269,                      /* IF  */
    ELSE = 270,                    /* ELSE  */
    concat = 271,                  /* concat  */
    isEqual = 272,                 /* isEqual  */
    isLarge = 273,                 /* isLarge  */
    isLargeEqual = 274,            /* isLargeEqual  */
    isSmaller = 275,               /* isSmaller  */
    isSmallerEqual = 276,          /* isSmallerEqual  */
    isNotEqual = 277,              /* isNotEqual  */
    qt = 278,                      /* qt  */
    compare = 279,                 /* compare  */
    LOOP = 280,                    /* LOOP  */
    INC = 281,                     /* INC  */
    DEC = 282,                     /* DEC  */
    FUNC = 283,                    /* FUNC  */
    copy = 284,                    /* copy  */
    len = 285,                     /* len  */
    FLOOR = 286,                   /* FLOOR  */
    CEIL = 287,                    /* CEIL  */
    SIN = 288,                     /* SIN  */
    COS = 289,                     /* COS  */
    TAN = 290,                     /* TAN  */
    LOG = 291,                     /* LOG  */
    POW = 292,                     /* POW  */
    LOG10 = 293,                   /* LOG10  */
    scan = 294,                    /* scan  */
    GCD = 295,                     /* GCD  */
    headerName = 296,              /* headerName  */
    varName = 297,                 /* varName  */
    number = 298,                  /* number  */
    numberd = 299                  /* numberd  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 104 "bisonFile.y"

    int num;
    char* txt;
    double numd;

#line 114 "bisonFile.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_BISONFILE_TAB_H_INCLUDED  */
