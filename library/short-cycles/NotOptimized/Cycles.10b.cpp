/**
 * ---==== Counting the Number of 10-Cycles in a Bipartite Undirected Graph  ====---
 *                             with Int128 answer type
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
#define K 10     // The length of the cycles ( DO NOT CHANGE )

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

void c10b ( );

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

	c10b ( );
  	
	ans . print ( out );
	fclose ( out );

	return 0;
}

void c10b ( ) {
	TAnswer s, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33;
	int i1, i2, i3, i4;
	s = 0;

	/* FOUR */
	t1 = 0;
	for ( i1 = 0; i1 < n; i1 ++ ) {
		for ( i2 = 0; i2 < n; i2 ++ ) {
			for ( i3 = 0; i3 < n; i3 ++ ) {
				for ( i4 = 0; i4 < n; i4 ++ ) {
					t1 += A[1][i2][i3]*A[0][i1][i3]*A[1][i1][i4]*A[0][i3][i4]*A[0][i2][i4]*A[0][i1][i2];
				}
			}
		}
	}
	s += t1 * ( 55 );

	/* THREE */
	t1 = t2 = t3 = t4 = t5 = t6 = t7 = t8 = 0;
	for ( i1 = 0; i1 < n; i1 ++ ) {
		for ( i2 = 0; i2 < n; i2 ++ ) {
			for ( i3 = 0; i3 < n; i3 ++ ) {
				t1 += A[0][i1][i2]*A[0][i1][i3]*A[1][i2][i3]*A[1][i2][i3]*A[1][i2][i3]*A[1][i1][i1];
				t2 += A[2][i1][i3]*A[0][i1][i3]*A[1][i2][i3]*A[1][i2][i3]*A[0][i1][i2];
				t3 += A[1][i1][i3]*A[2][i1][i2]*A[1][i3][i3]*A[0][i2][i3]*A[0][i1][i2];
				t4 += A[1][i1][i2]*A[1][i3][i3]*A[1][i2][i3]*A[1][i2][i3];
				t5 += A[2][i1][i2]*A[0][i1][i2]*A[1][i2][i3]*A[1][i1][i1];
				t6 += A[1][i2][i2]*A[0][i1][i2]*A[1][i1][i3]*A[1][i3][i3]*A[0][i2][i3]*A[1][i1][i1];
				t7 += A[1][i2][i3]*A[1][i2][i3]*A[0][i1][i3]*A[0][i1][i2]*A[1][i1][i1];
				t8 += A[1][i1][i3]*A[1][i1][i2]*A[1][i1][i1];
			}
		}
	}
	s += t1 * ( -10 );
	s += t2 * ( -80 );
	s += t3 * ( -60 );
	s += t4 * ( -10 );
	s += t5 * ( -20 );
	s += t6 * ( -10 );
	s += t7 * ( 120 );
	s += t8 * ( 20 );

	/* TWO */
	t1 = t2 = t3 = t4 = t5 = t6 = t7 = t8 = t9 = t10 = t11 = t12 = t13 = t14 = t15 = t16 = t17 = t18 = t19 = t20 = t21 = t22 = t23 = t24 = t25 = t26 = t27 = t28 = t29 = t30 = t31 = t32 = t33 = 0;
	for ( i1 = 0; i1 < n; i1 ++ ) {
		for ( i2 = 0; i2 < n; i2 ++ ) {
			t1 += A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[3][i1][i2];
			t2 += A[2][i1][i2]*A[2][i1][i2]*A[2][i1][i2]*A[0][i1][i2];
			t3 += A[3][i1][i1]*A[3][i2][i2]*A[0][i1][i2];
			t4 += A[3][i2][i2]*A[1][i1][i1]*A[1][i1][i2]*A[1][i1][i2];
			t5 += A[3][i2][i2]*A[2][i1][i2]*A[0][i1][i2]*A[1][i1][i1];
			t6 += A[4][i1][i2]*A[2][i1][i2]*A[0][i1][i2];
			t7 += A[2][i1][i2]*A[2][i1][i2]*A[1][i2][i2]*A[1][i1][i1];
			t8 += A[1][i1][i2]*A[3][i1][i2]*A[1][i1][i1]*A[1][i2][i2];
			t9 += A[1][i1][i2]*A[5][i2][i2];
			t10 += A[1][i2][i2]*A[0][i1][i2]*A[4][i1][i2]*A[1][i1][i1];
			t11 += A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i1];
			t12 += A[1][i1][i2]*A[1][i1][i2]*A[3][i1][i2];
			t13 += A[1][i1][i1]*A[2][i1][i2]*A[2][i1][i2]*A[0][i1][i2];
			t14 += A[3][i2][i2]*A[2][i1][i2];
			t15 += A[3][i1][i1]*A[1][i1][i2]*A[1][i1][i1];
			t16 += A[1][i1][i1]*A[1][i1][i1]*A[1][i2][i2]*A[1][i1][i2]*A[1][i1][i2];
			t17 += A[1][i1][i1]*A[1][i1][i1]*A[3][i2][i2]*A[0][i1][i2];
			t18 += A[1][i1][i1]*A[1][i1][i1]*A[0][i1][i2]*A[1][i2][i2]*A[2][i1][i2];
			t19 += A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2];
			t20 += A[1][i1][i1]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2];
			t21 += A[2][i1][i2]*A[2][i1][i2]*A[0][i1][i2];
			t22 += A[1][i1][i1]*A[1][i1][i2]*A[1][i1][i2]*A[1][i2][i2];
			t23 += A[3][i2][i2]*A[1][i1][i2];
			t24 += A[2][i1][i2]*A[1][i2][i2]*A[0][i1][i2]*A[1][i1][i1];
			t25 += A[4][i1][i2];
			t26 += A[1][i1][i1]*A[1][i1][i1]*A[2][i1][i2];
			t27 += A[1][i1][i1]*A[1][i1][i1]*A[0][i1][i2]*A[1][i2][i2]*A[1][i2][i2];
			t28 += A[1][i1][i2]*A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i1];
			t29 += A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2];
			t30 += A[3][i1][i2];
			t31 += A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i2];
			t32 += A[2][i1][i2];
			t33 += A[1][i1][i2];
		}
	}
	s += t1 * ( 10 );
	s += t2 * ( 10 );
	s += t3 * ( 5 );
	s += t4 * ( 10 );
	s += t5 * ( 20 );
	s += t6 * ( 30 );
	s += t7 * ( 5 );
	s += t8 * ( 10 );
	s += t9 * ( 10 );
	s += t10 * ( 10 );
	s += t11 * ( -20 );
	s += t12 * ( -40 );
	s += t13 * ( -120 );
	s += t14 * ( -10 );
	s += t15 * ( -40 );
	s += t16 * ( -20 );
	s += t17 * ( -20 );
	s += t18 * ( -40 );
	s += t19 * ( 80 );
	s += t20 * ( 160 );
	s += t21 * ( 420 );
	s += t22 * ( 100 );
	s += t23 * ( 200 );
	s += t24 * ( 290 );
	s += t25 * ( 5 );
	s += t26 * ( 20 );
	s += t27 * ( 20 );
	s += t28 * ( 60 );
	s += t29 * ( -600 );
	s += t30 * ( -100 );
	s += t31 * ( -580 );
	s += t32 * ( 1040 );
	s += t33 * ( -2400 );

	/* ONE */
	t1 = t2 = t3 = t4 = t5 = t6 = t7 = t8 = t9 = t10 = t11 = t12 = t13 = t14 = t15 = t16 = t17 = 0;
	for ( i1 = 0; i1 < n; i1 ++ ) {
		t1 += A[9][i1][i1];
		t2 += A[3][i1][i1]*A[5][i1][i1];
		t3 += A[7][i1][i1]*A[1][i1][i1];
		t4 += A[3][i1][i1]*A[3][i1][i1]*A[1][i1][i1];
		t5 += A[7][i1][i1];
		t6 += A[1][i1][i1]*A[1][i1][i1]*A[5][i1][i1];
		t7 += A[3][i1][i1]*A[3][i1][i1];
		t8 += A[5][i1][i1]*A[1][i1][i1];
		t9 += A[3][i1][i1]*A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i1];
		t10 += A[5][i1][i1];
		t11 += A[3][i1][i1]*A[1][i1][i1]*A[1][i1][i1];
		t12 += A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i1];
		t13 += A[1][i1][i1]*A[3][i1][i1];
		t14 += A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i1];
		t15 += A[3][i1][i1];
		t16 += A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i1];
		t17 += A[1][i1][i1];
	}
	s += t1 * ( 1 );
	s += t2 * ( -10 );
	s += t3 * ( -10 );
	s += t4 * ( 20 );
	s += t5 * ( 10 );
	s += t6 * ( 20 );
	s += t7 * ( -100 );
	s += t8 * ( -140 );
	s += t9 * ( -60 );
	s += t10 * ( 95 );
	s += t11 * ( 580 );
	s += t12 * ( 48 );
	s += t13 * ( -2220 );
	s += t14 * ( -480 );
	s += t15 * ( 1460 );
	s += t16 * ( 1680 );
	s += t17 * ( 576 );

	ans = s /= 20;
}
