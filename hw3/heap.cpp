#include <iostream>

using namespace std;

void Swap(int &, int &);

int a[100];

int count = 0;

class MinHeap {
private:
    int num = 0;
    int heap[1000];

public:
    void push(int);

    void pop(void);

    void top(void);

    void size(void);

    void decrease(int, int);

    void MinHeapify(int);

    int search(int);
};

int main() {
    MinHeap h;
    string command;
    while (cin >> command) {
        if (command == "push") {
            int x;
            cin >> x;
            h.push(x);
        } else if (command == "pop") {
            h.pop();
        } else if (command == "top") {
            h.top();
        } else if (command == "size") {
            h.size();
        } else if (command == "decrease") {
            int i, k;
            cin >> i >> k;
            h.decrease(i, k);
        }
    }
    return 0;
}

void MinHeap::push(int x) {
    count++;
    a[count] = x;
    heap[num + 1] = x;
    int i = num + 1;
    while (i != 1 && heap[i] < heap[i / 2]) {
        Swap(heap[i], heap[i / 2]);
        i /= 2;
    }

    num++;
}

void MinHeap::pop(void) {
    if (num > 1) {
        heap[1] = heap[num];
        MinHeapify(1);
    }
    num--;
}

void MinHeap::top(void) {
    cout << heap[1] << endl;
}

void MinHeap::size(void) {
    cout << num << endl;
}

void MinHeap::decrease(int i, int k) {
    int id = search(a[i]);
    heap[id] = k;
    a[i] = k;
    while (id != 1 && heap[id] < heap[id / 2]) {
        Swap(heap[id], heap[id / 2]);
        id /= 2;
    }
}

void MinHeap::MinHeapify(int idx) {
    int idx_l = 2 * idx;
    int idx_r = 2 * idx + 1;
    int idx_max = (idx_l <= num and heap[idx_l] < heap[idx]) ? idx_l : idx;
    idx_max = (idx_r <= num and heap[idx_r] < heap[idx_max]) ? idx_r : idx_max;
    if (idx_max != idx) {
        Swap(heap[idx_max], heap[idx]);
        MinHeapify(idx_max);
    }
}

void Swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int MinHeap::search(int target) {
    for (int i = 1; i <= num; ++i) {
        if (heap[i] == target) {
            return i;
        }
    }
    return -1;
}


