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
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

using ll = long long; using vll = vector<ll>; using vvll = vector<vll>; using P = pair<ll, ll>;
using ld = long double;  using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>; vll conv(vi& v) { vll r(v.size()); rep(i, v.size()) r[i] = v[i]; return r; }

inline void input(int &v){ v=0;char c=0;int p=1; while(c<'0' || c>'9'){if(c=='-')p=-1;c=getchar();} while(c>='0' && c<='9'){v=(v<<3)+(v<<1)+c-'0';c=getchar();} v*=p; } // これを使うならば、tieとかを消して！！
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template<size_t...> struct seq{}; template<size_t N, size_t... Is> struct gen_seq : gen_seq<N-1, N-1, Is...>{}; template<size_t... Is> struct gen_seq<0, Is...> : seq<Is...>{};
template<class Ch, class Tr, class Tuple, size_t... Is>
void print_tuple(basic_ostream<Ch,Tr>& os, Tuple const& t, seq<Is...>){ using s = int[]; (void)s{0, (void(os << (Is == 0? "" : ", ") << get<Is>(t)), 0)...}; }
template<class Ch, class Tr, class... Args> 
auto operator<<(basic_ostream<Ch, Tr>& os, tuple<Args...> const& t) -> basic_ostream<Ch, Tr>& { os << "("; print_tuple(os, t, gen_seq<sizeof...(Args)>()); return os << ")"; }
ostream &operator<<(ostream &o, const vvll &v) { rep(i, v.size()) { rep(j, v[i].size()) o << v[i][j] << " "; o << endl; } return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T> ostream &operator<<(ostream &o, const deque<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const unordered_set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U, typename V>  ostream &operator<<(ostream &o, const unordered_map<T, U, V> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it; o << "]";  return o; }
vector<int> range(const int x, const int y) { vector<int> v(y - x + 1); iota(v.begin(), v.end(), x); return v; }
template <typename T> istream& operator>>(istream& i, vector<T>& o) { rep(j, o.size()) i >> o[j]; return i;}
template <typename T, typename S, typename U> ostream &operator<<(ostream &o, const priority_queue<T, S, U> &v) { auto tmp = v; while (tmp.size()) { auto x = tmp.top(); tmp.pop(); o << x << " ";} return o; }
template <typename T> ostream &operator<<(ostream &o, const queue<T> &v) { auto tmp = v; while (tmp.size()) { auto x = tmp.front(); tmp.pop(); o << x << " ";} return o; }
template <typename T> ostream &operator<<(ostream &o, const stack<T> &v) { auto tmp = v; while (tmp.size()) { auto x = tmp.top(); tmp.pop(); o << x << " ";} return o; }
template <typename T> unordered_map<T, ll> counter(vector<T> vec){unordered_map<T, ll> ret; for (auto&& x : vec) ret[x]++; return ret;};
string substr(string s, P x) {return s.substr(x.fi, x.se - x.fi); }
void vizGraph(vvll& g, int mode = 0, string filename = "out.png") { ofstream ofs("./out.dot"); ofs << "digraph graph_name {" << endl; set<P> memo; rep(i, g.size())  rep(j, g[i].size()) { if (mode && (memo.count(P(i, g[i][j])) || memo.count(P(g[i][j], i)))) continue; memo.insert(P(i, g[i][j])); ofs << "    " << i << " -> " << g[i][j] << (mode ? " [arrowhead = none]" : "")<< endl;  } ofs << "}" << endl; ofs.close(); system(((string)"dot -T png out.dot >" + filename).c_str()); }
size_t random_seed; namespace std { using argument_type = P; template<> struct hash<argument_type> { size_t operator()(argument_type const& x) const { size_t seed = random_seed; seed ^= hash<ll>{}(x.fi); seed ^= (hash<ll>{}(x.se) << 1); return seed; } }; }; // hash for various class
struct timeval start; double sec() { struct timeval tv; gettimeofday(&tv, NULL); return (tv.tv_sec - start.tv_sec) + (tv.tv_usec - start.tv_usec) * 1e-6; }
struct init_{init_(){ ios::sync_with_stdio(false); cin.tie(0); gettimeofday(&start, NULL); struct timeval myTime; struct tm *time_st; gettimeofday(&myTime, NULL); time_st = localtime(&myTime.tv_sec); srand(myTime.tv_usec); random_seed = RAND_MAX / 2 + rand() / 2; }} init__;
#define ldout fixed << setprecision(40) 

#define EPS (double)1e-14
#define INF (ll)1e18
#define mo  (ll)(1e9+7)

int MOD = 111111113;
struct ModInt {
	int Mod = -1;
	unsigned x;
	ModInt() : x(0) {Mod = MOD;}
	ModInt(signed sig) { Mod = MOD;int sigt = sig % MOD; if(sigt < 0) sigt += MOD; x = sigt; }
	ModInt(signed long long sig) { Mod = MOD;int sigt = sig % MOD; if(sigt < 0) sigt += MOD; x = sigt; }
	int get() const { return (int)x; }

	ModInt &operator+=(ModInt that) { if((x += that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator-=(ModInt that) { if((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
	ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }

	ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
	ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
	ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
	ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }

	ModInt inverse() const {
		signed a = x, b = MOD, u = 1, v = 0;
		while(b) {
			signed t = a / b;
			a -= t * b; std::swap(a, b);
			u -= t * v; std::swap(u, v);
		}
		if(u < 0) u += Mod;
		ModInt res; res.x = (unsigned)u;
		return res;
	}

	bool operator==(ModInt that) const { return x == that.x; }
	bool operator!=(ModInt that) const { return x != that.x; }
	ModInt operator-() const { ModInt t; t.x = x == 0 ? 0 : Mod - x; return t; }
};
ModInt operator^(ModInt a, unsigned long long k) {
	ModInt r = 1;
	while(k) {
		if(k & 1) r *= a;
		a *= a;
		k >>= 1;
	}
	return r;
}
typedef ModInt mint;
typedef vector<mint> vmint;
ostream &operator<<(ostream &o, const mint v) {  o << v.x; return o; }

// n!と1/n!のテーブルを作る。
// nCrを高速に計算するためのもの。
//
// O(n + log mo)
vector<mint> fact, rfact;
void constructFactorial(const long long n) {
    fact.resize(n);
    rfact.resize(n);
    fact[0] = rfact[0] = 1;
    for (int i = 0; i < n - 1; i++) {
        fact[i+1] = fact[i] * (i+1);
    }
    rfact[n-1] = mint(1) / fact[n-1]; 
    for (int i = n - 1; i >= 1; i--) 
        rfact[i-1] = rfact[i] * i; // ((n-1)!)^-1 = (n!)^-1 * n
}

// O(1)
// constructFactorialしておけば、n, r=1e7くらいまではいけます
mint nCr(const long long n, const long long r) {
    if (n < 0 || r < 0) return 0;
    if (n < r) return 0;
    return fact[n] * rfact[r] * rfact[n-r];
}

// O(r.size())
// sum(r)! / r[0]! / r[1]! / ...
mint nCr(const vector<long long> r) {
    ll sum = accumulate(r.begin(), r.end(), 0ll);
    mint ret = fact[sum];
    rep(i, r.size()) 
        ret *= rfact[r[i]];
    return ret;
}

// O(k log mo) 
mint nCrWithoutConstruction(const long long n, const long long k) {
    if (n < 0) return 0;
    if (k < 0) return 0;
    mint ret = 1;
    for (int i = 0; i < k; i++) {
        ret *= (mint)n - (mint)i;
        ret /= mint(i+1);
    }
    return ret;
}






// Matrix


// 行列xベクトル
vector<mint> mul(vector<vector<mint>> A, vector<mint> x) {
    assert(A.size() >= 0); assert(A[0].size() == x.size());
    vector<mint> b(A.size());
    rep(i, A.size()) {
        rep(j, A[0].size()) {
            b[i] += A[i][j] * x[j];
        }
    }
    return b;
}
// 行列x行列
vector<vector<mint>> mul(vector<vector<mint>> A, vector<vector<mint>> B) {
    assert(A[0].size() == B.size());
    vector<vector<mint>> C(A.size(), vector<mint>(B[0].size()));
    rep(i, A.size()) rep(j, B[0].size()) {
        rep(h, A[0].size()) {
            C[i][j] += A[i][h] * B[h][j];
        }
    }
    return C;
}
// ベクトル+ベクトル
vector<mint> plu(vector<mint> x, vector<mint> y) {
    assert(x.size() == y.size());
    rep(i, x.size()) {
        y[i] += x[i];
    }
    return y;
}
// 行列+行列
vector<vector<mint>> plu(vector<vector<mint>> A, vector<vector<mint>> B) {
    assert(A.size() == B.size());
    assert(A[0].size() == B[0].size());
    rep(i, A.size()) rep(j, A[0].size()) {
        B[i][j] += A[i][j];
    }
    return B;
}


vector<vector<mint>> transpose(vector<vector<mint>> A) {
    rep(i, A.size()) repi(j, i+1, A.size()) swap(A[i][j], A[j][i]);
    return A;
}
mint dot(vector<mint> x, vector<mint> y) {
    mint ret = 0;
    rep(i, x.size())
        ret += x[i] * y[i];
    return ret;
}
vector<mint> pow(vector<vector<mint>> A, vector<mint> x, long long k) {
    vector<vector<vector<mint>>> Ak; // Ak[i] = A^{2^i}

    Ak.push_back(A);
    rep(i, 70) 
        Ak.push_back(mul(Ak[i], Ak[i]));
    ll cyc = 0;
    while (k) {
        if (k & 1)
            x = mul(Ak[cyc], x);
        k /= 2;
        cyc++;
    }
    return x;
}




// GF(mo)列sから、それを生成する最小線形漸化式Cを復元する
//
// 入力: 漸化式が生成したGF(mo)列s
// 出力: d項間漸化式の係数C (size = d+1)
// 漸化式
//      C_0 s_{n} + C_1 s_{n-1} + ... + C_{L} s{n-L} = 0
// がsを生成した時、Cを求める。
//
// O(n^2)
//
// 例:
// s = [1, 2, 4, 8] -> C = [1, 1000000005(-2)] (s[1] - 2 * s[0] = 0)
// s = [1, 1, 1, 1] -> C = [1, 1000000006(-1)] (s[1] - s[0] = 0)
int berlekampMassey(const vector<mint> &s, vector<mint> &C) {
    int N = (int)s.size();
    C.assign(N + 1, mint());
    vector<mint> B(N + 1, mint());
    C[0] = B[0] = 1;
    int degB = 0;
    vector<mint> T;
    int L = 0, m = 1;
    mint b = 1;
    for(int n = 0; n < N; ++ n) {
        mint d = s[n];
        for(int i = 1; i <= L; ++ i)
            d += C[i] * s[n - i];
        if(d == mint()) {
            ++ m;
        } else {
            if(2 * L <= n)
                T.assign(C.begin(), C.begin() + (L + 1));
            mint coeff = -d * b.inverse();
            for(int i = -1; i <= degB; ++ i)
                C[m + i] += coeff * B[i];
            if(2 * L <= n) {
                L = n + 1 - L;
                B.swap(T);
                degB = (int)B.size() - 1;
                b = d;
                m = 1;
            } else {
                ++ m;
            }
        }
    }
    C.resize(L + 1);
    return L;
}

// GF(mo)列aから、それを生成する最小線形漸化式\phiを復元する
// berlekampMasseyとの違いは、係数の順序が違うのと安全用のassertチェックがあること。
//
// 入力: 漸化式が生成したGF(mo)列a
// 出力: d項間漸化式の係数\phi (size = d+1)
// 漸化式
//      \phi_0 a_{i} + \phi_1 a_{1} + ... + \phi_L a_L = 0
// がaを生成した時、\phiを求める。
//
// O(n^2)
//
// 例:
// s = [1, 2, 4, 8] -> C = [1000000005(-2), 1] (s[1] - 2 * s[0] = 0)
// s = [1, 1, 1, 1] -> C = [1000000006(-1), 1] (s[1] - s[0] = 0)
void computeMinimumPolynomialForLinearlyRecurrentSequence(const vector<mint> &a, vector<mint> &phi) {
    assert(a.size() % 2 == 0);
    int L = berlekampMassey(a, phi);
    reverse(phi.begin(), phi.begin() + (L + 1));
}

// 漸化式
//      \phi_0 a_0 + \phi_1 a_1 + ... + \phi_L a_L = 0
// と、initValues = a[0:phi.size()-1]が与えられる。
// この時、a[k]をinitValues(=a[0:phi.size()-1])の線形結合の係数を返す。
//     a[k] = coeff[0] * initValues[0] + coeff[1] * initValues[1] + ...  + coeff[d-1] * initValues[d-1] 
//
// O(n^2 log k)
void linearlyRecurrentSequenceCoeffs(long long k, const vector<mint> &phi_in, vector<mint> &coeffs) {
	int d = (int)phi_in.size() - 1;
	assert(d >= 0);
	assert(phi_in[d].get() == 1);

    coeffs = vector<mint>(d);
	vector<mint> square;
	coeffs[0] = 1;
	int l = 0;
	while ((k >> l) > 1) ++l;
	for (; l >= 0; --l) {
		square.assign(d * 2 - 1, mint());
        rep(i, d) rep(j, d) square[i + j] += coeffs[i] * coeffs[j];
		for (int i = d * 2 - 2; i >= d; -- i) {
			mint c = square[i];
			if (c.x == 0) continue;
            rep(j, d) square[i - d + j] -= c * phi_in[j];
		}
        rep(i, d)
			coeffs[i] = square[i];
		if (k >> l & 1) {
			mint lc = coeffs[d - 1];
			for(int i = d - 1; i >= 1; -- i)
				coeffs[i] = coeffs[i - 1] - lc * phi_in[i];
			coeffs[0] = mint() - lc * phi_in[0];
		}
	}
}

// 漸化式
//      \phi_0 a_{i} + \phi_1 a_{1} + ... + \phi_L a_L = 0
// と、initValues = a[0:phi.size()-1]が与えられる。
// この時、
//      a_{k}を求める
//
// O(n^2 log k)
// 
// また、副産物として、a[k]をinitVectorの線形結合として表す係数coeffが得られる
// a[k] = coeff[0] * initValues[0] + coeff[1] * initValues[1] + ...  + coeff[d-1] * initValues[d-1] 
// 
mint linearlyRecurrentSequenceValue(long long k, const vector<mint> &initValues, const vector<mint> &phi) {
    int d = phi.size() - 1;
	if(d == 0) return mint();
	assert(d <= (int)initValues.size());
    assert(k >= 0);

    if(k < (int)initValues.size())
        return initValues[(int)k];

    vector<mint> coeffs;
    linearlyRecurrentSequenceCoeffs(k, phi, coeffs);

	mint res; rep(i, d) res += coeffs[i] * initValues[i];
	return res;
}

// 線形漸化的数列aのk番目は？
// O(n^2 log k)
mint reconstruct(long long k, vector<mint> a) {
    if (a.size() % 2) a.pop_back();
    vector<mint> a_first_half;
    rep(i, a.size() / 2)
        a_first_half.push_back(a[i]);
    vector<mint> phi;
    computeMinimumPolynomialForLinearlyRecurrentSequence(a, phi);
    return linearlyRecurrentSequenceValue(k, a_first_half, phi);
}


ll N = 4000;
int main(void) {
    ll n, m; cin >> n >> m;
    MOD = m;
    constructFactorial(N);

    vector<vector<mint>> dp;
    dp.resize(N);
    rep(i, dp.size()) dp[i].resize(N);
    dp[0][0] = 1;
    repi(i, 1, n+1) rep(k, n+1) {
        dp[i][k] = dp[i-1][k] * mint(k+1) + dp[i-1][k-1];
    }
//    cout << dp << endl;

    //2^2^i
    vector<mint> pp(N);
    pp[0] = 2;
    repi(i,1,N) {
        pp[i]=pp[i-1]*pp[i-1];
    }
//    cout << pp << endl;

    vector<mint> f(N);
    repi(i,1,n+1) {
        mint tmp = 0;
        rep(k,i+1) {
            tmp += dp[i][k] * (mint(2)^((n-i)*k));
        }
        tmp *= pp[n-i];
        f[i] = tmp;
    }
//    cout << f << endl;

    mint ret = pp[n];
    repi(i,1,n+1) {
        ret += (i%2?mint(-1):mint(1))*nCr(n,i)*f[i];
    }
    cout << ret << endl;

    return 0;
}
