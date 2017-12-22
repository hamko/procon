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
#define ldout fixed << setprecision(40) 

#define EPS (double)1e-14
#define INF (ll)1e9
#define mo  (ll)(1e9+7)

// Range Min Point Assignの2次元segment tree
// 閉区間なので注意！！！！！
// 
// init(h, w)
//      b[h][w]の盤面を作成, 初期値はINF
// update(i, j, a) 
//      b[i][j] = a
// query(i1, j1, i2, j2) 
//      return min(b[i1:i2][j1:j2])
// 

// 二次元seg treeのデータを格納
const int MAX_N=1<<20;
using state = uint;
state dat[8*MAX_N];
int n;
int h,w;
int r,c,q;

void init(int h_,int w_){
	h=w=1;
	while(h<h_)h*=2;
	while(w<w_)w*=2;
	for(int i = 0; i < 8*MAX_N; i++)
		dat[i]=INF;
}
void update(int qminx,int qminy,int qmaxx,int qmaxy,int sminx,int sminy,int smaxx,int smaxy,state a,int k,bool isHor){
    // 重なり部分がない
    if(qmaxy<sminy||smaxy<qminy||qmaxx<sminx||smaxx<qminx)return;
    dat[k]=min(dat[k],a);
    // 今回の場所を更新したら終了
    if(qminx<=sminx&&smaxx<=qmaxx&&qminy<=sminy&&smaxy<=qmaxy)
        return;
    // 今回どちらで切るか
    bool nxt=!isHor;
    // xかyの幅が1になったら、片方のみ見ていく
    if(sminy==smaxy){
        update(qminx,qminy,qmaxx,qmaxy,sminx,sminy,(smaxx+sminx)/2,smaxy,a,2*k+1,nxt);
        update(qminx,qminy,qmaxx,qmaxy,(smaxx+sminx)/2+1,sminy,smaxx,smaxy,a,2*k+2,nxt);
        return;
    }
    else if(sminx==smaxx){
        update(qminx,qminy,qmaxx,qmaxy,sminx,sminy,smaxx,(smaxy+sminy)/2,a,2*k+1,nxt);
        update(qminx,qminy,qmaxx,qmaxy,sminx,(smaxy+sminy)/2+1,smaxx,smaxy,a,2*k+2,nxt);
        return;
    }
    if(isHor){
        update(qminx,qminy,qmaxx,qmaxy,sminx,sminy,smaxx,(smaxy+sminy)/2,a,2*k+1,nxt);
        update(qminx,qminy,qmaxx,qmaxy,sminx,(smaxy+sminy)/2+1,smaxx,smaxy,a,2*k+2,nxt);
    }
    else{
        update(qminx,qminy,qmaxx,qmaxy,sminx,sminy,(smaxx+sminx)/2,smaxy,a,2*k+1,nxt);
        update(qminx,qminy,qmaxx,qmaxy,(smaxx+sminx)/2+1,sminy,smaxx,smaxy,a,2*k+2,nxt);
    }
}
void update(int qminx,int qminy, state a){
    return update(qminx,qminy,qminx,qminy,0,0,w-1,h-1,a,0,true);
}

state query(int qminx,int qminy,int qmaxx,int qmaxy,int sminx,int sminy,int smaxx,int smaxy,int k,bool isHor){
    // 重なり部分がない
    if(qmaxy<sminy||smaxy<qminy||qmaxx<sminx||smaxx<qminx)return INF;
    // 完全に含まれる
    if(qminx<=sminx&&smaxx<=qmaxx&&qminy<=sminy&&smaxy<=qmaxy)return dat[k];
    // 現在xを分割しているか、yで分割しているかで場合わけ
    state vl,vr;
    // 今回どちらで切るか
    bool nxt=!isHor;
    // xかyの幅が1になったら、片方のみ見ていく
    if(sminy==smaxy){
        vl=query(qminx,qminy,qmaxx,qmaxy,sminx,sminy,(smaxx+sminx)/2,smaxy,2*k+1,nxt);
        vr=query(qminx,qminy,qmaxx,qmaxy,(smaxx+sminx)/2+1,sminy,smaxx,smaxy,2*k+2,nxt);
        return min(vl,vr);
    }
    else if(sminx==smaxx){
        vl=query(qminx,qminy,qmaxx,qmaxy,sminx,sminy,smaxx,(smaxy+sminy)/2,2*k+1,nxt);
        vr=query(qminx,qminy,qmaxx,qmaxy,sminx,(smaxy+sminy)/2+1,smaxx,smaxy,2*k+2,nxt);
        return min(vl,vr);
    }
    if(isHor){
        vl=query(qminx,qminy,qmaxx,qmaxy,sminx,sminy,smaxx,(smaxy+sminy)/2,2*k+1,nxt);
        if(sminy!=smaxy)
            vr=query(qminx,qminy,qmaxx,qmaxy,sminx,(smaxy+sminy)/2+1,smaxx,smaxy,2*k+2,nxt);
        else
            vr=INF;
    }
    else{
        vl=query(qminx,qminy,qmaxx,qmaxy,sminx,sminy,(smaxx+sminx)/2,smaxy,2*k+1,nxt);
        if(smaxx!=sminx)
            vr=query(qminx,qminy,qmaxx,qmaxy,(smaxx+sminx)/2+1,sminy,smaxx,smaxy,2*k+2,nxt);
        else vr=INF;
    }
    return min(vl,vr);
}
state query(int qminx,int qminy,int qmaxx,int qmaxy){
    return query(qminx,qminy,qmaxx,qmaxy,0,0,w-1,h-1,0,true);
}
void print(void) {
    cout << "########" << endl;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << query(i, j, i, j) << " ";
        }
        cout << endl;
    }
}

int main(void) {
    int h = 4, w = 2;
    init(h, w);
    print();
    update(0, 0, 1); update(0, 1, 2);
    update(1, 0, 2); update(1, 1, 3);
    print();
    cout << query(0, 0, 0, 0) << endl;
    cout << query(1, 1, 1, 1) << endl;
    cout << query(0, 0, 1, 1) << endl;
    cout << query(1, 1, 3, 1) << endl;


}
