/**
 * ---==== Counting the Number of 9-Cycles in an Undirected Graph  ====---
 *                         with Int128 answer type
 *
 * AUTHORS: Anton N. Voropaev 
 * ```````  Artem M. Karavaev ( http://www.flowproblem.ru )
 *      
 * CREATED: 25.11.2009     
 * ```````     
 * VERSION: 6.0 ( from 21.03.2010 )     
 * ```````
 */

#define VERSION "6.0"

#define N 128   // The maximum number of vertices ( YOU MAY CHANGE IT )
#define K 9     // The length of the cycles ( DO NOT CHANGE )

#include "Int128.h"
using namespace Zeal;

typedef Int128 TAnswer;

#include <stdio.h>
#include <stdlib.h>

int n, m;
FILE * in, * out = stdout;

int A1 [ N ] [ N ];
TAnswer A [ K ] [ N ] [ N ];
TAnswer ans;

void c9 ( );

// Multiply A * B. A contains only 0 and 1.
void MulMatrix ( int A [ N ] [ N ], TAnswer B [ N ] [ N ], TAnswer C [ N ] [ N ] ) {
	int i, j, r;
	for ( i = 0; i < n; i ++ )		
		for ( r = 0; r < n; r ++ )
			if ( A [ i ] [ r ] )
				for ( j = 0; j < n; j ++ )
					C [ i ] [ j ] += B [ r ] [ j ];
}

void Init ( ) {
	int i, p, q;

	fscanf ( in, "%d %d", &n, &m );  	  
	if ( n > N ) {
	  fprintf ( stderr, "n is too big (%d), make constant `N' bigger\n", n );
		exit ( 1 );
	}
  for ( i = 0; i < m; i ++ ) {
  	fscanf ( in, "%d %d", &p, &q );
  	A1 [ p - 1 ] [ q - 1 ] = 1;
    A1 [ q - 1 ] [ p - 1 ] = 1;
  	A [ 0 ] [ p - 1 ] [ q - 1 ] = 1;
  	A [ 0 ] [ q - 1 ] [ p - 1 ] = 1;
  } 		
	
	for ( i = 1; i < K; i ++ ) 
		MulMatrix ( A1, A [ i - 1 ], A [ i ] );

}

int main ( int argc, char * argv [ ] ) {

	int i;

	if ( argc < 2 ) {
  	fprintf ( stderr, "Usage: %s ``input-file'' [ ``output-file'' ]\n", argv [ 0 ] );
  	return 0;
	}
	if ( argc > 3 ) {
  	fprintf ( stderr, "Too many parameters: %d\n", argc );
  	return 1;
	}
      
	if ( ( in = fopen ( argv [ 1 ], "r" ) ) == NULL ) {
		fprintf ( stderr, "Cannot open file %s for reading\n", argv [ 1 ] );
		return 1;
	}  
	if ( argc == 3 && ( out = fopen ( argv [ 2 ], "w" ) ) == NULL ) {
		fprintf ( stderr, "Cannot open file %s for writing\n", argv [ 2 ] );
		return 1;
	} 

	Init ( );
	fclose ( in );

	c9 ( );
  	
	ans . print ( out );
	fclose ( out );

	return 0;
}

