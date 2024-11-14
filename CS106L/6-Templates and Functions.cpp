#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

//Templates
template<typename T>
pair<T, T> my_minmax(const T &a, const T &b) {
    if (a < b) return {a, b};
    else return {b, a};
}

template<typename InputIt, typename UnitPred>
int count_occurences(InputIt begin, InputIt end, UnitPred predicate) {
    int count = 0;
    for (auto iter = begin; iter != end; iter++) {
        if (predicate(*iter)) count++;
    }
    return count;
}

bool isLessThan5(int elem) {
    if (elem < 5) return true;
    return false;
}

bool lessThanLimit(int val, int limit) {
    if (val < limit) return true;
    return false;
}

int main() {
    auto [x, y] = my_minmax<string>("Wang", "Li");
    cout << x << " " << y << endl;
    vector<int> arr{1, 3, 7, 4, 18, 222};
    cout << count_occurences(arr.begin(), arr.end(), isLessThan5) << endl;
    //lambda function
    int limit = 4;
    auto isLessThanLimit = [limit](auto val) {
        if (val < limit) return true;
        return false;
    };
    cout << count_occurences(arr.begin(), arr.end(), isLessThanLimit) << endl;
    //bind
    auto isLessThan8 = bind(lessThanLimit, placeholders::_1, 8);
    cout << count_occurences(arr.begin(), arr.end(), isLessThan8) << endl;

    return 0;
}
