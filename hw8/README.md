## 拓扑序

图的拓扑序（Topological Sort）是指对于一个有向无环图（Directed Acyclic Graph, DAG）中的所有节点，按照某种顺序排列，使得对于每一条有向边 (u,v)(u, v)，节点 uu 在拓扑序列中出现在节点 vv 之前。换句话说，拓扑排序给出了一种节点的线性排列方式，使得图中的所有边都指向正确的顺序。

### 1. 拓扑排序的基本性质

- **有向无环图**（DAG）必须满足拓扑排序的条件。若图中存在环，则无法进行拓扑排序，因为有向环会导致节点间相互依赖，无法确定线性顺序。
- 拓扑排序是图的一个特定排列，每个节点只出现一次，所有的边从前向后指向下一个节点。

### 2. 拓扑排序的应用

拓扑排序在许多领域中有广泛的应用，特别是在以下几种情况下：

- **任务调度**：当某些任务必须在其他任务完成之后执行时，拓扑排序可以帮助安排任务执行顺序。例如，在软件构建和编译过程中，必须先处理依赖关系。
- **依赖分析**：例如，包管理系统中，某个包的安装可能依赖于另一个包，拓扑排序可以帮助确定安装包的顺序。
- **前置条件约束**：在许多问题中，处理某些元素时可能有前置条件，例如课程安排、流程图分析等。

### 3. 拓扑排序的算法

有几种常见的算法可以实现拓扑排序，以下是其中两种典型的算法：

#### 1. **Kahn 算法（入度法）**

Kahn 算法是基于图中每个节点的入度（即指向该节点的边的数量）来进行拓扑排序的。具体步骤如下：

1. **初始化**：计算图中每个节点的入度，并将所有入度为零的节点放入一个队列中。
2. **遍历**：从队列中取出一个节点，将其添加到拓扑排序结果中。
3. **更新入度**：对该节点的所有邻接节点进行处理，减少其入度。如果某个邻接节点的入度变为零，则将该节点加入队列。
4. **重复**：直到队列为空。如果所有节点都被处理完，则完成拓扑排序。

如果在过程中发现有节点的入度始终不为零，说明图中存在环，无法进行拓扑排序。

#### 2. **深度优先搜索（DFS）法**

深度优先搜索（DFS）法利用递归来进行拓扑排序。具体步骤如下：

1. **递归遍历**：从未访问的节点开始，进行深度优先搜索。
2. **回溯时添加节点**：在递归过程中，当一个节点的所有邻接节点都被访问过后，就将当前节点加入到结果列表中。注意，由于递归的特性，节点会被按拓扑顺序反向加入列表。
3. **反转结果**：由于深度优先搜索过程中节点的添加是“回溯”顺序，最终需要将结果列表反转，以得到正确的拓扑排序。

### 4. 时间复杂度

- **Kahn 算法**：由于每个节点和边都只处理一次，所以时间复杂度是 O(V+E)O(V + E)，其中 VV 是图中的节点数，EE 是图中的边数。
- **DFS 算法**：同样，DFS 算法的时间复杂度为 O(V+E)O(V + E)。

### 5. 例子

考虑一个简单的有向无环图：

```
A → B → D
↓   ↑
C → E
```

这个图可以表示为以下的邻接表：

- A → B, C
- B → D
- C → E
- D → （没有邻接节点）
- E → （没有邻接节点）

使用Kahn算法（入度法）：

1. 初始时，A的入度为0，B的入度为1，C的入度为1，D的入度为1，E的入度为1。
2. 将A加入队列，A的邻接节点B和C的入度分别减1。队列现在为[A]。
3. 从队列中取出A，将B和C加入队列。队列现在为[B, C]。
4. 从队列中取出B，处理B的邻接节点D，减去D的入度。队列现在为[C, D]。
5. 从队列中取出C，将E加入队列。队列现在为[D, E]。
6. 从队列中取出D和E，处理完毕。最终的拓扑排序结果为 [A, B, C, D, E]。

