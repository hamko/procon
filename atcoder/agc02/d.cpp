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

// ***************************************************************
// persistent RBST
// ***************************************************************
int T[100100];
struct rbst {
	int size = 1;
	int key;
	rbst *lch = nullptr;
	rbst *rch = nullptr;
	rbst(int key) : key(key) {}
};
void print(rbst *x) {
	if (x == nullptr) return;
	print(x->lch);
	cout << x->key << " ";
	print(x->rch);
}
unsigned xor32() {
	static unsigned z = time(NULL);
	z ^= z << 13; z ^= z >> 17; z ^= z << 5;
	return z;
}
int size(rbst *x) {
	return x == nullptr ? 0 : x->size;
}
rbst *push(rbst *x) {
	x = new rbst(*x);
	x->size = 1 + size(x->lch) + size(x->rch);
	return x;
}
rbst *merge(rbst *x, rbst *y) {
	if (x == nullptr) return y;
	if (y == nullptr) return x;
	if (xor32() % (size(x) + size(y)) < size(x)) {
		x = push(x);
		x->rch = merge(x->rch, y);
		return push(x);
	} else {
		y = push(y);
		y->lch = merge(x, y->lch);
		return push(y);
	}
}
pair<rbst *, rbst *> split(rbst *x, int k) {
	if (!x) return{ nullptr, nullptr };
	x = push(x);
	if (k <= size(x->lch)) {
		auto tmp = split(x->lch, k);
		x->lch = tmp.second;
		return make_pair(tmp.first, push(x));
	} else {
		auto tmp = split(x->rch, k - size(x->lch) - 1);
		x->rch = tmp.first;
		return make_pair(push(x), tmp.second);
	}
}
int lower_bound(rbst *x, int key) {
	if (!x) return 0;
	if (key <= x->key) return lower_bound(x->lch, key);
	return lower_bound(x->rch, key) + size(x->lch) + 1;
}
bool contains(rbst *x, int key) {
	if (!x) return false;
	if (key == x->key) return true;
	if (key < x->key) return contains(x->lch, key);
	return contains(x->rch, key);
}
rbst *insert(rbst *x, int key) {
	int lb = lower_bound(x, key);
	auto p = split(x, lb);

	if (contains(x, key)) {
		x = merge(p.first, p.second);
	} else {
		rbst *n = new rbst(key);
		x = merge(merge(p.first, n), p.second);
	}
	return x;
}
rbst *inorder(rbst *x, rbst *y) {
	if (x == nullptr) return y;
	y = inorder(x->lch, y);
	y = insert(y, x->key);
	y = inorder(x->rch, y);
	return y;
}

// ***************************************************************
// persistent union find 
// ***************************************************************
struct UnionFind {
	struct node {
		node *parent;
		int n_size = 1;
		int id;
		rbst *st = nullptr;
		node(int id) : id(id) { parent = this; }
	};

	vector<map<int, node *>> uf;

	UnionFind(int n) {
		uf.assign(n, map<int, node *>());
		for (int i = 0; i < n; i++) {
			node *x = new node(i);
			x->st = new rbst(T[i]);
			uf[i][-1] = x;
		}
	}

	node inline *clone(int sec, node *x) {
		x = new node(*x);
		uf[x->id][sec] = x;
		return x;
	}

	node inline *get(int x) {
		return uf[x].rbegin()->second;
	}

	node inline *get(int sec, int x) {
		return prev(uf[x].upper_bound(sec))->second;
	}

	node inline *root(int sec, node *x) {
		if (x->parent == x) return x;
		return root(sec, get(sec, x->parent->id));
	}

	void inline merge(int sec, node *x, node *y) {
		x = root(sec, x);
		y = root(sec, y);
		if (x == y) return;
		x = clone(sec, x);
		y = clone(sec, y);

		rbst *st;
		if (size(x->st) > size(y->st)) {
			st = inorder(y->st, x->st);
		} else {
			st = inorder(x->st, y->st);
		}

		x->parent = y->parent = x->n_size > y->n_size ? x : y;
		x->n_size = y->n_size = x->n_size + y->n_size;
		x->st = y->st = st;
	}

	void inline merge(int sec, int x, int y) {
		merge(sec, get(x), get(y));
	}

	bool inline is_same(int sec, int x, int y) {
		node *xx = prev(uf[x].upper_bound(sec))->second;
		node *yy = prev(uf[y].upper_bound(sec))->second;
		xx = root(sec, xx);
		yy = root(sec, yy);
        return xx == yy;
    }
	int inline get_size(int sec, int x) {
		node *xx = prev(uf[x].upper_bound(sec))->second;
		xx = root(sec, xx);
        return xx->n_size;
    }
    int query(int sec, int u, int v) {
		node *xx = prev(uf[u].upper_bound(sec))->second;
		node *yy = prev(uf[v].upper_bound(sec))->second;
		xx = root(sec, xx);
		yy = root(sec, yy);

        int anum = xx->n_size;
        int bnum = yy->n_size;
        bool same = xx == yy;

        int walk_num;
        if (same) {
            walk_num = anum;
        } else {
            walk_num = anum + bnum;
        }
//        cout << sec << " " << anum << " " << bnum << " " << same << ":" << walk_num<< endl;

        return walk_num;
    }
};


int main(void) {
    int n, m; scanf("%d %d", &n, &m);
    UnionFind uf(n);
    rep(i, m) {
        int u, v; scanf("%d %d", &u, &v); u--; v--;
        uf.merge(i, u, v);
    }

    int q; scanf("%d", &q);
    rep(i, q) {
        int u, v, c; scanf("%d %d %d", &u, &v, &c); u--; v--;
        int fail = -1, pass = n;
        while (pass - fail != 1) {
            int mid = (pass + fail) / 2;

            if (uf.query(mid, u, v) >= c) {
                pass = mid;
            } else {
                fail = mid;
            }
        }
        printf("%d\n", pass+1);
    }

    return 0;
}
