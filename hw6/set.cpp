#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    set<int> s;
    int n;
    cin >> n;
    while (n--) {
        int opr, x;
        cin >> opr >> x;
        if (opr == 1) {
            s.insert(x);
        } else if (opr == 2) {
            cout << (s.find(x) == s.end() ? 1 : 0) << endl;
        } else if (opr == 3) {
            s.erase(x);
        } else if (opr == 4) {
            cout << distance(s.upper_bound(x), s.end()) << endl;
        }
    }
    return 0;
}
