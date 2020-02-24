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

class ArmySize {
    public:
        vector <string> part(vector <string> units) {
            return {};
        }
        vector <string> getSum(vector <string> units) {
            vll m = {1, 5, 10, 20, 50, 100, 250, 500, 1000};
            vll M = {4, 9, 19, 49, 99, 249, 499, 999, 10000};

            map<string, ll> memo;
            memo["Few"] = 0;
            memo["Several"] = 1;
            memo["Pack"] = 2;
            memo["Lots"] = 3;
            memo["Horde"] = 4; memo["Throng"] =5; memo["Swarm"] = 6;
            memo[ "Zounds"] = 7; memo["Legion"] = 8;

            vector<string> s(10);
            for (auto x : memo) {
                s[x.se] = x.fi;
            }

            map<ll, string> hoge;
            rep(i, m.size()) {
                repi(j, m[i], M[i]+1) {
                    hoge[j] = s[i];
                }
            }


            ll x = 0, y = 0;
            rep(i, units.size()) {
                x += m[memo[units[i]]];
                y += M[memo[units[i]]];
            }

            set<string> ret;
            repi(i, x, y+1) if (hoge.count(i)) {
                ret.insert(hoge[i]);
            }

            vector<string> xx;
            for (auto x : ret) {
                xx.pb(x);
            }
            return xx;
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
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, vector <string> p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	ArmySize *obj;
	vector <string> answer;
	obj = new ArmySize();
	clock_t startTime = clock();
	answer = obj->getSum(p0);
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
			cout << "\"" << p1[i] << "\"";
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << answer[i] << "\"";
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
    while (1) {
        vector<string> input; 
        vector<string> ss = {"Few", "Several", "Pack", "Lots", "Horde", "Throng", "Swarm", "Zounds","Legion"};
        repi(i, 1, 2 + rand() % 7) {
            input.pb(ss[rand() % ss.size()]);
        }
        ArmySize *obj;
        obj = new ArmySize();
        vector <string> part = obj->part(input);
        sort(all(part));
        vector <string> answer = obj->getSum(input);
        sort(all(answer));
        if (part != answer) {
            cout << input << "#HIT" << endl;
            cout << part << " " << answer << endl;
        }
    }

    bool all_right;
    bool disabled;
    bool tests_disabled;
	all_right = true;
	tests_disabled = false;
	
	vector <string> p0;
	vector <string> p1;
	
	// ----- test 0 -----
	disabled = false;
	p0 = {"Lots","Lots"};
	p1 = {"Lots","Horde"};
    sort(all(p1));
	all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {"Throng","Few","Few"};
	p1 = {"Throng","Swarm"};
    sort(all(p1));
	all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {"Few","Few","Few","Few","Several"};
	p1 = {"Several","Pack","Lots"};
    sort(all(p1));
	all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {"Swarm","Pack","Horde"};
	p1 = {"Swarm","Zounds"};
    sort(all(p1));
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {"Horde","Horde","Zounds","Pack"};
	p1 = {"Zounds","Legion"};
    sort(all(p1));
	all_right = (disabled || KawigiEdit_RunTest(4, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 5 -----
	disabled = false;
	p0 = {"Legion","Horde","Swarm","Several"};
	p1 = {"Legion"};
    sort(all(p1));
	all_right = (disabled || KawigiEdit_RunTest(5, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
    //
		// ----- test 5 -----
	disabled = false;
	p0 = {"Legion","Legion","Legion","Legion","Legion","Legion","Legion",};
	p1 = {"Legion"};
    sort(all(p1));
	all_right = (disabled || KawigiEdit_RunTest(5, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
    //
			// ----- test 5 -----
	disabled = false;
	p0 = {"Legion"};
	p1 = {"Legion"};
    sort(all(p1));
	all_right = (disabled || KawigiEdit_RunTest(5, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
				// ----- test 5 -----
	disabled = false;
	p0 = {"Pack"};
	p1 = {"Pack"};
    sort(all(p1));
	all_right = (disabled || KawigiEdit_RunTest(5, p0, true, p1) ) && all_right;
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
// In a computer game called "Zeroes of Blight and Tragic", players command heroes who fight each other in epic battles.
// The heroes do not fight each other directly.
// Instead, each hero leads an army that consists of many distinct types of creatures.
// 
// 
// 
// Upon inspecting an enemy hero, a player learns an approximate composition of the hero's army.
// The player can then use this information to decide whether to attack that hero or flee.
// 
// 
// 
// When describing the number of creatures in an army unit, the game uses a fixed set of words (called quantifiers).
// Each word represents a range of values, as listed below.
// For example, the word "Horde" can represent any number between 50 and 99, inclusive.
// 
// 
// 
// The quantifiers are as follows:
// 
// Few: 1-4
// Several: 5-9
// Pack: 10-19
// Lots: 20-49
// Horde: 50-99
// Throng: 100-249
// Swarm: 250-499
// Zounds: 500-999
// Legion: 1000 or more
// 
// 
// 
// 
// We are examining an enemy hero.
// You are given a vector <string> units.
// Each element of units is a quantifier that represents the size of one unit of the hero's army.
// 
// 
// 
// Consider the following statement:
// "In total, there are Q creatures in this hero's army."
// In this statement, Q is one of the quantifiers mentioned above.
// 
// 
// 
// Find all quantifiers for which that the statement may be true.
// Return a vector <string> containing those quantifiers.
// 
// 
// 
// If there are multiple quantifiers that may correspond to the size of the hero's army, you have to output all of them.
// You may output them in any order, but you have to output each valid quantifier exactly once.
// Also, note that the return value is case-sensitive.
// 
// 
// DEFINITION
// Class:ArmySize
// Method:getSum
// Parameters:vector <string>
// Returns:vector <string>
// Method signature:vector <string> getSum(vector <string> units)
// 
// 
// CONSTRAINTS
// -units will contain between 1 and 7 elements, inclusive.
// -Each element of units will be one of "Few", "Several", "Pack", "Lots", "Horde", "Throng", "Swarm", "Zounds", and "Legion".
// 
// 
// EXAMPLES
// 
// 0)
// {"Lots","Lots"}
// 
// Returns: {"Lots", "Horde" }
// 
// 
// This hero has, for example, "Lots" of skeletons and "Lots" of ghouls.
// In other words, there are somewhere between 20 and 49 skeletons and somewhere between 20 and 49 ghouls.
// 
// 
// 
// What quantifier can be used to describe the total number of creatures in this hero's army?
// 
// 
// 
// One possibility is "Lots". For example, if there are 22 skeletons and 24 ghouls, the total number of creatures is 22+24 = 46, which still falls into the range for "Lots".
// 
// 
// 
// Another possibility is "Horde". For example, if there are 40 skeletons and 45 ghouls, we have a total of 85 creatures.
// 
// 
// 
// There are no other possibilities. For example, "Throng" cannot be true, because this hero's army will surely have fewer than 100 creatures.
// 
// 
// 
// 1)
// {"Throng","Few","Few"}
// 
// Returns: {"Throng", "Swarm" }
// 
// The total size of this army is somewhere between 102 and 257 creatures, inclusive, so it's either a "Throng" or a "Swarm".
// 
// 2)
// {"Few","Few","Few","Few","Several"}
// 
// Returns: {"Several", "Pack", "Lots" }
// 
// Here we have three possibilities:
// 
// This hero's army may have a total of 9 creatures, in which case the correct quantifier is "Several".
// This hero's army may have anywhere between 10 and 19 creatures, in which case the correct quantifier is "Pack".
// This hero's army may have anywhere between 20 and 25 creatures, in which case the correct quantifier is "Lots".
// 
// 
// 3)
// {"Swarm","Pack","Horde"}
// 
// Returns: {"Swarm", "Zounds" }
// 
// 
// 
// 4)
// {"Horde","Horde","Zounds","Pack"}
// 
// Returns: {"Zounds", "Legion" }
// 
// 
// 
// 5)
// {"Legion","Horde","Swarm","Several"}
// 
// Returns: {"Legion" }
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
