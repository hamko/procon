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
#define ZERO(a) memset(a,0,sizeof(a))
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
#define exists find_if
#define forall all_of

using ll = long long; using vll = vector<ll>; /*using vvll = vector<vll>;*/ using P = pair<ll, ll>;
using ld = long double;  using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>; vll conv(vi& v) { vll r(v.size()); rep(i, v.size()) r[i] = v[i]; return r; }

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;
#define ldout fixed << setprecision(40) 

inline void input(int &v){ v=0;char c=0;int p=1; while(c<'0' || c>'9'){if(c=='-')p=-1;c=getchar();} while(c>='0' && c<='9'){v=(v<<3)+(v<<1)+c-'0';c=getchar();} v*=p; }
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template<size_t...> struct seq{}; template<size_t N, size_t... Is> struct gen_seq : gen_seq<N-1, N-1, Is...>{}; template<size_t... Is> struct gen_seq<0, Is...> : seq<Is...>{};
template<class Ch, class Tr, class Tuple, size_t... Is>
void print_tuple(basic_ostream<Ch,Tr>& os, Tuple const& t, seq<Is...>){ using s = int[]; (void)s{0, (void(os << (Is == 0? "" : ", ") << get<Is>(t)), 0)...}; }
template<class Ch, class Tr, class... Args> 
auto operator<<(basic_ostream<Ch, Tr>& os, tuple<Args...> const& t) -> basic_ostream<Ch, Tr>& { os << "("; print_tuple(os, t, gen_seq<sizeof...(Args)>()); return os << ")"; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const unordered_set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U, typename V>  ostream &operator<<(ostream &o, const unordered_map<T, U, V> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it; o << "]";  return o; }
vector<int> range(const int x, const int y) { vector<int> v(y - x + 1); iota(v.begin(), v.end(), x); return v; }
template <typename T> istream& operator>>(istream& i, vector<T>& o) { rep(j, o.size()) i >> o[j]; return i;}
string bits_to_string(ll input, ll n=64) { string s; rep(i, n) s += '0' + !!(input & (1ll << i)); reverse(all(s)); return s; }
template <typename T> ostream &operator<<(ostream &o, const priority_queue<T> &v) { auto tmp = v; while (tmp.size()) { auto x = tmp.top(); tmp.pop(); o << x << " ";} o << endl; return o; }

template <typename T> unordered_map<T, ll> counter(vector<T> vec){unordered_map<T, ll> ret; for (auto&& x : vec) ret[x]++; return ret;};
string substr(string s, P x) {return s.substr(x.fi, x.se - x.fi); }

size_t random_seed; namespace std { using argument_type = P; template<> struct hash<argument_type> { size_t operator()(argument_type const& x) const { size_t seed = random_seed; seed ^= hash<ll>{}(x.fi); seed ^= (hash<ll>{}(x.se) << 1); return seed; } }; }; // hash for various class
namespace myhash{ const int Bsizes[]={3,9,13,17,21,25,29,33,37,41,45,49,53,57,61,65,69,73,77,81}; const int xor_nums[]={0x100007d1,0x5ff049c9,0x14560859,0x07087fef,0x3e277d49,0x4dba1f17,0x709c5988,0x05904258,0x1aa71872,0x238819b3,0x7b002bb7,0x1cf91302,0x0012290a,0x1083576b,0x76473e49,0x3d86295b,0x20536814,0x08634f4d,0x115405e8,0x0e6359f2}; const int hash_key=xor_nums[rand()%20]; const int mod_key=xor_nums[rand()%20]; template <typename T> struct myhash{ std::size_t operator()(const T& val) const { return (hash<T>{}(val)%mod_key)^hash_key; } }; };
template <typename T> class uset:public std::unordered_set<T,myhash::myhash<T>> { using SET=std::unordered_set<T,myhash::myhash<T>>; public: uset():SET(){SET::rehash(myhash::Bsizes[rand()%20]);} };
uint32_t randxor() { static uint32_t x=1+(uint32_t)random_seed,y=362436069,z=521288629,w=88675123; uint32_t t; t=(x^(x<<11));x=y;y=z;z=w; return( w=(w^(w>>19))^(t^(t>>8)) ); }
struct timeval start; double sec() { struct timeval tv; gettimeofday(&tv, NULL); return (tv.tv_sec - start.tv_sec) + (tv.tv_usec - start.tv_usec) * 1e-6; }
struct init_{init_(){ gettimeofday(&start, NULL); ios::sync_with_stdio(false); cin.tie(0); struct timeval myTime; struct tm *time_st; gettimeofday(&myTime, NULL); time_st = localtime(&myTime.tv_sec); srand(myTime.tv_usec); random_seed = RAND_MAX / 2 + rand() / 2; }} init__;
#define rand randxor

ll n;
vll a, x, y;

// 状態1<=j<=nの確定のときに、状態0<=k<jからの遷移kを選ぶ時のコスト
ll w_InverseQuadrangleInequality(ll k, ll j) {
    assert(1<=j&&j<=n);
    assert(0<=k&&k<j);
    // 点P, Qがそれぞれn個ある。
    // 点P_i = (a[k], 0)
    // 点Q_i = (x[k], y[i])
    //
    // この時、cost[i][j] = 点P_iと点Q_iの二乗距離
    // cost[i][j]は順QIを満たすことが知られている
    return -((a[j-1]-x[k])*(a[j-1]-x[k]) + y[k]*y[k]);
}
// 状態1<=j<=nの確定のときに、状態0<=k<iからの遷移kを選ぶ時のコスト
ll w_QuadrangleInequality(ll k, ll j) {
    assert(1<=j&&j<=n);
    assert(0<=k&&k<j);
    // 点P, Qがそれぞれn個ある。
    // 点P_i = (a[k], 0)
    // 点Q_i = (x[k], y[i])
    //
    // この時、cost[i][j] = 点P_iと点Q_iの二乗距離
    // cost[i][j]は順QIを満たすことが知られている
    return +((a[j-1]-x[k])*(a[j-1]-x[k]) + y[k]*y[k]);
}



using vvll = vector<vector<ll>>;
bool isInverseQuadrangleInequality(function<ll(ll, ll)> w) {
    repi(i, 1, n) repi(j, i, n) repi(k, j, n) repi(l, k, n) {
        if (w(i, l) + w(j, k) <= w(i, k) + w(j, l)) {
        } else {
            cout << i << " " << j << " " << k << " " << l << " " << "HIT" << endl;
            return 0;
        }
    }
    return 1;
}
bool isQuadrangleInequality(function<ll(ll, ll)> w) {
    repi(i, 1, n) repi(j, i, n) repi(k, j, n) repi(l, k, n) {
        if (w(i, l) + w(j, k) >= w(i, k) + w(j, l)) {
        } else {
            cout << i << " " << j << " " << k << " " << l << " " << "HIT" << endl;
            return 0;
        }
    }
    return 1;
}


ll solveBrutal(ll dp0, function<ll(ll, ll)> w) {
    vll dp(n+1, INF);
    dp[0] = dp0;
    repi(i, 1, n+1) {
        rep(j, i) {
            chmin(dp[i], dp[j] + w(j, i));
        }
    }
//    cout << dp <<"Brutal"<< endl;
    return dp[n];
}

// D. Eppstein, Z. Galil, and R. Giancalco: "Speeding up Dynamic Programming", 29th IEEE Symposium on Foundations of Computer Science, White Plains, New York, pp. 488-496, 1988.
// 
// dp[j] = min_{0 <= k < j} (dp[k] + w(k, j)) (0 <= j <= n)
// wが逆Quadrangle Inequalityを満たす場合のO(n log n)あるいはO(n)解法
//
// given: 
// dp[0] 
//
// given: 
// wは0-indexed monge n*n行列 (逆Quadrangle Ineqalityを満たす)
//
// この実装は """"逆"""" Quadrangle Inequalityであることに注意！！！！
// 逆ではないQuadrangle Inequalityを満たす場合は、wの全要素に-1をかけておくと良い。
//
// 一般にO(n log n)
// Closest Zero Propertyが満たされていて、hをO(1)自前実装するならばO(n)
ll solveInverseQuadrangleInequality(ll dp0, function<ll(ll, ll)> w) {
    vll dp(n+1);
    dp[0] = dp0;

    // 状態rの確定のために、遷移kをしようとした時の候補
    // k in [0, n), r in [1, n]
    auto C = [&](ll k, ll r) { 
        return dp[k] + w(k, r);
    }; 

    // C(l, h) <= C(k, h)となるような最小のk < h <= n.
    // もしなければn+1を返す。
    //
    // wがClosest Zero Propertyを満たしていて、これを自前実装するならばO(1)
    // デフォルトでO(log n)
    auto h = [&](ll l, ll k) { 
//        if (!(C(l, n) <= C(k, n))) 
        if (!(w(l, n) - w(k, n) <= dp[k] - dp[l])) 
            return n+1;

        ll ng = k, ok = n;
        while (ok - ng > 1) {
            ll mid = (ok + ng) / 2;
//            if (C(l, mid) <= C(k, mid)) 
            if (w(l, mid) - w(k, mid) <= dp[k] - dp[l])
                ok = mid; 
            else 
                ng = mid;
        }
        return ok;
        /*
        // Brutal
        ll ret = -1;
        repi(hc, k+1, n+1) { 
            if (C(l, hc) <= C(k, hc)) {
                ret = hc;
                break;
            }
        }
        if (ret < 0)
            ret = n + 1;
        return ret;
//        assert(ret == ok);
//        */
    };

    vector<P> s = {P(0, n+1)};
    repi(j, 1, n+1) {
        ll l = s.back().fi;
        if (C(j-1, j) >= C(l, j)) {
            dp[j] = C(l, j);
        } else {
            dp[j] = C(j-1, j);
            while (s.size() && C(j-1, s.back().se - 1) < C(s.back().fi, s.back().se-1)) {
                s.pop_back();
            }
            if (s.size() == 0) {
                s.pb(P(j-1, n+1));
            } else {
                ll hc = h(s.back().fi, j-1);
                s.pb(P(j-1, hc));
            }
        }
        if (s.back().se == j+1) 
            s.pop_back();
    }
//    cout << dp << "Eppstein" << endl;
    return dp[n];
}

// Zvi Galil; Raffaele Giancarlo, "Speeding up dynamic programming with applications to molecular biology", 1987
// D. Eppstein, Z. Galil, and R. Giancalco: "Speeding up Dynamic Programming", 29th IEEE Symposium on Foundations of Computer Science, White Plains, New York, pp. 488-496, 1988.
// 
// dp[j] = min_{0 <= k < j} (dp[k] + w(k, j)) (0 <= j <= n)
// wが逆Quadrangle Inequalityを満たす場合のO(n log n)あるいはO(n)解法
//
// given: 
// dp[0] 
//
// given: 
// wは0-indexed monge n*n行列 (逆Quadrangle Ineqalityを満たす)
//
// この実装は """"逆"""" Quadrangle Inequalityであることに注意！！！！
// 逆ではないQuadrangle Inequalityを満たす場合は、wの全要素に-1をかけておくと良い。
//
// 一般にO(n log n)
// Closest Zero Propertyが満たされていて、hをO(1)自前実装するならばO(n)
ll solveQuadrangleInequality(ll dp0, function<ll(ll, ll)> w) {
    vll dp(n+1);
    dp[0] = dp0;

    // 状態rの確定のために、遷移kをしようとした時の候補
    // k in [0, n), r in [1, n]
    auto C = [&](ll k, ll r) { 
        assert(0<=k&&k<n && 1<=r<=n);
        return dp[k] + w(k, r);
    }; 

    // C(l, h) <= C(k, h)となるような最小のl < h <= n. (k < l < n)
    // もしなければn+1を返す。
    //
    // wがClosest Zero Propertyを満たしていて、これを自前実装するならばO(1)
    // デフォルトでO(log n)
    auto h = [&](ll l, ll k) { 
        assert(k<l&&l<n);
        if (!(w(l, n) - w(k, n) <= dp[k] - dp[l])) 
            return n+1;

        ll ng = l, ok = n;
        while (ok - ng > 1) {
            ll mid = (ok + ng) / 2;
            if (w(l, mid) - w(k, mid) <= dp[k] - dp[l]) 
                ok = mid; 
            else 
                ng = mid;
        }
        return ok;

        // Brutal
        /*
        ll ret = -1;
        repi(hc, l+1, n+1) { 
            if (w(l, hc) - w(k, hc) <= dp[k] - dp[l]) {
                ret = hc;
                break;
            }
        }
        if (ret < 0)
            ret = n + 1;
        assert(ret == ok);
        return ret;
        */
    };

    deque<P> Q = {P(0, 1)};
    repi(j, 1, n+1) {
        ll l = Q.back().fi; // 最小のつもり
        if (C(j-1, j) <= C(l, j)) {
            dp[j] = C(j-1, j);
            Q.clear();
            Q.push_back(P(j-1, j+1));
        } else {
            dp[j] = C(l, j);
            while (C(j-1, Q[0].se) <= C(Q[0].fi, Q[0].se))  
                Q.pop_front();
            ll hc = h(j-1, Q[0].fi); 
            if (hc != n + 1)
                Q.push_front(P(j-1, hc));
            if (Q.size() >= 2 && j + 1 == Q[Q.size()-2].se)
                Q.pop_back();
            else 
                Q.back().se++;
        }
    }

//    cout << dp << "Eppstein" << endl;
    return dp[n];
}


void compareMax(void) {
    function<ll(ll, ll)> w = w_InverseQuadrangleInequality;
    ll ret_m = solveInverseQuadrangleInequality(0, w);
#if 1
    ll ret_b = solveBrutal(0, w);
    if (ret_b != ret_m) {
        cout << "Not Match" << endl;
        cout << "Jury : " << ret_b << ", Participant : " << ret_m<<endl;
        cout << a << endl;
        cout << x << endl;
        cout << y << endl;

        repi(i, 1, n+1) { 
            rep(j, i) {
                cout << w(j, i) << "\t";
            }
            cout << endl;
        }

        ll is_monge = isInverseQuadrangleInequality(w);
        if (is_monge) {
            cout << "Monge OK" << endl;
        } else {
            cout << "NOT Monge" << endl;
        }
    }
    assert(ret_b == ret_m);
#endif
    cout << -ret_m << endl;
}

void compareMin(void) {
    function<ll(ll, ll)> w = w_QuadrangleInequality;
    ll ret_m = solveQuadrangleInequality(0, w);
#if 1
    ll ret_b = solveBrutal(0, w);
    if (ret_b != ret_m) {
        cout << "Not Match" << endl;
        cout << "Jury : " << ret_b << ", Participant : " << ret_m<<endl;
        cout << a << endl;
        cout << x << endl;
        cout << y << endl;

        repi(i, 1, n+1) { 
            rep(j, i) {
                cout << w(j, i) << "\t";
            }
            cout << endl;
        }

        ll is_monge = isQuadrangleInequality(w);
        if (is_monge) {
            cout << "Monge OK" << endl;
        } else {
            cout << "NOT Monge" << endl;
        }
    }
    assert(ret_b == ret_m);
#endif
    cout << ret_m << endl;
}


int main(void) {
    cin >> n;
    a.resize(n);
    x.resize(n);
    y.resize(n);
    cin >> a;
    cin >> x;
    cin >> y;
    assert(1<=n&&n<=1e5);
    rep(i, n) {
        assert(0<=a[i]&&a[i]<=1e5);
        assert(0<=x[i]&&x[i]<=1e5);
        assert(0<=y[i]&&y[i]<=1e5);
    }
    compareMin();
    compareMax();

    return 0;
}
