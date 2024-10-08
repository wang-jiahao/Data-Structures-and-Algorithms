#include <iostream>
#include <vector>
#include <cmath>

const int THRESHOLD = 16; // 设定递归深度限制的阈值

using Matrix = std::vector<std::vector<int>>;

Matrix matrixAdd(const Matrix &A, const Matrix &B, int n) {
    Matrix C(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

Matrix multiply(const Matrix &A, const Matrix &B, int n) {
    Matrix C(n, std::vector<int>(n, 0));

    if (n <= THRESHOLD) {
        // 直接计算矩阵乘法
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return C;
    }

    // 分块矩阵乘法
    int half = n / 2;

    Matrix A11(half, std::vector<int>(half)), A12(half, std::vector<int>(half));
    Matrix A21(half, std::vector<int>(half)), A22(half, std::vector<int>(half));
    Matrix B11(half, std::vector<int>(half)), B12(half, std::vector<int>(half));
    Matrix B21(half, std::vector<int>(half)), B22(half, std::vector<int>(half));
    Matrix C11, C12, C21, C22;

    // 分割矩阵A和B
    for (int i = 0; i < half; ++i) {
        for (int j = 0; j < half; ++j) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half];
        }
    }

    // 递归计算子矩阵乘积
    C11 = matrixAdd(multiply(A11, B11, half), multiply(A12, B21, half), half);
    C12 = matrixAdd(multiply(A11, B12, half), multiply(A12, B22, half), half);
    C21 = matrixAdd(multiply(A21, B11, half), multiply(A22, B21, half), half);
    C22 = matrixAdd(multiply(A21, B12, half), multiply(A22, B22, half), half);

    // 合并结果
    for (int i = 0; i < half; ++i) {
        for (int j = 0; j < half; ++j) {
            C[i][j] = C11[i][j];
            C[i][j + half] = C12[i][j];
            C[i + half][j] = C21[i][j];
            C[i + half][j + half] = C22[i][j];
        }
    }

    return C;
}

int main() {
    int N;
    std::cin >> N;

    Matrix A(N, std::vector<int>(N));
    Matrix B(N, std::vector<int>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> A[i][j];
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> B[i][j];
        }
    }

    Matrix C = multiply(A, B, N);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << C[i][j] << (j < N - 1 ? " " : "\n");
        }
    }

    return 0;
}
