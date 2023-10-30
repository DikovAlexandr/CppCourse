#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> findLCS(const vector<int>& sequence1, const vector<int>& sequence2) {
    int n = sequence1.size();
    int m = sequence2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Fill dp
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (sequence1[i - 1] == sequence2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Get result
    int i = n, j = m;
    vector<int> lcs;
    while (i > 0 && j > 0) {
        if (sequence1[i - 1] == sequence2[j - 1]) {
            lcs.push_back(sequence1[i - 1]);
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main() {
    ifstream input("INPUT.txt");
    ofstream output("OUTPUT.txt");

    int n, m;
    input >> n;
    vector<int> sequence1(n);
    for (int i = 0; i < n; i++) {
        input >> sequence1[i];
    }
    input >> m;
    vector<int> sequence2(m);
    for (int i = 0; i < m; i++) {
        input >> sequence2[i];
    }

    // Find LCS
    vector<int> lcs = findLCS(sequence1, sequence2);

    for (int k = 0; k < lcs.size(); k++) {
        output << lcs[k];
        if (k < lcs.size() - 1) {
            output << " ";
        }
    }

    input.close();
    output.close();

    return 0;
}