#include <iostream>
#include <string>

using std::cin, std::cout, std::endl, std::string;

struct node {
    int value;
    node *next;

    node(int x, node *m) : value(x), next(m) {}
};

class linked_list {
private:
    node *head;
    node *tail;

public:
    linked_list() {
        tail = new node(0, nullptr);
        head = tail;
    }

    void pushFront(int x) {
        if (head == tail) {
            head->value = x;
        } else {
            node *p = new node(x, head);
            head = p;
        }
    }

    void pushBack(int x) {
        node *p = new node(x, nullptr);
        tail->next = p;
        tail = p;
    }

    void search(int x) {
        for (node *p = head; p != nullptr; p = p->next) {
            if (p->value == x) {
                cout << 1 << endl;
                return;
            }
        }
        cout << 0 << endl;
    }

    void remove(int x) {
        node *prev = head;
        node *p = head->next;
        if (prev->value == x) {
            head = p;
        }
        while (p) {
            if (p->value == x) {
                prev->next = p->next;
            }
            p = p->next;
            prev = prev->next;
        }
    }

    void print(void) {
        for (node *p = head; p != nullptr; p = p->next) {
            cout << p->value << " ";
        }
        cout << endl;
    }
};

int main() {
    linked_list lst;
    string cmd;
    int x;
    while (cin >> cmd) {
        if (cmd == "pushFront") {
            cin >> x;
            lst.pushFront(x);
        } else if (cmd == "pushBack") {
            cin >> x;
            lst.pushBack(x);
        } else if (cmd == "search") {
            cin >> x;
            lst.search(x);
        } else if (cmd == "remove") {
            cin >> x;
            lst.remove(x);
        } else if (cmd == "print") {
            lst.print();
        }
    }
    return 0;
}