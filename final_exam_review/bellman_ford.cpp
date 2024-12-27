#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct edge {
    int u, v, w;

    edge(int u, int v, int w): u(u), v(v), w(w) {
    }
};

bool bellman_ford(int n, vector<edge> &edges, int source) {
    vector<int> dist(n + 1,INT_MAX);
    dist[source] = 0;
    for (int i = 1; i < n; ++i) {
        //n-1次松弛
        for (auto edge: edges) {
            int u = edge.u;
            int v = edge.v;
            int w = edge.w;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    for (auto edge: edges) {
        if (dist[edge.u] != INT_MAX && dist[edge.u] + edge.w < dist[edge.v]) {
            return true;
        }
    }
    return false;
}

int main() {
    int f;
    cin >> f;
    while (f--) {
        int n, m, w;
        cin >> n >> m >> w;
        vector<edge> edges;
        for (int i = 0; i < m; ++i) {
            int u, v, weight;
            cin >> u >> v >> weight;
            edges.emplace_back(u, v, weight);
            edges.emplace_back(v, u, weight);
        }
        for (int i = 0; i < w; ++i) {
            int u, v, weight;
            cin >> u >> v >> weight;
            edges.emplace_back(u, v, -weight);
        }
        cout << (bellman_ford(n, edges, 1) ? "YES" : "NO") << endl;
    }

    return 0;
}
