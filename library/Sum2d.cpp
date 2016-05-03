#include <bits/stdc++.h>
using namespace std;
using ll = long long; using vll = vector<ll>;
#define rep(i,n) for(int i = 0; i < n; i++)

class Sum2d {
public:
    vector<vll> data;
    vector<vll> sumdata;
    Sum2d(vector<vll>& d) {
        int n = d.size();
        int m = d[0].size();
        data = d;
        sumdata = vector<vll>(n+1, vll(m+1, 0));
        rep(i, n) rep(j, m) sumdata[i+1][j+1] = data[i][j];
        rep(i, n) rep(j, m) sumdata[i+1][j+1] += sumdata[i+1][j];
        rep(i, n) rep(j, m) sumdata[i+1][j+1] += sumdata[i][j+1];
//        rep(i, n) {{rep(j, m) cout << sumdata[i+1][j+1] << " "; } cout << endl;}
    }
    // (i, j)から(ilen * jlen)の小区間の総和（閉区間）
    ll sum2d(int i, int j, int ilen, int jlen) {
        return sumdata[i+ilen][j+jlen]-sumdata[i+ilen][j]-sumdata[i][j+jlen]+sumdata[i][j];
    }
};

int main(void) {
    vector<vll> data = {
        {1, 2}, 
        {2, 3}, 
        {3, 4}};
    Sum2d s(data);
    cout << s.sum2d(1, 0, 1, 1) << endl; // (1, 0)から見た小区間(1, 1)=data[1][0]
    cout << s.sum2d(0, 0, 2, 2) << endl; // (0, 0)から見た小区間(2, 2)=data[0][0]+data[0][1]+data[1][0]+data[1][1]
    return 0;
}
