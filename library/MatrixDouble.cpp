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

inline void input(int &v){ v=0;char c=0;int p=1; while(c<'0' || c>'9'){if(c=='-')p=-1;c=getchar();} while(c>='0' && c<='9'){v=(v<<3)+(v<<1)+c-'0';c=getchar();} v*=p; }
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
uint32_t randxor() { static uint32_t x=1+(uint32_t)random_seed,y=362436069,z=521288629,w=88675123; uint32_t t; t=(x^(x<<11));x=y;y=z;z=w; return( w=(w^(w>>19))^(t^(t>>8)) ); }
#define rand randxor
#define ldout fixed << setprecision(40) 

#define EPS (double)1e-14
#define INF (ll)1e18
#define mo  (ll)(1e9+7)


typedef double number;
const number eps = 1e-8;
using arr = vector<number>;
using matrix = vector<arr>;

ostream &operator<<(ostream &o, const arr &v) { 
    for (int i = 0; i < v.size(); i++) { cout << v[i] << " "; } cout << endl;
    return o; 
}
ostream &operator<<(ostream &o, const matrix &v) { 
    for (int i = 0; i < v.size(); i++) { cout << v[i]; } 
    return o; 
}

// O( n^2 )
matrix zero(int n) {
    matrix A(n, arr(n, 0));
    return A;
}
// O( n m )
matrix zero(int n, int m) {
    matrix A(n, arr(m, 0));
    return A;
}


// O( n^2 )
matrix identity(int n) {
    matrix A(n, arr(n, 0));
    for (int i = 0; i < n; ++i) A[i][i] = 1; // 積の単位元（和の単位元は？）
    return A;
}
// O( n^2 )
arr mul(const matrix &A, const arr &x) {
    arr y(A.size(), 0);
    for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < A[0].size(); ++j)
            y[i] += A[i][j] * x[j]; // 加群の積と和の演算子
    return y;
}
// O( n^3 )
matrix mul(const matrix &A, const matrix &B) {
    matrix C(A.size(), arr(B[0].size(), 0));
    for (int i = 0; i < C.size(); ++i)
        for (int j = 0; j < C[i].size(); ++j)
            for (int k = 0; k < A[i].size(); ++k)
                C[i][j] += A[i][k] * B[k][j]; // 加群の積と和の演算子
    return C;
}
// O( n^3 log e )
matrix pow(const matrix &A, int e) {
    return e == 0 ? identity(A.size())  :
        e % 2 == 0 ? pow(mul(A, A), e/2) : mul(A, pow(A, e-1));
}
// O( n )
number inner_product(const arr &a, const arr &b) {
    number ans = 0;
    for (int i = 0; i < a.size(); ++i)
        ans += a[i] * b[i];
    return ans;
}
// O( n^3 )
number det(matrix A) {
    const int n = A.size();
    number D = 1;
    for (int i = 0; i < n; ++i) {
        int pivot = i;
        for (int j = i+1; j < n; ++j)
            if (abs(A[j][i]) > abs(A[pivot][i])) pivot = j;
        swap(A[pivot], A[i]);
        D *= A[i][i] * (i != pivot ? -1 : 1);
        if (abs(A[i][i]) < eps) break;
        for(int j = i+1; j < n; ++j)
            for(int k = n-1; k >= i; --k)
                A[j][k] -= A[i][k] * A[j][i] / A[i][i];
    }
    return D;
}
// O(n)
number tr(const matrix &A) {
    number ans = 0;
    for (int i = 0; i < A.size(); ++i)
        ans += A[i][i];
    return ans;
}
// O( n^3 ).
int rank(matrix A) {
    const int n = A.size(), m = A[0].size();
    int r = 0;
    for (int i = 0; r < n && i < m; ++i) {
        int pivot = r;
        for (int j = r+1; j < n; ++j)
            if (abs(A[j][i]) > abs(A[pivot][i])) pivot = j;
        swap(A[pivot], A[r]);
        if (abs(A[r][i]) < eps) continue;
        for (int k = m-1; k >= i; --k)
            A[r][k] /= A[r][i];
        for(int j = r+1; j < n; ++j)
            for(int k = i; k < m; ++k)
                A[j][k] -= A[r][k] * A[j][i];
        ++r;
    }
    return r;
}

