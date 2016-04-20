#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// O(n log n)
vector<int> sieve_of_eratosthenes(int n) {
      vector<int> primes(n);
        for (int i = 2; i < n; ++i)
                primes[i] = i;
          for (int i = 2; i*i < n; ++i)
                  if (primes[i])
                            for (int j = i*i; j < n; j+=i)
                                        primes[j] = 0;
            return primes;
}

// Millar-Rabin Test
// 確率的素数判定、2^32程度では大体の数に対して200ループで厳密な素数判定を実現。2^64も多分行けるかもたぶんね。
// {2,7,61,-1}                 is for n < 4759123141 (= 2^32)
// {2,3,5,7,11,13,17,19,23,-1} is for n < 10^16 (at least)
bool suspect(Int a, int s, Int d, Int n) {
      Int x = powMod(a, d, n);
        if (x == 1) return true;
          for (int r = 0; r < s; ++r) {
                  if (x == n - 1) return true;
                      x = x * x % n;
                        }
            return false;
}

bool isPrime(Int n) {
      if (n <= 1 || (n > 2 && n % 2 == 0)) return false;
        int test[] = {2,3,5,7,11,13,17,19,23,-1};
          Int d = n - 1, s = 0;
            while (d % 2 == 0) ++s, d /= 2;
              for (int i = 0; test[i] < n && test[i] != -1; ++i)
                      if (!suspect(test[i], s, d, n)) return false;
                return true;
}

// ガウス素数＝複素数の素数判定
bool isGaussianPrime(Int a, Int b) {
      if (a < 0) a = -a;
        if (b < 0) b = -b;
          if (a == 0) return b % 4 == 3 && isPrime(b);
            if (b == 0) return a % 4 == 3 && isPrime(a);
              return isPrime(a*a+b*b);
}

// 区間篩
const int N = 100000000; // MAXPRIME 
const int M = 10000;     // SQRT(N)
const int K = 6000000;   // NUMBER OF PRIMES, CHOOSE 9/8 * N / LOG(N)
vector<Int> iterativeSieve() {
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
    return vector<Int>(p, p+num);
}



int main(void) {

    return 0;
}
