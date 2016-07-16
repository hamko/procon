#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)

#ifdef _WIN32
#define scanfll(x) scanf("%I64d", x)
#define printfll(x) printf("%I64d", x)
#else
#define scanfll(x) scanf("%lld", x)
#define printfll(x) printf("%lld", x)
#endif
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


const int MAX = 100010;
int N, M;
typedef pair<int,int> pii;

struct union_find{
    vector<ll> rnk, par, w;

    union_find(int n){ rnk.resize(n); par.resize(n); w.resize(n); rep(i,n) rnk[i] = 1, par[i] = i, w[i] = 0;}

    pii weight(int x){
        if(x == par[x]) return pii(x,0);
        pii ret = weight(par[x]);
        cout << x << " " << ret.second << "#lazy" << endl;
        return pii((par[x]=ret.first), (w[x]+=ret.second));
    }
    int find(int x){ 
        return weight(x).first;
    }
    void unite(int a, int b, int k){
        cout << "----" << endl;
        cout << par << endl;
        cout << w << endl;
        int x = find(a), y = find(b);
        k -= w[b]-w[a];
        if(x == y) return;
        if(rnk[x] > rnk[y]){
            par[y] = x;
            w[y] = k;
        }
        else{
            par[x] = y;
            w[x] = -k;
            if(rnk[x] == rnk[y]) rnk[y]++;
        }
        cout << par << endl;
        cout << w << endl;
    }
    bool same(int x, int y){ return find(x)==find(y);}
};

void solve(){
    union_find uf(N);
    int a, b, w; char c;
    rep(i,M){
        cin >> c >> a >> b; a--; b--;
        cout << uf.w << endl;
        if(c=='!'){
            cin >> w;
            uf.unite(a,b,w);
        }
        else {
            if(!uf.same(a,b)) puts("UNKNOWN");
            else cout << uf.w[b]-uf.w[a] << endl;
        }
    }
}

int main(){
    while(cin >> N >> M, N and M) solve();
    return 0;
}
