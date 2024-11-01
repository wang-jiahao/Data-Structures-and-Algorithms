#include <iostream>
#include <deque>
#include <string>

using namespace std;

int capacity;

class circular_queue {
private:
    deque<int> ccr_queue;
public:
    void enqueue(int x) {
        if (isFull()) {
            cout << "Overflow" << endl;
        } else {
            ccr_queue.push_back(x);
        }
    }

    void dequeue(void) {
        if (isEmpty()) {
            cout << "Underflow" << endl;
        } else {
            ccr_queue.pop_front();
        }
    }

    int front(void) {
        if (isEmpty()) {
            return -1;
        }
        return ccr_queue.front();
    }

    int rear(void) {
        if (isEmpty()) {
            return -1;
        }
        return ccr_queue.back();
    }

    bool isEmpty(void) {
        if (ccr_queue.size() == 0) {
            return true;
        }
        return false;
    }

    bool isFull(void) {
        if (ccr_queue.size() == capacity) {
            return true;
        }
        return false;
    }
};

int main() {
    circular_queue q;
    cin >> capacity;
    string cmd;
    while (cin >> cmd) {
        if (cmd == "enqueue") {
            int x;
            cin >> x;
            q.enqueue(x);
        } else if (cmd == "dequeue") {
            q.dequeue();
        } else if (cmd == "front") {
            cout << q.front() << endl;
        } else if (cmd == "rear") {
            cout << q.rear() << endl;
        } else if (cmd == "isEmpty") {
            cout << (q.isEmpty() ? "True" : "False") << endl;
        } else if (cmd == "isFull") {
            cout << (q.isFull() ? "True" : "False") << endl;
        }
    }
    return 0;
}
