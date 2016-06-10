#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { if (!v.empty()) { o << '['; copy(v.begin(), v.end(), ostream_iterator<T>(o, ", ")); o << "\b\b]"; } return o; }
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;
typedef pair<ll, ll> P;

static const double EPS = 1e-14;
static const long long INF = 1e18;
#define MAX_N 100005


// 整数二分探索
// O(log(range))
// f: 単調増加関数. 000111, 111111, 000000を許容する（11110000で探索したい場合は、自分でfを反転すること）
// 閉区間[rl, rr]から単調関数fを満たす最小の数を返す。
// 全て0ならrr+1を返す！
ll BinarySearch(ll rl, ll rr, function<bool(ll)> f) { 
    ll lo = rl-1, ro = rr+1;
    while (ro - lo != 1) {
        ll m = (lo + ro) / 2; 
        ((m!=rl-1&&f(m))?ro:lo)=m; 
    }
    return ro;
}
void BinarySearchInteractive(ll rl, ll rr, function<bool(ll)> f) { 
    while (1) {
        cout << "####" << endl;
        ll tmp; cin >> tmp;
        if (rl > tmp) {cout << "Out of range: too small" << endl; continue; }
        if (rr < tmp) {cout << "Out of range: too large" << endl; continue; }
        ll ret = f(tmp); cout << tmp << " : " << ret << endl;
    }
}
void BinarySearchPrint(ll rl, ll rr, function<bool(ll)> f) { 
    for (int i = rl; i <= rr; i++) cout << f(i); cout << endl;
}
void BinarySearchAssert(ll rl, ll rr, function<bool(ll)> f) { 
    bool p = false;
    for (int i = rl; i <= rr; i++) {
        bool t = f(i);
        if (p && !t) cerr << i << ": F NOT MONOTONIC INCREASE" << endl, exit(1);
        p |= t;
    }
}

// 浮動小数点二分探索
ld BinarySearchReal(ld rl, ld rr, function<bool(ld)> f) { 
    rep(i, 200) { ld m = (rl + rr) / 2; f(m)?rr=m:rl=m; }
    return rl;
}
void BinarySearchRealInteractive(ld rl, ld rr, function<bool(ld)> f) { 
    while (1) {
        cout << "####" << endl;
        ld tmp; cin >> tmp;
        if (rl > tmp) {cout << "Out of range: too small" << endl; continue; }
        if (rr < tmp) {cout << "Out of range: too large" << endl; continue; }
        ld ret = f(tmp); cout << tmp << " : " << ret << endl;
    }
}

int main(void) {
    /**********テンプレート**********/
    {
        auto f = [&](ll x){
            return c - 10 * x <= A;
        };
        BinarySearchPrint(0, INF, f);
//        BinarySearchInteractive(0, INF, f);
        ll ret = BinarySearch(0, INF, f);
    }
    /**********整数の二分探索**********/
    {
        vector<ll> a = {0, 0, 0, 0, 1, 1};
        auto f = [&](ll x){return !!a[x];};
        BinarySearchPrint(0, a.size()-1, f);
        cout << BinarySearch(0, a.size()-1, f) << endl;
    }
    {
        vector<ll> a = {1, 1, 1, 1, 1, 1};
        BinarySearchPrint(0, a.size()-1, [&](ll x){return !!a[x];});
        cout << BinarySearch(0, a.size()-1, [&](ll x){return !!a[x];}) << endl;
    }
    {
        vector<ll> a = {0, 0, 0, 0, 0, 0};
        BinarySearchPrint(0, a.size()-1, [&](ll x){return !!a[x];});
        cout << BinarySearch(0, a.size()-1, [&](ll x){return !!a[x];}) << endl;
    }

    /**********浮動小数点の二分探索**********/
    {
        auto f = [&](ld x){return x * x > 2;};
        cout << BinarySearchReal(0.0l, 3.0l, f) << endl;
    }

    /**********実践的課題**********/
    // there exist a in [0, A] and b in [0, B]
    // s.t. a + 10 * b = c
    {
        ll A = 13, B = 7, c = 42;
        auto f = [&](ll x){return c - 10 * x <= A;};
        BinarySearchPrint(0, min(c / 10, B), f); // [0, min(c/10, B)]に範囲を限定して初めて単調増加になる！
        ll ret = BinarySearch(0, min(c / 10, B), f);

        cout << "a + 10 * b = " << c << " (a in [0, " << A << "], b in [0, " << B << "]" << endl;
        if (ret == min(c / 10, B) + 1) 
            cout << "Not found" << endl;
        else 
            cout << "Solution with minimum b: a = " << c - 10 * ret << ", b = " << ret << endl;

        cout << "Let's check f!" << endl;
        BinarySearchInteractive(0, min(c / 10, B), f);
    }

    // 状態付き二分探索
    // 二分探索内の全探索の場合、逆にすると枝刈りできて高速に
    // 具体的には、探索範囲n状態数sとするとO(s log n)がO(s + log n log s)
    {
        vector<vector<ll>> data = {
            {0, 2, 6, 4, 4, 1, 3, 7, 3},
            {0, 4, 3, 5, 9, 1, 3, 7, 5},
            {0, 4, 6, 4, 4, 2, 8, 0, 5},
        };
        vector<ll> states = {0, 1, 2};

        ll s;
        auto f = [&](ll x) { 
            return data[s][x] % 2;
        };

        // there exists
        {
            ll r = 0; // 最大のupper bound
            for (auto s_ : states) {
                s = s_;
                if (f(data[s][r-1])) continue; // rを伸ばすためには少なくとも今までの最高と同じところまでは満たしているべき
                ll tmp = BinarySearch(0, data[0].size(), f);
                chmax(r, tmp);
            }
            cout << r << endl;
        }

        // for all
        {
            ll r = data[0].size(); // 最大のupper bound
            for (auto s_ : states) {
                s = s_;
                if (!f(data[s][r-1])) continue; // rを狭めるためには少なくとも今までの最高と同じところは満たしていないべき
                ll tmp = BinarySearch(0, data[0].size(), f);
                chmin(r, tmp);
            }
            cout << r << endl;
        }
    }

    return 0;
}

