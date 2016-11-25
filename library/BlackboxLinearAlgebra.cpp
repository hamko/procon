#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

using ll = long long; using vll = vector<ll>; using vvll = vector<vll>;
using ld = long double;  using vld = vector<ld>; 
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
string bits_to_string(ll mask, ll n) { string s; rep(i, n) s += '0' + !!(mask & (1ll << i)); return s; }
#define ldout fixed << setprecision(40) 



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

ostream &operator<<(ostream &o, const mint v) {  o << v.x; return o; }

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
//      \phi_0 a_{i} + \phi_1 a_{1} + ... + \phi_L a_L = 0
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

	mint res;
    rep(i, d) res += coeffs[i] * initValues[i];
	return res;
}

class matrixData {
public:
    int n;
    vmint data;
    vmint phi;
    int d;
    matrixData(int n_arg, vmint &data_arg) { n = n_arg; data = data_arg; }
    void init(void) {
        computeMinimumPolynomialUsingBlackBoxLinearAlgebra();
    }

    int size(void) { return n; }

    // vec_out is allocated in THIS function.
    // u, v: random vector
    // dp[i] = u^t A^i v
    virtual void productMatrixByVector(vmint& vec_out, vmint& vec_in) = 0;

    // Cayley-Hamilton
    // O(n M(n)), M(n) is computation time of "matrix by vector"
    // 
    // I never care about "unlucky" situations because I'm enough lucky man.
    void computeMinimumPolynomialUsingBlackBoxLinearAlgebra(void) {
        vector<mint> dp(n * 2), u(n), v(n);
        randomModIntVector(u); randomModIntVector(v);
        vector<mint> Aiv = v; // i = 0

        // enumerate 2n dp[i]
        vector<mint> Aiv_next;
        rep(i, n * 2) {
            rep(j, n) dp[i] += u[j] * Aiv[j];
            productMatrixByVector(Aiv_next, Aiv);
            Aiv = Aiv_next;
        }

        computeMinimumPolynomialForLinearlyRecurrentSequence(dp, phi);
        d = phi.size() - 1;
    }

    // vec_out is allocated in THIS function.
    void computeMatrixPowerByVector(vmint &res_out, const vmint &v_in, long long k) {
        res_out.assign(n, mint());
        vmint vec = v_in;
        vmint vec_next;
        vector<mint> coeffs;

        linearlyRecurrentSequenceCoeffs(k, phi, coeffs);

        rep(i, d) {
            rep(j, n) res_out[j] += coeffs[i] * vec[j];
            productMatrixByVector(vec_next, vec); 
            vec = vec_next;
        }
    }
    virtual ~matrixData() {}
};

class myMatrixData : public matrixData {
public:
    myMatrixData(int n_arg, vmint &data_arg) : matrixData(n_arg, data_arg) {}
    virtual void productMatrixByVector(vmint& vec_out, vmint& vec_in) {
        vec_out.resize(n);
        vec_out[0] = vec_in[0] * data[0];
        rep(i, n-1) 
            vec_out[i+1] = vec_out[i] + vec_in[i+1] * data[i+1];
    }
    virtual ~myMatrixData() {}
};

int main() {
    /*
    {
        vector<mint> s = {1, 2, 4, 8}, C;
        berlekampMassey(s, C);
        cout << s << endl;
        cout << C << endl;
    }
    {
        vector<mint> s = {1, 1, 1, 1, 1, 1}, C;
        berlekampMassey(s, C);
        cout << s << endl;
        cout << C << endl;
    }
    */
    /*
    {
        vector<mint> a = {100, 1, 0, 0, 0, 0}, phi;
        computeMinimumPolynomialForLinearlyRecurrentSequence(a, phi);
        cout << a << endl;
        cout << phi << endl;
    }
    */

    // BLAを介して解く
    int n; long long c;
    cin >> n >> c;
    vmint data; rep(i, n) { int tmp; cin >> tmp; data.push_back(tmp); }

    myMatrixData m = myMatrixData(n, data);
    m.init();

    vmint res_out;
    vmint v_in(n, 1);
    m.computeMatrixPowerByVector(res_out, v_in, c);
    
    mint ans = res_out[n-1];
    rep(i, n)
        ans -= mint(data[i]) ^ c;
    cout << ans << endl;

    return 0;
}
