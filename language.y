%{
#include <iostream>
#include "tables.h"
extern int yylex();
int yyerror(const char* s);
extern FILE* yyin; 
extern int line_nr;
using namespace std;

bool ok = true;

struct vec{
    int nr_elem = 0;
    char* value[10];
};

struct expr_symbol
{
    bool bool_value;
    char* value;
    char* type;
};

struct par
{
    char* type;
    char* value;
};

struct call_parameters
{
    int cnt = 0;
    par* parameters[100];
};


%}

%union{
    char* string_val;
    struct vec* vec_type;
    struct parameters* params;
    struct cond_symbol* cond;
    struct expr_symbol* expr;
    struct call_parameters* paramets;
    struct par* paramet;
}

%token <string_val> ID_VAL
%token <string_val> INT_TYPE FLOAT_TYPE CHAR_TYPE STRING_TYPE BOOL_TYPE VOID_TYPE CLASS_TYPE 
%token <string_val> FOR_INST WHILE_INST IF_INST ELSE_INST DO_INST
%token <string_val> INT_VAL FLOAT_VAL CHAR_VAL STRING_VAL BOOL_VAL
%token <string_val> READ WRITE
%token <string_val> FUNC MAIN_PRG EVAL TYPEOF RETURN
%token <string_val> PLUS MINUS MULT DIV MOD ASSIGN INC DEC EQ NEQ LT LE GT GE AND OR

%type<string_val> type
%type<string_val> value
%type<string_val> function_name
%type<string_val> class_name
%type<params> parameter
%type<params> function_parameters
%type<vec_type> vector
%type<expr>  expression
%type <expr> condition
%type<expr> return
%type<paramets> call_params
%type<paramet> call_param

%right ASSIGN
%left OR
%left AND
%left EQ NEQ
%left LT LET GT GET
%left MINUS PLUS
%left MULT DIV MOD
%right INC DEC NOT 



%start prog

%%

  prog: global_variables classes functions MAIN_PRG {char m[] = "main"; updateLastScope(m); updateLastFuncScope(m);} '{' body '}'
    ;

  global_variables: declaration global_variables
    |
    ;

  classes: classes class
        | 
        ;

    class: class_declaration class_var_list 
         ;

    class_declaration: class_name '{' body_class '}' {char g[] = "Global"; addClass($1); updateLastScope(g); updateLastFuncScope(g); }

    class_name : CLASS_TYPE ID_VAL { $$ = $2; updateLastClassName($2); updateLastFuncScope(strdup($2)); updateLastScope(strdup($2));}
               ;

    body_class : global_variables functions
               ;
               
    class_var_list: class_var_list ',' class_var
                  | class_var
                  |
                  ;

    class_var: ID_VAL {updateLastType(lastClassName); char c[] ="Class"; addSymbol("Variable", strdup($1), NULL, c); addVariableClass(lastClassName, strdup($1)); }

 functions: function functions
    |
    ;

 function : function_name '(' function_parameters ')' '{' body return  '}' {if(strcmp($7->type,lastDeclaredFunctionType)) {yyerror("Error! Wrong conversion type!"); return -1;}  addFunction(strdup($1), $3->type, $3->type_and_name); }
             | function_name '(' function_parameters ')' '{' return '}' {if(strcmp($6->type,lastDeclaredFunctionType)) {yyerror("Error! Wrong conversion type!"); return -1;} addFunction($1, $3->type, $3->type_and_name);}
             | function_name '(' function_parameters ')' '{' body '}' {char v[] = "void"; addFunctionType(v); addFunction(strdup($1), $3->type, $3->type_and_name); }
             ;

 function_name: FUNC type ID_VAL {$$ = strdup($3); updateLastFuncScope(strdup($3)); updateLastScope(strdup($3)); addFunctionType(strdup($2));}
    ;


 function_parameters : function_parameters ',' parameter {$$->type_and_name = strcat(strdup($1->type_and_name), strcat(strdup(","), strdup($3->type_and_name)));
                                             $$->type = strcat($1->type,$3->type);
                                             }
                | parameter {$$ = $1;}
                | {$$->type_and_name = strdup("No parameters"); $$->type = strdup("No parameters");}
                ;


 parameter : type ID_VAL { char z[] = "0"; addSymbol("Variable",strdup($2), z, strdup($1));
                         $$->type_and_name = strcat(strdup($1), (strcat(strdup(" "), strdup($2))));
                         $$->type = strdup($1);}
              | type ID_VAL '[' value ']' {addSymbol("Vector",strdup($2), strdup($4), strdup($1));
                         $$->type_and_name = strcat(strdup($1), (strcat(strdup(" "), strdup($2))));
                         $$->type = strdup($1);}
              ;




 body:body instr
    |instr
    ;
 
 instr:declaration
    |assignement
    |control
    |write
    |read
    ;   

