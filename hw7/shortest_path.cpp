#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adjList;
vector<bool> visited;
vector<int> path;

void BFS(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto neighbor: adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
                path[neighbor] = path[node] + 1;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    adjList.resize(n + 1);
    visited.resize(n + 1, false);
    path.resize(n + 1, -1);
    path[1] = 0;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    BFS(1);
    for (int i = 2; i < n + 1; ++i) {
        cout << path[i] << " ";
    }
    cout << endl;

    return 0;
}