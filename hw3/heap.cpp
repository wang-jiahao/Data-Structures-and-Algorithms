#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MinHeap {
private:
    int heap[100];
    int Size = 0;
    vector<int> push_history;
public:
    void push(int x) {
        Size++;
        push_history.push_back(x);
        heap[Size] = x;
        int i = Size;
        while (i != 1 && heap[i] < heap[i / 2]) {
            swap(heap[i], heap[i / 2]);
            i /= 2;
        }
    }

    void pop() {
        heap[1] = heap[Size];
        Size--;
        min_heapify(1);
    }

    void min_heapify(int id) {
        int id_l = 2 * id;
        int id_r = 2 * id + 1;
        int id_min = (id_l <= Size && heap[id] > heap[id_l]) ? id_l : id;
        id_min = (id_r <= Size && heap[id_min] > heap[id_r]) ? id_r : id_min;
        if (id_min != id) {
            swap(heap[id], heap[id_min]);
            min_heapify(id_min);
        }
    }

    void top() {
        cout << heap[1] << endl;
    }

    void size() {
        cout << Size << endl;
    }

    void decrease(int i, int k) {
        auto pos=find(heap+1,heap+Size+1,push_history[i-1]);
        push_history[i-1]=k;
        *pos=k;
        int m = pos-heap;
        while (m != 1 && heap[m] < heap[m / 2]) {
            swap(heap[m], heap[m / 2]);
            m /= 2;
        }
    }
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

