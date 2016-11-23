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
// 出力: 漸化式係数C
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
// 出力: 漸化式係数\phi
// 漸化式
//      \phi_0 a_0 + \phi_1 a_1 + ... + \phi_L a_L = 0
// がaを生成した時、\phiを求める。
//
// O(n^2)
//
// 例:
// s = [1, 2, 4, 8] -> C = [1, 1000000005(-2)] (s[1] - 2 * s[0] = 0)
// s = [1, 1, 1, 1] -> C = [1, 1000000006(-1)] (s[1] - s[0] = 0)
void computeMinimumPolynomialForLinearlyRecurrentSequence(const vector<mint> &a, vector<mint> &phi) {
    int n2 = (int)a.size(), n = n2 / 2;
    assert(n2 % 2 == 0);
    int L = berlekampMassey(a, phi);
    reverse(phi.begin(), phi.begin() + (L + 1));
}

// 第K項をinitValuesの線形結合coeffsで表す。
void linearlyRecurrentSequenceCoeffs(long long K, const vector<mint> &initValues, const vector<mint> &annPoly, vector<mint> &coeffs, int& d) {
	d = (int)annPoly.size() - 1;
	assert(d >= 0);
	assert(annPoly[d].get() == 1);
	assert(d <= (int)initValues.size());

    coeffs = vector<mint>(d);
	vector<mint> square;
	coeffs[0] = 1;
	int l = 0;
	while((K >> l) > 1) ++ l;
	for(; l >= 0; -- l) {
		square.assign(d * 2 - 1, mint());
		for(int i = 0; i < d; ++ i)
			for(int j = 0; j < d; ++ j)
				square[i + j] += coeffs[i] * coeffs[j];
		for(int i = d * 2 - 2; i >= d; -- i) {
			mint c = square[i];
			if(c.x == 0) continue;
			for(int j = 0; j < d; ++ j)
				square[i - d + j] -= c * annPoly[j];
		}
		for(int i = 0; i < d; ++ i)
			coeffs[i] = square[i];
		if(K >> l & 1) {
			mint lc = coeffs[d - 1];
			for(int i = d - 1; i >= 1; -- i)
				coeffs[i] = coeffs[i - 1] - lc * annPoly[i];
			coeffs[0] = mint() - lc * annPoly[0];
		}
	}
//    cout << coeffs << " " << coeffs.size() << endl;
}

// 数列aは、annPolyがinitValuesから生成する数列である。
// この時、a[K]を求める。
// 
// また、副産物として、a[K]をinitVectorの線形結合として表す係数coeffが得られる
// a[K] = coeff[0] * initValues[0] + coeff[1] * initValues[1] + ...  + coeff[d-1] * initValues[d-1] 
// 
// O(n^2 log K)
mint linearlyRecurrentSequenceValue(long long K, const vector<mint> &initValues, const vector<mint> &annPoly) {
    assert(K >= 0);
    if(K < (int)initValues.size())
        return initValues[(int)K];

    vector<mint> coeffs;
    int d;
    linearlyRecurrentSequenceCoeffs(K, initValues, annPoly, coeffs, d);

	assert(d >= 0);
	assert(annPoly[d].get() == 1);
	assert(d <= (int)initValues.size());
	if(d == 0)
		return mint();

	mint res;
	for(int i = 0; i < d; ++ i)
		res += coeffs[i] * initValues[i];
	return res;
}

mint linearlyRecurrentSequenceValue(long long K, const pair<vector<mint>, vector<mint> > &seqPair) {
	return linearlyRecurrentSequenceValue(K, seqPair.first, seqPair.second);
}

