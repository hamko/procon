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
    vector<string> w(n); rep(i, n) cin >> w[i];


    map<char, string> ctoi;
    ctoi['b'] = "1"; ctoi['c'] = "1";
    ctoi['d'] = "2"; ctoi['w'] = "2";
    ctoi['t'] = "3"; ctoi['j'] = "3";
    ctoi['f'] = "4"; ctoi['q'] = "4";
    ctoi['l'] = "5"; ctoi['v'] = "5";
    ctoi['s'] = "6"; ctoi['x'] = "6";
    ctoi['p'] = "7"; ctoi['m'] = "7";
    ctoi['h'] = "8"; ctoi['k'] = "8";
    ctoi['n'] = "9"; ctoi['g'] = "9";
    ctoi['z'] = "0"; ctoi['r'] = "0";

    rep(i, n) {
        string tmp = "";
        rep(j, w[i].length()) {
            char c = w[i][j];
            string ac = "qwrtpsdfghjklzxcvbnmQWRTPSDFGHJKLZXCVBNM";

            bool found;
            rep(h, ac.length()) 
                if (c == ac[h]) {
                    found = 1;
                    break;
                }
            if (found) {
                tmp += ctoi[tolower(c)];
            }
        }
        w[i] = tmp;
    }

    bool first = true;
    rep(i, n) {
        if (!w[i].size()) continue;
        if (first) {
            first = false;
        } else {
            cout << " ";
        }
        cout << w[i];
    }
    cout << endl;


    return 0;
}
