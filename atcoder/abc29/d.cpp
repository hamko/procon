#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long; using vll = vector<ll>; using vi = vector<int>;

map<int, ll> memo;
ll ret(int N) {
    if (!N) return 0; // いらんだろｗと思って消したらMLE。余計に見えても間違ってないなら変に消さない。
    if (memo[N]) return memo[N];

    int sig = N, dig = 0;
    while (1) {
        if (sig / 10 == 0) 
            break;
        sig /= 10; dig++;
    }

    ll bef = pow(10, dig);
    ll red = N - bef * sig;
    return sig * ret(bef-1) + (sig == 1 ? red + 1 : bef) + ret(red); // ものすっごくこの漸化式を作るのに時間がかかった。紙できちんと書き下してから実装すること！！！！
}

int main(void) {
    int N; cin >> N;
    rep(i, 9) memo[i+1] = 1;
    cout << ret(N) << endl;
    return 0;
}
