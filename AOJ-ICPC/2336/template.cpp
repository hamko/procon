#include <bits/stdc++.h>
using namespace std;

#ifdef _WIN32
#define scanfll(x) scanf("%I64d", x)
#define printfll(x) printf("%I64d", x)
#else
#define scanfll(x) scanf("%lld", x)
#define printfll(x) printf("%lld", x)
#endif
#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define repi(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mt make_tuple
#define mp make_pair
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

using ll = long long; using ld = long double; using vll = vector<ll>; using vvll = vector<vll>; using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>;
vll conv(vi& v) { vll r(v.size()); rep(i, v.size()) r[i] = v[i]; return r; }
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

// 浮動小数点二分探索
ld BinarySearchReal(ld rl, ld rr, function<bool(ld)> f) { 
    rep(i, 200) { ld m = (rl + rr) / 2; f(m)?rr=m:rl=m; }
    return rl;
}
void BinarySearchRealInteractive(ld rl, ld rr, function<bool(ld)> f) { 
    while (1) {
        cout << "####" << endl;
        ld tmp; cin >> tmp;
        if (rl > tmp) {cout << "Out of range: too small" << endl; continue; }
        if (rr < tmp) {cout << "Out of range: too large" << endl; continue; }
        ld ret = f(tmp); cout << tmp << " : " << ret << endl;
    }
}

char m[500][500] = {};
ll b[500][500] = {};
ll g[500][500] = {};
void print_map(ll w, ll h) {
    rep(hi, h) {
        rep(wi, w) {
            cout << m[hi][wi];
        }
        cout << endl;
    }
}

void print_bane(ll w, ll h) {
    rep(hi, h) {
        rep(wi, w) {
            if (b[hi][wi] == INF) 
                cout << -1 << "\t";
            else
                cout << b[hi][wi] << "\t";
        }
        cout << endl;
    }
}

void print_goal(ll w, ll h) {
    rep(hi, h) {
        rep(wi, w) {
            if (g[hi][wi] == INF) 
                cout << -1 << "\t";
            else
                cout << g[hi][wi] << "\t";
        }
        cout << endl;
    }
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll w, h; cin >> w >> h;
    rep(hi, h) {
        rep(wi, w) {
            cin >> m[hi][wi];
        }
    }
//    print_map(w, h);

    rep(hi, h) {
        rep(wi, w) {
            b[hi][wi] = INF;
        }
    }
    rep(hi, h) {
        rep(wi, w) {
            g[hi][wi] = INF;
        }
    }

    vector<ll> dh = {1, 0, -1, 0};
    vector<ll> dw = {0, 1, 0, -1};
    queue<P> q;

    rep(hi, h) {
        rep(wi, w) {
            if (m[hi][wi] == '*') {
                q.push(P(hi, wi));
                b[hi][wi] = 0;
            }
        }
    }
    while (!q.empty()) {
        P pos = q.front(); q.pop();
        ll hi = pos.fi, wi = pos.se;
        ll pos_dist = b[hi][wi];
        rep(d, 4) {
            ll next_hi = hi + dh[d];
            ll next_wi = wi + dw[d];
            if (next_hi < h && next_hi >= 0 && 
                next_wi < w && next_wi >= 0 &&
                (m[next_hi][next_wi] == '.' || m[next_hi][next_wi] == 's') && 
                b[next_hi][next_wi] == INF) {

                b[next_hi][next_wi] = pos_dist + 1;
                q.push(P(next_hi, next_wi));
            }
        }
    }
//    cout << endl;
//    print_bane(w, h);
    
    rep(hi, h) {
        rep(wi, w) {
            if (m[hi][wi] == 'g') {
                q.push(P(hi, wi));
                g[hi][wi] = 0;
            }
        }
    }
    while (!q.empty()) {
        P pos = q.front(); q.pop();
        ll hi = pos.fi, wi = pos.se;
        ll pos_dist = g[hi][wi];
        rep(d, 4) {
            ll next_hi = hi + dh[d];
            ll next_wi = wi + dw[d];
            if (next_hi < h && next_hi >= 0 && 
                next_wi < w && next_wi >= 0 &&
                (m[next_hi][next_wi] == '.' || m[next_hi][next_wi] == 's') && 
                g[next_hi][next_wi] == INF) {

                g[next_hi][next_wi] = pos_dist + 1;
                q.push(P(next_hi, next_wi));
            }
        }
    }
//    cout << endl;
//    print_goal(w, h);
 
    vector<P> bg;
    rep(hi, h) {
        rep(wi, w) {
            if (m[hi][wi] == '.' || m[hi][wi] == 's') {
                bg.pb(P(b[hi][wi], g[hi][wi]));
            }
        }
    }
    ll n = bg.size();

    // !!!!!!!!!!!!!!!!!!!! 1e8 !!!!!!!!!!!!!!!!!!!!
    function<bool(ld)> f = [&](ld e){
        ll k = 0;
        ll bsum = 0; 
        ll gsum = 0; 
        for (auto x : bg) {
            if (x.fi + e < x.se) {
                k++;
                bsum += x.fi;
            } else {
                gsum += x.se;
            }
        }
        return e * (n - k) > bsum + gsum;
    };
    ld e = BinarySearchReal(0, 1e40,  f);
//    cout << e << endl;

    ll hs = -1, ws = -1;
    rep(hi, h) {
        rep(wi, w) {
            if (m[hi][wi] == 's') {
                hs = hi;
                ws = wi;
            }
        }
    }
    cout << ldout << min((ld)b[hs][ws] + e, (ld)g[hs][ws]) << endl;
    
    // 5 1
    // .g...s*
    //
    //
    // 7 1
    // .g...s*
    //
    // 8 1
    // .g...s.*
    // # e = 2
    // # e = (1+1+2+3)/5 + (1+e)/5
    //
    // eってそんなに大きくなることあるの？
    // sample 2でe=2.8e15なんだけど

    return 0;
}
