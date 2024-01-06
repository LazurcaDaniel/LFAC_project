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
    struct parameters* params;
    struct BodyTree* body_expr;
}

%token <string_val> ID_VAL
%token <string_val> INT_TYPE FLOAT_TYPE CHAR_TYPE STRING_TYPE BOOL_TYPE VOID_TYPE CLASS_TYPE 
%token <string_val> FOR_INST WHILE_INST IF_INST ELSE_INST DO_INST
%token <string_val> INT_VAL FLOAT_VAL CHAR_VAL STRING_VAL 
%token <string_val> READ WRITE
%token <string_val> FUNC MAIN_PRG EVAL TYPEOF RETURN
%token <math_op> PLUS MINUS MULT DIV MOD ASSIGN INC DEC EQ NEQ LT LE GT GE AND OR UMINUS

%type<string_val> type
%type<string_val> value
%type<string_val> function_name
%type<string_val> return
%type<string_val> class_name
%type<params> parameter
%type<params> function_parameters
%type<vec_type> vector

%type <body_expr> body
%type <body_expr> assignement
%type <body_expr> condition;
%type <body_expr> control
%type <body_expr> if
%type <body_expr> while
%type <body_expr> for


%right ASSIGN
%left OR
%left AND
%left EQ NEQ
%left LT LET GT GET
%left MINUS PLUS
%left MULTIPLY DIVIDE MODULO
%right INC DEC NOT 
%nonassoc UMINUS 



%start prog

