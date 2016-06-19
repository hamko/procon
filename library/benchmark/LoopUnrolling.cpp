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


// Loop Unroll
// 1    0.990512    100%
// 2    0.906881    91%
// 4    0.894252    89%
// 8    0.847672    85%
// 16   0.830906    83%
// 32   0.831918    83%

const ll n = 1e8;
vector<int> a(n), b(n), c(n);
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);

    {
        stopwatch_start(0);
        for(int i=0; i<n; i++)
            a[i] = b[i] * c[i];
        cout << stopwatch_end(0) << endl;
    }

    {
        stopwatch_start(0);
        for(int i=0; i<n; i+=2) {
            a[i+0] = b[i+0] * c[i+0];
            a[i+1] = b[i+1] * c[i+1];
        }
        cout << stopwatch_end(0) << endl;
    }

    {
        stopwatch_start(0);
        for(int i=0; i<n; i+=4) {
            a[i+0] = b[i+0] * c[i+0];
            a[i+1] = b[i+1] * c[i+1];
            a[i+2] = b[i+2] * c[i+2];
            a[i+3] = b[i+3] * c[i+3];
        }
        cout << stopwatch_end(0) << endl;
    }

    {
        stopwatch_start(0);
        for(int i=0; i<n; i+=8) {
            a[i+0] = b[i+0] * c[i+0];
            a[i+1] = b[i+1] * c[i+1];
            a[i+2] = b[i+2] * c[i+2];
            a[i+3] = b[i+3] * c[i+3];
            a[i+4] = b[i+4] * c[i+4];
            a[i+5] = b[i+5] * c[i+5];
            a[i+6] = b[i+6] * c[i+6];
            a[i+7] = b[i+7] * c[i+7];
        }
        cout << stopwatch_end(0) << endl;
    }

    {
        stopwatch_start(0);
        for(int i=0; i<n; i+=16) {
            a[i+0] = b[i+0] * c[i+0];
            a[i+1] = b[i+1] * c[i+1];
            a[i+2] = b[i+2] * c[i+2];
            a[i+3] = b[i+3] * c[i+3];
            a[i+4] = b[i+4] * c[i+4];
            a[i+5] = b[i+5] * c[i+5];
            a[i+6] = b[i+6] * c[i+6];
            a[i+7] = b[i+7] * c[i+7];
            a[i+8+0] = b[i+8+0] * c[i+8+0];
            a[i+8+1] = b[i+8+1] * c[i+8+1];
            a[i+8+2] = b[i+8+2] * c[i+8+2];
            a[i+8+3] = b[i+8+3] * c[i+8+3];
            a[i+8+4] = b[i+8+4] * c[i+8+4];
            a[i+8+5] = b[i+8+5] * c[i+8+5];
            a[i+8+6] = b[i+8+6] * c[i+8+6];
            a[i+8+7] = b[i+8+7] * c[i+8+7];
        }
        cout << stopwatch_end(0) << endl;
    }

    {
        stopwatch_start(0);
        for(int i=0; i<n; i+=32) {
            a[i+0] = b[i+0] * c[i+0];
            a[i+1] = b[i+1] * c[i+1];
            a[i+2] = b[i+2] * c[i+2];
            a[i+3] = b[i+3] * c[i+3];
            a[i+4] = b[i+4] * c[i+4];
            a[i+5] = b[i+5] * c[i+5];
            a[i+6] = b[i+6] * c[i+6];
            a[i+7] = b[i+7] * c[i+7];
            a[i+8+0] = b[i+8+0] * c[i+8+0];
            a[i+8+1] = b[i+8+1] * c[i+8+1];
            a[i+8+2] = b[i+8+2] * c[i+8+2];
            a[i+8+3] = b[i+8+3] * c[i+8+3];
            a[i+8+4] = b[i+8+4] * c[i+8+4];
            a[i+8+5] = b[i+8+5] * c[i+8+5];
            a[i+8+6] = b[i+8+6] * c[i+8+6];
            a[i+8+7] = b[i+8+7] * c[i+8+7];
            a[i+16+0] = b[i+16+0] * c[i+16+0];
            a[i+16+1] = b[i+16+1] * c[i+16+1];
            a[i+16+2] = b[i+16+2] * c[i+16+2];
            a[i+16+3] = b[i+16+3] * c[i+16+3];
            a[i+16+4] = b[i+16+4] * c[i+16+4];
            a[i+16+5] = b[i+16+5] * c[i+16+5];
            a[i+16+6] = b[i+16+6] * c[i+16+6];
            a[i+16+7] = b[i+16+7] * c[i+16+7];
            a[i+16+8+0] = b[i+16+8+0] * c[i+16+8+0];
            a[i+16+8+1] = b[i+16+8+1] * c[i+16+8+1];
            a[i+16+8+2] = b[i+16+8+2] * c[i+16+8+2];
            a[i+16+8+3] = b[i+16+8+3] * c[i+16+8+3];
            a[i+16+8+4] = b[i+16+8+4] * c[i+16+8+4];
            a[i+16+8+5] = b[i+16+8+5] * c[i+16+8+5];
            a[i+16+8+6] = b[i+16+8+6] * c[i+16+8+6];
            a[i+16+8+7] = b[i+16+8+7] * c[i+16+8+7];
        }
        cout << stopwatch_end(0) << endl;
    }




    return 0;
}
