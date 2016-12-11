#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { if (!v.empty()) { o << '['; copy(v.begin(), v.end(), ostream_iterator<T>(o, ", ")); o << "\b\b]"; } return o; }
using ll = long long;  using vll = vector<ll>; using vi = vector<int>;
typedef pair<ll, ll> P;

static const double EPS = 1e-14;
static const long long INF = 1e18;
#define MAX_N 100005

typedef long double Double;

int m; 
Double highres(int a, int b, Double t) {
        if (!a) {
            return expl(powl(t, 1.0l / b));
        }
        if (!b) {
            return powl(t, 1.0l / a);
        }

        Double rl = 1e-12;
        Double rr = 11;
        rep(i, 100) { 
            Double m = (rl + rr) / 2.0l;
            (powl(m, a) * powl(log(m), b) - t > 0.0l) ? rr = m : rl = m;
        }
        Double n = rl;
        return n;
}

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

Double wfunc(int a, int b, Double t) {
    if (!a) {
        return exp(pow(t, 1.0 / b));
    }
    if (!b) {
        return pow(t, 1.0 / a);
    }
    double n = exp(1.0 * b / a * LambertW(1.0 * a / b * pow(t, 1.0 / b))); 
    return n;
}

int main(void) {
    scanf("%d", &m);
    rep(i, m) {
        int a, b; scanf("%d%d", &a, &b);
        Double t; scanf("%Lf", &t);
        Double n_highres = highres(a, b, t);
        Double n_wfunc = wfunc(a, b, t);
        if (abs(n_wfunc - n_highres) > 1e-9) {
            cout << i << " : " << n_wfunc << " " << n_highres << endl;
        }
    }
}
