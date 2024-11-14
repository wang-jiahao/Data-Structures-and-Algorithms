#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main() {
    list<int> lst;
    string cmd;
    int x;
    while (cin >> cmd) {
        if (cmd == "pushFront") {
            cin >> x;
            lst.push_front(x);
        } else if (cmd == "pushBack") {
            cin >> x;
            lst.push_back(x);
        } else if (cmd == "search") {
            cin >> x;
            auto iter = find(lst.begin(), lst.end(), x);
            iter == lst.end() ? cout << 0 << endl : cout << 1 << endl;
        } else if (cmd == "remove") {
            cin >> x;
            lst.remove(x);
        } else if (cmd == "print") {
            for (auto i: lst) {
                cout << i << " ";
            }
            cout << endl;
        }
    }
    return 0;
}