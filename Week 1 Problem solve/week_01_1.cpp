//Write a program that takes user input (string) and shows......
//the amount of VOWEL, CONSONANT, OPERATOR, BRACKET and SPECIAL CHARACTER

#include<bits/stdc++.h>
using namespace std;

void Count(string s)
{
    int vowel= 0, cons= 0, bracket= 0, special= 0, ope= 0;

    for(int i=0; i<s.length(); i++)
    {
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            c = tolower(c);

            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            {
                ++vowel;
            }
            else
            {
                ++cons;
            }
        }
        else if ( c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '=' )
        {
            ++ope;
        }
        else if ( c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']' )
        {
            ++bracket;
        }
        else if (!isalnum(c) && !isspace(c))
        {
            ++special;
        }
    }


    cout<<" Vowels            : "<< vowel<<endl;
    cout<<" Consonants        : "<< cons<<endl;
    cout<<" Brackets          : "<< bracket<<endl;
    cout<<" Operator          : "<< ope<<endl;
    cout<<" Special character : "<< special<<endl;
}

int main()
{
    string s;

    cout<< "Enter any String: ";
    cin>>s;
    cout<<"\n";

    Count(s);

    return 0;
}
