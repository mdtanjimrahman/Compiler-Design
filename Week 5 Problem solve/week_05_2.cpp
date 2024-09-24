#include <bits/stdc++.h>
using namespace std;

struct State
{
    map<char, set<int>> transitions;
};

struct NFA
{
    vector<State> states; //set of states
    int startState;       //start state
    int endState;         //end state
};

//creating new state
int addState(NFA &nfa)
{
    nfa.states.emplace_back();
    return nfa.states.size() - 1;
}

//RE to NFA
NFA REtoNFA(const string &reString)
{
    NFA nfa;
    stack<pair<int, int>> stateStack;
    for (char ch : reString)
    {
        if (isalnum(ch))
        {
            int start = addState(nfa);
            int accept = addState(nfa);
            nfa.states[start].transitions[ch].insert(accept);
            stateStack.push({start, accept});
        }
        else if (ch == '*')
        {
            if (stateStack.empty())
                throw runtime_error("Invalid RE: stack is empty for '*'");

            auto [start, accept] = stateStack.top();
            stateStack.pop();

            int newStart = addState(nfa);
            int newAccept = addState(nfa);

            nfa.states[newStart].transitions['e'].insert(start);
            nfa.states[newStart].transitions['e'].insert(newAccept);
            nfa.states[accept].transitions['e'].insert(start);
            nfa.states[accept].transitions['e'].insert(newAccept);

            stateStack.push({newStart, newAccept});
        }
        else if (ch == '.')
        {
            if (stateStack.size() < 2)
                throw runtime_error("Invalid RE: stack size is less than 2 for '.'");

            auto [start1, accept1] = stateStack.top(); stateStack.pop();
            auto [start2, accept2] = stateStack.top(); stateStack.pop();

            nfa.states[accept1].transitions['e'].insert(start2); //transition to the next state's start
            stateStack.push({start1, accept2});                 // New start and accept
        }
        else if (ch == '|') { // Union
            if (stateStack.size() < 2)
                throw runtime_error("Invalid RE: stack size is less than 2 for '|'");

            auto [start1, accept1] = stateStack.top(); stateStack.pop();
            auto [start2, accept2] = stateStack.top(); stateStack.pop();

            int newStart = addState(nfa);
            int newAccept = addState(nfa);

            //epsilon
            nfa.states[newStart].transitions['e'].insert(start1);
            nfa.states[newStart].transitions['e'].insert(start2);
            nfa.states[accept1].transitions['e'].insert(newAccept);
            nfa.states[accept2].transitions['e'].insert(newAccept);

            stateStack.push({newStart, newAccept});
        }
    }

    if (!stateStack.empty())
    {
        auto [start, accept] = stateStack.top();
        nfa.startState = start;
        nfa.endState = accept;
    }

    return nfa;
}

// Function to print the transition table
void printTransitionTable(const NFA &nfa)
{
    cout << "Transition Table:\n";
    cout << "State\tInput\tNext States\n";
    for (size_t stateIndex = 0; stateIndex < nfa.states.size(); ++stateIndex)
    {
        for (const auto &[input, nextStates] : nfa.states[stateIndex].transitions)
        {
            cout << stateIndex << "\t" << input << "\t";
            for (int nextState : nextStates)
                cout << nextState << " ";

            cout << "\n";
        }
    }
}

int main()
{
    string REexpression;
    cin>>REexpression;
    cout<<"Regular Expression: "<<REexpression<<endl;

    try
    {
        NFA nfa = REtoNFA(REexpression);
        printTransitionTable(nfa);
    }
    catch (const runtime_error &e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
