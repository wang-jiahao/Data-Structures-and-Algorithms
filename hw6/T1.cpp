#include <iostream>

using namespace std;

struct node {
    int val;
    node *left;
    node *right;

    node(int x) : val(x), left(nullptr), right(nullptr) {}
};

class set {
public:
    node *insert(node *root, const int &x) {
        if (!root) { return new node(x); }
        if (x < root->val) { root->left = insert(root->left, x); }
        else if (x > root->val) { root->right = insert(root->right, x); }
        return root;
    }

    node *search(node *root, const int &x) {
        if (!root || root->val == x) { return root; }
        if (x < root->val) { return search(root->left, x); }
        else { return search(root->right, x); }
    }

    node *remove(node *root, const int &key) {
        if (!root) return root;
        if (key < root->val) {
            root->left = remove(root->left, key);
        } else if (key > root->val) {
            root->right = remove(root->right, key);
        } else {
            if (!root->left) {
                node *temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                node *temp = root->left;
                delete root;
                return temp;
            }
            node *temp = minValueNode(root->right);
            root->val = temp->val;
            root->right = remove(root->right, temp->val);
        }
        return root;
    }

    node *minValueNode(node *n) {
        node *current = n;
        while (current && current->left) {
            current = current->left;
        }
        return current;
    }

    void inorder(node *root, const int &x, int &count) {
        if (root) {
            inorder(root->left, x, count);
            if (root->val > x) { count += 1; }
            inorder(root->right, x, count);
        }
    }
};

int main() {
    int n;
    cin >> n;
    set s;
    node *root = nullptr;
    while (n--) {
        int opr, x;
        cin >> opr >> x;
        if (opr == 1) {
            root = s.insert(root, x);
        } else if (opr == 2) {
            cout << (s.search(root, x) ? 0 : 1) << endl;
        } else if (opr == 3) {
            root = s.remove(root, x);
        } else if (opr == 4) {
            int count = 0;
            s.inorder(root, x, count);
            cout << count << endl;
        }
    }
    return 0;
}
