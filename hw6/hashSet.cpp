#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;
        unordered_map<int, bool> uop;
        while (n--) {
            int x;
            cin >> x;
            if (uop.find(x) == uop.end()) {
                arr.push_back(x);
                uop[x] = true;
            }
        }
        for (auto i: arr) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}