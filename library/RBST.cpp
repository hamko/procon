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


uint64_t xor128(void) { 
  static uint64_t x = 123456789;
  static uint64_t y = 362436069;
  static uint64_t z = 521288629;
  static uint64_t w = 88675123; 
  uint64_t t;
   
  t = x ^ (x << 11);
  x = y; y = z; z = w;
  return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}
  
struct Node {
  ll Value;
  ll SubTreeSize;
  Node *Lch, *Rch;
  ll RMQ;
  
  Node(ll V):Value(V), SubTreeSize(1), RMQ(V) {
    Lch = (Node *)NULL;
    Rch = (Node *)NULL;
  };
};
inline ll Count(Node *t)
{
  if(t == (Node *)NULL) return(0);
  else return(t -> SubTreeSize);
}
inline ll Sum(Node *t)
{
  if(t == (Node *)NULL) return(INF);
  else return(t -> RMQ);
}
  
inline Node *Update(Node *t)
{
  t -> SubTreeSize = Count(t -> Lch) + Count(t -> Rch) + 1;
  t -> RMQ = min(Sum(t -> Lch), min(Sum(t -> Rch), t -> Value));
  return(t);
}
  
// 機能 1ノードの木を返す
// 引数 value: ノードの値
// 戻り値   木の根
inline Node *MakeRoot(ll value)
{
  return(new Node(value));
}
  
// 機能   位置posに新しいノードを挿入(区間反転とかそういうときに使う)
//引数  root: 木の根
//pos: 挿入位置
//value: 挿入ノードの値
//戻り値    新しい木の根
Node *Merge(Node *l, Node *r)
{
  if(l == (Node *)NULL) return(r);
  if(r == (Node *)NULL) return(l);
  ll Left  = l -> SubTreeSize;
  ll Right = r -> SubTreeSize;
  if(xor128() % (Left + Right) < Left) {
    l -> Rch = Merge(l -> Rch, r);
    return(Update(l));
  } else {
    r -> Lch = Merge(l, r -> Lch);
    return(Update(r));
  }
}
    
// 機能 位置posに新しいノードを挿入(区間反転とかそういうときに使う)
// 引数 root: 木の根
// pos: 挿入位置
// value: 挿入ノードの値
// 戻り値   新しい木の根
pair< Node*, Node* > Split(Node *t, ll k) // [0, k), [k, n)
{
  if(t == (Node *)NULL) return(make_pair((Node *)NULL, (Node *)NULL));
  if(k <= Count(t -> Lch)) {
    pair< Node *, Node *> s = Split(t -> Lch, k);
    t -> Lch = s.second;
    return(make_pair(s.first, Update(t)));
  } else {
    pair< Node *, Node *> s = Split(t -> Rch, k - Count(t -> Lch) - 1);
    t -> Rch = s.first;
    return(make_pair(Update(t), s.second));
  }
}
  
// 機能 位置posに新しいノードを挿入(区間反転とかそういうときに使う)
// 引数 root: 木の根
// pos: 挿入位置
// value: 挿入ノードの値
// 戻り値   新しい木の根
//
// a 
// -> a[0, root) value a[root, n)
Node *Insert(Node *root, ll pos, ll value)
{
  Node *p = MakeRoot(value);
  pair< Node *, Node *> s = Split(root, pos);
  return(Merge(Merge(s.first, p), s.second));
}
 
// 機能 pos番目のノードを削除
// 引数 root: 木の根
// pos: 削除位置
// 戻り値   新しい木の根
//
// a
// -> a[0, pos) a[pos+1, n)
Node *Erase(Node *root, ll pos)
{
  pair< Node *, Node *> s = Split(root, pos);
  pair< Node *, Node *> t = Split(s.second, 1);
  delete t.first;
  return(Merge(s.first, t.second));
}
 
// 機能 value 以上の最左位置を返す
// 引数 root: 木の根
// value: 検索値
// 戻り値   位置
//
// 列が単調になっている必要がある
ll Lower_Bound(Node *root, ll Value)
{
  if(root == (Node *)NULL) return(0);
  if(Value < root -> Value) return(Lower_Bound(root -> Lch, Value));
  return(Lower_Bound(root -> Rch, Value) + Count(root -> Lch) + 1);
}

// 機能 木に値 value のノードを挿入(setsetみたいに使いたいときに使う)
// 引数 root: 木の根
// value: 挿入値
// 戻り値   新しい木の根
//
// これのみを使っていると、列が単調になる
Node *Insert(Node *root, ll Value)
{
  return(Insert(root, Lower_Bound(root, Value), Value));
} 
 
void Dump(Node *root)
{
  if(root == (Node *)NULL) return;
  cout << "(";
  Dump(root -> Lch);
  cout << "" << root -> Value << "";
  Dump(root -> Rch);
  cout << ")";
}

int main(void) {
    Node* a[10];

    cout << "########" << endl;
    rep(i, 10) a[i] = MakeRoot(i);
    rep(i, 10) Dump(a[i]), cout << endl;

    cout << "########" << endl;
    repi(i, 1, 10) 
        a[0] = Merge(a[0], a[i]);
    rep(i, 10) Dump(a[i]), cout << endl;

    cout << "########" << endl;
    auto x = Split(a[0], 3);
    Dump(x.fi), cout << endl;
    Dump(x.se), cout << endl;
    Dump(a[0]), cout << endl;

    return 0;
}
