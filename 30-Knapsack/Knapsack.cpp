#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void knapsack(int N, int M, vector<int>& weights, vector<int>& values) {
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0)); // Initialize a 2D array for dynamic programming
    vector<vector<bool>> keep(N + 1, vector<bool>(M + 1, false)); // Initialize a 2D array to keep track of chosen items

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            dp[i][j] = dp[i - 1][j]; // If do not take  
            keep[i][j] = false; // Mark the item as not chosen

            if (j >= weights[i - 1]) {
                int value = dp[i - 1][j - weights[i - 1]] + values[i - 1];
                if (value > dp[i][j]) {
                    dp[i][j] = value; // Update the maximum value
                    keep[i][j] = true; // Mark the item as chosen
                }
            }
        }
    }

    int result = dp[N][M];
    vector<int> chosen_items; // List of chosen items

    for (int i = N, j = M; i > 0; i--) {
        if (keep[i][j]) {
            chosen_items.push_back(i);
            j -= weights[i - 1];
        }
    }

    ofstream output("OUTPUT.txt");

    // output << result << endl;
    // output << chosen_items.size() << endl;

    for (int i = chosen_items.size() - 1; i >= 0; i--) {
        output << chosen_items[i] << endl;
    }

    output.close();
}

int main() {
    ifstream input("INPUT.txt");

    int N, M;
    input >> N >> M;

    vector<int> weights(N), values(N);
    for (int i = 0; i < N; i++) {
        input >> weights[i];
    }

    for (int i = 0; i < N; i++) {
        input >> values[i];
    }

    knapsack(N, M, weights, values);

    input.close();

    return 0;
}
