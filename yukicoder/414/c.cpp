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
template<size_t...> struct seq{}; template<size_t N, size_t... Is> struct gen_seq : gen_seq<N-1, N-1, Is...>{}; template<size_t... Is> struct gen_seq<0, Is...> : seq<Is...>{}; template<class Ch, class Tr, class Tuple, size_t... Is> void print_tuple(basic_ostream<Ch,Tr>& os, Tuple const& t, seq<Is...>){ using s = int[]; (void)s{0, (void(os << (Is == 0? "" : ", ") << get<Is>(t)), 0)...}; }
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

// 見た目はコピーが高速なUnion-Find

// memory: O(Q loglogN logN)
// mutable_get: O(loglogN logN)
// immutable_get: O(loglogN)
template<class T>
class Array {
public:
	Array() {}
 
	Array(int n) {
		h = 0;
		for (int i = 1; i < n; i *= 16) h += 4;
	}
 
	T *mutable_get(int k) {
		auto p = mutable_get(k, root, 0, h);
		root = p.first;
		return &p.second->value;
	}
 
	T immutable_get(int k) {
		return immutable_get(k, root, 0, h)->value;
	}
 
private:
	struct node {
		node *ch[16] = {};
		T value;
 
		node() {}
		node(T value) : value(value) {}
	};
 
	int h;
	node *root = nullptr;
 
	node *immutable_get(int a, node *x, int l, int d) {
		if (d == 0) return x;
		int id = (a - l) >> (d - 4);
		return immutable_get(a, x->ch[id], l + (id << (d - 4)), d - 4);
	}
 
	pair<node *, node *> mutable_get(int a, node *x, int l, int d) {
		x = x != nullptr ? new node(*x) : new node();
		if (d == 0) return make_pair(x, x);
		int id = (a - l) >> (d - 4);
		auto p = mutable_get(a, x->ch[id], l + (id << (d - 4)), d - 4);
		x->ch[id] = p.first;
		return make_pair(x, p.second);
	}
};
 
// root: O(logN loglogN)
// merge: O(logN loglogN)
struct UnionFind {
	struct node {
		int parent;
		int size;
	};
 
	Array<node> uf;
 
	UnionFind() : uf(0) {}
 
	UnionFind(int n) : uf(n) {
		for (int i = 0; i < n; i++) {
			node *nd = uf.mutable_get(i);
			nd->parent = i;
			nd->size = 1;
		}
	}
 
	int root(int x) {
		node nd = uf.immutable_get(x);
		if (nd.parent == x) return x;
		return root(nd.parent);
	}
 
	UnionFind merge(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y) return *this;
 
		node *u = uf.mutable_get(x);
		node *v = uf.mutable_get(y);
 
		u->parent = v->parent = u->size > v->size ? x : y;
		u->size = v->size = u->size + v->size;
		return *this;
	}
 
	bool same(int x, int y) {
        return root(x) == root(y);
    }

	int size(int x) {
        return uf.immutable_get(root(x)).size;
    }

	int query(int x, int y) {
        // Something
        /*
		x = root(x);
		y = root(y);
		if (x != y) {
			return uf.immutable_get(x).size + uf.immutable_get(y).size;
		} else {
			return uf.immutable_get(x).size;
		}
        */
        return 0;
	}
};
 

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n, m, q; cin >> n >> m >> q;
	vector<UnionFind> his(q+1);
    vll a(m), b(m); rep(i, m) { cin >> a[i] >> b[i]; a[i]--, b[i]--; }
    vll c(q), d(q); rep(i, q) { cin >> c[i] >> d[i]; c[i]--, d[i]--; }

    UnionFind uf(n);
    for (auto x : memo) {
        uf.unite(x.fi, x.se);
        cout << x << endl;
    }

    vll ret(n, 0);
    rep(i, n) {
        if (uf.find(0, i)) {
            ret[i] = -1;
        }
    }

    for (ll i = q-1; i >= 0; i--) {
        vector<bool> flags_bef(2) = {uf.find(0, c[i]), uf.find(0, d[i])};
        uf.unite(c[i], d[i]);
        vector<bool> flags_aft(2) = {uf.find(0, c[i]), uf.find(0, d[i])};
    }
    repi(i, 1, n) {
        cout << ret[i] << endl;
    }
    return 0;
}
