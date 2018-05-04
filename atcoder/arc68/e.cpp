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

template<int MOD>
struct ModInt {
	static const int Mod = MOD;
	unsigned x;
	ModInt() : x(0) {}
	ModInt(signed sig) { int sigt = sig % MOD; if(sigt < 0) sigt += MOD; x = sigt; }
	ModInt(signed long long sig) { int sigt = sig % MOD; if(sigt < 0) sigt += MOD; x = sigt; }
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
template<int MOD> ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k) {
	ModInt<MOD> r = 1;
	while(k) {
		if(k & 1) r *= a;
		a *= a;
		k >>= 1;
	}
	return r;
}
typedef ModInt<1000000007> mint;
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




// Black box liner algebra
struct RandomModInt {
    default_random_engine re;
    uniform_int_distribution<int> dist;
#ifndef _DEBUG
    RandomModInt() : re(random_device{}()), dist(1, mint::Mod - 1) { }
#else
    RandomModInt() : re(), dist(1, mint::Mod - 1) { }
#endif
    mint operator()() {
        mint r;
        r.x = dist(re);
        return r;
    }
} randomModInt;

void randomModIntVector(vector<mint> &v) {
    int n = (int)v.size();
    for(int i = 0; i < n; ++ i)
        v[i] = randomModInt();
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


// GF(mod)の行列演算
// thisが表す行列はAとする。
//
// この行列演算は、「掛け算の実装のみを要求する」。
// 合計で、O(n^2 + n^2 log k + n T(n))
class matrixData {
public:
    int n;
    matrixData(int n_arg) { n = n_arg; }
    int size(void) { return n; }

    // 行列Aとベクトルvec_inの掛け算して、vec_outを返す。
    // vec_outはこの関数で確保される。
    // 
    // O(M(n)) : 密行列でO(n^2), コンパニオンでO(n), w要素疎行列でO(w)
    virtual void productMatrixByVector(vmint& vec_out, const vmint& vec_in) = 0;

    // 行列Aとベクトルdiag_inの掛け算して、副作用でAを更新する
    // この関数は最小多項式を特性多項式に一致させるためのものなので、diag_inの掛け算方向は問わない
    // 
    // O(w) : w要素疎行列でO(w)
    virtual void productDiagByMatrix(const vmint& diag_in) = 0;

    // Black Box Linear Algebraを使って、最小多項式の係数を乱択計算する
    // 乱択だがほぼ100%一致するので、答えが合っているかのチェックする必要なし
    // 出力はthis->phiに格納される。
    // 
    // O(n^2 + n T(n)), T(n)は行列とベクトルの掛け算
    void computeMinimumPolynomialUsingBlackBoxLinearAlgebra(vmint& phi_out) {
        vector<mint> dp(n * 2), u(n), v(n);
        randomModIntVector(u); randomModIntVector(v);
        vector<mint> Aiv = v; // i = 0

        // 2n個のdp[i]=u^t A^i vを列挙
        vector<mint> Aiv_next;
        rep(i, n * 2) {
            rep(j, n) dp[i] += u[j] * Aiv[j];
            productMatrixByVector(Aiv_next, Aiv);
            Aiv = Aiv_next;
        }

        // dpが線形漸化的で、その係数が行列の最小多項式phi_outに高確率に一致する
        computeMinimumPolynomialForLinearlyRecurrentSequence(dp, phi_out);
    }

    // A^k vec_inを、vec_outを返す。
    // vec_outはこの関数で確保される。
    // 
    // O(n^2 log k)
    void computeMatrixPowerByVector(vmint &res_out, const vmint &v_in, const long long k) {
        res_out.assign(n, mint());

        // 最小多項式を得る
        vmint phi; computeMinimumPolynomialUsingBlackBoxLinearAlgebra(phi);

        // A^k = \Sigma A^i coeffs[i]となるcoeffsを得る。
        vector<mint> coeffs; linearlyRecurrentSequenceCoeffs(k, phi, coeffs);

        // A^k v_inを具体的に計算
        vmint vec = v_in, vec_next;
        rep(i, phi.size() - 1) {
            rep(j, n) res_out[j] += coeffs[i] * vec[j];
            productMatrixByVector(vec_next, vec);
            vec = vec_next;
        }
    }

    // ベクトルbを入力として、A x = bなるxを返す。
    // xこの関数で確保される。
    // 
    // O(n T(n)), T(n)は行列とベクトルの掛け算
    void solve(vmint &x, const vmint &b) {
        x.assign(n, mint());

        // 最小多項式を得る
        vmint phi; computeMinimumPolynomialUsingBlackBoxLinearAlgebra(phi);

        // x = -1/phi[0]*(phi[1]*b+phi[2]*A*b+...+phi[d]*A^{d-1}*b)
        // なのでそれを愚直に計算
        vmint Aib = b;
        repi(i, 1, phi.size()) {
            rep(j, n) x[j] += phi[i] * Aib[j];
            vmint Aib_next;
            productMatrixByVector(Aib_next, Aib);
            Aib = Aib_next;
        }
        rep(j, n) x[j] /= -phi[0];
    }

    // det(A)を高確率に求める
    // 
    // det(A) = (-1)^n char(A)(0)なので、まず特性方程式char(A)を求める。
    // Black Box Linear Algebraで求めるのは最小多項式だが、
    // ランダムな対角行列をかけると、最小多項式と特性方程式が高確率で一致する。
    // 特性多項式というのは、要するにケイリーハミルトンの係数のことである。
    // 
    // 乱択だがほぼ100%一致するので、答えが合っているかのチェックする必要なし
    ///
    // O(n^2 + n T(n)), T(n)は行列とベクトルの掛け算
    mint det(void) {
        // ランダム対角行列DをAにかける
        vmint D(n); randomModIntVector(D); productDiagByMatrix(D);

        // 最小多項式phi(AD)を得る。
        // ランダム対角行列Dをかけたので、これは高確率で特性多項式char(AD)でもある。
        vmint Dphi; computeMinimumPolynomialUsingBlackBoxLinearAlgebra(Dphi);

        // det(AD) = det(DA) = (-1)^n * char(AD)(0) = det(A) * \Pi D[i]
        // なので、det(A) = (-1)^n * char(AD)(0) / (\Pi D[i])
        mint ret = Dphi[0] * (n % 2 ? -1 : 1); rep(i, n) ret /= D[i];

        // productDiagByMatrixは副作用で変更するので、行列を戻しとく
        rep(i, n) D[i] = mint(1) / D[i];
        productDiagByMatrix(D);

        return ret;
    }

    virtual ~matrixData() {}
};

// yukicoder旨味の相乗効果用。O(n)
class myMatrixData : public matrixData {
public:
    vmint data; // 行列のデータ。データのアラインメントはユーザに任せる。
    myMatrixData(int n_arg, vmint &data_arg) : matrixData(n_arg) {
        data = data_arg; 
    }
    // O(n)
    virtual void productMatrixByVector(vmint& vec_out, const vmint& vec_in) {
        vec_out.resize(n);
        vec_out[0] = vec_in[0] * data[0];
        rep(i, n-1) 
            vec_out[i+1] = vec_out[i] + vec_in[i+1] * data[i+1];
    }
    // O(n), 対角行列は右からかける
    virtual void productDiagByMatrix(const vmint& diag_in) {
        rep(i, n) data[i] *= diag_in[i];
    }

    virtual ~myMatrixData() {}
};


/*
   テンプレート
*/
class templateMatrixData : public matrixData {
public:
    vmint data; // 行列のデータ。データのアラインメントはユーザに任せる。
    templateMatrixData(int n_arg, vmint &data_arg) : matrixData(n_arg) {
        data = data_arg; 
    }
    virtual void productMatrixByVector(vmint& vec_out, const vmint& vec_in) {
        cerr << "productMatrixByVector not implemented." << endl; exit(1); 
    }
    virtual void productDiagByMatrix(const vmint& diag_in) {
        cerr << "productDiagByMatrix not implemented." << endl; exit(1); 
    }

    virtual ~templateMatrixData() {}
};

int main(void) {
    constructFactorial(2e6);
    ll N; cin >> N;
    ll a,b,c,d;cin>>a>>b>>c>>d;
    mint dp[1010][1010] = {};
    dp[0][0] = 1;
    repi(k, 1, N+1) {
        rep(n, N+1) {
            rep(x, n/k+1) { 
                if (!(a <= k && k <= b) && x != 0) continue;
                if (!(x == 0 || (c <= x && x <= d))) continue;
                if (x)  {
//                    cout << x << " " << n << " " << k  << " " << mt(fact[n],  fact[n-x*k] , (fact[k] ^ x) , (fact[x])  , dp[k-1][n-x*k]) << endl;;
                    mint tmp = fact[n] / fact[n-x*k] / (fact[k] ^ x) / (fact[x])  * dp[k-1][n-x*k];
                    dp[k][n] += tmp;
                } else {
                    dp[k][n] += dp[k-1][n];
                }
            }
            /*
            if (dp[k][n] != 0) {
                cout << mt(k,n,dp[k][n]) << "#DP" << endl;
            }
            */
        }
    }
    rep(i, N+1) {
        rep(j, N+1) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << dp[N][N] << endl;

    return 0;
}
