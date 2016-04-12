#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll;

#define MAX_N 2005
static const double EPS = 1e-14; // 罠：(1.0/20000/2);としたらダメだった。
int main(void) {
    int N; cin >> N;
    int x[MAX_N], y[MAX_N];
    rep(i, N) scanf("%d %d", x+i, y+i); // 教えてくれてありがとう:)

    ll acute = 0, right = 0; // 鋭角数、直角数
    rep(i, N) {
        vector<double> angle; // ∠(j)(i)(x軸)の集合。
        rep(j, N) 
            if (i != j) 
                angle.push_back(atan2(x[i] - x[j], y[i] - y[j]));
        sort(begin(angle), end(angle));
        rep(j, N-1) // 罠: angle.size()と指定しそうになった。危ない。
            angle.push_back(angle[j]+2*M_PI);

        rep(j, N-1) {
            int acute_max_index = j; // 最大鋭角の添字
            // 次見て鋭角だったら最大鋭角の添字を更新
            while (angle[acute_max_index+1] - angle[j] < M_PI / 2 - EPS) 
                acute_max_index++;
            acute += acute_max_index - j;

            // この時点でj, acute_max_indexは最大鋭角の添字なので
            // 次は直角か鈍角のはず。直角ならカウント
            if (angle[acute_max_index+1] - angle[j] < M_PI / 2 + EPS) 
                right++;
        }
    }

    ll all_triangle_num = (ll)N * (N-1) * (N-2) / 6;
    cout    << (ll)acute - 2 * all_triangle_num << " " 
            << (ll)right << " " 
            << (ll)3 * all_triangle_num - right - acute << endl;

    return 0;
}
