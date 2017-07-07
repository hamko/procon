#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back

using ll = long long; using vll = vector<ll>; using vvll = vector<vll>; using P = pair<ll, ll>;
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }

// ちょうどi個を見終えて、残りがsで、現在の配列がaである場合。
ll c = 0;
void f(vll& x) {
//    cout << x << endl;
}
void dfs(ll s, ll i, vll& a, const vll& amax, const int target_sum, vll& amaxsum) {
    if (amaxsum.back() - amaxsum[i] < s) return; // 枝刈り
    if (s && i == a.size()) return;
    if (!s) {
//        assert(accumulate(a.begin(), a.end(), 0ll) == target_sum);
        c++;
        f(x);
        return;
    }
    rep(j, min(s, amax[i])+1) {
        a[i] = j;
        dfs(s-j, i+1, a, amax, target_sum, amaxsum);
        a[i] = 0;
    }
}
void start_dfs(const vll amax, const int target_sum) {
    c = 0;
    ll s = target_sum; vll a(amax.size()); 
    vll amaxsum(amax.size()+1);
    rep(i, amax.size()) amaxsum[i+1] = amaxsum[i] + amax[i];
    dfs(s, 0, a, amax, target_sum, amaxsum);
}

int main(void) {
    ll x; cin >> x;
    vll N;
    rep(i, 10) N.pb(5);

    {
        cout << "dfs" << endl;
        start_dfs(N, x);
        cout << c << endl;
    }

    return 0;
}
