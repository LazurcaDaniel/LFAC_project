%{
#include <iostream>
#include "tables.h"
extern int yylex();
int yyerror(const char* s);
extern FILE* yyin; 
extern int line_nr;
using namespace std;

struct vec{
    int nr_elem = 0;
    char* value[10];
};

%}

%union{
    char* string_val;
    char* math_op;
    struct vec* vec_type;
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
%type<vec_type> vector

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
        int i = search(strdup($4));
        if(strcmp(symbol_table[i].var_type,"int") || symbol_table[i].value[0] == '-')
        {
            yyerror("Error! Unavailable index!");
            return -1;
        }
        addSymbol("Vector", strdup($2),strdup($4),strdup($1));
    }
    |type ID_VAL '[' value ']' ASSIGN '{' vector '}'
    {
        int s = search(strdup($2));
        if(s != -1)
        {
            yyerror("Error! Redeclaration of variable!");
            return -1;
        }
        int v = search(strdup($4));
        if(strcmp(symbol_table[v].var_type,"int") || symbol_table[v].value[0] == '-')
        {
            yyerror("Error! Unavailable index!");
            return -1;
        }
        addSymbol("Vector",strdup($2),strdup($4),strdup($1));
        if($8->nr_elem > atoi($4))
        {
            yyerror("Error! Too many elements in the vector.");
            return -1;
        }
        for(int i = 0; i < $8->nr_elem; i++)
        {
            s = search(makeVectorName(strdup($2),i));
            int e = search($8->value[i]);
            if(strcmp(lastType,symbol_table[e].var_type))
            {
                yyerror("Error! An element in the vector is of the wrong type!");
                return -1;
            }
            modifyVarValue(s,symbol_table[e].value);
        }
        if(strcmp(lastType,"int")==0)
        {
            for(int i = $8->nr_elem; i < atoi(strdup($4)); i++)
                {
                    s = search(makeVectorName(strdup($2),i));
                    char zero[] = "0";
                    modifyVarValue(s,zero);
                }
        }
        else if(strcmp(lastType,"float") == 0)
        {
            for(int i = $8->nr_elem; i < atoi(strdup($4)); i++)
                {
                    s = search(makeVectorName(strdup($2),i));
                    char zero[] = "0.0";
                    modifyVarValue(s,zero);
                }
        }
    }
    |ID_VAL '[' value ']' ASSIGN value
    {
        int s = search(strdup($1));
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

        int i = search(strdup($3));
        if(strcmp(symbol_table[i].var_type,"int") || symbol_table[i].value[0] == '-')
        {
            yyerror("Error! Unavailable index!");
            return -1;
        }
        
        int x = search(getVectorIndexName(strdup($1),strdup($3)));
        if(x == -1)
        {
            yyerror("Error! Unavailable index!");
            return -1;
        }
        modifyVarValue(x,symbol_table[v].value);
    }
    |ID_VAL '[' value ']' ASSIGN ID_VAL
    {
        int s = search(strdup($1));
        if(s == -1)
        {
            yyerror("Error! Uninitialised value!");
            return -1;
        }
        int v = search(strdup($6));
        if(v == -1 || symbol_table[v].value == NULL)
        {
            yyerror("Error! Uninitialised value!");
            return -1;
        }   
        if(strcmp(symbol_table[v].var_type,symbol_table[s].var_type))
        {
            yyerror("Error! Wrong conversion type!");
            return -1;
        }
        int i = search(strdup($3));
        if(strcmp(symbol_table[i].var_type,"int") || symbol_table[i].value[0] == '-')
        {
            yyerror("Error! Unavailable index!");
            return -1;
        }
        
        int x = search(getVectorIndexName(strdup($1),strdup($3)));
        if(x == -1)
        {
            yyerror("Error! Unavailable index!");
            return -1;
        }
        modifyVarValue(x,symbol_table[v].value);
    }
    ;

vector: vector ',' value { strcpy($1->value[$1->nr_elem],$3); $1->nr_elem++; $$ = $1; }
    | value {
    $$ = new vec;
    for(int i = 0; i < 100; i++)
        $$->value[i] = (char*)malloc(10);     
    $$->nr_elem = 0; strcpy($$->value[$$->nr_elem],$1); $$->nr_elem++;
    }
    ;

type:INT_TYPE {updateLastType(strdup($1)); $$ = $1;}
    |FLOAT_TYPE {updateLastType(strdup($1)); $$ = $1;}
    |BOOL_TYPE {updateLastType(strdup($1)); $$ = $1;}
    |CHAR_TYPE {updateLastType(strdup($1)); $$ = $1;}
    |STRING_TYPE {updateLastType(strdup($1)); $$ = $1;}   
    ;

value:INT_VAL {char var_type[] = "int"; addSymbol("Constant", strdup($1), strdup($1), var_type); $$ = $1;}
    |FLOAT_VAL {char var_type[] = "float"; addSymbol("Constant", strdup($1), strdup($1), var_type); $$ = $1;}
    |CHAR_VAL {char var_type[] = "char"; addSymbol("Constant", strdup($1), strdup($1), var_type); $$ = $1;}
    |STRING_VAL {char var_type[] = "string"; addSymbol("Constant", strdup($1), strdup($1), var_type); $$ = $1;}
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