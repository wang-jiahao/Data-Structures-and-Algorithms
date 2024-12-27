#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > adjList;
vector<int> dist;

void bfs(int u) {
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto v: adjList[node]) {
            if (dist[v] == -1) {
                q.push(v);
                dist[v] = dist[node] + 1;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    adjList.resize(n + 1);
    dist.resize(n + 1, -1);
    dist[1] = 0;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    bfs(1);
    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
}
