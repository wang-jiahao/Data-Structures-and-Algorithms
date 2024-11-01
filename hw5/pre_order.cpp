#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

struct node {
    int value;
    node *left;
    node *right;

    node(int x) : value(x), left(nullptr), right(nullptr) {}
};

void input(vector<int> &inorder, vector<int> &postorder);

void preOrder(node *root, vector<int> &preorder);

node *buildTree(vector<int> &inorder, vector<int> &postorder, int start, int end, int &postIndex,
                unordered_map<int, int> &inodermap);

node *init(vector<int> &inoder, vector<int> &postorder);


int main() {
    vector<int> inorder;
    vector<int> postorder;
    input(inorder, postorder);
    vector<int> preorder;
    node *root = init(inorder, postorder);
    preOrder(root, preorder);
    for (int num: preorder) {
        cout << num << " ";
    }
    return 0;
}

void input(vector<int> &inorder, vector<int> &postorder) {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    istringstream iss1(s1);
    istringstream iss2(s2);
    int x;
    while (iss1 >> x) {
        inorder.push_back(x);
    }
    while (iss2 >> x) {
        postorder.push_back(x);
    }
}

node *buildTree(vector<int> &inorder, vector<int> &postorder, int start, int end, int &postIndex,
                unordered_map<int, int> &inodermap) {
    if (start > end) {
        return nullptr;
    }
    int val = postorder[postIndex--];
    int key = inodermap[val];
    node *root = new node(val);
    root->right = buildTree(inorder, postorder, key + 1, end, postIndex, inodermap);
    root->left = buildTree(inorder, postorder, start, key - 1, postIndex, inodermap);

    return root;
}

node *init(vector<int> &inoder, vector<int> &postorder) {
    int n = inoder.size();
    unordered_map<int, int> inodermap;
    for (int i = 0; i < n; ++i) {
        inodermap[inoder[i]] = i;
    }
    int postIndex = n - 1;
    return buildTree(inoder, postorder, 0, n - 1, postIndex, inodermap);
}

void preOrder(node *root, vector<int> &preorder) {
    if (root == nullptr) {
        return;
    }
    preorder.push_back(root->value);
    preOrder(root->left, preorder);
    preOrder(root->right, preorder);
}