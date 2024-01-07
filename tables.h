#include <iostream>
#include <cstring>

using namespace std;



struct symbol
{
    char *type;         // int, char, etc
    char *var_type;     // variable, constant, class
    char *name;         // name of the variable
    char *value;        // value of the variable
    char *scope;        // scope of the variable
} symbol_table[100000]; // table of symbols

struct parameters
{
    char *type;
    char *type_and_name;
};

struct function_symbol
{
    char *name;            // name of the function
    char *var_type;        // type of the function
    char *parameters;      // parameters of the function
    char *type_parameters; // type of the parameters
    char *function_scope;  // scope of the function
} function_table[20];      // table of functions
struct class_symbol
{
    char *class_name; // name of the class
    char *type;       // type of the class
    int index;        // index of the class
} class_table[100];   // table of classes

char lastDeclaredType[20];             // last declared type
char lastDeclaredFunctionType[20];     // last declared function type
int nr_funct = 0;                      // number of functions
int nr_symbols = 0;                    // number of symbols
int nr_classes = 0;                    // number of classes
char lastScope[60] = "Global";         // last scope
char lastFunctionScope[20] = "Global"; // last function scope

char lastClassName[60];

char *lastType = NULL; // Ultimul tip de variabilă declarat

void updateLastType(char *newType) // Updatează ultimul tip de variabilă declarat
{
    if (lastType != NULL)
    {
        free(lastType);
    } // Eliberează memoria alocată pentru ultimul tip de variabilă declarat
    // Allocate memory for the new type and copy it
    lastType = (char *)malloc(strlen(newType) + 1); // Alocă memorie pentru noul tip de variabilă și copiază-l
    lastType = strdup(newType);                     // Copiază noul tip de variabilă
}

int search(char *name) // search for a symbol
{
    for (int i = 0; i < nr_symbols; i++) // search in the symbol table
        if (strcmp(symbol_table[i].type, "Constant") != 0)
        {
            if (!strcmp(symbol_table[i].name, name) && (!strcmp(symbol_table[i].scope,lastScope) || !strcmp(symbol_table[i].scope,"Global"))) // if the symbol is found
                return i;// return the position
        } 
        else
        {
            if (!strcmp(symbol_table[i].name, name))
                return i;// return the position
        }
    return -1; // else return -1
}
int searchFunction(char *c) // search for a function
{
    for (int i = 0; i < nr_funct; i++)              // search in the function table
        if (strcmp(c, function_table[i].name) == 0) // if the function is found
            return i;                               // return the position
    return -1;                                      //    else return -1
}

void modifyVarValue(int pos, char *newValue) // modify the value of a variable
{
    if (symbol_table[pos].value == NULL)
        symbol_table[pos].value = (char *)malloc(strlen(newValue) + 1);
    strcpy(symbol_table[pos].value, newValue); // modify the value
}

char *makeVectorName(char *name, int index)
{
    char i[15];
    int cnt = 0;
    if (index == 0)
    {
        i[0] = '0';
        cnt++;
    }
    else
    {
        while (index)
        {
            i[cnt] = (char)(index % 10) + '0';
            cnt++;
            index /= 10;
        }
    }
    i[cnt] = '\0';
    for (int j = 0; j < cnt / 2; j++)
        swap(i[j], i[cnt - j - 1]);

    char *res = (char *)malloc(strlen(name) + strlen(i) + 1);
    strcpy(res, name);
    strcat(res, "[");
    strcat(res, i);
    strcat(res, "]");
    res[strlen(res)] = '\0';
    return res;
}

char *getVectorIndexName(char *name, char *index)
{
    char *res = (char *)malloc(strlen(name) + strlen(index) + 1);
    strcpy(res, name);
    strcat(res, "[");
    strcat(res, index);
    strcat(res, "]");
    res[strlen(res)] = '\0';
    return res;
}

