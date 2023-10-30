#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> findLIS(const vector<int>& sequence) {
    int n = sequence.size();

    vector<int> dp(n, 1);
    vector<int> prev(n, -1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (sequence[i] > sequence[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
    }

    // Find minimal element index
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (dp[i] > dp[maxIndex]) {
            maxIndex = i;
        }
    }

    // Get LIS
    vector<int> lis;
    while (maxIndex != -1) {
        lis.push_back(sequence[maxIndex]);
        maxIndex = prev[maxIndex];
    }

    reverse(lis.begin(), lis.end());
    return lis;
}

int main() {
    ifstream input("INPUT.txt");
    ofstream output("OUTPUT.txt");

    int n;
    input >> n;

    vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        input >> sequence[i];
    }

    // Find LIS
    vector<int> lis = findLIS(sequence);

    for (int i = 0; i < lis.size(); i++) {
        output << lis[i];
        if (i < lis.size() - 1) {
            output << " ";
        }
    }

    input.close();
    output.close();

    return 0;
}
