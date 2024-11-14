#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

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
    auto cmp = [](const curriculum &c1, const curriculum &c2) {
        return c1.grade < c2.grade;
    };
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

    //stable_partition

    return 0;
}