void addSymbol(const char *type, char *name, char *value, char *var_type) // add a symbol
{
    int isHereAlready = search(name); // search for the symbol
    if (isHereAlready == -1)          // if the symbol is not found
    {
        if (strcmp(type, "Variable") == 0) // if the type is variable
        {
            if (value != NULL)                                    // if the value is not null
                symbol_table[nr_symbols].value = strdup(value);   // copy the value
            symbol_table[nr_symbols].var_type = strdup(var_type); // copy the variable type
            symbol_table[nr_symbols].type = strdup(type);         // copy the type
            symbol_table[nr_symbols].name = strdup(name);         // copy the name
            symbol_table[nr_symbols].scope = strdup(lastScope);   // copy the scope
            nr_symbols++;                                         // increment the number of symbols
        }
        else if (strcmp(type, "Constant") == 0) // if the type is constant
        {
            symbol_table[nr_symbols].value = strdup(value);       // copy the value
            symbol_table[nr_symbols].var_type = strdup(var_type); // copy the variable type
            symbol_table[nr_symbols].type = strdup(type);         // copy the type
            symbol_table[nr_symbols].name = strdup(name);         // copy the name
            symbol_table[nr_symbols].scope = strdup(lastScope);   // copy the scope
            nr_symbols++;                                         // increment the number of symbols
        }
        else if (strcmp(type, "Vector") == 0)
        {
            symbol_table[nr_symbols].value = strdup(value);
            symbol_table[nr_symbols].var_type = strdup(var_type);
            symbol_table[nr_symbols].type = strdup(type);
            symbol_table[nr_symbols].name = strdup(name);
            symbol_table[nr_symbols].scope = strdup(lastScope);
            nr_symbols++;
            int n = atoi(value);
            for (int i = 0; i < n; i++)
            {
                addSymbol("Variable", makeVectorName(name, i), NULL, var_type);
            }
        }
    }
}

void getLastType(char *type)
{
    strcpy(lastDeclaredType, type);
}

void updateLastScope(char *scope)
{
    strcpy(lastScope, scope);
}

void updateLastFuncScope(char *scope)
{
    strcpy(lastFunctionScope, scope);
}

void addFunctionType(char *type) // add a function type
{
    strcpy(lastDeclaredFunctionType, type); // copy the type
}
int addFunction(char *name, char *type_parameters, char *parameters) // add a function
{
    int isHereAlready = searchFunction(name); // search for the function
    if (isHereAlready == -1)                  // if the function is not found
    {
        function_table[nr_funct].name = strdup(name);                         // copy the name
        function_table[nr_funct].parameters = strdup(parameters);             // copy the parameters
        function_table[nr_funct].type_parameters = strdup(type_parameters);   // copy the type of the parameters
        function_table[nr_funct].var_type = strdup(lastDeclaredFunctionType); // copy the type of the function
        function_table[nr_funct].function_scope = strdup(lastFunctionScope);  // copy the scope of the function
        nr_funct++;                                                           // increment the number of functions
        return nr_funct - 1;                                                  // return the position
    }
    else
        return -1;
}

void updateLastClassName(char* name)
{
    strcpy(lastClassName,name);
}

