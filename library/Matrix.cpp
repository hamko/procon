#include <bits/stdc++.h>
using namespace std;

typedef double number;
const number eps = 1e-8;
using arr = vector<number>;
using matrix = vector<arr>;

ostream &operator<<(ostream &o, const arr &v) { 
    for (int i = 0; i < v.size(); i++) { cout << v[i] << " "; } cout << endl;
    return o; 
}
ostream &operator<<(ostream &o, const matrix &v) { 
    for (int i = 0; i < v.size(); i++) { cout << v[i]; } 
    return o; 
}

// O( n )
matrix identity(int n) {
    matrix A(n, arr(n, 0));
    for (int i = 0; i < n; ++i) A[i][i] = 1; // 積の単位元（和の単位元は？）
    return A;
}
// O( n^2 )
arr mul(const matrix &A, const arr &x) {
    arr y(A.size(), 0);
    for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < A[0].size(); ++j)
            y[i] += A[i][j] * x[j]; // 加群の積と和の演算子
    return y;
}
// O( n^3 )
matrix mul(const matrix &A, const matrix &B) {
    matrix C(A.size(), arr(B[0].size(), 0));
    for (int i = 0; i < C.size(); ++i)
        for (int j = 0; j < C[i].size(); ++j)
            for (int k = 0; k < A[i].size(); ++k)
                C[i][j] += A[i][k] * B[k][j]; // 加群の積と和の演算子
    return C;
}
// O( n^3 log e )
matrix pow(const matrix &A, int e) {
    return e == 0 ? identity(A.size())  :
        e % 2 == 0 ? pow(mul(A, A), e/2) : mul(A, pow(A, e-1));
}
// O( n )
number inner_product(const arr &a, const arr &b) {
    number ans = 0;
    for (int i = 0; i < a.size(); ++i)
        ans += a[i] * b[i];
    return ans;
}
// O( n^3 )
number det(matrix A) {
    const int n = A.size();
    number D = 1;
    for (int i = 0; i < n; ++i) {
        int pivot = i;
        for (int j = i+1; j < n; ++j)
            if (abs(A[j][i]) > abs(A[pivot][i])) pivot = j;
        swap(A[pivot], A[i]);
        D *= A[i][i] * (i != pivot ? -1 : 1);
        if (abs(A[i][i]) < eps) break;
        for(int j = i+1; j < n; ++j)
            for(int k = n-1; k >= i; --k)
                A[j][k] -= A[i][k] * A[j][i] / A[i][i];
    }
    return D;
}
// O(n)
number tr(const matrix &A) {
    number ans = 0;
    for (int i = 0; i < A.size(); ++i)
        ans += A[i][i];
    return ans;
}
// O( n^3 ).
int rank(matrix A) {
    const int n = A.size(), m = A[0].size();
    int r = 0;
    for (int i = 0; r < n && i < m; ++i) {
        int pivot = r;
        for (int j = r+1; j < n; ++j)
            if (abs(A[j][i]) > abs(A[pivot][i])) pivot = j;
        swap(A[pivot], A[r]);
        if (abs(A[r][i]) < eps) continue;
        for (int k = m-1; k >= i; --k)
            A[r][k] /= A[r][i];
        for(int j = r+1; j < n; ++j)
            for(int k = i; k < m; ++k)
                A[j][k] -= A[r][k] * A[j][i];
        ++r;
    }
    return r;
}

struct LUinfo {
    vector<number> value;
    vector<int> index;
};
// O( n^3 ), Gaussian forward elimination
LUinfo LU_decomposition(matrix A) {
    const int n = A.size();
    LUinfo data;
    for (int i = 0; i < n; ++i) {
        int pivot = i;
        for (int j = i+1; j < n; ++j)
            if (abs(A[j][i]) > abs(A[pivot][i])) pivot = j;
        swap(A[pivot], A[i]);
        data.index.push_back(pivot);
        // if A[i][i] == 0, LU decomposition failed.
        for(int j = i+1; j < n; ++j) {
            A[j][i] /= A[i][i];
            for(int k = i+1; k < n; ++k)
                A[j][k] -= A[i][k] * A[j][i];
            data.value.push_back(A[j][i]);
        }
    }
    for(int i = n-1; i >= 0; --i) {
        for(int j = i+1; j < n; ++j)
            data.value.push_back(A[i][j]);
        data.value.push_back(A[i][i]);
    }
    return data;
}
// O( n^2 ) Gaussian backward substitution
arr LU_backsubstitution(const LUinfo &data, arr b) {
    const int n = b.size();
    int k = 0;
    for (int i = 0; i < n; ++i){
        swap(b[data.index[i]], b[i]);
        for(int j = i+1; j < n; ++j)
            b[j] -= b[i] * data.value[k++];
    }
    for (int i = n-1; i >= 0; --i) {
        for (int j = i+1; j < n; ++j)
            b[i] -= b[j] * data.value[k++];
        b[i] /= data.value[k++];
    }
    return b;
}

