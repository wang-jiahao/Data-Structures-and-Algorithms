#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
    int u, v, w;
};

bool cmp(edge p, edge q) {
    return p.w < q.w;
}

class UnionFind {
private:
    vector<int> parent;
    vector<int> size;

public:
    UnionFind(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (size[rootX] <= size[rootY]) {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            } else {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            }
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    int weight = 0;
    int amount = 0;
    vector<edge> edges(m);
    UnionFind u(n);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    sort(edges.begin(), edges.end(), cmp);
    for (auto edge: edges) {
        if (u.find(edge.u) != u.find(edge.v)) {
            u.merge(edge.u, edge.v);
            weight += edge.w;
            amount += 1;
            if (amount == n - 1) {
                break;
            }
        }
    }
    cout << weight << endl;

    return 0;
}
