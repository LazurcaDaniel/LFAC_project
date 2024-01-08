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
    VOID_TYPE = 264,               /* VOID_TYPE  */
    CLASS_TYPE = 265,              /* CLASS_TYPE  */
    FOR_INST = 266,                /* FOR_INST  */
    WHILE_INST = 267,              /* WHILE_INST  */
    IF_INST = 268,                 /* IF_INST  */
    ELSE_INST = 269,               /* ELSE_INST  */
    DO_INST = 270,                 /* DO_INST  */
    INT_VAL = 271,                 /* INT_VAL  */
    FLOAT_VAL = 272,               /* FLOAT_VAL  */
    CHAR_VAL = 273,                /* CHAR_VAL  */
    STRING_VAL = 274,              /* STRING_VAL  */
    BOOL_VAL = 275,                /* BOOL_VAL  */
    READ = 276,                    /* READ  */
    WRITE = 277,                   /* WRITE  */
    FUNC = 278,                    /* FUNC  */
    MAIN_PRG = 279,                /* MAIN_PRG  */
    EVAL = 280,                    /* EVAL  */
    TYPEOF = 281,                  /* TYPEOF  */
    RETURN = 282,                  /* RETURN  */
    PLUS = 283,                    /* PLUS  */
    MINUS = 284,                   /* MINUS  */
    MULT = 285,                    /* MULT  */
    DIV = 286,                     /* DIV  */
    MOD = 287,                     /* MOD  */
    ASSIGN = 288,                  /* ASSIGN  */
    INC = 289,                     /* INC  */
    DEC = 290,                     /* DEC  */
    EQ = 291,                      /* EQ  */
    NEQ = 292,                     /* NEQ  */
    LT = 293,                      /* LT  */
    LE = 294,                      /* LE  */
    GT = 295,                      /* GT  */
    GE = 296,                      /* GE  */
    AND = 297,                     /* AND  */
    OR = 298,                      /* OR  */
    LET = 299,                     /* LET  */
    GET = 300,                     /* GET  */
    NOT = 301                      /* NOT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 39 "language.y"

    char* string_val;
    struct vec* vec_type;
    struct parameters* params;
    struct cond_symbol* cond;
    struct expr_symbol* expr;
    struct call_parameters* paramets;
    struct par* paramet;

#line 120 "language.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_LANGUAGE_TAB_H_INCLUDED  */
