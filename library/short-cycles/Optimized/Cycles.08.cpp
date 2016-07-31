/**
 * ---==== Counting the Number of 8-Cycles in an undirected Graph  ====---
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
#define K 8     // The length of the cycles ( DO NOT CHANGE )

#include "Int128.h"
using namespace Zeal;

typedef Int128 TAnswer;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m;
FILE * in, * out = stdout;
//char str [ 16 ];

int A1 [ N ] [ N ];
int A2 [ N ] [ N ];
int A3 [ N ] [ N ];
TAnswer A [ K ] [ N ] [ N ];

TAnswer c8 ( );

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

	c8 ( ) . print ( out );

	return 0;
}

TAnswer c8 ( ) { 
	TAnswer s, t; 
	
	int i1, i2, i3, i4; 
	int64u t1, t2, t3, t4;
	
	s = 0;
	
	for ( i1 = 0; i1 < n; i1 ++ ) { 		

		for(i2 = 0; i2 < n; i2++) { 

			t1 = t2 = t3 = 0;
			if ( A1[i1][i2] ) {
	      for(i3 = 0; i3 < n; i3++) { 	      	
	      	if ( A1[i1][i3] && A1[i2][i3] ) {
						for(i4 = 0; i4 < n; i4++) {
							t1 += ( A1[i3][i4]&A1[i1][i4]&A1[i2][i4] );
						}					
						t2 += A2[i3][i3];
						t3 += (int64u)A2[i2][i3]*A2[i1][i3];
					}
				}
				t2 *= A2[i1][i2];
			}

			s += TAnswer (  22 ) * t1;
			s += TAnswer ( -24 ) * t2;
			s += TAnswer ( -64 ) * t3;

			s += -132 * A[1][i1][i2];
			s += 48 * A[2][i1][i2];
			s += 272 * A[1][i1][i2]*A[1][i1][i2]*A[0][i1][i2];
			s += -16 * A[1][i1][i2]*A[1][i1][i1]*A[1][i1][i1];
			s += -4 * A[3][i1][i2];
			s += -96 * A[1][i1][i1]*A[1][i1][i2]*A[1][i1][i2]*A[0][i1][i2];
			s += -32 * A[0][i1][i2]*A[1][i1][i2]*A[2][i1][i2];
			s += -16 * A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2];
			s += 8 * A[1][i2][i2]*A[0][i1][i2]*A[1][i1][i1]*A[2][i1][i2];
			s += 8 * A[1][i1][i2]*A[3][i2][i2];
			s += 4 * A[1][i1][i1]*A[1][i1][i2]*A[1][i1][i2]*A[1][i2][i2];
			s += 24 * A[0][i1][i2]*A[3][i1][i2]*A[1][i1][i2];
			s += 12 * A[0][i1][i2]*A[2][i1][i2]*A[2][i1][i2];
			s += 16 * A[0][i1][i2]*A[1][i1][i1]*A[1][i1][i2]*A[2][i2][i2];
			s += 4 * A[2][i1][i1]*A[2][i2][i2]*A[0][i1][i2];
			s += 24 * A[1][i1][i2]*A[1][i1][i2]*A[0][i1][i2]*A[2][i1][i2];
			s += 2 * A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2];
		}
		s += 36 * A[1][i1][i1];
		s += -112 * A[2][i1][i1];
		s += 72 * A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i1];
		s += 73 * A[3][i1][i1];
		s += 64 * A[1][i1][i1]*A[2][i1][i1];
		s += -12 * A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i1];
		s += -96 * A[3][i1][i1]*A[1][i1][i1];
		s += -72 * A[2][i1][i1]*A[2][i1][i1];
		s += 16 * A[3][i1][i1]*A[1][i1][i1]*A[1][i1][i1];
		s += 8 * A[5][i1][i1];
		s += 16 * A[1][i1][i1]*A[2][i1][i1]*A[2][i1][i1];
		s += -8 * A[1][i1][i1]*A[5][i1][i1];
		s += -8 * A[2][i1][i1]*A[4][i1][i1];
		s += -4 * A[3][i1][i1]*A[3][i1][i1];
		s += 1 * A[7][i1][i1];
	} 
	return s /= 16;
}
