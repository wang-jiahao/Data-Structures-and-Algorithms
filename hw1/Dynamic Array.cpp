#include <iostream>
#include <string>

using namespace std;

int arr[100000];
int Size = 0;
int Capacity = 10;

void append(int x);

void set(int x, int y);

void erase(int x);

int get(int x);


void print(void);

void input(void);

int main() {
    input();
    return 0;
}

void append(int x) {
    if (Size == Capacity) {
        Capacity *= 2;
    }
    arr[Size] = x;
    Size++;
}

void set(int x, int y) {
    arr[x] = y;
}

void erase(int x) {
    for (int i = x; i < Size - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    arr[Size-1]=0;
    Size--;
    if (Size < (Capacity / 2)) {
        Capacity /= 2;
    }
}

int get(int x) {
    return arr[x];
}

void print(void) {
    for (int i = 0; i < Size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void input(void) {
    string opr;
    while (cin >> opr) {
        if (opr == "append") {
            int x;
            cin >> x;
            append(x);
        } else if (opr == "set") {

            int x, y;
            cin >> x >> y;
            set(x, y);
        } else if (opr == "erase") {
            int x;
            cin >> x;
            erase(x);
        } else if (opr == "get") {
            int x;
            cin >> x;
            cout << get(x) << endl;
        } else if (opr == "size") {
            cout << Size << endl;
        } else if (opr == "capacity") {
            cout << Capacity << endl;
        } else if (opr == "print") {
            print();
        }
    }
}