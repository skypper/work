#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>

using namespace std;

const char eps = '\0';

const string symbols("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789\\* ");
const set<char> alphabet(symbols.begin(), symbols.end());

class Node {
    unordered_multimap<char, int> next;
    int _index;

public:
    Node() {}

    void addTransition(int to, char with) {
        next.emplace(with, to);
    }

    vector<pair<char, int>> edges() {
        return vector<pair<char,int>>(next.begin(), next.end());
    }

    vector<int> goesTo(char with) {
        vector<int> result;

        auto ret = next.equal_range(with);
        for (auto it = ret.first; it != ret.second; ++it) {
            result.push_back(it->second);
        }

        return result;
    }

    void setIndex(int index) {
        _index = index;
    }

    void makeAsterisk() {
        for (char symbol : alphabet) {
            addTransition(_index, symbol);
        }
    }
};

class SubstrAutomaton {
    int n;
    vector<Node> states;
    vector<bool> isFinal;

    string _input;
    bool accepted;

public:
    SubstrAutomaton(string &pattern) :
        n(pattern.size()),
        states(n + 1),
        isFinal(n + 1, 0) {

        for (int i = 0; i < n + 1; ++i) {
            states[i].setIndex(i);
        }
        for (int i = 0; i < n; ++i) {
            char symbol = pattern[i];

            if (symbol == '\\' && i + 1 < pattern.size() && pattern[i + 1] == '*') {
                addTransition(i, i + 1, eps);
            } else if (symbol == '*' && i >= 1 && pattern[i - 1] != '\\') {
                states[i].makeAsterisk();
                addTransition(i, i + 1, eps);
            } else if (symbol == '*' && i == 0) {
                states[i].makeAsterisk();
                addTransition(0, 1, eps);
            } else {
                addTransition(i, i + 1, symbol);
            }
        }
        states[0].makeAsterisk();
        states[n].makeAsterisk();
        isFinal[n] = 1;
    }

    void setInput(string &input) {
        _input = input;
    }

    bool isAccepted() {
        accepted = false;
        process();

        return accepted;
    }
    bool isAccepted(string &input) {
        setInput(input);

        accepted = false;
        process();

        return accepted;
    }
private:
    void process(int current = 0, int config_offset = 0) {
        if (!accepted) {
            if (isFinal[current]) {
                accepted = true;
            } else if (config_offset < _input.size()) {
                Node x = states[current];
                for (pair<char, int> edge : x.edges()) {
                    char symbol = edge.first;
                    int next = edge.second;

                    if (symbol != eps) {
                        if (symbol == _input[config_offset]) {
                            process(next, config_offset + 1);
                        }
                    } else {
                        process(next, config_offset);
                    }
                }
            }
        }
    }
    void addTransition(int from, int to, char with) {
        states[from].addTransition(to, with);
    }
};

int main(int argc, char *argv[])
{
    ifstream inputFile;
    string lineBuffer;

    inputFile.open(argv[1]);

    while (!inputFile.eof()) {
        getline(inputFile, lineBuffer);

        if (lineBuffer.empty())
            continue;

        size_t pos = lineBuffer.find_first_of(',');
        string text(lineBuffer.substr(0, pos));
        string pattern(lineBuffer.substr(pos + 1, lineBuffer.size()));

        if (pattern.size() > text.size()) {
            cout << "false\n";
        } else {
            SubstrAutomaton T(pattern);
            cout << (T.isAccepted(text) ? "true" : "false") << "\n";
        }
    }

    return 0;
}
