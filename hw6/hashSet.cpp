#include <iostream>
#include <unordered_set>
#include <vector>

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
        unordered_set<int> set;
        while (n--) {
            int x;
            cin >> x;
            if (set.find(x) == set.end()) {
                set.insert(x);
                arr.push_back(x);
            }
        }
        for (auto i: arr) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
