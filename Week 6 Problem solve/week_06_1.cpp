#include <bits/stdc++.h>
using namespace std;


struct NFA
{
    int num_states;
    set<int> accept_states;
    map<int, map<char, set<int>>> transitions; // state -> input -> set of states
};


struct DFA
{
    int num_states;
    set<int> accept_states;
    map<int, map<char, int>> transitions; // state -> input -> new state
};

// Function to print DFA
void printDFA(const DFA& dfa)
{
    cout << "DFA States: " << dfa.num_states << "\n";
    cout << "DFA Accept States: ";
    for (int final_state : dfa.accept_states)
        cout << final_state << " ";

    cout << endl;

    cout << "DFA Transitions:\n";
    for (const auto& state : dfa.transitions)
    {
        for (const auto& trans : state.second)
            cout << "From state " << state.first << " on '" << trans.first << "' -> state " << trans.second << "\n";

    }
}

// Subset Construction Algorithm: Convert NFA to DFA
DFA convertNFAToDFA(const NFA& nfa, const set<char>& alphabet, const set<int>& start_state)
{
    map<set<int>, int> nfa_to_dfa_state; // NFA state sets -> DFA state
    vector<set<int>> dfa_states;         // Store DFA states ]
    DFA dfa;

    queue<set<int>> state_queue;
    state_queue.push(start_state);
    dfa_states.push_back(start_state);
    nfa_to_dfa_state[start_state] = 0;
    dfa.num_states = 1;

    while (!state_queue.empty())
    {
        set<int> current_nfa_states = state_queue.front();
        state_queue.pop();
        int current_dfa_state = nfa_to_dfa_state[current_nfa_states];

        // Process all input symbols in the alphabet
        for (char input : alphabet)
        {
            set<int> new_nfa_states;

            // For each NFA state in the current DFA state, find transitions on 'input'
            for (auto state : current_nfa_states)
            {
                if (nfa.transitions.count(state) && nfa.transitions.at(state).count(input))
                {
                    const set<int>& next_states = nfa.transitions.at(state).at(input);
                    new_nfa_states.insert(next_states.begin(), next_states.end());
                }
            }

            // If a new set of NFA states is generated
            if (!new_nfa_states.empty())
            {
                // If the set of NFA states hasn't been assigned a DFA state yet
                if (nfa_to_dfa_state.find(new_nfa_states) == nfa_to_dfa_state.end())
                {
                    nfa_to_dfa_state[new_nfa_states] = dfa.num_states++;
                    dfa_states.push_back(new_nfa_states);
                    state_queue.push(new_nfa_states);
                }
                // Add the DFA transition
                dfa.transitions[current_dfa_state][input] = nfa_to_dfa_state[new_nfa_states];
            }
        }
    }

    // Mark DFA accept states
    for (auto i = 0; i < dfa_states.size(); ++i)
    {
        for (auto nfa_state : dfa_states[i])
        {
            if (nfa.accept_states.count(nfa_state))
            {
                dfa.accept_states.insert(i);
                break;
            }
        }
    }

    return dfa;
}

int main()
{
    int alpha;
    cout << "Number of Alphabet: ";
    cin >> alpha;

    set<char> alphabet;
    cout << "Enter the alphabets: ";
    char value;
    for (int i = 0; i < alpha; i++)
    {
        cin >> value;
        alphabet.insert(value);
    }


    NFA nfa; // Define the NFA

    cout << "Enter the number of states: ";
    cin >> nfa.num_states;

    set<int> start_state;
    int starting_state;
    cout << "Enter the starting state: ";
    cin >> starting_state;
    start_state.insert(starting_state);

    cout << "Enter the number of accepted state(s): ";
    int num_accept_states;
    cin >> num_accept_states;

    cout << "Enter the accepted states: ";
    for (auto i = 0; i < num_accept_states; i++)
    {
        int accept_state;
        cin >> accept_state;
        nfa.accept_states.insert(accept_state);
    }

    // Input transitions for state and alphabet
    for (auto i = 0; i < nfa.num_states; i++)
    {
        for (auto ch : alphabet)
        {
            int transitions;
            cout << "Enter the number of transitions from state " << i << " on '" << ch << "': ";
            cin >> transitions;

           if (transitions > 0)
           {
                cout << "Enter the transition states: ";

                set<int> transitionSet;
                while (transitions--)
                {
                    int target_state;
                    cin >> target_state;
                    transitionSet.insert(target_state);
                }

                nfa.transitions[i][ch] = transitionSet; // // Store
           }

        }
    }


    DFA dfa = convertNFAToDFA(nfa, alphabet, start_state);
    printDFA(dfa);

    return 0;
}



   /*
    // Transitions: state -> input -> set of states
    // nfa.transitions[0]['a'] = {0, 1};
    // nfa.transitions[1]['b'] = {2};

    // Alphabet (allowed inputs)
    // set<char> alphabet = {'a', 'b'};

    // Convert NFA to DFA
    DFA dfa = convertNFAToDFA(nfa, alphabet);

    // Print DFA
    printDFA(dfa);

    return 0;
}
*/
