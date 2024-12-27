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

    int find(int node) {
        if (node != parent[node]) {
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }

    void UnionSet(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);
        if (size[root_x] <= size[root_y]) {
            size[root_y] += size[root_x];
            parent[root_x] = root_y;
        } else {
            size[root_x] += size[root_y];
            parent[root_y] = root_x;
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    sort(edges.begin(), edges.end(), cmp);
    UnionFind uf(n);
    int edge_num = 0;
    int weight_sum = 0;
    for (int i = 0; i < m; ++i) {
        if (edge_num == n - 1) {
            break;
        }
        int u = edges[i].u;
        int v = edges[i].v;
        if (uf.find(u) != uf.find(v)) {
            uf.UnionSet(u, v);
            weight_sum += edges[i].w;
            edge_num++;
        }
    }
    cout << weight_sum << endl;

    return 0;
}
