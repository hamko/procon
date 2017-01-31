#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long; using vll = vector<ll>; using vvll = vector<vll>;
static const long long mo = 1e9+7;

using hash_t = unsigned long long;
hash_t hashVll(vll const& vec) {
    hash_t seed = vec.size();
    for(auto& i : vec) 
        seed ^= i + 0x9e3779b9e973979b + (seed << 12) + (seed >> 4);
    return seed;
}

int main(void) {
    ll n, m; cin >> n >> m;

    vvll table(m);
    rep(i, n) {
        ll gn; cin >> gn;
        rep(j, gn) {
            ll tmp; cin >> tmp; tmp--;
            table[tmp].push_back(i);
        }
    }

    unordered_map<hash_t, ll> memo;
    rep(j, m) {
        sort(all(table[j]));
        memo[hashVll(table[j])]++;
    }

    static ll fact[1000010];
    fact[0] = 1;
    for (int i = 1; i < 1000010; i++) 
        (fact[i] = (fact[i-1] * i)) %= mo;

    ll ret = 1;
    for (auto x : memo) 
        (ret *= fact[x.second]) %= mo;

    cout << ret << endl;
    return 0;
}
