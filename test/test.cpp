#include "../src/algo.h"
#include <chrono>

long long runAlgo(ifstream& fd) {
    auto processed = processInput(fd);
    unordered_map<char, int> value = processed.first;
    string A = processed.second.first;
    string B = processed.second.second;

    auto start = chrono::high_resolution_clock::now();
    algo(A, B, value);
    auto end = chrono::high_resolution_clock::now();

    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    cout << "T = " << elapsed << " ns" << endl;

    return elapsed;
}

int main() {
    vector<string> exampleNames;
    vector<long long> T;

    for (int i = 1; i <= 10; i++) {
        string fd = "example" + to_string(i) + ".in";
        exampleNames.push_back(fd);
        ifstream input("../test/io/" + fd);
        auto t = runAlgo(input);
        T.push_back(t);
    }

    ofstream myfile;
    myfile.open("../test/io/runtimes.csv");
    myfile << "filename,T\n";
    for (int i = 0; i < T.size(); i++) {
        myfile << exampleNames[i] << "," << T[i] << "\n";
    }
    myfile.close();

    // manually run graph.py at this point

    return 0;
}