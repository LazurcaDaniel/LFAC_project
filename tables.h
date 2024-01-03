#include <iostream>
#include <cstring>

using namespace std;
extern int yyerror(const char *);
struct symbol
{
    char* type; //variable, constanta, vector
    char* var_type; //int, float, char, etc
    char* name; //name of the variable
    char* value; //value of the variable
    //char* scope;
}symbol_table[10000];


/// to do function logic
struct function_symbols{
    //to do
}

int nr_symbols = 0;

char* lastType = NULL; 

void updateLastType(char* newType)
{
    if (lastType != NULL) {
        free(lastType);
    }
    // Allocate memory for the new type and copy it
    lastType = (char*)malloc(strlen(newType) + 1);
    strcpy(lastType, newType);
}

int search(char *name)
{
    for(int i = 0; i < nr_symbols; i++)
        if(!strcmp(symbol_table[i].name,name))
            return i;
    return -1;
}

void modifyVarValue(int pos, char* newValue)
{
    if(symbol_table[pos].value == NULL)
        symbol_table[pos].value = (char*)malloc(sizeof(newValue));
    strcpy(symbol_table[pos].value,newValue);
}


char* vectorVarName(char* name, int index)
{
    char* res = strdup(name);
    char* i = (char*)malloc(strlen(name) + 10);
    if (i == NULL) {
        return NULL;
    }

    snprintf(i, 10, "[%d]", index);
    strcat(res, i);
    return res;
}

int ExistsVectorVarName(char* name, char* index)
{
    char *res = strdup(name);
    strcat(res,"[");
    strcat(res,index);
    strcat(res,"]");
    return search(res);
}

int addSymbol(const char *type, char* name, char* value, const char* var_type)
{
   
    int isHereAlready = search(name);
    if(isHereAlready == -1)
    {
        
        if(strcmp(type, "Variable") == 0)
        {

            if(value != NULL)
            symbol_table[nr_symbols].value = strdup(value);
            symbol_table[nr_symbols].var_type = strdup(var_type);
            symbol_table[nr_symbols].type = strdup(type);
            symbol_table[nr_symbols].name = strdup(name);
            nr_symbols++;
        }
        else if(strcmp(type,"Constant") == 0)
        {
            symbol_table[nr_symbols].value = strdup(value);
            symbol_table[nr_symbols].var_type = strdup(var_type);
            symbol_table[nr_symbols].type = strdup(type);
            symbol_table[nr_symbols].name = strdup(name);
            nr_symbols++;
        }
        else if(strcmp(type,"Vector") == 0)
        {
            symbol_table[nr_symbols].name = strdup(name);
            symbol_table[nr_symbols].type = strdup(type);
            symbol_table[nr_symbols].var_type = strdup(var_type);
            symbol_table[nr_symbols].value = strdup(value);
            int n = atoi(value);
            nr_symbols++;
            for(int i = 0; i<n; i++)
            {
                addSymbol("Variable",vectorVarName(name, i),NULL, var_type);    
            }
        }
    }
    else
    {
        if(strcmp(type, "Constant"))
            yyerror("Error! Redeclaration of variable");
        return -1;
    }
    return 0;
}



void printOneSymbol(symbol s)
{
    cout<<s.type<<" "<<s.var_type<<" "<<s.name<<" "<<s.value<<'\n';
}

void printSymbols()
{
    for(int i = 0; i<nr_symbols; i++)
        printOneSymbol(symbol_table[i]);
}   
