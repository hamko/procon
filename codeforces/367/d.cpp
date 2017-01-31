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

class node {
public:
    node* one = NULL;
    node* zero = NULL;
    int bit;
    using uint = unsigned int;
    unordered_map<uint, int> nums;
    node(int bit_) {
        bit = bit_;
    }
    void add(uint x) {
//        cerr << bit << " : " << x << endl;
        nums[x]++;
        if (x & ((uint)1 << bit)) {
            if (one) {
                one->add(x);
            } else {
                if (bit>=0) {
                    one = new node(bit-1);
                    one->add(x);
                }
            }
        } else {
            if (zero) {
                zero->add(x);
            } else {
                if (bit>=0) {
                    zero = new node(bit-1);
                    zero->add(x);
                }
            }
        }
    }
    void erase(uint x) {
        nums[x]--;
        if (nums[x] == 0) {
            nums.erase(x);
        }
        if (x & ((uint)1 << bit)) {
            if (one) {
                one->erase(x);
            } 
        } else {
            if (zero) {
                zero->erase(x);
            }
        }
    }
    uint getMax(uint x) {
        if (nums.size() == 1) {
            return nums.begin()->fi;
        }
        if (x & ((uint)1 << bit)) {
            if (zero && zero->nums.size()) {
                return zero->getMax(x);
            } else if (one && one->nums.size()) {
                return one->getMax(x);
            } else {
                cerr << nums << endl;
                assert(0);
            }
        } else {
            if (one && one->nums.size()) {
                return one->getMax(x);
            } else if (zero && zero->nums.size()){
                return zero->getMax(x);
            } else {
                cerr << nums << endl;
                assert(0);
            }
        }
    }
    void print(void) {
        cout << bit << " : " << nums << endl;
        if (one) one->print();
        if (zero) zero->print();
    }
};

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    int q; cin >> q;
    node* root = new node(31);
    root->add(0);
    rep(_, q) {
        char c; ll x; cin >> c >> x;
        if (c == '+') {
            root->add(x);
        } else if (c == '-') {
            root->erase(x);
        } else {
            cout << ((root->getMax(x)) ^ x) << endl;
        }
    }
    return 0;
}
