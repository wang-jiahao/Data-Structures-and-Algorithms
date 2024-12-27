#include <iostream>
#include <string>
#include <vector>

using namespace std;

int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; ++j) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int insertion = dp[i][j - 1] + 1;
            int deletion = dp[i - 1][j] + 1;
            int substitution = dp[i - 1][j - 1] + (word1[i - 1] == word2[j - 1] ? 0 : 1);
            dp[i][j] = min(insertion, min(deletion, substitution));
        }
    }
    return dp[n][m];
}

int main() {
    string word1 = "horse";
    string word2 = "ros";
    cout << minDistance(word1, word2) << endl;
    return 0;
}
