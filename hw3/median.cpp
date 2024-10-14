#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> maxHeap; // 大顶堆，保存较小的一半
    priority_queue<int, vector<int>, greater<int>> minHeap; // 小顶堆，保存较大的一半

public:
    // 插入一个数
    void insert(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        // 调整两个堆的大小使得 maxHeap 的元素个数 >= minHeap 的元素个数
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    // 返回当前的中位数
    int getMedian() {
        return maxHeap.top(); // 因为我们保证 maxHeap 的元素个数 >= minHeap，所以中位数是 maxHeap 的堆顶
    }
};

int main() {
    int num;
    MedianFinder mf;

    while (cin >> num) {
        mf.insert(num);
        cout << mf.getMedian() << endl;
    }

    return 0;
}
