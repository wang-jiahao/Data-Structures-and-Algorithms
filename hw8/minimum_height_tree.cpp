#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int> > adjList;

pair<int, int> BFS(int start, int n) {
    vector<int> dist(n, -1);
    dist[start] = 0;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto neighbor: adjList[node]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }
    auto max_iter = max_element(dist.begin(), dist.end());
    return {*max_iter, distance(dist.begin(), max_iter)};
}

int main() {
    int n;
    cin >> n;
    adjList.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    auto [dist1,node1] = BFS(0, n);
    auto [diameter,node2] = BFS(node1, n);
    cout << (diameter % 2 == 0 ? diameter / 2 : diameter / 2 + 1) << endl;

    return 0;
}
