#include<bits/stdc++.h>
using namespace std;

void keywordCheck()
{
    // C++ keywords (used CHATGPT to generate keywords to be honest)
    unordered_set<string> keywords =
                {   "int", "float", "double", "char", "if", "else", "switch", "case",
                     "for", "while", "do", "return", "void", "bool", "const", "enum",
                     "struct", "class", "public", "private", "protected", "virtual",
                     "override", "static", "inline", "namespace", "using", "typedef",
                     "template", "typename", "new", "delete", "this", "friend", "operator",
                     "sizeof", "try", "catch", "throw", "default", "break", "continue",
                     "goto", "extern", "volatile", "mutable", "register", "signed",
                     "unsigned", "short", "long"
                };

    string input;
    cout << "Enter a string: ";
    getline(cin, input);
    cout<<"\n";

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
                                    cout << "Keywords found: ";
                                    foundKeywords = true;
                                }
                            cout << words[i] << " ";
                            }
                        }


                        if (!foundKeywords)
                            {
                                cout << "No keywords found" << endl;
                            }
                        else
                            {
                                cout << endl;
                            }

                            delete[] words;
                            return;


}


int main()
{
    keywordCheck();
    return 0;
}
