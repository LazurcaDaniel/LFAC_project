%{
    #include "language.tab.h"
    int line_nr = 0;
%}

%option noyywrap
NUMBER [0-9]|[1-9][0-9]*
FLOAT_NR [0-9]+
ID [a-zA-Z][a-zA-Z0-9_]*

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


"+" {yylval.string_val = strdup(yytext); return PLUS;}
"-" {yylval.string_val = strdup(yytext); return MINUS;}
"*" {yylval.string_val = strdup(yytext); return MULT;}
"/" {yylval.string_val = strdup(yytext); return DIV;}
"%" {yylval.string_val = strdup(yytext); return MOD;}
"=" {yylval.string_val = strdup(yytext); return ASSIGN;}
"++" {yylval.string_val = strdup(yytext); return INC;}
"--" {yylval.string_val = strdup(yytext); return DEC;}

"&&" {yylval.string_val = strdup(yytext); return AND;} 
"||" {yylval.string_val = strdup(yytext); return OR;}
"!" {yylval.string_val = strdup(yytext); return NOT;}
"==" {yylval.string_val = strdup(yytext); return EQ;}
"!=" {yylval.string_val = strdup(yytext); return NEQ;}
"<" {yylval.string_val = strdup(yytext); return LT;}
"<=" {yylval.string_val = strdup(yytext); return LE;}
">" {yylval.string_val = strdup(yytext); return GT;}
">=" {yylval.string_val = strdup(yytext); return GE;}

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