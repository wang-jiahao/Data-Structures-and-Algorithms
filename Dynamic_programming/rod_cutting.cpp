#include <iostream>
#include <vector>

using namespace std;

int max_price(vector<int> prices, int n) {
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            dp[i] = max(dp[i], prices[j] + dp[i - j - 1]);
        }
    }
    return dp[n];
}

int main() {
    vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20};
    cout << max_price(prices, 8) << endl;

    return 0;
}
