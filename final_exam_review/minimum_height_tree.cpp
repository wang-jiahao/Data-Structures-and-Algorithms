#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int> > adjList;

pair<int, int> bfs(int start, int n) {
    vector<int> dist(n, -1);
    dist[start] = 0;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto neighbor: adjList[node]) {
            if (dist[neighbor] == -1) {
                q.push(neighbor);
                dist[neighbor] = dist[node] + 1;
            }
        }
    }
    int node = max_element(dist.begin(), dist.end()) - dist.begin();
    int maximum = *max_element(dist.begin(), dist.end());
    return {node,maximum};
}

int main() {
    int n;
    cin >> n;
    adjList.resize(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    auto [node1,h1] = bfs(0, n);
    auto [node2,h2] = bfs(node1, n);
    cout << (h2 % 2 == 0 ? h2 / 2 : h2 / 2 + 1) << endl;

    return 0;
}
