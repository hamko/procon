// ARC36 B
#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define Min(x) *min_element(all(x))
#define Max(x) *max_element(all(x))
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { if (!v.empty()) { o << '['; copy(v.begin(), v.end(), ostream_iterator<T>(o, ", ")); o << "\b\b]"; } return o; }
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;
typedef pair<int, int> P;

static const double EPS = 1e-14;
static const long long INF = 1e18;
#define MAX_N 100005

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n; cin >> n;
    vll a(n);
    rep(i, n) { cin >> a[i]; }

    ll state = 0, prev_state = -1;
    ll trans[4][4] // next_state = trans[state][arrow]
        //  arrow
        //  +  -  0  End        // state
        = {{1, 1, 1, 3},        // start
           {1, 2, 1, 3},        // +
           {1, 2, 2, 3},        // -
           {-1, -1, -1, -1}};   // goal
    ll prev_index = 0;
    ll prev_value = 0;
    ll ret = 0;
    rep(i, n+1) { // n-1は特殊
        // input -> arrow
        ll arrow; 
        if (a[i] - prev_value > 0)
            arrow = 0;
        else if (a[i] - prev_value < 0)
            arrow = 1;
        else 
            arrow = 2;
        if (i == n)
            arrow = 3;
//        cout << i << "(" << a[i] << ")"<< ":" << arrow << " " << state << "->" << trans[arrow][state] << endl;

        // active arrowの処理
        if ((state == 2 && arrow == 0) ||
            (state == 2 && arrow == 3) ||
            (state == 1 && arrow == 3) ||
            (state == 0 && arrow == 3)) {
//            cout << i << " " << prev_index << "UPDATE" << endl;
            ret = max(ret, i - prev_index);
            prev_index = i - 1;
        }

        // FSM更新
        prev_state = state;
        state = trans[state][arrow];
        
        // 後処理
        prev_value = a[i];
    }

    cout << ret << endl;

    return 0;
}
