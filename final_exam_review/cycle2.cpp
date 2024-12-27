#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

enum STATE {
    WHITE, GRAY, BLACK
};

vector<vector<int> > adjList;
vector<STATE> states;
vector<int> order;

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
    order.push_back(start);
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
        //注意！一次dfs可能不够访问到所有节点，所以对未访问到的节点再次dfs
        if (states[i] == WHITE) {
            if (dfs(i)) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    copy(order.rbegin(), order.rend(), ostream_iterator<int>(cout, " "));

    return 0;
}
