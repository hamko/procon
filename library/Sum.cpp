#include <bits/stdc++.h>
using namespace std;
using ll = long long; using vll = vector<ll>;
#define rep(i,n) for(int i = 0; i < n; i++)

// 累積和の計算
// 構築O(n)
// クエリO(1)
const function<bool(ll)> f1_default = [](ll x) { return 1; };
class Sum1d {
public:
    vll data;
    vll sumdata;
    Sum1d(vll& d, function<bool(ll)> f = f1_default) {
        int n = d.size();
        data = d;
        sumdata = vll(n+1, 0);
        rep(i, n) if(f(i)) sumdata[i+1] = data[i];
        rep(i, n) sumdata[i+1] += sumdata[i];
    }
    // [i, j)の小区間の総和 (半開区間)
    ll sum(int i, int j) {
        return sumdata[j]-sumdata[i];
    }
    // [i, i+ilen)の小区間の総和 (半開区間)
    ll suml(int i, int len) {
        return this->sum(i, i+len);
    }
    void print(void) {
        rep(i, sumdata.size()) cout << sumdata[i] << " "; cout << endl;
    }
};

// 二次元累積和の計算
// 構築O(n^2)
// クエリO(1)
const function<bool(ll, ll)> f2_default = [](ll x, ll y) { return 1; };
class Sum2d {
public:
    vector<vll> data;
    vector<vll> sumdata;
    Sum2d(vector<vll>& d, function<bool(ll, ll)> f = f2_default) {
        int n = d.size(), m = d[0].size();
        data = d;
        sumdata = vector<vll>(n+1, vll(m+1, 0));
        rep(i, n) rep(j, m) if(f(i, j)) sumdata[i+1][j+1] = data[i][j];
        rep(i, n) rep(j, m) sumdata[i+1][j+1] += sumdata[i+1][j];
        rep(i, n) rep(j, m) sumdata[i+1][j+1] += sumdata[i][j+1];
//        rep(i, n+1) {{rep(j, m+1) cout << sumdata[i][j] << " "; } cout << endl;}
    }
    // [(i0, j0), (i1, j1))の小区間の総和 (半開区間)
    ll sum(int i0, int j0, int i1, int j1) {
        return sumdata[i1][j1]-sumdata[i1][j0]-sumdata[i0][j1]+sumdata[i0][j0];
    }
    // [(i, j), (i+ilen, j+jlen))の小区間の総和 (半開区間)
    ll suml(int i, int j, int ilen, int jlen) {
        return this->sum(i, j, i+ilen, j+jlen);
    }
};

int main(void) {
    {
        vll data = {1, 2, 3, 4, 5};
        Sum1d s(data);
        cout << s.sum(1, 4) << endl; // [1, 4)
        cout << s.suml(1, 3) << endl; // 1から3個
    }

    {
        vector<vll> data = {
            {1, 2}, 
            {2, 3}, 
            {3, 4}};
        Sum2d s(data);
        cout << s.sum(1, 0, 2, 1) << endl; // [(1, 0), (2, 1))
        cout << s.sum(0, 0, 2, 2) << endl; // [(0, 0), (2, 2))
        cout << s.suml(1, 0, 1, 1) << endl; // (1, 0)から見た小区間[1, 1]=data[1][0]
        cout << s.suml(0, 0, 2, 2) << endl; // (0, 0)から見た小区間[2, 2]=data[0][0]+data[0][1]+data[1][0]+data[1][1]
    }
    return 0;
}
