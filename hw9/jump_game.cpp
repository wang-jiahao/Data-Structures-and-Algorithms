#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    vector<int> arr;
    int x;
    while (cin >> x) {
        arr.push_back(x);
    }
    int n = arr.size();
    int jump = 0;
    int curr = 0;
    while (curr < n - 1) {
        if (curr + arr[curr] >= n - 1) {
            jump++;
            break;
        }
        unordered_map<int, int> map;
        int maximum = 0;
        for (int i = 1; i <= arr[curr]; ++i) {
            int dist = i + arr[curr + i];
            maximum = max(maximum, dist);
            map[dist] = i;
        }
        curr += map[maximum];
        jump++;
    }
    cout << jump << endl;

    return 0;
}
