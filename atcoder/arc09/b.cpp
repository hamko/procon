#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { if (!v.empty()) { o << '['; copy(v.begin(), v.end(), ostream_iterator<T>(o, ", ")); o << "\b\b]"; } return o; }
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;
typedef pair<ll, ll> P;

static const double EPS = 1e-14;
static const long long INF = 1e18;
#define MAX_N 100005

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    map<char, char> a, ainv; rep(i, 10) { char tmp; cin >> tmp; a['0' + i] = tmp; ainv[tmp] = '0' + i;}
    ll n; cin >> n;
    vector<string> nums(n);
    rep(i, n) {
        cin >> nums[i];
        rep(j, nums[i].length())
            nums[i][j] = ainv[nums[i][j]];
    }

    vector<int> nums_ll(n); rep(i, n) { nums_ll[i] = stoi(nums[i]); }
    sort(all(nums_ll));

    rep(i, n) {
        nums[i] = to_string(nums_ll[i]);
        rep(j, nums[i].length()) 
            nums[i][j] = a[nums[i][j]];
    }
    rep(i, n) 
        cout << nums[i] << endl;


    return 0;
}
