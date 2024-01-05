#include <iostream>
#include <cstring>

using namespace std;

struct symbol
{
    char* type; //int, char, etc
    char* var_type; // variable, constant, class
    char* name; //name of the variable
    char* value; //value of the variable
    char* scope; //scope of the variable
}symbol_table[1000];//table of symbols
struct function_symbol
{
    char* name;//name of the function
    char* var_type;//type of the function
    char * parameters;//parameters of the function
    char * type_parameters;//type of the parameters
    char * function_scope;//scope of the function
}function_table[20];//table of functions
struct class_symbol
{
    char * class_name;//name of the class
    char * type;//type of the class
    int index;//index of the class
}class_table[100];//table of classes

char lastDeclaredType[20];//last declared type
char lastDeclaredFunctionType[20];//last declared function type
int nr_funct = 0;// number of functions
int nr_symbols = 0;//number of symbols
int nr_classes = 0;//number of classes
char lastScope[60] = "Global";//last scope
char lastFunctionScope[20] = "Global";//last function scope

char* lastType = NULL; // Ultimul tip de variabilă declarat

void updateLastType(char* newType)// Updatează ultimul tip de variabilă declarat
{
    if (lastType != NULL) {
        free(lastType);
    }// Eliberează memoria alocată pentru ultimul tip de variabilă declarat
    // Allocate memory for the new type and copy it
    lastType = (char*)malloc(strlen(newType) + 1);// Alocă memorie pentru noul tip de variabilă și copiază-l
    lastType = strdup(newType);// Copiază noul tip de variabilă
}

int search(char *name)//search for a symbol
{
    for(int i = 0; i < nr_symbols; i++)//search in the symbol table
        if(!strcmp(symbol_table[i].name,name))//if the symbol is found
            return i;//return the position
    return -1;//else return -1
}
int searchFunction(char *c)//search for a function
{
    for(int i = 0; i < nr_funct; i++)//search in the function table
        if(strcmp(c,function_table[i].name) == 0)//if the function is found
            return i;//return the position
    return -1;//    else return -1
}  

void modifyVarValue(int pos, char* newValue)//modify the value of a variable
{
    strcpy(symbol_table[pos].value,newValue);//modify the value
}

