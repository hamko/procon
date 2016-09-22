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
static const long long INF = 1e18;

static const long long mo = 1e9+7;
class Mod {
    public:
        int num;
        Mod() : Mod(0) {}
        Mod(long long int n) : num(n) { }
        Mod(const string &s){ long long int tmp = 0; for(auto &c:s) tmp = (c-'0'+tmp*10) % mo; num = tmp; }
        Mod(int n) : Mod(static_cast<long long int>(n)) {}
        operator int() { return num; }
};
istream &operator>>(istream &is, Mod &x) { long long int n; is >> n; x = n; return is; }
ostream &operator<<(ostream &o, const Mod &x) { o << x.num; return o; }
Mod operator+(const Mod a, const Mod b) { return Mod((a.num + b.num) % mo); }
Mod operator+(const long long int a, const Mod b) { return Mod(a) + b; }
Mod operator+(const Mod a, const long long int b) { return b + a; }
Mod operator++(Mod &a) { return a + Mod(1); }
Mod operator-(const Mod a, const Mod b) { return Mod((mo + a.num - b.num) % mo); }
Mod operator-(const long long int a, const Mod b) { return Mod(a) - b; }
Mod operator--(Mod &a) { return a - Mod(1); }
Mod operator*(const Mod a, const Mod b) { return Mod(((long long)a.num * b.num) % mo); }
Mod operator*(const long long int a, const Mod b) { return Mod(a)*b; }
Mod operator*(const Mod a, const long long int b) { return Mod(b)*a; }
Mod operator*(const Mod a, const int b) { return Mod(b)*a; }
Mod operator+=(Mod &a, const Mod b) { return a = a + b; }
Mod operator+=(long long int &a, const Mod b) { return a = a + b; }
Mod operator-=(Mod &a, const Mod b) { return a = a - b; }
Mod operator-=(long long int &a, const Mod b) { return a = a - b; }
Mod operator*=(Mod &a, const Mod b) { return a = a * b; }
Mod operator*=(long long int &a, const Mod b) { return a = a * b; }
Mod operator*=(Mod& a, const long long int &b) { return a = a * b; }
Mod factorial(const long long n) {
    if (n < 0) return 0;
    Mod ret = 1;
    for (int i = 1; i <= n; i++) {
        ret *= i;
    }
    return ret;
}
Mod operator^(const Mod a, const long long n) {
    if (n == 0) return Mod(1);
    Mod res = (a * a) ^ (n / 2);
    if (n % 2) res = res * a;
    return res;
}
Mod modpowsum(const Mod a, const long long b) {
    if (b == 0) return 0;
    if (b % 2 == 1) return modpowsum(a, b - 1) * a + Mod(1);
    Mod result = modpowsum(a, b / 2);
    return result * (a ^ (b / 2)) + result;
}


/*************************************/
// 以下、modは素数でなくてはならない！
/*************************************/
Mod inv(const Mod a) { return a ^ (mo - 2); }
Mod operator/(const Mod a, const Mod b) { assert(b.num != 0); return a * inv(b); }
Mod operator/(const long long int a, const Mod b) { assert(b.num != 0); return Mod(a) * inv(b); }
Mod operator/=(Mod &a, const Mod b) { assert(b.num != 0); return a = a * inv(b); }

// n!と1/n!のテーブルを作る。
// nCrを高速に計算するためのもの。
//
// assertでnを超えていないかをきちんとテストすること。
//
// O(n log mo)
vector<Mod> fact, rfact;
void constructFactorial(const long long n) {
    fact.resize(n);
    rfact.resize(n);
    fact[0] = rfact[0] = 1;
    for (int i = 1; i < n; i++) {
        fact[i] = fact[i-1] * i;
        rfact[i] = Mod(1) / fact[i];
    }
}

// O(1)
Mod nCr(const long long n, const long long r) {
//    assert(n < (long long)fact.size());
    if (n < 0 || r < 0) return 0;
    return fact[n] * rfact[r] * rfact[n-r];
}

