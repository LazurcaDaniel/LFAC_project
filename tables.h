#include <iostream>
#include <cstring>

using namespace std;

struct symbol
{
    char* type; //int, char, etc
    char* var_type; // variable, constant, class
    char* name; //name of the variable
    char* value; //value of the variable
    //char* scope;
}symbol_table[1000];

int nr_symbols = 0;

char* lastType = NULL; 

void updateLastType(char* newType)
{
    if (lastType != NULL) {
        free(lastType);
    }
    // Allocate memory for the new type and copy it
    lastType = (char*)malloc(strlen(newType) + 1);
    lastType = strdup(newType);
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
    strcpy(symbol_table[pos].value,newValue);
}

void addSymbol(char *type, char* name, char* value, char* var_type)
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
    }
    
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
