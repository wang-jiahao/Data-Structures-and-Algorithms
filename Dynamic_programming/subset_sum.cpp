#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

bool canPartition(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 == 1) { return false; }
    int target = sum / 2;
    vector<bool> dp(target + 1);
    dp[0] = true;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = target; j >= nums[i]; j--) {
            dp[j] = dp[j] || dp[j - nums[i]];
        }
    }
    return dp[target];
}

int main() {
    return 0;
}
