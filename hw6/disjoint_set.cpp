#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    unordered_map<int, unordered_set<int>> uop;
    while (n--) {
        int opr, x, y;
        cin >> opr >> x >> y;
        if (opr == 1) {
            if (uop.find(x) == uop.end()) {
                unordered_set<int> s;
                s.insert(x);
                uop[x] = s;
            }
            if (uop.find(y) == uop.end()) {
                unordered_set<int> s;
                s.insert(y);
                uop[y] = s;
            }
            uop[x].merge(uop[y]);
            for (auto i: uop[x]) {
                uop[i] = uop[x];
            }
        } else if (opr == 2) {
            if (uop.find(x) == uop.end() || uop.find(y) == uop.end()) {
                cout << 0 << endl;
            } else if (uop[x] == uop[y]) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }
    return 0;
}
