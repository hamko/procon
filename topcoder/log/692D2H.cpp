#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define repi(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mt make_tuple
#define mp make_pair
#define ZERO(a) memset(a,0,sizeof(a))
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
#define exists find_if
#define forall all_of

using ll = long long; using vll = vector<ll>; using vvll = vector<vll>; using P = pair<ll, ll>;
using ld = long double;  using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>; vll conv(vi& v) { vll r(v.size()); rep(i, v.size()) r[i] = v[i]; return r; }
using Pos = complex<double>;

namespace std{ namespace { template <class T> inline void hash_combine(size_t& seed, T const& v) { seed ^= hash<T>()(v) + 0x9e3779b9 + (seed<<6) + (seed>>2); } template <class Tuple, size_t Index = tuple_size<Tuple>::value - 1> struct HashValueImpl { static void apply(size_t& seed, Tuple const& tuple) { HashValueImpl<Tuple, Index-1>::apply(seed, tuple); hash_combine(seed, get<Index>(tuple)); } }; template <class Tuple> struct HashValueImpl<Tuple,0> { static void apply(size_t& seed, Tuple const& tuple) { hash_combine(seed, get<0>(tuple)); } }; } template <typename ... TT> struct hash<tuple<TT...>> { size_t operator()(tuple<TT...> const& tt) const { size_t seed = 0; HashValueImpl<tuple<TT...> >::apply(seed, tt); return seed; } }; } 
namespace std { template<typename U, typename V> struct hash<pair<U, V>> { size_t operator()(pair<U, V> const& v) const { return v.first ^ v.second; } }; } struct pairhash { public: template <typename T, typename U> size_t operator()(const pair<T, U> &x) const { return hash<T>()(x.first) ^ hash<U>()(x.second); } };

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
template <typename T, typename U>  ostream &operator<<(ostream &o, const unordered_map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it; o << "]";  return o; }
vector<int> range(const int x, const int y) { vector<int> v(y - x + 1); iota(v.begin(), v.end(), x); return v; }
template <typename T> istream& operator>>(istream& i, vector<T>& o) { rep(j, o.size()) i >> o[j]; return i;}
string bits_to_string(ll input, ll n=64) { string s; rep(i, n) s += '0' + !!(input & (1ll << i)); return s; }
template <typename T> unordered_map<T, ll> counter(vector<T> vec){unordered_map<T, ll> ret; for (auto&& x : vec) ret[x]++; return ret;};
string substr(string s, P x) {return s.substr(x.fi, x.se - x.fi); }
struct ci : public iterator<forward_iterator_tag, ll> { ll n; ci(const ll n) : n(n) { } bool operator==(const ci& x) { return n == x.n; } bool operator!=(const ci& x) { return !(*this == x); } ci &operator++() { n++; return *this; } ll operator*() const { return n; } };

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+9;
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

