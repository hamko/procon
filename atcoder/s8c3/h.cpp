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
#define exists find_if
#define forall all_of
 
using ll = long long; using vll = vector<ll>; using vvll = vector<vll>; using P = pair<ll, ll>;
using ld = long double;  using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>; vll conv(vi& v) { vll r(v.size()); rep(i, v.size()) r[i] = v[i]; return r; }
using Pos = complex<double>;
 
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template<size_t...> struct seq{}; template<size_t N, size_t... Is> struct gen_seq : gen_seq<N-1, N-1, Is...>{}; template<size_t... Is> struct gen_seq<0, Is...> : seq<Is...>{};
template<class Ch, class Tr, class Tuple, size_t... Is>
void print_tuple(basic_ostream<Ch,Tr>& os, Tuple const& t, seq<Is...>){ using s = int[]; (void)s{0, (void(os << (Is == 0? "" : ", ") << get<Is>(t)), 0)...}; }
template<class Ch, class Tr, class... Args> 
auto operator<<(basic_ostream<Ch, Tr>& os, tuple<Args...> const& t) -> basic_ostream<Ch, Tr>& { os << "("; print_tuple(os, t, gen_seq<sizeof...(Args)>()); return os << ")"; }
ostream &operator<<(ostream &o, const vvll &v) { rep(i, v.size()) { rep(j, v[i].size()) o << v[i][j] << " "; o << endl; } return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U, typename V>  ostream &operator<<(ostream &o, const unordered_map<T, U, V> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it; o << "]";  return o; }
vector<int> range(const int x, const int y) { vector<int> v(y - x + 1); iota(v.begin(), v.end(), x); return v; }
template <typename T> istream& operator>>(istream& i, vector<T>& o) { rep(j, o.size()) i >> o[j]; return i;}
string bits_to_string(ll input, ll n=64) { string s; rep(i, n) s += '0' + !!(input & (1ll << i)); reverse(all(s)); return s; }
 
template <typename T> unordered_map<T, ll> counter(vector<T> vec){unordered_map<T, ll> ret; for (auto&& x : vec) ret[x]++; return ret;};
string substr(string s, P x) {return s.substr(x.fi, x.se - x.fi); }
struct ci : public iterator<forward_iterator_tag, ll> { ll n; ci(const ll n) : n(n) { } bool operator==(const ci& x) { return n == x.n; } bool operator!=(const ci& x) { return !(*this == x); } ci &operator++() { n++; return *this; } ll operator*() const { return n; } };
 
size_t random_seed; namespace std { using argument_type = P; template<> struct hash<argument_type> { size_t operator()(argument_type const& x) const { size_t seed = random_seed; seed ^= hash<ll>{}(x.fi); seed ^= (hash<ll>{}(x.se) << 1); return seed; } }; }; // hash for various class
namespace myhash{ const int Bsizes[]={3,9,13,17,21,25,29,33,37,41,45,49,53,57,61,65,69,73,77,81}; const int xor_nums[]={0x100007d1,0x5ff049c9,0x14560859,0x07087fef,0x3e277d49,0x4dba1f17,0x709c5988,0x05904258,0x1aa71872,0x238819b3,0x7b002bb7,0x1cf91302,0x0012290a,0x1083576b,0x76473e49,0x3d86295b,0x20536814,0x08634f4d,0x115405e8,0x0e6359f2}; const int hash_key=xor_nums[rand()%20]; const int mod_key=xor_nums[rand()%20]; template <typename T> struct myhash{ std::size_t operator()(const T& val) const { return (hash<T>{}(val)%mod_key)^hash_key; } }; };
template <typename T> class uset:public std::unordered_set<T,myhash::myhash<T>> { using SET=std::unordered_set<T,myhash::myhash<T>>; public: uset():SET(){SET::rehash(myhash::Bsizes[rand()%20]);} };
template <typename T,typename U> class umap:public std::unordered_map<T,U,myhash::myhash<T>> { public: using MAP=std::unordered_map<T,U,myhash::myhash<T>>; umap():MAP(){MAP::rehash(myhash::Bsizes[rand()%20]);} };    
 
struct timeval start; double sec() { struct timeval tv; gettimeofday(&tv, NULL); return (tv.tv_sec - start.tv_sec) + (tv.tv_usec - start.tv_usec) * 1e-6; }
struct init_{init_(){ gettimeofday(&start, NULL); ios::sync_with_stdio(false); cin.tie(0); srand((unsigned int)time(NULL)); random_seed = RAND_MAX / 2 + rand() / 2; }} init__;
 
static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;
#define ldout fixed << setprecision(40) 
const int DEBUG = 1;
ll h, w; 

// 標準入力からの質問応答
ll ask_from_stdin(ll x1, ll y1, ll x2, ll y2) {
    cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    ll ret; cin >> ret; return ret;
}

// 答えからの質問応答
vvll b_ans(50, vll(50, -1));
void set_answer(vvll& input) {
    b_ans = input;
}
ll ask_from_answer(ll x1, ll y1, ll x2, ll y2) {
    ll ret = 0;
    repi(i, x1, x2+1) repi(j, y1, y2+1) if (b_ans[i][j]) ret++;
    return ret;
}
ll ask_num = 0;
ll ask(ll x1, ll y1, ll x2, ll y2) {
    ask_num++;
    if (DEBUG) 
        return ask_from_answer(x1, y1, x2, y2);
    else 
        return ask_from_stdin(x1, y1, x2, y2);
}

vvll b(50, vll(50, -1));
// [(x1, y1), (x2, y2)]にn個爆弾がある場合に確定する。
void rec(ll x1, ll y1, ll x2, ll y2, ll n) {
//    cout << x1 << " " << y1 << " " << x2 << " " << y2 << " #in" << endl;
    assert(x1 <= x2);
    assert(y1 <= y2);
    assert(x1 >= 0 && y1 >= 0);
    assert(x2 <= 49 && y2 <= 49);
    if (n == 0 || n == (x2-x1+1)*(y2-y1+1)) {
        repi(i, x1, x2+1) repi(j, y1, y2+1)
            b[i][j] = !!n;
        return;
    }
 
    if (x1 == x2) {
        ll m = y1+(y2-y1)/2;
//        cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << n << " : " << m << endl;
        ll l = ask(x1, y1, x2, m);
        rec(x1, y1, x2, m, l);
        ll u = n - l;
        rec(x1, m+1, x2, y2, u);
    } else {
        ll m = x1+(x2-x1)/2;
        ll l = ask(x1, y1, m, y2);
        rec(x1, y1, m, y2, l);
        ll u = n - l;
        rec(m+1, y1, x2, y2, u);
    }
}
void rec_main(ll h, ll w) {
    ll n;
    if (DEBUG) 
        n = ask(0, 0, h-1, w-1);
    else 
        cin >> n;

    ask_num = 0;

    b = vvll(50, vll(50, -1));
    rec(0, 0, h-1, w-1, n);
}

ll compress(ll h, ll w, ll k) {
    ll ret = 0;
    vll two(10000); two[0] = 1; rep(i, two.size()-1) two[i+1] = (two[i] * 2ll) % k;
    rep(i, h) rep(j, w) if (b[i][j]) (ret += two[i*w+j]) %= k;
    return ret;
}

void print_board(vvll& b, ll h, ll w) {
    rep(i, h) rep(j, w) assert(b[i][j] != -1);
    rep(i, h) { 
        rep(j, w) cout << b[i][j] << " ";
        cout << endl;
    }
}

// state = 最大h*w個のペア(ll 質問mask, ll 返答);
// 2x2なら状態9^4=6561くらい、nがはじめに与えられるから少しは減る…？
// 3x2なら状態16^6=1700万くらい <-すでにやばそう
// 4x2なら状態24^8くらい
// 3x3なら状態54^9くらい
// 2x2なら行けそうだけど、3x3でもう結構状態量がやばい
using state = vector<P>;
ll countSolution(state s) {
    ll ret = 0;
    rep(mask, (1ll << (h*w))) {
        // maskがすべてのstateに合致しているか
        rep(i, s.size()) {
            if (__builtin_popcount(mask & s[i].fi) != s[i].se) 
                goto SKIP;
        }
        ret++;
        SKIP:;
    }
    return ret;
}

vll histogramSolution(state s, ll next_query_board) {
    vll ret(h*w+1);
    rep(mask, (1ll << (h*w))) {
        rep(i, s.size()) {
            if (__builtin_popcount(mask & s[i].fi) != s[i].se) 
                goto SKIP;
        }
        // maskがすべてのstateに合致している
        ret[__builtin_popcount(mask & next_query_board)]++;
        SKIP:;
    }
    return ret;
}

void test_countSolotion(void) {
    assert(h == 2), assert(w == 2);
    {
        assert(countSolution({P(0b1111, 0)}) == 1);
        assert(countSolution({P(0b1111, 1)}) == 4);
        assert(countSolution({P(0b1111, 2)}) == 6);
        assert(countSolution({P(0b1111, 3)}) == 4);
        assert(countSolution({P(0b1111, 4)}) == 1);

        assert(countSolution({P(0b1111, 2), P(0b1010, 1)}) == 4);
    }
}

void transite(state s) {
    ll num_of_solution_s = countSolution(s);

    vector<state> v_s_next; // state
    vector<double> v_p_next; // prob
    vector<int> v_r_next; // reward
    rep(h1, h) rep(w1, w) repi(h2, h1, h) repi(w2, w1, w) {
        ll next_query_board = 0;
        rep(hh, h) rep(ww, w) if (h1 <= hh && hh <= h2 && w1 <= ww && ww <= w2) 
            next_query_board |= 1ll << (hh*w + ww);

        cout << h1 << " " << h2 << " " << w1 << " " << w2 << ": " << bitset<4>(next_query_board) <<"#range" << endl;

        vll histogram_of_solution_s_next = histogramSolution(s, next_query_board);
        ll histogram_of_solution_sum = accumulate(all(histogram_of_solution_s_next), 0ll);
        cout << s << " " << bitset<4>(next_query_board) << " $ "<< histogram_of_solution_s_next << endl;

        rep(ret_ask, h*w+1) {
            // 状態sから、行動a=(h1, w1, h2, w2)を行った結果、
            // ret_askを受け取って状態s_nextに変動する確率と、その時に得られる報酬
            //
            state s_next = s;
            P next_query = P(next_query_board, ret_ask);

            // すでに聞いたことがある
            ll flag = 0; for (auto q : s) if (q == next_query) flag = 1;
            if (flag) continue;

            s_next.pb(next_query);
            sort(all(s_next));
            ll num_of_solution_s_next = countSolution(s_next);
            cout << s_next << " " << num_of_solution_s_next << endl;
            if (num_of_solution_s_next) {
                v_s_next.pb(s_next);
                v_r_next.pb(num_of_solution_s - num_of_solution_s_next);
                v_p_next.pb((double)histogram_of_solution_s_next[ret_ask] / histogram_of_solution_sum); 
            } else {
                v_s_next.pb(s_next);
                v_r_next.pb(-h*w);
                v_p_next.pb(0); 
            }
            // pってsからs_nextに行った時に、爆弾個数取得クエリでret_askを得る確率
            //            v_p_next.pb(); 
        }
    }

    cout << v_s_next << "#v_s_next" << endl;
    cout << v_p_next << "#v_p_next" << endl;
    cout << v_r_next << "#v_r_next" << endl;
}

void test(void) {
    test_countSolotion();
}

int main(void) {
    cin >> h >> w;
//    test();

    transite({P((1ll<<4)-1, 2)});
//    transite({P((1ll<<9)-1, 3)});
//    transite({P((1ll<<16)-1, 4)});

    

    /*
    vll ask_num_histogram(h*w);
    rep(mask, 1ll << (h*w)) {
//        cout << "####" << bitset<16>(mask) << "#mask" << endl;
        rep(hh, h) rep(ww, w) 
            b_ans[hh][ww] = !!(mask & (1ll << (hh*w+ww)));

//        print_board(b_ans, h, w);
        rec_main(h, w);
//        print_board(b, h, w);
//        cout << "took " << ask_num << endl;
        ask_num_histogram[ask_num]++;
    }
    cout << ask_num_histogram << endl;
    */

    /*
    ll k; cin >> k;
    cout << "! " << compress(h, w, k) << endl;
    */
    return 0;
}

