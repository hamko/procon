#include <cassert>
#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <utility>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <functional>
#include <numeric>
#include <complex>
#include <iomanip>

using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mt make_tuple
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

using ll = long long; using ld = long double; using vll = vector<ll>; using vvll = vector<vll>; using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>;
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
#define VN(v) # v
#define print(a) cout << a << "#" << VN(a) << endl;

#define bitcount(n) __builtin_popcount(n)

#define debug(n) cout << (n) << endl;

#define PREC(n) setprecision(n)
#define DOTPREC(n) fixed << setprecision(n)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;

#define fst first
#define scd second
#define PB push_back
#define MP make_pair
#define rep1(i,x) for(int i=1;i<=(x);++i)
#define rrep(i,x) for(int i=(x)-1;i>=0;--i)
#define rrep1(i,x) for(int i=(x);i>=1;--i)
#define FOR(i,a,x) for(int i=(a);i<(x);++i)
#define rall(a) a.rbegin(),a.rend()

#define omajinai ios::sync_with_stdio(false); cin.tie(0)

template<typename T> bool chmax(T&a,T b) { if(a < b) {a = b; return true;} return false;}
template<typename T> bool chmin(T&a,T b) { if(a > b) {a = b; return true;} return false;}

const int inf = 1e9;
const ll linf = 3e18;
const double eps = 1e-9;

const ll MOD = 1000000007;

template<typename T> 
bool intersect(vector<T> &A, vector<T> &B, vector<T> &C, vector<T> &D) {
    if (((A[0] - B[0]) * (C[1] - A[1]) + (A[1] - B[1]) * (A[0] - C[0])) *
            ((A[0] - B[0]) * (D[1] - A[1]) + (A[1] - B[1]) * (A[0] - D[0])) < 0) {
        if (((C[0] - D[0]) * (A[1] - C[1]) + (C[1] - D[1]) * (C[0] - A[0])) *
                ((C[0] - D[0]) * (B[1] - C[1]) + (C[1] - D[1]) * (C[0] - B[0])) < 0) {
            return 1;
        } else {return 0;}
    } else {
        return 0;
    }
}

int main() {
    vector<int> AI(2); vector<int> BI(2);
    int s = 300;
    AI[0] =  (rand() % s) * (rand() % 2 ? 1 : -1);
    BI[0] =  (rand() % s) * (rand() % 2 ? 1 : -1);
    AI[1] =  (rand() % s) * (rand() % 2 ? 1 : -1);
    BI[1] =  (rand() % s) * (rand() % 2 ? 1 : -1);
    vector<double> A = {(double)AI[0], (double)AI[1]}; vector<double> B = {(double)BI[0], (double)BI[1]};

    vector<double> coordinate1(2);
    vector<double> coordinate2(2);
    vector<int> coordinateI1(2);
    vector<int> coordinateI2(2);

    rep(i, 1000000) {
        int a = (rand() % s) * (rand() % 2 ? 1 : -1);
        int b = (rand() % s) * (rand() % 2 ? 1 : -1);
        int c = (rand() % s) * (rand() % 2 ? 1 : -1);
        int d = (rand() % s) * (rand() % 2 ? 1 : -1);
        coordinate1[0] = a;
        coordinate1[1] = b;
        coordinate2[0] = c;
        coordinate2[1] = d;
        coordinateI1[0] = a;
        coordinateI1[1] = b;
        coordinateI2[0] = c;
        coordinateI2[1] = d;


        bool Int = intersect(AI, BI, coordinateI1, coordinateI2);
        bool Double = intersect(A, B, coordinate1, coordinate2);
        if (Int != Double) {
            cout << coordinateI1 << " " << coordinateI2 << " : " <<  Int << " " << Double << endl;
        }
    }

    return 0;
}
