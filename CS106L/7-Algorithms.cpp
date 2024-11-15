#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

auto excellent = [](const auto &c) {
    return c.grade > 4.5;
};
auto cmp = [](const auto &c1, const auto &c2) {
    return c1.grade < c2.grade;
};

struct curriculum {
    string name;
    double grade;
};

int main() {
    vector<curriculum> classes{{"Math",        4.7},
                               {"Physics",     4.5},
                               {"English",     4.4},
                               {"Programming", 5.0},
                               {"Chemistry",   4.9}};
    //sort,排序,O(NlogN)
    sort(classes.begin(), classes.end(), cmp);
    for (auto i: classes) {
        cout << i.name << " " << i.grade << endl;
    }

    //nth_element,选择,O(N),只将第k小放在k位置,保证左边的比它小,右边的比它大,不一定排序好
    nth_element(classes.begin(), classes.begin() + classes.size() / 2, classes.end(), cmp);
    for (auto i: classes) {
        cout << i.name << " " << i.grade << endl;
    }

    //stable_partition,分组,符合条件的放在前面,不符合的放在后面,并且不改变元素相对顺序
    auto ite=stable_partition(classes.begin(),classes.end(),excellent);
    classes.erase(ite,classes.end());
    for (auto i: classes) {
        cout << i.name << " " << i.grade << endl;
    }

    //copy_if,复制,复制符合条件的元素,但是不能改变vector的容量,配合back_inserter使用
    vector<curriculum> classes2;
    copy_if(classes.begin(),classes.end(), back_inserter(classes2),excellent);
    for (auto i: classes2) {
        cout << i.name << " " << i.grade << endl;
    }

    //remove_if,消除符合条件的元素,因为不是类方法,实际上并没有真正的删除,是把这些元素放到后面,返回分界处的iterator,所以需要配合erase使用
    //又称为erase-remove idiom
    classes.erase(remove_if(classes.begin(),classes.end(),excellent),classes.end());
    for (auto i: classes) {
        cout << i.name << " " << i.grade << endl;
    }


    return 0;
}

