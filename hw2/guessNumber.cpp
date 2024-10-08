#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    unsigned long long left = 0;
    unsigned long long right = pow(2, 64);
    cout << (left + right) / 2 << endl;
    string tip;
    while (cin >> tip) {
        unsigned long long middle = left + (right - left) / 2;
        if (tip == "TooBig") {
            right = middle - 1;
            cout << left + (right - left) / 2 << endl;
        } else if (tip == "TooSmall") {
            left = middle + 1;
            cout << left + (right - left) / 2 << endl;
        } else {
            return 0;
        }
    }
    return 0;
}