ll dp[2600][55][55];
class LinenCenterEasy {
    public:
        int countStrings(string s, int n, int k) {
            name.clear();
            ll l = s.size();
            vector<string> dict = {s};
            auto root = buildTrie(dict);
            buildAhoCrasick(root);
            changeToCoveringMode(root); // covering matchingに変更
            cout << name << endl;
            vector<pma*> name_rev(1000);
            for (auto x : name) {
                name_rev[x.se] = x.fi;
            }


            ll m = name.size();

            // h, c -> name[p], !!(p->matched.size())
            ll name_p[100][256];
            ll p_matched_size[100][26];
            rep(h, m) repi(c, 'a', 'z'+1) {
                auto p = transite(name_rev[h], c);
                name_p[h][c] = name[p];
                p_matched_size[h][c] = !!(p->matched.size());
            }


            // dp[i][j][h] =　ちょうどi文字見たとき、マッチングがj個で、Aho上のノードhにいるときの場合の数
            ZERO(dp);
            dp[0][0][name[root]] = 1;
            rep(i, l*k+n) {
                cout << i << endl;
                rep(j, 52) rep(h, m) {
                    if (!dp[i][j][h]) continue;
                    repi(c, 'a', 'z'+1) {
                        (dp[i+1][j+p_matched_size[h][c]][name_p[h][c]] += dp[i][j][h]) %= mo;
                    }
                }
            }

            ll ret = 0;
            repi(i, l*k, l*k+n+1) repi(j, k, k+1) rep(h, m) {
                (ret += dp[i][j][h]) %= mo;
            }

            return ret;
        }
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit-pf 2.3.0
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
using namespace std;
bool KawigiEdit_RunTest(int testNum, string p0, int p1, int p2, bool hasAnswer, int p3) {
    cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << p1 << "," << p2;
    cout << "]" << endl;
    LinenCenterEasy *obj;
    int answer;
    obj = new LinenCenterEasy();
    clock_t startTime = clock();
    answer = obj->countStrings(p0, p1, p2);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << p3 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer) {
        res = answer == p3;
    }
    if (!res) {
        cout << "DOESN'T MATCH!!!!" << endl;
    } else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
        cout << "FAIL the timeout" << endl;
        res = false;
    } else if (hasAnswer) {
        cout << "Match :-)" << endl;
    } else {
        cout << "OK, but is it right?" << endl;
    }
    cout << "" << endl;
    return res;
}
int main() {
    bool all_right;
    bool disabled;
    bool tests_disabled;
    all_right = true;
    tests_disabled = false;

    string p0;
    int p1;
    int p2;
    int p3;

    // ----- test 0 -----
    disabled = false;
    p0 = "xy";
    p1 = 2;
    p2 = 1;
    p3 = 2079;
    all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, true, p3) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 1 -----
    disabled = false;
    p0 = "q";
    p1 = 2;
    p2 = 1;
    p3 = 1926;
    all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, true, p3) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 2 -----
    disabled = false;
    p0 = "ababab";
    p1 = 5;
	p2 = 4;
	p3 = 527166180;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = "fgcdx";
	p1 = 10;
	p2 = 3;
	p3 = 586649223;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = "ghjhhhgjhjhgjhghghjhjg";
	p1 = 8;
	p2 = 10;
	p3 = 192161304;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 5 -----
	disabled = false;
	p0 = "pdpfrpfdfdpfdpfdpfpdfldfpfldpfe";
	p1 = 49;
	p2 = 25;
	p3 = 164673990;
	all_right = (disabled || KawigiEdit_RunTest(5, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 6 -----
	disabled = false;
	p0 = "a";
	p1 = 7;
	p2 = 0;
	p3 = 357828722;
	all_right = (disabled || KawigiEdit_RunTest(6, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 7 -----
	disabled = false;
	p0 = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee";
	p1 = 50;
	p2 = 50;
	p3 = 960113657;
	all_right = (disabled || KawigiEdit_RunTest(7, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	if (all_right) {
		if (tests_disabled) {
			cout << "You're a stud (but some test cases were disabled)!" << endl;
		} else {
			cout << "You're a stud (at least on given cases)!" << endl;
		}
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// PROBLEM STATEMENT
// 
// A few days ago, you won a tour of a textile factory. (Chocolate factory tours were deemed too risky to children and therefore banned). As everyone knows, textile is made of strings, so it's time to solve a string problem!
// 
// 
// 
// 
// 
// You are given a string S of length L.
// For any string T, we can now define its covering number c(T) as the maximum number of non-overlapping occurrences of S in T.
// Each occurrence must be a contiguous substring of T, and they may not share any letters.
// 
// 
// 
// 
// 
// Examples:
// If S="ab", we have c("xyz")=0 and c("ababxab")=3.
// If S="aaa", we have c("aa")=0 and c("aaaaaa")=2.
// 
// 
// 
// 
// 
// In addition to S, you are given two ints N and K.
// 
// 
// 
// 
// 
// Consider all strings with the following properties:
// 
// Each character of the string is a lowercase English letter ('a'-'z').
// The length of the string is between L*K and L*K+N, inclusive.
// The covering number of the string is exactly K.
// 
// 
// 
// Let X be the number of strings with the above properties.
// Since X may be large, compute and return the value (X modulo 1,000,000,009).
// 
// 
// DEFINITION
// Class:LinenCenterEasy
// Method:countStrings
// Parameters:string, int, int
// Returns:int
// Method signature:int countStrings(string S, int N, int K)
// 
// 
// CONSTRAINTS
// -N will be between 0 and 50, inclusive.
// -K will be between 0 and 50, inclusive.
// -L will be between 1 and 50, inclusive.
// -S will contain exactly L characters.
// -S will contain only lowercase English letters.
// 
// 
// EXAMPLES
// 
// 0)
// "xy"
// 2
// 1
// 
// Returns: 2079
// 
// There are 2027 strings of length 4, 52 strings of length 3 and one string of length 2 containing "xy" as a substring. One of them, "xyxy", has covering number 2, so we don't count it.
// 
// 1)
// "q"
// 2
// 1
// 
// Returns: 1926
// 
// We're counting strings containing exactly one character 'q' and at most two other characters. There's one such string of length 1 ("q"), 2*25=50 of length 2 and 3*25^2=1875 of length 3.
// 
// 2)
// "ababab"
// 5
// 4
// 
// Returns: 527166180
// 
// Watch out for integer overflows and make sure you are using the correct modulus!
// 
// 3)
// "fgcdx"
// 10
// 3
// 
// Returns: 586649223
// 
// 
// 
// 4)
// "ghjhhhgjhjhgjhghghjhjg"
// 8
// 10
// 
// Returns: 192161304
// 
// 
// 
// 5)
// "pdpfrpfdfdpfdpfdpfpdfldfpfldpfe" 
// 49
// 25
// 
// Returns: 164673990
// 
// 
// 
// 6)
// "a"
// 7
// 0
// 
// Returns: 357828722
// 
// 
// 
// 7)
// "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee" 
// 50
// 50
// 
// Returns: 960113657
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
