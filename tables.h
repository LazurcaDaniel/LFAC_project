#include <iostream>
#include <cstring>

using namespace std;

// Definirea structurii pentru simbolurile variabilelor
struct Symbol
{
    char* dataType; // "int", "char", etc.
    char* variableType; // "variable", "constant", "class"
    char* name; // numele variabilei
    char* value; // valoarea variabilei
} symbolTable[1000];

// Definirea structurii pentru parametrii
struct ParameterStruct
{
    char* type;
    char* typeInfo;
};

// Definirea structurii pentru simbolurile de funcții
struct FunctionSymbol
{
    char* name; // numele funcției
    char* variableType; // tipul de variabilă al funcției
    char* parameters; // parametrii funcției
    char* typeParameters; // tipurile de parametrii ai funcției
    char* functionScope; // domeniul de aplicare al funcției
} functionTable[20];

// Definirea structurii pentru simbolurile de clasă
struct ClassSymbol
{
    char* className; // numele clasei
    char* type; // tipul clasei (variabilă sau funcție)
    int index; // indexul clasei
} classTable[100];

int numberOfSymbols = 0;

char* lastType = nullptr;

// Funcție pentru actualizarea ultimului tip
void updateLastType(char* newType)
{
    if (lastType != nullptr) {
        free(lastType);
    }
    // Alocare memorie pentru noul tip și copierea acestuia
    lastType = (char*)malloc(strlen(newType) + 1);
    lastType = strdup(newType);
}

// Funcție pentru căutarea unui simbol
int searchSymbol(char* name)
{
    for (int i = 0; i < numberOfSymbols; i++)
        if (!strcmp(symbolTable[i].name, name))
            return i;
    return -1;
}

// Funcție pentru căutarea unei funcții
int searchFunction(char* functionName) {
    for (int i = 0; i < fcount; i++) {
        if (strcmp(functionTable[i].name, functionName) == 0) {
            return i;
        }
    }
    return -1;
}

// Funcție pentru modificarea valorii unei variabile
void modifyVariableValue(int position, char* newValue)
{
    strcpy(symbolTable[position].value, newValue);
}

// Funcție pentru adăugarea unui simbol
void addSymbol(char* type, char* name, char* value, char* variableType)
{
    int isAlreadyPresent = searchSymbol(name);
    if (isAlreadyPresent == -1)
    {
        if (strcmp(type, "Variable") == 0)
        {
            if (value != nullptr)
                symbolTable[numberOfSymbols].value = strdup(value);
            symbolTable[numberOfSymbols].variableType = strdup(variableType);
            symbolTable[numberOfSymbols].dataType = strdup(type);
            symbolTable[numberOfSymbols].name = strdup(name);
            numberOfSymbols++;
        }
        else if (strcmp(type, "Constant") == 0)
        {
            symbolTable[numberOfSymbols].value = strdup(value);
            symbolTable[numberOfSymbols].variableType = strdup(variableType);
            symbolTable[numberOfSymbols].dataType = strdup(type);
            symbolTable[numberOfSymbols].name = strdup(name);
            numberOfSymbols++;
        }
    }
}

// Funcție pentru adăugarea unei funcții
int addFunction(char* functionName, char* typeParameters, char* parameters) {
    int index = searchFunction(functionName);

    if (index != -1) {
        printf("Function name '%s' already exists.\n", functionName);
        return -1;
    }

    functionTable[fcount].name = strdup(functionName);
    functionTable[fcount].parameters = strdup(parameters);
    functionTable[fcount].typeParameters = strdup(typeParameters);
    functionTable[fcount].variableType = strdup(lastDeclaredFunctionType);
    functionTable[fcount].functionScope = strdup(lastFunctionScope);

    fcount++;
    return fcount - 1;
}

