#include <iostream>

using namespace std;

int size1 = 0;
int size2 = 0;

int main() {
    string opr;
    while (cin >> opr) {
        if (opr == "enqueue") {
            size1++;
            cout << "push A" << endl;
        } else if (opr == "dequeue") {
            if (size2 == 0) {
                while (size1 != 0) {
                    size1--;
                    size2++;
                    cout << "move A B" << endl;
                }
            }
            size2--;
            cout<<"pop B"<<endl;
        }
    }
    return 0;
}
