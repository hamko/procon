#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;

/**********************************************************/
// 前処理ありの素数判定
// 素数の最大値Mに対して先にconstructPrimesList(M)するといい
/**********************************************************/
// O(n log n)
void sieve_of_eratosthenes(vector<ll>& primes, ll n) {
    primes.resize(n);
    for (ll i = 2; i < n; ++i)
        primes[i] = i;
    for (ll i = 2; i*i < n; ++i)
        if (primes[i])
            for (ll j = i*i; j < n; j+=i)
                primes[j] = 0;
}
void getPrimesList(ll n, vector<ll>& primes_list) {
    vector<ll> tmpList;
    primes_list.clear(); primes_list.resize(0); primes_list.reserve(n / 5);
    sieve_of_eratosthenes(tmpList, n);
    rep(i, n) { 
        if (tmpList[i])
            primes_list.push_back(i);
    }
}

// 素数テーブル構築: O(n log n)
vector<ll> primesList;      // 素数リスト（primesListMaxまで）。こいつ自体を使うことあるかも。
set<ll> primesSet;
ll primesListMax;
void constructPrimesList(ll n) {
    n++;
    if (primesListMax > n) 
        return;
    primesListMax = n;
    getPrimesList(n, primesList);
    for (ll i = 0; i < primesList.size(); i++) {
        primesSet.insert(primesList[i]);
    }
}

// constructされていないなら、O(sqrt(n) log n)
// constructされているなら、O(log n)
// Divisor系は、最大nをMAXNとしてconstructPrimesList(sqrt(MAXN))で早くなる
void getPrimeFactorizationList(ll n, vector<ll>& divisors_list) {
    divisors_list.clear(); divisors_list.resize(0);
    if (n <= 1) return;
    constructPrimesList(sqrt(n)+1);

    ll prime = 2;
    while (n >= prime * prime) {
        if (n % prime == 0) {
            divisors_list.push_back(prime);
            n /= prime;
        } else {
            prime++;
        }
    }
    divisors_list.push_back(n);
}


const ll MOD = 1000000007;
ll n, k;
using pset = map<ll, ll>;

ll calc_gcd(pset& counter) {
    ll p = k;
    for (auto x : counter) 
        rep(i, x.second) 
            p /= x.first;
    return p;
}

ll calc_sum(pset& counter) {
    ll p = calc_gcd(counter);
    ll tmp = n / p;

    return ((p % MOD) * ((tmp * (tmp + 1) / 2) % MOD)) % MOD;
}

map<pset, ll> memo;
ll rec(pset counter) {
    if (memo.count(counter)) // ここをif(memo[counter])にしていて、メモ化がきちんとできていなかった
        return memo[counter];

    ll ret = calc_sum(counter);

    ll maxi = 1;
    for (auto x : counter) 
        maxi *= x.second + 1;
    for (ll i = 0; i < maxi - 1; i++) {
        pset next = counter;
        for (auto x : next) 
            next[x.first] = 0;
        ll tmpi = i;
        for (auto x : counter) {
            next[x.first] = tmpi % (x.second + 1);
            tmpi /= (x.second + 1);
        }
        (ret -= rec(next)) %= MOD;
    }
    
    return memo[counter] = ret;
}

signed main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> n >> k;
    constructPrimesList(sqrt(max(n, k))+1);

    vector<ll> p;
    getPrimeFactorizationList(k, p);
    pset counter;
    rep(i, p.size()) counter[p[i]]++;

    pset allprimes;
    for (auto x : counter) 
        allprimes[x.first] = 0;
    memo[allprimes] = calc_sum(allprimes);

    rec(counter);

    ll ret = 0;
    for (auto x : memo) {
        pset tmp = x.first;
        ret += k / calc_gcd(tmp) * x.second; ret %= MOD;
    }
    cout << (ret + MOD) % MOD << endl;

    return 0;
}
