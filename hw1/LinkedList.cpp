#include <iostream>
#include <string>

using namespace std;

int list[10000];
int Size = 0;

void pushFront(int);

void pushBack(int);

int search(int);

void remove(int);

void print(void);

int main() {
    string cmd;
    while (cin >> cmd) {
        if (cmd == "pushFront") {
            int x;
            cin >> x;
            pushFront(x);
        } else if (cmd == "pushBack") {
            int x;
            cin >> x;
            pushBack(x);
        } else if (cmd == "search") {
            int x;
            cin >> x;
            cout << search(x) << endl;
        } else if (cmd == "remove") {
            int x;
            cin >> x;
            remove(x);
        } else if (cmd == "print") {
            print();
        }
    }
    return 0;
}

void pushFront(int x) {
    for (int i = Size - 1; i >= 0; --i) {
        list[i + 1] = list[i];
    }
    list[0] = x;
    Size++;
}

void pushBack(int x) {
    list[Size] = x;
    Size++;
}

int search(int x) {
    for (int i = 0; i < Size; ++i) {
        if (list[i] == x) {
            return 1;
        }
    }
    return 0;
}

void remove(int x) {
    for (int i = 0; i < Size; ++i) {
        if (list[i] == x) {
            for (int j = i; j < Size - 1; ++j) {
                list[j] = list[j + 1];
            }
            Size--;
        }
    }
}

void print(void) {
    for (int i = 0; i < Size; ++i) {
        cout << list[i] << " ";
    }
    cout << endl;
}