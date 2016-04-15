#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define MAX_N 100005

int main(void) {
    int N, a, b[MAX_N];
    string k;
    cin >> N >> a >> k; a--; // ちゃんと0indexにしないと頭がこんがらがる。必ず0indexに。
    rep(i, N) {
        cin >> b[i];
        b[i]--;
    }

    // これ忘れかけてた。kが小さい時はそもそもループに入らない
    if (k.length() <= 6 && stoi(k) < MAX_N) {
        rep(i, stoi(k)) a = b[a];
        cout << a + 1 << endl;
        return 0;
    }

    map<int, int> memo;
    int i = a, step = 1;
    int d, l, loop_start;
    while (1) {
        if (memo[i]) {
            loop_start = i;
            d = memo[i] - 1;
            l = step - d - 1;
            break;
        }
        memo[i] = step;
        i = b[i];
        step++;
    }
    
    int mod[MAX_N]; mod[0] = 1;
    rep(i, MAX_N-1)
        mod[i+1] = (10*mod[i])%l;

    // (k - d) % l
    int ret = -d; (ret %= l) += l;
    rep(i, k.length()) {
        int p = k.length() - i - 1; // 10^p桁目
        (ret += mod[p] * (k[i] - '0')) %= l;
    }

    rep(i, ret) loop_start = b[loop_start];
    cout << loop_start + 1 << endl;


    return 0;
}
