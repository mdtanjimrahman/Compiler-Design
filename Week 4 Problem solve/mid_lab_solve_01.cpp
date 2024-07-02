
#include<bits/stdc++.h>
using namespace std;

bool Syntax(const string& input)
{
    stack<char> syntaxStack;
    char prevChar = '\0';
    int special = 0;

    for (char ch : input)
        {

            if (ch == '(')
            {
                syntaxStack.push(ch);
            }
            else if (ch == ')')
            {

                if (syntaxStack.empty())
                {
                    return true;
                }
                syntaxStack.pop();
            }


            else if (ch == '{')
            {
                syntaxStack.push(ch);
            }
            else if (ch == '}')
            {

                if (syntaxStack.empty())
                {
                    return true;
                }
                syntaxStack.pop();
            }



            else if (ch == '[')
            {
                syntaxStack.push(ch);
            }
            else if (ch == ']')
            {

                if (syntaxStack.empty())
                {
                    return true;
                }
                syntaxStack.pop();
            }
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
