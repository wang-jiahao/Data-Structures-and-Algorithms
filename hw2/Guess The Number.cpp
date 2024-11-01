#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    unsigned long long left = 0;
    unsigned long long right = pow(2, 64);
    cout << left + (right - left) / 2 << endl;
    string feedback;
    while (cin >> feedback) {
        if (feedback == "TooBig") {
            right = left + (right - left) / 2 - 1;
            cout << left + (right - left) / 2 << endl;
        } else if (feedback == "TooSmall") {
            left = left + (right - left) / 2 + 1;
            cout << left + (right - left) / 2 << endl;
        } else if (feedback == "Correct") {
            return 0;
        }
    }
    return 0;
}