/**
 * ---==== Counting the Number of 10-Cycles in an undirected bipartite Graph  ====---
 *
 * AUTHORS: Anton N. Voropaev 
 * ```````  Artem M. Karavaev ( http://www.flowproblem.ru )
 *      
 * CREATED: 25.11.2009     
 * ```````     
 * VERSION: 6.0 ( from 18.03.2010 )     
 * ```````
 */

#define VERSION "6.0"

#define N 128   // The maximum number of vertices ( YOU MAY CHANGE IT )
#define K 10    // The length of the cycles ( DO NOT CHANGE )

#include "Int128.h"
using namespace Zeal;

typedef Int128 TAnswer;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m;
FILE * in, * out = stdout;

int A1 [ N ] [ N ];
int A2 [ N ] [ N ];
int A3 [ N ] [ N ];
int A4 [ N ] [ N ];
TAnswer A [ K ] [ N ] [ N ];

TAnswer c10b ( );

// Multiply A * B. A contains only 0 and 1.
void MulMatrix ( int A [ N ] [ N ], int B [ N ] [ N ], int C [ N ] [ N ] ) {
	int i, j, r;
	for ( i = 0; i < n; i ++ )		
		for ( r = 0; r < n; r ++ )
			if ( A [ i ] [ r ] )
				for ( j = 0; j < n; j ++ )
					C [ i ] [ j ] += B [ r ] [ j ];
}
// The same function but for Int128
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
	
	MulMatrix ( A1, A1, A2 );
	MulMatrix ( A1, A2, A3 );
	MulMatrix ( A1, A3, A4 );
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

	c10b ( ) . print ( out );

	return 0;
}

