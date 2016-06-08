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

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll a, b; cin >> a >> b;
    string s, t; cin >> s >> t;
    vll cs(1000), ct(1000);
    rep(i, s.length()) cs[s[i]]++;
    rep(i, t.length()) ct[t[i]]++;
    ll ret = 0;
    rep(i, 1000) {
      ret += max<ll>(0, ct[i] - cs[i]);
    }
    cout << ret << endl;

    return 0;
}