struct LUinfo {
    vector<number> value;
    vector<int> index;
};
// O( n^3 ), Gaussian forward elimination
LUinfo LU_decomposition(matrix A) {
    const int n = A.size();
    LUinfo data;
    for (int i = 0; i < n; ++i) {
        int pivot = i;
        for (int j = i+1; j < n; ++j)
            if (abs(A[j][i]) > abs(A[pivot][i])) pivot = j;
        swap(A[pivot], A[i]);
        data.index.push_back(pivot);
        // if A[i][i] == 0, LU decomposition failed.
        for(int j = i+1; j < n; ++j) {
            A[j][i] /= A[i][i];
            for(int k = i+1; k < n; ++k)
                A[j][k] -= A[i][k] * A[j][i];
            data.value.push_back(A[j][i]);
        }
    }
    for(int i = n-1; i >= 0; --i) {
        for(int j = i+1; j < n; ++j)
            data.value.push_back(A[i][j]);
        data.value.push_back(A[i][i]);
    }
    return data;
}
// O( n^2 ) Gaussian backward substitution
arr LU_backsubstitution(const LUinfo &data, arr b) {
    const int n = b.size();
    int k = 0;
    for (int i = 0; i < n; ++i){
        swap(b[data.index[i]], b[i]);
        for(int j = i+1; j < n; ++j)
            b[j] -= b[i] * data.value[k++];
    }
    for (int i = n-1; i >= 0; --i) {
        for (int j = i+1; j < n; ++j)
            b[i] -= b[j] * data.value[k++];
        b[i] /= data.value[k++];
    }
    return b;
}

// reduce Hessenberg form (inplace). 
// O ( n^3 )
void hessenberg(matrix &A) {
    const int n = A.size();
    for (int k = 1; k <= n-2; ++k) {
        arr u(n);
        for (int i = k; i < n; ++i) u[i] = A[i][k-1];

        number ss = 0;
        for (int i = k+1; i < n; ++i) ss += u[i] * u[i];
        if (abs(ss) <= 0.0) continue;
        number s = sqrt( ss + u[k]*u[k] );
        if (u[k] > 0.0) s = -s;

        u[k] -= s;
        number uu = sqrt( ss + u[k]*u[k] );
        for (int i = k; i < n; ++i) u[i] /= uu;

        arr f(n), g(n);
        for (int i = 0; i < n; ++i)
            for (int j = k; j < n; ++j)
                f[i] += A[i][j] * u[j],
                    g[i] += A[j][i] * u[j];
        number gamma = inner_product(u, g);
        for (int i = 0; i < n; ++i)
            f[i] -= gamma * u[i],
                g[i] -= gamma * u[i];

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                A[i][j] = A[i][j] - 2*u[i]*g[j] - 2*f[i]*u[j];
    }
}

// find all eigenvalues using Hessenberg-QR Method
// O( n^3 + M n^2 ) where M is the number of iterations.
vector<number> eigenvalues(matrix A) {
    const int n = A.size();
    hessenberg(A);
    vector<number> s(n), c(n);
    for (int m = n; m >= 2; ) {
        if (abs(A[m-1][m-2]) < eps) { --m; continue; }
        number shift = A[m-1][m-1];
        for (int i = 0; i < m; ++i) A[i][i] -= shift;
        for (int k = 0; k < m-1; ++k) {
            number a = A[k][k], b = A[k+1][k], r = sqrt(a*a + b*b);
            s[k] = r == 0.0 ? 0.0 : b/r,
                c[k] = r == 0.0 ? 0.0 : a/r;
            for (int j = k; j < m; ++j) {
                number x = A[k][j], y = A[k+1][j];
                A[ k ][j] =  c[k] * x + s[k] * y;
                A[k+1][j] = -s[k] * x + c[k] * y;
            }
        }
        for (int k = 0; k < m-1; ++k) {
            for (int i = 0; i <= k+1; ++i) {
                number x = A[i][k], y = A[i][k+1];
                A[i][ k ] =  c[k] * x + s[k] * y;
                A[i][k+1] = -s[k] * x + c[k] * y;
            }
        }
        for (int i = 0; i < m; ++i) A[i][i] += shift;
    }
    vector<number> lambda;
    for (int i = 0; i < n; ++i)
        lambda.push_back( A[i][i] );
    return lambda;
}

