#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <array>
#include <queue>
#include <stack>


using namespace std;

int main() {
    //vector
    vector<int> vt;
    vt.push_back(1);
    vt.push_back(9);
    vt.push_back(2);
    vt.erase(vt.begin(), vt.begin() + 2);
    cout << vt.size() << endl;
    //deque,double edged queue(双端队列)
    deque<double> dq;
    dq.push_back(4.1);
    dq.push_back(1.2);
    dq.push_front(3.2);
    dq.erase(dq.begin());
    for (auto i: dq) {
        cout << i << " ";
    }
    cout << endl;
    //forward_list,单向链表
    forward_list<int> fw_lst{1, 3, 2, 9, 5};
    fw_lst.pop_front();
    fw_lst.sort();
    for (auto i: fw_lst) {
        cout << i << " ";
    }
    cout << endl;
    //list,双向链表
    list<int> lst{1, 5, 4, 2, 3};
    lst.pop_back();
    for (auto i = lst.rbegin(); i != lst.rend(); i++) {
        cout << *i << " ";
    }
    cout << endl;
    lst.push_back(2);
    lst.push_back(2);
    lst.unique();
    lst.sort();
    lst.reverse();
    for (auto i: lst) {
        cout << i << " ";
    }
    cout << endl;
    //array,与c数组一模一样
    array<int, 10> arr{1, 3, 2, 5, 4};
    arr.at(0) = arr.at(1);
    for (auto i: arr) {
        cout << i << " ";
    }
    cout << endl;
    array<int, 10> arr2;
    arr2.fill(9);
    arr2.swap(arr);
    for (auto i: arr) {
        cout << i << " ";
    }
    cout<<endl;

    //Container Adaptors
    // queue,先进先出
    queue<int, deque<int>> q;//利用deque实现queue
    q.push(1);
    q.push(3);
    q.push(4);
    q.pop();
    cout << q.front() << " " << q.back() << endl;
    //stack,先进后出
    stack<int, deque<int>> s;//利用deque实现stack
    s.push(3);
    s.push(9);
    s.push(8);
    s.pop();
    cout << s.top() << endl;

    return 0;
}
