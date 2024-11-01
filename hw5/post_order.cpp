#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

struct node {
    int val;
    node *left;
    node *right;

    node(int x) : val(x), left(nullptr), right(nullptr) {}
};

void post_order(node *root, vector<int> &postorder) {
    if (root == nullptr) {
        return;
    }
    post_order(root->left, postorder);
    post_order(root->right, postorder);
    postorder.push_back(root->val);
}

node *build_tree(vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &inorder_map, int start, int end,
                 int &pre_index) {
    if (start > end) {
        return nullptr;
    }
    int val = preorder[pre_index++];
    node *root = new node(val);
    int key = inorder_map[val];
    root->left = build_tree(preorder, inorder, inorder_map, start, key - 1, pre_index);
    root->right = build_tree(preorder, inorder, inorder_map, key + 1, end, pre_index);
    return root;
}

node *init(vector<int> &preorder, vector<int> &inorder) {
    int n = preorder.size();
    int pre_index = 0;
    unordered_map<int, int> inorder_map;
    for (int i = 0; i < n; ++i) {
        inorder_map[inorder[i]] = i;
    }
    return build_tree(preorder, inorder, inorder_map, 0, n - 1, pre_index);
}


void input(vector<int> &preorder, vector<int> &inorder) {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    istringstream iss1(s1);
    istringstream iss2(s2);
    int x;
    while (iss1 >> x) {
        preorder.push_back(x);
    }
    while (iss2 >> x) {
        inorder.push_back(x);
    }
}

int main() {
    vector<int> preorder;
    vector<int> inorder;
    input(preorder, inorder);

    auto root = init(preorder, inorder);
    vector<int> postorder;
    post_order(root, postorder);
    for (auto i: postorder) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}