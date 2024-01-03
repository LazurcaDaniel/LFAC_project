%{
#include <iostream>
#include "tables.h"
extern int yylex();
int yyerror(const char* s);
extern FILE* yyin; 
extern int line_nr;
using namespace std;

%}



%union{
    char* string_val;
    char* math_op;
}

%token <string_val> ID_VAL
%token <string_val> INT_TYPE FLOAT_TYPE CHAR_TYPE STRING_TYPE BOOL_TYPE
%token <string_val> FOR_INST WHILE_INST IF_INST ELSE_INST DO_INST
%token <string_val> INT_VAL FLOAT_VAL CHAR_VAL STRING_VAL 
%token <string_val> READ WRITE
%token <string_val> FUNC BEGIN_PRG FINISH_PRG MAIN_PRG EVAL TYPEOF
%token <math_op> PLUS MINUS MULT DIV MOD ASSIGN INC DEC

%type<string_val> type
%type<string_val> value

%start main

%%

main: '{' body '}'

body:instr body
    |instr
    ;

instr:type ID_VAL { addSymbol("Variable", strdup($2), NULL, strdup($1)); } //int x
    |type ID_VAL ASSIGN value { //int x = 5
        int v = search(strdup($4)); 
        if(strcmp(symbol_table[v].var_type, lastType)!=0)
        {
            yyerror("Error! Wrong conversion type.");
            return -1;
        }
        addSymbol("Variable", strdup($2), strdup($4), strdup($1));
    }
    |ID_VAL ASSIGN value {int s = search(strdup($1)); if(s == -1) //x = 5
    {
        yyerror("Error! Undeclared variable!");
        return -1;
    }
    else
    {
        int v = search(strdup($3)); if(strcmp(symbol_table[s].var_type,symbol_table[v].var_type) == 0)
        {
            modifyVarValue(s,symbol_table[v].value);
        }
        else
        {
            yyerror("Error! Wrong conversion type.");
            return -1;
        }
    }
    }
    |type ID_VAL ASSIGN ID_VAL {int s = search(strdup($4)); if(s == -1) ///int x = y
    {
        yyerror("Error! Undeclared variable!");
        return -1;
    }
        if(symbol_table[s].value == NULL)
        {
            yyerror("Error! Value uninitialised!");
            return -1;
        }
        if(strcmp(lastType,symbol_table[s].var_type)!=0)
        {
            yyerror("Error! Wrong conversion type.");
            return -1;
        }
        addSymbol("Variable",strdup($2),symbol_table[s].value,strdup($1));
    }    
    |ID_VAL ASSIGN ID_VAL {
        int s = search(strdup($3)); if(s == -1) // x = y
    {
        yyerror("Error! Undeclared variable!");
        return -1;
    }
    else
    {
        int v = search(strdup($1)); if(v == -1)
        {
            yyerror("Error! Undeclared variable!");
            return -1;
        }
        if(strcmp(symbol_table[s].var_type,symbol_table[v].var_type)!=0)
        {
            yyerror("Error! Wrong conversion type.");
            return -1;
        }
        if(symbol_table[s].value == NULL)
        {
            yyerror("Error! Value uninitialised!");
            return -1;
        }
        modifyVarValue(v,symbol_table[s].value);
    }
    }
    |type ID_VAL '[' value ']' //int x[100]
    {
        addSymbol("Vector", strdup($2),strdup($4),strdup($1));
    }
    |ID_VAL '[' value ']' ASSIGN value
    {
        int s = ExistsVectorVarName(strdup($1),strdup($3));
        if(s == -1)
        {
            yyerror("Error! Uninitialised value!");
            return -1;
        }
        int v = search(strdup($6));
        if(strcmp(symbol_table[v].var_type,symbol_table[s].var_type))
        {
            yyerror("Error! Wrong conversion type!");
            return -1;
        }
        modifyVarValue(s,symbol_table[v].value);
    }
    ;

type:INT_TYPE {updateLastType(strdup($1)); $$ = $1;}
    |FLOAT_TYPE {updateLastType(strdup($1)); $$ = $1;}
    |BOOL_TYPE {updateLastType(strdup($1)); $$ = $1;}
    |CHAR_TYPE {updateLastType(strdup($1)); $$ = $1;}
    |STRING_TYPE {updateLastType(strdup($1)); $$ = $1;}   
    ;

value:INT_VAL {addSymbol("Constant", strdup($1), strdup($1), "int"); $$ = $1;}
    |FLOAT_VAL {addSymbol("Constant", strdup($1), strdup($1), "float"); $$ = $1;}
    |CHAR_VAL {addSymbol("Constant", strdup($1), strdup($1), "char"); $$ = $1;}
    |STRING_VAL {addSymbol("Constant", strdup($1), strdup($1), "string"); $$ = $1;}
    ;
    
%%
int yyerror(const char* s){
    printf("Line %d: Error! %s\n",line_nr+1, s);
    return -1;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s input_file\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    yyin = file; // Set the input file for Flex

    yyparse();
    printSymbols();

    fclose(file);

    return 0;
}