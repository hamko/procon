#include <bits/stdc++.h>
using namespace std;

#ifdef _WIN32
#define scanfll(x) scanf("%I64d", x)
#define printfll(x) printf("%I64d", x)
#else
#define scanfll(x) scanf("%lld", x)
#define printfll(x) printf("%lld", x)
#endif
#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define repi(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mt make_tuple
#define mp make_pair
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

using ll = long long; using vll = vector<ll>; using vvll = vector<vll>;
using ld = long double;  using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>;
vll conv(vi& v) { vll r(v.size()); rep(i, v.size()) r[i] = v[i]; return r; }
using P = pair<ll, ll>;

template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template<size_t...> struct seq{}; template<size_t N, size_t... Is> struct gen_seq : gen_seq<N-1, N-1, Is...>{}; template<size_t... Is> struct gen_seq<0, Is...> : seq<Is...>{};
template<class Ch, class Tr, class Tuple, size_t... Is>
void print_tuple(basic_ostream<Ch,Tr>& os, Tuple const& t, seq<Is...>){ using s = int[]; (void)s{0, (void(os << (Is == 0? "" : ", ") << get<Is>(t)), 0)...}; }
template<class Ch, class Tr, class... Args> 
auto operator<<(basic_ostream<Ch, Tr>& os, tuple<Args...> const& t) -> basic_ostream<Ch, Tr>& { os << "("; print_tuple(os, t, gen_seq<sizeof...(Args)>()); return os << ")"; }
ostream &operator<<(ostream &o, const vvll &v) { rep(i, v.size()) { rep(j, v[i].size()) o << v[i][j] << " "; cout << endl; } return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const unordered_map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it; o << "]";  return o; }
string bits_to_string(ll mask, ll n) { string s; rep(i, n) s += '0' + !!(mask & (1ll << i)); return s; }
#define ldout fixed << setprecision(40) 

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;

/* ランベルトのW関数
   http://keithbriggs.info/software/LambertW.c
*/
const double eps=4.0e-16, em1=0.3678794411714423215955237701614608; 
double LambertW(const double z) {
    int i; 
    double p,e,t,w;
#ifdef DEBUG
    fprintf(stderr,"LambertW: z=%g\n",z);
    if (z<-em1 || ::isinf(z) || ::isnan(z)) { 
        fprintf(stderr,"LambertW: bad argument %g, exiting.\n",z); exit(1); 
    }
#endif
    if (0.0==z) return 0.0;
    if (z<-em1+1e-4) { // series near -em1 in sqrt(q)
        double q=z+em1,r=sqrt(q),q2=q*q,q3=q2*q;
        return 
            -1.0
            +2.331643981597124203363536062168*r
            -1.812187885639363490240191647568*q
            +1.936631114492359755363277457668*r*q
            -2.353551201881614516821543561516*q2
            +3.066858901050631912893148922704*r*q2
            -4.175335600258177138854984177460*q3
            +5.858023729874774148815053846119*r*q3
            -8.401032217523977370984161688514*q3*q;  // error approx 1e-16
    }
    /* initial approx for iteration... */
    if (z<1.0) { /* series near 0 */
        p=sqrt(2.0*(2.7182818284590452353602874713526625*z+1.0));
        w=-1.0+p*(1.0+p*(-0.333333333333333333333+p*0.152777777777777777777777)); 
    } else 
        w=log(z); /* asymptotic */
    if (z>3.0) w-=log(w); /* useful? */
    for (i=0; i<10; i++) { /* Halley iteration */
        e=exp(w); 
        t=w*e-z;
        p=w+1.0;
        t/=e*p-0.5*(p+1.0)*t/p; 
        w-=t;
        if (fabs(t)<eps*(1.0+fabs(w))) return w; /* rel-abs error */
    }
    /* should never get here */
    fprintf(stderr,"LambertW: No convergence at z=%g, exiting.\n",z); 
    exit(1);
}

#define TESTW
#ifdef TESTW
double err_dur = 1e-9;
int main() {
    int m; scanf("%d", &m);
    double maxerr = -INF;
    rep(i, m) {
        int a, b; scanf("%d%d", &a, &b);
        double t; scanf("%lf", &t);
//        cout << a << " " << b << " " << t << endl;
        if (!a) {
//            cout << "a=0" << endl;
            printf("%.12f\n", exp(pow(t, 1.0 / b)));
            continue;
        }
        if (!b) {
//            cout << "b=0" << endl;
            printf("%.12f\n", pow(t, 1.0 / a));
            continue;
        }
        double n = exp(1.0 * b / a * LambertW(1.0 * a / b * pow(t, 1.0 / b))); 
        printf("%.12f\n", n);
#ifdef DEBUG
        double err = pow(n, a) * pow(log(n), b) -  t;
        chmax(maxerr, abs(err));
        if (err > err_dur) {
            fprintf(stderr, "###########LARGE!!!!!!!!!!\n");
            exit(1);
        }
#endif
//        cout << pow(n, b) * pow(log(n), a) -  t << endl;
        /*
        cout << pow(n, b) * pow(log(n), a) << endl;
        cout << t << endl;
        */
    }
//    fprintf(stderr, "%.20f\n", maxerr);
    return 0;
}
#endif
