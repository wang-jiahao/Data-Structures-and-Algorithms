#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int main() {
    stack<int> track;//调度轨道
    vector<int> out;//出战顺序
    string str;
    getline(cin, str);
    istringstream iss(str);
    int num;
    while (iss >> num) {
        out.push_back(num);
    }
    int number = 1;//进站编号
    int n = out.size();
    for (int i = 0; i < n; ++i) {
        if (track.empty()){
            track.push(number);
            number++;
        }
        while (number <= n && track.top() != out[i]) {
            track.push(number);
            number++;
        }
        if (track.empty()||track.top() != out[i]) {
            cout << "NO" << endl;
            return 0;
        }
        track.pop();
    }
    if (number - 1 == n && track.empty()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
