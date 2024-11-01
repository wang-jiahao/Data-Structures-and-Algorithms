#include <iostream>
#include <vector>

using namespace std;

using matrix = vector<vector<int>>;

matrix multiply(const matrix &a,const matrix &b, int n);

matrix add(const matrix &a,const matrix &b, int n);

int main() {
    int n;
    cin >> n;
    matrix a(n, vector<int>(n));
    matrix b(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> b[i][j];
        }
    }
    matrix c(n, vector<int>(n));
    c = multiply(a, b, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

matrix add(const matrix &a,const matrix &b, int n) {
    matrix c(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    return c;
}

matrix multiply(const matrix &a,const matrix &b, int n) {
    matrix c(n, vector<int>(n));
    if (n <= 128) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return c;
    }
    matrix A(n/2,vector<int>(n/2));
    matrix B(n/2,vector<int>(n/2));
    matrix C(n/2,vector<int>(n/2));
    matrix D(n/2,vector<int>(n/2));
    matrix E(n/2,vector<int>(n/2));
    matrix F(n/2,vector<int>(n/2));
    matrix G(n/2,vector<int>(n/2));
    matrix H(n/2,vector<int>(n/2));
    for (int i = 0; i < n/2; ++i) {
        for (int j = 0; j < n/2; ++j) {
            A[i][j]=a[i][j];
            B[i][j]=a[i][j+n/2];
            C[i][j]=a[i+n/2][j];
            D[i][j]=a[i+n/2][j+n/2];
            E[i][j]=b[i][j];
            F[i][j]=b[i][j+n/2];
            G[i][j]=b[i+n/2][j];
            H[i][j]=b[i+n/2][j+n/2];
        }
    }
    auto e= add(multiply(A,E,n/2), multiply(B,G,n/2),n/2);
    auto f= add(multiply(A,F,n/2), multiply(B,H,n/2),n/2);
    auto g= add(multiply(C,E,n/2), multiply(D,G,n/2),n/2);
    auto h= add(multiply(C,F,n/2), multiply(D,H,n/2),n/2);
    for (int i = 0; i < n/2; ++i) {
        for (int j = 0; j < n/2; ++j) {
            c[i][j]=e[i][j];
            c[i][j+n/2]=f[i][j];
            c[i+n/2][j]=g[i][j];
            c[i+n/2][j+n/2]=h[i][j];
        }
    }
    return c;
}
