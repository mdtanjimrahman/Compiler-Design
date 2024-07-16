#include<bits/stdc++.h> //universal header, used STL
using namespace std;


bool Syntax(const string& input) //Boolean function to check syntax of the input string
{
    stack<char> syntaxStack; //empty stack to store character and keep track of opening brackets
    char prevChar = '\0'; //variable to store the previous character, set to null
    int special = 0;  //counter variable to track special characters

    for (char ch : input) //iterating each character in the input string over and over again
        {

            if (ch == '(')
            {
                syntaxStack.push(ch); //push '(' into the stack
            }
            else if (ch == ')')
            {

                if (syntaxStack.empty()) //if stack is empty when getting only ')', return true (syntax error)
                {
                    return true;
                }
                syntaxStack.pop(); //pop '(' from the stack
            }


            else if (ch == '{')
            {
                syntaxStack.push(ch); //push '{' into the stack
            }
            else if (ch == '}')
            {

                if (syntaxStack.empty()) //if stack is empty when getting only '}', return true (syntax error)
                {
                    return true;
                }
                syntaxStack.pop(); //pop '{' from the stack
            }



            else if (ch == '[')
            {
                syntaxStack.push(ch); //push '[' into the stack
            }
            else if (ch == ']')
            {

                if (syntaxStack.empty()) //if stack is empty when getting only ']', return true (syntax error)
                {
                    return true;
                }
                syntaxStack.pop(); //pop '[' from the stack
            }



            else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '=')
            {
                //checks if the current character is one of the operators: (+, -, *, /, %, =)
                if ((ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '=') && ch == prevChar)
                {
                    return true; //if the current character is a operator and it is the same as previous operator character
                                 //then it indicates consecutive operator
                                 //returning true for indicating syntax error
                }
            }



            else if (!isalnum(ch) || isspace(ch)) //checks if the character is not alphanumeric or not whitespace
            {
                return true; //returning true for indicating syntax error
            }

            prevChar = ch; //store the current character as the previous character
        }

    return !syntaxStack.empty();  //checks if the stack is not empty, it indicates there are unmatched opening brackets
                                  //which is wrong syntax. returning true if the stack is not empty (syntax error)
}



int main()
{
    string input; //variable to store user input

    // getline to read entire line of text from the user (cin) into the string 'input'
    // allows user input to use spaces in the string
    cout << "Enter the expression: ";
    getline(cin, input);

    if (Syntax(input)) //call the 'Syntax' function to check for syntax errors in the input
        {
            cout << "Syntax error detected!" << endl;
        }
    else
        {
            cout << "No syntax error detected." << endl;
        }

    return 0;
}
