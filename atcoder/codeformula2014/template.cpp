#include <bits/stdc++.h>
using namespace std;

// gcc -E -v -march=native - 2>&1 | grep cc1   
// -mavx -mno-avx2 -msse4.2 -msse4.1 -mno-fma

//include file              //Ver.      Option
#include <xmmintrin.h>      //SSE       default
#include <emmintrin.h>      //SSE  2    default
//#include <pmmintrin.h>      //SSE  3    -msse3
//#include <tmmintrin.h>      //SSSE 3    -mssse3
//#include <smmintrin.h>      //SSE 4.1   -msse4.1
//#include <nmmintrin.h>      //SSE 4.2   -msse4.2

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mt make_tuple
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

#define al __attribute__((aligned(16)))
#define Int __m128i
#define Float __m128
#define Double __m128d

//-----------------------------------------------------------------------------
// SSE3以上のラッパ

// 64bit整数2つの比較 (greater than, equal)
// cmpltやはSSE4.*にもない
//
// gt:
// [ a_0, a_1 ], [ b_0, b_1 ]
//   => [ -(a_0 > b_0), -(a_1 > b_1) ]
//
// eq:
// [ a_0, a_1 ], [ b_0, b_1 ]
//   => [ -(a_0==b_0), -(a_1==b_1) ]
static inline __m128i __attribute__((always_inline)) _mm_cmpgt_epi64(__m128i a, __m128i b) {
    __asm__("pcmpgtq %1, %0" : "+x" (a) : "xm" (b));
    return a;
}
static inline __m128i __attribute__((always_inline)) _mm_cmpeq_epi64(__m128i a, __m128i b) {
    __asm__("pcmpeqq %1, %0" : "+x" (a) : "xm" (b));
    return a;
}
 
// 32bit整数2つの積 (64bitに拡張)
// [ a_0, a_1, a_2, a_3 ] * [ b_0, b_1, b_2, b_3 ]
//   => [ (ll)a_0 * b_0, (ll)a_2 * b_2 ]
//
// _mm_mul_epu32はSSE2からある
static inline __m128i __attribute__((always_inline))
_mm_mul_epi32(__m128i a, __m128i b){
    __asm__("pmuldq %1, %0" : "+x" (a) : "xm" (b));
    return a;
}

//-----------------------------------------------------------------------------
void printbits(Int n) {
    int32_t a[4];
    _mm_store_si128((Int*)a, n);
    rep(i, 32) cout << !!(a[0] & (1ll << (31 - i))); cout << " ";
    rep(i, 32) cout << !!(a[1] & (1ll << (31 - i))); cout << " ";
    rep(i, 32) cout << !!(a[2] & (1ll << (31 - i))); cout << " ";
    rep(i, 32) cout << !!(a[3] & (1ll << (31 - i))); cout << " ";
    cout << endl;
}

void print_epi8(Int n) { int8_t a[16]; _mm_store_si128((Int*)a, n); rep(i, 16) cout << (int)a[i] << " "; cout << endl; }
void print_epu8(Int n) { uint8_t a[16]; _mm_store_si128((Int*)a, n); rep(i, 16) cout << (int)a[i] << " "; cout << endl; }
void print_epi16(Int n) { int16_t a[8]; _mm_store_si128((Int*)a, n); rep(i, 8) cout << a[i] << " "; cout << endl; }
void print_epi32(Int n) { int32_t a[4]; _mm_store_si128((Int*)a, n); rep(i, 4) cout << a[i] << " "; cout << endl; }
void print_epi64(Int n) { int64_t a[2]; _mm_store_si128((Int*)a, n); rep(i, 2) cout << a[i] << " "; cout << endl; }
 