void addSymbol(char *type, char* name, char* value, char* var_type)//add a symbol
{
    int isHereAlready = search(name);//search for the symbol
    if(isHereAlready == -1)//if the symbol is not found
    {
        if(strcmp(type, "Variable") == 0)//if the type is variable
        {
            if(value != NULL)//if the value is not null
            symbol_table[nr_symbols].value = strdup(value);//copy the value
            symbol_table[nr_symbols].var_type = strdup(var_type);//copy the variable type
            symbol_table[nr_symbols].type = strdup(type);//copy the type
            symbol_table[nr_symbols].name = strdup(name);//copy the name
            symbol_table[nr_symbols].scope = strdup(lastScope);//copy the scope
            nr_symbols++;//increment the number of symbols
        }
        else if(strcmp(type,"Constant") == 0)//if the type is constant
        {
            symbol_table[nr_symbols].value = strdup(value);//copy the value
            symbol_table[nr_symbols].var_type = strdup(var_type);//copy the variable type
            symbol_table[nr_symbols].type = strdup(type);//copy the type
            symbol_table[nr_symbols].name = strdup(name);//copy the name
            symbol_table[nr_symbols].scope = strdup(lastScope);//copy the scope
            nr_symbols++;//increment the number of symbols
        }
    }
    
}
void addFunctionType(char *type)//add a function type
{
    strcpy(lastDeclaredFunctionType, type);//copy the type
}
int addFunction(char *name, char* type_parameters, char *parameters)//add a function
{
    int isHereAlready = searchFunction(name);//search for the function
    if(isHereAlready == -1)//if the function is not found
    {
        function_table[nr_funct].name = strdup(name);//copy the name
        function_table[nr_funct].parameters = strdup(parameters);//copy the parameters
        function_table[nr_funct].type_parameters = strdup(type_parameters);//copy the type of the parameters
        function_table[nr_funct].var_type = strdup(lastDeclaredFunctionType);//copy the type of the function
        function_table[nr_funct].function_scope = strdup(lastFunctionScope);//copy the scope of the function
        nr_funct++;//increment the number of functions
        return nr_funct - 1;//return the position
    }
}
void addClass(char * class_name)//add a class
{
    for(int i = 0; i < nr_symbols; i++)//search in the symbol table
    {
        if(!strcmp(symbol_table[i].scope, class_name))//if the scope is the class name
        {   class_table[nr_classes].class_name = strdup(class_name);//  copy the class name
            class_table[nr_classes].type = strdup(symbol_table[i].type);//  copy the type
            class_table[nr_classes].index = i;//  copy the index
            nr_classes++;//increment the number of classes
        }
    }
    for(int i = 0; i < nr_funct; i++)//search in the function table
    {
        if(!strcmp(function_table[i].function_scope, class_name))// if the scope is the class name
        {   class_table[nr_classes].class_name = strdup(class_name);//  copy the class name
            class_table[nr_classes].type = strdup("Function");//  copy the type
            class_table[nr_classes].index = i;//  copy the index
            nr_classes++;//increment the number of classes
        }
    }
}
void addVariableClass(char * class_name, char * var_name)//add a variable in a class
{
    int isHereAlready = -1;//initialize the position
    for(int i = 0; i < nr_classes; i++)//search in the class table
    {
        if(!strcmp(class_name, class_table[i].class_name))//if the class is found
            isHereAlready = i;//save the position
    }
    for(int i = 0; i < nr_classes; ++i)//search in the class table
    {
        if(!strcmp(class_name, class_table[i].class_name))//if the class is found
        {
            if(!strcmp(class_table[i].type, "Function"))//if the type is function
            {
                int index = class_table[i].index;//save the index
                char * name = strdup(var_name);//copy the name
                strcat(name, ".");
                strcat(name, function_table[index].name);
                function_table[nr_funct].name = strdup(name);//copy the name
                function_table[nr_funct].parameters = strdup(function_table[index].parameters);//copy the parameters
                function_table[nr_funct].type_parameters = strdup(function_table[index].type_parameters);//copy the type of the parameters
                function_table[nr_funct].var_type = strdup(function_table[index].var_type);//copy the type of the function
                function_table[nr_funct].function_scope = strdup(lastFunctionScope);//copy the scope of the function
                nr_funct++;//increment the number of functions
            }
            else//if the type is variable
            {
                int index = class_table[i].index;//save the index
                char * name = strdup(var_name);//copy the name
                strcat(name, ".");
                strcat(name, symbol_table[index].name);
                symbol_table[nr_symbols].name = strdup(name);//copy the name
                symbol_table[nr_symbols].var_type = strdup(symbol_table[index].var_type);//copy the variable type
                symbol_table[nr_symbols].type = strdup(symbol_table[index].type);//copy the type
                symbol_table[nr_symbols].value = "0";//copy the value
                symbol_table[nr_symbols].scope = strdup(lastScope);//copy the scope
                nr_symbols++;//increment the number of symbols
            }
        }
    }
}
void printTable() {//print the symbol table
    FILE* file = fopen("symbol_table.txt", "w");//open the file
    if (file == NULL) {//if the file is not found
        printf("Error opening file!\n");//print an error message
        return;//return
    }

    fprintf(file, "VARIABLE TABLE:\n");//print the variable table
    fprintf(file, "NAME\t\tVAR_TYPE\tTYPE\t\tVALUE\t\tSCOPE\n");//print the header
    fprintf(file, "_____________________________________________________________\n");//print the line

    for (int i = 0; i < nr_symbols; i++) {//search in the symbol table
        if (strcmp(symbol_table[i].type, "Constant") == 0) {//if the type is constant
            fprintf(file, "%-15s\t%-15s\t%-15s\t%-15s\t%-15s\n",//print the symbol
                    symbol_table[i].name, symbol_table[i].var_type,//print the symbol
                    symbol_table[i].type, symbol_table[i].value,//print the symbol
                    symbol_table[i].scope);//print the symbol
        }
    }

    fprintf(file, "\nCONSTANTS:\n");//print the constants
    fprintf(file, "NAME\t\tVAR_TYPE\tTYPE\t\tVALUE\t\tSCOPE\n");//print the header
    fprintf(file, "_____________________________________________________________\n");//print the line

    for (int i = 0; i < nr_symbols; i++) {//search in the symbol table
        if (strcmp(symbol_table[i].type, "Constant") == 0) {//if the type is constant
            fprintf(file, "%-15s\t%-15s\t%-15s\t%-15s\t%-15s\n",//print the symbol
                    symbol_table[i].name, symbol_table[i].var_type,//print the symbol
                    symbol_table[i].type, symbol_table[i].value,//print the symbol
                    symbol_table[i].scope);//print the symbol
        }
    }

    fclose(file);//   close the file
}

