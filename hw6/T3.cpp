#include <iostream>
#include <vector>

using namespace std;

class disjoint_set {
private:
    vector<int> parent;
    vector<int> rank;
public:
    disjoint_set(int size) {
        parent.resize(size);
        rank.resize(size, 1);
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootX] = rootY;
            rank[rootY]++;
        }
    }

    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }

};

int main() {
    int n, m;
    cin >> n >> m;
    disjoint_set s(m+1);
    while (n--) {
        int opr, x, y;
        cin >> opr >> x >> y;
        if (opr == 1) {
            s.merge(x, y);
        } else if (opr == 2) {
            cout << s.isConnected(x, y) << endl;
        }
    }

    return 0;
}
