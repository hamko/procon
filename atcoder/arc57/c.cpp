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

using ll = long long; using ld = long double; using vll = vector<ll>; using vvll = vector<vll>; using vld = vector<ld>; 
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
void printbits(ll mask, ll n) { rep(i, n) { cout << !!(mask & (1ll << i)); } cout << endl; }
#define ldout fixed << setprecision(40) 

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;

// 固定多倍長演算
const int MAXDIGIT = 5005; // it can represent 4*MAXDIGIT digits (in base 10)
//const int MAXDIGIT = 25000; // it can represent 4*MAXDIGIT digits (in base 10)
typedef long long Int;
const Int B = 10000;      // base (power of 10)
const int BW = 4;         // log B
struct BigNum {
    Int digit[MAXDIGIT];
    int size;
    BigNum(int size = 1, Int a = 0) : size(size) {
        memset(digit, 0, sizeof(digit));
        digit[0] = a;
    }
};
const BigNum ZERO(1, 0), ONE(1, 1);

// Comparators
bool operator<(BigNum x, BigNum y) {
    if (x.size != y.size) return x.size < y.size;
    for (int i = x.size-1; i >= 0; --i)
        if (x.digit[i] != y.digit[i]) return x.digit[i] < y.digit[i];
    return false;
}
bool operator >(BigNum x, BigNum y) { return y < x; }
bool operator<=(BigNum x, BigNum y) { return !(y < x); }
bool operator>=(BigNum x, BigNum y) { return !(x < y); }
bool operator!=(BigNum x, BigNum y) { return x < y || y < x; }
bool operator==(BigNum x, BigNum y) { return !(x < y) && !(y < x); }

// Utilities
BigNum normal(BigNum x) {
    Int c = 0;
    for (int i = 0; i < x.size; ++i) {
        while (x.digit[i] < 0)
            x.digit[i+1] -= 1, x.digit[i] += B;
        Int a = x.digit[i] + c;
        x.digit[i] = a % B;
        c          = a / B;
    }
    for (; c > 0; c /= B) x.digit[x.size++] = c % B;
    while (x.size > 1 && x.digit[x.size-1] == 0) --x.size;
    return x;
}
BigNum convert(Int a) {
    return normal(BigNum(1, a));
}
BigNum convert(const string &s) {
    BigNum x;
    int i = s.size() % BW;
    if (i > 0) i -= BW;
    for (; i < (int)s.size(); i += BW) {
        Int a = 0;
        for (int j = 0; j < BW; ++j)
            a = 10 * a + (i + j >= 0 ? s[i+j] - '0' : 0);
        x.digit[x.size++] = a;
    }
    reverse(x.digit, x.digit+x.size);
    return normal(x);
}
// Input/Output
ostream &operator<<(ostream &os, BigNum x) {
    os << x.digit[x.size-1];
    for (int i = x.size-2; i >= 0; --i)
        os << setw(BW) << setfill('0') << x.digit[i];
    return os;
}
istream &operator>>(istream &is, BigNum &x) {
    string s; is >> s;
    x = convert(s);
    return is;
}

// Basic Operations 
BigNum operator+(BigNum x, BigNum y) {
    if (x.size < y.size) x.size = y.size;
    for (int i = 0; i < y.size; ++i)
        x.digit[i] += y.digit[i];
    return normal(x);
}
BigNum operator-(BigNum x, BigNum y) {
    assert(x >= y);
    for (int i = 0; i < y.size; ++i)
        x.digit[i] -= y.digit[i];
    return normal(x);
}
BigNum operator*(BigNum x, BigNum y) {
    BigNum z(x.size + y.size);
    for (int i = 0; i < x.size; ++i)
        for (int j = 0; j < y.size; ++j)
            z.digit[i+j] += x.digit[i] * y.digit[j];
    return normal(z);
}
BigNum operator*(BigNum x, Int a) {
    for (int i = 0; i < x.size; ++i)
        x.digit[i] *= a;
    return normal(x);
}
pair<BigNum, Int> divmod(BigNum x, Int a) {
    Int c = 0, t;
    for (int i = x.size-1; i >= 0; --i) {
        t          = B * c + x.digit[i];
        x.digit[i] = t / a;
        c          = t % a;
    }
    return pair<BigNum, Int>(normal(x), c);
}
BigNum operator/(BigNum x, Int a) {
    return divmod(x, a).first;
}
Int operator%(BigNum x, Int a) {
    return divmod(x, a).second;
}
pair<BigNum, BigNum> divmod(BigNum x, BigNum y) {
    if (x.size < y.size) return pair<BigNum, BigNum>(ZERO, x);
    int F = B / (y.digit[y.size-1] + 1); // multiplying good-factor
    x = x * F; y = y * F;
    BigNum z(x.size - y.size + 1);
    for (int k = z.size-1, i = x.size-1; k >= 0; --k, --i) {
        z.digit[k]  = (i+1 < x.size ? x.digit[i+1] : 0) * B + x.digit[i];
        z.digit[k] /= y.digit[y.size-1];
        BigNum t(k + y.size);
        for (int m = 0; m < y.size; ++m)
            t.digit[k+m] = z.digit[k] * y.digit[m];
        t = normal(t);
        while (x < t) {
            z.digit[k] -= 1;
            for (int m = 0; m < y.size; ++m)
                t.digit[k+m] -= y.digit[m];
            t = normal(t);
        }
        x = x - t;
    }
    return pair<BigNum, BigNum>(normal(z), x / F);
}
BigNum operator/(BigNum x, BigNum y) {
    return divmod(x, y).first;
}
BigNum operator%(BigNum x, BigNum y) {
    return divmod(x, y).second;
}

