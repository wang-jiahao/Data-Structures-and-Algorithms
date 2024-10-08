#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

struct Point {
    int x, y;
};

double dist(const Point& p1, const Point& p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

bool compareX(const Point& p1, const Point& p2) {
    return p1.x < p2.x;
}

bool compareY(const Point& p1, const Point& p2) {
    return p1.y < p2.y;
}

double closestPair(vector<Point>& points, int left, int right) {
    // 当点数小于等于3时，直接计算所有点对的距离
    if (right - left <= 3) {
        double minDist = numeric_limits<double>::infinity();
        for (int i = left; i < right; ++i) {
            for (int j = i + 1; j < right; ++j) {
                minDist = min(minDist, dist(points[i], points[j]));
            }
        }
        return minDist;
    }

    // 分治：递归计算左右两部分的最小距离
    int mid = left + (right - left) / 2;
    double d1 = closestPair(points, left, mid);
    double d2 = closestPair(points, mid, right);
    double d = min(d1, d2);

    // 处理跨中线的点对
    vector<Point> strip;
    for (int i = left; i < right; ++i) {
        if (abs(points[i].x - points[mid].x) < d) {
            strip.push_back(points[i]);
        }
    }

    // 按 y 坐标排序
    sort(strip.begin(), strip.end(), compareY);

    // 计算 strip 中的最小距离
    for (int i = 0; i < strip.size(); ++i) {
        for (int j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < d; ++j) {
            d = min(d, dist(strip[i], strip[j]));
        }
    }

    return d;
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    // 按 x 坐标排序
    sort(points.begin(), points.end(), compareX);

    // 计算最近点对距离
    double result = closestPair(points, 0, n);

    // 输出结果，保留4位小数
    cout.precision(4);
    cout << fixed << result << endl;

    return 0;
}

