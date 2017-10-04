#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define repi(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mt make_tuple
#define mp make_pair
#define ZERO(a) memset(a,0,sizeof(a))
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
#define exists find_if
#define forall all_of

using ll = long long; using vll = vector<ll>; using vvll = vector<vll>; using P = pair<ll, ll>;
using ld = long double;  using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>; vll conv(vi& v) { vll r(v.size()); rep(i, v.size()) r[i] = v[i]; return r; }

inline void input(int &v){ v=0;char c=0;int p=1; while(c<'0' || c>'9'){if(c=='-')p=-1;c=getchar();} while(c>='0' && c<='9'){v=(v<<3)+(v<<1)+c-'0';c=getchar();} v*=p; }
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template<size_t...> struct seq{}; template<size_t N, size_t... Is> struct gen_seq : gen_seq<N-1, N-1, Is...>{}; template<size_t... Is> struct gen_seq<0, Is...> : seq<Is...>{};
template<class Ch, class Tr, class Tuple, size_t... Is>
void print_tuple(basic_ostream<Ch,Tr>& os, Tuple const& t, seq<Is...>){ using s = int[]; (void)s{0, (void(os << (Is == 0? "" : ", ") << get<Is>(t)), 0)...}; }
template<class Ch, class Tr, class... Args> 
auto operator<<(basic_ostream<Ch, Tr>& os, tuple<Args...> const& t) -> basic_ostream<Ch, Tr>& { os << "("; print_tuple(os, t, gen_seq<sizeof...(Args)>()); return os << ")"; }
ostream &operator<<(ostream &o, const vvll &v) { rep(i, v.size()) { rep(j, v[i].size()) o << v[i][j] << " "; o << endl; } return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const unordered_set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U, typename V>  ostream &operator<<(ostream &o, const unordered_map<T, U, V> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it; o << "]";  return o; }
vector<int> range(const int x, const int y) { vector<int> v(y - x + 1); iota(v.begin(), v.end(), x); return v; }
template <typename T> istream& operator>>(istream& i, vector<T>& o) { rep(j, o.size()) i >> o[j]; return i;}
string bits_to_string(ll input, ll n=64) { string s; rep(i, n) s += '0' + !!(input & (1ll << i)); reverse(all(s)); return s; }
template <typename T> ostream &operator<<(ostream &o, const priority_queue<T> &v) { auto tmp = v; while (tmp.size()) { auto x = tmp.top(); tmp.pop(); o << x << " ";} o << endl; return o; }

template <typename T> unordered_map<T, ll> counter(vector<T> vec){unordered_map<T, ll> ret; for (auto&& x : vec) ret[x]++; return ret;};
string substr(string s, P x) {return s.substr(x.fi, x.se - x.fi); }
void vizGraph(vvll& g, int mode = 0, string filename = "out.png") { ofstream ofs("./out.dot"); ofs << "digraph graph_name {" << endl; set<P> memo; rep(i, g.size())  rep(j, g[i].size()) { if (mode && (memo.count(P(i, g[i][j])) || memo.count(P(g[i][j], i)))) continue; memo.insert(P(i, g[i][j])); ofs << "    " << i << " -> " << g[i][j] << (mode ? " [arrowhead = none]" : "")<< endl;  } ofs << "}" << endl; ofs.close(); system(((string)"dot -T png out.dot >" + filename).c_str()); }

size_t random_seed; namespace std { using argument_type = P; template<> struct hash<argument_type> { size_t operator()(argument_type const& x) const { size_t seed = random_seed; seed ^= hash<ll>{}(x.fi); seed ^= (hash<ll>{}(x.se) << 1); return seed; } }; }; // hash for various class
namespace myhash{ const int Bsizes[]={3,9,13,17,21,25,29,33,37,41,45,49,53,57,61,65,69,73,77,81}; const int xor_nums[]={0x100007d1,0x5ff049c9,0x14560859,0x07087fef,0x3e277d49,0x4dba1f17,0x709c5988,0x05904258,0x1aa71872,0x238819b3,0x7b002bb7,0x1cf91302,0x0012290a,0x1083576b,0x76473e49,0x3d86295b,0x20536814,0x08634f4d,0x115405e8,0x0e6359f2}; const int hash_key=xor_nums[rand()%20]; const int mod_key=xor_nums[rand()%20]; template <typename T> struct myhash{ std::size_t operator()(const T& val) const { return (hash<T>{}(val)%mod_key)^hash_key; } }; };
template <typename T> class uset:public std::unordered_set<T,myhash::myhash<T>> { using SET=std::unordered_set<T,myhash::myhash<T>>; public: uset():SET(){SET::rehash(myhash::Bsizes[rand()%20]);} };
uint32_t randxor() { static uint32_t x=1+(uint32_t)random_seed,y=362436069,z=521288629,w=88675123; uint32_t t; t=(x^(x<<11));x=y;y=z;z=w; return( w=(w^(w>>19))^(t^(t>>8)) ); }
struct timeval start; double sec() { struct timeval tv; gettimeofday(&tv, NULL); return (tv.tv_sec - start.tv_sec) + (tv.tv_usec - start.tv_usec) * 1e-6; }
struct init_{init_(){ gettimeofday(&start, NULL); ios::sync_with_stdio(false); cin.tie(0); struct timeval myTime; struct tm *time_st; gettimeofday(&myTime, NULL); time_st = localtime(&myTime.tv_sec); srand(myTime.tv_usec); random_seed = RAND_MAX / 2 + rand() / 2; }} init__;
#define rand randxor

static const long long INF = 1e18;
static const long long mo = 1e9+7;
#define ldout fixed << setprecision(40) 

typedef double Num;
typedef short Var;
typedef vector<Num> Vec;
typedef vector<Vec> Mat;
const Num Inf = numeric_limits<Num>::infinity();
const Num NaN = numeric_limits<Num>::quiet_NaN();
#define IsNaN(x) (x != x)
const Num EPS = 1e-10;
inline bool isInteger(Num x) { return abs(floor(x) - x) <= EPS; }

#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))

Num simplex(const Mat& A, const Vec& b, const Vec& c, vector<Num> &out_assigns) {
	const int m = A.size(), n = A[0].size();
	Mat D(m+1, Vec(n+1)); vi id(n+m+1);
	rer(i, 0, n+m) id[i] = i;
	rep(i, m) {
		rep(j, n) D[i][j] = -A[i][j];
		D[i][n] = b[i];
	}
	rep(j, n) D[m][j] = c[j];
	while(1) {
		int r = m, s = n+m;
		rep(i, m) if(D[i][n] < -EPS && id[n+r] > id[n+i]) r = i;
		rep(j, n) if(D[m][j] > EPS && id[s] > id[j]) s = j;
		if(r == m && s == n + m) break;
		if(id[n + r] < id[s]) {
			s = n + m;
			rep(j, n) if(D[r][j] > EPS && id[s] > id[j]) s = j;
		}else {
			r = m;
			rep(i, m) if(D[i][s] < -EPS && id[n+r] > id[n+i]) r = i;
		}
		if(r == m) { /* Unbounded */ return Inf; }
		if(s == n + m) { /* NoSolution */ return NaN; }
		swap(id[s], id[n+r]);
		D[r][s] = 1. / D[r][s];
		rer(j, 0, n) if(j != s) D[r][j] *= -D[r][s];
		rer(i, 0, m) if(i != r && abs(D[i][s]) > EPS) {
			rer(j, 0, n) if(j != s) D[i][j] += D[r][j] * D[i][s];
			D[i][s] *= D[r][s];
		}
	}

	out_assigns.assign(n, 0);
	rep(i, m) if(id[n+i] < n)
		out_assigns[id[n+i]] = D[i][n];

	return D[m][n];
}

Num go_simplex(const unique_ptr<Var[]> &vars, int orderi, Mat A, Vec b, Vec c, vector<Num> &out_assigns) {
	int m = b.size();
	Num cs = 0;
	rep(i, orderi) {
		Num val = vars[i];
		rep(j, m) {
			b[j] -= A[j][i] * val;
			A[j][i] = 0;
		}
		cs += c[i] * val;
		c[i] = 0;
	}
	Num solution = simplex(A, b, c, out_assigns);
	if(!IsNaN(solution) && solution != Inf) {
		solution += cs;
		rep(i, orderi)
			out_assigns[i] = vars[i];
	}
	return solution;
}

pair<Num, Num> get_relaxedbound_simplex(const unique_ptr<Var[]> &vars, int orderi, const Mat &org_A, const Vec &org_b, const Vec &org_c, Num best) {
	if(IsNaN(best)) best = -Inf;
	int n = org_c.size(), m = org_b.size();
	Mat A(m+1, Vec(n - orderi)); Vec b(m+1), c(n - orderi);
	rep(j, m) b[j] = org_b[j];
	rep(i, orderi) {
		Num val = vars[i];
		rep(j, m)
			b[j] -= org_A[j][i] * val;
		best -= org_c[i] * val;
	}
	reu(i, orderi, n) {
		rep(j, m) A[j][i - orderi] = org_A[j][i];
		A[m][i - orderi] = -org_c[i];
	}
	b[m] = -best;
	vector<Num> tmp;
	c[0] = 1;
	Num upper = simplex(A, b, c, tmp);
	c[0] = -1;
	Num lower = -simplex(A, b, c, tmp);
	return make_pair(lower, upper);
}

// Input: 
// x = (x_0, x_1, ..., x_{n-1})^T
//
// s.t. A x <= b
// max  c^t x
//
// A = k x n
// b = k
// c = n
//
// Output:
// 副作用でout_assignsに変数が入る。
Num branch_and_bound(const vector<pair<Var,Var> > &bounds, const Mat &A, const Vec &b, const Vec &c, Vec &out_assigns) {
    int n = bounds.size(), m = b.size();
    assert(n == c.size()); assert(n == A[0].size()); assert(m == A.size());

	Num best = NaN;
	//BFS
	vector<unique_ptr<Var[]>> q, next;
	next.push_back(nullptr);
	int orderi = 0;
	while(!next.empty()) {
		q.swap(next);
		while(!q.empty()) {
			unique_ptr<Var[]> assigns = move(q.back()); Vec relaxed_assigns; q.pop_back();
			Num relaxed = go_simplex(assigns, orderi, A, b, c, relaxed_assigns);
			if(IsNaN(relaxed) || best >= relaxed - EPS) continue;
			
			bool bounds_ok = true;
			rep(i, n) {
				Num assign = relaxed_assigns[i];
				bool e = bounds[i].first - EPS <= assign && assign <= bounds[i].second + EPS;
				e &= abs(assign - floor(assign + EPS)) <= EPS;
				if(!(bounds_ok &= e)) break;
			}
			if(bounds_ok) {
				if(IsNaN(best) || best < relaxed) {
					best = relaxed;
					out_assigns = relaxed_assigns;
				}
				continue;
			}

			if(orderi == n) continue;
			
			pair<Num, Num> relaxed_bound = get_relaxedbound_simplex(assigns, orderi, A, b, c, best);
			Var lower = (Var)(max((Num)bounds[orderi].first, relaxed_bound.first) + 1 - EPS);
			Var upper = (Var)(min((Num)bounds[orderi].second, relaxed_bound.second) + EPS);
			
			for(int x = upper; x >= lower; x --) {
				unique_ptr<Var[]> nx(new Var[orderi+1]);
				for(int i = 0; i < orderi; i ++) nx[i] = assigns[i];
				nx[orderi] = x;
				next.push_back(move(nx));
			}
		}
		orderi ++;
	}
	
	return best;
}

//Num branch_and_bound(const vector<pair<Var,Var> > &bounds, const Mat &A, const Vec &b, const Vec &c, Vec &out_assigns) {
int main(void) {
#if 0
    {
        // x = (x_0, x_1)^T
        //
        // s.t. A x <= b
        // max  c^t x

        // 1 <= x_0 <= 4
        // 3 <= x_1 <= 7
        //
        // s.t.
        // 1 x_0 + 2 x_1 <= 9
        // 5 x_0 + 9 x_1 <= 41
        //
        // max
        // 1 x_0 + 2 x_1
        vector<pair<Var, Var>> bounds = {
            {1, 3},
            {4, 7},
            {2, 9},
        };
        Mat A = {
            {1, 2, 3},
            {5, 9, 4},
        };
        Vec b = {
            100,
            100,
        };
        Vec c = {
            1,
            2,
            8,
        };

        Vec out_assigns;
        cout << branch_and_bound(bounds, A, b, c, out_assigns) << endl;
        cout << out_assigns<<endl;
    }
#endif


#if 0
    {
        ll n = 10, k = 10; // cin >> n >> k;
        vector<pair<Var, Var>> bounds(n);
        rep(i, n) {
            /*
               bounds[i].fi = rand() % 10;
               bounds[i].se = 10 + rand() % 10;
               */
            bounds[i].fi = 0;
            bounds[i].se = 10;
        }
        Mat A(k, Vec(n)); 
        rep(i, k) rep(j, n) {
            A[i][j] = rand() % 10;
        }
        Vec b(k);
        rep(i, k) {
            b[i] = 100 + rand() % 100;
        }
        Vec c(n);
        rep(i, n) {
            c[i] = rand() % 10;
        }
        Vec out_assigns;
        cout << branch_and_bound(bounds, A, b, c, out_assigns) << endl;
        cout << out_assigns<<endl;
    }
#endif

    // 01ナップザック
    {
        ll n, W; cin >> n >> W;
        vll p(n), w(n);
        rep(i, n) {
            cin >> p[i] >> w[i];
        }
        vector<pair<Var, Var>> bounds(n);
        rep(i, n) bounds[i] = pair<Var, Var>(0, 1);
        Mat A(1);
        rep(i, n) {
            A[0].pb(w[i]);
        }
        Vec b(1);
        b[0] = W;
        Vec c(n);
        rep(i, n) 
            c[i] = p[i];

        Vec out_assigns;
        cout << branch_and_bound(bounds, A, b, c, out_assigns) << endl;
        cout << out_assigns<<endl;
    }

    return 0;
}

