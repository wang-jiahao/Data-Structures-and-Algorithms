#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int n;
vector<vector<int> > adjList; //节点i的邻居节点
vector<int> dist; //节点i到其他节点的距离和
vector<int> subTree; //节点i的子树节点数

//计算根节点到其他节点的距离和，同时计算每个节点的子树节点数
void dfs1(int u, int parent) {
    dist[u] = 0;
    subTree[u] = 1;
    for (auto v: adjList[u]) {
        if (v == parent) { continue; }
        dfs1(v, u);
        subTree[u] += subTree[v];
        dist[u] += dist[v] + subTree[v];
    }
}

//计算除了根节点以外的其他节点到所有节点的距离和
void dfs2(int u, int parent) {
    if (parent != -1) {
        dist[u] = dist[parent] + n - 2 * subTree[u];
    }
    for (auto v: adjList[u]) {
        if (v == parent) { continue; }
        dfs2(v, u);
    }
}

int main() {
    cin >> n;
    adjList.resize(n);
    dist.resize(n);
    subTree.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    dfs1(0, -1);
    dfs2(0, -1);
    copy(dist.begin(), dist.end(), ostream_iterator<int>(cout, " "));

    return 0;
}
