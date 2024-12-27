#include <iostream>
#include  <vector>
using namespace std;

enum state {
    WHITE, GRAY, BLACK
}; //white表示未访问,gray表示访问中,black表示已访问

vector<vector<int> > adjList;
vector<state> states;

bool dfs(int start) {
    states[start] = GRAY;
    for (auto neighbor: adjList[start]) {
        if (states[neighbor] == WHITE) {
            if (dfs(neighbor)) {
                return true;
            }
        } else if (states[neighbor] == GRAY) {
            return true;
        }
    }
    states[start] = BLACK;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    adjList.resize(n + 1);
    states.resize(n + 1, WHITE);
    while (m--) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i) {
        if (states[i] == WHITE) {//对每个未访问到的节点dfs，如果根节点一次性可访问到所有节点，则只dfs一次
            if (dfs(i)) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
}
