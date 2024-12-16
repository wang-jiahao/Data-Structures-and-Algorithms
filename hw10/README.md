参考链接：

[单源最短路径(Dijkstra算法)](https://blog.csdn.net/qq_42500831/article/details/89608104?ops_request_misc=%257B%2522request%255Fid%2522%253A%25223f125175167567dee887c0b7de5f0dcc%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=3f125175167567dee887c0b7de5f0dcc&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-89608104-null-null.142^v100^pc_search_result_base2&utm_term=%E5%8D%95%E6%BA%90%E6%9C%80%E7%9F%AD%E8%B7%AF%E5%BE%84&spm=1018.2226.3001.4187)

[单源最短路径(Bellman-Ford算法)](https://blog.csdn.net/m0_70980326/article/details/133916402?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522689c988ede407f8b1ed22330523e9ca6%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=689c988ede407f8b1ed22330523e9ca6&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-2-133916402-null-null.142^v100^pc_search_result_base2&utm_term=Bellman-Ford%20%E7%AE%97%E6%B3%95&spm=1018.2226.3001.4187)

### 单源最短路径

**单源最短路径问题（Single-Source Shortest Path Problem）** 是图论中的一个经典问题，目的是在一个加权图中，从一个指定的起点出发，计算到其他所有顶点的最短路径长度。这里的图可以是有向图或无向图，边的权值通常是非负的。该问题广泛应用于路由算法、网络优化、地理信息系统（GIS）等领域。

#### 问题定义

给定一个加权图 $G(V,E)$，其中 $V$ 表示顶点集，$E$ 表示边集。每条边 $(u,v)$ 具有一个非负的权重 $w(u,v)$，目标是计算从一个源点 $S$ 到图中所有其他顶点的最短路径。

#### 常见算法

1. **Dijkstra 算法**：用于图中所有边的权重为非负数时的单源最短路径问题。
2. **Bellman-Ford 算法**：能够处理带负权边的情况，并且可以检测负权环，但时间复杂度较高。
3. **Floyd-Warshall 算法**：用于求解任意两点之间的最短路径，适用于所有顶点之间的最短路径问题，虽然也可以处理负权边，但不适用于负权环。

这里，我们主要介绍 **Dijkstra 算法**和**Bellman-Ford 算法**，它是解决单源最短路径问题的最常用方法，适用于没有负权边的图。

#### Dijkstra 算法

Dijkstra 算法基于贪心策略，逐步确定最短路径。在每一步，它选择当前距离源点最近的未访问节点，并更新与其邻接的所有节点的最短路径。

#### 算法步骤

1. 初始化：设定源点的距离为 0，其他所有节点的距离为无穷大。将源点加入一个未处理的集合。
2. 在未处理节点中选择距离源点最近的节点。
3. 更新该节点的所有邻居的最短路径。如果通过当前节点到达某个邻居的路径更短，就更新该邻居的最短距离。
4. 标记当前节点为已处理，表示其最短路径已确定。
5. 重复步骤 2 和 3，直到所有节点都被处理完毕。

#### C++实现

以下是 Dijkstra 算法的 C++ 实现，使用了优先队列（`priority_queue`）来高效地选择距离源点最近的节点：

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// 定义图的结构：邻接表
typedef pair<int, int> pii; // pair<邻接点, 边的权重>

void dijkstra(int n, vector<vector<pii>>& adj, int src) {
    // 最短路径数组，初始化为无穷大
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    // 优先队列，存储距离和节点，按距离升序排列
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second; // 当前节点
        int d = pq.top().first;  // 当前最短路径
        pq.pop();

        // 如果当前路径已经不优于已知路径，跳过
        if (d > dist[u]) continue;

        // 遍历邻接节点
        for (auto& edge : adj[u]) {
            int v = edge.first;    // 邻接节点
            int weight = edge.second; // 边的权重

            // 更新最短路径
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // 输出从源点到其他节点的最短路径
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            cout << "Node " << i << " is unreachable from source." << endl;
        else
            cout << "Shortest path to node " << i << " is " << dist[i] << endl;
    }
}

int main() {
    int n, m; // n是节点数，m是边数
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<pii>> adj(n);
    
    cout << "Enter the edges (u, v, w):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    int src;
    cout << "Enter the source node: ";
    cin >> src;

    dijkstra(n, adj, src);

    return 0;
}

```

#### 代码解释：

1. **输入部分：**
   - `n` 是图的顶点数，`m` 是边的数量。
   - 每条边由三个整数表示：`u`、`v`、`w`，分别表示从顶点 `u` 到顶点 `v` 的边，权重为 `w`。
   - `source` 表示计算单源最短路径的起始顶点。
2. **图的表示：**
   - 使用 `vector<vector<PII>> graph(n)` 来存储图的邻接表，每个元素是一个 `PII` 对，表示一个邻接节点及其边的权重。
3. **Dijkstra 算法：**
   - 初始化 `dist` 数组，表示从源点到其他点的最短路径距离，初始值为 `INT_MAX`，表示不可达。
   - 使用优先队列 `pq` 来动态选择当前最短的未访问节点。
   - 对每个节点的邻接节点进行松弛操作，更新最短路径。
4. **输出结果：**
   - 输出源点到每个节点的最短距离。如果某个节点不可达，则输出 `INF`。

#### 时间复杂度：

- 使用优先队列（堆）实现 Dijkstra 算法时，时间复杂度为 

  $O((V+E)log⁡V)$

#### Bellman-Ford 算法简介

Bellman-Ford 算法是一种用于求解单源最短路径问题的经典算法。与 Dijkstra 算法不同，Bellman-Ford 算法不仅可以处理非负权边的图，还能够处理具有负权边的图，甚至能检测图中是否存在负权环。(在图论中，**负权环**指的是图中一个环（即路径可以回到起点），该环上所有边的权重之和小于零。简单来说，负权环是一个循环路径，沿着该路径走一圈所得到的权重总和是负数。)

#### 算法原理

Bellman-Ford 算法的核心思想是通过逐步“松弛”图中每条边来逐渐逼近最短路径的解。松弛操作指的是，假设当前节点 `u` 到达节点 `v` 的路径的已知距离为 `d[u]` 和 `d[v]`，如果通过 `u` 到 `v` 的路径会使得 `d[v]` 的值变小（即 `d[u] + w(u,v) < d[v]`），则更新 `d[v]`。

#### 算法步骤

1. **初始化**：
   - 对于所有节点 `v`，设置初始距离 `d[v]` 为无穷大（表示从源节点到该节点不可达）。
   - 对源节点 `s`，设置 `d[s] = 0`，因为源节点到自身的距离为 0。
2. **松弛操作**：
   - 对图中的每一条边 `(u, v)`，如果 `d[u] + w(u, v) < d[v]`，则更新 `d[v] = d[u] + w(u, v)`。
   - 重复上述松弛操作 `V - 1` 次，其中 `V` 是图中节点的数量。这是因为最长的最短路径可能经过图中最多 `V - 1` 条边。
3. **负权环检测**：
   - 在完成 `V - 1` 次松弛操作之后，若仍然存在边 `(u, v)`，使得 `d[u] + w(u, v) < d[v]`，则图中存在负权环。

#### 算法时间复杂度

- 由于每次松弛操作需要遍历所有的边，而最多需要进行 `V - 1` 次松弛操作，因此时间复杂度为 **O(V \* E)**，其中 `V` 是图中的节点数，`E` 是图中的边数。

#### 优缺点

**优点**：

- 可以处理包含负权边的图，且能够检测负权环。
- 算法实现相对简单。

**缺点**：

- 时间复杂度相对较高，尤其是在稠密图中，可能不如 Dijkstra 算法高效。

#### C++ 实现代码

下面是 Bellman-Ford 算法的 C++ 实现：

```cpp
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// 边的结构体
struct Edge {
    int u, v, weight;
};

// Bellman-Ford 算法
bool BellmanFord(int V, int E, vector<Edge>& edges, int src) {
    // 初始化距离数组，所有节点距离源节点的距离为无穷大
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // 松弛操作：对每条边进行 V-1 次松弛
    for (int i = 1; i < V; ++i) {
        for (int j = 0; j < E; ++j) {
            int u = edges[j].u;
            int v = edges[j].v;
            int weight = edges[j].weight;

            // 如果可以通过 u 到 v 更短，则更新 dist[v]
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // 检查是否存在负权环
    for (int i = 0; i < E; ++i) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains negative weight cycle" << endl;
            return false;  // 如果发现负权环，则返回 false
        }
    }

    // 打印每个节点的最短距离
    cout << "Vertex Distance from Source " << src << endl;
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << i << ": " << dist[i] << endl;
    }

    return true;  // 算法成功执行
}

int main() {
    int V = 5;  // 图中节点的数量
    int E = 8;  // 图中边的数量

    // 创建图的边
    vector<Edge> edges = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2},
        {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };

    // 调用 Bellman-Ford 算法，从源节点 0 开始
    BellmanFord(V, E, edges, 0);

    return 0;
}
```

#### 代码说明

- **Edge 结构体**：表示图中的一条边，包含起始节点 `u`，目标节点 `v` 和边的权重 `weight`。

- BellmanFord 函数：

  - `V` 表示节点数，`E` 表示边数，`edges` 是图中的边。
  - 在第一次循环中进行 `V - 1` 次松弛操作，更新最短路径。
  - 第二次循环用于检查是否存在负权环，如果发现负权环，则输出提示信息并返回 `false`。
  
- main 函数：

  - 构建一个包含 5 个节点和 8 条边的有向图，图中包含一些负权边。
- 调用 `BellmanFord` 函数计算从源节点 0 出发的最短路径。

#### 输出示例

假设运行该程序，输出结果可能如下：

```
Vertex Distance from Source 0
Vertex 0: 0
Vertex 1: -1
Vertex 2: 2
Vertex 3: -2
Vertex 4: 1
```

如上所示，从源节点 `0` 出发，经过松弛操作后得到每个节点的最短距离。

#### 总结

Bellman-Ford 算法通过反复松弛每条边来找到图中各个节点到源节点的最短路径。它能够处理包含负权边的图，并且具有较强的负权环检测能力。尽管其时间复杂度较高，但在一些特殊情况下（例如图中可能包含负权边或需要检测负权环）是非常有效的算法。

### 全源最短路径

全源最短路径问题（All-Pairs Shortest Path，简称 APSP）是指给定一个加权图，要求计算图中所有顶点对之间的最短路径长度。与单源最短路径（如 Dijkstra 算法）不同，全源最短路径算法需要计算每一对顶点之间的最短路径。

#### 常见算法

1. **Floyd-Warshall 算法**

   Floyd-Warshall 算法是一种动态规划算法，用于解决全源最短路径问题。它通过逐步检查所有可能的中间顶点，更新路径的最短值。该算法适用于处理稠密图（即边的数量较多的图），时间复杂度为 $O(V^3)$，其中 V 是图的顶点数。(这个我怎么我感觉我都能想出来🤓)

2. **Johnson 算法**

   Johnson 算法使用了 Dijkstra 算法来求解全源最短路径。它通过对图进行加权重标定，转化为一组单源最短路径问题。适用于稀疏图（边的数量较少的图），时间复杂度为 $O(V^2 \log V + VE)$，其中 E 是边数，V 是顶点数。

#### Floyd-Warshall 算法详细介绍

Floyd-Warshall 算法的核心思想是，假设图中存在一个中间顶点 k，并计算从每个顶点 i 到顶点 j 的最短路径。然后通过反复迭代更新最短路径。具体的更新方式是：

$$
d(i, j) = \min(d(i, j), d(i, k) + d(k, j))
$$
其中，$d(i,j)$ 表示从顶点 i 到顶点 j 的最短路径，k 是图中一个中间顶点。

#### 算法流程

1. 初始化一个 $V \times V$ 的距离矩阵 dist，其中 $dist[i][j]$表示顶点 i 到顶点 j 的初始距离。如果存在边，则为该边的权重，否则为无穷大。
2. 对于每个顶点 k，遍历所有顶点对 i,j，尝试通过顶点 k 来更新 $dist[i][j]$。
3. 最终，矩阵 dist 中的值即为所有顶点对之间的最短路径。

#### C++ 实现

```cpp
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// 定义无穷大的值
const int INF = INT_MAX;

