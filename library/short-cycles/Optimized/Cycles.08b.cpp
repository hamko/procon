/**
 * ---==== Counting the Number of 8-Cycles in an undirected bipartite Graph  ====---
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

int A1 [ N ] [ N ];
int A2 [ N ] [ N ];
int A3 [ N ] [ N ];
int A4 [ N ] [ N ];
TAnswer A [ K ] [ N ] [ N ];

TAnswer c8b ( );

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

	c8b ( ) . print ( out );

	return 0;
}

TAnswer c8b ( ) { 
	TAnswer s, t; int i1, i2; 
	s = 0;
	for ( i1 = 0; i1 < n; i1 ++ ) { 
		for(i2 = 0; i2 < n; i2++) {
			s += -132 * A2[i1][i2];
			s += 48 * A3[i1][i2];
			s += TAnswer(-16) * A2[i1][i1]*A2[i1][i1]*A2[i1][i2];
			s += -4 * A4[i1][i2];
			s += TAnswer(-16) * A2[i1][i2]*A2[i1][i2]*A2[i1][i2];
			s += TAnswer(8) * A1[i1][i2]*A2[i1][i1]*A2[i2][i2]*A3[i1][i2];
			s += TAnswer(8) * A4[i2][i2]*A2[i1][i2];
			s += TAnswer(4) * A2[i1][i1]*A2[i2][i2]*A2[i1][i2]*A2[i1][i2];
			s += TAnswer(12) * A3[i1][i2]*A3[i1][i2]*A1[i1][i2];
			s += TAnswer(2) * A2[i1][i2]*A2[i1][i2]*A2[i1][i2]*A2[i1][i2];
		}
		s += 36 * A2[i1][i1];
		s += TAnswer(72) * A2[i1][i1]*A2[i1][i1]*A2[i1][i1];
		s += 73 * A4[i1][i1];
		s += TAnswer(-12) * A2[i1][i1]*A2[i1][i1]*A2[i1][i1]*A2[i1][i1];
		s += TAnswer(-96) * A4[i1][i1]*A2[i1][i1];
		s += TAnswer(16) * A4[i1][i1]*A2[i1][i1]*A2[i1][i1];
		s += 8 * A[5][i1][i1];
		s += TAnswer(-8) * A2[i1][i1]*A[5][i1][i1];
		s += TAnswer(-4) * A4[i1][i1]*A4[i1][i1];
		s += A[7][i1][i1];
	}
	return s /= 16;
}
