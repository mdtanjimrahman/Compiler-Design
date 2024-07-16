#include<bits/stdc++.h>  //universal header, used STL
using namespace std;

void keywordCheck()
{
    // C++ keywords (used GOOGLE for searching all keywords)
    // declared an unordered_set named "keywords" that store element type string
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




    string input;  // variable to store user input



    // getline to read entire line of text from the user (cin) into the string 'input'
    // allows user input to use spaces in the string
    cout << "Enter a string: ";
    getline(cin, input);
    cout<<"\n";




    int wordCount = 0;  //counter variable to keep track of number of words
    bool inWord = false; //flag to indicate whether currently inside a word


    for (char ch : input) //iterating each character in the input string over and over again
        {
            if (isspace(ch)) // checks the current character is whitespace or not
            {
                if (inWord) // checks if currently inside a word
                {
                    ++wordCount; //if reached the end of the word, increment the word counter
                    inWord = false; //set inWord flag to false, when no longer inside a word
                }
            }
            else
                {
                    inWord = true; //current character is not a whitespace, so still inside a word. Flag to true
                }
        }


    if (inWord)
        {
            ++wordCount; //after loop ends, if still inside a word, increment the word counter
        }



    string* words = new string[wordCount]; //pointer to allocate array of strings to store the words
                                           //array size = the number of words counted


    int index = 0;  //index variable to keep track of the position in 'words' array
    string word = "";  //an empty string to collect character one by one to build a word. This works as a container



    for (char ch : input)
        {
            if (isspace(ch)) // checks the current character is whitespace or not
            {
                if (!word.empty()) //if current word is not empty, reached the end of the word
                {
                    words[index++] = word; //store the current word in the 'words' array at next index
                    word = ""; //reset the 'word' string to initial state
                }
            }
            else
            {
                word += ch; //if the current character is not whitespace, add it to empty 'word' string
            }
        }

        if (!word.empty()) //if current word is not empty, reached the end of the word
            {
                words[index++] = word; //store the current word in the 'words' array at next index
            }



            bool foundKeywords = false; //bool variable to check if keywords are found or not, initially flase
            for (int i = 0; i < wordCount; ++i) // loop through each word in the 'words' array
                {
                    if (keywords.find(words[i]) != keywords.end()) //if the current word is a keyword by looking it up in the 'keywords' set
                    {
                        if (!foundKeywords) //if the keyword is found, print "Keywords found: " and setting bool value to true.
                        {
                            cout << "Keywords found: ";
                            foundKeywords = true;
                        }
                    cout << words[i] << " ";
                    }
                }


                if (!foundKeywords) //if no keywords are found, print "No keywords found"
                    {
                        cout << "No keywords found" << endl;
                    }
                else
                    {
                        cout << endl;
                    }

                    delete[] words; // Delete the allocated array to free memory
                    return;
}




int main()
{
    keywordCheck(); //calls the whole function to execute
    return 0;
}

