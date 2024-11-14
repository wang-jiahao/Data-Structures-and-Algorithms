#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    //利用istringstream实现字符串分割
    string s;
    cin >> s;
    istringstream iss(s);
    cout << iss.str() << endl;//str()用法将stringstream转为string
    string token;
    while (getline(iss, token, ',')) {
        cout << token << endl;
    }
    //利用ostringstream实现字符串拼接
    ostringstream oss;
    oss << "hello" << " I" << " am " << "Zackaria";
    cout << oss.str() << endl;
    //利用stringstream实现数据类型转换
    stringstream ss;
    int a = 1;
    int b = 199;
    ss << a << b;
    string int_to_string;
    ss >> int_to_string;
    cout << int_to_string << endl;

    return 0;
}