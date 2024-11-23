#include <iostream>
#include <vector>

using namespace std;

const int N = 50000;

class hashSet {
private:
    vector<vector<int>> set;

    int hashFunction(int key) {
        return (key % N + N) % N;//需要考虑key为负的情况
    }

public:
    hashSet() {
        set.resize(N);
    }

    void insert(int key) {
        int index = hashFunction(key);
        for (auto i: set[index]) {
            if (key == i) { return; }
        }
        set[index].push_back(key);
    }

    bool find(int key) {
        int index = hashFunction(key);
        for (auto i: set[index]) {
            if (key == i) { return true; }
        }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        hashSet hash;
        vector<int> arr;
        while (n--) {
            int x;
            cin >> x;
            if (!hash.find(x)) {
                hash.insert(x);
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
