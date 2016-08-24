#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define all(x) (x).begin(), (x).end()

/**********************************************************/
// 前処理ありの素数判定
// 素数の最大値Mに対して先にconstructPrimesList(M)が必須！
/**********************************************************/
// O(n log log n)
void sieve_of_eratosthenes(vector<long long>& primes, long long n) {
    primes.resize(n);
    for (long long i = 2; i < n; ++i)
        primes[i] = i;
    for (long long i = 2; i*i < n; ++i)
        if (primes[i])
            for (long long j = i*i; j < n; j+=i)
                primes[j] = 0;
}
void getPrimesList(long long n, vector<long long>& primes_list) {
    vector<long long> tmpList;
    primes_list.clear(); primes_list.resize(0); primes_list.reserve(n / 5);
    sieve_of_eratosthenes(tmpList, n);
    rep(i, n) { 
        if (tmpList[i])
            primes_list.push_back(i);
    }
}

// 素数テーブル構築: O(n log n)
vector<long long> primesList;      // 素数リスト（primesListMaxまで）。こいつ自体を使うことあるかも。
set<long long> primesSet;
long long primesListMax;
void constructPrimesList(long long n) {
    if (primesListMax >= n) 
        return;
    primesListMax = n;
    getPrimesList(n, primesList);
    for (long long i = 0; i < primesList.size(); i++) {
        primesSet.insert(primesList[i]);
    }
}

int main(void) {
    long long n = 0; 
    constructPrimesList(200000);
    
    while (cin >> n && n) 
        cout << (long long)(lower_bound(all(primesList), n) - primesList.begin()) << endl;
    return 0;
}
