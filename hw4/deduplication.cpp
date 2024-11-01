#include <iostream>
#include <bitset>

using namespace std;

const int N = 10000;

int main() {
    bitset<N> arr;
    int num;
    while (cin >> num) {
        arr.set(num);
    }
    for (int i = 0; i < N; ++i) {
        if (arr.test(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