void c9 ( ) {
	TAnswer s, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28;
	int i1, i2, i3, i4;
	s = 0;

	/* FOUR */
	t1 = t2 = t3 = 0;
	for ( i1 = 0; i1 < n; i1 ++ ) {
		for ( i2 = 0; i2 < n; i2 ++ ) {
			for ( i3 = 0; i3 < n; i3 ++ ) {
				for ( i4 = 0; i4 < n; i4 ++ ) {
					t1 += A[0][i1][i2]*A[1][i3][i4]*A[0][i1][i4]*A[0][i2][i4]*A[0][i1][i3]*A[0][i2][i3]*A[0][i3][i4];
					t2 += A[0][i1][i2]*A[0][i2][i4]*A[0][i1][i3]*A[1][i1][i4]*A[0][i2][i3]*A[0][i3][i4];
					t3 += A[0][i2][i3]*A[0][i1][i4]*A[0][i2][i4]*A[0][i3][i4]*A[0][i1][i3]*A[0][i1][i2];
				}
			}
		}
	}
	s += t1 * ( 99 );
	s += t2 * ( 99 );
	s += t3 * ( -156 );

	/* THREE */
	t1 = t2 = t3 = t4 = t5 = t6 = t7 = t8 = t9 = t10 = t11 = 0;
	for ( i1 = 0; i1 < n; i1 ++ ) {
		for ( i2 = 0; i2 < n; i2 ++ ) {
			for ( i3 = 0; i3 < n; i3 ++ ) {
				t1 += A[1][i1][i2]*A[0][i1][i2]*A[1][i2][i3]*A[1][i1][i3]*A[0][i2][i3]*A[0][i1][i3];
				t2 += A[1][i1][i1]*A[0][i1][i3]*A[0][i1][i2]*A[0][i2][i3]*A[1][i2][i3]*A[1][i2][i3];
				t3 += A[0][i1][i2]*A[1][i1][i3]*A[0][i1][i3]*A[1][i2][i3]*A[1][i2][i3];
				t4 += A[1][i1][i2]*A[0][i1][i2]*A[2][i3][i3]*A[0][i1][i3]*A[0][i2][i3];
				t5 += A[0][i1][i2]*A[0][i1][i3]*A[2][i1][i3]*A[1][i2][i3]*A[0][i2][i3];
				t6 += A[0][i1][i2]*A[2][i1][i2]*A[1][i3][i3]*A[0][i2][i3]*A[0][i1][i3];
				t7 += A[1][i1][i2]*A[0][i1][i2]*A[0][i2][i3]*A[1][i1][i3]*A[1][i3][i3];
				t8 += A[1][i1][i1]*A[1][i1][i2]*A[0][i1][i2]*A[1][i2][i3];
				t9 += A[1][i1][i1]*A[0][i1][i2]*A[1][i2][i2]*A[1][i3][i3]*A[0][i1][i3]*A[0][i2][i3];
				t10 += A[0][i1][i2]*A[0][i1][i3]*A[1][i1][i2]*A[1][i1][i3]*A[0][i2][i3];
				t11 += A[1][i1][i1]*A[0][i1][i3]*A[0][i1][i2]*A[0][i2][i3]*A[1][i2][i3];
			}
		}
	}
	s += t1 * ( -48 );
	s += t2 * ( -27 );
	s += t3 * ( -72 );
	s += t4 * ( -27 );
	s += t5 * ( -144 );
	s += t6 * ( -27 );
	s += t7 * ( -54 );
	s += t8 * ( -18 );
	s += t9 * ( -3 );
	s += t10 * ( 324 );
	s += t11 * ( 180 );

	/* TWO */
	t1 = t2 = t3 = t4 = t5 = t6 = t7 = t8 = t9 = t10 = t11 = t12 = t13 = t14 = t15 = t16 = t17 = t18 = t19 = t20 = t21 = t22 = t23 = t24 = t25 = t26 = t27 = t28 = 0;
	for ( i1 = 0; i1 < n; i1 ++ ) {
		for ( i2 = 0; i2 < n; i2 ++ ) {
			t1 += A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[2][i1][i2];
			t2 += A[0][i1][i2]*A[2][i1][i1]*A[2][i2][i2]*A[1][i1][i2];
			t3 += A[1][i1][i2]*A[2][i1][i2]*A[2][i1][i2]*A[0][i1][i2];
			t4 += A[0][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[3][i1][i2];
			t5 += A[0][i1][i2]*A[2][i1][i1]*A[3][i2][i2];
			t6 += A[1][i1][i1]*A[2][i2][i2]*A[1][i1][i2]*A[1][i1][i2];
			t7 += A[1][i1][i1]*A[1][i1][i2]*A[0][i1][i2]*A[3][i2][i2];
			t8 += A[1][i1][i1]*A[0][i1][i2]*A[2][i1][i2]*A[2][i2][i2];
			t9 += A[0][i1][i2]*A[3][i1][i2]*A[2][i1][i2];
			t10 += A[1][i1][i2]*A[0][i1][i2]*A[4][i1][i2];
			t11 += A[1][i1][i1]*A[1][i1][i2]*A[1][i2][i2]*A[2][i1][i2];
			t12 += A[4][i2][i2]*A[1][i1][i2];
			t13 += A[1][i1][i1]*A[0][i1][i2]*A[1][i2][i2]*A[3][i1][i2];
			t14 += A[1][i1][i1]*A[0][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2];
			t15 += A[0][i1][i2]*A[2][i1][i1]*A[1][i1][i2]*A[1][i1][i2];
			t16 += A[1][i1][i2]*A[1][i1][i2]*A[2][i1][i2];
			t17 += A[3][i1][i2]*A[1][i1][i2]*A[0][i1][i2];
			t18 += A[1][i1][i1]*A[1][i1][i2]*A[0][i1][i2]*A[2][i1][i2];
			t19 += A[2][i2][i2]*A[2][i1][i2];
			t20 += A[2][i1][i1]*A[1][i1][i1]*A[1][i1][i2];
			t21 += A[1][i1][i1]*A[1][i1][i1]*A[2][i2][i2]*A[0][i1][i2];
			t22 += A[1][i1][i1]*A[1][i1][i1]*A[0][i1][i2]*A[1][i1][i2]*A[1][i2][i2];
			t23 += A[0][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2];
			t24 += A[1][i1][i1]*A[0][i1][i2]*A[1][i1][i2]*A[1][i1][i2];
			t25 += A[2][i1][i2]*A[1][i1][i2]*A[0][i1][i2];
			t26 += A[1][i1][i2]*A[2][i2][i2];
			t27 += A[1][i1][i1]*A[1][i1][i2]*A[0][i1][i2]*A[1][i2][i2];
			t28 += A[0][i1][i2]*A[1][i1][i2]*A[1][i1][i2];
		}
	}
	s += t1 * ( 9 );
	s += t2 * ( 9 );
	s += t3 * ( 27 );
	s += t4 * ( 27 );
	s += t5 * ( 9 );
	s += t6 * ( 9 );
	s += t7 * ( 18 );
	s += t8 * ( 18 );
	s += t9 * ( 27 );
	s += t10 * ( 27 );
	s += t11 * ( 9 );
	s += t12 * ( 9 );
	s += t13 * ( 9 );
	s += t14 * ( -72 );
	s += t15 * ( -108 );
	s += t16 * ( -36 );
	s += t17 * ( -36 );
	s += t18 * ( -216 );
	s += t19 * ( -9 );
	s += t20 * ( -36 );
	s += t21 * ( -18 );
	s += t22 * ( -36 );
	s += t23 * ( 336 );
	s += t24 * ( 288 );
	s += t25 * ( 684 );
	s += t26 * ( 171 );
	s += t27 * ( 252 );
	s += t28 * ( -1296 );

	/* ONE */
	t1 = t2 = t3 = t4 = t5 = t6 = t7 = t8 = t9 = t10 = t11 = t12 = t13 = t14 = t15 = t16 = 0;
	for ( i1 = 0; i1 < n; i1 ++ ) {
		t1 += A[8][i1][i1];
		t2 += A[4][i1][i1]*A[3][i1][i1];
		t3 += A[2][i1][i1]*A[5][i1][i1];
		t4 += A[6][i1][i1]*A[1][i1][i1];
		t5 += A[2][i1][i1]*A[2][i1][i1]*A[2][i1][i1];
		t6 += A[3][i1][i1]*A[2][i1][i1]*A[1][i1][i1];
		t7 += A[6][i1][i1];
		t8 += A[4][i1][i1]*A[1][i1][i1]*A[1][i1][i1];
		t9 += A[3][i1][i1]*A[2][i1][i1];
		t10 += A[4][i1][i1]*A[1][i1][i1];
		t11 += A[2][i1][i1]*A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i1];
		t12 += A[2][i1][i1]*A[2][i1][i1];
		t13 += A[4][i1][i1];
		t14 += A[2][i1][i1]*A[1][i1][i1]*A[1][i1][i1];
		t15 += A[2][i1][i1]*A[1][i1][i1];
		t16 += A[2][i1][i1];
	}
	s += t1 * ( 1 );
	s += t2 * ( -9 );
	s += t3 * ( -9 );
	s += t4 * ( -9 );
	s += t5 * ( 6 );
	s += t6 * ( 36 );
	s += t7 * ( 9 );
	s += t8 * ( 18 );
	s += t9 * ( -171 );
	s += t10 * ( -117 );
	s += t11 * ( -54 );
	s += t12 * ( 72 );
	s += t13 * ( 81 );
	s += t14 * ( 504 );
	s += t15 * ( -1746 );
	s += t16 * ( 1148 );

	ans = s /= 18;
}
