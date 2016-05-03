#include <bits/stdc++.h>
using namespace std;
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;
#define rep(i,n) for(int i = 0; i < n; i++)

ll randr(ll i, ll j) { if (i == j) return i; else return ((ll)rand() * rand()) % (j - i) + i; }
ld randrf(ld i, ld j) { return ((ld)rand() / RAND_MAX) * (j - i) + i; }

int D[51][51];
int S[51][51];
int nabe(vector<vector<int>>& d, int P)
{
    ios::sync_with_stdio(false);
    int N = d.size();
    for( int i=1; i<=N; i++ ){
        for( int j=1; j<=N; j++ ){
            D[i][j] = d[i-1][j-1];
        }
    }
    for( int i=1; i<=N; i++ ){
        for( int j=1; j<=N; j++ ){
            S[i][j] = S[i][j-1] + D[i][j];
        }
    }
    for( int j=1; j<=N; j++ ){
        for( int i=1; i<=N; i++ ){
            S[i][j] += S[i-1][j];
        }
    }
    int ret = 0;
    for( int j=1; j<=P; j++ ){
        int H = min( j, N );
        int W = min( P/j, N );
        for( int y=0; y<=N-H; y++ ){
            for( int x=0; x<=N-W; x++ ){
                ret = max( ret, S[y+H][x+W]-S[y][x+W]-S[y+H][x]+S[y][x] );
            }
        }
    }
    return ret;
}

/**********************************************************/
// 前処理ありの素数判定
// 素数の最大値Mに対して先にconstructPrimesList(M)するといい
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
}int hamko(vector<vector<int>>& Din, int P)
{
    ll n = Din.size();
    constructPrimesList(n);

    vector<vector<ll>> d(n+1,vector<ll>(n+1, 0));
    rep(x, n) rep(y, n) d[x+1][y+1] = Din[x][y];
    int q = 1;
    ll p[q]; p[0] = P;

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
        return points[p[i]];
}
int main(void)
{
    ll n = randr(1, 50);
    rep(c, 100000) {
        vector<vector<int>> d(n, vector<int>(n, 0));
        rep(i, n) rep(j, n) {
            d[i][j] = randr(1, 100);
        }
        int p = randr(1, n*n);
        int x = nabe(d, p);
        int y = hamko(d, p);
        if (x != y) {
            cout << "################HIT############" << endl;
            cout << "NABE: " << x << endl;
            cout << "HAMKO: " << y << endl;
            cout << n << endl;
            rep(i, n) { 
                rep(j, n) { cout << d[i][j] << " "; }
                cout << endl;
            }
            cout << 1 << endl;
            cout << p << endl;
        }
    }

    return 0;
}

