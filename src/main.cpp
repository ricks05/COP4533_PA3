#include "algo.h"

int main() {
    ifstream input("../src/io/example.in");
    if (!input) {
        cerr << "Could not open file example.in";
        return 1;
    }

    auto processed = processInput(input);
    unordered_map<char, int> value = processed.first;
    string A = processed.second.first;
    string B = processed.second.second;

    input.close();

    ofstream output("../src/io/example.out");
    if (!output) {
        cerr << "Could not open file example.out";
        return 1;
    }

    auto res = algo(A, B, value);
    output << res.first << endl;
    output << res.second;

    output.close();

    return 0;
}