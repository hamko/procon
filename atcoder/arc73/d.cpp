#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define repi(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
using ll = long long; using vll = vector<ll>; using vvll = vector<vll>; using P = pair<ll, ll>;
#define INF (ll)1e18

#define SIZE 2001
ll n, W; 
ll best_feasible = 0;
vector<P> ab;
vll v, w;

// [0, i)がb[0, i)のように確定していて、その後が不確定である時、線形緩和問題を解く
// 返り値(double, bool) = (緩和問題の最適解, その最適解が元問題の制約を厳密に満たすか)
pair<double, bool> solveRelaxationProblem(ll i, bitset<SIZE>& b) {
    double ans = 0;
    double w_now = W;
    rep(j, i) ans += b[j] * v[j], w_now -= b[j] * w[j];
    bool faf = 1;
    repi(j, i, n) {
        double tmp = min<double>(w_now, w[j]);
        faf &= (tmp == 0 || tmp == w[j]);
        w_now -= tmp;
        ans += tmp * (v[j] * 1.0 / w[j]);
    }
    return make_pair(ans, faf);

}

// [0, i)がb[0, i)のように確定していてその後が不確定である時、線形緩和問題を解く
// （負荷情報として、確定しているところの価値総和がv_now, 重さ総和w_nowを持っておく）
//
// 返り値double = 最適解
ll dfs(ll i, bitset<SIZE>& b, ll v_now, ll w_now) {
//    string s = b.to_string(); reverse(begin(s), end(s)); cout << s << endl;
    if (i == n) { best_feasible = max<ll>(best_feasible, v_now); return v_now; }

    auto relax_p = solveRelaxationProblem(i, b);
    double relax = relax_p.first; 
    double satisfiability = relax_p.second;

    if (satisfiability) { best_feasible = max<ll>(best_feasible, relax); return relax; } // 緩和問題の解を与える選び方が元問題の制約を満たしているので、それが最適でもある
    if (relax < best_feasible) { return -INF; } // 緩和問題の解が、今までの最善許容解に達さないので、探索しても無駄

    ll tmp = -INF;

    // 解がありそうな方を先に分岐するのが極めて重要！今回、0->1の順番で分岐するとTLEする。
    // 1を分岐
    if (w_now+w[i]<=W) {
        b[i] = 1;
        chmax(tmp, dfs(i+1, b, v_now+v[i], w_now+w[i]));
        b[i] = 0;
        chmax(best_feasible, tmp);
    }
    // 0を分岐
    chmax(tmp, dfs(i+1, b, v_now, w_now));
    chmax(best_feasible, tmp);

    return tmp;
}
int main(void) {
    cin >> n >> W;
    ab.resize(n); rep(i, n) cin >> ab[i].second >> ab[i].first;
    sort(ab.begin(), ab.end(), [&](P l, P r) { return l.first*r.second>r.first*l.second; });
    v = vll(n), w = vll(n);
    rep(i, n) {
        v[i] = ab[i].first;
        w[i] = ab[i].second;
    }

    ll w_now = W;
    rep(i, n) {
        if (w[i] <= w_now) {
            w_now -= w[i];
            best_feasible += v[i];
        }
    }
    
    bitset<SIZE> b;
    cout << dfs(0, b, 0, 0) << endl;;

    return 0;
}