### 总结

拓扑排序是一种非常有用的图论算法，尤其在处理依赖关系和调度问题时具有重要应用。它要求图是有向无环的（DAG），并通过不同的算法（如Kahn算法或DFS法）可以高效地实现。

## 最小生成树

要解这个问题，我们可以使用 Kruskal 算法或 Prim 算法来求解图的最小生成树。这里选择使用 Kruskal 算法，它的思想是按边的权重从小到大排序，然后逐步添加边到最小生成树中，保证添加的每条边不会形成环，最终得到一个包含所有节点的生成树。

### 步骤：

1. **输入解析**：读取节点数 `N` 和边数 `M`，接着读取每条边的节点对和权重。
2. **排序**：将所有边按照权重从小到大排序。
3. **并查集**：使用并查集（Union-Find）来管理图中的连通性，确保在添加一条边时不会形成环。
4. **逐步添加边**：从最小的边开始，如果这条边连接的两个节点属于不同的连通块，则将其加入生成树，并合并这两个连通块。直到生成树包含 `N-1` 条边。

### 代码实现：

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 并查集数据结构
class UnionFind {
public:
    UnionFind(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);  // 路径压缩
        }
        return parent[u];
    }

    void unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV) {
            // 按秩合并，保证树的深度较小
            if (size[rootU] < size[rootV]) {
                parent[rootU] = rootV;
                size[rootV] += size[rootU];
            } else {
                parent[rootV] = rootU;
                size[rootU] += size[rootV];
            }
        }
    }

private:
    vector<int> parent;
    vector<int> size;
};

// 边的结构体
struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;  // 按权重升序排序
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<Edge> edges(M);

    // 读取边的信息
    for (int i = 0; i < M; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    // 对边按权重进行排序
    sort(edges.begin(), edges.end());

    // 使用并查集处理最小生成树
    UnionFind uf(N);
    int mstWeight = 0;
    int edgeCount = 0;

    for (const auto& edge : edges) {
        if (uf.find(edge.u) != uf.find(edge.v)) {
            uf.unionSets(edge.u, edge.v);
            mstWeight += edge.w;
            edgeCount++;
            if (edgeCount == N - 1) {
                break;  // 最小生成树包含 N-1 条边
            }
        }
    }

    // 输出最小生成树的权重
    cout << mstWeight << endl;

    return 0;
}
```

### 解释：

1. **UnionFind 类**：实现了并查集的数据结构，支持 `find`（查找根节点）和 `unionSets`（合并两个节点的连通块）。
2. **Edge 结构体**：每个边包含两个节点和该边的权重，并重载了 `<` 操作符，以便可以按权重排序。
3. 主函数：
   - 先读取所有边的输入并存储在 `edges` 向量中。
   - 将边按权重升序排序。
   - 使用并查集处理每条边，判断其是否可以加入到最小生成树中（即它的两个端点是否属于不同的连通块）。
   - 当已加入的边数为 `N-1` 时，停止算法。
   - 输出最小生成树的总权重。

### 复杂度：

- **时间复杂度**：排序的时间复杂度为 `O(M log M)`，每次并查集的 `find` 和 `union` 操作平均时间复杂度为 `O(α(N))`（α 是反阿克曼函数，几乎是常数），因此总时间复杂度是 `O(M log M + M α(N))`。在最坏情况下，`M ≤ 100` 和 `N ≤ 100`，所以效率足够满足题目要求。

### 测试样例：

#### 输入：

```
4 4
0 1 1
1 2 2
2 3 3
0 3 4
```

#### 输出：

```
6
```

### 解释：

最小生成树包含的边是：

- 边 (0, 1) 权重 1
- 边 (1, 2) 权重 2
- 边 (2, 3) 权重 3

总权重为 1 + 2 + 3 = 6。