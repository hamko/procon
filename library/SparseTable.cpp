#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

// スパーステーブル
// 構築O(n log n)
// クエリO(log (log n))
//
// rmq(i, j)    [i, j)の最小値を求める
struct SparseTable {
    // 構築時データ
    vector<ll> val;

    // table[i][j]: [i, i+2^j)の最小値を取る添字
    vector<vector<ll>> table;

    inline ll MSB(ll x) { return x>0?31-__builtin_clz(x):-1; }
    SparseTable(void){}
    SparseTable(const vector<ll> a) : val(a) {
        ll n = a.size(), ln = MSB(n);
        table = vector<vector<ll>>(n, vector<ll>(ln + 1,0));
        rep(i,n)
            table[i][0] = i;

        ll k = 1;
        rep(j, ln) {
            rep(i, n){
                ll id1 = table[i][j], id2 = (i+k<n)?table[i+k][j]:id1;
                table[i][j+1] = (val[id1]<=val[id2])?id1:id2;
            }
            k <<= 1;
        }
    }

    inline ll rmqi(ll l, ll r){
        ll ln = MSB(r-l);
        ll id1 = table[l][ln], id2 = table[r-(1<<ln)][ln];
        return (val[id1]<=val[id2])?id1:id2;
    }

    inline ll rmq(ll l, ll r){ return val[rmqi(l,r)]; }
};

int main(void)
{
    vector<ll> a = {2, 1, 8, 3};
    SparseTable st(a);

    cout << st.rmq(0, 1) << endl;
    cout << st.rmq(0, 2) << endl;
    cout << st.rmq(0, 3) << endl;
    cout << st.rmq(2, 3) << endl;
    cout << st.rmq(2, 4) << endl;

    rep(i, st.table.size()) {
        rep(j, st.table[i].size()) 
            cout << st.table[i][j];
        cout << endl;
    }

    return 0;
}
