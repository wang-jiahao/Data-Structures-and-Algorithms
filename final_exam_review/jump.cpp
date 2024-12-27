#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int num;
    vector<int> arr;
    while (cin >> num) {
        arr.push_back(num);
    }
    int n = arr.size();
    int jumps = 0; // 跳跃次数
    int curr = 0;
    while (curr < n - 1) {
        if (curr + arr[curr] >= n - 1) {
            jumps++;
            break;
        }
        unordered_map<int, int> udp;
        int maximum = 0;
        for (int i = 1; i <= arr[curr]; ++i) {
            udp[i + arr[i + curr]] = i;
            maximum = max(maximum, i + arr[i + curr]);
        }
        curr += udp[maximum];
        jumps++;
    }

    cout << jumps << endl;

    return 0;
}
