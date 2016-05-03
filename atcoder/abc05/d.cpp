#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
using ll = long long;

/**********************************************************/
// 前処理ありの素数判定
// 素数の最大値Mに対して先にconstructPrimesList(M)せよ！！！
/**********************************************************/
// O(n log n)
void sieve_of_eratosthenes(vector<ll>& primes, ll n) {
    primes.resize(n);
    for (int i = 2; i < n; ++i)
        primes[i] = i;
    for (int i = 2; i*i < n; ++i)
        if (primes[i])
            for (int j = i*i; j < n; j+=i)
                primes[j] = 0;
}

void getPrimesList(int n, vector<ll>& primes_list) {
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
    for (int i = 0; i < primesList.size(); i++) {
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

    int i = 0, prime = 2;
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
    map<ll, int> counter;
    for (auto x : fac_list) 
        counter[x]++;
    divisors_list.push_back(1);
    for (auto x : counter) {
        int tmp_size = divisors_list.size();
        ll p = 1;
        for (int i = 0; i < x.second; i++) {
            p *= x.first;
            for (int j = 0; j < tmp_size; j++) 
                divisors_list.push_back(divisors_list[j] * p);
        }
    }
    sort(divisors_list.begin(), divisors_list.end());
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n, q; cin >> n;
    constructPrimesList(n);

    vector<vector<ll>> d(n+1,vector<ll>(n+1, 0));
    rep(x, n) rep(y, n) cin >> d[x+1][y+1];
    cin >> q;
    ll p[q]; rep(i, q) cin >> p[i];

    ll dx[n+1][n+1]; rep(x, n+1) rep(y, n+1) dx[x][y] = 0;
    for (int x = 1; x < n + 1; x++) for (int y = 1; y < n + 1; y++) {
        if (x > 0)
            dx[x][y] += dx[x-1][y];
        dx[x][y] += d[x][y];
    }

    ll dxy[n+1][n+1]; rep(x, n+1) rep(y, n+1) dxy[x][y] = 0;
    for (int x = 1; x < n + 1; x++) for (int y = 1; y < n + 1; y++) {
        if (y > 0)
            dxy[x][y] += dxy[x][y-1];
        dxy[x][y] += dx[x][y];
    }

    vector<int> points(n*n+1);
    rep(query, points.size()) {
        if (!query) continue;
        vector<ll> divisors;
        getDivisorsList(query, divisors);
        ll M = 0;
        rep(j, divisors.size()) {
            ll x = divisors[j];
            ll y = query / x; // x * yの小区間
            x = min(x, n);
            y = min(y, n);
            rep(h, n - x + 1) // (h, k)を原点に持つx * yの小区間の累積和を求める
                rep(k, n - y + 1)
                    M = max(M, dxy[h+x][k+y]-dxy[h][k+y]-dxy[h+x][k]+dxy[h][k]);
        }
        points[query] = M;
    }

    rep(i, points.size()-1) 
        points[i+1] = max(points[i], points[i+1]);
    rep(i, q) 
        cout << points[p[i]] << endl;

    return 0;
}
