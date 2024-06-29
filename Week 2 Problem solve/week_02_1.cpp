////Write a program that takes user input (string) and shows......
//if any KEYWORDS are present in the sentence

#include<bits/stdc++.h>
#include<unordered_set>

using namespace std;

int main() {

    unordered_set<string> keywords = {"int", "float", "double", "char", "if", "else", "switch", "case", "for", "while", "do", "return"};

    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    int wordCount = 0;
    bool inWord = false;

    for (char ch : input)
        {
            if (isspace(ch))
            {
                if (inWord)
                {
                    ++wordCount;
                    inWord = false;
                }
            }
            else
                {
                    inWord = true;
                }
        }

    if (inWord)
        {
            ++wordCount;
        }



    string* words = new string[wordCount];


    int index = 0;
    string word = "";
    for (char ch : input)
        {
            if (isspace(ch))
            {
                if (!word.empty())
                {
                    words[index++] = word;
                    word = "";
                }
            }
            else
            {
                word += ch;
            }
        }

    if (!word.empty())
        {
            words[index++] = word;
        }


    bool foundKeywords = false;
    for (int i = 0; i < wordCount; ++i)
        {
            if (keywords.find(words[i]) != keywords.end())
            {
                if (!foundKeywords)
                {
                    cout << "Keywords found in the string: ";
                    foundKeywords = true;
                }
            cout << words[i] << " ";
            }
        }


    if (!foundKeywords)
        {
            cout << "No keywords found in the string." << endl;
        }
    else
        {
            cout << endl;
        }


    delete[] words;

    return 0;
}
