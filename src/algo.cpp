#include "algo.h"

pair<unordered_map<char, int>, pair<string, string>> processInput(ifstream& fd) {
    int K;
    fd >> K;

    unordered_map<char, int> value;
    while (K--) {
        char key;
        fd >> key;
        fd >> value[key];
    }

    string A, B;
    fd >> A;
    fd >> B;
    A = '#' + A;  // filler character so that indexed accesses are nicer
    B = '#' + B;  // "

    return make_pair(value, make_pair(A, B));
}

pair<int, string> algo(string& A, string& B, unordered_map<char, int>& value) {
    // find max value
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

    pair<int, string> res;

    res.first = dp[m-1][n-1];

    // backtracking for sequence
    int i = m - 1;
    int j = n - 1;

    while (i > 0 && j > 0) {
        if (A[i] == B[j] && dp[i][j] == dp[i-1][j-1] + value[A[i]]) {
            res.second += A[i];
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

    reverse(res.second.begin(), res.second.end());
    return res;
}