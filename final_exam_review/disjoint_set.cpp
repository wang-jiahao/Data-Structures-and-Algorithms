#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> size;

public:
    UnionFind(int m) {
        parent.resize(m + 1);
        size.resize(m + 1, 1);
        for (int i = 0; i <= m; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void UnionSet(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);
        if (root_x != root_y) {
            if (size[root_x] <= size[root_y]) {
                size[root_y] += size[root_x];
                parent[root_x] = root_y;
            } else {
                size[root_x] += size[root_y];
                parent[root_y] = root_x;
            }
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    UnionFind uf(m);
    while (n--) {
        int opr, x, y;
        cin >> opr >> x >> y;
        if (opr == 1) {
            uf.UnionSet(x, y);
        } else if (opr == 2) {
            cout << (uf.find(x) == uf.find(y) ? 1 : 0) << endl;
        }
    }

    return 0;
}
