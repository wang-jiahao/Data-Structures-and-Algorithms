#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

void dijkstra(vector<vector<pair<int, int> > > &edges, vector<int> &dist, int source) {
    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push({0, source});
    while (!pq.empty()) {
        auto [d,u] = pq.top();
        pq.pop();
        for (auto &[v,weight]: edges[u]) {
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<vector<pair<int, int> > > edges(n);
    vector<int> dist(n,INT_MAX);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }
    dijkstra(edges, dist, s);
    cout << dist[t] << endl;

    return 0;
}
