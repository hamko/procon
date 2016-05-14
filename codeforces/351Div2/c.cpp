#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { if (!v.empty()) { o << '['; copy(v.begin(), v.end(), ostream_iterator<T>(o, ", ")); o << "\b\b]"; } return o; }
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;
typedef pair<ll, ll> P;

static const double EPS = 1e-14;
static const long long INF = 1e18;
#define MAX_N 100005

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n; cin >> n;
    vll a(n); rep(i, a.size()) { cin >> a[i]; a[i]--; }

    vll ret(n);
    rep(i, n) { 
//        map<ll, ll> counter;
        vector<ll> counter(n, 0);
        ll prev = 0;
        for (int j = i; j < n; j++) {
            counter[a[j]]++;
            if (counter[prev] < counter[a[j]]) 
                prev = a[j];
            else if (counter[prev] == counter[a[j]])  
                chmin(prev, a[j]);
            ret[prev]++;
        }
    }

    rep(i, n) {
        if (i) cout << " ";
        cout << ret[i];
    }
    cout << endl;
    return 0;
}
