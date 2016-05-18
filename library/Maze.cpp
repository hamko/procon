#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define Min(x) *min_element(all(x))
#define Max(x) *max_element(all(x))
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { if (!v.empty()) { o << '['; copy(v.begin(), v.end(), ostream_iterator<T>(o, ", ")); o << "\b\b]"; } return o; }
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;
typedef pair<ll, ll> P;

static const double EPS = 1e-14;
static const long long INF = 1e18;

#define MAX_N 100005

ll ni, nj; 
ll si, sj, gi, gj;
char a[50][50];
ll di[4] = {0, 0, 1, -1}, dj[4] = {1, -1, 0, 0};

// 配る再帰！
// 配る再帰では、最後にメモするのではなく、

// 更新してから遷移する再帰
ll s[50][50]; // INFで「まだ来ていない」を表現
void rec1(ll i, ll j) {
    rep(d, 4) {
        ll ii = i+di[d], jj = j+dj[d];
        if (ii < 0 || ii >= ni || jj < 0 || jj >= nj)
            continue;
        if (a[ii][jj] == '#') 
            continue;
        if (s[ii][jj] > s[i][j] + 1) {
            s[ii][jj] = s[i][j] + 1;    // メモしてから
            rec1(ii, jj);               // 再帰
        }
    }
}

// 更新してから遷移する再帰 map ver
map<P, ll> memo; // count == 0で「まだ来ていない」を表現
void rec2(ll i, ll j) {
    rep(d, 4) {
        ll ii = i+di[d], jj = j+dj[d];
        if (ii < 0 || ii >= ni || jj < 0 || jj >= nj)
            continue;
        if (a[ii][jj] == '#') 
            continue;
        if (!memo.count(P(ii, jj)) || memo[P(ii, jj)] > memo[P(i, j)] + 1) {
            memo[P(ii, jj)] = memo[P(i, j)] + 1;   // メモしてから
            rec2(ii, jj);                          // 再帰
        }
    }
}

// 集める再帰風の、配る再帰 map ver、だがこれは配る再帰には合わない！
// 無効なものを作ってから無効なものを弾いてるので、memoに無効なものが入ってしまう。
void rec3(ll i, ll j) {
    if (i < 0 || i >= ni || j < 0 || j >= nj)
        return;
    if (a[i][j] == '#') 
        return;

    rep(d, 4) {
        ll ii = i+di[d], jj = j+dj[d];
        if (!memo.count(P(ii, jj))) {
            memo[P(ii, jj)] = memo[P(i, j)] + 1;   // メモしてから
            rec3(ii, jj);  // 再帰
        }
    }
}


// vectorをqueueとみなして迷路を解く
// O(ni * nj)
// 入力     char*二次元配列grid、その盤面の大きさ縦ni, 横nj、壁を表す文字wallc, スタート地点を表す文字sc, ゴール地点を表す文字gc
// 出力     dist
// scは必ずセットされている必要がある。gc複数セットできて、セットしておくと返り値にgcの中で最短距離を出力してくれる
template<typename Grid, typename Dist>
ll solveMaze(const Grid &grid, ll ni, ll nj, Dist &dist, char wallc, char sc, char gc = 0) {
    rep(i, ni) rep(j, nj) dist[i][j] = INF;

    ll sy = -1, sx = -1; rep(i, ni) rep(j, nj) if (grid[i][j] == sc) sy = i, sx = j;
    if(sy == -1) return INF;
    dist[sy][sx] = 0;

    vector<P> q, q_next;
    q_next.push_back(P(sy, sx));
    ll t = 0;
    while(!q_next.empty()) {
        q.swap(q_next);
        while(!q.empty()) {
            ll i = q.back().first, j = q.back().second; q.pop_back();
            rep(d, 4) {
                ll ii = i + di[d], jj = j + dj[d];
                if (ii<0||ii>=ni||jj<0||jj>=nj) continue;
                if (grid[ii][jj] == wallc) continue;
                if (dist[ii][jj] != INF) continue;
                dist[ii][jj] = t + 1;
                q_next.push_back(P(ii, jj));
            }
        }
        t++;
    }
    ll goal = INF;
    rep(i, ni) rep(j, nj)
        if (grid[i][j] == gc) 
            goal = min<ll>(goal, dist[i][j]);

    return goal;
}

/*
3 4
0 1 0 3
..#.
.##.
....
*/

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> ni >> nj;
    cin >> si >> sj >> gi >> gj; 
    rep(i, ni) rep(j, nj) cin >> a[i][j];

    {
        rep(i, ni) rep(j, nj) s[i][j] = INF;
        s[si][sj] = 0;
        rec1(si, sj);
        cout << s[gi][gj] << endl;
    }

    {
        memo.clear();
        memo[P(si, sj)] = 0;
        rec2(si, sj);
        cout << memo[P(gi, gj)] << endl;
    }

    {
        memo.clear();
        memo[P(si, sj)] = 0;
        rec3(si, sj);
        cout << memo[P(gi, gj)]  << endl;
    }

    {
        ll dist[50][50];
        a[si][sj] = 's', a[gi][gj] = 'g';
        ll ret = solveMaze(a, ni, nj, dist, '#', 's', 'g');
        cout << ret << endl;
        a[si][sj] = '.', a[gi][gj] = '.';
    }


    return 0;
}
