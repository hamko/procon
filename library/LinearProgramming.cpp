// UVA 10498, Happiness
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

typedef vector<double> array;
typedef vector<array> matrix;

const double EPS = 1e-8;
enum { OPTIMAL, UNBOUNDED, NOSOLUTION, UNKNOWN };
struct two_stage_simplex {
    int N, M, st;
    matrix a;
    vector<int> s;
    two_stage_simplex(const matrix &A, const array &b, const array &c)
        : N(A.size()), M(A[0].size()), a(N+2, array(M+N+1)), s(N+2), st(UNKNOWN) {
            for (int j = 0; j < M; ++j) a[N+1][j] = c[j]; // make simplex table
            for (int i = 0; i < N; ++i)
                for (int j = 0; j < M; ++j) a[i+1][j] = A[i][j];
            for (int i = 0; i < N; ++i) a[i+1][M+N] = b[i]; // add helper table
            for (int i = 0; i < N; ++i) a[ 0 ][i+M] = 1;
            for (int i = 0; i < N; ++i) a[i+1][i+M] = 1;
            for (int i = 0; i < N; ++i) s[i+1]      = i+M;
            for (int i = 1; i <= N; ++i)
                for (int j = 0; j <= N+M; ++j) a[0][j] += a[i][j];
            st = solve();
        }
    int status() const { return st; }
    double solution() const { return -a[0][M]; }
    double solution(array &x) const {
        x.resize(M, 0);
        for (int i = 0; i < N; ++i)
            x[s[i+1]] = a[i+1].back();
        return -a[0][M];
    }
    int solve() {
        M += N; N += 1;
        solve_sub(); // solve stage one
        if (solution() > EPS) return NOSOLUTION;
        N -= 1; M -= N;
        swap(a[0], a.back()); a.pop_back(); // modify table
        for (int i = 0; i <= N; ++i) {
            swap(a[i][M], a[i].back());
            a[i].resize(M+1);
        }
        return solve_sub(); // solve stage two
    }
    int solve_sub() {
        int p, q;
        while (1) {
            //print();
            for (q = 0; q <= M && a[0][q] >= -EPS; ++q);
            for (p = 0; p <= N && a[p][q] <=  EPS; ++p);
            if (q >= M || p > N) break;
            for (int i = p+1; i <= N; ++i) // bland's care for cyclation
                if (a[i][q] > EPS)
                    if (a[i][M]/a[i][q] < a[p][M]/a[p][q] ||
                            (a[i][M]/a[i][q] == a[p][M]/a[p][q] && s[i] < s[q])) p = i;
            pivot(p, q);
        }
        if (q >= M) return OPTIMAL;
        else        return UNBOUNDED;
    }
    void pivot(int p, int q) {
        for (int j = 0; j <= N; ++j)
            for (int k = M; k >= 0; --k)
                if (j != p && k != q)
                    a[j][k] -= a[p][k]*a[j][q]/a[p][q];
        for (int j = 0; j <= N; ++j)
            if (j != p) a[j][q] = 0;
        for (int k = 0; k <= M; ++k)
            if (k != q) a[p][k] = a[p][k]/a[p][q];
        a[p][q] = 1.0;
        s[p] = q;
    }
};

int main() {
    for (int n, m; cin >> n >> m; ) {
        array c(n+m), b(m);
        for (int i = 0; i < n; ++i)
            cin >> c[i], c[i] *= -1;
        matrix A(m, array(n+m));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j)
                cin >> A[i][j];
            A[i][n+i] = 1;
            cin >> b[i];
        }
        two_stage_simplex tss(A, b, c);
        double ans = -tss.solution() * m;
        printf("Nasa can spend %.0f taka.\n", ans + 0.5 - EPS);
    }
}