// Funcție pentru adăugarea unei clase
void addClass(char* className) {
    for (int i = 0; i < count; i++) {
        if (!strcmp(symbolTable[i].scope, className)) {
            classTable[classCount++] = (struct ClassSymbol) {
                .className = strdup(className),
                .type = strdup(symbolTable[i].dataType),
                .index = i
            };
        }
    }

    for (int i = 0; i < fcount; i++) {
        if (!strcmp(functionTable[i].functionScope, className)) {
            classTable[classCount++] = (struct ClassSymbol) {
                .className = strdup(className),
                .type = strdup("Function"),
                .index = i
            };
        }
    }
}
// Funcția addVariableClass este responsabilă pentru adăugarea unei variabile într-o clasă sau într-o funcție, în funcție de tipul clasei.
void addVariableClass(char *class_name, char *var_name) {
    int class_index = -1;

    // Caută clasa în class_table
    for (int i = 0; i < classCount; i++) {
        if (!strcmp(class_name, class_table[i].class_name)) {
            class_index = i;
            break;
        }
    }

    // Verifică dacă clasa a fost găsită în tabela de clase
    if (class_index == -1) {
        yyerror("There is no class declared with the given name!"); // Afisează eroare în cazul în care clasa nu a fost găsită
        return;
    }

    // Verifică tipul clasei: Funcție sau Variabilă
    if (!strcmp(class_table[class_index].type, "Function")) {
        // Dacă clasa este o funcție, adăugați variabila în function_table
        int function_index = class_table[class_index].index;

        char *name = strdup(var_name);
        strcat(name, ".");
        strcat(name, function_table[function_index].name);

        // Adaugă variabila în function_table
        function_table[fcount].name = strdup(name);
        function_table[fcount].parameters = strdup(function_table[function_index].parameters);
        function_table[fcount].type_parameters = strdup(function_table[function_index].type_parameters);
        function_table[fcount].var_type = strdup(function_table[function_index].var_type);
        function_table[fcount].function_scope = strdup(lastFunctionScope);

        fcount++;
    } else {
        // Dacă clasa este o variabilă, adăugați variabila în symbol_table
        int variable_index = class_table[class_index].index;

        char *name = strdup(var_name);
        strcat(name, ".");
        strcat(name, symbol_table[variable_index].name);

        // Adaugă variabila în symbol_table
        symbol_table[count].name = strdup(name);
        symbol_table[count].var_type = strdup(symbol_table[variable_index].var_type);
        symbol_table[count].type = strdup(symbol_table[variable_index].type);
        symbol_table[count].value = "0"; 
        symbol_table[count].scope = strdup(lastScope);

        count++;
    }
}

// Functie pentru a verifica tipul 
bool isCustomType(char *type) {
    // Lista cu tipurile de bază predefinite
    const char* basicTypes[] = { "int", "char", "float", "string", "bool" };
    
    // Numărul de tipuri de bază
    const int numBasicTypes = sizeof(basicTypes) / sizeof(basicTypes[0]);

    // Verifică dacă tipul dat este unul dintre tipurile de bază
    for (int i = 0; i < numBasicTypes; ++i) {
        if (strcmp(type, basicTypes[i]) == 0) {
            return false; // Este un tip de bază
        }
    }

    return true; // Nu este un tip de bază, deci este un tip personalizat
}
// Funcție pentru a obține numele clasei asociate cu o variabilă
char* getClassFromVariable(const char* variableName) {
    for (int i = 0; i < count; ++i) {
        if (strcmp(variableName, symbol_table[i].name) == 0) {
            return strdup(symbol_table[i].var_type);
        }
    }
    return NULL;
}

// Funcție pentru a găsi indexul unei variabile în tabelul de simboluri
int findSymbolIndex(const char* name) {
    for (int i = 0; i < count; ++i) {
        if (strcmp(name, symbol_table[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

// Funcție pentru a compune numele membrului clasei
char* composeClassName(const char* variableName, const char* memberName) {
    char* className = strdup(variableName);
    strcat(className, ".");
    strcat(className, memberName);
    return className;
}

// Funcția principală care atribuie valoarea membrilor claselor
void assignClass(char* left, char* right) {
    char* class_name = getClassFromVariable(left);

    if (class_name != NULL) {
        for (int i = 0; i < count; ++i) {
            if (strcmp(symbol_table[i].scope, class_name) == 0) {
                char* left_member_name = composeClassName(left, symbol_table[i].name);
                char* right_member_name = composeClassName(right, symbol_table[i].name);

                int index_left = findSymbolIndex(left_member_name);
                int index_right = findSymbolIndex(right_member_name);

                if (index_left != -1 && index_right != -1) {
                    symbol_table[index_left].value = strdup(symbol_table[index_right].value);
                }
            }
        }
    } else {
        // Tratați cazurile speciale sau eroarea pentru un tip non-custom sau nedetectat
    }
}



// Funcție pentru afișarea unui simbol
void printOneSymbol(Symbol s)
{
    cout << s.dataType << " " << s.variableType << " " << s.name << " " << s.value << '\n';
}

// Funcție pentru afișarea tuturor simbolurilor
void printSymbols()
{
    for (int i = 0; i < numberOfSymbols; i++)
        printOneSymbol(symbolTable[i]);
}
