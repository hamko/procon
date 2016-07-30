/**
 * ---==== Counting the Number of 3-Cycles in an Undirected Graph  ====---
 *                 Parallel version with Int128 answer type
 *
 * AUTHORS: Anton N. Voropaev 
 * ```````  Artem M. Karavaev ( http://www.flowproblem.ru )
 *      
 * CREATED: 25.11.2009     
 * ```````     
 * VERSION: 6.0 ( from 21.03.2010 )     
 * ```````
 */

#include "mpi.h"

#define VERSION "6.0"

#define N 128   // The maximum number of vertices ( YOU MAY CHANGE IT )
#define K 3     // The length of the cycles ( DO NOT CHANGE )

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

void c3 ( );

#define MAIN 0
char nameOfProc [ MPI_MAX_PROCESSOR_NAME ];
int myId, numOfProcs, lenOfName;
double startTime, endTime, Time;
MPI_Status status;
int64 number [ 2 ];

void sumAndDiv ( TAnswer s, int k ) {
	int p;
	TAnswer tmp;
	if ( myId != MAIN ) {
		number [ 0 ] = s . l;
		number [ 1 ] = s . h;
    MPI_Send ( number, 2, MPI_LONG_LONG, MAIN, 1, MPI_COMM_WORLD );
	}
  if ( myId == MAIN ) {                                                     
		for ( p = 1; p < numOfProcs; p ++ ) {                               
			MPI_Recv ( number, 2, MPI_LONG_LONG, p, 1, MPI_COMM_WORLD, & status ); 
			tmp . l = number [ 0 ];
			tmp . h = number [ 1 ];
			s += tmp;   
		}
  }                                                                         
  ans = s;
  ans /= k;
}

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

  // Init MPI variables
	MPI_Init ( & argc, & argv );    
	MPI_Comm_size ( MPI_COMM_WORLD, & numOfProcs );
	MPI_Comm_rank ( MPI_COMM_WORLD, & myId );
	MPI_Get_processor_name ( nameOfProc, & lenOfName );

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
	if ( argc == 3 && myId == MAIN && ( out = fopen ( argv [ 2 ], "w" ) ) == NULL ) {
		fprintf ( stderr, "Cannot open file %s for writing\n", argv [ 2 ] );
		return 1;
	} 

	Init ( );
	fclose ( in );

	c3 ( );
  	
	if ( myId == MAIN ) {		
		ans . print ( out );
		fclose ( out );
	}

  // Waiting for all to finish at once
  MPI_Barrier ( MPI_COMM_WORLD );
	MPI_Finalize ( );

	return 0;
}

void c3 ( ) {
	TAnswer s, t1;
	int i, i1;
	s = 0;

	/* ONE */
	t1 = 0;
	for ( i1 = myId; i1 < n; i1 += numOfProcs ) {
		t1 += A[2][i1][i1];
	}
	s += t1 * ( 1 );

	sumAndDiv ( s, 6 );
}
