%{
    #include "language.tab.h"
    int line_nr = 0;
%}

%option noyywrap
NUMBER [0-9]|[1-9][0-9]*
FLOAT_NR [0-9]+
ID [a-zA-Z][a-zA-Z0-9]*

%%
"int" {yylval.string_val = strdup(yytext); return INT_TYPE; }
"float" {yylval.string_val = strdup(yytext); return FLOAT_TYPE; }
"char" {yylval.string_val = strdup(yytext); return CHAR_TYPE; }
"string" {yylval.string_val = strdup(yytext); return STRING_TYPE; }
"bool" {yylval.string_val = strdup(yytext); return BOOL_TYPE; }
"void" {yylval.string_val = strdup(yytext); return VOID_TYPE; }
"class" {yylval.string_val = strdup(yytext); return CLASS_TYPE; }

"for" {yylval.string_val = strdup(yytext); return FOR_INST; }
"while" {yylval.string_val = strdup(yytext); return WHILE_INST; }
"if" {yylval.string_val = strdup(yytext); return IF_INST; }
"else" {yylval.string_val = strdup(yytext); return ELSE_INST; }
"do" {yylval.string_val = strdup(yytext); return DO_INST; }

"read" {yylval.string_val = strdup(yytext); return READ;}
"write" {yylval.string_val = strdup(yytext); return WRITE;}
"return" {yylval.string_val = strdup(yytext); return RETURN;}
"fn" {yylval.string_val = strdup(yytext); return FUNC;}
"main" {yylval.string_val = strdup(yytext); return MAIN_PRG;}
"Eval" {yylval.string_val = strdup(yytext); return EVAL;}
"TypeOf" {yylval.string_val = strdup(yytext); return TYPEOF;}


"+" {yylval.math_op = strdup(yytext); return PLUS;}
"-" {yylval.math_op = strdup(yytext); return MINUS;}
"*" {yylval.math_op = strdup(yytext); return MULT;}
"/" {yylval.math_op = strdup(yytext); return DIV;}
"%" {yylval.math_op = strdup(yytext); return MOD;}
"=" {yylval.math_op = strdup(yytext); return ASSIGN;}
"++" {yylval.math_op = strdup(yytext); return INC;}
"--" {yylval.math_op = strdup(yytext); return DEC;}

"&&" {yylval.math_op = strdup(yytext); return AND;} 
"||" {yylval.math_op = strdup(yytext); return OR;}
"!" {yylval.math_op = strdup(yytext); return NOT;}
"==" {yylval.math_op = strdup(yytext); return EQ;}
"!=" {yylval.math_op = strdup(yytext); return NEQ;}
"<" {yylval.math_op = strdup(yytext); return LT;}
"<=" {yylval.math_op = strdup(yytext); return LE;}
">" {yylval.math_op = strdup(yytext); return GT;}
">=" {yylval.math_op = strdup(yytext); return GE;}

\"(.*)\" {yylval.string_val = strdup(yytext); return STRING_VAL;}
\'.\' {yylval.string_val = strdup(yytext); return CHAR_VAL;}
{ID} {yylval.string_val = strdup(yytext); return ID_VAL;}
[-]?{NUMBER} {yylval.string_val = strdup(yytext); return INT_VAL;}
[-]?{NUMBER}\.{FLOAT_NR} {yylval.string_val = strdup(yytext); return FLOAT_VAL;}
[ ] ;
[ \t] ;
[ \n] {line_nr++;}

. {return yytext[0];}
%%

/*** C Code section ***/