%%

  prog: classes global_variables functions MAIN_PRG {char m[] = "main"; updateLastScope(m); updateLastFuncScope(m);} '{' body '}'
    ;

  global_variables: declaration global_variables
    |
    ;

  classes: classes class
        | 
        ;

    class: class_declaration class_var_list 
         ;

    class_declaration: class_name '{' body_class '}' {char g[] = "Global"; addClass($1); updateLastScope(g); updateLastFuncScope(g);}

    class_name : CLASS_TYPE ID_VAL {$$ = $2; updateLastClassName($2); updateLastFuncScope(strdup($2)); updateLastScope(strdup($2));}
               ;

    body_class : global_variables functions
               ;
               
    class_var_list: class_var_list ',' class_var
                  | class_var
                  |
                  ;

    class_var: ID_VAL {getLastType(lastClassName); char c[] ="Class"; addSymbol("Variable", strdup($1), NULL, c); addVariableClass(lastClassName, strdup($1));}

 functions: function functions
    |
    ;

 function : function_name '(' function_parameters ')' '{' body return  '}' {addFunction($1, $3->type, $3->type_and_name);}
             | function_name '(' function_parameters ')' '{' return '}' {addFunction($1, $3->type, $3->type_and_name);}
             | function_name '(' function_parameters ')' '{' body '}' {char v[] = "void"; addFunctionType(v); addFunction($1, $3->type, $3->type_and_name); }
             ;

 function_name: FUNC type ID_VAL {$$ = $3; updateLastFuncScope(strdup($3)); updateLastScope(strdup($3));}
    ;


 function_parameters : function_parameters ',' parameter {$$->type_and_name = strcat(strdup($1->type_and_name), strcat(strdup(", "), strdup($3->type_and_name)));
                                             $$->type = strcat(strdup($1->type), strdup($3->type));}
                | parameter {$$ = $1;}
                | {$$->type_and_name = strdup("No parameters"); $$->type = strdup("No parameters");}
                ;


 parameter : type ID_VAL {addSymbol("Variable",strdup($2), NULL, strdup($1));
                         $$->type_and_name = strcat(strdup($1), (strcat(strdup(" "), strdup($2))));
                         $$->type = strdup($1);}
              | type ID_VAL '[' value ']' {addSymbol("Vector",strdup($2), strdup($4), strdup($1));
                         $$->type_and_name = strcat(strdup($1), (strcat(strdup(" "), strdup($2))));
                         $$->type = strdup($1);}
              ;




 body:body instr
    |instr{$$ = $2;}
    ;
 
 instr:declaration
    |assignement
    |control
    |condition
    |EVAL '(' condition ')'
    |TYPEOF '(' condition')' 
    ;   

    
     
 control:
    |IF_INST 
    |WHILE_INST
    |FOR_INST
    |DO_INST 
    ;
 for: FOR_INST '(' declaration ';' condition ';' condition ')' '{' body '}'
    {
        $7; // Execute the body of the for statement
    }
    ;    
 while: WHILE_INST '(' condition ')' '{' body '}'
    {
        while($3)
        {
            $5; // Execute the body of the while statement
        }
    }
    ;
 if: IF_INST '(' condition ')' '{' body '}'
    {
        if ($3) {
            $5; // Execute the body of the if statement
        }
    }
    ;

    IF_INST '(' condition ')' '{' body '}' ELSE_INST '{' body '}'
    {
        if ($3) {
            $5; // Execute the body of the if statement
        } else {
            $7; // Execute the body of the else statement
        }
    }
    ;

 condition:
        |condition PLUS condition {if(strcmp($1->var_type, $3->var_type)) {yyerror("ERR");}$$->var_type = $1->var_type; }
         | condition MINUS condition { if(strcmp($1->var_type, $3->var_type)) {yyerror("ERR");}$$->var_type = $1->var_type; }
         | condition MULT condition { if(strcmp($1->var_type, $3->var_type)) {yyerror("ERR");}$$->var_type = $1->var_type;}
         | condition DIV condition { if(strcmp($1->var_type, $3->var_type)) {yyerror("ERR");$$->var_type = $1->var_type;}}
         | condition MODULO condition { if(strcmp($1->var_type, $3->var_type)) {yyerror("ERR");}$$->var_type = $1->var_type;}
         | condition ASSIGN condition { if(strcmp($1->var_type, $3->var_type)) {yyerror("ERR");}$$->var_type = $1->var_type; }
         | condition EQ condition { if(strcmp($1->var_type, $3->var_type)) {yyerror("ERR");}$$->var_type = $1->var_type;}
         | condition NEQ condition { if(strcmp($1->var_type, $3->var_type)) {yyerror("ERR");}$$->var_type = $1->var_type;}
         | condition LT condition { if(strcmp($1->var_type, $3->var_type)) {yyerror("ERR");}$$->var_type = $1->var_type;}
         | condition LET condition { if(strcmp($1->var_type, $3->var_type)) {yyerror("ERR");}$$->var_type = $1->var_type;}
         | condition GT condition { if(strcmp($1->var_type, $3->var_type)) {yyerror("ERR");}$$->var_type = $1->var_type; }
         | condition GET condition { if(strcmp($1->var_type, $3->var_type)) {yyerror("ERR");}$$->var_type = $1->var_type; }
         | condition OR condition { if(strcmp($1->var_type, $3->var_type)) {yyerror("ERR");}$$->var_type = $1->var_type; }
         |condition INC{$$->var_type = $1->var_type;}
         |condition DEC{$$->var_type = $1->var_type;}
         |         
         ;

       
 assignement:ID_VAL ASSIGN value {int s = search(strdup($1));  if(s == -1) //x = 5
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
    |ID_VAL ASSIGN ID_VAL {
        int s = search(strdup($3)); if(s == -1 || symbol_table[s].value == NULL) // x = y
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
        modifyVarValue(v,symbol_table[s].value);
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
    |ID_VAL '[' ID_VAL ']' ASSIGN value{
        int s = search(strdup($1));
        if(s == -1)
        {
            yyerror("Error! Uninitialised value!");
            return -1;
        }
        int v = search(strdup($3));
        if(v == -1 || symbol_table[v].value == NULL)
        {
            yyerror("Error! Uninitialised value!");
            return -1;
        }
        if(strcmp(symbol_table[v].var_type,"int") || symbol_table[v].value[0] == '-' )
        {
            yyerror("Error! Unavailable index!");
            return -1;
        }
        if(strcmp(symbol_table[v].type,"Variable") && strcmp(symbol_table[v].type,"Constant"))
        {
            yyerror("Error! Index type is not correct!");
            return -1;
        }
        int a = search(makeVectorName(strdup($1),atoi(symbol_table[v].value)));
        if(a == -1)
        {
            yyerror("Error! Unavailable index!");
            return -1;
        }
        int x = search(strdup($6));
        if(strcmp(symbol_table[s].var_type,symbol_table[x].var_type))
        {
            yyerror("Error! Wrong conversion type.");
            return -1;
        }
        modifyVarValue(a,symbol_table[x].value);
    }
    |ID_VAL '[' ID_VAL ']' ASSIGN ID_VAL
    {
        int s = search(strdup($1));
        if(s == -1)
        {
            yyerror("Error! Uninitialised value!");
            return -1;
        }
        int v = search(strdup($3));
        if(v == -1 || symbol_table[v].value == NULL)
        {
            yyerror("Error! Uninitialised value!");
            return -1;
        }
        if(strcmp(symbol_table[v].var_type,"int") || symbol_table[v].value[0] == '-' )
        {
            yyerror("Error! Unavailable index!");
            return -1;
        }
        if(strcmp(symbol_table[v].type,"Variable") && strcmp(symbol_table[v].type,"Constant"))
        {
            yyerror("Error! Index type is not correct!");
            return -1;
        }   
        int a = search(makeVectorName(strdup($1),atoi(symbol_table[v].value)));
        if(a == -1)
        {
            yyerror("Error! Unavailable index!");
            return -1;
        }
        int x = search(strdup($6));
        if(x == -1 || symbol_table[x].value == NULL)
        {
            yyerror("Error! Uninitialised value!");
            return -1;
        }
        if(strcmp(symbol_table[x].type,"Variable") && strcmp(symbol_table[x].type,"Constant"))
        {
            yyerror("Error! Index type is not correct!");
            return -1;
        }
        if(strcmp(symbol_table[s].var_type,symbol_table[x].var_type))
        {
            yyerror("Error! Wrong conversion type.");
            return -1;
        }
        modifyVarValue(a,symbol_table[x].value);
    }
    ;  

declaration:type ID_VAL { addSymbol("Variable", strdup($2), NULL, strdup($1)); } //int x
    |type ID_VAL ASSIGN value { //int x = 5
        int v = search(strdup($4)); 
        if(strcmp(symbol_table[v].var_type, lastType)!=0)
        {
            yyerror("Error! Wrong conversion type.");
            return -1;
        }
        addSymbol("Variable", strdup($2), strdup($4), strdup($1));
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
    
    |type ID_VAL '[' ID_VAL ']' {
        int i = search(strdup($4));
        if(i == -1)
        {
            yyerror("Error! Uninitialised value!");
            return -1;
        }   
        if(strcmp(symbol_table[i].type,"Variable") && strcmp(symbol_table[i].type,"Constant"))
        {
            yyerror("Error! Index type is not correct!");
            return -1;
        }
        if(strcmp(symbol_table[i].var_type,"int") || symbol_table[i].value[0] == '-')
        {
            yyerror("Error! Unavailable index!");
            return -1;
        }
        addSymbol("Vector", strdup($2),symbol_table[i].value,strdup($1));
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
    |VOID_TYPE {updateLastType(strdup($1)); $$ = $1;}        
    ;

value:INT_VAL {char var_type[] = "int"; addSymbol("Constant", strdup($1), strdup($1), var_type); $$ = $1;}
    |FLOAT_VAL {char var_type[] = "float"; addSymbol("Constant", strdup($1), strdup($1), var_type); $$ = $1;}
    |CHAR_VAL {char var_type[] = "char"; addSymbol("Constant", strdup($1), strdup($1), var_type); $$ = $1;}
    |STRING_VAL {char var_type[] = "string"; addSymbol("Constant", strdup($1), strdup($1), var_type); $$ = $1;}
    ;
    
return: RETURN value
    | RETURN ID_VAL {int s = search(strdup($2)); if(s == -1 || symbol_table[s].value == NULL)
    {
        yyerror("Error! Variable uninitialised!");
        return -1;
    }}
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
    printFunctions();
    printSymbols();

    fclose(file);

    return 0;
}
