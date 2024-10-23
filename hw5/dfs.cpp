#include <iostream>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main(){
    string ceo="Janez";
    unordered_map<string, vector<string>> org_chart;
    vector<string> employees;
    employees.push_back("Josip");
    employees.push_back("Karolina");
    employees.push_back("Janez");
    employees.push_back("Zofia");
    org_chart["Janez"].push_back("Josip");
    org_chart["Janez"].push_back("Zofia");
    org_chart["Zofia"].push_back("Karolina");
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
    return 0;
}