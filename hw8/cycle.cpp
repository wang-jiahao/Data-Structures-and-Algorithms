#include <iostream>
#include <vector>
#include <queue>

using namespace std;

enum STATE {
    WHITE, GRAY, BLACK
};

vector<vector<int> > adjList;
vector<STATE> state;
vector<int> sort;

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
    sort.push_back(node);
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
    bool is_cycle = false;
    for (int i = 1; i <= n; ++i) {
        if (state[i] == WHITE) {
            // 如果该节点没有被访问
            if (DFS(i)) {
                is_cycle = true;
                break;
            }
        }
    }
    cout << (is_cycle ? "YES" : "NO") << endl;
    if (!is_cycle) {
        for (auto i = sort.rbegin(); i != sort.rend(); i++) {
            cout << *i << " ";
        }
        cout << endl;
    }


    return 0;
}
