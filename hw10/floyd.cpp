#include <iostream>
#include <vector>

using namespace std;

void floyd_warshall(vector<vector<int> > &dist, int n) {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> sequence(m + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> sequence[i];
    }
    vector<vector<int> > dist(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> dist[i][j];
        }
    }
    floyd_warshall(dist, n);
    int result = 0;
    for (int i = 1; i <= m; ++i) {
        if (i == 1) {
            result += dist[1][sequence[i]];
            continue;
        }
        result += dist[sequence[i - 1]][sequence[i]];
        if (i == m) {
            result += dist[sequence[m]][n];
        }
    }
    cout << result << endl;

    return 0;
}
