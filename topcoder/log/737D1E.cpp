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
static const long long mo = 1e9+7;
#define ldout fixed << setprecision(40) 

class AliceAndBobEasy {
    public:
        ll solve(vll a) {
            ll n = a.size();
            ll x = 0;
            rep(i, n) {
                x ^= a[i];
            }
            if (x == 0) {
                return -1;
            }
            ll ret = 0;
            rep(i, n) if ((a[i] ^ x) <= a[i]) {
                ret++;
            }
            return ret;
        }
        ll rint(ll i, ll j) { if (i > j) return i; else return (ll)rand() % (j - i + 1) + i; }
        vll rvector(ll n, ll x, ll y) { vll a(n); rep(i, n) a[i] = rint(x, y); return a; }
        vector <int> make_random(int n) {
            if (n == 1) {
                return {737};
            }
            if (n == 2) {
                return {737, 373};
            }
            if (n == 3) {
                return {3337, 3373, 3733};
            }

            vll ret; 

            ll ss = 0;
            rep(_, 100000) {
                auto tmp = rvector(n, 1, 16);
                ll s = solve(tmp);
//                cout << tmp << " " << s << endl;

                chmax(ss, s);
            }
//            cout << ss << endl;

            const ll maxd = 25;
            while (1) {
                vll g(n);
                rep(i, n) {
                    g[i] = 1;
                }
                if (n % 2 == 0) g[0] = 0;
                repi(d, 1, maxd+1) {
                    vll zo(n);
                    ll u = n / 2;
                    if (u % 2 == 1) u--;
                    rep(i, u) zo[i] = 1;
                    random_shuffle(all(zo));
                    rep(i, n) {
                        g[i] ^= (zo[i] << d);
                    }
                }
                /*
                rep(i, n) {
                    cout << bitset<30>(g[i]) << endl;
                }
                */
//                cout << g << endl;
                ll x = 0;
                rep(i, n) x ^= g[i];
//                cout << x << endl;
                assert(x == 1);

                set<ll> memo;
                rep(i, n) memo.insert(g[i]);
                if (memo.size() != n) {
                    continue;
                } else {
                    ret = g;
                    break;
                }
            }

            assert(ret.size() == n);
            if (n % 2 == 1) {
                assert(solve(ret) == n);
            } else {
                assert(solve(ret) == n - 1);
            }

            vector<int> ans;
            rep(i, ret.size()) {
                assert(1 <= ret[i] && ret[i] <= 737373737);
                ans.pb(ret[i]);
            }
            return ans;
        }
        vector <int> make(int n) {
            vvll rets = 
            {
                {},
                {737},
                {737, 373},
                {3337, 3373, 3733},
                {22423802, 45724945, 32262127, 33806853},
                {28836097, 13003079, 743017, 34714295, 56921241},
                {34603266, 16180417, 33628241, 526855, 19518397, 29760553},
                {3408391, 9477905, 156813, 27334915, 55058553, 49249, 38731905},
                {46895514, 54360309, 62033605, 63514455, 6048563, 23387181, 2564235, 9631593},
                {35728609, 66686041, 17215823, 66115497, 13243159, 36062257, 1804951, 13464237, 18114883},
                {7424338, 43668321, 6480039, 59258009, 39158809, 8462757, 5154839, 25644845, 19142347, 54041153},
                {5252181, 2469475, 36786353, 5251345, 10522377, 25973317, 65142913, 42946733, 34212543, 22325579, 17552643},
                {2592346, 19699621, 64966733, 37265865, 22525915, 44919015, 12680721, 17988967, 63517729, 64129595, 6605237, 45761439},
                {25224809, 20459577, 46203343, 42735645, 37592307, 27392835, 15179207, 1204681, 14627489, 6671157, 56250157, 53371927, 55740051},
                {6595264, 8510865, 50563519, 33203337, 44423009, 22546725, 64958067, 17719827, 52469525, 6061071, 40042731, 34624355, 12464349, 8470541},
                {40974405, 398529, 697221, 5616033, 8996091, 61050433, 9738799, 30558809, 22828225, 33565753, 41679375, 19048351, 42729783, 23085347, 61686033},
                {38723440, 12223567, 65196881, 9428987, 51922969, 10607311, 21765175, 22503811, 532879, 60918893, 41345091, 44966461, 64843651, 32847521, 7418293, 51625981},
                {30881843, 679909, 45490247, 49562965, 19476363, 4835195, 50819365, 48602275, 37338359, 10864345, 23826825, 32563393, 34120509, 29499803, 5938725, 60578377, 51792415},
                {18472298, 41969359, 34886577, 48626435, 41860609, 64108517, 57977059, 42837013, 19341097, 59216413, 2115645, 4975907, 23748633, 19595411, 1053637, 14453079, 11141371, 30491853},
                {48934993, 307795, 24808045, 18670003, 41969813, 25760591, 337613, 15758509, 576267, 62127181, 53757047, 41615369, 55318283, 3573137, 935427, 12949681, 32577957, 42143153, 54750051},
                {36916526, 15270083, 61608981, 46015655, 56015655, 47736429, 23226587, 48547113, 1490643, 54157, 22001553, 18602333, 42375845, 10351599, 36680801, 30525971, 27986995, 24212441, 54808063, 66661209},
                {52482699, 40280255, 13343729, 29685381, 52922149, 26107071, 62074201, 533511, 16757443, 62807053, 51580981, 39909779, 56129877, 34111807, 3243475, 54742569, 28656483, 14091513, 7906125, 9187049, 14535491},
                {9860864, 30438205, 43533757, 18957385, 34545281, 15106389, 59720715, 39883901, 23920909, 23640127, 17146305, 45083363, 47667911, 6291819, 54434211, 51613311, 16803857, 13612675, 35237011, 24143839, 47233829, 12212977},
                {43386981, 55986769, 8455079, 5109099, 46765287, 6779481, 40986513, 581053, 10399775, 58765057, 53684687, 13288795, 18752659, 35177089, 31745543, 30873721, 42183597, 20458661, 18877219, 15487049, 19518613, 56826721, 36999195},
                {62126482, 48644211, 35479229, 58509291, 47584265, 27803207, 40279009, 51849247, 36014017, 14170217, 57034619, 9796109, 24026877, 57894177, 9474121, 32236055, 9004309, 16899583, 50131703, 17476487, 10431369, 3396863, 63448469, 21596451},
                {12271005, 700353, 50590665, 6511935, 51846421, 49081457, 9564589, 48318115, 704009, 55445807, 31076955, 24408929, 60942279, 47672065, 40420945, 53324383, 9867403, 16261119, 43270207, 20489415, 26198443, 6362865, 17189041, 56428581, 66359383},
                {20113794, 27693099, 40047977, 64541985, 9597657, 1119791, 29055737, 49350597, 807671, 47323977, 23253199, 17336437, 38855573, 30223861, 19745033, 53419105, 9353349, 66039199, 12936587, 35554929, 42331667, 40636763, 22145583, 25479, 66727477, 37069843},
                {6638721, 30189173, 7754045, 20384201, 27271075, 47852519, 16517269, 37383455, 17282005, 37200191, 48322081, 35577649, 50718151, 28903513, 9801985, 46281343, 4220447, 18510063, 12700737, 30081401, 34793627, 25206465, 46725671, 38339849, 52926091, 20497025, 53227619},
                {53925116, 11301633, 37703311, 48910261, 25031817, 8893063, 26632495, 40595747, 26453459, 40978519, 8457785, 51223533, 13972283, 58558823, 6859219, 40893341, 20059763, 65787999, 6317253, 22752835, 58798297, 6065769, 2422163, 26790377, 60202045, 64407525, 58736417, 46793247},
                {49633963, 9473573, 51947191, 16924701, 40238149, 58445863, 44852209, 18046079, 62926471, 21714509, 45268841, 23634771, 34154317, 37696987, 14014353, 52697889, 29833717, 8897179, 49285415, 3319963, 35464205, 27742471, 30018917, 1948809, 65464563, 14422441, 61394547, 8045019, 22016985},
                {14711694, 8595839, 51139887, 39195191, 44382277, 26562593, 30216739, 25054807, 51264653, 38718989, 61943855, 34274511, 16892881, 15459729, 47728605, 22872323, 17546489, 20032241, 48396869, 1230785, 36700473, 14259443, 16559241, 36431275, 65327961, 18943667, 12492499, 57942821, 26659123, 37986637},
                {20456697, 38213943, 27592243, 46583449, 43265195, 22671393, 34083021, 8711761, 410663, 7376325, 60984347, 8634705, 28924165, 45702535, 16196275, 55592765, 17446981, 51094345, 56961601, 24901025, 23597391, 15321697, 57409637, 447451, 14053599, 39277475, 3285903, 66960955, 8953041, 60024717, 34388799},
                {63324462, 64379259, 54082559, 37254961, 6139639, 19133853, 46432931, 53658101, 10037277, 30380573, 43971009, 11900815, 23559675, 59801859, 25692673, 29905023, 58695367, 20581361, 309413, 57068599, 44692539, 42767371, 41892387, 44854667, 31942329, 1278933, 14191739, 64090053, 56782785, 6502217, 1528901, 6908493},
                {45228155, 33469437, 26342007, 50530825, 21356817, 19529907, 32410541, 42010775, 31522921, 2224943, 47320979, 57794305, 16641099, 38719339, 925765, 57685021, 48404813, 42738423, 57726457, 18742945, 44921239, 58516655, 8927693, 35415931, 59735259, 24895061, 18181379, 11425057, 22944341, 12784111, 34838167, 11914913, 37916545},
                {58554458, 2435189, 16553859, 35380437, 57077365, 43022243, 24872653, 62164011, 63439681, 51013393, 10176451, 55777077, 11017123, 25634875, 38533013, 613535, 25481399, 23643133, 44213961, 40093985, 48505063, 34643277, 31328303, 10777119, 21979265, 18431241, 9872105, 1354793, 65564867, 44930599, 66165115, 22501661, 5704537, 2286039},
                {20801751, 12218307, 29430283, 23254091, 38119419, 24490039, 24774323, 5024411, 32131897, 45449873, 5016577, 35569765, 34043921, 23284685, 61224511, 26806635, 46250189, 13948101, 36243273, 43200041, 44196155, 39170897, 30826141, 10005553, 25973109, 56678503, 35096877, 59462053, 36000737, 11063439, 21118737, 1707953, 28894599, 36844751, 55420231},
                {61286308, 37899533, 42984289, 66535463, 57410135, 62627249, 59041249, 10231135, 34219659, 38441675, 20215479, 48091543, 708211, 22130715, 49909655, 31544545, 63853485, 18947197, 22339337, 12004667, 16425815, 18680785, 30452489, 20178363, 10598549, 47889049, 14838649, 21579021, 56383687, 11927503, 48027719, 231019, 40116909, 53440611, 37141753, 19626101},
                {46156341, 19579679, 42646215, 18256295, 29119489, 48041003, 49414043, 40100961, 34823887, 13374181, 3726421, 58476713, 13949621, 57381145, 36646069, 15808051, 17700445, 912361, 13446365, 29147265, 21738903, 6337335, 24120667, 59812765, 62218625, 38104943, 53114551, 17506123, 50839027, 59941209, 8587555, 15098313, 52315341, 45974123, 29480483, 15905663, 58157377},
            };

            assert(n < rets.size());
            vll ret = rets[n];
            assert(ret.size() == n);
            if (n % 2 == 1) {
                assert(solve(ret) == n);
            } else {
                assert(solve(ret) == n - 1);
            }

            vector<int> ans;
            rep(i, ret.size()) {
                assert(1 <= ret[i] && ret[i] <= 737373737);
                ans.pb(ret[i]);
            }
            return ans;

        }
        vector <int> makePart(int n) {
            vector<int> v;
            if (n&1) {
                rep(i, n) v.pb((1<<20)|i);
            } else {
                rep(i, n-1) v.pb((1<<20)|i);
                v.pb(1<<19);
            }
            return v;
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
bool KawigiEdit_RunTest(int testNum, int p0, bool hasAnswer, vector <int> p1) {
    cout << "Test " << testNum << ": [" << p0;
    cout << "]" << endl;
    AliceAndBobEasy *obj;
    vector <int> answer;
    obj = new AliceAndBobEasy();
    clock_t startTime = clock();
    answer = obj->make(p0);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << "{";
        for (int i = 0; int(p1.size()) > i; ++i) {
            if (i > 0) {
                cout << ",";
            }
            cout << p1[i];
        }
        cout << "}" << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << "{";
    for (int i = 0; int(answer.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << answer[i];
    }
    cout << "}" << endl;
    if (hasAnswer) {
        if (answer.size() != p1.size()) {
            res = false;
        } else {
            for (int i = 0; int(answer.size()) > i; ++i) {
                if (answer[i] != p1[i]) {
                    res = false;
                }
            }
        }
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
	AliceAndBobEasy *obj;
	vector <int> answer;
	obj = new AliceAndBobEasy();

    /*
    vll cand = {};
    ll n = cand.size();
    ll s = obj->solve(cand);
    if (n % 2 == 1) {
        if (s != n) {
            cout << mt(s, n) << " " << cand << endl;
            return 1;
        }
    } else {
        if (s != (n - 1)) {
            cout << mt(s, n) << " " << cand << endl;
            return 1;
        }
    }
    */
    repi(i, 1, 38) {
        auto t = obj->makePart(i);
        vll hoge;
        rep(i, t.size()) hoge.pb(t[i]);
        ll s = obj->solve(hoge);
        ll n = t.size();
        cout << mt(i, s) << hoge << endl;
        set<ll> memo;
        rep(i, n) memo.insert(hoge[i]);
        assert(memo.size() == n);
        rep(i, n) {
            cout << bitset<30>(hoge[i]) << endl;
        }
        if (n % 2 == 1) {
            if (s != n) {
                cout << mt(s, n) << " " << hoge << endl;
                return 1;
            }
        } else {
            if (s != n - 1) {
                cout << mt(s, n) << " " << hoge << endl;
                return 1;
            }
        }
    }
    return 0;

    bool all_right;
    bool disabled;
    bool tests_disabled;
    all_right = true;
    tests_disabled = false;

    int p0;
    vector <int> p1;

    /*
    // ----- test 0 -----
    disabled = false;
    p0 = 1;
    p1 = {737};
    all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 1 -----
    disabled = false;
    p0 = 2;
    p1 = {737,373};
    all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 2 -----
    disabled = false;
    p0 = 3;
    p1 = {3337,3373,3733};
    all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------
    // */
    // ----- test 2 -----
    repi(i, 1, 38) {
        disabled = false;
        p0 = i;
        p1 = {3337,3373,3733};
        all_right = (disabled || KawigiEdit_RunTest(2, p0, false, p1) ) && all_right;
        tests_disabled = tests_disabled || disabled;
    }
    // ------------------

    /*
    // ----- test 2 -----
    disabled = false;
    p0 = 37;
    p1 = {3337,3373,3733};
    all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------
    // */

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
// Alice and Bob are playing a game of NIM.
// 
// 
// The rules of NIM are as follows:
// There are several piles of stones.
// The players take alternating turns.
// In each turn, the current player selects one non-empty pile of stones and removes some stones from the pile.
// (The player must remove at least one stone. They can remove as many stones as they want, possibly all of them, but just from a single pile.)
// The game ends when all stones have been removed.
// The player who removed the last stone wins the game.
// Equivalently, the first player who is unable to make a valid move loses the game.
// 
// 
// More formally, a position in the game is an ordered sequence of pile sizes and a move consists of decrementing one of those values.
// Note that {1,2,3} and {3,2,1} are considered different positions, and thus the move from {3,2,3} to {1,2,3} and the move from {3,2,3} to {3,2,1} are two different moves.
// 
// 
// Given a position, a move from that position is called a winning move if the player who plays that move can guarantee that from the resulting position they can win the game, even if their opponent plays optimally.
// 
// 
// You are given the int N.
// Construct and return any position such that:
// 
// 
// There are exactly N piles of stones.
// Each pile has between 1 and 737,373,737 stones, inclusive.
// All pile sizes are distinct.
// The number of different winning moves from this position is as large as possible. (I.e., no other position that satisfies the previous items has more winning moves.)
// 
// 
// DEFINITION
// Class:AliceAndBobEasy
// Method:make
// Parameters:int
// Returns:vector <int>
// Method signature:vector <int> make(int N)
// 
// 
// CONSTRAINTS
// -N will be between 1 and 37, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 1
// 
// Returns: {737 }
// 
// In this position the active player has exactly one winning move: take all the stones.
// 
// 1)
// 2
// 
// Returns: {737, 373 }
// 
// In this position there is also exactly one winning move: take 364 stones from pile 0.
// There is no other valid position with more than one valid move.
// 
// 2)
// 3
// 
// Returns: {3337, 3373, 3733 }
// 
// Note that the pile sizes must be distinct. For example, { 373, 373, 373 } is not a valid answer.
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
