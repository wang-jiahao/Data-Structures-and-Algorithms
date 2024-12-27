动态规划：

- [x] The Rod-Cutting Problem
- [x] Matrix-chain Multiplication
- [x] Edit Distance
- [x] Maximum Independent Set
- [x] Subset Sum

老师说期末机试动态规划（Dynamic Programming, DP）考课件里的，所以我总结了一下这五个问题。

------

### 1. The Rod-Cutting Problem (切割钢条问题)

#### 问题描述：

给定一个长度为 `n` 的钢条和一个价格数组 `p[]`，`p[i]` 表示长度为 `i+1` 的钢条的价格。我们需要确定如何将这根钢条切割成多个部分，使得总的销售额最大。

#### 动态规划解法：

- 定义 `dp[i]` 为长度为 `i` 的钢条的最大价格。
- 对于每个长度 `i`，可以将其分成两部分，分别求解这两部分的最大值并加上它们的价格。
- 递推式：`dp[i] = max(p[j] + dp[i - j - 1])`，其中 `j` 为切割点。

#### C++代码：

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rodCutting(const vector<int>& prices, int n) {
    vector<int> dp(n + 1, 0);
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            dp[i] = max(dp[i], prices[j] + dp[i - j - 1]);
        }
    }
    return dp[n];
}

int main() {
    vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20}; // 各个长度的钢条价格
    int n = 8; // 钢条长度
    cout << "最大销售额是: " << rodCutting(prices, n) << endl;
    return 0;
}
```

#### 解释：

- 我们使用 `dp[i]` 来存储长度为 `i` 的最大价值。
- 外层循环遍历每个可能的钢条长度，内层循环遍历每个切割点，计算最大销售额。

------

### 2. Matrix-chain Multiplication (矩阵链乘法)

#### 问题描述：

给定 `n` 个矩阵的维度，如何确定矩阵的乘法顺序，以使得总的乘法运算次数最小。

#### 动态规划解法：

- 定义 `dp[i][j]` 为从矩阵 `i` 到矩阵 `j` 之间的最小乘法次数。
- 递推式：`dp[i][j] = min(dp[i][k] + dp[k+1][j] + dim[i-1] * dim[k] * dim[j])`，其中 `k` 为分割点。
- 目标是计算 `dp[1][n]`，即矩阵从第一个到最后一个的最小乘法次数。

#### C++代码：

```cpp
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int matrixChainOrder(const vector<int>& dims) {
    int n = dims.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // l 为链的长度，从2到n
    for (int l = 2; l <= n; ++l) {
        for (int i = 0; i < n - l + 1; ++i) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + dims[i] * dims[k + 1] * dims[j + 1]);
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    vector<int> dims = {30, 35, 15, 5, 10, 20, 25}; // 矩阵维度数组
    cout << "最小乘法次数: " << matrixChainOrder(dims) << endl;
    return 0;
}
```

#### 解释：

- 我们定义了一个 `dp[i][j]` 表示矩阵 `i` 到矩阵 `j` 之间的最小乘法次数。
- 使用两层循环计算每个矩阵链的最优分割点。

------

### 3. Edit Distance (编辑距离)

#### 问题描述：

给定两个字符串 `str1` 和 `str2`，我们需要计算将 `str1` 转换为 `str2` 所需要的最小操作次数。操作包括插入一个字符、删除一个字符、替换一个字符。

#### 动态规划解法：

- 定义 `dp[i][j]` 为将 `str1[0..i-1]` 转换为 `str2[0..j-1]` 所需的最小操作次数。
- 递推式：`dp[i][j] = min(dp[i-1][j-1] + (str1[i-1] != str2[j-1]), dp[i-1][j] + 1, dp[i][j-1] + 1)`。

#### C++代码：

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int editDistance(const string& str1, const string& str2) {
    int m = str1.size(), n = str2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 0; i <= m; ++i) dp[i][0] = i;
    for (int j = 0; j <= n; ++j) dp[0][j] = j;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
            }
        }
    }
    return dp[m][n];
}

int main() {
    string str1 = "kitten", str2 = "sitting";
    cout << "编辑距离是: " << editDistance(str1, str2) << endl;
    return 0;
}
```

#### 解释：

- `dp[i][j]` 存储从 `str1[0..i-1]` 到 `str2[0..j-1]` 的最小编辑操作数。
- 如果两个字符相同，`dp[i][j]` 继承自 `dp[i-1][j-1]`，否则取三者最小值（替换、插入、删除）。

------

### 4. Maximum Independent Set (最大独立集)

#### 问题描述：

给定一个树，求该树的最大独立集（一个独立集是一个节点集合，其中没有任何两个节点是相邻的）。

#### 动态规划解法：

这个问题通常通过树的 **动态规划** 处理：

- `dp[u][0]` 表示不选节点 `u` 时，子树的最大独立集。
- `dp[u][1]` 表示选节点 `u` 时，子树的最大独立集。

#### C++代码：

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> tree[100]; // 树的邻接表表示
int dp[100][2]; // dp[u][0] 表示不选 u，dp[u][1] 表示选 u

void dfs(int u, int parent) {
    dp[u][0] = 0; // 不选 u 的最大独立集大小
    dp[u][1] = 1; // 选 u 的最大独立集大小
    
    for (int v : tree[u]) {
        if (v == parent) continue;
        dfs(v, u);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}

int main() {
    int n, m;
    cin >> n >> m; // 输入节点数和边数
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1, -1); // 从根节点1开始DFS
    cout << "最大独立集大小: " << max(dp[1][0], dp[1][1]) << endl;
    return 0;
}
```

#### 解释：

- `dp[u][0]`和`dp[u][1]`分别表示不选和选节点`u` 时的最大独立集大小。

- 通过 DFS 递归遍历树，并更新每个子树的最大独立集大小。

------

### 5. Subset Sum (子集和问题)

#### 问题描述：

给定一个整数集合 `S` 和一个目标值 `T`，问是否存在一个子集，其元素之和为 `T`。

#### 动态规划解法：

- 定义 `dp[i]` 为是否能通过某些元素的和得到值 `i`。
- 递推式：`dp[i] = dp[i] || dp[i - num]`。

#### C++代码：

```cpp
#include <iostream>
#include <vector>
using namespace std;

bool subsetSum(const vector<int>& nums, int target) {
    vector<bool> dp(target + 1, false);
    dp[0] = true; // 和为0的子集为空集

    for (int num : nums) {
        for (int i = target; i >= num; --i) {
            dp[i] = dp[i] || dp[i - num];
        }
    }
    return dp[target];
}

int main() {
    vector<int> nums = {3, 34, 4, 12, 5, 2};
    int target = 9;
    if (subsetSum(nums, target)) {
        cout << "存在子集和为 " << target << endl;
    } else {
        cout << "不存在子集和为 " << target << endl;
    }
    return 0;
}
```

#### 解释：

- `dp[i]` 表示是否存在子集，使得其和为 `i`。
- 每次遍历一个数，更新可能的和，最终判断是否存在目标和 `target`。