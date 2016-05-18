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

void permutation(vll& s, vll& p)
{
    vll tmp(s.size());
    rep(i, s.size())
        tmp[p[i]] = s[i];
    s = tmp;
}
int main(void) {
    ll n; cin >> n;
    vll s(n); rep(i, n) { cin >> s[i]; s[i]--; }
    ll m; cin >> m;
    vector<vll> p(m, vll(n)); rep(i, m) rep(j, n) { cin >> p[i][j]; p[i][j]--; }

    vll perm(m); 

    vll ret = s;
    rep(mask, 1 << m) {
        rep(i, m) perm[i] = i;
        do {
            vll tmp = s;
            rep(i, m) if (mask & (1 << i)) permutation(tmp, p[perm[i]]);
            if (ret > tmp) ret = tmp;
        } while (next_permutation(all(perm)));
    }

    rep(i, ret.size()) {
        if (i != 0) cout << " ";
        cout << ret[i] + 1;
    }
    cout << endl;
    return 0;
}
