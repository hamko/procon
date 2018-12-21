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
ll ugauss(ll a, ll b) { if (!a) return 0; if (a>0^b>0) return a/b; else return (a+(a>0?-1:1))/b+1; }
ll lgauss(ll a, ll b) { if (!a) return 0; if (a>0^b>0) return (a+(a>0?-1:1))/b-1; else return a/b; }
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
template <typename T>  ostream &operator<<(ostream &o, const multiset<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const unordered_set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U, typename V>  ostream &operator<<(ostream &o, const unordered_map<T, U, V> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it; o << "]";  return o; }
vector<int> range(const int x, const int y) { vector<int> v(y - x + 1); iota(v.begin(), v.end(), x); return v; }
template <typename T> istream& operator>>(istream& i, vector<T>& o) { rep(j, o.size()) i >> o[j]; return i;}
template <typename T, typename S, typename U> ostream &operator<<(ostream &o, const priority_queue<T, S, U> &v) { auto tmp = v; while (tmp.size()) { auto x = tmp.top(); tmp.pop(); o << x << " ";} return o; }
template <typename T> ostream &operator<<(ostream &o, const queue<T> &v) { auto tmp = v; while (tmp.size()) { auto x = tmp.front(); tmp.pop(); o << x << " ";} return o; }
template <typename T> ostream &operator<<(ostream &o, const stack<T> &v) { auto tmp = v; while (tmp.size()) { auto x = tmp.top(); tmp.pop(); o << x << " ";} return o; }
template <typename T> unordered_map<T, ll> counter(vector<T> vec){unordered_map<T, ll> ret; for (auto&& x : vec) ret[x]++; return ret;};
void vizGraph(vvll& g, int mode = 0, string filename = "out.png") { ofstream ofs("./out.dot"); ofs << "digraph graph_name {" << endl; set<P> memo; rep(i, g.size())  rep(j, g[i].size()) { if (mode && (memo.count(P(i, g[i][j])) || memo.count(P(g[i][j], i)))) continue; memo.insert(P(i, g[i][j])); ofs << "    " << i << " -> " << g[i][j] << (mode ? " [arrowhead = none]" : "")<< endl;  } ofs << "}" << endl; ofs.close(); system(((string)"dot -T png out.dot >" + filename).c_str()); }
struct timeval start; double sec() { struct timeval tv; gettimeofday(&tv, NULL); return (tv.tv_sec - start.tv_sec) + (tv.tv_usec - start.tv_usec) * 1e-6; }
size_t random_seed; struct init_{init_(){ ios::sync_with_stdio(false); cin.tie(0); gettimeofday(&start, NULL); struct timeval myTime; struct tm *time_st; gettimeofday(&myTime, NULL); time_st = localtime(&myTime.tv_sec); srand(myTime.tv_usec); random_seed = RAND_MAX / 2 + rand() / 2; }} init__;
#define ldout fixed << setprecision(40) 

#define EPS (double)1e-14
#define INF (ll)1e18
#define mo  (ll)(1e9+7)


#include <vector>
#include <cassert>
#include <set>
#include <queue>
#include <functional>
#include <algorithm>

struct edge {
  int to;
  int label;
};


::std::vector<::std::pair<int, int>> gabow_edmonds(const ::std::vector<::std::vector<int>>& gra){
  // E0 - 初期化
  int N = gra.size();
  ::std::vector<::std::vector<edge>> g(N + 1);
  ::std::vector<::std::pair<int, int>> edges;
  {
    int cnt = N + 1;
    for(int i = 0;i < N;i++){
      for(auto to : gra[i]){
        if(i < to){
          g[to + 1].push_back({i + 1, cnt});
          g[i + 1].push_back({to + 1, cnt++});
          edges.push_back({i + 1, to + 1});
        }
      }
    }
  }
  ::std::vector<int> mate(N + 1 , 0);
  ::std::vector<int> label(N + 1 , -1);
  ::std::vector<int> first(N + 1 , 0);
  ::std::queue<int> que;

  // firstの遅延評価
  ::std::function<int(int)> eval_first = [&](int x){
    if(label[first[x]] < 0) return first[x];
    first[x] = eval_first(first[x]);
    return first[x];
  };

  // サブルーチンR
  ::std::function<void(int, int)> rematch = [&](int v, int w){
    // R1
    int t = mate[v];
    mate[v] = w;
    if(mate[t] != v) return;
    // R2
    if(label[v] <= N){
      mate[t] = label[v];
      rematch(label[v] , t);
    }
    // R3
    else{
      int x = edges[label[v] - N - 1].first;
      int y = edges[label[v] - N - 1].second;
      rematch(x , y);
      rematch(y , x);
    }
  };

  ::std::function<void(int, int, int)> assignLabel = [&](int x, int y, int num){
    // L0
    int r = eval_first(x);
    int s = eval_first(y);
    int join = 0;
    if(r == s) return;
    // -numがフラグ
    label[r] = -num;
    label[s] = -num;
    while(true){
      // L1
      if(s != 0) ::std::swap(r , s);
      // L2
      r = eval_first(label[mate[r]]);
      if(label[r] == -num){
        join = r;
        break;
      }
      label[r] = -num;
    }
    // L3
    int v = first[x];
    // L4
    while(v != join){
      que.push(v);
      label[v] = num;
      first[v] = join;
      v = first[label[mate[v]]];
    }
    // L3
    v = first[y];
    // L4
    while(v != join){
      que.push(v);
      label[v] = num;
      first[v] = join;
      v = first[label[mate[v]]];
    }
    // L5は遅延評価しているため不要
    // L6
    return;
  };

  ::std::function<bool(int)> augment_check = [&](int u){
    // E1 後半
    first[u] = 0;
    label[u] = 0;
    que.push(u);
    while(!que.empty()){
      // E2 
      int x = que.front();
      que.pop();
      for(auto e : g[x]){
        int y = e.to;
        // E3
        if(mate[y] == 0 && y != u){
          mate[y] = x;
          rematch(x , y);
          return true;
        }
        // E4
        else if(label[y] >= 0){
          assignLabel(x , y , e.label);
        }
        // E5
        else if(label[mate[y]] < 0){
          label[mate[y]] = x;
          first[mate[y]] = y;
          que.push(mate[y]);
        }
        // E6
      }
    }
    return false;
  };

  for(int i = 1;i <= N;i++){
    // E1
    que = ::std::queue<int>();
    if(mate[i] != 0) continue;
    if(augment_check(i)){
      // E7
      ::std::fill(label.begin(), label.end(), -1);
    }
  }

  ::std::vector<::std::pair<int, int>> ans;
  for(int i = 1;i <= N;i++){
    if(i < mate[i]){
      ans.push_back({i , mate[i]});
    }
  }
  return ans;
}

int main(void) {
    ll n; cin >> n;
    vll a(n); cin >> a;
    sort(all(a));
    reverse(all(a));
    ll ret = 0;

    vll p2 = {};
    ll tmp = 1;
    rep(i, 40) {
        p2.pb(tmp);
        tmp *= 2ll;
    }
    reverse(all(p2));

    /*
    vector<vector<int>> g(n);
    rep(i, n) repi(j, i+1, n) {
        for (auto p : p2) {
            if (a[i] + a[j] == p) {
                g[i].pb(j);
                g[j].pb(i);
            }
        }
    }
    cout << gabow_edmonds(g) << endl;
    ll brutal = gabow_edmonds(g).size();
    */

    map<ll, set<ll>> memo;
    rep(i, n) {
        memo[a[i]].insert(i);
    }
    vll flag(n);
    multiset<ll> s;
    rep(i,n) if (!flag[i]) {
        s.insert(a[i]);
    }
//    cout << ret << endl;
//    cout << a << endl;
    rep(i, n) if (!flag[i]) {
//        cout << flag << endl;
//        cout << s << endl;
//        cout << i  << " " << a[i] << " " << *s.lower_bound(a[i]) << endl;
        s.erase(s.lower_bound(a[i]));
        flag[i] = 1;
        memo[a[i]].erase(i);
        for (auto p : p2) if (p-a[i] <= a[i]) {
//            cout << a[i] << " " << p << endl;
            if (s.count(p - a[i])) {
//                cout << p-a[i] << "#FOUND"<<endl;
                s.erase(s.lower_bound(p - a[i]));
                ll id = *(memo[p-a[i]].begin());
                flag[id] = 1;
                memo[p-a[i]].erase(id);
//                cout << a[i] << " " << p-a[i]  << "#Fount " << endl;
                ret++;
                break;
            }
        }
    }

    cout << ret << endl;
    /*
    if (ret != brutal) {
        cout << "HIT!"<<endl;
        cout << n << endl;
        cout << a << endl;
        cout << brutal << " " << ret << endl;
    }
    */
    return 0;
}
