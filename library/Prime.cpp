#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;

/**********************************************************/
// 前処理ありの素数判定
// 素数の最大値が決まっているなら先にconstructPrimesList
/**********************************************************/
// O(n log n)
// primesは欲しい範囲のサイズを事前に確保しておくと早くなる。
void sieve_of_eratosthenes(vector<ll>& primes) {
    int n = primes.size();
    for (int i = 2; i < n; ++i)
        primes[i] = i;
    for (int i = 2; i*i < n; ++i)
        if (primes[i])
            for (int j = i*i; j < n; j+=i)
                primes[j] = 0;
}
void getPrimesList(int n, vector<ll>& primes_list) {
    vector<ll> tmpList;
    tmpList.clear(); tmpList.resize(n);
    primes_list.clear(); primes_list.resize(0); primes_list.reserve(n / 5);
    sieve_of_eratosthenes(tmpList);
    rep(i, n) { 
        if (tmpList[i])
            primes_list.push_back(i);
    }
}

// O(n log n)で素数を覚えておく
vector<ll> primesList;
set<ll> primesSet;
ll primesListMax;
void constructPrimesList(ll n) {
    if (primesListMax > n) 
        return;
    primesListMax = n;
    getPrimesList(n, primesList);
    for (int i = 0; i < primesList.size(); i++) {
        primesSet.insert(primesList[i]);
    }
}
bool isPrimeLookup(ll n) {
    return primesSet.count(n);
}

// O(sqrt(n) log n) くらい
void getDivisorsList(ll n, vector<ll>& divisors_list) {
    divisors_list.clear(); divisors_list.resize(0);
    constructPrimesList(sqrt(n)+1);

    int i = 0, prime = primesList[i];
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
ll getDivisorsNum(ll n) {
    vector<ll> divisors_list; getDivisorsList(n, divisors_list);
    map<ll, int> num;
    for (int i = 0; i < divisors_list.size(); i++) {
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
// 確率的素数判定、2^32程度では大体の数に対して200ループで厳密な素数判定を実現。2^64も多分行けるかもたぶんね。
// {2,7,61,-1}                 is for n < 4759123141 (= 2^32)
// {2,3,5,7,11,13,17,19,23,-1} is for n < 10^16 (at least)
ll powMod(ll base, ll exponent, ll mod)
{
    ll x = 1;
    ll y = base;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            x = (x * y) % mod;
        y = (y * y) % mod;
        exponent = exponent / 2;
    }
    return x % mod;
}
bool suspect(ll a, int s, ll d, ll n) {
    ll x = powMod(a, d, n);
    if (x == 1) return true;
    for (int r = 0; r < s; ++r) {
        if (x == n - 1) return true;
        x = x * x % n;
    }
    return false;
}
// O(1) 200回演算程度
bool isPrime(ll n) {
    if (n <= 1 || (n > 2 && n % 2 == 0)) return false;
    int test[] = {2,3,5,7,11,13,17,19,23,-1};
    ll d = n - 1, s = 0;
    while (d % 2 == 0) ++s, d /= 2;
    for (int i = 0; test[i] < n && test[i] != -1; ++i)
        if (!suspect(test[i], s, d, n)) return false;
    return true;
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
const int N = 100000000; // MAXPRIME 
const int M = 10000;     // SQRT(N)
const int K = 6000000;   // NUMBER OF PRIMES, CHOOSE 9/8 * N / LOG(N)
vector<ll> iterativeSieve() {
    static int p[K], table[M];
    for (int i = 2; i < M; ++i) p[i] = i;
    for (int i = 2; i*i < M; ++i)
        if (p[i])
            for (int j = i*i; j < M; j += i)
                p[j] = 0;
    p[0] = p[1] = 0;
    int num = remove(p, p+M, 0) - p;
    for (int m = M; m < N; m += M) {
        for (int x = m; x < m+M; ++x)
            table[x-m] = x;
        for (int i = 0, j; p[i]*p[i] < m+M; ++i) {
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
vector<ll> primes(n);
int main(void) {
    int count;

    // O(n log n)
    count = 0;
    sieve_of_eratosthenes(primes);
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
    vector<ll> divisors;
    getDivisorsList(120, divisors);
    rep(i, divisors.size()) {
        cout << divisors[i] << " ";
    }
    cout << "#" << getDivisorsNum(120) << " ";
    cout << endl;

    return 0;
}

