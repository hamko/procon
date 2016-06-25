#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define repi(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define fi first
#define se second
#define mp make_pair
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }

using ll = long long; using vll = vector<ll>; using vvll = vector<vll>;
static const long long INF = 1e18;

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n; 
    while (cin >> n && n) {
        string d(n, ' ');
        vector<char> x(n); rep(i, n) cin >> x[i];
        vector<char> y(n); rep(i, n) cin >> y[i];
        rep(i, n) 
            d[i] = (x[i] - y[i] + 10) % 10 + '0';

        static stack<pair<string, ll>> q;
        stack<pair<string, ll>>().swap(q);

        q.push(mp(d, 0));
        ll ret = INF;
        while (!q.empty()) {
            auto tmp = q.top().fi; auto d = q.top().se; q.pop();

            if (tmp == string(n, '0')) {
                chmin(ret, d);
                continue;
            }

            ll i = 0;
            while (tmp[i] == '0') i++;
            ll number = tmp[i] - '0';
            repi(j, i, n) {
                tmp[j] = '0' + ((tmp[j] - '0' - number) + 10) % 10;
                q.push(mp(tmp, d+1));
            }
        }
        cout << ret << endl;
    }
    return 0;
}