write: WRITE expression
    ;
read: READ ID_VAL
    {
        int s = search(strdup($2));
        if(s == -1)
        {
            yyerror("Error! Variable uninitialised!");
            return -1;
        }
        char z[] = "0";
        modifyVarValue(s,z);
    }
    ;
    
     
 control:if
    |while
    |for
    |do
    ;
 for: FOR_INST '(' declaration ';' condition ';' expression ')' '{' body '}'
    {
        cout<<"FOR"<<'\n'; // Execute the body of the for statement
    }
    ;    
 while: WHILE_INST '(' condition ')' '{' body '}'
    {
        if ($3->bool_value == true) {
             cout<<"TRUE"<<'\n';  // Execute the body of the if statement
        }
        else
        {
            cout<<"FALSE"<<'\n';
        }
    }
    ;
 if: IF_INST '(' condition ')' '{' body '}'
    {
        if ($3->bool_value == true) {
             cout<<"TRUE"<<'\n';  // Execute the body of the if statement
        }
        else
        {
            cout<<"FALSE"<<'\n';
        }
    }
    | IF_INST '(' condition ')' '{' body '}' ELSE_INST '{' body '}'
    {
        if ($3 -> bool_value == true) {
            cout<<"TRUE"<<'\n'; // Execute the body of the if statement
        } else {
            cout<<"FALSE"<<'\n'; // Execute the body of the else statement
        }
    }
    | IF_INST '(' condition ')' '{' body '}' ELSE_INST if
    ;