// find the corresponding eigenvector from the eigenvalue.
// O ( n^3 + M n^2 ) where M is the number of iterations.
arr eigenvector(matrix A, number lambda) {
    const int n = A.size();
    arr y(n); y[0] = 1;
    for (int i = 0; i < n; ++i) A[i][i] -= lambda;
    LUinfo data = LU_decomposition(A);
    number mu, v2, v2s;
    do {
        arr v = LU_backsubstitution(data, y); // A v = y 
        mu = inner_product(v, y);
        v2 = inner_product(v, v);
        v2s = sqrt(v2);
        for (int j = 0; j < n; ++j) y[j] = v[j] / v2s;
    } while (abs(1.0-mu*mu/v2) > eps);
    return y;
}

matrix operator*(const matrix& t1, const matrix& t2) {
    assert(t1[0].size() == t2.size());
    matrix ret = zero(t1.size(), t2[0].size()); 
    rep(i, t1.size()) {
        rep(j, t2[0].size()) {
            rep(k, t1.size()) {
                ret[i][j] += t1[i][k] * t2[k][j];
            }
        }
    }
    return ret;
}
arr operator*(const matrix& t1, const arr& t2) {
    assert(t1[0].size() == t2.size());
    arr ret(t1.size());
    rep(i, t1.size()) {
        rep(j, t2.size()) {
            ret[i] += t1[i][j] * t2[j];
        }
    }
    return ret;
}
arr operator+(const arr& t1, const arr& t2) {
    assert(t1.size() == t2.size());
    arr ret(t1.size());
    rep(i, t1.size()) {
        ret[i] = t1[i] + t2[i];
    }
    return ret;
}
matrix operator+(const matrix& t1, const matrix& t2) {
    assert(t1.size() == t2.size() && t1[0].size() == t2[0].size());
    matrix ret = zero(t1.size(), t1[0].size()); 
    rep(i, t1.size()) {
        rep(j, t1[0].size()) {
            ret[i][j] = t1[i][j] + t2[i][j];
        }
    }
    return ret;
}
arr operator-(const arr& t1, const arr& t2) {
    assert(t1.size() == t2.size());
    arr ret(t1.size());
    rep(i, t1.size()) {
        ret[i] = t1[i] - t2[i];
    }
    return ret;
}
matrix operator-(const matrix& t1, const matrix& t2) {
    assert(t1.size() == t2.size() && t1[0].size() == t2[0].size());
    matrix ret = zero(t1.size(), t1[0].size()); 
    rep(i, t1.size()) {
        rep(j, t1[0].size()) {
            ret[i][j] = t1[i][j] - t2[i][j];
        }
    }
    return ret;
}

matrix inverse(const matrix& t) {
    assert(t.size() == t[0].size());
    assert(t.size() == 2); // TODO
    matrix ret = zero(2, 2);
    ret[0][0] = t[1][1];
    ret[0][1] = -t[1][0];
    ret[1][0] = -t[0][1];
    ret[1][1] = t[0][0];

    return ret;
}
matrix transpose(const matrix& t) {
    matrix ret = zero(t[0].size(), t.size());
    rep(i, t.size()) rep(j, t[0].size()) {
        ret[j][i] = t[i][j];
    }
    return ret;
}


int main(void)
{
    vector<arr> m = {
        {2, 3,}, 
        {1, 2,}};
    vector<arr> a = {
        {2,}, 
        {1,}};
    cout << m << endl;
    cout << a << endl;
    cout <<  m * a  << endl;
    cout <<  m + m  << endl;
    cout <<  m - m  << endl;
    cout <<  a + a  << endl;
    cout <<  a - a  << endl;
    cout << inverse(m) << endl;
    cout << transpose(m) << endl;


    return 0;
}
