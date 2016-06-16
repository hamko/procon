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
#define MAX_TIMER_NUM 256
static double s_tmptime[MAX_TIMER_NUM] = {}; // [s]
void stopwatch_start(int index)
{
    if (index >= MAX_TIMER_NUM) {
        cout << "INVALID TIMER NUM, IGNORED: MAX_TIMER_NUM is " << MAX_TIMER_NUM<< endl;
        return;
    }
    struct timeval tim;  
    gettimeofday(&tim, NULL);  
    s_tmptime[index] = tim.tv_sec+(tim.tv_usec / 1000000.0);  
}

double stopwatch_end(int index)
{
    if (index >= MAX_TIMER_NUM) {
        cout << "INVALID TIMER NUM, IGNORED: MAX_TIMER_NUM is " << MAX_TIMER_NUM<< endl;
        return -1;
    }
    struct timeval tim;  
    gettimeofday(&tim, NULL);  
    return tim.tv_sec+(tim.tv_usec / 1000000.0) - s_tmptime[index];
}

double get_clock_now(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + (double)tv.tv_usec*1e-6;
}


// int128_tの描画
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
void printbits(__int128_t n) {
    rep(i, 128) {
        if (n & ((__int128_t)1 << (127 - i))) 
            cout << 1;
        else 
            cout << 0;
    }
    cout << endl;
}

// int128_tの計算
// int, long longに比べて、計算時間は
// +, -, bit        125%
// *                150%
// /, %             400%

// int, long longの計算時間は同じ

// int, long longの中では、以下。
// +, -             100%
// *                125%
// /                180%
// %                250%
// bit              100%
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    {
        cout << ((__int128_t)1 << 80) << endl;

        __int128_t a = 1;
        cout << a << endl;
        printbits(a);
        a *= -1;
        cout << a << endl;
        printbits(a);
    }

    int n = 1e8;

    cout << "Nothing" << endl;
    {
        stopwatch_start(0);
        int a = 0; for (int i = 0; i < n; i++) { }
        cout << stopwatch_end(0) << endl;
    }

    cout << "=" << endl;
    {
        stopwatch_start(0);
        int a = 1; for (int i = 0; i < n; i++) { a = a; }
        cout << stopwatch_end(0) << endl;
    }
    {
        stopwatch_start(0);
        long long a = 1; for (int i = 0; i < n; i++) { a = a; }
        cout << stopwatch_end(0) << endl;
    }
    {
        stopwatch_start(0);
        __int128_t a = 1; for (int i = 0; i < n; i++) { a = a; }
        cout << stopwatch_end(0) << endl;
    }

    cout << "+" << endl;
    {
        stopwatch_start(0);
        int a = 0; for (int i = 0; i < n; i++) { a = a + 5; }
        cout << stopwatch_end(0) << endl;
    }
    {
        stopwatch_start(0);
        long long a = 0; for (int i = 0; i < n; i++) { a = a + 5; }
        cout << stopwatch_end(0) << endl;
    }
    {
        stopwatch_start(0);
        __int128_t a = 0; for (int i = 0; i < n; i++) { a = a + 5; }
        cout << stopwatch_end(0) << endl;
    }

    cout << "-" << endl;
    {
        stopwatch_start(0);
        int a = 0; for (int i = 0; i < n; i++) { a = a - 5; }
        cout << stopwatch_end(0) << endl;
    }
    {
        stopwatch_start(0);
        long long a = 0; for (int i = 0; i < n; i++) { a = a - 5; }
        cout << stopwatch_end(0) << endl;
    }
    {
        stopwatch_start(0);
        __int128_t a = 0; for (int i = 0; i < n; i++) { a = a - 5; }
        cout << stopwatch_end(0) << endl;
    }


    cout << "*" << endl;
    {
        stopwatch_start(0);
        int a = 1; for (int i = 0; i < n; i++) { a = a * 5; }
        cout << stopwatch_end(0) << endl;
    }
    {
        stopwatch_start(0);
        long long a = 1; for (int i = 0; i < n; i++) { a = a * 5; }
        cout << stopwatch_end(0) << endl;
    }
    {
        stopwatch_start(0);
        __int128_t a = 1; for (int i = 0; i < n; i++) { a = a * 5; }
        cout << stopwatch_end(0) << endl;
    }

    cout << "/" << endl;
    {
        stopwatch_start(0);
        int a = 1; for (int i = 0; i < n; i++) { a = a / 5; }
        cout << stopwatch_end(0) << endl;
    }
    {
        stopwatch_start(0);
        long long a = 1; for (int i = 0; i < n; i++) { a = a / 5; }
        cout << stopwatch_end(0) << endl;
    }
    {
        stopwatch_start(0);
        __int128_t a = 1; for (int i = 0; i < n; i++) { a = a / 5; }
        cout << stopwatch_end(0) << endl;
    }

    cout << "%" << endl;
    {
        stopwatch_start(0);
        int a = 1; for (int i = 0; i < n; i++) { a = a % 5; }
        cout << stopwatch_end(0) << endl;
    }
    {
        stopwatch_start(0);
        long long a = 1; for (int i = 0; i < n; i++) { a = a % 5; }
        cout << stopwatch_end(0) << endl;
    }
    {
        stopwatch_start(0);
        __int128_t a = 1; for (int i = 0; i < n; i++) { a = a % 5; }
        cout << stopwatch_end(0) << endl;
    }

    cout << "&" << endl;
    {
        stopwatch_start(0);
        int a = 1; for (int i = 0; i < n; i++) { a = a & (1 << 15); }
        cout << stopwatch_end(0) << endl;
    }
    {
        stopwatch_start(0);
        long long a = 1; for (int i = 0; i < n; i++) { a = a & (1ll << 30); }
        cout << stopwatch_end(0) << endl;
    }
    {
        stopwatch_start(0);
        __int128_t a = 1; for (int i = 0; i < n; i++) { a = a & ((__int128_t)1 << 70); }
        cout << stopwatch_end(0) << endl;
    }


    return 0;
}