do: DO_INST '{' body '}' WHILE_INST '(' condition ')'

 condition:condition EQ condition { if(strcmp($1->type, $3->type)) {yyerror("Error! Wrong conversion type!"); return -1;}$$->type = $1->type; if(strcmp($1->value,$3->value) == 0) {$$->bool_value = true; strcpy($$->value,"1");} else {$$->bool_value = false; strcpy($$->value,"0");}}
         | condition NEQ condition { if(strcmp($1->type, $3->type)) {yyerror("Error! Wrong conversion type!"); return -1;}$$->type = $1->type; if(strcmp($1->value,$3->value)) {$$->bool_value = true; strcpy($$->value,"1");} else {$$->bool_value = false; strcpy($$->value,"0");}}
         | condition LT condition { if(strcmp($1->type, $3->type)) {yyerror("Error! Wrong conversion type!"); return -1;}$$->type = $1->type; if($1->value < $3->value) {$$->bool_value = true; strcpy($$->value,"1");} else {$$->bool_value = false; strcpy($$->value,"0");}}
         | condition LET condition { if(strcmp($1->type, $3->type)) {yyerror("Error! Wrong conversion type!"); return -1;}$$->type = $1->type; if($1->value <= $3->value) {$$->bool_value = true; strcpy($$->value,"1");} else {$$->bool_value = false; strcpy($$->value,"0");}}
         | condition GT condition { if(strcmp($1->type, $3->type)) {yyerror("Error! Wrong conversion type!"); return -1;}$$->type = $1->type; if($1->value > $3->value) {$$->bool_value = true; strcpy($$->value,"1");} else {$$->bool_value = false; strcpy($$->value,"0");}}
         | condition GET condition { if(strcmp($1->type, $3->type)) {yyerror("Error! Wrong conversion type!"); return -1;}$$->type = $1->type; if($1->value >= $3->value) {$$->bool_value = true; strcpy($$->value,"1");} else {$$->bool_value = false; strcpy($$->value,"0");}}
         | condition OR condition { if(strcmp($1->type, $3->type)) {yyerror("Error! Wrong conversion type!"); return -1;}$$->type = $1->type; if($1->bool_value || $3->bool_value) {$$->bool_value = true; strcpy($$->value,"1");} else {$$->bool_value = false; strcpy($$->value,"0");}}
         | condition AND condition { if(strcmp($1->type, $3->type)) {yyerror("Error! Wrong conversion type!"); return -1;}$$->type = $1->type; if($1->bool_value && $3->bool_value) {$$->bool_value = true; strcpy($$->value,"1");} else {$$->bool_value = false; strcpy($$->value,"0");}}
         | NOT condition { $2->bool_value = !$2->bool_value; $$ = $2;}
         |expression {$$ = $1;}      
         ;


 expression:expression PLUS expression {if(strcmp($1->type, $3->type) || (strcmp($1->type,"int") && strcmp($1->type,"float"))) {yyerror("Error! Wrong conversion type!"); return -1;}$$->type = $1->type;  strcpy($$->value,itoa(atoi($1->value) + atoi($3->value))); strcmp($$->value,"0") == 0 ? $$->bool_value = true : $$->bool_value = false;}
         | expression MINUS expression { if(strcmp($1->type, $3->type) ||(strcmp($1->type,"int") && strcmp($1->type,"float"))) {yyerror("Error! Wrong conversion type!"); return -1;}$$->type = $1->type;  strcpy($$->value,itoa(atoi($1->value) - atoi($3->value))); strcmp($$->value,"0") == 0 ? $$->bool_value = true : $$->bool_value = false;}
         | expression MULT expression { if(strcmp($1->type, $3->type) ||(strcmp($1->type,"int") && strcmp($1->type,"float"))) {yyerror("Error! Wrong conversion type!"); return -1;}$$->type = $1->type;  strcpy($$->value,itoa(atoi($1->value) * atoi($3->value))); strcmp($$->value,"0") == 0 ? $$->bool_value = true : $$->bool_value = false;}
         | expression DIV expression { if(strcmp($1->type, $3->type) || (strcmp($1->type,"int") && strcmp($1->type,"float"))) {yyerror("Error! Wrong conversion type!"); return -1;} if(strcmp($3->value,"0") == 0) {yyerror("Error! Cannot divide by 0!"); return -1;} $$->type = $1->type;  strcpy($$->value,itoa(atoi($1->value) / atoi($3->value))); strcmp($$->value,"0") == 0 ? $$->bool_value = true : $$->bool_value = false;}
         | expression MOD expression { if(strcmp($1->type, $3->type) || (strcmp($1->type,"int") && strcmp($1->type,"float"))) {yyerror("Error! Wrong conversion type!"); return -1;}if(strcmp($3->value,"0") == 0) {yyerror("Error! Cannot divide by 0!"); return -1;} $$->type = $1->type; strcpy($$->value,itoa(atoi($1->value) % atoi($3->value))); strcmp($$->value,"0") == 0 ? $$->bool_value = true : $$->bool_value = false;}
         | '(' expression ')' {$$ = $2;}
         |expression INC{if(strcmp($1->type,"int")) {yyerror("Error! You can't increment on a non integer!"); return -1;} $$->type = $1->type; strcpy($$->value,itoa(atoi($1->value) + 1)); strcmp($$->value,"0") == 0 ? $$->bool_value = true : $$->bool_value = false;}
         |expression DEC{if(strcmp($1->type,"int")) {yyerror("Error! You can't decrement on a non integer!"); return -1;} $$->type = $1->type; strcpy($$->value,itoa(atoi($1->value) - 1)); strcmp($$->value,"0") == 0 ? $$->bool_value = true : $$->bool_value = false;}
         | ID_VAL
         {
            int s = search(strdup($1));
            if(s == -1 || symbol_table[s].value == NULL)
            {
                yyerror("Error! Variable uninitialised!");
                return -1;
            }
            $$->value = (char*) malloc (60);
            strcpy($$->value, symbol_table[s].value);
            $$->type = (char*) malloc(60);
            strcpy($$->type, symbol_table[s].var_type);
            if(strcmp(symbol_table[s].value,"0"))
                $$->bool_value = false;
            else
                $$->bool_value = true;
         }  
         | value
         {
            int s = search(strdup($1));
            $$->value = (char*) malloc (60);
            strcpy($$->value, symbol_table[s].value);
            $$->type = (char*) malloc(60);
            strcpy($$->type, symbol_table[s].var_type);
            if(strcmp(symbol_table[s].value,"0"))
                $$->bool_value = false;
            else
                $$->bool_value = true;
         }
         | ID_VAL '(' call_params ')'
         {
            int s = searchFunction(strdup($1));
            if(s == -1 )
            {
                yyerror("Error! Variable uninitialised!");
                return -1;
            }
            char *r = (char*) malloc(100);
            for(int i = 0; i < $3->cnt; i++)
            {
                strcat(r,$3->parameters[i]->type);
            }
            if(strcmp(r,function_table[s].type_parameters))
            {
                yyerror("Error! Incorrect parameters!");
                return -1;
            }
            $$->value = (char*) malloc (60);
            strcpy($$->value,"0");
            $$->type = (char*) malloc(60);
            strcpy($$->type,function_table[s].var_type);
            $$->bool_value = true;
         }
         | ID_VAL '('')'
         {
            int s = searchFunction(strdup($1));
            if(s == -1 )
            {
                yyerror("Error! Variable uninitialised!");
                return -1;
            }
            if(strcmp(function_table[s].type_parameters,"No parameters"))
            {
                yyerror("Error! Incorrect parameters!");
                return -1;
            }
            $$->value = (char*) malloc (60);
            strcpy($$->value,"0");
            $$->type = (char*) malloc(60);
            strcpy($$->type,function_table[s].var_type);
            $$->bool_value = true;
         }
         | ID_VAL '.' ID_VAL
         {
            char* r = (char*)malloc(100);
            strcpy(r,$1);
            strcat(r,".");
            strcat(r,$3);
            int s = search(r);
            if(s == -1 || symbol_table[s].value == NULL)
            {
                yyerror("Error! Value uninitialised!");
                return -1;
            }
            $$->value = (char*) malloc (60);
            strcpy($$->value,symbol_table[s].value);
            $$->type = (char*) malloc(60);
            strcpy($$->type,function_table[s].var_type);
            if(strcmp(symbol_table[s].value,"0"))
                $$->bool_value = false;
            else
                $$->bool_value = true;
         }
         |EVAL '(' expression ')'
         {
            $$ = $3;
         }
         |TYPEOF '(' expression ')'
         {
            $$ = $3;
         }
        ;
 assignement:ID_VAL ASSIGN expression {int s = search(strdup($1));  if(s == -1) //x = 5
    {
        yyerror("Error! Undeclared variable!");
        return -1;
    }
    else
    {
        if(strcmp(symbol_table[s].var_type,$3->type) == 0)
        {
            modifyVarValue(s,$3->value);
        }
        else
        {
            yyerror("Error! Wrong conversion type.");
            return -1;
        }
    }
    }
    |ID_VAL '[' value ']' ASSIGN expression
    {
        int s = search(strdup($1));
        if(s == -1)
        {
            yyerror("Error! Uninitialised value!");
            return -1;
        }
        if(strcmp($6->type,symbol_table[s].var_type))
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
        modifyVarValue(x,$6->value);
    }
    |ID_VAL '[' ID_VAL ']' ASSIGN expression{
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
        if(strcmp(symbol_table[s].var_type,$6->type))
        {
            yyerror("Error! Wrong conversion type.");
            return -1;
        }
        modifyVarValue(a,$6->value);
    }
    | ID_VAL '(' call_params ')' 
    {
        int s = searchFunction(strdup($1));
        if(s == -1)
        {
            yyerror("Error! Function non-existant!");
            return -1;
        }
        char *r = (char*) malloc(100);
        for(int i = 0; i < $3->cnt; i++)
        {
            strcat(r,$3->parameters[i]->type);
        }
        if(strcmp(r,function_table[s].type_parameters))
        {
            yyerror("Error! Incorrect parameters!");
            return -1;
        }
    }
    |ID_VAL '('')'
    {
        int s = searchFunction(strdup($1));
        if(s == -1)
        {
            yyerror("Error! Function non-existant!");
            return -1;
        }
        if(strcmp(function_table[s].type_parameters,"No parameters"))
        {
            yyerror("Error! Incorrect parameters!");
            return -1;
        }
    }
    |ID_VAL '.' ID_VAL ASSIGN expression
    {
        char* r = (char*)malloc(100);
        strcpy(r,$1);
        strcat(r,".");
        strcat(r,$3);
        int s = search(r);
        if(s == -1 || symbol_table[s].value == NULL)
        {
            yyerror("Error! Value uninitialised!");
            return -1;
        }
        if(strcmp(symbol_table[s].var_type,$5->type))
        {
            yyerror("Error! Wrong conversion type!");
            return -1;
        }
        modifyVarValue(s,$5->value);
    }
    ;

