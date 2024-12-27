#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;
        unordered_set<int> s;
        while (n--) {
            int number;
            cin >> number;
            if (s.find(number) == s.end()) {
                s.insert(number);
                arr.push_back(number);
            }
        }
        copy(arr.begin(), arr.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }

    return 0;
}
