// C++ program to evaluate a given expression


#include <bits/stdc++.h>
using namespace std;

// A utility function to check if a given character is operand
bool isOperand(char c) { return (c >= '0' && c <= '9'); }

// utility function to find value of and operand
int value(char c) {  return (c - '0'); }

// This function evaluates simple expressions. It returns -1 if the
// given expression is invalid.
int evaluate(char *exp)
{
    // Base Case: Given expression is empty
    if (*exp == '\0')  return -1;

    if (!isOperand(exp[0])) return -1;

    // The first character must be an operand, find its value
    int res = value(exp[0]);

    int operatorCount = 0;

    // Traverse the remaining characters in pairs
    for (int i = 1; exp[i]; i += 1)
    {
        // The next character must be an operator, and
        // next to next an operand
        char current = exp[i];
        char prev = exp[i - 1];

        // If next to next character is not an operand
        if (!isOperand(current) && current != '+' && current != '-' && current != '*' && current != '/')  return -1;

        // Update result according to the operator
        if (current == '+' || current == '-' || current == '*' || current == '/') {
            operatorCount++;

            // The next character must be an operand
            if (!isOperand(exp[i + 1])) return -1;

            // Update result according to the operator
            if (current == '+') res += value(exp[i + 1]);
            else if (current == '-') res -= value(exp[i + 1]);
            else if (current == '*') res *= value(exp[i + 1]);
            else if (current == '/') res /= value(exp[i + 1]);

            ++i; // Skip the next character as it has been processed
        }
    }

    // Check if the last character is an operator (which is invalid)
    if (exp[strlen(exp) - 1] == '+' || exp[strlen(exp) - 1] == '-' || exp[strlen(exp) - 1] == '*' || exp[strlen(exp) - 1] == '/') {
        return -1;
    }

    cout << "The number of operators in the expression: " << operatorCount << endl;

    return res;
}


// Driver program to test above function
int main()
{
    int MAX_LENGTH = 100;
    char expr1[MAX_LENGTH];
    int i = 0;

    cout << "Enter a mathematical expression: ";

    // Read characters one by one until newline or array is full
    char ch;
    while (i < MAX_LENGTH - 1 && (ch = cin.get()) != '\n') {
        expr1[i++] = ch;
    }
    expr1[i] = '\0'; // Null-terminate the array

    cout << "You entered: " << expr1 << endl;

    int res = evaluate(expr1);
    if (res == -1)
        {
            cout << expr1 << " is Invalid\n";
        }
    else
        {
            cout << "The value of the expression " << expr1 << " is " << res << endl;
        }

    return 0;
}

