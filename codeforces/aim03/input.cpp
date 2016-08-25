#include <bits/stdc++.h>
using namespace std;
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;
#define rep(i,n) for(int i = 0; i < n; i++)

ll randr(ll i, ll j) { if (i == j) return i; else return ((ll)rand() * rand()) % (j - i) + i; }
ld randrf(ld i, ld j) { return ((ld)rand() / RAND_MAX) * (j - i) + i; }

// 整数二分探索
// O(log(range))
// f: 単調増加関数. 000111, 111111, 000000を許容する（11110000で探索したい場合は、自分でfを反転すること）
// 閉区間[rl, rr]から単調関数fを満たす最小の数を返す。
// 全て1なら0を返す（定義通り）、全て0ならrr+1を返す（異常検出用）！
ll BinarySearch(ll rl, ll rr, function<bool(ll)> f) { 
    ll lo = rl-1, ro = rr+1;
    while (ro - lo != 1) {
        ll m = (lo + ro) / 2; 
        ((m!=rl-1&&f(m))?ro:lo)=m; 
    }
    return ro;
}

string hamko(ll a00, ll a01, ll a10, ll a11) {
    auto f0 = [&](ll x) { return x * x - x - 2 * a00 >= 0; };
    auto f1 = [&](ll x) { return x * x - x - 2 * a11 >= 0; };
    ll a0 = BinarySearch(0, 1000010, f0);
    ll a1 = BinarySearch(0, 1000010, f1);
//    cout << a0 << " " << a1 << endl;

    if (a0 * (a0 - 1ll) / 2ll != a00) {
        cout << "Impossible" << endl;
        return 0;
    }
    if (a1 * (a1 - 1ll) / 2ll != a11) {
        cout << "Impossible" << endl;
        return 0;
    }
    if (a0 == 0 && a1 == 0) {
        cout << "Impossible" << endl;
        return 0;
    }
    if (a0 * a1 != a01 + a10) {
        cout << "Impossible" << endl;
        return 0;
    }
    vll a(a1+1);
    ll rem = a10;
    ll sum = 0;
    for (ll i = a1; i > 0; i--) {
        a[i] = rem / i;
        rem -= a[i] * i;
        sum += a[i];
    }
    a[0] = a0 - sum;
//    cout << a << endl;
    string ret = "";
    rep(i, a.size()) {
        rep(j, a[i]) {
            ret+='0';
        }
        if (i != a.size() - 1) 
            ret+='1';
    }

    return ret;
}
bool check_hamko(string s, ll a00, ll a01, ll a10, ll a11) {
    rep(i, s.size()-1) {
        for (int j = i+1; j < s.size(); j++) {
            if (s[i] == '0' && s[j] == '0') a00--;
            if (s[i] == '0' && s[j] == '1') a01--;
            if (s[i] == '1' && s[j] == '0') a10--;
            if (s[i] == '1' && s[j] == '1') a11--;
        }
    }
    assert(a00 == 0);
    assert(a01 == 0);
    assert(a10 == 0);
    assert(a11 == 0);
    return 0;
}
int main(void)
{

    rep(i, 1) {
        ll a0 = 100000;
        ll a1 = 100000;

        rep(i, a0*a1) {
            string s = hamko(a0 * (a0 - 1)/2, i, a0*a1-i, a1*(a1-1)/2);
            check_hamko(s, a0 * (a0 - 1)/2, i, a0*a1-i, a1*(a1-1)/2);
        }
    }

    return 0;
}

