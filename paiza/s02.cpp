#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector<long long> vll;
typedef pair<ll, ll> P;
#define INF 1e18

// vectorをqueueとみなして迷路を解く
// O(ni * nj)
// 入力     char*二次元配列grid、その盤面の大きさ縦ni, 横nj、壁を表す文字wallc, スタート地点を表す文字sc, ゴール地点を表す文字gc
// 出力     dist
// scは必ずセットされている必要がある。gc複数セットできて、セットしておくと返り値にgcの中で最短距離を出力してくれる
ll di[4] = {0, 0, 1, -1}, dj[4] = {1, -1, 0, 0};
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

char a[1010][1010];
ll dist[1010][1010];
int main(void) {
    ll ni, nj; cin >> nj >> ni;
    rep(i, ni) rep(j, nj) {
        char c; cin >> c;
        a[i][j] = c;
    }

    ll ret = solveMaze(a, ni, nj, dist, '1', 's', 'g');
    if (ret == INF)
        cout << "Fail" << endl;
    else
        cout << ret << endl;


    return 0;
}
