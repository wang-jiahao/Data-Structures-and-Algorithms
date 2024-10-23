#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>
using namespace std;

unordered_map<string, vector<string>> org_chart;
unordered_set<string> employees;

void encode() {
    string line, ceo;
    while (getline(cin, line)) {
        if (line.empty()) continue;
        size_t pos = line.find(':');
        string manager = line.substr(0, pos);
        employees.insert(manager);
        if (ceo.empty()) ceo = manager;  // The first line gives us the CEO
        istringstream iss(line.substr(pos + 2));
        string employee;
        while (iss >> employee) {
            org_chart[manager].push_back(employee);
            employees.insert(employee);
        }
    }

    for (const auto& name : employees) {
        cout << name << endl;
    }

    string binary_code;
    function<void(const string&)> dfs = [&](const string& name) {
        binary_code += "0";
        for (const auto& emp : org_chart[name]) {
            dfs(emp);
        }
        binary_code += "1";
    };

    dfs(ceo);
    cout << binary_code << endl;
}

void decode() {
    vector<string> names;
    string name;
    while (cin >> name) {
        names.push_back(name);
    }
    string binary_code = names.back();
    names.pop_back();

    reverse(names.begin(), names.end());
    unordered_map<string, vector<string>> decoded_org_chart;
    int index = 0;
    function<void(string)> dfs = [&](string manager) {
        while (index < binary_code.size() && binary_code[index] == '0') {
            index++;
            string employee = names.back();
            names.pop_back();
            decoded_org_chart[manager].push_back(employee);
            dfs(employee);
        }
        index++;
    };

    string ceo = names.back();
    names.pop_back();
    dfs(ceo);

    for (const auto& kv : decoded_org_chart) {
        cout << kv.first << ": ";
        for (const auto& emp : kv.second) {
            cout << emp << " ";
        }
        cout << endl;
    }
}

int main() {
    string command;
    getline(cin, command);
    if (command == "ENCODE") {
        encode();
    } else if (command == "DECODE") {
        decode();
    }
    return 0;
}

