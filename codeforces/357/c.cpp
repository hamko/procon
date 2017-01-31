#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mt make_tuple
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

using ll = long long; using ld = long double; using vll = vector<ll>; using vvll = vector<vll>; using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>;
using P = pair<ll, ll>;

template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template<size_t...> struct seq{}; template<size_t N, size_t... Is> struct gen_seq : gen_seq<N-1, N-1, Is...>{}; template<size_t... Is> struct gen_seq<0, Is...> : seq<Is...>{};
template<class Ch, class Tr, class Tuple, size_t... Is>
void print_tuple(basic_ostream<Ch,Tr>& os, Tuple const& t, seq<Is...>){ using s = int[]; (void)s{0, (void(os << (Is == 0? "" : ", ") << get<Is>(t)), 0)...}; }
template<class Ch, class Tr, class... Args> 
auto operator<<(basic_ostream<Ch, Tr>& os, tuple<Args...> const& t) -> basic_ostream<Ch, Tr>& { os << "("; print_tuple(os, t, gen_seq<sizeof...(Args)>()); return os << ")"; }
ostream &operator<<(ostream &o, const vvll &v) { rep(i, v.size()) { rep(j, v[i].size()) o << v[i][j] << " "; cout << endl; } return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const unordered_map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it; o << "]";  return o; }
void printbits(ll mask, ll n) { rep(i, n) { cout << !!(mask & (1ll << i)); } cout << endl; }
#define ldout fixed << setprecision(40) 

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;

vector<char> c(100010);
vector<ll> v(100010);
vector<char> cret; 
vector<ll> vret; 
priority_queue<ll, vector<ll>, greater<ll>> q;
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n; cin >> n;

    rep(i, n) {
        string s; cin >> s; c[i] = s[0];
        if (c[i] != 'r')
            cin >> v[i];
    }

    cret.reserve(1000000);
    vret.reserve(1000000);
    rep(i, n) {
        if (c[i] == 'i') {
            q.push(v[i]);
            cret.pb('i');
            vret.pb(v[i]);
        } else if (c[i] == 'r') {
            if (q.size()) {
                q.pop();
                cret.pb('r');
                vret.pb('0');
            } else {
                cret.pb('i');
                vret.pb(0);
                cret.pb('r');
                vret.pb('0');
            }
        } else { // g
            if (!q.size()) {
                cret.pb('i');
                vret.pb(v[i]);
                q.push(v[i]);
                cret.pb('g');
                vret.pb(v[i]);
            } else {
                while (q.size() && q.top() < v[i]) {
                    cret.pb('r');
                    vret.pb('0');
                    q.pop();
                }
                if (q.size() && q.top() == v[i]) {
                    cret.pb('g');
                    vret.pb(v[i]);
                } else {
                    cret.pb('i');
                    vret.pb(v[i]);
                    q.push(v[i]);
                    cret.pb('g');
                    vret.pb(v[i]);
                }
            }
        }
    }

    cout << cret.size() << endl;
    rep(i, cret.size()) {
        if (cret[i] == 'i') 
            cout << "insert";
        else if (cret[i] == 'g') 
            cout << "getMin";
        else 
            cout << "removeMin";

        cout << " ";

        if (cret[i] == 'i') 
            cout << vret[i];
        else if (cret[i] == 'g') 
            cout << vret[i];

        cout << endl;
    }

    return 0;
}
