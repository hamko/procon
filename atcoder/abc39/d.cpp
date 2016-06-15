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
#define VN(v) # v
#define print(a) cout << a << "#" << VN(a) << endl;
#define ldout fixed << setprecision(40) 

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll ni, nj; cin >> ni >> nj;
	vector<string> b(ni);
	rep(i, ni)
		cin >> b[i];

	vector<string> b_cand(ni, string(nj, '.'));
	ll di[9] = {1, 1, 1, 0, 0, 0, -1, -1, -1};
	ll dj[9] = {1, -1, 0, 1, 0, -1, 1, -1, 0};
	rep(i, ni) {
		rep(j, nj) {
			int faf = 1;
			rep(d, 9) {
				if (i+di[d] < 0 || i+di[d] >= ni || j+dj[d] < 0 || j+dj[d] >= nj)
					continue;
				if (b[i+di[d]][j+dj[d]] == '.')
					faf = 0;
			}
			if (faf)
				b_cand[i][j] = '#';
		}
	}

	vector<string> b_ret(ni, string(nj, '.'));
	rep(i, ni) {
		rep(j, nj) {
			if (b_cand[i][j] == '.')
				continue;
			rep(d, 9) {
				if (i+di[d] < 0 || i+di[d] >= ni || j+dj[d] < 0 || j+dj[d] >= nj)
					continue;
				b_ret[i+di[d]][j+dj[d]] = '#';

			}
		}
	}

	rep(i, ni) {
		if (b[i] != b_ret[i]) {
			cout << "impossible" << endl;
			return 0;
		}
	}

	cout << "possible" << endl;
	rep(i, ni) {
		cout << b_cand[i] << endl;
	}
    return 0;
}