call_params: call_params ',' call_param
    {
        $1->parameters[$1->cnt] = new par;
        $1->parameters[$1->cnt]->type = (char*)malloc(20);
        $1->parameters[$1->cnt]->value = (char*)malloc(60);
        strcpy($1->parameters[$1->cnt]->type,$3->type);
        strcpy($1->parameters[$1->cnt]->value,$3->value);
        $1->cnt++;
        $$ = $1;
    }
    |call_param {
        $$ = new call_parameters;
        $$->cnt = 0;
        $$->parameters[0] = new par;
        $$->parameters[0]->type = (char*)malloc(20);
        $$->parameters[0]->value = (char*)malloc(60);
        strcpy($$->parameters[$$->cnt]->type,$1->type);
        strcpy($$->parameters[$$->cnt]->value,$1->value);
        $$->cnt++;
    }
    ;

call_param: expression 
    {
        $$ = new par;
        $$->type = (char*)malloc(20);
        strcpy($$->type,$1->type);
        $$->value = (char*)malloc(60);
        strcpy($$->value,$1->value);
    }
    ;
declaration:type ID_VAL { addSymbol("Variable", strdup($2), NULL, strdup($1)); } //int x
    |type ID_VAL ASSIGN expression { //int x = 5
        if(strcmp($4->type, lastType)!=0)
        {
            yyerror("Error! Wrong conversion type.");
            return -1;
        }
        addSymbol("Variable", strdup($2), $4->value, strdup($1));
    } 
    |type ID_VAL '[' value ']' //int x[100]
    {
        int i = search(strdup($4));
        if(strcmp(symbol_table[i].var_type,"int") || symbol_table[i].value[0] == '-')
        {
            yyerror("Error! Unavailable index!");
            return -1;
        }
        int v = search(strdup($2));
        if(v!=-1)
        {
            yyerror("Error! Redeclaration of variable!");
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
        int v = search(strdup($2));
        if(v!=-1)
        {
            yyerror("Error! Redeclaration of variable!");
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
    |BOOL_VAL {char var_type[] = "bool"; addSymbol("Constant", strdup($1), strdup($1), var_type); $$ = $1;}
    ;
    
return: RETURN expression 
    {
        $$->type = (char*)malloc(20);
        $$->value = (char*)malloc(60);
        $$ = $2;
    }
    ;    
%%
int yyerror(const char* s){
    ok = false;
    printf("Line %d: %s\n",line_nr+1, s);
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
    printSymbolsToFile();
    if(ok)
        cout<<"Compilation was successful!\n";
    fclose(file);

    return 0;
}