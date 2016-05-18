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

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll l, n, m; cin >> l >> n >> m;
    vector<vll> x(n);
    map<P, P> memo;
    vll a(m); rep(i, m) { int tmp, x1, x2; cin >> tmp >> x1 >> x2; tmp--; x[tmp].pb(x1); x[tmp+1].pb(x2); memo[P(tmp, x1)] = P(tmp+1, x2); memo[P(tmp+1, x2)] = P(tmp, x1); }
    rep(i, n) sort(all(x[i]), greater<ll>());

    ll now = 0;
    ll pos = l;
    while (1) {
        vector<ll>::iterator it = upper_bound(all(x[now]), pos, greater<ll>());
        if (it == x[now].end()) 
            break;
        P tmp = memo[P(now, *it)];
        now = tmp.first;
        pos = tmp.second;
    }
    cout << now + 1 << endl;

    return 0;
}