void printFunctionTable() {//print the function table
    FILE* file = fopen("function_table.txt", "w");//open the file
    if (file == NULL) {//if the file is not found
        printf("Error opening file!\n");//print an error message
        return;//return
    }

    fprintf(file, "Function Table:\n\n");//print the function table
    fprintf(file, "Name\t\tReturn Type\tParameters\n");//print the header
    fprintf(file, "-----------------------------------\n");//print the line

    for (int i = 0; i < nr_funct; i++) {//search in the function table
        fprintf(file, "%s\t\t%s\t\t%s\n", function_table[i].name, function_table[i].var_type,//print the function
                function_table[i].parameters);//print the function
    }

    fclose(file);//close the file
}

bool isCustomType(char *type) {
    const char* basicTypes[] = { "int", "char", "float", "string", "bool" };//array of basic types
    const int numBasicTypes = sizeof(basicTypes) / sizeof(basicTypes[0]);//number of basic types
    for (int i = 0; i < numBasicTypes; ++i) {//search in the array
        if (strcmp(type, basicTypes[i]) == 0) {//if the type is found
            return false; // Return false if the type is a basic type    
        }
    }

return true;//return true if the type is not a basic type
}


void assignClass(char* left, char* right)
{
    char* class_name = nullptr;//initialize the class name
    
    // Find the class name of the left variable
    for (int i = 0; i < nr_symbols; i++)
    {
        if (strcmp(left, symbol_table[i].name) == 0)//if the left variable is found
        {
            class_name = strdup(symbol_table[i].var_type);//copy the class name
            break;//break the loop
        }
    }
        for (int i = 0; i < nr_symbols; i++)//search in the symbol table
    {
        if (strcmp(symbol_table[i].scope, class_name) == 0)//if the scope is the class name
        {
            char* left_member_name = strdup(left);//copy the left variable
            strcat(left_member_name, ".");//concatenate the left variable with a dot
            strcat(left_member_name, symbol_table[i].name);//concatenate the left variable with the name of the member
            
            char* right_member_name = strdup(right);//copy the right variable
            strcat(right_member_name, ".");//concatenate the right variable with a dot
            strcat(right_member_name, symbol_table[i].name);//concatenate the right variable with the name of the member
            
            int index_left = search(left_member_name);//search for the left variable
            int index_right = search(right_member_name);//search for the right variable
            
            if (index_left != -1 && index_right != -1)//    if the variables are found
            {
                symbol_table[index_left].value = strdup(symbol_table[index_right].value);//copy the value
            }
        }
    }
}
bool existsClass(const char* class_name)//check if a class exists
{
    for(int i = 0; i < nr_classes; i++)//search in the class table
    {
        if(strcmp(class_name, class_table[i].class_name) == 0)//if the class is found
            return true;//return true
    }
    return false;//else return false
}
char* createVectorElement(char * identifier, char * index)//create a vector element
{
    char * vectorElement = strdup(identifier);//copy the identifier
    strcat(vectorElement, "[");//concatenate the identifier with a square bracket
    strcat(vectorElement, index);//concatenate the identifier with the index
    strcat(vectorElement, "]");//concatenate the identifier with a square bracket
    return vectorElement;//return the vector element
}
string convertIntToString(int value)//convert an integer to a string
{
    return to_string(value);//return the string
}
void printOneSymbol(symbol s)//print a symbol
{
    cout<<s.type<<" "<<s.var_type<<" "<<s.name<<" "<<s.value<<'\n';//print the symbol
}

void printSymbols()//print the symbols
{
    for(int i = 0; i<nr_symbols; i++)//search in the symbols
        printOneSymbol(symbol_table[i]);//print a symbol
}
void getLastType(char *type)//get the last type
{
    strcpy(type, lastDeclaredType);//copy the last type
}

void updateLastFunctionType(char * type)//update the last function type
{
    strcpy(lastDeclaredFunctionType, type);//copy the last function type
}


void updateLastScope(char * scope)//update the last scope
{
    strcpy(lastScope,scope);//copy the last scope
}

void updateLastFunctionScope(char * functionScope)//update the last function scope
{
    strcpy(lastFunctionScope,functionScope);//copy the last function scope
}