// O(k log mo) 
Mod nCrWithoutConstruction(const long long n, const long long k) {
    if (n < 0) return 0;
    if (k < 0) return 0;
    Mod ret = 1;
    for (int i = 0; i < k; i++) {
        ret *= n - (Mod)i;
        ret /= Mod(i+1);
    }
    return ret;
}
// n*mの盤面を左下から右上に行く場合の数
// O(1)
Mod nBm(const long long n, const long long m) {
    if (n < 0 || m < 0) return 0;
    return nCr(n + m, n);
}

/*************************************/
// GF(p)の行列演算
/*************************************/
using number = Mod;
using arr = vector<number>;
using matrix = vector<vector<Mod>>;

ostream &operator<<(ostream &o, const arr &v) { rep(i, v.size()) cout << v[i] << (i == v.size() - 1 ? "" : " "); return o; }
ostream &operator<<(ostream &o, const matrix &v) { rep(i, v.size()) cout << v[i]; return o; }

matrix zero(int n) { return matrix(n, arr(n, 0)); } // O(n^2)
matrix identity(int n) { matrix A(n, arr(n, 0)); rep(i, n) A[i][i] = 1; return A; } // O(n^2)
// O(n^2)
arr mul(const matrix &A, const arr &x) { 
    arr y(A.size(), 0); 
    rep(i, A.size()) rep(j, A[0].size()) y[i] += A[i][j] * x[j]; 
    return y; 
} 
// O(n^3)
matrix mul(const matrix &A, const matrix &B) {
    matrix C(A.size(), arr(B[0].size(), 0));
    rep(i, C.size())
        rep(j, C[i].size())
        rep(k, A[i].size())
        C[i][j] += A[i][k] * B[k][j];
    return C;
}
// O(n^2)
matrix plu(const matrix &A, const matrix &B) {
    matrix C(A.size(), arr(B[0].size(), 0));
    rep(i, C.size())
        rep(j, C[i].size())
            C[i][j] = A[i][j] + B[i][j];
    return C;
}
// O(n^2)
matrix minu(const matrix &A, const matrix &B) {
    matrix C(A.size(), arr(B[0].size(), 0));
    rep(i, C.size())
        rep(j, C[i].size())
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

// O(n^2)
arr plu(const arr &A, const arr &B) {
    arr C(A.size());
    rep(i, A.size())
        C[i] += A[i] + B[i];
    return C;
}


struct node {
//    matrix A = identity(3), B = identity(2), S = matrix(2, arr(3, 0));
    matrix A, B, S;
};
node identity_node = {identity(3), identity(2), matrix(2, arr(3, 0))};

class SegmentTree {
public:
    // datのデータ構造
    // 0123456789ABCDEF // インターフェースの添字
    // ################
    // 1--------------- // datの添字, 0は使わない！！
    // 2-------3-------
    // 4---5---6---7---
    // 8-9-A-B-C-D-E-F-
    // GHIJKLMNOPQRSTUV

    // SegmentTree[i] = dat[i+n] = dat[i+n]

    // v<<1, v<<1|1は子どもたちを表している
    vector<node> dat; 
    int n = 1; // ノード数は2*n-1
    int bits = 0; // n == 1 << bits
    const size_t size_; // 確保しているサイズではなく、コンストラクタに与えたサイズ
    int ql, qr;
    SegmentTree(int n_) : size_(n_) {
        while(n < n_) { n <<= 1; bits++; }
        dat.resize(n+n);
    }
    // 範囲クエリ
    // 範囲番号nの区間[nl, nr)にop(x)を演算結果を返す
    node query(int n, int nl, int nr){
        // この関数は、[ql, qr)より上のノードとその子の全てにHITする
        if(nr <= ql || qr <= nl) return identity_node; // TODO 単位元を前提していて良くない！！！本来nothingを返して、何もしないのが良い
        if(ql <= nl && nr <= qr) return dat[n]; // 一回の区間更新に付き最大3回、した区間が小さい順にHitする。
        int m = (nl + nr) / 2;
        node ret; node x = query(n<<1, nl, m); node y = query(n<<1|1, m, nr);
        merge(ret, x, y);
        return ret;
    }
    // [l, r)の演算結果を出力
    node query(int l, int r){
        ql = l; qr = r;
        return query(1, 0, n);
    }
    // node_idに相当する区間[l, r)を返す。
    //
    // 0 < node_id < n
    pair<int, int> get_range(int node_id){
        int d = 32-__builtin_clz(node_id);
        node_id &= ~(1 << (d - 1));
        int broad = 1 << (bits - d + 1);
        return pair<int, int>(node_id * broad, (node_id + 1) * broad);
    }

    // 直接node_idのノードにxを代入する。
    //
    // 主に初期化に使う。
    void set(int node_id, node& x){
        dat[node_id] = x;
    }
    // 直接node_idのノードの値を取得する。
    node get(int node_id){
        return dat[node_id];
    }

    /***************************************/
    // ここから下をいじる
    /***************************************/
    // 初期化
    // より高速な初期化方法があるなら、これを使わずに自分で実装する
    // 
    // ノード数がthis->n * 2であることに非常に注意 
    void init(node& x){
        for (int i = 1; i < this->n*2; i++) {
            set(i, x);
        }
    }
    // マージ則
    // 
    // ret = f(x, y)
    // fは結合演算, retはすでに確保済み
    void merge(node& ret, node& x, node& y){
        ret.A = mul(y.A, x.A);
        ret.B = mul(x.B, y.B);
        ret.S = plu(x.S, mul(x.B, mul(y.S, x.A)));
    }
    // 点更新
    void updateA(int v, const matrix &A){
        v += n;
        // 実装場所はじめ
        dat[v].A = A;
        // 実装場所おわり
//        while (v){ v = v >> 1; merge(dat[v], dat[v<<1], dat[v<<1|1]); }
        while (v = v >> 1){ merge(dat[v], dat[v<<1], dat[v<<1|1]); }
    }
    // 点更新
    void updateB(int v, const matrix &B){
        v += n;
        // 実装場所はじめ
        dat[v].B = B;
        // 実装場所おわり
//        while (v){ v = v >> 1; merge(dat[v], dat[v<<1], dat[v<<1|1]); }
        while (v = v >> 1){ merge(dat[v], dat[v<<1], dat[v<<1|1]); }
    }
    void print(void){
        for (int i = 1; i < this->n; i++) {
            cout << i << " " << dat[i].A.size() << " " << dat[i].A[0].size() << endl;
            cout << i << " " << dat[i].B.size() << " " << dat[i].B[0].size() << endl;
            cout << i << " " << dat[i].S.size() << " " << dat[i].S[0].size() << endl;
        }
    }

};

int main() {
    ll n; cin >> n;
    SegmentTree s(n+1);

    vector<matrix> S_sum(s.n+1, matrix(2, arr(3, 0)));
    rep(i, s.n) {
        rep(j, 6) {
            S_sum[i+1][j/3][j%3] = 6 * i + j;
        }
    }
    rep(i, s.n) {
        S_sum[i+1] = plu(S_sum[i+1], S_sum[i]);
    }

    for (int i = 1; i < s.n*2; i++) {
        node x;
        x.A = identity(3);
        x.B = identity(2);
        auto range = s.get_range(i);
        x.S = minu(S_sum[range.se], S_sum[range.fi]);
        s.set(i, x);
    }

    arr a0(3), bn(2);
    rep(i, 3) cin >> a0[i];
    rep(i, 2) cin >> bn[i];

    ll q; cin >> q;
    rep(_, q) {
        string type; cin >> type;
        ll index; cin >> index;
        if (type == "a") {
            matrix A(3, arr(3));
            rep(i, 9) cin >> A[i/3][i%3];
            s.updateA(index, A);
        } else if (type == "b") {
            matrix B(2, arr(2));
            rep(i, 4) cin >> B[i/2][i%2];
            s.updateB(index, B);
        } else if (type == "ga") {
            cout << mul(s.query(0, index).A, a0) << endl;
        } else {
            auto A = s.query(0, index+1).A;
            auto tmp = s.query(index+1, n+1);
            auto B = tmp.B;
            auto S = tmp.S;
            cout << plu(
                    mul(B, bn),
                    mul(S, mul(A, a0))
                    ) << endl;
        } 
    }
    return 0;
}
