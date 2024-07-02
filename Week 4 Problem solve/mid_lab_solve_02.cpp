#include<bits/stdc++.h>
using namespace std;

bool Syntax(const string& input)
{
    stack<char> syntaxStack;
    char prevChar = '\0';
    bool prevOpe = false;
    int special = 0;

    for (char ch : input)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            syntaxStack.push(ch);
            prevOpe = false;
        }

        else if (ch == ')' || ch == '}' || ch == ']')
            {
                if (syntaxStack.empty())
                {
                    return true;
                }

                syntaxStack.pop();
                prevOpe = false;
            }

        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '=')
            {
                if (prevOpe)
                {
                    return true;
                }

                prevOpe = true;
            }

        else if (isalnum(ch))
            {
                prevOpe = false;
            }

        else if (!isspace(ch))
            {
                return true;
            }

            prevChar = ch;
    }

    return !syntaxStack.empty();
}



int main()
{
    string input;
    cout << "Enter the expression: ";
    getline(cin, input);

    if (Syntax(input))
        {
            cout << "Syntax error detected!" << endl;
        }
    else
        {
            cout << "No syntax error detected." << endl;
        }

    return 0;
}
