#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { if (!v.empty()) { o << '['; copy(v.begin(), v.end(), ostream_iterator<T>(o, ", ")); o << "\b\b]"; } return o; }
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;
typedef pair<ll, ll> P;

static const double EPS = 1e-14;
static const long long INF = 1e18;
#define MAX_N 100005

ll n, k, p;
string s;
string command;
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> n >> k >> p;
    cin >> s;
    cin >> command;

    list<char> l;
    rep(i, n) l.pb(s[i]);
    auto it = l.begin();
    advance(it, p - 1);
    prev(it, p - 1);
    advance(it, p - 1);

    rep(i, k) {
        char c = command[i];
        if (c == 'R') { it++; continue; }
        if (c == 'L') { it--; continue; }
        if (*it == '(') {
            int d = 0;
            do {
                d += (*it == '(' ? 1 : -1);
                it = l.erase(it);
            } while (d > 0);
        } else {
            int d = 0;
            do {
                d += (*it == '(' ? 1 : -1);
                it = l.erase(it), it--;
            } while (d < 0);
            it++;
        }
        if (it == l.end()) 
            it--;
    }

    for (auto x : l) cout << x;
    cout << endl;

    return 0;
}
