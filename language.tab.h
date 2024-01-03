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

#ifndef YY_YY_LANGUAGE_TAB_H_INCLUDED
# define YY_YY_LANGUAGE_TAB_H_INCLUDED
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
    ID_VAL = 258,                  /* ID_VAL  */
    INT_TYPE = 259,                /* INT_TYPE  */
    FLOAT_TYPE = 260,              /* FLOAT_TYPE  */
    CHAR_TYPE = 261,               /* CHAR_TYPE  */
    STRING_TYPE = 262,             /* STRING_TYPE  */
    BOOL_TYPE = 263,               /* BOOL_TYPE  */
    FOR_INST = 264,                /* FOR_INST  */
    WHILE_INST = 265,              /* WHILE_INST  */
    IF_INST = 266,                 /* IF_INST  */
    ELSE_INST = 267,               /* ELSE_INST  */
    DO_INST = 268,                 /* DO_INST  */
    INT_VAL = 269,                 /* INT_VAL  */
    FLOAT_VAL = 270,               /* FLOAT_VAL  */
    CHAR_VAL = 271,                /* CHAR_VAL  */
    STRING_VAL = 272,              /* STRING_VAL  */
    READ = 273,                    /* READ  */
    WRITE = 274,                   /* WRITE  */
    FUNC = 275,                    /* FUNC  */
    BEGIN_PRG = 276,               /* BEGIN_PRG  */
    FINISH_PRG = 277,              /* FINISH_PRG  */
    MAIN_PRG = 278,                /* MAIN_PRG  */
    EVAL = 279,                    /* EVAL  */
    TYPEOF = 280,                  /* TYPEOF  */
    PLUS = 281,                    /* PLUS  */
    MINUS = 282,                   /* MINUS  */
    MULT = 283,                    /* MULT  */
    DIV = 284,                     /* DIV  */
    MOD = 285,                     /* MOD  */
    ASSIGN = 286,                  /* ASSIGN  */
    INC = 287,                     /* INC  */
    DEC = 288                      /* DEC  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "language.y"

    char* string_val;
    char* math_op;

#line 102 "language.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_LANGUAGE_TAB_H_INCLUDED  */
