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
const int DEBUG = 0;
ll h, w; 
double g_gamma = 0.90;

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

vvll b;
// [(x1, y1), (x2, y2)]にn個爆弾がある場合に確定する。
void rec(ll x1, ll y1, ll x2, ll y2, ll n) {
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
pair<vvll, ll> rec_main(ll h, ll w, ll n, ll h0 = 0, ll w0 = 0) {
    if (DEBUG) 
        n = ask(0, 0, h-1, w-1);

    ask_num = 0;

    b = vvll(h+h0, vll(w+w0, -1));
    rec(h0, w0, h0+h-1, w0+w-1, n);
    vvll b_ret(h, vll(w));
    rep(i, h) rep(j, w)
        b_ret[i][j] = b[h0+i][w0+j];
    return mp(b_ret, ask_num);
}

ll compress(vvll& b, ll h, ll w, ll k) {
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
map<state, ll> memo_countSolution;
ll countSolution(state s) {
    if (memo_countSolution.count(s)) return memo_countSolution[s];
    ll ret = 0;
    rep(mask, (1ll << (h*w))) {
        // maskがすべてのstateに合致しているか
        rep(i, s.size()) 
            if (__builtin_popcount(mask & s[i].fi) != s[i].se) 
                goto SKIP;
        ret++;
//        if (ret > 1) break; // 0, 1, 2しか興味がない
        SKIP:;
    }
    return memo_countSolution[s] = ret;
}
vll enumerateSolution(state s) {
    vll ret;
    rep(mask, (1ll << (h*w))) {
        // maskがすべてのstateに合致しているか
        rep(i, s.size()) 
            if (__builtin_popcount(mask & s[i].fi) != s[i].se) 
                goto SKIP;

        ret.pb(mask);
//        if (ret > 1) break; // 0, 1, 2しか興味がない
        SKIP:;
    }
    return ret;
}

vll histogramSolution(state s, ll next_query_board) {
    vll ret(h*w+1);
    rep(mask, (1ll << (h*w))) {
        rep(i, s.size()) 
            if (__builtin_popcount(mask & s[i].fi) != s[i].se) 
                goto SKIP;
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

struct edge_t {
    state s;
    double p;
    ll r;
};
ostream &operator<<(ostream &o, const edge_t &e) {  
    o << "(" << e.s << ", " << e.p << ", " << e.r << ") "; return o; 
}


map<state, ll> all_states;
map<ll, state> all_states_rev;
map<ll, map<ll, vector<tuple<ll, double, double>>>> pr; // pr[s][a] = [(s'2, p2, r2), (s'1, p1, r1) ...  ]
void addState(state s) {
    if (!all_states.count(s)) {
        ll all_states_size = all_states.size();
        all_states[s] = all_states_size;
        all_states_rev[all_states_size] = s;
    }
}

map<tuple<ll, ll, ll, ll>, ll> all_actions; // h1, h2, w1, w2
map<ll, tuple<ll, ll, ll, ll>> all_actions_rev;
void addAction(ll h1, ll h2, ll w1, ll w2) {
    auto action = tie(h1, h2, w1, w2);
    if (!all_actions.count(action)) {
        ll all_actions_size = all_actions.size();
        all_actions[action] = all_actions_size;
        all_actions_rev[all_actions_size] = action;
    }
}
ll getQueryFromHW(ll h1, ll h2, ll w1, ll w2) {
    ll mask = 0;
    repi(hh, h1, h2+1) repi(ww, w1, w2+1) mask |= (1ll << (hh*w+ww));
    return mask;
}
void transite(state s, vector<edge_t>& ret) {
    addState(s);
    if (countSolution(s) == 1) return;
    if (s.size() > h * w - 1) return; // 長さh*wで絶対終わるので
    ret.clear();

    rep(h1, h) rep(w1, w) repi(h2, h1, h) repi(w2, w1, w) {
        addAction(h1, h2, w1, w2);
    }
    rep(h1, h) rep(w1, w) repi(h2, h1, h) repi(w2, w1, w) {
        ll next_query_board = getQueryFromHW(h1, h2, w1, w2);

        vll histogram_of_solution_s_next = histogramSolution(s, next_query_board);
        ll histogram_of_solution_sum = accumulate(all(histogram_of_solution_s_next), 0ll);

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

            if (!num_of_solution_s_next) continue; // 解が存在しないような状態には遷移しない
            if (s_next.size() >= h*w && num_of_solution_s_next != 1) continue; // h*w回クエリもらってるのに解が1位に定まらないような状態には遷移しない
            edge_t tmp;
            tmp.s = s_next;
#if 0
            tmp.r = num_of_solution_s - num_of_solution_s_next;
#else
            if (num_of_solution_s_next == 1) 
                tmp.r = 1;
            else 
                tmp.r = -1;
#endif
//            tmp.r = 0; // デバッグ用。これがonなのに性能が高かったらおかしい。
            tmp.p = (double)histogram_of_solution_s_next[ret_ask] / histogram_of_solution_sum; 
            ret.pb(tmp);

            addState(s_next);
            pr[all_states[s]][all_actions[tie(h1, h2, w1, w2)]].pb(tie(all_states[s_next], tmp.p, tmp.r));
        }
    }
}


ll transitFromID(ll si, ll ai) {
    state s = all_states_rev[si];

    ll h1, h2, w1, w2; tie(h1, h2, w1, w2) = all_actions_rev[ai];
    ll ret_of_ask = ask_from_answer(h1, w1, h2, w2);

    ll mask = getQueryFromHW(h1, h2, w1, w2);

    s.pb(P(mask, ret_of_ask));
    sort(all(s));
    assert(all_states.count(s));
    return all_states[s];
}

void test(void) {
    test_countSolotion();
}

ll evaluateBinarySearch(ll mask) {
    rep(hh, h) rep(ww, w) 
        b_ans[hh][ww] = !!(mask & (1ll << (hh*w+ww)));
    rec_main(h, w, -1/*bomb num*/);
    return ask_num;
}
double expectValOfEvaluateBinarySearch(ll n) {
    double ret = 0;
    ll num = 0;
    rep(mask, 1ll << (h*w)) if (__builtin_popcount(mask) == n) {
        num++;
        ret += evaluateBinarySearch(mask);
    }
    return ret / num;
}

ll evaluatePolicy(ll mask, state initial_state, vll& pi) {
    rep(hh, h) rep(ww, w) 
        b_ans[hh][ww] = !!(mask & (1ll << (hh*w+ww)));

    assert(all_states.count(initial_state));
    ll si = all_states[initial_state];
    ll ret = 0;
    while (1) {
        ll a = pi[si];
        if (a == -1) return ret;

        ll h1, h2, w1, w2; tie(h1, h2, w1, w2) = all_actions_rev[a];
        state s = all_states_rev[si];
        state next_s = all_states_rev[si];
        next_s.pb(P(getQueryFromHW(h1, h2, w1, w2), ask(h1, w1, h2, w2)));
        sort(all(next_s));
        assert(all_states.count(next_s));
        si = all_states[next_s];
        ret++;
    }

    assert(0);
    return -1;
}
double expectValOfEvaluatePolicy(ll n, state initial_state, vll& pi) {
    double ret = 0;
    ll num = 0;
    rep(mask, 1ll << (h*w)) if (__builtin_popcount(mask) == n) {
        num++;
        ret += evaluatePolicy(mask, initial_state, pi);
    }
    return ret / num;
}

vector<double> calculateV(void) {
    ll sn = all_states.size();
    ll an = all_actions.size();
    vector<double> V(sn, 0); // v(s) : 状態価値
    double delta = INF;
    while (delta > 1e-10) {
        delta = 0;
        rep(s, sn) {
            // 終端条件
            if (!pr[s].size()) {
                V[s] = 0;
                continue; 
            }
            double prev_v = V[s];
            double v_max = -INF;
            double v_max_a = -INF;
            rep(a, an) if (pr[s].count(a)) {
                double sum = 0;
                for (auto&& spr_dash : pr[s][a]) {
                    int s_dash; double p, r; tie(s_dash, p, r) = spr_dash;
                    sum += p * (r + g_gamma * V[s_dash]);
                }
                if (v_max < sum) {
                    v_max = sum;
                    v_max_a = a;
                }
            }
            V[s] = v_max;
            delta += abs(V[s] - prev_v);
        }
    }
    // assert
    // 初期値をちょっと変えて、同じ場所に収束する

    return V;
}

vll calculatePi(vector<double>& V) {
    ll sn = all_states.size();
    ll an = all_actions.size();
    vector<ll> pi(sn); // pi(s) : S -> A
    {
        rep(s, sn) {
            // 終端条件
            if (!pr[s].size()) {
                pi[s] = -1;
                continue; 
            }
            double v_max = -INF;
            double v_max_a = -INF;
            rep(a, an) if (pr[s].count(a)) {
                double sum = 0;
                for (auto&& spr_dash : pr[s][a]) {
                    int s_dash; double p, r; tie(s_dash, p, r) = spr_dash;
                    sum += p * (r + g_gamma * V[s_dash]);
                }
                if (v_max < sum) {
                    v_max = sum;
                    v_max_a = a;
                }
            }
            pi[s] = v_max_a;
            assert(pi[s] == -INF || pr[s].count(pi[s]));
        }
    }
    rep(s, sn) if (pr[s].size() != 0) assert(pi[s] != -INF);

    return pi;
}

pair<vvll, ll> determineBoardFromPolicy(ll h, ll w, ll num, vll pi, ll offset_h = 0, ll offset_w = 0) {
    state s = {P((1ll<<(h*w))-1,num)};
    ll ret_num = 0;
    while (1) {
        // TODO countSolutionに変更
        ll cs = 0;
        rep(mask, (1ll << (h*w))) {
            rep(i, s.size()) 
                if (__builtin_popcount(mask & s[i].fi) != s[i].se) 
                    goto SKIP;
            cs++;
            SKIP:;
        }
        if (cs == 1) break;

        ret_num++;

        ll si = all_states[s];
        ll ai = pi[si];
        ll h1, h2, w1, w2; tie(h1, h2, w1, w2) = all_actions_rev[ai];

        ll n = ask(offset_h+h1, offset_w+w1, offset_h+h2, offset_w+w2);

        ll mask = 0;
        repi(hh, h1, h2+1) repi(ww, w1, w2+1) 
            mask |= (1ll << (hh*w+ww));

        s.pb(P(mask, n));
        sort(all(s));
        assert(all_states.count(s));
    }
    vll ret = enumerateSolution(s);
    assert(ret.size() == 1);
    ll b_mask = ret[0];

    vvll ret_b(h, vll(w, 0));
    rep(hh, h) rep(ww, w) if (b_mask & (1ll << (hh*w+ww))){
        ret_b[hh][ww] = 1;
    }
    return mp(ret_b, ret_num);
}
int main(void) {
    h = 2, w = 2;

    //    test();

    queue<state> q;

    state initial_state = {P((1ll<<(h*w))-1, 2)};
    q.push(initial_state);
    addState(initial_state);

    set<state> used;
    used.insert(initial_state);
    while(!q.empty()) {
        state s = q.front(); q.pop();

        vector<edge_t> edges;
        transite(s, edges);
        for (auto&& e : edges) {
            if (used.count(e.s)) continue;
            used.insert(e.s);
            q.push(e.s);
        }
    }
//    cout << "# state num = " << all_states.size() << endl;
//    cout << "# action num = " << all_actions.size() << endl;

    for(auto x : all_states) {
        state s = x.fi;
        ll si = x.se;
        if (countSolution(s) == 1) 
            assert(pr[si].size() == 0);
    }

    //    cout << "# state size = " << all_states.size() << endl;
    //    cout << "# All States " << endl;
    //    for (auto x : all_states)  cout << x.se << " " << x.fi << " " << countSolution(x.fi)<< endl; 
    //    cout << "# All Actions " << endl;
    //    for (auto x : all_actions) cout << x.se << " " << x.fi << endl;
    //    cout << "# Prob, Reward " << endl;
    //    for (auto pr_s : pr) { ll s = pr_s.fi; for (auto pr_sa : pr_s.se) { ll a = pr_sa.fi; cout << s << " " << a << " " << pr_sa.se << endl; } }


    vector<double> V = calculateV();
    vll pi = calculatePi(V);

    ll g_h, g_w, n; cin >> g_h >> g_w >> n; 
    ll k; cin >> k;
    vvll ret; ll ret_num;
//    tie(ret, ret_num) = rec_main(g_h, g_w, n, 0, 0);
    tie(ret, ret_num) = determineBoardFromPolicy(g_h, g_w, n, pi);


    /*
    vvll ret(g_h, vll(g_w));
    ll all_ret_num = 0;
    ll hs = 2, ws = 2; // h size, w size
    rep(i, g_h/hs) rep(j, g_w/ws) {
        ll num = ask(i*hs, j*ws, i*hs+1, j*ws+1); // h1, w1, h2, w2

        vvll ret_b; ll ret_num;
        if (num == 2) 
            tie(ret_b, ret_num) = determineBoardFromPolicy(hs, ws, num, pi, i*hs, j*ws);
        else 
            tie(ret_b, ret_num) = rec_main(2, 2, num, i*hs, j*ws);

        all_ret_num += ret_num + 1;
        rep(hh, hs) rep(ww, ws)
            ret[i*hs+hh][j*ws+ww] = ret_b[hh][ww];
    }
    */
    /*
    rep(i, g_h) { 
        rep(j, g_w) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
    */

    /*
    cout << expectValOfEvaluateBinarySearch(2) << endl;
    cout << expectValOfEvaluatePolicy(2, initial_state, pi) << endl;
    */
       cout << "! " << compress(ret, g_h, g_w, k) << endl;
    return 0;
}

