#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    vector<int> scores;
    int x;
    while (cin >> x) {
        scores.push_back(x);
    }
    int n = scores.size();
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> candies(n, 1);
    //往右递归
    for (int i = 1; i < n; i++) {
        if (scores[i] > scores[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }
    //往左递归
    for (int i = n - 2; i >= 0; i--) {
        if (scores[i] > scores[i + 1]) {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }
    cout << accumulate(candies.begin(), candies.end(), 0) << endl;

    return 0;
}
