#include <iostream>
#include <vector>
#include <string>

using namespace std;

class dynamic_array {
private:
    vector<int> arr;
    int Capacity = 10;
public:
    void append(int x) {
        if (arr.size() == Capacity) {
            Capacity *= 2;
        }
        arr.push_back(x);
    }

    void set(int x, int y) {
        arr[x] = y;
    }

    void erase(int x) {
        arr.erase(arr.begin() + x);
        if (arr.size() < Capacity / 2) {
            Capacity /= 2;
        }
    }

    int get(int x) {
        return arr[x];
    }

    int size(void) {
        return arr.size();
    }

    int capacity(void) {
        return Capacity;
    }

    void print(void) {
        for (int i: arr) {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main() {
    dynamic_array darr;
    string cmd;
    while (cin >> cmd) {
        int x, y;
        if (cmd == "append") {
            cin >> x;
            darr.append(x);
        } else if (cmd == "set") {
            cin >> x >> y;
            darr.set(x, y);
        } else if (cmd == "erase") {
            cin >> x;
            darr.erase(x);
        } else if (cmd == "get") {
            cin >> x;
            cout << darr.get(x) << endl;
        } else if (cmd == "size") {
            cout << darr.size() << endl;
        } else if (cmd == "capacity") {
            cout << darr.capacity() << endl;
        } else if (cmd == "print") {
            darr.print();
        }
    }
    return 0;
}