#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct edge {
    int u, v, weight;

    edge(int u, int v, int weight): u(u), v(v), weight(weight) {
    }
};

const int INF = numeric_limits<int>::max();

bool bellman_ford(int n, int m, vector<edge> edges, int source) {
    vector<int> dist(n + 1, INF);
    dist[source] = 0;
    for (int i = 1; i < n; ++i) {
        for (auto edge: edges) {
            if (dist[edge.u] != INF && dist[edge.u] + edge.weight < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.weight;
            }
        }
    }
    for (auto edge: edges) {
        if (dist[edge.u] != INF && dist[edge.u] + edge.weight < dist[edge.v]) {
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
        cin >> n >> m >> w; //n节点数，m边数
        vector<edge> edges;
        for (int i = 0; i < m; ++i) {
            int s, e, t;
            cin >> s >> e >> t;
            edges.emplace_back(s, e, t);
            edges.emplace_back(e, s, t);
        }
        for (int i = 0; i < w; ++i) {
            int s, e, t;
            cin >> s >> e >> t;
            edges.emplace_back(s, e, -t);
        }
        cout << (bellman_ford(n, m, edges, 1) ? "YES" : "NO") << endl;
    }
    return 0;
}
