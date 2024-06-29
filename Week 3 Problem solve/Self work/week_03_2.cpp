//Write a program that takes user input as a function declaration syntax (as string) and analyze......
//if the SYNTAX of Function declaration is valid or not
//   Sample:  int myFunction() { return 0; }  or    void printNumber(int number) { cout << number; }
//                    ->> Function declaration is Valid

#include <iostream>
#include <string>

using namespace std;

// deleting initial and end whitespace. Searched google and found this kind of function on stack_overflow
string trim(const string& str)
{
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == string::npos) return "";
    size_t last = str.find_last_not_of(" \t\n\r");
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

// check if the string is valid function type
bool isValidFunctionTypeOrName(const string& str)
{
    if (str.empty() || isdigit(str[0]) || isKeyword(str)) return false;
    for (char c : str)
        {
            if (!isalnum(c) && c != '_') return false;
        }
    return true;
}



// check for valid function declare.....(googled it found this function from stack_overflow) modified some additional condition

bool isValidFunctionDeclaration(const string& declaration)
{
    string trimmed = trim(declaration);

    // Check for ( ) and { }
    size_t first_bracket_start = trimmed.find('(');
    size_t first_bracket_end = trimmed.find(')');
    size_t second_bracket_start = trimmed.find('{');
    size_t second_bracket_end = trimmed.find('}');

    if (first_bracket_start == string::npos || first_bracket_end == string::npos ||
        second_bracket_start == string::npos || second_bracket_end == string::npos)
        return false;

    // call function type and name
    size_t pos = trimmed.find(' ');
    if (pos == string::npos || pos >= first_bracket_start)
        return false;

    string typeAndName = trimmed.substr(0, pos);
    string params = trimmed.substr(first_bracket_start + 1, first_bracket_end - first_bracket_start - 1);

    // validate function type and name
    size_t lastSpace = typeAndName.find_last_of(' ');
    string type = trim(typeAndName.substr(0, lastSpace));
    string name = trim(typeAndName.substr(lastSpace + 1));

    if (!isValidFunctionTypeOrName(type) || !isValidFunctionTypeOrName(name))
        return false;

    // check parameter section
    bool isValidParams = true;
    int bracketCount = 0;

    for (char c : params)
    {
        if (c == '(')
        {
            bracketCount++;
        }
        else if (c == ')')
        {
            bracketCount--;
        }
        if (bracketCount < 0)
        {
            isValidParams = false;
            break;
        }
    }

    return bracketCount == 0 && isValidParams;
}




int main()
{
    string declaration;
    cout << "Declare a function: ";
    getline(cin, declaration);

    if (isValidFunctionDeclaration(declaration))
        {
            cout << "Function is valid." << endl;
        }
    else
        {
            cout << "Function is invalid." << endl;
        }

    return 0;
}
