#include <iostream>
#include <queue>

using namespace std;

class median {
private:
    priority_queue<int> max_heap;//大根堆保存较小的部分
    priority_queue<int, vector<int>, greater<int>> min_heap;//小根堆保存较大的部分
public:
    void insert(int x) {
        if (max_heap.empty() || x <= max_heap.top()) {
            max_heap.push(x);
        } else {
            min_heap.push(x);
        }
        //保证大根堆元素数量始终比小根堆数量多1（k为奇数）或者相等（k为偶数）
        while (max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        while (min_heap.size() > max_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }

    void Median() {
        cout << max_heap.top() << endl;
    }
};

int main() {
    median arr;
    int a;
    while (cin >> a) {
        arr.insert(a);
        arr.Median();
    }
    return 0;
}