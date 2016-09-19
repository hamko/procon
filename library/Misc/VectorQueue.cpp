#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { if (!v.empty()) { o << '['; copy(v.begin(), v.end(), ostream_iterator<T>(o, ", ")); o << "\b\b]"; } return o; }
using ll = long long; using ld = long double; using vll = vector<ll>; using vld = vector<ld>;
typedef pair<ll, ll> P;

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;
#define MAX_N 100005

// 括弧列の列挙を例としたvector queue
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n; cin >> n;
    vector<ll> q, q_next;
    q_next.pb(0); // 初期値をq_nextに代入
    ll t = 0;
    while (t < n && !q_next.empty()) {
        // 初めqは空で、q_nextは候補。これをswapして、qを全部消費する。
        q.swap(q_next);
        while (!q.empty()) {
            ll tmp = q.back(); q.pop_back();
            if (__builtin_popcount(tmp) > t / 2) // if 011->2,3/2=1 ->OK, 0011->2, 4/2=2->NG
                q_next.pb(tmp); // Down
            if (__builtin_popcount(tmp) < n / 2)
                q_next.pb(tmp | (1ll << t)); // Up
        }
        t++;
    }
    rep(i, q_next.size()) {
        ll tmp = q_next[i];
        rep(j, n) 
            cout << ((tmp & (1ll << j)) ? "(" : ")");
        cout << endl;
    }
    return 0;
}
