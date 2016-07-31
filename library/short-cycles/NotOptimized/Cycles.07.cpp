/**
 * ---==== Counting the Number of 7-Cycles in an Undirected Graph  ====---
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
#define K 7     // The length of the cycles ( DO NOT CHANGE )

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

void c7 ( );

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

	c7 ( );
  	
	ans . print ( out );
	fclose ( out );

	return 0;
}

void c7 ( ) {
	TAnswer s, t1, t2, t3, t4, t5, t6, t7;
	int i1, i2;
	s = 0;

	/* TWO */
	t1 = t2 = t3 = t4 = t5 = 0;
	for ( i1 = 0; i1 < n; i1 ++ ) {
		for ( i2 = 0; i2 < n; i2 ++ ) {
			t1 += A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[0][i1][i2];
			t2 += A[2][i1][i2]*A[1][i1][i2]*A[0][i1][i2];
			t3 += A[2][i2][i2]*A[1][i1][i2];
			t4 += A[1][i1][i1]*A[1][i1][i2]*A[1][i2][i2]*A[0][i1][i2];
			t5 += A[0][i1][i2]*A[1][i1][i2]*A[1][i1][i2];
		}
	}
	s += t1 * ( 7 );
	s += t2 * ( 21 );
	s += t3 * ( 7 );
	s += t4 * ( 7 );
	s += t5 * ( -28 );

	/* ONE */
	t1 = t2 = t3 = t4 = t5 = t6 = t7 = 0;
	for ( i1 = 0; i1 < n; i1 ++ ) {
		t1 += A[6][i1][i1];
		t2 += A[2][i1][i1]*A[3][i1][i1];
		t3 += A[1][i1][i1]*A[4][i1][i1];
		t4 += A[4][i1][i1];
		t5 += A[2][i1][i1]*A[1][i1][i1]*A[1][i1][i1];
		t6 += A[2][i1][i1]*A[1][i1][i1];
		t7 += A[2][i1][i1];
	}
	s += t1 * ( 1 );
	s += t2 * ( -7 );
	s += t3 * ( -7 );
	s += t4 * ( 7 );
	s += t5 * ( 14 );
	s += t6 * ( -77 );
	s += t7 * ( 56 );

	ans = s /= 14;
}
