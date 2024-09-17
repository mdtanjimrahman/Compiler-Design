#include <bits/stdc++.h>
using namespace std;

// check digit
bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}

// Check alphabet
bool isAlpha(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}




// deleting initial and end whitespace. Searched google and got a few help with syntax
string trim(const string& str)
{
    int first = 0;
    int last = str.length() - 1;

    // finding 1st non whitespace char
    while (first <= last && isspace(str[first]))
    {
        first++;
    }

    // finding last non whitespace char
    while (last >= first && isspace(str[last]))
    {
        last--;
    }

    // returning substr from 1st to last
    return str.substr(first, last - first + 1);
}




// C++ keywords (used CHATGPT to generate keywords to be honest)
const char* keywords[] =
    {
        "auto", "break", "case", "char", "const", "continue", "default", "do", "double",
        "else", "enum", "extern", "float", "for", "goto", "if", "int", "long",
        "register", "return", "short", "signed", "sizeof", "static", "struct", "switch",
        "typedef", "union", "unsigned", "void", "volatile", "while", "bool", "catch",
        "class", "const_cast", "delete", "dynamic_cast", "explicit", "export", "false",
        "friend", "inline", "mutable", "namespace", "new", "operator", "private",
        "protected", "public", "reinterpret_cast", "static_cast", "template", "this",
        "throw", "true", "try", "typeid", "typename", "using", "virtual"
    };



// Number of keywords
const int numKeywords = sizeof(keywords) / sizeof(keywords[0]);

// check if string is a C++ keyword
bool isKeyword(const string& word)
{
    for (int i = 0; i < numKeywords; ++i)
        {
            if (word == keywords[i]) return true;
        }
        return false;
}

// check if string is a variable name
bool isValidVariableName(const string& name)
{
    if (name.empty() || (!isAlpha(name[0]) && name[0] != '_'))      return false; //format seen in doc file without using any block or colon
    for (char c : name)
        {
            if (!isAlpha(c) && !isDigit(c) && c != '_')         return false;
        }
        return !isKeyword(name);
}

// check if string is a valid int
bool isInteger(const string& str)
{
    if (str.empty())     return false;
    for (char c : str)
        {
            if (!isDigit(c) && c != '-' && c != '+') return false;
        }
        return true;
}

// check if a string is a valid float number
bool isFloat(const string& str)
{
    bool hasDot = false;
    if (str.empty())    return false;
    for (char c : str)
        {
            if (c == '.')
            {
                if (hasDot)     return false;
                hasDot = true;
            }
            else if (!isDigit(c) && c != '-' && c != '+')
                {
                    return false;
                }
        }
        return true;
}

// check if a string is a valid char
bool isChar(const string& str)
{
    return str.length() == 3 && str[0] == '\'' && str[2] == '\'';
}

// check if a string is a valid bool
bool isBool(const string& str)
{
    return str == "true" || str == "false";
}






// check if a variable declare is valid.....got a bit help from my friend

bool isValidVariableDeclaration(const string& declaration) {
    string trimming = trim(declaration);

    // Check if ends with semicolon
    if (trimming.back() != ';') return false;

    // Remove semicolon
    trimming.pop_back();

    size_t firstSpace = trimming.find(' ');
    if (firstSpace == string::npos) return false;

    string dataType = trimming.substr(0, firstSpace);
    string rest = trim(trimming.substr(firstSpace + 1));

    size_t possible = rest.find('=');
    if (possible == string::npos) return false;

    string varName = trim(rest.substr(0, possible));
    string assignedValue = trim(rest.substr(possible + 1));



    // Valid data type or not
    if (!isKeyword(dataType)) return false;

    // Valid variable name or not
    if (!isValidVariableName(varName)) return false;



    // Valid assign value based on data type ......... Only checked for int, float, double, char and bool
    if (dataType == "int")
        {
            if (!isInteger(assignedValue)) return false;
        }
        else if (dataType == "float" || dataType == "double")
            {
                if (!isFloat(assignedValue)) return false;
            }
        else if (dataType == "char")
            {
                if (!isChar(assignedValue)) return false;
            }
        else if (dataType == "bool")
            {
                if (!isBool(assignedValue)) return false;
            }
        else
            {
                return false; // unsupported data type
            }

    return true;
}




int main()
{
    string declaration;

    cout << "Declare a variable: ";
    getline(cin, declaration);

    if (isValidVariableDeclaration(declaration))
        {
            cout << "Declaration is valid." << endl;
        }
    else
        {
            cout << "Declaration is invalid." << endl;
        }

    return 0;
}
