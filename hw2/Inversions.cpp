#include <iostream>
#include <vector>

using namespace std;

long long inversions(vector<int> &arr, vector<int> &temp, int left, int right);

long long merge_inversions(vector<int> &arr, vector<int> &temp, int left, int mid, int right);

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> temp(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << inversions(arr, temp, 0, n - 1) << endl;

    return 0;
}

long long inversions(vector<int> &arr, vector<int> &temp, int left, int right) {
    int mid = left + (right - left) / 2;
    long long inversion = 0;
    if (left < right) {
        inversion += inversions(arr, temp, left, mid);//左子数组的逆序
        inversion += inversions(arr, temp, mid + 1, right);//右子数组的逆序
        inversion += merge_inversions(arr, temp, left, mid, right);//合并过程中左数组与右数组之间的逆序
    }
    return inversion;
}

long long merge_inversions(vector<int> &arr, vector<int> &temp, int left, int mid, int right) {
    int i = left;//左端数组起始
    int j = mid + 1;//右端数组起始
    int k = left;//temp数组起始
    long long inversion = 0;
    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inversion += mid - i + 1;//arr[i]到arr[mid]与arr[j-1]逆序
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    for (int l = left; l <= right; ++l) {
        arr[l] = temp[l];
    }
    return inversion;
}
