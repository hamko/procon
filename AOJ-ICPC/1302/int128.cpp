#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

using ll = long long; 

static const long long INF = 1e18;

using lll = __int128_t;

ll popcount(lll x) {
    ll c = 0;
    rep(i, 128) 
        c += !!(x & ((lll)1 << i));
    return c;
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n, qnum; 
    while (cin >> n >> qnum && n && qnum) {
        vector<ll> a(qnum); 
        rep(i, qnum) rep(j, n) { 
            char c; cin >> c; 
            if (c - '0') 
                a[i] |= 1ll << j; 
        }

        map<lll, ll> memo; // 1 if impossible
        function<ll(lll, ll)> f = [&](lll x, ll counter) -> ll {
            if (popcount(x) == qnum - 1) 
                return 0;
            if (popcount(x) == qnum) 
                return INF;
            if (memo.count(x)) 
                return memo[x];

            ll ret = INF;
            rep(j, n) {
                lll yes, no; yes = no = x; 
                rep(i, qnum) 
                    (a[i] & ((ll)1 << j) ? yes : no) |= (lll)1 << i;

                ll tmp = -1;
                ll yes_ret = INF, no_ret = INF; 
                if (yes != x)
                    yes_ret = f(yes, counter+1);
                if (no != x)
                    no_ret = f(no, counter+1);
                if (yes_ret != INF)
                    chmax(tmp, yes_ret);
                if (no_ret != INF)
                    chmax(tmp, no_ret);
                if (tmp != -1)
                    chmin(ret, tmp + 1);
            }
            return memo[x] = ret;
        };
        cout << f(0, 0) << endl;
    }
    return 0;
}
