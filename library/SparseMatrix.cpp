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

template<typename Pair>
struct first_less {
  bool operator()(const Pair& x, const Pair& y) const {
    return x.first < y.first;
  }
};

namespace sparse {

template<typename T>
class matrix {
public:
  using key_type   = std::pair<int,int>;      // 位置(first,second) = (y,x)
  using value_type = std::pair<key_type,T>;   // 行列の[y][x]成分
  using container  = std::vector<value_type>;
  using compare    = first_less<value_type>;
private:
  container dictionary_; // 可変長配列による辞書
  typename container::size_type sorted_size_; // dictionary_の先頭からココまでソート済

public:

  matrix() : sorted_size_(0) {}

  void finalize() {
    // dictionary_を再ソートする
    if ( dictionary_.size() != sorted_size_ ) {
      // dictionary_.begin() から mid まで（前半）はソート済なので
      typename container::iterator mid = dictionary_.begin();
      std::advance(mid, sorted_size_);
      // mid から　dictionary_.end() まで（後半）をソートし
      std::sort(mid, dictionary_.end(), compare());
      // 前半と後半をマージする
      std::inplace_merge(dictionary_.begin(), mid, dictionary_.end(), compare());
      sorted_size_ = dictionary_.size();
    }
  }

  void clear() {
    // dictionary_を空にする
    sorted_size_ = 0; dictionary_.clear();
  }

  std::size_t size() const { return dictionary_.size(); }

  bool ok() const {
    // dictionary_にrow.colの重複がなければtrueを返す
    // ただし、dictionary_は（finalize()によって）ソート済でなければならない
    return std::adjacent_find(dictionary_.begin(), dictionary_.end()) == dictionary_.end();
  }

  typename container::const_iterator find_at(int row, int col) const {
    // row,col の組を dicrtionary_ から探す
    assert( dictionary_.size() == sorted_size_ );
    value_type tmp(std::make_pair(row,col), T());
    typename container::const_iterator iter = 
      std::lower_bound(dictionary_.cbegin(), dictionary_.cend(), tmp, compare());
    return ( iter != dictionary_.cend() && iter->first == tmp.first ) 
      ? iter : dictionary_.end();
  }

  void insert(int row, int col, const T& val) {
    // row, col, val の組を dictionary_の末尾に挿入する
    dictionary_.emplace_back(std::make_pair(row,col), val);
  }

  T* at(int row, int col, T* valp) const {
    // rpw,colの組がdictionary_にあるなら対応する値を(*valp)
    // にセットし、valpを返す(なければnullptrを返す)
    typename container::const_iterator iter = find_at(row, col);
    if ( iter == dictionary_.end() ) return nullptr;
    *valp = iter->second;
    return valp;
  }

  bool at(int row, int col, T& val) const {
    // rpw,colの組がdictionary_にあるなら対応する値をval
    // にセットし、trueを返す（なければfalseを返す）
    return at(row, col, &val) != nullptr;
  }

  bool replace_at(int row, int col, const T& val) {
    // rpw,colの組がdictionary_にあるなら対応する値をval
    // に変更し、を返す（なければfalseを返す）
    typename container::iterator iter = find_at(row, col);
    bool found = iter != dictionary_.end();
    if ( found ) {
      iter->second = val;
    }
    return found;
  }

  template<typename Function>
  void enumerate(Function fn) const {
    // dictionary_内の各 row,col,val を引数としてfnを呼ぶ
    for ( const value_type& entry : dictionary_ ) {
      fn(entry.first.first, entry.first.second, entry.second);
    }
  }

  /*
  template <typename T>  ostream &operator<<(ostream &o, const matrix<T> &A) {
      A.enumerate([](int row, int col, float val) {
              o << '[' << row << ',' << col << "] " 
              << val << std::endl;}); 
      return o;
  }
  */


};

// k : row
// m : col
// l : ??
template<typename T>
matrix<T> multiply(const matrix<T>& A, const matrix<T>& B, int k, int l, int m) {
  matrix<T> out;
  // out[row, col] = Σ(A[row,i] * B[i,col]
  for ( int row = 0; row < k; ++row ) {
    for ( int col = 0; col < m; ++col ) {
      T sum = T(0);
      T aval;
      T bval;
      for ( int i = 0; i < l; ++i ) {
        aval = T(0); A.at(row, i, aval);
        bval = T(0); B.at(i, col, bval);
        sum += aval * bval;
      }
      if ( sum != T(0) ) {
        out.insert(row, col, sum);
      }
    }
  }
  out.finalize();
  return out;
}

template<typename T>
void fill_diagonal(matrix<T>& mtx, int n, const T& val) {
  // (0,0), (1,1) ... (n-1,n-1) を val で埋める
  for ( int i = 0; i < n; ++i ) {
    mtx.insert(i, i, val);
  }
  mtx.finalize();
}


}

// 素行列による交差しない5歩での閉路の数え上げ
int main(void) {
    using namespace sparse;
    matrix<ll> tmp;
    cin.tie(0); ios::sync_with_stdio(false);
    ll n, m; cin >> n >> m;
    matrix<ll> A;
    fill_diagonal(A, n, 1ll); // nxnの単位行列

    matrix<ll> B; // 隣接行列
    vll dig(n);
    rep(i, m) {
        ll u, v; cin >> u >> v; u--; v--;
        dig[u]++; dig[v]++; 
        B.insert(u, v, 1ll);
        B.insert(v, u, 1ll);
        B.finalize();
    }
    cout << dig << endl;
    tmp = A; rep(i, n) { rep(j, n) { ll x = 0; tmp.at(i, j, x); cout << x << " "; } cout << endl; }
    tmp = B; rep(i, n) { rep(j, n) { ll x = 0; tmp.at(i, j, x); cout << x << " "; } cout << endl; }

    ll ret = 0;

    A = multiply(A, B, n, n, n);
    A = multiply(A, B, n, n, n);
    A = multiply(A, B, n, n, n);
    rep(i, n) {
        ll x = 0; A.at(i, i, x);
        ret += x * (dig[i] - 1);
    }
    ret *= -5;

    A = multiply(A, B, n, n, n);
    A = multiply(A, B, n, n, n);
    rep(i, n) {
        ll x = 0; A.at(i, i, x);
        ret += x;
    }

    ret /= 10;
    cout << ret << endl;
    cout << (ret ? "YES" : "NO") << endl;

    return 0;
}
