#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

struct point {
    double x;
    double y;
};

double minimum(vector<point> &, int, int);

double distance(point &, point &);

bool compareX(point &, point &);

bool compareY(point &, point &);

int main() {
    int n;
    cin >> n;
    vector<point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }
    sort(points.begin(), points.end(), compareX);
    double min_distance = minimum(points, 0, n);
    cout << fixed << setprecision(4) << min_distance << endl;

    return 0;
}

double distance(point &p1, point &p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

bool compareX(point &p1, point &p2) {
    return p1.x < p2.x;
}

bool compareY(point &p1, point &p2) {
    return p1.y < p2.y;
}

double minimum(vector<point> &points, int left, int right) {
    if (right - left <= 3) {
        double mini = numeric_limits<double>::max();
        for (int i = left; i < right; ++i) {
            for (int j = i + 1; j < right; ++j) {
                mini = min(mini, distance(points[i], points[j]));
            }
        }
        return mini;
    }
    int mid = left + (right - left) / 2;
    double d1 = minimum(points, left, mid);//左边数组内距离最小值
    double d2 = minimum(points, mid, right);//右边数组内距离最小值
    double d = min(d1, d2);
    //计算跨越中点的最小值
    vector<point> temp;
    for (int i = left; i < right; ++i) {
        if (abs(points[i].x - points[mid].x < d)) {
            temp.push_back(points[i]);
        }
    }
    sort(temp.begin(), temp.end(), compareY);
    for (int i = 0; i < temp.size(); ++i) {
        for (int j = i + 1; j < temp.size() && temp[j].y - temp[i].y < d; ++j) {
            d = min(d, distance(temp[i], temp[j]));
        }
    }
    return d;
}