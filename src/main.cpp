#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ifstream input("../io/example.in");
    if (!input) {
        cerr << "Could not open file example.in";
        return 1;
    }

    int K;
    input >> K;

    unordered_map<char, int> value;
    while (K--) {
        char key;
        input >> key;
        input >> value[key];
    }

    string A, B;
    input >> A;
    input >> B;
    A = '#' + A;  // filler character so that indexed accesses are nicer
    B = '#' + B;  // "

    input.close();

    // algorithm
    size_t m = A.size();
    size_t n = B.size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if (A[i] == B[j]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + value[A[i]]);
            }
        }
    }

    ofstream output("../io/example.out");
    if (!output) {
        cerr << "Could not open file example.out";
        return 1;
    }

    output << dp[m-1][n-1] << endl;

    // backtracking
    string res;
    int i = m - 1;
    int j = n - 1;
    while (i > 0 && j > 0) {
        if (A[i] == B[j] && dp[i][j] == dp[i-1][j-1] + value[A[i]]) {
            res += A[i];
            i -= 1;
            j -= 1;
        }
        else if (dp[i][j] == dp[i-1][j]) {
            i -= 1;
        }
        else {
            j -= 1;
        }
    }

    reverse(res.begin(), res.end());
    output << res;
    output.close();

    return 0;
}