// Floyd-Warshall 算法
void floydWarshall(vector<vector<int>>& dist, int V) {
    // dist[i][j] 表示从 i 到 j 的最短路径
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                // 更新最短路径
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

// 打印最短路径矩阵
void printSolution(const vector<vector<int>>& dist, int V) {
    cout << "最短路径矩阵：" << endl;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // 顶点数目
    int V = 4;
    
    // 初始化图的邻接矩阵
    vector<vector<int>> dist(V, vector<int>(V, INF));

    // 自己到自己距离为 0
    for (int i = 0; i < V; ++i) {
        dist[i][i] = 0;
    }

    // 给定图的边和权重
    dist[0][1] = 5;
    dist[0][2] = 10;
    dist[1][2] = 3;
    dist[1][3] = 1;
    dist[2][3] = 2;

    // 调用 Floyd-Warshall 算法
    floydWarshall(dist, V);

    // 输出最短路径矩阵
    printSolution(dist, V);

    return 0;
}
```

#### 代码说明

1. **邻接矩阵初始化**：
   - 初始化一个 $V \times V $的矩阵 `dist`，其中 `dist[i][j]` 代表从顶点 i 到顶点 j 的距离。如果存在边，则设置为该边的权重；否则，设置为 `INF`（无穷大）。
2. **Floyd-Warshall 算法**：
   - 通过三层嵌套的循环来遍历每对顶点 i 和 j，对于每个可能的中间顶点 k，更新 `dist[i][j]` 为更小的值，即 `min(dist[i][j], dist[i][k] + dist[k][j])`。
3. **打印结果**：
   - 最终，`dist` 矩阵中存储了每对顶点之间的最短路径。如果某一对顶点之间没有路径，值为 `INF`。

#### 时间复杂度和空间复杂度

- **时间复杂度**：Floyd-Warshall 算法的时间复杂度是$O(V^3)$，因为我们有三重循环，每一重循环都遍历 V 次。
- **空间复杂度**：空间复杂度是 $O(V^2)$，用于存储最短路径的矩阵。

#### 适用场景

Floyd-Warshall 算法适用于顶点数量相对较小或者图较为稠密的场景。当图中的边非常多时，它比一些基于优先队列的算法（如 Dijkstra）更高效，尤其是在计算所有顶点对之间的最短路径时。

#### 总结

Floyd-Warshall 算法是解决全源最短路径问题的一种经典算法，适用于求解图中任意两点之间的最短路径。尽管其时间复杂度较高，但在处理小规模的图时，它依然是一个非常有效和直观的选择。