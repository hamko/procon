#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;

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
// constructされていないなら、O(n log n)
// constructされているなら、O(log n)
bool isPrimeLookup(ll n) {
    constructPrimesList(n);
    return primesSet.count(n);
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

// constructされていないなら、O(sqrt(n) log n)
// constructされているなら、O(log n)
// Divisor系は、最大nをMAXNとしてconstructPrimesList(sqrt(MAXN))で早くなる
void getDivisorsList(ll n, vector<ll>& divisors_list) {
    divisors_list.clear(); divisors_list.resize(0);
    constructPrimesList(sqrt(n)+1);

    vector<ll> fac_list;
    getPrimeFactorizationList(n, fac_list);
    map<ll, ll> counter;
    for (auto x : fac_list) 
        counter[x]++;
    divisors_list.push_back(1);
    for (auto x : counter) {
        ll tmp_size = divisors_list.size();
        ll p = 1;
        for (ll i = 0; i < x.second; i++) {
            p *= x.first;
            for (ll j = 0; j < tmp_size; j++) 
                divisors_list.push_back(divisors_list[j] * p);
        }
    }
    sort(divisors_list.begin(), divisors_list.end());
}

// constructされていないなら、O(sqrt(n) log n)
// constructされているなら、O(log n)
ll getDivisorsNum(ll n) {
    vector<ll> divisors_list; getPrimeFactorizationList(n, divisors_list);
    map<ll, ll> num;
    for (ll i = 0; i < divisors_list.size(); i++) {
        num[divisors_list[i]]++;
    }
    ll p = 1;
    for (auto x : num) {
        p *= x.second + 1;
    }
    return p;
}
/**********************************************************/
// 前処理なしの素数判定
/**********************************************************/
// Millar-Rabin Test

using ull = unsigned long long;
bool isPrimeSmall(const ll &n){
    if(n == 2) return true;
    if(n < 2 || n%2 == 0) return false;
    const ll m = n-1, d = m / (m & -m);
    auto modpow = [&](ll a, ll b){
        ll res = 1;
        while(b){
            if(b&1) res = res*a%n;
            a = a*a%n;
            b >>= 1;
        }
        return res;
    };
    auto suspect = [&](ll a, ll t){
        a = modpow(a,t);
        while(t != -1+n && a != 1 && a != -1+n){
            a = a*a%n;
            t *= 2;
        }
        return a == n-1 || t%2 == 1;
    };
    static const ll witness[] = {2,7,61,0}; // n <= 2^32
    for(const ll *w = witness; *w < n && *w; w++){
        if(!suspect(*w,d)) return false;
    }
    return true;
}

bool isPrimeLarge(const ll &n){
    if(n == 2) return true;
    if(n < 2 || n%2 == 0) return false;
    const ll m = n-1, d = m / (m & -m);
    auto modmul = [&](ll a, ll b){
        ll res = 0;
        while(b){
            if(b&1) res = ((ull)res+a)%n;
            a = ((ull)a+a)%n;
            b >>= 1;
        }
        return res;
    };
    auto modpow = [&](ll a, ll b){
        ll res = 1;
        while(b){
            if(b&1) res = modmul(res,a);
            a = modmul(a,a);
            b >>= 1;
        }
        return res;
    };
    auto suspect = [&](ll a, ll t){
        a = modpow(a,t);
        while(t != -1+n && a != 1 && a != -1+n){
            a = modmul(a,a);
            t *= 2;
        }
        return a == n-1 || t%2 == 1;
    };
    static const ll witness[] = {2,325,9375,28178,450775,9780504,1795265022,0}; // n <= 2^64
    for(const ll *w = witness; *w < n && *w; w++){
        if(!suspect(*w,d)) return false;
    }
    return true;
}

bool isPrime(const ll &n){
    return n < INT_MAX ? isPrimeSmall(n) : isPrimeLarge(n);
}

// ガウス素数＝複素数の素数判定
bool isGaussianPrime(ll a, ll b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    if (a == 0) return b % 4 == 3 && isPrime(b);
    if (b == 0) return a % 4 == 3 && isPrime(a);
    return isPrime(a*a+b*b);
}

// 区間篩
// O( n log n )．
const ll N = 100000000; // MAXPRIME 
const ll M = 10000;     // SQRT(N)
const ll K = 6000000;   // NUMBER OF PRIMES, CHOOSE 9/8 * N / LOG(N)
vector<ll> iterativeSieve() {
    static ll p[K], table[M];
    for (ll i = 2; i < M; ++i) p[i] = i;
    for (ll i = 2; i*i < M; ++i)
        if (p[i])
            for (ll j = i*i; j < M; j += i)
                p[j] = 0;
    p[0] = p[1] = 0;
    ll num = remove(p, p+M, 0) - p;
    for (ll m = M; m < N; m += M) {
        for (ll x = m; x < m+M; ++x)
            table[x-m] = x;
        for (ll i = 0, j; p[i]*p[i] < m+M; ++i) {
            if (p[i] >= m)          j = p[i] * p[i];
            else if (m % p[i] == 0) j = m;
            else                    j = m - (m % p[i]) + p[i];
            for (; j < m+M; j += p[i]) table[j-m] = 0;
        }
        num = remove_copy(table, table+M, p+num, 0) - p;
    }
    return vector<ll>(p, p+num);
}



ll n = 1000000;
vector<ll> primes;
int main(void) {
    // 構築しないで素数判定
    cout << isPrimeLookup(2) << endl;
    cout << isPrimeLookup(4) << endl;
    cout << isPrimeLookup(17) << endl;

    int count;

    // O(n log n)
    count = 0;
    sieve_of_eratosthenes(primes, n);
    rep(i, n) { 
        if (primes[i])
            count++;
    }
    cout << count << endl;

    // O(n log n)
    vector<ll> primes_list;
    getPrimesList(n, primes_list);
    cout << primes_list.size() << endl;

    // 構築O(n log n), 参照O(log n)
    count = 0;
    constructPrimesList(n);
    rep(i, n) { 
        if (isPrimeLookup(i)) 
            count++;
    }
    cout << count << endl;

    // O(n * 200)
    count = 0;
    rep(i, n) { 
        if (isPrime(i)) 
            count++;
    }
    cout << count << endl;

    // 素因数分解
    int m = 120;
    vector<ll> prime_factorization;
    getPrimeFactorizationList(m, prime_factorization);
    rep(i, prime_factorization.size()) {
        cout << prime_factorization[i] << " ";
    }
    cout << endl;

    vector<ll> divisors_list;
    getDivisorsList(m, divisors_list);
    rep(i, divisors_list.size()) {
        cout << divisors_list[i] << " ";
    }

    cout << "#" << getDivisorsNum(m) << " ";
    cout << endl;

    return 0;
}

