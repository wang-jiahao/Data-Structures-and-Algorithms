#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    vector<int> arr;
    int k;
    cin >> k;
    cin.get();
    string cmd;
    getline(cin, cmd);
    istringstream iss(cmd);
    int num;
    while (iss >> num) {
        arr.push_back(num);
    }
    nth_element(arr.begin(), arr.begin() + arr.size() - k, arr.end());
    cout << arr[arr.size() - k] << endl;
    return 0;
}
