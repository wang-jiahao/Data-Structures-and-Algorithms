#include <iostream>
#include <vector>
using namespace std;

class CircularQueue {
private:
    vector<int> data;
    int front, rear, capacity;

public:
    CircularQueue(int cap) : front(0), rear(0), capacity(cap + 1) {
        data.resize(capacity);
    }

    bool enqueue(int x) {
        if (isFull()) {
            cout << "Overflow" << endl;
            return false;
        }
        data[rear] = x;
        rear = (rear + 1) % capacity;
        return true;
    }

    bool dequeue() {
        if (isEmpty()) {
            cout << "Underflow" << endl;
            return false;
        }
        front = (front + 1) % capacity;
        return true;
    }

    int frontElement() {
        if (isEmpty()) return -1;
        return data[front];
    }

    int rearElement() {
        if (isEmpty()) return -1;
        // 注意：如果队列只有一个元素，rear 会指向下一个位置（循环），所以需要调整
        return data[(rear + capacity - 1) % capacity];
    }

    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return (rear + 1) % capacity == front;
    }
};

int main() {
    int N;
    cin >> N;
    CircularQueue cq(N);

    string command;
    int x;
    while (cin >> command) {
        if (command == "enqueue") {
            cin >> x;
            cq.enqueue(x);
        } else if (command == "dequeue") {
            cq.dequeue();
        } else if (command == "front") {
            cout << cq.frontElement() << endl;
        } else if (command == "rear") {
            cout << cq.rearElement() << endl;
        } else if (command == "isEmpty") {
            cout << (cq.isEmpty() ? "True" : "False") << endl;
        } else if (command == "isFull") {
            cout << (cq.isFull() ? "True" : "False") << endl;
        }
    }

    return 0;
}