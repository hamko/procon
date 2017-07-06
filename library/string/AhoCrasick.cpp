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
template <typename T>  ostream &operator<<(ostream &o, const unordered_set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
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

// 簡単な挙動
//
// (a)
// p = transite(p, c) 
//      cが成功なら     p = p->next[c]
//      cが失敗なら     p = p->p[fail]->next[c]
//
// (b)
// 各pで、マッチングしている辞書番号集合が保持されている。
//
// (c)
// 複数マッチング。"aaaa"には"aa"が3回マッチングする。
// もしcoveringマッチングにしたいなら、マッチングするノードの失敗辺を全てrootに張り替えれば良い

const int fail = 0;
// パターンマッチングの頂点
// 256個の子を持つ多分木
struct pma {
    // trie木では、非0ならば遷移可能
    //
    // Aho-Crasickでは、
    // next[0]が、failure辺として特別扱いとなる。fail = 0である。
    // (1) thisがrootなら、next[fail]はNULLとなる。
    // (2) thisがrootでないなら、next[fail]は失敗辺の行き先となる。
    //
    // next[i]は、rootの時のみ特別扱いとなる。
    // (3) thisがrootなら、next[i]がない時は自己ループになる。
    pma* next[256] = {}; 

    unordered_set<ll> matched; // 正にこの頂点を表す文字列パターンの集合（昇順）
    pma() {}
    ~pma() { rep(i, 256) if (next[i]) delete next[i]; }
};
unordered_map<pma*, ll> name; // ネームサーバ

// rootに文字列sをパターンsiとして登録する。
void add(pma* root, string& s, ll si) {
    pma* now = root;
    for (int c : s) {
        if (!now->next[c]) {
            now->next[c] = new pma;
            ll name_size = name.size(); name[now->next[c]] = name_size; // for name server
        }
        now = now->next[c];
    }
    now->matched.insert(si);
}

// パターン集合pによってtrie木を構築する。
pma* buildTrie(vector<string> p) {
    name.clear();
    pma* root = new pma;
    name[root] = 0; // for name server

    ll pn = p.size();
    rep(si, pn) 
        add(root, p[si], si);
    return root;
}

// 今のTrie木に対して、AhoCrasickによって失敗辺を構築する。
//
// 頂点iのマッチング失敗辺failure(i)を既知とする。
// 
// この時、頂点iの次の頂点j=goto(i, c)での失敗辺は、
// cで遷移可能になるまで戻る関数failure(i)に対して、goto(failure(i), c)である。
void buildAhoCrasick(pma* root) {
    queue<pma*> q;

    // rootの失敗辺と、rootに直接つながっている成功辺の失敗辺の初期化
    repi(i, 1, 256) 
        if (root->next[i]) 
            root->next[i]->next[fail] = root, q.push(root->next[i]); // rootの直後で失敗したらrootに戻る
        else 
            root->next[i] = root; // (3)
    
    while (q.size()) {
        auto now = q.front(); q.pop();
        // 以下が(2) 
        repi(i, 1, 256) if (now->next[i]) {
            // iでの遷移が成功するところまで、失敗辺をたどってから進んだところが、新たな失敗辺
            auto now_f = now->next[fail];
            while (!now_f->next[i]) now_f = now_f->next[fail];
            now->next[i]->next[fail] = now_f->next[i];

            for (auto x : now_f->next[i]->matched) // 失敗辺の先のマッチングを継承する。パターンが互いに含まないなら不要
                now->next[i]->matched.insert(x);
            q.push(now->next[i]);
        }
    }
}

// Aho-Corasickをcoveringマッチングにする
// 破壊的
//
// 内部でやってることは、マッチングするノードの失敗辺を全てrootに張り替えている
void changeToCoveringMode(pma* root) {
    unordered_set<pma*> memo;
    function<void(pma*)> f = [&](pma* p) {
        if (memo.count(p)) return;
        memo.insert(p);
        if (p->matched.size()) 
            p->next[0] = root;
        rep(i, 256) if (p->next[i]) {
            f(p->next[i]);
        }
    };
    f(root);
}

// 頂点pから遷移cによって、次の頂点へと遷移する。
// 1回の遷移によるマッチング増加は、transite(p, c)->matchingによって計算できる。
pma* transite(pma* p, int c) {
    while (!p->next[c]) p = p->next[fail];
    p = p->next[c];
    return p;
}

// AhoCrasick pを構築したパターンが、sに何個入っているかをresに副作用で返す。
// 注意！！これはデフォルトで複数マッチング。coveringマッチングにしたいなら、changeToCoveringMode(root)を読ぶこと。
void match(pma* &p, string s, vll& res) {
    rep(i, s.length()) {
        p = transite(p, s[i]);
        for (auto x : p->matched) 
            res[x]++; 
    }
}

int main(void) {
    {
        vector<string> dict = {"abb", "b", "bbb"};
        auto root = buildTrie(dict);
        buildAhoCrasick(root);

        char c; 

        // pが表す接尾辞は""
        auto p = root;

        // pが表す接尾辞は""
        // 辞書に"c"はマッチしないので、matchした辞書は何もなし
        c = 'c'; p = transite(p, c); cout << c << " " << p->matched << endl; 

        // pが表す接尾辞は"b"
        // 辞書のうち#1の"b"がマッチする
        c = 'b'; p = transite(p, c); cout << c << " " << p->matched << endl; 

        // pが表す接尾辞は"bb"
        // 辞書のうち#1の"b"がマッチする
        c = 'b'; p = transite(p, c); cout << c << " " << p->matched << endl; 

        // pが表す接尾辞は"bbb"
        // 辞書のうち#1の"b"と、#2の"bbb"がマッチする
        c = 'b'; p = transite(p, c); cout << c << " " << p->matched << endl; 
    }

    {
        vector<string> dict = {"ab", "abab"};
        auto root = buildTrie(dict);
        buildAhoCrasick(root);

        char c; 

        // pが表す接尾辞は""
        auto p = root;

        // pが表す接尾辞は"a"
        // 辞書に"a"はマッチしない
        c = 'a'; p = transite(p, c); cout << c << " " << p->matched << endl; 

        // pが表す接尾辞は"ab"
        // 辞書のうち#0の"ab"がマッチする
        c = 'b'; p = transite(p, c); cout << c << " " << p->matched << endl; 

        // pが表す接尾辞は"aba"
        // 辞書に"aba"はマッチしない
        c = 'a'; p = transite(p, c); cout << c << " " << p->matched << endl; 

        // pが表す接尾辞は"abab"
        // 辞書のうち#0の"ab"と、#1の"abab"がマッチする
        c = 'b'; p = transite(p, c); cout << c << " " << p->matched << endl; 
    }

    {
        vector<string> dict = {"abb", "b", "bbb"};
        auto root = buildTrie(dict);
        buildAhoCrasick(root);

        auto p = root;

        string s = "abbbbbbb";
        vll res(dict.size());
        match(p, s, res); // 重複マッチングで何個ある？
        cout << res << endl;
    }

    {
        vector<string> dict = {"abab"};
        auto root = buildTrie(dict);
        buildAhoCrasick(root);

        auto p = root;
        string s = "abababab";

        {
            vll res(dict.size());
            match(p, s, res); // 重複マッチングで何個ある？
            cout << res << endl;
        }

        {
            changeToCoveringMode(root); // covering matchingに変更
            vll res(dict.size());
            match(p, s, res); // covering matchingで何個ある？
            cout << res << endl;
        }
    }


    return 0;
}
