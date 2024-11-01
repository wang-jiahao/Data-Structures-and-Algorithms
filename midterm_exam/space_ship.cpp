#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct child {
    int number;
    int weight;
};

int compare_number(child a, child b) {
    return a.number < b.number;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<child> children(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> children[i].number >> children[i].weight;
        sum += children[i].weight;
    }
    sort(children.begin(), children.end(), compare_number);
    int sum1 = sum / 2;
    int sum2 = 0;
    if (sum % 2 == 0) {
        sum2 = sum1;
    } else {
        sum2 = sum1 + 1;
    }
    int temp_sum = 0;
    for (int i = 0; i < n; ++i) {
        if ((temp_sum < sum1) && (sum - temp_sum - children[i].weight) <= sum2) {
            cout << children[i].number << endl;
            return 0;
        }
        temp_sum += children[i].weight;
    }

    return 0;
}