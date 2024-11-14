#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    //map,按照key自动排序
    map<int, string> ranking{{502, "wang"},
                             {88,  "wu"},
                             {610, "li"}};
    ranking.insert(ranking.begin(), pair<int, string>(10000, "he"));
    for (auto i: ranking) {
        cout << i.first << " " << i.second << endl;
    }
    cout << ranking.size() << endl;
    cout << ranking[88] << endl;
    ranking.erase(ranking.begin());
    auto comp = ranking.key_comp();
    cout << comp(502, 610) << endl;
    cout << ranking.count(10000) << endl;

    //unordered_map,无序,单个查询十分高效
    unordered_map<int, string> weight{{120, "Wang"},
                                      {110, "He"},
                                      {130, "Wu"}};
    weight[110] = "Jing";
    for (auto i: weight) {
        cout << i.first << " " << i.second << endl;
    }
    auto iter = weight.find(110);
    iter == weight.end() ? cout << "404 not found" << endl : cout << "found " << iter->second << endl;

    //set,集合,自动排序,不重复
    set<string> names{"Wang jia hao", "Wu chen wu", "Li ning jing"};
    set<string> names2{"He yu xuan", "He chen jie", "Song xing you"};
    names.insert(names2.begin(), names2.end());
    auto iterator=names.begin();
    advance(iterator,3);
    names.erase(iterator);
    for (auto i = names.rbegin(); i != names.rend(); i++) {
        cout << *i << endl;
    }
    auto it = names.lower_bound("Song xing you");
    cout << *it << endl;

    //unordered_set,无序,不重复
    unordered_set<double> height{170.0, 168.2, 191.3, 152.7};
    for (auto i: height) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

