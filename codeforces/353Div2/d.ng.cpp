#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { if (!v.empty()) { o << '['; copy(v.begin(), v.end(), ostream_iterator<T>(o, ", ")); o << "\b\b]"; } return o; }
using ll = long long; using ld = long double; using vll = vector<ll>; using vld = vector<ld>;
typedef pair<ll, ll> P;

static const double EPS = 1e-14;
static const long long INF = 1e18;
#define MAX_N 100005

unordered_map<ll, ll> memo;
class node {
public:
    node* p=NULL;
    node* l=NULL, *r=NULL; // small, large
    ll val = 0;
    node(){}
    void add(ll v) {
        if (v > val && r) {
            r->add(v);
        } else if (v > val && !r) {
            r = new node(); r->val = v; 
            memo[v] = val;
        } else if (v < val && l) {
            l->add(v);
        } else {
            l = new node(); l->val = v; 
            memo[v] = val;
        }
    }
};

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n; cin >> n;
    vll a(n); rep(i, a.size()) cin >> a[i];
    node* root = new node(); root->val = a[0];
    for (int i = 1; i < n; i++) {
        root->add(a[i]);
    }
    for (int i = 1; i < n; i++) {
        if (i != 1)  cout << " ";
        cout << memo[a[i]];
    }
    cout << endl;

    return 0;
}
