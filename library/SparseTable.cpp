#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 2e18
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

// スパーステーブル
// 構築O(n log n)
// クエリO(log (log n))
//
// rmq(i, j)    [i, j)の最小値・最大値を求める
struct SparseTable {
    // 構築時データ
    vector<ll> val;
    
    // max_flag==trueならRange Maximum Query
    // デフォルトMinimum
    bool max_flag;

    // table[i][j]: [i, i+2^j)の最小値を取る添字
    vector<vector<ll>> table;

    inline ll MSB(ll x) { return x>0?31-__builtin_clz(x):-1; }
    SparseTable(void){}
    SparseTable(const vector<ll> a, bool max_flag_ = false) : val(a), max_flag(max_flag_) {
        ll n = a.size(), ln = MSB(n);
        table = vector<vector<ll>>(n, vector<ll>(ln + 1,0));
        rep(i,n)
            table[i][0] = i;

        ll k = 1;
        rep(j, ln) {
            rep(i, n){
                ll id1 = table[i][j], id2 = (i+k<n)?table[i+k][j]:id1;
                table[i][j+1] = (max_flag ? (val[id1]>=val[id2]) : (val[id1]<=val[id2]))?id1:id2;
            }
            k <<= 1;
        }
    }

    inline ll rmqi(ll l, ll r){
        ll ln = MSB(r-l);
        ll id1 = table[l][ln], id2 = table[r-(1<<ln)][ln];
        return (max_flag ? (val[id1]>=val[id2]) : (val[id1]<=val[id2]))?id1:id2;
    }

    inline ll rmq(ll l, ll r){ 
        if (l >= r) return max_flag ? 0 : INF;
        return val[rmqi(l,r)]; 
    }
};

int main(void)
{
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
    }

    {
        cout << "RMQ_I" << endl;
        vector<ll> a = {2, 1, 8, 3};
        SparseTable st(a);

        cout << st.rmqi(0, 1) << endl;
        cout << st.rmqi(0, 2) << endl;
        cout << st.rmqi(0, 3) << endl;
        cout << st.rmqi(2, 3) << endl;
        cout << st.rmqi(2, 4) << endl;
    }


    {
        vector<ll> a = {2, 1, 8, 3};
        SparseTable st(a, true);

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
    }

    return 0;
}
