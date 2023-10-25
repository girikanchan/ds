#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>

using namespace std;

// Define a structure to represent a production rule
struct ProductionRule {
    char nonTerminal;  // The non-terminal symbol
    vector<string> productions;  // The right-hand side productions
};

// Function to calculate the FIRST set
void calculateFirstSet(map<char, set<char>>& first, char nonTerminal, vector<ProductionRule>& grammar) {
    // Rule 01: If X -> ε is a production, then add ε to FIRST(X)
    for (ProductionRule rule : grammar) {
        if (rule.nonTerminal == nonTerminal) {
            for (string production : rule.productions) {
                if (production == "ε") {
                    first[nonTerminal].insert('ε');
                }
            }
        }
    }

    // Rule 02: If X is a terminal, then FIRST(X) = {X}
    if (isalpha(nonTerminal) && !isupper(nonTerminal)) {
        first[nonTerminal].insert(nonTerminal);
    }

    // Rule 03: For X -> Y1Y2Y3...Yn, calculate FIRST(X)
    for (ProductionRule rule : grammar) {
        if (rule.nonTerminal == nonTerminal) {
            for (string production : rule.productions) {
                bool allYiProduceEpsilon = true;
                for (char Yi : production) {
                    calculateFirstSet(first, Yi, grammar);
                    for (char x : first[Yi]) {
                        first[nonTerminal].insert(x);
                    }
                    if (first[Yi].find('ε') == first[Yi].end()) {
                        allYiProduceEpsilon = false;
                        break;
                    }
                }
                if (allYiProduceEpsilon) {
                    first[nonTerminal].insert('ε');
                }
            }
        }
    }
}

// Function to calculate the FOLLOW set
void calculateFollowSet(map<char, set<char>>& follow, char nonTerminal, vector<ProductionRule>& grammar) {
    // Rule 01: For the start symbol S, add $ to FOLLOW(S)
    if (nonTerminal == 'S') {
        follow['S'].insert('$');
    }

    // Rule 02: For X -> αB, add FIRST(α) to FOLLOW(B)
    for (ProductionRule rule : grammar) {
        for (string production : rule.productions) {
            for (size_t i = 0; i < production.size(); i++) {
                if (production[i] == nonTerminal) {
                    for (size_t j = i + 1; j < production.size(); j++) {
                        calculateFirstSet(follow, production[j], grammar);
                        for (char x : follow[production[j]]) {
                            follow[nonTerminal].insert(x);
                        }
                        if (follow[production[j]].find('ε') == follow[production[j]].end()) {
                            break;
                        }
                    }
                }
            }
        }
    }

    // Rule 03: For X -> αBβ, add FOLLOW(X) to FOLLOW(B)
    for (ProductionRule rule : grammar) {
        for (string production : rule.productions) {
            for (size_t i = 0; i < production.size(); i++) {
                if (production[i] == nonTerminal) {
                    bool betaProducesEpsilon = true;
                    for (size_t j = i + 1; j < production.size(); j++) {
                        calculateFirstSet(follow, production[j], grammar);
                        for (char x : follow[production[j]]) {
                            follow[nonTerminal].insert(x);
                        }
                        if (follow[production[j]].find('ε') == follow[production[j]].end()) {
                            betaProducesEpsilon = false;
                            break;
                        }
                    }
                    if (betaProducesEpsilon) {
                        for (char x : follow[rule.nonTerminal]) {
                            follow[nonTerminal].insert(x);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    // Define the grammar
    vector<ProductionRule> grammar = {
        {'S', {"aBDh"}},
        {'B', {"cC"}},
        {'C', {"bC", "ε"}},
        {'D', {"EF"}},
        {'E', {"g", "ε"}},
        {'F', {"f", "ε"}}
    };

    // Create data structures to store FIRST and FOLLOW sets
    map<char, set<char>> first;
    map<char, set<char>> follow;

    // Calculate FIRST and FOLLOW sets for each non-terminal
    for (char nonTerminal = 'A'; nonTerminal <= 'Z'; nonTerminal++) {
        calculateFirstSet(first, nonTerminal, grammar);
        calculateFollowSet(follow, nonTerminal, grammar);
    }

    // Display FIRST sets
    cout << "FIRST sets:" << endl;
    for (char nonTerminal = 'A'; nonTerminal <= 'Z'; nonTerminal++) {
        if (!first[nonTerminal].empty()) {
            cout << "FIRST(" << nonTerminal << ") = { ";
            for (char x : first[nonTerminal]) {
                cout << x << " ";
            }
            cout << "}" << endl;
        }
    }

    // Display FOLLOW sets
    cout << "FOLLOW sets:" << endl;
    for (char nonTerminal = 'A'; nonTerminal <= 'Z'; nonTerminal++) {
        if (!follow[nonTerminal].empty()) {
            cout << "FOLLOW(" << nonTerminal << ") = { ";
            for (char x : follow[nonTerminal]) {
                cout << x << " ";
            }
            cout << "}" << endl;
        }
    }

    return 0;
}
