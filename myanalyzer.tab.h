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

#ifndef YY_YY_MYANALYZER_TAB_H_INCLUDED
# define YY_YY_MYANALYZER_TAB_H_INCLUDED
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
    KEYWORD_INTEGER = 258,         /* KEYWORD_INTEGER  */
    KEYWORD_SCALAR = 259,          /* KEYWORD_SCALAR  */
    KEYWORD_STR = 260,             /* KEYWORD_STR  */
    KEYWORD_BOOL = 261,            /* KEYWORD_BOOL  */
    KEYWORD_TRUE = 262,            /* KEYWORD_TRUE  */
    KEYWORD_FALSE = 263,           /* KEYWORD_FALSE  */
    KEYWORD_CONST = 264,           /* KEYWORD_CONST  */
    KEYWORD_IF = 265,              /* KEYWORD_IF  */
    KEYWORD_ELSE = 266,            /* KEYWORD_ELSE  */
    KEYWORD_ENDIF = 267,           /* KEYWORD_ENDIF  */
    KEYWORD_FOR = 268,             /* KEYWORD_FOR  */
    KEYWORD_IN = 269,              /* KEYWORD_IN  */
    KEYWORD_ENDFOR = 270,          /* KEYWORD_ENDFOR  */
    KEYWORD_WHILE = 271,           /* KEYWORD_WHILE  */
    KEYWORD_ENDWHILE = 272,        /* KEYWORD_ENDWHILE  */
    KEYWORD_BREAK = 273,           /* KEYWORD_BREAK  */
    KEYWORD_CONTINUE = 274,        /* KEYWORD_CONTINUE  */
    KEYWORD_DEF = 275,             /* KEYWORD_DEF  */
    KEYWORD_ENDDEF = 276,          /* KEYWORD_ENDDEF  */
    KEYWORD_MAIN = 277,            /* KEYWORD_MAIN  */
    KEYWORD_RETURN = 278,          /* KEYWORD_RETURN  */
    KEYWORD_COMP = 279,            /* KEYWORD_COMP  */
    KEYWORD_ENDCOMP = 280,         /* KEYWORD_ENDCOMP  */
    KEYWORD_OF = 281,              /* KEYWORD_OF  */
    DELIM_SEMICOLON = 282,         /* DELIM_SEMICOLON  */
    DELIM_COMMA = 283,             /* DELIM_COMMA  */
    DELIM_COLON = 284,             /* DELIM_COLON  */
    OP_HASHTAG = 285,              /* OP_HASHTAG  */
    CONST_INTEGER = 286,           /* CONST_INTEGER  */
    CONST_FLOAT = 287,             /* CONST_FLOAT  */
    CONST_STRING = 288,            /* CONST_STRING  */
    IDENTIFIER = 289,              /* IDENTIFIER  */
    DELIM_DOT = 290,               /* DELIM_DOT  */
    DELIM_LPAR = 291,              /* DELIM_LPAR  */
    DELIM_RPAR = 292,              /* DELIM_RPAR  */
    DELIM_LBRAC = 293,             /* DELIM_LBRAC  */
    DELIM_RBRAC = 294,             /* DELIM_RBRAC  */
    OP_POWER = 295,                /* OP_POWER  */
    OP_SIGN = 296,                 /* OP_SIGN  */
    OP_PROD = 297,                 /* OP_PROD  */
    OP_DIV = 298,                  /* OP_DIV  */
    OP_MOD = 299,                  /* OP_MOD  */
    OP_PLUS = 300,                 /* OP_PLUS  */
    OP_MINUS = 301,                /* OP_MINUS  */
    OP_SMALLER = 302,              /* OP_SMALLER  */
    OP_SMALLER_EQ = 303,           /* OP_SMALLER_EQ  */
    OP_BIGGER = 304,               /* OP_BIGGER  */
    OP_BIGGER_EQ = 305,            /* OP_BIGGER_EQ  */
    OP_EQUALS = 306,               /* OP_EQUALS  */
    OP_NOT_EQUALS = 307,           /* OP_NOT_EQUALS  */
    KEYWORD_NOT = 308,             /* KEYWORD_NOT  */
    KEYWORD_AND = 309,             /* KEYWORD_AND  */
    KEYWORD_OR = 310,              /* KEYWORD_OR  */
    OP_ASSIGN = 311,               /* OP_ASSIGN  */
    OP_ASSIGN_PLUS = 312,          /* OP_ASSIGN_PLUS  */
    OP_ASSIGN_MINUS = 313,         /* OP_ASSIGN_MINUS  */
    OP_ASSIGN_PROD = 314,          /* OP_ASSIGN_PROD  */
    OP_ASSIGN_DIV = 315,           /* OP_ASSIGN_DIV  */
    OP_ASSIGN_MOD = 316,           /* OP_ASSIGN_MOD  */
    OP_ASSIGN_ARR = 317            /* OP_ASSIGN_ARR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 20 "myanalyzer.y"

	char* str;
	double dbl;

#line 131 "myanalyzer.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_MYANALYZER_TAB_H_INCLUDED  */
