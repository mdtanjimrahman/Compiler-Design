//LEXICAL analysis

#include <bits/stdc++.h>
using namespace std;

// Method to check a given sentence for given rules
bool checkSentence(char str[]) {
    // Calculate the length of the string.
    int len = strlen(str);

    // Check that the first character lies in [A-Z].
    if (str[0] < 'A' || str[0] > 'Z')
        return false;

    // If the last character is not a full stop (.), no need to check further.
    if (str[len - 1] != '.')
        return false;

    // Maintain two states: previous and current state based on which vertex state you are.
    // Initialize both with 0 = start state.
    int prev_state = 0, curr_state = 0;

    // Keep the index to the next character in the string.
    int index = 1;

    // Loop to go over the string.
    while (str[index]) {
        // Set states according to the input characters in the string and the rules defined.
        // If the current character is [A-Z], set current state as 0.
        if (str[index] >= 'A' && str[index] <= 'Z')
            curr_state = 0;
        // If the current character is a space, set current state as 1.
        else if (str[index] == ' ')
            curr_state = 1;
        // If the current character is [a-z], set current state as 2.
        else if (str[index] >= 'a' && str[index] <= 'z')
            curr_state = 2;
        // If the current character is a dot (.), set current state as 3.
        else if (str[index] == '.')
            curr_state = 3;
        else
            return false; // Invalid character

        // Validate all current state with previous state for the rules in the problem description.
        if (prev_state == curr_state && curr_state != 2)
            return false;

        if (prev_state == 2 && curr_state == 0)
            return false;

        // If we have reached the last state and the previous state is not 1,
        // then check the next character. If the next character is '\0', return true, else false.
        if (curr_state == 3 && prev_state != 1)
            return (str[index + 1] == '\0');

        index++;

        // Set the previous state as the current state before going over to the next character.
        prev_state = curr_state;
    }
    return false;
}

// Driver program
int main() {
    const int MAX_LENGTH = 1000; // Assuming a reasonable maximum length for input
    char str[MAX_LENGTH];

    cout << "Enter a sentence to check: ";
    cin.getline(str, MAX_LENGTH);

    if (checkSentence(str)) {
        cout << "\"" << str << "\" is correct" << endl;
    } else {
        cout << "\"" << str << "\" is incorrect" << endl;
    }

    return 0;
}