// reduce Hessenberg form (inplace). 
// O ( n^3 )
void hessenberg(matrix &A) {
    const int n = A.size();
    for (int k = 1; k <= n-2; ++k) {
        arr u(n);
        for (int i = k; i < n; ++i) u[i] = A[i][k-1];

        number ss = 0;
        for (int i = k+1; i < n; ++i) ss += u[i] * u[i];
        if (abs(ss) <= 0.0) continue;
        number s = sqrt( ss + u[k]*u[k] );
        if (u[k] > 0.0) s = -s;

        u[k] -= s;
        number uu = sqrt( ss + u[k]*u[k] );
        for (int i = k; i < n; ++i) u[i] /= uu;

        arr f(n), g(n);
        for (int i = 0; i < n; ++i)
            for (int j = k; j < n; ++j)
                f[i] += A[i][j] * u[j],
                    g[i] += A[j][i] * u[j];
        number gamma = inner_product(u, g);
        for (int i = 0; i < n; ++i)
            f[i] -= gamma * u[i],
                g[i] -= gamma * u[i];

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                A[i][j] = A[i][j] - 2*u[i]*g[j] - 2*f[i]*u[j];
    }
}

// find all eigenvalues using Hessenberg-QR Method
// O( n^3 + M n^2 ) where M is the number of iterations.
vector<number> eigenvalues(matrix A) {
    const int n = A.size();
    hessenberg(A);
    vector<number> s(n), c(n);
    for (int m = n; m >= 2; ) {
        if (abs(A[m-1][m-2]) < eps) { --m; continue; }
        number shift = A[m-1][m-1];
        for (int i = 0; i < m; ++i) A[i][i] -= shift;
        for (int k = 0; k < m-1; ++k) {
            number a = A[k][k], b = A[k+1][k], r = sqrt(a*a + b*b);
            s[k] = r == 0.0 ? 0.0 : b/r,
                c[k] = r == 0.0 ? 0.0 : a/r;
            for (int j = k; j < m; ++j) {
                number x = A[k][j], y = A[k+1][j];
                A[ k ][j] =  c[k] * x + s[k] * y;
                A[k+1][j] = -s[k] * x + c[k] * y;
            }
        }
        for (int k = 0; k < m-1; ++k) {
            for (int i = 0; i <= k+1; ++i) {
                number x = A[i][k], y = A[i][k+1];
                A[i][ k ] =  c[k] * x + s[k] * y;
                A[i][k+1] = -s[k] * x + c[k] * y;
            }
        }
        for (int i = 0; i < m; ++i) A[i][i] += shift;
    }
    vector<number> lambda;
    for (int i = 0; i < n; ++i)
        lambda.push_back( A[i][i] );
    return lambda;
}

// find the corresponding eigenvector from the eigenvalue.
// O ( n^3 + M n^2 ) where M is the number of iterations.
arr eigenvector(matrix A, number lambda) {
    const int n = A.size();
    arr y(n); y[0] = 1;
    for (int i = 0; i < n; ++i) A[i][i] -= lambda;
    LUinfo data = LU_decomposition(A);
    number mu, v2, v2s;
    do {
        arr v = LU_backsubstitution(data, y); // A v = y 
        mu = inner_product(v, y);
        v2 = inner_product(v, v);
        v2s = sqrt(v2);
        for (int j = 0; j < n; ++j) y[j] = v[j] / v2s;
    } while (abs(1.0-mu*mu/v2) > eps);
    return y;
}

int main(void)
{
    vector<arr> m = {
        {2, 3,}, 
        {1, 2,}};
    vector<arr> a = {
        {2,}, 
        {1,}};
    cout << m << endl;
    cout << a << endl;
    cout << mul(m, a) << endl;


    return 0;
}
