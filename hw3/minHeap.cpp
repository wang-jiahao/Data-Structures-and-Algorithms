#include <iostream>
#include <queue>

using namespace std;

int pushcount[10000];
int count=0;

class minHeap {
private:
    priority_queue<int, vector<int>, greater<int>> heap;
public:
    void push(int);

    void pop(void);

    void top(void);

    void size(void);

    void decrease(int, int);

    int search(int);
};

int main() {
    minHeap h;
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

void minHeap::push(int x) {
    heap.push(x);
    count++;
    pushcount[count]=x;
}

void minHeap::pop(void) {
    heap.pop();
}

void minHeap::top(void) {
    cout << heap.top() << endl;
}

void minHeap::size(void) {
    cout << heap.size() << endl;
}

void minHeap::decrease(int i, int k) {

}

int minHeap::search(int target){

}