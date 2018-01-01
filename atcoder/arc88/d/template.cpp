#include <bits/stdc++.h>
using namespace std;

template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define all(x) (x).begin(), (x).end()

int main(void) {
    string a; cin >> a;
    int n = a.length();
    if (count(all(a), '1') == 0) return cout << n << endl, 0;
    rep(i, n) a[i] -= '0';
    vector<int> as(n+1); 
    rep(i, n) 
        as[i] ^= a[i], as[i+1] ^= a[i];
    int ret = 1e8;
    rep(i, n+1) if (as[i] == 1) 
        chmin(ret, max(i, n-i));
    cout << ret << endl;

    return 0;
}