void addClass(char *class_name) // add a class
{
    for (int i = 0; i < nr_symbols; i++) // search in the symbol table
    {
        if (!strcmp(symbol_table[i].scope, class_name)) // if the scope is the class name
        {
            class_table[nr_classes].class_name = strdup(class_name);     //  copy the class name
            class_table[nr_classes].type = strdup(symbol_table[i].type); //  copy the type
            class_table[nr_classes].index = i;                           //  copy the index
            nr_classes++;                                                // increment the number of classes
        }
    }
    for (int i = 0; i < nr_funct; i++) // search in the function table
    {
        if (!strcmp(function_table[i].function_scope, class_name)) // if the scope is the class name
        {
            class_table[nr_classes].class_name = strdup(class_name); //  copy the class name
            class_table[nr_classes].type = strdup("Function");       //  copy the type
            class_table[nr_classes].index = i;                       //  copy the index
            nr_classes++;                                            // increment the number of classes
        }
    }
}
void addVariableClass(char *class_name, char *var_name) // add a variable in a class
{
    int isHereAlready = -1;              // initialize the position
    for (int i = 0; i < nr_classes; i++) // search in the class table
    {
        if (!strcmp(class_name, class_table[i].class_name)) // if the class is found
            isHereAlready = i;                              // save the position
    }
    for (int i = 0; i < nr_classes; ++i) // search in the class table
    {
        if (!strcmp(class_name, class_table[i].class_name)) // if the class is found
        {
            if (!strcmp(class_table[i].type, "Function")) // if the type is function
            {
                int index = class_table[i].index; // save the index
                char *name = strdup(var_name);    // copy the name
                strcat(name, ".");
                strcat(name, function_table[index].name);
                function_table[nr_funct].name = strdup(name);                                             // copy the name
                function_table[nr_funct].parameters = strdup(function_table[index].parameters);           // copy the parameters
                function_table[nr_funct].type_parameters = strdup(function_table[index].type_parameters); // copy the type of the parameters
                function_table[nr_funct].var_type = strdup(function_table[index].var_type);               // copy the type of the function
                function_table[nr_funct].function_scope = strdup(lastFunctionScope);                      // copy the scope of the function
                nr_funct++;                                                                               // increment the number of functions
            }
            else // if the type is variable
            {
                int index = class_table[i].index; // save the index
                char *name = strdup(var_name);    // copy the name
                strcat(name, ".");
                strcat(name, symbol_table[index].name);
                symbol_table[nr_symbols].name = strdup(name);                             // copy the name
                symbol_table[nr_symbols].var_type = strdup(symbol_table[index].var_type); // copy the variable type
                symbol_table[nr_symbols].type = strdup(symbol_table[index].type);         // copy the type
                strcpy(symbol_table[nr_symbols].value, "0");                              // copy the value
                symbol_table[nr_symbols].scope = strdup(lastScope);                       // copy the scope
                nr_symbols++;                                                             // increment the number of symbols
            }
        }
    }
}
bool isCustomType(char *type)
{
    const char *basicTypes[] = {"int", "char", "float", "string", "bool"}; // array of basic types
    const int numBasicTypes = sizeof(basicTypes) / sizeof(basicTypes[0]);  // number of basic types
    for (int i = 0; i < numBasicTypes; ++i)
    { // search in the array
        if (strcmp(type, basicTypes[i]) == 0)
        {                 // if the type is found
            return false; // Return false if the type is a basic type
        }
    }

    return true; // return true if the type is not a basic type
}

void printOneSymbol(symbol s) // print a symbol
{
    cout << s.type << " " << s.var_type << " " << s.name << " "; // print the symbol
    if (s.value != NULL)
        cout << s.value;
    cout << " " << s.scope;
    cout << '\n';
}

void printSymbols() // print the symbols
{
    cout << "SYMBOLS!\n";
    for (int i = 0; i < nr_symbols; i++) // search in the symbols
    {
        printOneSymbol(symbol_table[i]);
    } // print a symbol
}

void printOneFunc(function_symbol f)
{  
    cout << f.var_type << " " << f.name << " " << f.type_parameters << " " << f.parameters << " " << f.function_scope << '\n';
}

void printFunctions()
{
    cout << "FUNCTIONS!\n";
    for (int i = 0; i < nr_funct; i++)
        printOneFunc(function_table[i]);
}

char* itoa(int nr)
{
    char* res = (char*)malloc(20);
    int cnt = 0;
    if(nr == 0)
    {
        res[0] = '0';
        cnt++;
    }
    else
    {
        while(nr)
        {
            res[cnt++] = (char)(nr%10) + '0';
            nr/=10;
        }
    }
    res[cnt] = '\0';
    for(int i = 0; i < cnt/2; i++)
        swap(res[i],res[cnt - i - 1]);
    return res;
}