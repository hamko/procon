/**
 * ---==== Counting the Number of 9-Cycles in an Undirected Graph  ====---
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

	c9 ( );
  	
	if ( myId == MAIN ) {		
		ans . print ( out );
		fclose ( out );
	}

  // Waiting for all to finish at once
  MPI_Barrier ( MPI_COMM_WORLD );
	MPI_Finalize ( );

	return 0;
}

void c9 ( ) {
	TAnswer s, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28;
	int i, i1, i2, i3, i4;
	s = 0;

	/* FOUR */
	t1 = t2 = t3 = 0;
	for ( i = myId; i < n * n; i += numOfProcs ) {
		i1 = i / n;
		i2 = i - i1 * n;

		for ( i3 = 0; i3 < n; i3 ++ ) {
			for ( i4 = 0; i4 < n; i4 ++ ) {
				t1 += A[0][i1][i2]*A[1][i3][i4]*A[0][i1][i4]*A[0][i2][i4]*A[0][i1][i3]*A[0][i2][i3]*A[0][i3][i4];
				t2 += A[0][i1][i2]*A[0][i2][i4]*A[0][i1][i3]*A[1][i1][i4]*A[0][i2][i3]*A[0][i3][i4];
				t3 += A[0][i2][i3]*A[0][i1][i4]*A[0][i2][i4]*A[0][i3][i4]*A[0][i1][i3]*A[0][i1][i2];
			}
		}
	}
	s += t1 * ( 99 );
	s += t2 * ( 99 );
	s += t3 * ( -156 );

	/* THREE */
	t1 = t2 = t3 = t4 = t5 = t6 = t7 = t8 = t9 = t10 = t11 = 0;
	for ( i = myId; i < n * n; i += numOfProcs ) {
		i1 = i / n;
		i2 = i - i1 * n;

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
	for ( i = myId; i < n * n; i += numOfProcs ) {
		i1 = i / n;
		i2 = i - i1 * n;

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
	for ( i1 = myId; i1 < n; i1 += numOfProcs ) {
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

	sumAndDiv ( s, 18 );
}
