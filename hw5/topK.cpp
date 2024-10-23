#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

int main() {
    int k;
    cin >> k;
    cin.get();
    string s;
    getline(cin, s);
    istringstream iss(s);
    int arr[100000];
    int i = 0;
    while (iss >> arr[i]) {
        i++;
    }
    sort(arr, arr + i);
    cout << arr[i - k] << endl;
    return 0;
}
