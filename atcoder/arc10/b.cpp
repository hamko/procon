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
#define MAX_N 366

int main(void) {
    ll n; cin >> n;
    bool day[MAX_N]; rep(i, MAX_N) day[i] = (i % 7 == 0 || i % 7 == 6);
    vll month = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    rep(i, 12) month[i+1] += month[i];

    rep(i, n) {
        int a, b; 
        scanf("%d/%d", &a, &b);
        int d = month[a-1]+b-1;
        while(d < MAX_N && day[d]) d++;
        day[d] = true;
    }


    ll ret = 0, m = 0;
    rep(i, MAX_N) {
        m = (day[i] ? m + 1 : 0);
        chmax(ret, m);
    }
    cout << ret << endl;

    return 0;
}
