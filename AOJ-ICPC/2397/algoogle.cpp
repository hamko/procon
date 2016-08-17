#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)

const long long mod = 1000000009;

typedef long long number;
typedef vector<number> arr;
typedef vector<arr> mat;

arr mul(const mat &A, const arr &x) {
    arr y(A.size());
    for(int i = 0; i < (int)A.size(); ++i)
        for(int j = 0; j < (int)A[0].size(); ++j)
            (y[i] += 1LL * A[i][j] * x[j]) %= mod;
    return y;
}

mat mul(const mat &A, const mat &B) {
    mat C(A.size(), arr(B[0].size()));
    for(int i = 0; i < (int)C.size(); ++i)
        for(int j = 0; j < (int)C[i].size(); ++j)
            for(int k = 0; k < (int)A[i].size(); ++k)
                (C[i][j] += 1LL * A[i][k] * B[k][j] % mod) %= mod;
    return C;
}

mat identity(int n) {
    mat A(n, arr(n));
    for (int i = 0; i < n; i++)
        A[i][i] = 1;
    return A;
}

mat pow(const mat &A, long long e) {
    return e == 0 ? identity(A.size())  :
        e % 2 == 0 ? pow(mul(A, A), e/2) :
        mul(A, pow(A, e-1));
}

long long w, h, n;
map<long long, vector<int>> vs;

long long solve() {
    h--;
    arr as(w,0);
    mat A;
    A.assign(w,arr(w,0));
    rep(i,w) repi(j,max(0,i-1),min((int)w,i+2)) A[i][j] = 1;
    as[0] = 1;
    long long ch = 0;
    for(auto &hs: vs) {
        long long nh = hs.first;
        if(nh <= ch) continue;
        as = mul(pow(A,nh-ch), as);
        for(auto &e: hs.second) as[e] = 0;
        ch = nh;
    }
    as = mul(pow(A,h-ch),as);
    return as[w-1];
}

bool input() {
    cin >> w >> h >> n;
    vs.clear();
    long long x, y;
    rep(i,n) {
        cin >> x >> y;
        vs[y-1].push_back(x-1);
    }
    return w or h or n;
}

int main() {
    for(int i = 1; input(); i++) cout << "Case " << i << ": " << solve() << endl;
    return 0;
}
