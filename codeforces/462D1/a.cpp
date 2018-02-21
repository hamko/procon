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

#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
const int MX = 1415;
int t;
int n , q;
int inp[N];
int cmp[N];
int mx;
int arr[N];
int mp[N];
int when[N];
vector < pair < int , int > > v[N];
int ans[N];
int bit[MX][MX];
int tmp[MX];
int glo[MX];
void update(int idx){
    int sz = tmp[0];
    while(idx){
        for(int i = 1 ; i <= sz ; ++i){
            bit[idx][i] = min(bit[idx][i] , tmp[i]);
        }
        bit[idx][0] = max(bit[idx][0] , sz);
        idx -= idx & -idx;
    }
    for(int i = 1 ; i <= sz ; ++i){
        glo[i] = min(glo[i] , tmp[i]);
    }
    glo[0] = max(glo[0] , sz);
}
void query(int i , int idx){
    tmp[0] = 1;
    tmp[1] = i;
    for(int i = 2 ; i <= mx ; ++i){
        tmp[i] = n + 1;
    }
    while(idx <= mx){
        int sz = bit[idx][0];
        tmp[0] = max(tmp[0] , sz + 1);
        for(int j = 1 ; j <= sz ; ++j){
            tmp[j + 1] = min(tmp[j + 1] , bit[idx][j]);
        }
        idx += idx & -idx;
    }
}
int bit2[MX];
void update2(int idx , int val){
    while(idx){
        bit2[idx] = max(bit2[idx] , val);
        idx -= idx & -idx;
    }
}
int query2(int idx){
    int res = 0;
    while(idx <= mx){
        res = max(res , bit2[idx]);
        idx += idx & -idx;
    }
    return res;
}
void brute(){
    for(int i = 1 ; i <= q ; ++i){
        int l , r;
        scanf("%d %d" , &l , &r);
        for(int i = 1 ; i <= mx ; ++i){
            bit2[i] = 0;
        }
        for(int i = r ; i >= l ; --i){
            update2(inp[i] , query2(inp[i] + 1) + 1);
        }
        printf("%d\n" , query2(1));
    }
}
int main(){
    t=1;
//    scanf("%d" , &t);
    for(int tc = 1 ; tc <= t ; ++tc){
        scanf("%d" , &n);
        q = n*(n+1ll)/2;
        mx = 0;
        for(int i = 1 ; i <= n ; ++i){
            scanf("%d" , inp + i);
            if(when[inp[i]] != tc){
                when[inp[i]] = tc;
                arr[++mx] = inp[i];
            }
        }
        sort(arr + 1 , arr + 1 + mx);
        for(int i = 1 ; i <= mx ; ++i){
            cmp[arr[i]] = i;
        }
        for(int i = 1 ; i <= n ; ++i){
            inp[i] = cmp[inp[i]];
        }
        /*
        if(n <= 1000 && q <= 1000){
            brute();
            continue;
        }
        */
        int _n = 0;
        inp[0] = -1;
        for(int i = 1 ; i <= n ; ++i){
            if(inp[i] != inp[i - 1]){
                arr[++_n] = inp[i];
            }
            mp[i] = _n;
        }
        n = _n;

        ll i = 0;
        rep(a, 1, n+1) repi(b, a, n+1) { 
            ans[i] = 0;
            a = mp[a];
            b = mp[b];
            v[a].emplace_back(make_pair(b , i));
            i++;
        }
        for(int i = 1 ; i <= mx ; ++i){
            bit[i][0] = 0;
            for(int j = 1 ; j <= mx ; ++j){
                bit[i][j] = n + 1;
            }
        }
        glo[0] = 0;
        for(int i = 1 ; i <= mx ; ++i){
            glo[i] = n + 1;
        }
        for(int i = n ; i >= 1 ; --i){
            query(i , arr[i] + 1);
            update(arr[i]);
            for(auto it : v[i]){
                int l = 1;
                int r = glo[0];
                while(l < r){
                    int mid = l + r + 1 >> 1;
                    if(glo[mid] <= it.first){
                        l = mid;
                    }
                    else{
                        r = mid - 1;
                    }
                }
                ans[it.second] = l;
            }
        }
        rep(a, n) repi(b, a, n) { 
            i++;
            printf("%d\n" , ans[i]);
        }

    }
} 
