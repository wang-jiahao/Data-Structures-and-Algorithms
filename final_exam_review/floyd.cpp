#include <iostream>
#include <vector>

using namespace std;

void floyd(vector<vector<int> > &dist, int n) {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    vector<vector<int> > dist(n + 1, vector<int>(n + 1));
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> dist[i][j];
        }
    }
    floyd(dist, n);
    int sum = 0;
    for (int i = 0; i < m - 1; ++i) {
        sum += dist[a[i]][a[i + 1]];
    }
    cout << sum << endl;

    return 0;
}
