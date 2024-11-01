#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct node {
    int val;
    node *left;
    node *right;

    node(int x) : val(x), left(nullptr), right(nullptr) {}
};

void pre_order(node *root, vector<int> &preorder) {
    if (root == nullptr) {
        return;
    }
    preorder.push_back(root->val);
    pre_order(root->left, preorder);
    pre_order(root->right, preorder);
}

node *build_tree(vector<int> &arr, int &index) {
    node *root = new node(arr[index++]);
    while (index < arr.size()) {
        node *copy = root;
        node *parent = copy;
        int judge;
        while (copy != nullptr) {
            if (arr[index] <= copy->val) {
                parent = copy;
                copy = copy->left;
                judge = 0;
            } else {
                parent = copy;
                copy = copy->right;
                judge = 1;
            }
        }
        if (judge) {
            parent->right = new node(arr[index]);
        } else {
            parent->left = new node(arr[index]);
        }
        index++;
    }
    return root;
}

int main() {
    vector<int> arr;
    string s;
    getline(cin, s);
    istringstream iss(s);
    int num;
    while (iss >> num) {
        arr.push_back(num);
    }
    vector<int> preorder;
    int x = 0;
    node *root = build_tree(arr, x);
    pre_order(root, preorder);
    for (int i: preorder) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