int n; long long c;
vector<int> as;
void productMatrixVector(vector<mint>& vec_next, vector<mint>& vec) {
    vector<mint> vecSum(n+1); rep(j, n) vecSum[j+1] = vecSum[j] + vec[j];
    vec_next = vector<mint>(n); // i = 0
    rep(j, n) {
        mint as_j = as[j];
        vec_next[j] = as_j * vecSum[j+1];
    }
    vec = vec_next;
}
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
    /*
	int n; long long c;
	while(~scanf("%d%lld", &n, &c)) {
		vector<int> as(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &as[i]);
		vector<mint> dp(n * 2);
		dp[0] = 1;
		rep(i, n) {
			mint a = as[i];
			rep(j, (int)dp.size() - 1)
				dp[j + 1] += dp[j] * a;
		}
        cout << dp << endl;
		vector<mint> phi;
		computeMinimumPolynomialForLinearlyRecurrentSequence(dp, phi);
		mint ans = linearlyRecurrentSequenceValue(c, dp, phi);
		rep(i, n)
			ans -= mint(as[i]) ^ c;
		printf("%d\n", ans.get());
	}
    */
    // BLAを介して解く
    cin >> n >> c;
    for(int i = 0; i < n; ++ i) {
        int tmp; cin >> tmp;
        as.push_back(tmp);
    }

    rep(_, 1) {
        cout << _ << endl;
        // u A^i v
        vector<mint> dp(n * 2);
        vector<mint> u(n), v(n);
        randomModIntVector(u);
        randomModIntVector(v);
        vector<mint> Aiv = v; // i = 0

        /*
        // O(n^2)による行列xベクトル演算
        rep(i, n * 2) {
            rep(j, n) dp[i] += u[j] * Aiv[j];
            vector<mint> Aiv_next(n); // i = 0
            rep(j, n) rep(h, n) { // O(n)に累積和を使えばなる
                if (h > j) continue;
                mint as_j = as[j];
                Aiv_next[j] += as_j * Aiv[h];
            }
            Aiv = Aiv_next;
        }
        */
        // O(n)による行列xベクトル演算
        rep(i, n * 2) {
            rep(j, n) dp[i] += u[j] * Aiv[j];
            vector<mint> Aiv_next;
            productMatrixVector(Aiv_next, Aiv);
            Aiv = Aiv_next;
        }

        vector<mint> phi;
        computeMinimumPolynomialForLinearlyRecurrentSequence(dp, phi);
        cout << phi << endl;

        vector<mint> coeffs;
        int d;
        linearlyRecurrentSequenceCoeffs(c, dp, phi, coeffs, d);
        vector<vector<mint>> AivList(d+1, vector<mint>(n));
        vector<mint> Aiv_vec = vector<mint>(n, 1);
        vector<mint> Aiv_vec_next;

        vector<mint> res(n);
        rep(i, d) {
            rep(j, n) res[j] += coeffs[i] * Aiv_vec[j];
            productMatrixVector(Aiv_vec_next, Aiv_vec); 
            Aiv_vec = Aiv_vec_next;
            cout << Aiv_vec << endl;
        }
        cout << coeffs << endl;
        cout << res << endl;

        /*
        vector<mint> phi;
        computeMinimumPolynomialForLinearlyRecurrentSequence(dp, phi);
        cout << phi << endl;

        // 漸化式の2n項までを列挙
        dp = vector<mint>(2 * n);
        dp[0] = 1;
        rep(i, n) {
            mint a = as[i];
            rep(j, (int)dp.size() - 1)
                dp[j + 1] += dp[j] * a;
        }

        // 行列の最小多項式で、漸化式の第c項を計算
        mint ans = linearlyRecurrentSequenceValue(c, dp, phi);
        rep(i, n)
            ans -= mint(as[i]) ^ c;
        cout << ans.get() << endl;
        */
    }
    /*
    vector<mint> dp(n * 2);
    dp[0] = 1;
    rep(i, n) {
        mint a = as[i];
        rep(j, (int)dp.size() - 1)
            dp[j + 1] += dp[j] * a;
    }
    cout << dp << endl;
    vector<mint> phi;
    computeMinimumPolynomialForLinearlyRecurrentSequence(dp, phi);
    mint ans = linearlyRecurrentSequenceValue(c, dp, phi);
    rep(i, n)
        ans -= mint(as[i]) ^ c;
    printf("%d\n", ans.get());
    */
    return 0;
}
