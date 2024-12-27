#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int> > adjList; //树的邻接表表示
vector<vector<int> > dp; //0表示不取该节点的最大独立集，1表示取该节点的最大独立集

void dfs(int u, int parent) {
    dp[u][0] = 0;
    dp[u][1] = 1;
    for (auto v: adjList[u]) {
        if (v == parent) continue;
        dfs(v, u);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}

int main() {
    cin >> n;
    adjList.resize(n);
    dp.resize(n, vector<int>(2, 0));
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    dfs(0, -1);
    cout << max(dp[0][0], dp[0][1]) << endl;

    return 0;
}