TAnswer c10b ( ) { 
	TAnswer s, t; int i1, i2, i3, i4, i5, i6; s = 0;
	int64u p = 0;

for ( i1 = 0; i1 < n; i1 ++ ) { 
for(i2 = 0; i2 < n; i2++) { 
for(i3 = 0; i3 < n; i3++) { 

	p = 0;
	if ( A1[i1][i2] )
		for(i4 = 0; i4 < n; i4++) {
			p += ( A2[i1][i4] * A2[i2][i3] ) * ( A1[i3][i4]&A1[i2][i4]&A1[i1][i3] );
		}
	s += TAnswer ( p ) * 55;

s += TAnswer ( 20) * A2[i1][i2]*A2[i1][i1]*A2[i1][i3];
s += TAnswer ( 120) * A1[i1][i2]*A1[i1][i3]*A2[i1][i1]*A2[i2][i3]*A2[i2][i3];
s += TAnswer ( -10) * A1[i2][i3]*A2[i2][i2]*A2[i1][i1]*A1[i1][i2]*A2[i3][i3]*A2[i1][i3];
s += TAnswer ( -20) * A2[i2][i3]*A2[i1][i1]*A3[i1][i2]*A1[i1][i2];
s += TAnswer ( -10) * A2[i1][i2]*A2[i3][i3]*A2[i2][i3]*A2[i2][i3];
s += TAnswer ( -60) * A1[i1][i2]*A3[i1][i2]*A2[i3][i3]*A1[i2][i3]*A2[i1][i3];
s += TAnswer ( -80) * A1[i1][i2]*A3[i1][i3]*A1[i1][i3]*A2[i2][i3]*A2[i2][i3];
s += TAnswer ( -10) * A1[i1][i3]*A2[i1][i1]*A2[i2][i3]*A2[i2][i3]*A2[i2][i3]*A1[i1][i2];
}
s += -2400 * A2[i1][i2];
s += 1040 * A3[i1][i2];
s += TAnswer ( -580) * A2[i1][i1]*A2[i1][i1]*A2[i1][i2];
s += -100 * A4[i1][i2];
s += TAnswer ( -600) * A2[i1][i2]*A2[i1][i2]*A2[i1][i2];
s += TAnswer ( 60) * A2[i1][i1]*A2[i1][i1]*A2[i1][i1]*A2[i1][i2];
s += TAnswer ( 20) * A1[i1][i2]*A2[i1][i1]*A2[i1][i1]*A2[i2][i2]*A2[i2][i2];
s += TAnswer ( 20) * A2[i1][i1]*A2[i1][i1]*A3[i1][i2];
s += 5 * A[4][i1][i2];
s += TAnswer ( 290) * A1[i1][i2]*A3[i1][i2]*A2[i1][i1]*A2[i2][i2];
s += TAnswer ( 200) * A4[i2][i2]*A2[i1][i2];
s += TAnswer ( 100) * A2[i1][i2]*A2[i1][i2]*A2[i1][i1]*A2[i2][i2];
s += TAnswer ( 420) * A1[i1][i2]*A3[i1][i2]*A3[i1][i2];
s += TAnswer ( 160) * A2[i1][i1]*A2[i1][i2]*A2[i1][i2]*A2[i1][i2];
s += TAnswer ( 80) * A2[i1][i2]*A2[i1][i2]*A2[i1][i2]*A2[i1][i2];
s += TAnswer ( -40) * A1[i1][i2]*A3[i1][i2]*A2[i1][i1]*A2[i1][i1]*A2[i2][i2];
s += TAnswer ( -20) * A4[i2][i2]*A1[i1][i2]*A2[i1][i1]*A2[i1][i1];
s += TAnswer ( -20) * A2[i1][i2]*A2[i1][i2]*A2[i1][i1]*A2[i1][i1]*A2[i2][i2];
s += TAnswer ( -40) * A2[i1][i2]*A4[i1][i1]*A2[i1][i1];
s += TAnswer ( -10) * A4[i2][i2]*A3[i1][i2];
s += TAnswer ( -120) * A1[i1][i2]*A2[i1][i1]*A3[i1][i2]*A3[i1][i2];
s += TAnswer ( -40) * A2[i1][i2]*A2[i1][i2]*A4[i1][i2];
s += TAnswer ( -20) * A2[i1][i1]*A2[i1][i2]*A2[i1][i2]*A2[i1][i2]*A2[i1][i2];
s += 10 * A[4][i1][i2]*A2[i2][i2]*A2[i1][i1]*A1[i1][i2];
s += 10 * A[5][i2][i2]*A2[i1][i2];
s += TAnswer ( 10) * A4[i1][i2]*A2[i1][i2]*A2[i2][i2]*A2[i1][i1];
s += TAnswer ( 5) * A2[i1][i1]*A2[i2][i2]*A3[i1][i2]*A3[i1][i2];
s += 30 * A1[i1][i2]*A[4][i1][i2]*A3[i1][i2];
s += TAnswer ( 20) * A2[i1][i1]*A3[i1][i2]*A4[i2][i2]*A1[i1][i2];
s += TAnswer ( 10) * A4[i2][i2]*A2[i1][i2]*A2[i1][i2]*A2[i1][i1];
s += TAnswer ( 5) * A4[i2][i2]*A4[i1][i1]*A1[i1][i2];
s += TAnswer ( 10) * A3[i1][i2]*A3[i1][i2]*A3[i1][i2]*A1[i1][i2];
s += TAnswer ( 10) * A4[i1][i2]*A2[i1][i2]*A2[i1][i2]*A2[i1][i2];
}
s += 576 * A2[i1][i1];
s += TAnswer ( 1680) * A2[i1][i1]*A2[i1][i1]*A2[i1][i1];
s += 1460 * A4[i1][i1];
s += TAnswer ( -480) * A2[i1][i1]*A2[i1][i1]*A2[i1][i1]*A2[i1][i1];
s += TAnswer ( -2220) * A4[i1][i1]*A2[i1][i1];
s += TAnswer ( 48) * A2[i1][i1]*A2[i1][i1]*A2[i1][i1]*A2[i1][i1]*A2[i1][i1];
s += TAnswer ( 580) * A4[i1][i1]*A2[i1][i1]*A2[i1][i1];
s += 95 * A[5][i1][i1];
s += TAnswer ( -60) * A4[i1][i1]*A2[i1][i1]*A2[i1][i1]*A2[i1][i1];
s += -140 * A2[i1][i1]*A[5][i1][i1];
s += TAnswer ( -100) * A4[i1][i1]*A4[i1][i1];
s += 20 * A[5][i1][i1]*A2[i1][i1]*A2[i1][i1];
s += 10 * A[7][i1][i1];
s += TAnswer ( 20) * A2[i1][i1]*A4[i1][i1]*A4[i1][i1];
s += -10 * A2[i1][i1]*A[7][i1][i1];
s += -10 * A4[i1][i1]*A[5][i1][i1];
s += 1 * A[9][i1][i1];
} 

	return s /= 20;
}
