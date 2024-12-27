#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int num;
    vector<int> a;
    while (cin >> num) {
        a.push_back(num);
    }
    int n = a.size();
    vector<int> candies(n, 1);
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] < a[i + 1]) {
            candies[i + 1] = candies[i] + 1;
        }
    }
    for (int i = n - 1; i > 0; --i) {
        if (a[i] < a[i - 1]) {
            candies[i - 1] = max(candies[i - 1], candies[i] + 1);
        }
    }
    cout << accumulate(candies.begin(), candies.end(), 0) << endl;

    return 0;
}
