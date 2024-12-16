#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

void dijkstra(const vector<vector<pair<int, int> > > &edges, int source, int n, vector<int> &dist) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.emplace(0, source);
    while (!pq.empty()) {
        auto [d,u] = pq.top(); //d为当前最小距离，u为对应节点
        pq.pop();
        if (d > dist[u]) { continue; }
        for (auto &[v,w]: edges[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }
}

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<vector<pair<int, int> > > edges(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].emplace_back(v, w);
        edges[v].emplace_back(u, w);
    }
    vector<int> dist(n, INF);
    dist[s] = 0;
    dijkstra(edges, s, n, dist);
    cout << dist[t] << endl;

    return 0;
}
