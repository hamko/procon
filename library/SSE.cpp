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

// SSE Lib.
// https://software.intel.com/sites/landingpage/IntrinsicsGuide/#techs=SSE2
//
// __m128[, i, d]
//      基本的なデータ構造。128bitのfloat, int, double
//
// ps   precision single
// pd   precision double
// si   s? integer
//
// __mm_load[nead align]_[pd, ps, si]128(void* src)
// __mm_store[nead align]_si128(__m128[, i, d]* dst, __m128[, i, d] src)
//      void*は、__mint128[, i, d]でキャストせよ、という意味。
//
// need align
//      無印でアライン必須
//      uでアライン不要（遅くなる）
//
// __mm_[operation]_ep[i8, i16, i32, i64, u8, u16, u32, u64](__m128 a, __m128 b)
//      i8やi16とみなして切ったデータ構造で、a op bを返す。
//
// operatoin
//      add, sub, avg, min, max, mul, sub
//      adds, subs (飽和演算付き加減算)
//      sad (絶対値)
//
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
 
int main(void)
{
    // 代入
    {
        cout << "# Substitute" << endl;

        // 配列確保は必ず16でalignする必要あり
        int32_t a[4] al = {1, 2, 3, 4};
        // Aに配列4つ分を同時代入
        Int A = _mm_load_si128((Int*)a);
        // Aの中身確認
        print_epi32(A);

        // X = [ a[3], a[2], a[1], a[0] ]
        print_epi32(_mm_set_epi32(a[0], a[1], a[2], a[3]));  // 逆に入るので注意！！
        print_epi16(_mm_set_epi16(a[0], a[1], a[2], a[3], a[0], a[1], a[2], a[3]));  // 逆に入るので注意！！
        print_epi8(_mm_set_epi8(a[0], a[1], a[2], a[3], a[0], a[1], a[2], a[3], a[0], a[1], a[2], a[3], a[0], a[1], a[2], a[3]));  // 逆に入るので注意！！
//        print_epi64(_mm_set_epi64(sa, ta); // __m64を要求するのでダメ

        // X = [ x, x, x, x ]
        int32_t x = 100;
        Int X = _mm_set1_epi32(x);
        // Xをretに移して表示
        int32_t ret[4] al;
        _mm_store_si128((Int*)ret, X);
        rep(i, 4) 
            cout << ret[i] << " "; 
        cout << endl;

        // X = [0, 0, 0, 0]
        Int Y = _mm_setzero_si128();
        print_epi32(Y);

    }

    // 加算
    {
        cout << "# Add" << endl;
        int32_t a[4] al = {1, 2, 3, 4};
        // A        = [a, b, c, d]
        Int A = _mm_load_si128((Int*)a);
        print_epi32(A);
        print_epi32(A);
        // AplusA   = [a+a, b+b, c+c, d+d]
        Int AplusA = _mm_add_epi32(A, A);
        print_epi32(AplusA);

        int32_t ret[4] al;
        _mm_store_si128((Int*)ret, AplusA);
    }

    // 減算
    {
        cout << "# Sub" << endl;
        int32_t a[4] al = {1, 2, 3, 4};
        int32_t b[4] al = {0, 1, 7, 9};

        Int A = _mm_load_si128((Int*)a);
        Int B = _mm_load_si128((Int*)b);
        print_epi32(A);
        print_epi32(B);

        Int AsubB = _mm_sub_epi32(A, B);
        print_epi32(AsubB);

        int32_t ret[4] al;
        _mm_store_si128((Int*)ret, AsubB);
    }

    // 乗算
    // 乗算前の16 bitの乗算
    // なんか説明めんどい
    // 
    // http://www2.kobe-u.ac.jp/~lerl2/l_cc_p_10.1.008/doc/main_cls/mergedProjects/intref_cls/common/intref_sse2_integer_arithmetic.htm#mulhi_epi16
    // _mm_mulhi_epi16  
    // _mm_mulhi_epu16
    // _mm_mullo_epi16  
    /*
    {
        cout << "# Mul16->32" << endl;
        int32_t x[4] al = {10000, 0, 10000000, 0};
        int32_t y[4] al = {10000, 0, 10000000, 0};
        // x        = [a, _, b, _]
        Int X = _mm_load_si128((Int*)x);
        print_epi32(X);
        // y        = [c, _, d, _]
        Int Y = _mm_load_si128((Int*)y);
        print_epi32(Y);
        // X * Y    = [a*c , b*d ]
        Int XmulY = _mm_mul_epi32(X, Y);
        print_epi64(XmulY);

        int64_t ret[2] al;
        _mm_store_si128((Int*)ret, XmulY);
    }
    */

    // 乗算
    // 乗算前の32 bitのindex、0と2しか使わないところに注意
    {
        cout << "# Mul32->64" << endl;
        int32_t x[4] al = {10000, 0, 10000000, 0};
        int32_t y[4] al = {10000, 0, 10000000, 0};
        // x        = [a, _, b, _]
        Int X = _mm_load_si128((Int*)x);
        print_epi32(X);
        // y        = [c, _, d, _]
        Int Y = _mm_load_si128((Int*)y);
        print_epi32(Y);
        // X * Y    = [a*c , b*d ]
        Int XmulY = _mm_mul_epi32(X, Y);
        print_epi64(XmulY);
    
        int64_t ret[2] al;
        _mm_store_si128((Int*)ret, XmulY);
    }

    // いろいろな二項演算子
    // max, adds, avg
    {
        cout << "# others" << endl;
        int32_t x[4] al = {10000, 0, 10000000, 0};
        uint8_t a[16] al = {3, 20, 10, 4, 8, 20, 50, 10, 4, 8, 4, 0, 40, 30, 38, 58};
        uint8_t b[16] al = {4, 80, 20, 4, 10, 30, 50, 10, 4, 8, 4, 0, 40, 30, 38, 58};
        Int A = _mm_load_si128((Int*)a);
        Int B = _mm_load_si128((Int*)b);
        Int AaddsA = _mm_max_epu8(A, B);
//        Int AaddsA = _mm_adds_epu8(A, B);
//        Int AaddsA = _mm_avg_epu8(A, B); // 小数点以下切り上げっぽい　
        print_epu8(AaddsA);

        uint8_t ret[16] al;
        _mm_store_si128((Int*)ret, AaddsA);
    }

    // シフト
    {
        cout << "# Shift" << endl;
        int32_t x[4] al = {1, 2, 3, 4};
        // X        = [a, b, c, d]
        Int X = _mm_load_si128((Int*)x);
        print_epi32(X);
        // shift_x  = [b, c, d, 0]
        Int shift_x = _mm_srli_si128(X, 4); // 4バイト左シフト
        print_epi32(shift_x);
        // shift_x  = [0, a, b, c]
        Int rshift_x = _mm_slli_si128(X, 4); // 4バイト右シフト
        print_epi32(rshift_x);

        int32_t ret[4] al;
        _mm_store_si128((Int*)ret, shift_x);
    }

    // 32bit以下の大小比較
    // ==, >, <でないといけない
    // >=, <=は提供されていない
    {
        cout << "# Compare" << endl;
        int32_t x[4] al = {1, 4, 2, 3};
        int32_t y[4] al = {0, 4, 2, 1};
        Int X = _mm_load_si128((Int*)x);
        Int Y = _mm_load_si128((Int*)y);
        print_epi32(X);
        print_epi32(Y);

        // [-(x1==y1), -(x2==y2), -(x3==y3), -(x4==y4)]
        print_epi32(_mm_cmpeq_epi32(X, Y));
        // [-(x1>y1), -(x2>y2), -(x3>y3), -(x4>y4)]
        print_epi32(_mm_cmpgt_epi32(X, Y));
        // [-(x1<y1), -(x2<y2), -(x3<y3), -(x4<y4)]
        print_epi32(_mm_cmplt_epi32(X, Y));
    }

    // 64bitの大小比較
    // SSE2では自作ラッパを使わざるをえない
    {
        cout << "# Compare" << endl;
        int64_t x[2] al = {1, 4};
        int64_t y[2] al = {0, 4};

        // x > y
        {
            cout << "-Greater than" << endl;
            // x        = [a, b]
            Int X = _mm_load_si128((Int*)x);
            print_epi64(X);
            // y        = [c, d]
            Int Y = _mm_load_si128((Int*)y);
            print_epi64(Y);

            // X is greater than Y 
            // x        = [-(a>c), -(b>d)]
            Int XgY = _mm_cmpgt_epi64(X, Y); 
            print_epi64(XgY);
        }

        // x == y
        {
            cout << "-Equal to" << endl;
            // x        = [a, b]
            Int X = _mm_load_si128((Int*)x);
            // y        = [c, d]
            Int Y = _mm_load_si128((Int*)y);

            // X is greater than Y 
            // x        = [-(a>c), -(b>d)]
            Int XgY = _mm_cmpeq_epi64(X, Y); 
            print_epi64(XgY);
        }

        // x >= y
        // 予めx[i]++かy[i]--しておく
        {
            cout << "-Greater than or Equal" << endl;
            rep(i, 2) 
                x[i]++;
            // x        = [a, b]
            Int X = _mm_load_si128((Int*)x);
            // y        = [c, d]
            Int Y = _mm_load_si128((Int*)y);

            // X is greater than Y 
            // x        = [-(a>c), -(b>d)]
            Int XgY = _mm_cmpgt_epi64(X, Y); 
            print_epi64(XgY);

            int32_t ret[4] al;
            _mm_store_si128((Int*)ret, XgY);
        }

    }


    // bit演算
    {
        // これはbit列として解釈させるので、値に意味はない
        uint8_t a[16] al = {3, 20, 10, 4, 8, 20, 50, 10, 4, 8, 4, 0, 40, 30, 38, 58};
        uint8_t b[16] al = {4, 80, 20, 4, 10, 30, 50, 10, 4, 8, 4, 0, 40, 30, 38, 58};
        Int A = _mm_load_si128((Int*)a);
        Int B = _mm_load_si128((Int*)b);
        printbits(A);
        printbits(B);
        cout << "----" << endl;

        printbits(_mm_and_si128(A, B)); // a & b
        printbits(_mm_or_si128(A, B)); // a | b
        printbits(_mm_xor_si128(A, B)); // a ^ b
        printbits(_mm_andnot_si128(A, B)); // (not a) & b
        
        // bit反転は？
//        printbits(_mm_not_si128(A)); // (not a) & b
    }


    return 0;
}
