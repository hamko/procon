/**
 * ---==== Counting the Number of 3-Cycles in an undirected Graph  ====---
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
#define K 3     // The length of the cycles ( DO NOT CHANGE )

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

TAnswer c3 ( );

// Multiply A * B. A contains only 0 and 1.
void MulMatrix ( int A [ N ] [ N ], int B [ N ] [ N ], int C [ N ] [ N ] ) {
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
  }
	
	MulMatrix ( A1, A1, A2 );
	MulMatrix ( A1, A2, A3 );

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

	c3 ( ) . print ( out );

	return 0;
}

TAnswer c3 ( ) {
	TAnswer s; 
	int i; 
	s = 0;
	for ( i = 0; i < n; i ++ )
		s += A3 [ i ] [ i ];	
	s /= 6;	
	return s;
}
