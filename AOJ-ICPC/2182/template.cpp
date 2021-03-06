#include <bits/stdc++.h>
using namespace std;

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

// 累積和の計算
// 構築O(n)
// クエリO(1)
const function<bool(ll)> f1_default = [](ll x) { return 1; };
class Sum1d {
public:
    vll data;
    vll sumdata;
    Sum1d(vll& d, function<bool(ll)> f = f1_default) {
        int n = d.size();
        data = d;
        sumdata = vll(n+1, 0);
        rep(i, n) if(f(i)) sumdata[i+1] = data[i];
        rep(i, n) sumdata[i+1] += sumdata[i];
    }
    // [i, j)の小区間の総和 (半開区間)
    ll sum(int i, int j) {
        return sumdata[j]-sumdata[i];
    }
    // [i, i+ilen)の小区間の総和 (半開区間)
    ll suml(int i, int len) {
        return this->sum(i, i+len);
    }
    void print(void) {
        rep(i, sumdata.size()) cout << sumdata[i] << " "; cout << endl;
    }
};


int main(void) {
    string str;
    while(getline(cin, str))
    {
        if (str == "0")
            break;

        vll d(str.size());
        rep(i, str.size())
            d[i] = (i % 2 ? -1 : 1) * (str[i] - '0');
        ll n = d.size();

        Sum1d s(d);

        ll ret = 0;
        vll b(11);
        b[(s.sumdata[n] % 11 + 11) % 11] = 1;
        for (int i = n-1; i >= 0; i--) {
            ll tmp = (s.sumdata[i] % 11 + 11) % 11;
            if (d[i]) 
                ret += b[tmp];
            b[tmp]++;
        }
        cout << ret << endl;
    }

    return 0;
}
