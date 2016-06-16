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

#include <sys/time.h>
 struct stop_watch {
    chrono::high_resolution_clock::time_point start;
    stop_watch() 
        : start(chrono::high_resolution_clock::now()) {}
    ~stop_watch() {
        chrono::duration<double> duration = chrono::high_resolution_clock::now() - start;
        cout << duration.count() << " ";
    }  
};
   
    std::ostream&
operator<<( std::ostream& dest, __int128_t value )
{
    std::ostream::sentry s( dest );
    if ( s ) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[ 128 ];
        char* d = std::end( buffer );
        do
        {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = std::end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( std::ios_base::badbit );
        }
    }
    return dest;
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    {
        __int128_t a = 10;
        cout << ((__int128_t)1 << 80) << endl;
    }

    {
        stop_watch sw;
        int a = 0;
        for (int i = 0; i < 1e9; i++) {
            a = a * 3 + 5;
            a /= 2;
        }
        cout << a << endl;
    }
    {
        stop_watch sw;
        long long a = 0;
        for (int i = 0; i < 1e9; i++) {
            a = a * 3 + 5;
            a /= 2;
        }
        cout << a << endl;
    }
    {
        stop_watch sw;
        __int128_t a = 0;
        for (int i = 0; i < 1e9; i++) {
            a = a * 3 + 5;
            a /= 2;
        }
        cout << a << endl;
    }

    return 0;
}
