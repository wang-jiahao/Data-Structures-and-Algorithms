#include <iostream>
#include <vector>
#include <climits>

const int INF = INT_MAX;

using namespace std;

int minimum_multiplication(vector<int> &dims) {
    int n = dims.size() - 1;
    vector<vector<int> > dp(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; ++i) {
        dp[i][i] = 0;
    }
    for (int l = 2; l <= n; ++l) {
        for (int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1;
            for (int k = i; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + dims[i - 1] * dims[k] * dims[j]);
            }
        }
    }
    return dp[1][n];
}

int main() {
    vector<int> dims = {30, 35, 15, 5, 10, 20, 25};
    cout << minimum_multiplication(dims) << endl;

    return 0;
}
