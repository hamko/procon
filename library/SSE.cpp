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
// __mm_store[nead align]_si128(void* dst, __m128[, i, d] src)
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
// SSE4.1で追加された命令のラッパー。
 
// 64bit整数2つの比較 (greater than)
// [ a_0, a_1 ], [ b_0, b_1 ]
//   => [ (a_0 > b_0 ? -1 : 0), (a_1 > b_1 ? -1 : 0) ]
static inline __m128i __attribute__((always_inline))
_mm_cmpgt_epi64(__m128i a, __m128i b){
	__asm__("pcmpgtq %1, %0" : "+x" (a) : "xm" (b));
	return a;
}
 
// 32bit整数2つの積 (64bitに拡張)
// [ a_0, a_1, a_2, a_3 ] * [ b_0, b_1, b_2, b_3 ]
//   => [ (ll)a_0 * b_0, (ll)a_2 * b_2 ]
static inline __m128i __attribute__((always_inline))
_mm_mul_epi32(__m128i a, __m128i b){
	__asm__("pmuldq %1, %0" : "+x" (a) : "xm" (b));
	return a;
}
 

int main(void)
{
    // 簡単なチュートリアル
    {
        int32_t a[4] __attribute__((aligned(16))) = {1, 2, 3, 4};
        __m128i A = _mm_load_si128((__m128i*)a);
        __m128i AplusA = _mm_add_epi32(A, A);
        int32_t ret[4] __attribute__((aligned(16)));
        _mm_store_si128((__m128i*)ret, AplusA);
        cout << ret[0] << ret[1] << ret[2] << ret[3] << endl;
    }

    // 省略版
    {
        int32_t a[4] al = {1, 2, 3, 4};
        Int A = _mm_load_si128((Int*)a);
        Int AplusA = _mm_add_epi32(A, A);
        int32_t ret[4] al;
        _mm_store_si128((Int*)ret, AplusA);
        cout << ret[0] << ret[1] << ret[2] << ret[3] << endl;
    }

    // 乗算
    {
        int32_t a[4] al = {10000, 0, 10000000, 0};
        Int A = _mm_load_si128((Int*)a);
        Int AmulA = _mm_mul_epi32(A, A);
        int64_t ret[2] al;
        _mm_store_si128((Int*)ret, AmulA);
        cout << ret[0] << " " << ret[1] << endl;
    }

    // 小さいやつ
    {
        uint8_t a[16] al = {3, 20, 10, 4, 8, 20, 50, 10, 4, 8, 4, 0, 40, 30, 38, 58};
        uint8_t b[16] al = {4, 80, 20, 4, 10, 30, 50, 10, 4, 8, 4, 0, 40, 30, 38, 58};
        Int A = _mm_load_si128((Int*)a);
        Int B = _mm_load_si128((Int*)b);
//        Int AaddsA = _mm_max_epu8(A, B);
//        Int AaddsA = _mm_adds_epu8(A, B);
        Int AaddsA = _mm_avg_epu8(A, B); // 小数点以下切り上げっぽい　
        uint8_t ret[16] al;
        _mm_store_si128((Int*)ret, AaddsA);
        for (int i = 0; i < 16; i++)
            cout << (int)ret[i] << " ";
        cout << endl;
    }





    return 0;
}
