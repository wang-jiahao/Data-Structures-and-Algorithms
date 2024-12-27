#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > adjList;
vector<int> color; //-1表示未访问,0表示一种颜色,1表示另一种颜色，相邻节点使用不同颜色

bool bfs(int start) {
    color[start] = 0;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto neighbor: adjList[node]) {
            if (color[neighbor] == color[node]) {
                return false;
            }
            if (color[neighbor] == -1) {
                q.push(neighbor);
                color[neighbor] = 1 - color[node];
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    adjList.resize(n + 1);
    color.resize(n + 1, -1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    auto is_biparted = bfs(1);
    if (!is_biparted) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; ++i) {
        if (color[i] == 0) {
            cout << i << " ";
        }
    }
    cout << endl;
    for (int i = 1; i <= n; ++i) {
        if (color[i] == 1) {
            cout << i << " ";
        }
    }

    return 0;
}
