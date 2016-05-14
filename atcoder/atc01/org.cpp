#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define push_back pb
#define all(x) x.begin(), x.end()
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { if (!v.empty()) { o << '['; copy(v.begin(), v.end(), ostream_iterator<T>(o, ", ")); o << "\b\b]"; } return o; }
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;
typedef pair<ll, ll> P;

static const double EPS = 1e-14;
static const long long INF = 1e18;
#define MAX_N 100005

// O(n log n)
// int n 配列の長さ．2 のべきでなければならない．
// double theta 回転角．順変換のとき 2.0*PI/n を指定し，逆変換のとき -2.0*PI/n を指定する．
// Complex a[] 変換する配列．結果は in place で変換される．逆変換の場合は結果をさらに 1/n 倍する必要がある．
const long double PI = 4.0*atan(1.0);
typedef complex<long double> Complex;
const Complex I(0, 1);
void fft(int n, long double theta, vector<Complex>& a) {
    for (int m = n; m >= 2; m >>= 1) {
        int mh = m >> 1;
        for (int i = 0; i < mh; i++) {
            Complex w = exp(i*theta*I);
            for (int j = i; j < n; j += m) {
                int k = j + mh;
                Complex x = a[j] - a[k];
                a[j] += a[k];
                a[k] = w * x;
            }
        }
        theta *= 2;
    }
    int i = 0;
    for (int j = 1; j < n - 1; j++) {
        for (int k = n >> 1; k > (i ^= k); k >>= 1);
        if (j < i) swap(a[i], a[j]);
    }
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll size; cin >> size;
    ll n = 1 << 17;
    vector<Complex> a(n), b(n);

    // set 
    rep(i, size) {
        long double ai, bi; cin >> ai >> bi;

        a[i] = Complex(ai, 0);
        b[i] = Complex(bi, 0);
    }

    // fft
    fft(n, 2.0*PI/n, a);
    fft(n, 2.0*PI/n, b);
    rep(i, n) 
        a[i] = a[i] * b[i];

    // inv fft, nで割ることに注意！
    fft(n, -2.0*PI/n, a);
    rep(i, n) a[i] /= n;
    cout << 0 << endl;
    rep(i, 2 * size - 1) cout << (ll)round(a[i].real()) << endl;


    return 0;
}