int main(void) {
    ll n; cin >> n;
    int64_t s1, s2;
    scanf("%ld %ld", &s1, &s2);
    int32_t x[50000] al, y[50000] al;
    rep(i, n) scanf("%d %d", &x[i], &y[i]);

    ll ret = 0;
    rep(i, n) {
        ll j = 0;
        for (; j + 3 < n; j += 4) {
//            cout << i << " " << j << "#ij" << endl;
//
            // (x[i] - x[j]) * (y[i] - y[j])
            auto diff02 = _mm_mul_epi32(
                _mm_sub_epi32(_mm_set1_epi32(x[i]), _mm_load_si128((Int*)(x+j))),
                _mm_sub_epi32(_mm_set1_epi32(y[i]), _mm_load_si128((Int*)(y+j)))
            );
            int64_t d02[2] al; _mm_store_si128((Int*)d02, diff02);
            auto diff13 = _mm_mul_epi32(
                _mm_srli_si128(_mm_sub_epi32(_mm_set1_epi32(x[i]), _mm_load_si128((Int*)(x+j))), 4),
                _mm_srli_si128(_mm_sub_epi32(_mm_set1_epi32(y[i]), _mm_load_si128((Int*)(y+j))), 4)
            );
            int64_t d13[2] al; _mm_store_si128((Int*)d13, diff13);

            auto cond02 = _mm_andnot_si128(
                _mm_or_si128(
                    _mm_cmpgt_epi64(_mm_set_epi32(0, s1, 0, s1), diff02),
                    _mm_cmpgt_epi64(diff02, _mm_set_epi32(0, s2, 0, s2)) 
                ),
                _mm_set1_epi32(-1)
            );
            auto cond13 = _mm_andnot_si128(
                _mm_or_si128(
                    _mm_cmpgt_epi64(_mm_set_epi32(0, s1, 0, s1), diff13),
                    _mm_cmpgt_epi64(diff13, _mm_set_epi32(0, s2, 0, s2)) 
                ),
                _mm_set1_epi32(-1)
            );
            int64_t out02[2] al;
            int64_t out13[2] al;
            _mm_store_si128((Int*)out02, cond02);
            _mm_store_si128((Int*)out13, cond13);
            ret -= out02[0] + out02[1];
            ret -= out13[0] + out13[1];

            /*
            rep(k, 4) {
                cout << (x[i] - x[j+k]) * (y[i] - y[j+k]) << " ";
            }
            cout << endl;
            */

            /*
            // s1
            // s1 > 掛け算の結果(02)
            print_epi64(_mm_cmpgt_epi64(_mm_set_epi32(0, s1, 0, s1), diff02));
            // s1 > 掛け算の結果(13)
            print_epi64(_mm_cmpgt_epi64(_mm_set_epi32(0, s1, 0, s1), diff13));
            // s2
            // 掛け算の結果(02) < s2
            print_epi64(_mm_cmpgt_epi64(diff02, _mm_set_epi32(0, s2, 0, s2)));
            // 掛け算の結果(13) < s2
            print_epi64(_mm_cmpgt_epi64(diff13, _mm_set_epi32(0, s2, 0, s2)));

            // !si || !s2
            print_epi64( _mm_or_si128( _mm_cmpgt_epi64(_mm_set_epi32(0, s1, 0, s1), diff02), _mm_cmpgt_epi64(diff02, _mm_set_epi32(0, s2, 0, s2)) ));
            print_epi64( _mm_or_si128( _mm_cmpgt_epi64(_mm_set_epi32(0, s1, 0, s1), diff13), _mm_cmpgt_epi64(diff13, _mm_set_epi32(0, s2, 0, s2)) ));

            // !si || !s2
            print_epi64( _mm_andnot_si128(_mm_or_si128( _mm_cmpgt_epi64(_mm_set_epi32(0, s1, 0, s1), diff02), _mm_cmpgt_epi64(diff02, _mm_set_epi32(0, s2, 0, s2)) ), _mm_set1_epi32(-1)));
            print_epi64( _mm_andnot_si128(_mm_or_si128( _mm_cmpgt_epi64(_mm_set_epi32(0, s1, 0, s1), diff13), _mm_cmpgt_epi64(diff13, _mm_set_epi32(0, s2, 0, s2)) ), _mm_set1_epi32(-1)));

            cout << "sse result" << endl;
            cout << out02[0] << " " << out13[0] << " " << out02[1] << " " << out13[1] << endl;
            cout << "brutal result" << endl;
            rep(k, 4) {
                ll tmp = (x[i] - x[j+k]) * (y[i] - y[j+k]);
                cout << (s1 <= tmp && tmp <= s2) << " ";
            }
            cout << endl;
            */
        }
        for (; j < n; j++) {
            ll tmp = ((ll)x[i]-(ll)x[j])*((ll)y[i]-(ll)y[j]);
            ret += (s1 <= tmp && tmp <= s2);
        }

    }

    printf("%lld\n", ret / 2);

    return 0;
}
