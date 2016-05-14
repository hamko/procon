#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i = 0; i < n; i++)
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
using vi = vector<int>;

int size_i, size_j, n;
vi vpi, vpj;
map<tuple<int, int, int, int>, int> memo;

int rec(int si, int sj, int ei, int ej) {
    if ( si < 0 || si >= size_i || sj < 0 || sj >= size_j 
      || ei < 0 || ei >= size_i || ej < 0 || ej >= size_j
      || si > ei || sj > ej) 
        return 0;
    auto state = make_tuple(si, sj, ei, ej);
    if (memo.count(state))
        return memo[state];

    int ret = 0;
    rep(i, n) {
        int pi = vpi[i], pj = vpj[i];
        if (!(si <= pi && pi <= ei && sj <= pj && pj <= ej))
            continue;
        int tmp = (ei-si+1)+(ej-sj+1)-1;
        tmp += rec(si, sj, pi-1, pj-1);
        tmp += rec(si, pj+1, pi-1, ej);
        tmp += rec(pi+1, sj, ei, pj-1);
        tmp += rec(pi+1, pj+1, ei, ej);
        chmax(ret, tmp);
    }

    memo[state] = ret;
    return ret;
}

signed main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> size_i >> size_j >> n;
    vpi = vi(n), vpj = vi(n);
    rep(i, n) {cin >> vpi[i] >> vpj[i]; vpi[i]--; vpj[i]--; }

    cout << rec(0, 0, size_i-1, size_j-1) << endl;
    return 0;
}
