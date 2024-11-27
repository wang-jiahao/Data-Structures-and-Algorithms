#include <iostream>
#include <vector>
#include <queue>

using namespace std;

enum STATE {
    WHITE, GRAY, BLACK
};

vector<vector<int>> adjList;
vector<STATE> state;

bool DFS(int node) {
    state[node] = GRAY;
    for (auto neighbor: adjList[node]) {
        if (state[neighbor] == GRAY) {
            return true;
        } else if (state[neighbor] == WHITE) {
            if (DFS(neighbor)) {
                return true;
            }
        }
    }
    state[node] = BLACK;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    adjList.resize(n + 1);
    state.resize(n + 1, WHITE);
    while (m--) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }
    cout << (DFS(1) ? "YES" : "NO") << endl;


    return 0;
}
