#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a;
    cin >> a;
    vector<int> arr;
    int num;
    while (cin >> num) {
        arr.push_back(num);
    }
    vector<int> dp(a + 1, 0);
    dp[0] = 1;
    for (auto coin: arr) {
        for (int i = coin; i <= a; i++) {
            dp[i] += dp[i - coin];
        }
    }
    cout << dp[a] << endl;

    return 0;
}
