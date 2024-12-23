#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int num;
    vector<int> arr;
    while (cin >> num) {
        arr.push_back(num);
    }
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if (sum % 2 == 1) {
        cout << "0" << endl;
        return 0;
    }
    int target = sum / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = target; j >= arr[i]; --j) {
            dp[j] = dp[j] || dp[j - arr[i]];
        }
    }
    cout << (dp[target] ? "1" : "0") << endl;

    return 0;
}