// Advanced Operations
BigNum shift(BigNum x, int k) {
    if (x.size == 1 && x.digit[0] == 0) return x;
    x.size += k;
    for (int i = x.size - 1; i >= k; --i) x.digit[i] = x.digit[i-k];
    for (int i = k-1; i >= 0; --i) x.digit[i] = 0;
    return x;
}
/*
BigNum sqrt(BigNum x) { // verified UVA 10023
    const BigNum _20 = convert(2*B);
    BigNum odd = ZERO;
    BigNum rem(2,0);
    BigNum ans = ZERO;
    for (int i = 2*((x.size-1)/2); i >= 0; i -= 2) {
        int group = (i+1 < x.size ? x.digit[i+1] : 0) * B + x.digit[i];
        odd =  _20 * ans + ONE;
        rem = shift(rem, 2) + convert(group);
        int count = 0;
        while (rem >= odd) {
            count = count + 1;
            rem = rem - odd;
            odd.digit[0] += 2;
            odd = normal(odd);
        }
        ans = shift(ans,1) + convert(count);
    }
    return ans;
}
*/
BigNum sqrt(BigNum x) { 
    if (x == ZERO)
        return ZERO;
    BigNum lo = ZERO;
    BigNum ro = x;

    while (ro - lo != ONE) {
        BigNum mid = (lo + ro) / 2;
        if (mid * mid >= x) 
            ro = mid;
        else
            lo = mid;
    }
    if (ro * ro == x)
        return ro;
    else 
        return ro - ONE;
}


int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    BigNum a; // 初期化はZERO, ONEで行う
    cin >> a;
    stringstream ss; ss << a; string n = ss.str();

    a = a * a;

    BigNum test = ONE * 100;
//    cout << sqrt(test) << endl;
    test = test / 2;
//    cout << sqrt(test) << endl;

    stringstream sq; sq << a; string original_ = sq.str();
    BigNum original = a;
//    cout << original << "orig" << endl;
    for (ll i = (original_.length()+1)/2; i >= 0; i--) {
//        cout << i << endl;
        BigNum tmp = original;
        rep(j, i) {
            tmp = tmp / 100;
        }
//        cout << tmp << "tmp" << endl;
        BigNum cut = tmp;
//        cout << cut <<"cut"<< endl;
//        cout << cut+ONE <<"cut+1"<< endl;
        // +0
        BigNum pz = cut;
        rep(j, i) 
            pz = pz * 100;
//        cout << pz << "pz" << endl;
//        BigNum sqpz = ONE;
        BigNum sqpz = sqrt(pz);
        stringstream sspz; sspz << sqpz; string s_sqpz = sspz.str();
        if (s_sqpz.length() >= n.length()) {
//            cout << sqpz << " " << n << endl;
            bool hit = 1;
            rep(i, n.length()) {
                if (n[i] != s_sqpz[i]) {
                    hit = 0;
                    break;
                }
            }
            if (hit) {
//                cout << "HIT" << endl;
                cout << cut << endl;
                return 0;
            }
        }
        // +1
        BigNum po = cut;
        po = po + ONE;
        rep(j, i) 
            po = po * 100;
//        cout << po << "po" << endl;
//        BigNum sqpo = ONE;
        BigNum sqpo = sqrt(po);
        stringstream sspo; sspo << sqpo; string s_sqpo = sspo.str();
        if (s_sqpo.length() >= n.length()) {
//            cout << sqpo << " " << n << endl;
            bool hit = 1;
            rep(i, n.length()) {
                if (n[i] != s_sqpo[i]) {
                    hit = 0;
                    break;
                }
            }
            if (hit) {
//                cout << "HIT" << endl;
                cout << cut + ONE << endl;
                return 0;
            }
        }

    }

    return 0;
}
