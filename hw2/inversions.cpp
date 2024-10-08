#include <iostream>
#include <vector>

using namespace std;

// 合并两个已排序的子数组，并计算逆序对
long long mergeAndCount(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    int i = left;    // 左子数组的起始索引
    int j = mid + 1; // 右子数组的起始索引
    int k = left;    // 临时数组的起始索引
    long long invCount = 0; // 逆序对计数器

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            // 所有在arr[i]到arr[mid]之间的元素都会与arr[j-1]构成逆序对
            invCount += (mid - i + 1);
        }
    }

    // 复制左子数组剩余的元素（如果有）
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // 复制右子数组剩余的元素（如果有）
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // 将排序后的子数组复制回原数组
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return invCount;
}

// 归并排序并计算逆序对
long long mergeSortAndCount(vector<int>& arr, vector<int>& temp, int left, int right) {
    long long invCount = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        invCount += mergeSortAndCount(arr, temp, left, mid);
        invCount += mergeSortAndCount(arr, temp, mid + 1, right);

        invCount += mergeAndCount(arr, temp, left, mid, right);
    }
    return invCount;
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    vector<int> temp(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    long long invCount = mergeSortAndCount(arr, temp, 0, N - 1);
    cout << invCount << endl;

    return 0;
}
