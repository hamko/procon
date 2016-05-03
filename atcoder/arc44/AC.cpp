#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define Min(x) *min_element(all(x))
#define Max(x) *max_element(all(x))
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { if (!v.empty()) { o << '['; copy(v.begin(), v.end(), ostream_iterator<T>(o, ", ")); o << "\b\b]"; } return o; }
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;

const int MOD = 1e9 + 7;
int modpow(int64_t x, int64_t e) {
    int64_t ret = 1;
    int64_t cur = x;
    while (e) {
        if (e & 1) ret = (ret * cur) % MOD;
        cur = (cur * cur) % MOD;
        e >>= 1;
    }
    return ret;
}

const ll prime = 1000000007;
ll pow2(ll x){
    if(x==0) return 1;
    ll tmp=pow2(x/2);
    tmp*=tmp;
    tmp%=prime;
    if(x%2) return tmp*2%prime;
    else return tmp;
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n; cin >> n;
    vector<ll> buc(100005);
    rep(i, n) { 
        int tmp; cin >> tmp; 
        buc[tmp]++;
        if(i==0&&tmp!=0){
            cout << 0 << endl; return 0;
        }
    }
    if (buc[0]!=1) {
        cout << 0 << endl; return 0;
    }

    ll ret = 1;
    rep(i, n) {
        if(buc[i+1]){
            rep(j, buc[i+1]) {
                (ret*=(pow2(buc[i])-1))%=MOD;
            }
            (ret*=pow2(buc[i+1]*(buc[i+1]-1)/2))%=MOD;
        }
    }
    cout << ret << endl;
    return 0;
}
