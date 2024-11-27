#include <iostream>
#include <vector>
#include <queue>

using namespace std;

enum COLOR {
    WHITE, RED, BLUE
};

vector<vector<int>> adjList;
vector<COLOR> color;

bool BFS(int start) {
    color[start] = RED;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto neighbor: adjList[node]) {
            if (color[neighbor] == WHITE) {
                if (color[node] == RED) {
                    color[neighbor] = BLUE;
                } else {
                    color[neighbor] = RED;
                }
                q.push(neighbor);
            } else {
                if (color[neighbor] == color[node]) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    adjList.resize(n + 1);
    color.resize(n + 1, WHITE);
    while (m--) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    auto judge = BFS(1);
    cout << (judge ? "YES" : "NO") << endl;
    if (judge) {
        for (int i = 1; i < n + 1; ++i) {
            if (color[i] == RED) {
                cout << i << " ";
            }
        }
        cout << endl;
        for (int i = 1; i < n + 1; ++i) {
            if (color[i] == BLUE) {
                cout << i << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
