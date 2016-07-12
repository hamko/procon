#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
using ll = long long; using vll = vector<ll>; 

struct UnionFind {
    // 親がいるなら、親の添字
    // 根なら、-1 * その木のサイズ
    vector<int> data;
    // 親がいるなら、子-子より根側のある位置の値
    // 根なら0
    // 
    // w[i]から根方向へ積分すると、頂点iの値-根の値となる
    vector<ll> w; 

    UnionFind(int size) : data(size, -1), w(size, 0) { }
    // x, yをマージ
    // O(log n)
    void unite(int x, int y, int k) {
        x = root(x); y = root(y); if (x == y) return;
        ll wx = getWeight(x), wy = getWeight(y);

        if (data[y] < data[x]) {
            swap(x, y);
            swap(wx, wy);
            k *= -1;
        }
        data[x] += data[y]; 
        data[y] = x;
        w[y] = -k + wx - wy;
    }
    // x, yが同じ集合なら1
    // O(log n)
    bool find(int x, int y) {
        return root(x) == root(y);
    }
    // xの根を探す。同じ集合なら同じ根が帰る
    // O(log n)
    int root(int x) {
        return data[x] < 0 ? x : root(data[x]);
//        return data[x] < 0 ? x : data[x] = root(data[x]); // 縮約高速化は、アッカーマン程のスピードいらないし、更新面倒なので切っとく
    }
    // xから根までのwの積分
    // O(log n)
    ll getWeight(int x) {
        return data[x] < 0 ? 0 : w[x] + getWeight(data[x]);
    }
};

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);

    ll n, m; 
    while (cin >> n >> m && n && m) {
        UnionFind uf(n);
        rep(i, m) {
            char c; cin >> c;
            if (c == '!') {
                ll x, y, w; cin >> x >> y >> w; x--; y--;
                uf.unite(x, y, w);
            } else {
                ll x, y; cin >> x >> y; x--; y--;
                if (!uf.find(x, y))
                    cout << "UNKNOWN" << endl;
                else 
                    cout << uf.getWeight(x) - uf.getWeight(y) << endl;
            }
        }
    }

    return 0;
}
