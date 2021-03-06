/**
 * ---==== Counting the Number of 11-Cycles in an undirected Graph  ====---
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
#define K 11     // The length of the cycles ( DO NOT CHANGE )

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
int A4 [ N ] [ N ];
TAnswer A [ K ] [ N ] [ N ];

TAnswer c11 ( );

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

	c11 ( ) . print ( out );

	return 0;
}

TAnswer c11 ( ) { 
	TAnswer s, t; int i1, i2, i3, i4, i5; s = 0;
	int i, m = n * n;

	int64u t1  = 0, t2  = 0, t3  = 0, t4  = 0, t5  = 0, t6  = 0, t7  = 0, t8  = 0, t9  = 0, t10 = 0,
	       t11 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0, t16 = 0, t17 = 0, t18 = 0, t19 = 0, t20 = 0,
	       t21 = 0, t22 = 0, t23 = 0, t24 = 0, t25 = 0, t26 = 0, t27 = 0, t28 = 0, t29 = 0, t30 = 0,
	       t31 = 0, t32 = 0, t33 = 0, t34 = 0, t35 = 0, t36 = 0, t37 = 0, t38 = 0, t39 = 0, t40 = 0,
	       t41 = 0, t42 = 0, t43 = 0, t44 = 0, t45 = 0, t46 = 0, t47 = 0, t48 = 0, t49 = 0, t50 = 0,
	       t51 = 0, t52 = 0, t53 = 0, t54 = 0, t55 = 0, t56 = 0, t57 = 0, t58 = 0, t59 = 0, t60 = 0;

	for ( i = 0; i < m; i ++ ) { 
		i1 = i / n;
		i2 = i - i1 * n;	
		if ( A1[i1][i2] ) {
			for(i3 = 0; i3 < n; i3++) 
				if ( A1[i1][i3] )
				for(i4 = 0; i4 < n; i4++)  
					if ( A1[i2][i4] )
					for(i5 = 0; i5 < n; i5++) {
						t1 += ( A1[i4][i5]&A1[i1][i5]&A1[i3][i5]&A1[i2][i3]&A1[i1][i4] );
						t2 += ( A1[i1][i5]&A1[i2][i5]&A1[i3][i5]&A1[i3][i4]&A1[i1][i4]&A1[i4][i5] );
						t3 += ( A2[i5][i5]*(A1[i1][i5]&A1[i4][i5]&A1[i2][i3]&A1[i3][i4]) );
						t4 += ( A2[i1][i5]*(A1[i2][i3]&A1[i4][i5]&A1[i3][i5]&A1[i3][i4]) );
						t5 += ( A2[i3][i5]*(A1[i1][i5]&A1[i4][i5]&A1[i2][i3]&A1[i3][i4]) );
						t6 += ( A2[i5][i5]*(A1[i1][i4]&A1[i2][i3]&A1[i4][i5]&A1[i3][i5]&A1[i3][i4]) );
						t7 += ( A2[i4][i5]*(A1[i3][i5]&A1[i4][i5]&A1[i1][i4]&A1[i2][i3]) );
						t8 += ( A2[i4][i5]*(A1[i1][i5]&A1[i2][i3]&A1[i4][i5]&A1[i3][i5]&A1[i3][i4]) );
						t9 += ( A2[i1][i5]*(A1[i2][i3]&A1[i3][i4]&A1[i4][i5]&A1[i3][i5]&A1[i2][i5]&A1[i1][i4]) );
					}
		}
	}	

	s += ( TAnswer ( t1 ) ) * ( 1540 );
	s += ( TAnswer ( t2 ) ) * ( 1628 );
	s += ( TAnswer ( t3 ) ) * ( -121 );
	s += ( TAnswer ( t4 ) ) * ( -330 );
	s += ( TAnswer ( t5 ) ) * ( -660 );
	s += ( TAnswer ( t6 ) ) * ( -121 );
	s += ( TAnswer ( t7 ) ) * ( -308 );
	s += ( TAnswer ( t8 ) ) * ( -660 );
	s += ( TAnswer ( t9 ) ) * ( -242 );

	t1 = t2 = t3 = t4 = t5 = t6 = t7 = t8 = t9 = 0;
	
	for ( i = 0; i < m; i ++ ) { 
		i1 = i / n;
		i2 = i - i1 * n;	
		for(i3 = 0; i3 < n; i3++)  
			for(i4 = 0; i4 < n; i4++) { 
				t1  += A1[i1][i4]*A1[i1][i2]*A1[i2][i4]*A1[i2][i3]*A1[i1][i3]*A1[i3][i4];
				t2  += A1[i1][i4]*A1[i1][i2]*A1[i2][i4]*A2[i1][i1]*A1[i3][i4]*A1[i2][i3]*A1[i1][i3];
				t3  += A1[i1][i2]*A1[i2][i4]*A1[i2][i3]*A2[i1][i4]*A1[i1][i3]*A1[i3][i4];
				t4  += A1[i1][i4]*A1[i1][i2]*A2[i3][i4]*A1[i2][i4]*A1[i2][i3]*A1[i1][i3]*A1[i3][i4];
				t5  += A1[i1][i2]*A1[i2][i4]*A1[i2][i3]*A2[i1][i1]*A1[i1][i3]*A1[i3][i4]*A2[i4][i4];
				t6  += A1[i1][i4]*A1[i1][i2]*A1[i2][i4]*A2[i1][i3]*A2[i2][i4];
				t7  += A1[i1][i2]*A1[i1][i4]*A1[i2][i3]*A3[i3][i4]*A1[i2][i4]*A1[i1][i3];
				t8  += A1[i1][i2]*A2[i4][i4]*A1[i1][i4]*A2[i1][i2]*A1[i2][i3]*A1[i3][i4]*A1[i1][i3];
				t9  += A1[i1][i2]*A2[i3][i4]*A1[i1][i4]*A2[i2][i3]*A1[i2][i4]*A1[i1][i3];
				t10 += A1[i1][i2]*A2[i1][i1]*A1[i1][i3]*A1[i2][i4]*A2[i1][i4]*A1[i3][i4]*A1[i2][i3];
				t11 += A1[i1][i2]*A2[i1][i1]*A1[i1][i4]*A1[i3][i4]*A1[i1][i3]*A2[i2][i4]*A1[i2][i3];
				t12 += A1[i2][i3]*A1[i1][i4]*A2[i3][i4]*A1[i3][i4]*A2[i1][i2]*A1[i1][i2];
				t13 += A1[i1][i2]*A3[i1][i4]*A1[i1][i4]*A1[i2][i3]*A1[i3][i4]*A1[i2][i4]*A1[i1][i3];
				t14 += A1[i1][i2]*A2[i3][i4]*A1[i1][i4]*A1[i2][i3]*A1[i2][i4]*A1[i1][i3]*A2[i1][i4];
				t15 += A1[i1][i2]*A1[i1][i4]*A1[i3][i4]*A2[i2][i3]*A1[i2][i4]*A1[i1][i3]*A2[i1][i4];
				t16 += A1[i1][i2]*A1[i1][i4]*A2[i3][i4]*A2[i1][i2]*A1[i2][i4]*A1[i3][i4]*A1[i1][i3];
				t17 += A1[i1][i2]*A2[i1][i1]*A1[i1][i4]*A2[i3][i4]*A1[i1][i3]*A1[i2][i4]*A1[i3][i4]*A1[i2][i3];
				t18 += A1[i1][i2]*A1[i3][i4]*A2[i1][i4]*A2[i1][i4]*A1[i2][i4]*A1[i2][i3]*A1[i1][i3];
				t19 += A1[i1][i2]*A2[i1][i4]*A2[i1][i2]*A1[i2][i3]*A1[i1][i4]*A1[i3][i4]*A1[i1][i3];
				t20 += A1[i1][i2]*A1[i2][i4]*A1[i1][i4]*A1[i1][i3]*A3[i1][i1]*A1[i2][i3]*A1[i3][i4];
				t21 += A2[i1][i1]*A1[i2][i4]*A1[i1][i4]*A1[i3][i4]*A1[i1][i3]*A1[i2][i3]*A2[i1][i4]*A1[i1][i2];
				t22 += A1[i1][i2]*A1[i3][i4]*A1[i1][i4]*A1[i2][i4]*A1[i2][i3]*A2[i1][i4]*A2[i1][i3]*A1[i1][i3];
				t23 += A2[i1][i1]*A2[i3][i4]*A2[i2][i2]*A1[i2][i3]*A1[i1][i3]*A1[i1][i2];
				t24 += A1[i2][i3]*A2[i2][i3]*A2[i3][i4]*A2[i1][i2];
				t25 += A2[i1][i2]*A2[i4][i4]*A1[i1][i4]*A1[i2][i3]*A1[i3][i4]*A2[i3][i3]*A1[i1][i2];
				t26 += A2[i1][i2]*A1[i2][i3]*A2[i1][i3]*A2[i3][i4]*A1[i1][i2];
				t27 += A1[i2][i3]*A3[i1][i2]*A2[i3][i4]*A1[i1][i3]*A1[i1][i2];
				t28 += A1[i1][i3]*A1[i2][i3]*A2[i1][i4]*A2[i4][i4]*A1[i1][i2]*A1[i2][i4]*A2[i3][i3];
				t29 += A1[i1][i3]*A1[i2][i3]*A1[i3][i4]*A4[i1][i4]*A1[i2][i4]*A1[i1][i2];
				t30 += A1[i1][i3]*A1[i2][i3]*A2[i1][i4]*A2[i2][i3]*A2[i4][i4]*A1[i3][i4]*A1[i1][i2];
				t31 += A1[i1][i3]*A1[i2][i3]*A2[i3][i4]*A2[i2][i3]*A2[i4][i4]*A1[i1][i4]*A1[i1][i2];
				t32 += A1[i1][i3]*A1[i2][i3]*A1[i3][i4]*A2[i2][i4]*A3[i1][i4]*A1[i1][i2];
				t33 += A1[i1][i3]*A1[i2][i3]*A2[i4][i4]*A1[i3][i4]*A1[i1][i4]*A1[i1][i2]*A3[i2][i3];
				t34 += A2[i1][i2]*A1[i3][i4]*A1[i2][i3]*A2[i3][i4]*A1[i1][i2]*A2[i1][i4];
				t35 += A2[i1][i2]*A1[i3][i4]*A1[i2][i3]*A1[i1][i4]*A3[i3][i4]*A1[i1][i2];
				t36 += A2[i1][i2]*A2[i4][i4]*A1[i3][i4]*A1[i1][i3]*A1[i2][i3]*A2[i3][i4]*A1[i1][i2];
				t37 += A2[i1][i2]*A1[i3][i4]*A3[i4][i4]*A1[i1][i3]*A1[i2][i3]*A1[i1][i2];
				t38 += A1[i1][i3]*A1[i3][i4]*A2[i2][i3]*A3[i1][i4]*A1[i2][i4]*A1[i1][i2];
				t39 += A1[i1][i3]*A2[i2][i3]*A2[i2][i3]*A2[i4][i4]*A1[i3][i4]*A1[i1][i4]*A1[i1][i2];
				t40 += A1[i1][i3]*A2[i1][i4]*A2[i2][i4]*A2[i2][i3]*A1[i3][i4]*A1[i1][i2];
				t41 += A1[i1][i3]*A2[i1][i3]*A2[i4][i4]*A1[i2][i4]*A1[i3][i4]*A2[i2][i3]*A1[i1][i2];
				t42 += A1[i1][i3]*A1[i2][i3]*A1[i1][i2]*A1[i2][i4]*A1[i1][i4]*A3[i4][i4]*A2[i3][i3];
				t43 += A1[i1][i3]*A2[i1][i3]*A1[i3][i4]*A2[i2][i4]*A2[i2][i4]*A1[i1][i2];
				t44 += A1[i1][i2]*A1[i2][i3]*A2[i4][i4]*A1[i2][i4]*A1[i3][i4]*A2[i2][i3]*A1[i1][i3]*A2[i1][i1];
				t45 += A2[i3][i4]*A2[i3][i4]*A1[i3][i4]*A1[i2][i3]*A1[i2][i4]*A2[i1][i2];
				t46 += A1[i2][i3]*A1[i1][i3]*A1[i3][i4]*A1[i2][i4]*A3[i1][i4]*A2[i3][i4]*A1[i1][i2];
				t47 += A1[i2][i3]*A1[i1][i3]*A1[i3][i4]*A2[i1][i4]*A1[i2][i4]*A3[i3][i4]*A1[i1][i2];
				t48 += A1[i2][i3]*A1[i1][i3]*A1[i3][i4]*A1[i1][i4]*A1[i2][i4]*A4[i3][i4]*A1[i1][i2];
				t49 += A1[i2][i3]*A1[i1][i3]*A1[i3][i4]*A2[i2][i3]*A3[i4][i4]*A1[i1][i4]*A1[i1][i2];
				t50 += A1[i2][i3]*A1[i1][i3]*A2[i1][i4]*A1[i2][i4]*A2[i3][i4]*A2[i3][i4]*A1[i1][i2];
				t51 += A1[i2][i3]*A1[i1][i3]*A1[i1][i4]*A1[i2][i4]*A3[i3][i4]*A2[i3][i4]*A1[i1][i2];
				t52 += A1[i2][i3]*A1[i1][i3]*A2[i2][i4]*A1[i3][i4]*A2[i3][i4]*A2[i1][i4]*A1[i1][i2];
				t53 += A2[i1][i2]*A2[i3][i4]*A2[i3][i4]*A1[i3][i4]*A1[i1][i4]*A1[i2][i3]*A1[i1][i2];
				t54 += A2[i3][i4]*A1[i3][i4]*A1[i1][i3]*A2[i2][i3]*A2[i1][i4]*A1[i1][i2]*A1[i2][i4];
				t55 += A1[i1][i3]*A2[i2][i4]*A1[i3][i4]*A2[i2][i3]*A2[i3][i4]*A1[i1][i4]*A1[i1][i2];
				t56 += A2[i3][i4]*A1[i3][i4]*A1[i1][i3]*A2[i2][i4]*A2[i1][i3]*A1[i1][i2]*A1[i2][i4];
				t57 += A2[i2][i3]*A1[i2][i3]*A2[i1][i1]*A1[i1][i2]*A1[i2][i4]*A2[i3][i4]*A1[i3][i4]*A1[i1][i4];
				t58 += A1[i1][i2]*A1[i1][i3]*A1[i2][i3]*A1[i2][i4]*A2[i2][i3]*A1[i1][i4]*A1[i3][i4]*A3[i1][i4];
				t59 += A2[i1][i4]*A1[i1][i2]*A1[i1][i3]*A1[i2][i3]*A1[i2][i4]*A2[i2][i3]*A2[i3][i4]*A1[i1][i4];
				t60 += A1[i2][i4]*A2[i1][i2]*A1[i1][i4]*A1[i1][i2]*A1[i1][i3]*A1[i2][i3]*A2[i3][i4]*A2[i3][i4];
			}
	}

	s += TAnswer ( t1 )*(-16984) ; 
	s += TAnswer ( t2 )*(4004  ) ; 
	s += TAnswer ( t3 )*(8668  ) ; 
	s += TAnswer ( t4 )*(15796 ) ; 
	s += TAnswer ( t5 )*(-176  ) ; 
	s += TAnswer ( t6 )*(-220  ) ; 
	s += TAnswer ( t7 )*(-572  ) ; 
	s += TAnswer ( t8 )*(-792  ) ; 
	s += TAnswer ( t9 )*(-880  ) ; 
	s += TAnswer ( t10)*(-968  ) ; 
	s += TAnswer ( t11)*(-968  ) ; 
	s += TAnswer ( t12)*(-132  ) ; 
	s += TAnswer ( t13)*(-1144 ) ; 
	s += TAnswer ( t14)*(-2288 ) ; 
	s += TAnswer ( t15)*(-1298 ) ; 
	s += TAnswer ( t16)*(-2112 ) ; 
	s += TAnswer ( t17)*(-968  ) ; 
	s += TAnswer ( t18)*(-572  ) ; 
	s += TAnswer ( t19)*(-2112 ) ; 
	s += TAnswer ( t20)*(-484  ) ; 
	s += TAnswer ( t21)*(-968  ) ; 
	s += TAnswer ( t22)*(-2288 ) ; 
	s += TAnswer ( t23)*(11    ) ; 
	s += TAnswer ( t24)*(11    ) ; 
	s += TAnswer ( t25)*(33    ) ; 
	s += TAnswer ( t26)*(66    ) ; 
	s += TAnswer ( t27)*(33    ) ; 
	s += TAnswer ( t28)*(66    ) ; 
	s += TAnswer ( t29)*(121   ) ; 
	s += TAnswer ( t30)*(176   ) ; 
	s += TAnswer ( t31)*(176   ) ; 
	s += TAnswer ( t32)*(242   ) ; 
	s += TAnswer ( t33)*(176   ) ; 
	s += TAnswer ( t34)*(99    ) ; 
	s += TAnswer ( t35)*(209   ) ; 
	s += TAnswer ( t36)*(66    ) ; 
	s += TAnswer ( t37)*(33    ) ; 
	s += TAnswer ( t38)*(121   ) ; 
	s += TAnswer ( t39)*(88    ) ; 
	s += TAnswer ( t40)*(121   ) ; 
	s += TAnswer ( t41)*(176   ) ; 
	s += TAnswer ( t42)*(33    ) ; 
	s += TAnswer ( t43)*(55    ) ; 
	s += TAnswer ( t44)*(33    ) ; 
	s += TAnswer ( t45)*(33    ) ; 
	s += TAnswer ( t46)*(484   ) ; 
	s += TAnswer ( t47)*(484   ) ; 
	s += TAnswer ( t48)*(121   ) ; 
	s += TAnswer ( t49)*(176   ) ; 
	s += TAnswer ( t50)*(242   ) ; 
	s += TAnswer ( t51)*(121   ) ; 
	s += TAnswer ( t52)*(242   ) ; 
	s += TAnswer ( t53)*(99    ) ; 
	s += TAnswer ( t54)*(242   ) ; 
	s += TAnswer ( t55)*(242   ) ; 
	s += TAnswer ( t56)*(220   ) ; 
	s += TAnswer ( t57)*(176   ) ; 
	s += TAnswer ( t58)*(242   ) ; 
	s += TAnswer ( t59)*(484   ) ; 
	s += TAnswer ( t60)*(121   ) ; 

	for ( i1 = 0; i1 < n; i1 ++ ) { 
		for(i2 = 0; i2 < n; i2++) { 
			for(i3 = 0; i3 < n; i3++) { 
				s += 12936 * A[0][i1][i3]*A[0][i1][i2]*A[0][i2][i3]*A[1][i1][i1]*A[1][i2][i3];
				s += 33792 * A[0][i1][i2]*A[1][i1][i2]*A[0][i2][i3]*A[0][i1][i3]*A[1][i1][i3];
				s += -198 * A[0][i2][i3]*A[0][i1][i3]*A[1][i1][i1]*A[1][i3][i3]*A[0][i1][i2]*A[1][i2][i2];
				s += -792 * A[1][i2][i3]*A[1][i1][i1]*A[0][i1][i2]*A[1][i1][i2];
				s += -880 * A[0][i1][i3]*A[0][i1][i2]*A[0][i2][i3]*A[1][i2][i3]*A[1][i1][i1]*A[1][i1][i1];
				s += -3124 * A[0][i1][i2]*A[1][i1][i2]*A[0][i2][i3]*A[1][i1][i3]*A[1][i3][i3];
				s += -1694 * A[0][i1][i2]*A[0][i2][i3]*A[0][i1][i3]*A[2][i1][i2]*A[1][i3][i3];
				s += -1760 * A[0][i1][i2]*A[0][i2][i3]*A[1][i2][i2]*A[1][i1][i1]*A[0][i1][i3]*A[1][i1][i3];
				s += -352 * A[0][i1][i3]*A[1][i1][i2]*A[1][i1][i3]*A[1][i1][i3];
				s += -3564 * A[0][i1][i2]*A[1][i1][i2]*A[1][i1][i1]*A[0][i2][i3]*A[1][i1][i3]*A[0][i1][i3];
				s += -10208 * A[0][i1][i2]*A[2][i1][i3]*A[1][i2][i3]*A[0][i2][i3]*A[0][i1][i3];
				s += -1837 * A[0][i1][i3]*A[0][i1][i2]*A[2][i3][i3]*A[1][i1][i2]*A[0][i2][i3];
				s += -5016 * A[0][i1][i2]*A[0][i1][i3]*A[1][i1][i3]*A[1][i2][i3]*A[1][i2][i3];
				s += -2090 * A[1][i1][i1]*A[0][i1][i3]*A[0][i2][i3]*A[0][i1][i2]*A[1][i2][i3]*A[1][i2][i3];
				s += -3168 * A[0][i1][i2]*A[1][i1][i2]*A[0][i2][i3]*A[1][i1][i3]*A[0][i1][i3]*A[1][i2][i2];
				s += -1056 * A[1][i2][i3]*A[0][i1][i3]*A[1][i1][i2]*A[0][i1][i2]*A[1][i1][i3];
				s += -4752 * A[0][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[0][i2][i3]*A[1][i2][i3]*A[0][i1][i3];
				s += -3872 * A[0][i1][i2]*A[1][i2][i3]*A[1][i1][i3]*A[1][i1][i2]*A[0][i2][i3]*A[0][i1][i3];
				s += 22 * A[1][i3][i3]*A[0][i1][i3]*A[1][i1][i1]*A[1][i1][i1]*A[0][i2][i3]*A[0][i1][i2]*A[1][i2][i2];
				s += 44 * A[1][i1][i1]*A[1][i1][i1]*A[1][i2][i3]*A[0][i1][i2]*A[1][i1][i2];
				s += 44 * A[0][i2][i3]*A[1][i1][i1]*A[1][i1][i1]*A[1][i3][i3]*A[0][i1][i2]*A[1][i2][i3];
				s += 88 * A[1][i1][i1]*A[0][i1][i3]*A[1][i1][i2]*A[1][i3][i3]*A[1][i1][i3];
				s += 44 * A[1][i1][i1]*A[0][i1][i3]*A[1][i1][i2]*A[2][i3][i3];
				s += 22 * A[1][i1][i2]*A[2][i2][i2]*A[1][i2][i3];
				s += 22 * A[1][i1][i1]*A[1][i1][i2]*A[2][i2][i3]*A[0][i1][i2];
				s += 176 * A[0][i1][i2]*A[1][i1][i1]*A[0][i1][i3]*A[0][i2][i3]*A[3][i2][i3];
				s += 264 * A[0][i1][i2]*A[1][i1][i1]*A[1][i1][i2]*A[1][i3][i3]*A[0][i2][i3]*A[1][i1][i3];
				s += 264 * A[0][i1][i2]*A[1][i1][i1]*A[1][i3][i3]*A[0][i1][i3]*A[1][i2][i3]*A[1][i1][i2];
				s += 220 * A[0][i1][i2]*A[1][i1][i1]*A[2][i2][i3]*A[1][i2][i3]*A[0][i1][i3];
				s += 264 * A[2][i1][i2]*A[0][i1][i2]*A[1][i1][i1]*A[1][i3][i3]*A[0][i2][i3]*A[0][i1][i3];
				s += 132 * A[0][i2][i3]*A[1][i1][i1]*A[1][i1][i1]*A[0][i1][i2]*A[1][i2][i3]*A[1][i1][i3];
				s += 66 * A[0][i2][i3]*A[0][i1][i2]*A[0][i1][i3]*A[2][i2][i3]*A[1][i1][i1]*A[1][i1][i1];
				s += 264 * A[1][i1][i2]*A[2][i1][i2]*A[1][i1][i3]*A[0][i1][i2];
				s += 88 * A[0][i1][i2]*A[1][i1][i2]*A[1][i3][i3]*A[0][i2][i3]*A[2][i1][i3];
				s += 44 * A[0][i1][i2]*A[1][i1][i2]*A[1][i1][i3]*A[1][i3][i3]*A[1][i2][i3];
				s += 88 * A[1][i3][i3]*A[0][i1][i3]*A[1][i1][i2]*A[1][i1][i2]*A[1][i2][i3];
				s += 792 * A[0][i1][i3]*A[1][i1][i2]*A[0][i2][i3]*A[3][i1][i3]*A[0][i1][i2];
				s += 1012 * A[0][i1][i3]*A[1][i1][i2]*A[2][i1][i3]*A[1][i2][i3]*A[0][i1][i2];
				s += 396 * A[0][i1][i3]*A[1][i1][i2]*A[1][i1][i3]*A[0][i1][i2]*A[2][i2][i3];
				s += 704 * A[1][i2][i3]*A[2][i1][i3]*A[1][i1][i1]*A[0][i1][i3]*A[0][i2][i3]*A[0][i1][i2];
				s += 704 * A[2][i2][i3]*A[1][i1][i1]*A[0][i1][i3]*A[0][i2][i3]*A[1][i1][i3]*A[0][i1][i2];
				s += 264 * A[1][i1][i2]*A[1][i1][i1]*A[0][i1][i2]*A[0][i2][i3]*A[0][i1][i3]*A[2][i3][i3];
				s += 396 * A[0][i1][i3]*A[2][i1][i3]*A[0][i2][i3]*A[2][i1][i2]*A[0][i1][i2];
				s += 352 * A[1][i1][i1]*A[0][i1][i3]*A[1][i1][i3]*A[0][i1][i2]*A[1][i2][i3]*A[1][i2][i3];
				s += 352 * A[0][i2][i3]*A[1][i2][i3]*A[1][i1][i1]*A[0][i1][i2]*A[1][i1][i3]*A[1][i1][i3];
				s += 66 * A[0][i2][i3]*A[0][i1][i2]*A[0][i1][i3]*A[1][i1][i1]*A[1][i1][i1]*A[1][i2][i3]*A[1][i2][i3];
				s += 176 * A[0][i2][i3]*A[2][i1][i1]*A[0][i1][i3]*A[2][i2][i3]*A[0][i1][i2];
				s += 264 * A[1][i1][i2]*A[1][i3][i3]*A[0][i1][i3]*A[2][i1][i1]*A[0][i2][i3]*A[0][i1][i2];
				s += 132 * A[2][i1][i1]*A[1][i2][i3]*A[1][i2][i3]*A[0][i1][i3]*A[0][i1][i2];
				s += 704 * A[0][i1][i2]*A[1][i1][i2]*A[0][i2][i3]*A[2][i1][i3]*A[0][i1][i3]*A[1][i1][i1];
				s += 264 * A[1][i1][i2]*A[1][i1][i2]*A[0][i1][i2]*A[1][i3][i3]*A[0][i2][i3]*A[0][i1][i3]*A[1][i1][i1];
				s += 352 * A[0][i1][i2]*A[1][i1][i2]*A[0][i2][i3]*A[1][i1][i1]*A[1][i1][i3]*A[1][i1][i3];
				s += 132 * A[1][i1][i1]*A[1][i2][i3]*A[2][i1][i1]*A[0][i2][i3]*A[0][i1][i2]*A[0][i1][i3];
				s += 264 * A[1][i1][i3]*A[1][i3][i3]*A[1][i1][i2]*A[1][i1][i2]*A[0][i1][i2]*A[0][i1][i3];
				s += 132 * A[1][i1][i2]*A[1][i1][i2]*A[0][i1][i2]*A[0][i1][i3]*A[2][i3][i3];
				s += 220 * A[1][i2][i3]*A[3][i1][i1]*A[0][i1][i2]*A[0][i2][i3]*A[0][i1][i3];
				s += 88 * A[0][i1][i2]*A[1][i1][i2]*A[0][i2][i3]*A[2][i3][i3]*A[1][i1][i3];
				s += 110 * A[0][i1][i2]*A[1][i1][i2]*A[1][i2][i3]*A[1][i2][i3]*A[1][i1][i3];
				s += 88 * A[0][i2][i3]*A[1][i1][i2]*A[1][i2][i3]*A[1][i2][i3]*A[1][i2][i3];
				s += 1584 * A[0][i1][i3]*A[1][i1][i2]*A[2][i1][i3]*A[1][i1][i3]*A[0][i2][i3]*A[0][i1][i2];
				s += 792 * A[1][i1][i3]*A[1][i1][i3]*A[0][i1][i3]*A[1][i1][i2]*A[1][i2][i3]*A[0][i1][i2];
				s += 704 * A[2][i1][i1]*A[0][i2][i3]*A[1][i2][i3]*A[0][i1][i3]*A[1][i1][i3]*A[0][i1][i2];
				s += 792 * A[0][i2][i3]*A[0][i1][i3]*A[2][i1][i2]*A[1][i1][i3]*A[1][i1][i3]*A[0][i1][i2];
				s += 704 * A[1][i2][i3]*A[0][i2][i3]*A[1][i1][i1]*A[0][i1][i2]*A[1][i1][i2]*A[1][i1][i3]*A[0][i1][i3];
				s += 264 * A[1][i1][i2]*A[1][i1][i3]*A[1][i1][i3]*A[1][i1][i3]*A[0][i1][i2]*A[0][i2][i3];
				s += 352 * A[0][i2][i3]*A[0][i1][i3]*A[2][i3][i3]*A[1][i2][i3]*A[1][i1][i3]*A[0][i1][i2];
				s += 396 * A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i3]*A[1][i1][i3]*A[0][i1][i2]*A[0][i2][i3]*A[0][i1][i3];
				s += -11 * A[1][i1][i1]*A[0][i1][i2]*A[1][i3][i3]*A[2][i1][i3]*A[1][i2][i2]*A[0][i2][i3];
				s += -11 * A[1][i1][i1]*A[0][i1][i2]*A[1][i1][i3]*A[1][i3][i3]*A[1][i2][i2]*A[1][i2][i3];
				s += -22 * A[1][i1][i1]*A[0][i1][i2]*A[1][i2][i3]*A[3][i1][i2];
				s += -22 * A[1][i1][i2]*A[1][i3][i3]*A[2][i2][i3]*A[1][i2][i3];
				s += -66 * A[1][i1][i2]*A[3][i1][i3]*A[0][i2][i3]*A[1][i3][i3]*A[0][i1][i2];
				s += -66 * A[1][i3][i3]*A[2][i1][i3]*A[1][i2][i3]*A[1][i1][i2]*A[0][i1][i2];
				s += -66 * A[2][i1][i2]*A[1][i3][i3]*A[0][i2][i3]*A[2][i1][i3]*A[0][i1][i2];
				s += -33 * A[1][i2][i3]*A[2][i1][i2]*A[1][i1][i3]*A[1][i3][i3]*A[0][i1][i2];
				s += -33 * A[0][i2][i3]*A[0][i1][i3]*A[4][i1][i2]*A[1][i3][i3]*A[0][i1][i2];
				s += -66 * A[1][i1][i3]*A[1][i3][i3]*A[0][i1][i2]*A[0][i2][i3]*A[3][i1][i2];
				s += -22 * A[1][i1][i1]*A[0][i1][i2]*A[1][i2][i2]*A[0][i2][i3]*A[1][i1][i3]*A[2][i3][i3];
				s += -11 * A[1][i1][i1]*A[0][i1][i2]*A[1][i2][i2]*A[0][i1][i3]*A[0][i2][i3]*A[3][i3][i3];
				s += -11 * A[1][i1][i1]*A[0][i1][i2]*A[1][i1][i3]*A[2][i2][i2]*A[1][i3][i3]*A[0][i2][i3];
				s += -44 * A[1][i2][i3]*A[1][i3][i3]*A[0][i2][i3]*A[1][i1][i1]*A[0][i1][i2]*A[2][i1][i2];
				s += -22 * A[1][i1][i1]*A[0][i1][i2]*A[2][i3][i3]*A[0][i2][i3]*A[2][i1][i2];
				s += -22 * A[1][i1][i1]*A[0][i1][i2]*A[1][i1][i2]*A[0][i2][i3]*A[3][i3][i3];
				s += -22 * A[1][i1][i1]*A[0][i1][i2]*A[1][i1][i2]*A[1][i2][i3]*A[1][i2][i3]*A[1][i3][i3];
				s += -22 * A[1][i1][i2]*A[2][i3][i3]*A[0][i2][i3]*A[2][i2][i3];
				s += -22 * A[1][i1][i2]*A[1][i2][i3]*A[0][i2][i3]*A[3][i3][i3];
				s += -11 * A[1][i1][i2]*A[2][i3][i3]*A[1][i2][i3]*A[1][i2][i3];
				s += -11 * A[1][i1][i1]*A[2][i3][i3]*A[0][i2][i3]*A[1][i1][i2]*A[1][i1][i2];
				s += -176 * A[1][i2][i3]*A[0][i2][i3]*A[0][i1][i3]*A[4][i1][i3]*A[0][i1][i2];
				s += -176 * A[0][i2][i3]*A[0][i1][i3]*A[0][i1][i2]*A[2][i2][i3]*A[3][i1][i3];
				s += -66 * A[0][i2][i3]*A[2][i1][i3]*A[2][i3][i3]*A[1][i1][i2]*A[0][i1][i2];
				s += -66 * A[0][i2][i3]*A[3][i3][i3]*A[1][i1][i3]*A[1][i1][i2]*A[0][i1][i2];
				s += -33 * A[4][i3][i3]*A[0][i2][i3]*A[0][i1][i3]*A[1][i1][i2]*A[0][i1][i2];
				s += -33 * A[1][i1][i3]*A[2][i3][i3]*A[1][i1][i2]*A[0][i1][i2]*A[1][i2][i3];
				s += -88 * A[0][i1][i3]*A[0][i1][i2]*A[1][i2][i3]*A[1][i2][i3]*A[3][i1][i3];
				s += -176 * A[1][i2][i3]*A[0][i1][i3]*A[0][i1][i2]*A[2][i2][i3]*A[2][i1][i3];
				s += -176 * A[1][i2][i3]*A[0][i1][i3]*A[1][i1][i3]*A[3][i2][i3]*A[0][i1][i2];
				s += -66 * A[0][i2][i3]*A[1][i1][i3]*A[2][i3][i3]*A[0][i1][i2]*A[2][i1][i2];
				s += -33 * A[3][i3][i3]*A[0][i2][i3]*A[0][i1][i3]*A[0][i1][i2]*A[2][i1][i2];
				s += -88 * A[0][i1][i3]*A[1][i1][i3]*A[2][i2][i3]*A[2][i2][i3]*A[0][i1][i2];
				s += -88 * A[1][i1][i3]*A[2][i1][i3]*A[1][i2][i3]*A[1][i2][i3]*A[0][i1][i2];
				s += -33 * A[2][i3][i3]*A[3][i1][i2]*A[0][i1][i2]*A[0][i1][i3]*A[0][i2][i3];
				s += -66 * A[1][i1][i1]*A[0][i1][i2]*A[2][i1][i3]*A[0][i2][i3]*A[1][i2][i3]*A[1][i2][i3];
				s += -132 * A[1][i1][i3]*A[1][i1][i1]*A[0][i1][i2]*A[1][i2][i3]*A[0][i2][i3]*A[2][i2][i3];
				s += -66 * A[1][i1][i1]*A[0][i1][i2]*A[1][i2][i3]*A[0][i2][i3]*A[3][i2][i3]*A[0][i1][i3];
				s += -11 * A[1][i1][i1]*A[2][i3][i3]*A[0][i1][i2]*A[2][i2][i2]*A[0][i2][i3]*A[0][i1][i3];
				s += -33 * A[1][i1][i1]*A[0][i1][i2]*A[0][i2][i3]*A[2][i2][i3]*A[2][i2][i3]*A[0][i1][i3];
				s += -22 * A[1][i1][i1]*A[0][i1][i2]*A[1][i1][i3]*A[1][i2][i3]*A[1][i2][i3]*A[1][i2][i3];
				s += -33 * A[1][i1][i1]*A[0][i1][i2]*A[2][i2][i3]*A[1][i2][i3]*A[1][i2][i3]*A[0][i1][i3];
				s += -44 * A[1][i1][i1]*A[0][i1][i2]*A[2][i3][i3]*A[1][i2][i3]*A[1][i1][i2]*A[0][i2][i3];
				s += -33 * A[1][i1][i2]*A[1][i1][i1]*A[0][i2][i3]*A[1][i2][i3]*A[1][i2][i3]*A[1][i1][i3];
				s += -22 * A[1][i1][i2]*A[2][i3][i3]*A[0][i2][i3]*A[2][i1][i1]*A[0][i1][i2];
				s += -176 * A[0][i1][i3]*A[0][i2][i3]*A[1][i2][i3]*A[3][i1][i3]*A[1][i1][i2]*A[0][i1][i2];
				s += -176 * A[2][i1][i3]*A[2][i2][i3]*A[0][i1][i3]*A[0][i2][i3]*A[1][i1][i2]*A[0][i1][i2];
				s += -66 * A[1][i1][i2]*A[1][i1][i2]*A[0][i2][i3]*A[1][i1][i3]*A[2][i3][i3]*A[0][i1][i2];
				s += -33 * A[3][i3][i3]*A[1][i1][i2]*A[1][i1][i2]*A[0][i2][i3]*A[0][i1][i3]*A[0][i1][i2];
				s += -176 * A[2][i1][i3]*A[1][i2][i3]*A[1][i2][i3]*A[0][i1][i3]*A[1][i1][i2]*A[0][i1][i2];
				s += -176 * A[1][i1][i3]*A[2][i2][i3]*A[1][i2][i3]*A[0][i1][i3]*A[1][i1][i2]*A[0][i1][i2];
				s += -66 * A[2][i3][i3]*A[1][i1][i2]*A[0][i1][i2]*A[0][i1][i3]*A[0][i2][i3]*A[2][i1][i2];
				s += -44 * A[1][i1][i2]*A[0][i1][i2]*A[1][i2][i3]*A[1][i2][i3]*A[1][i1][i3]*A[1][i1][i3];
				s += -11 * A[0][i1][i3]*A[1][i2][i3]*A[1][i2][i3]*A[1][i2][i3]*A[2][i1][i1]*A[0][i1][i2];
			}
			s += -68464 * A[0][i1][i2]*A[1][i1][i2]*A[1][i1][i2];
			s += 10692 * A[0][i1][i2]*A[1][i1][i1]*A[1][i1][i2]*A[1][i2][i2];
			s += 5170 * A[2][i2][i2]*A[1][i1][i2];
			s += 25432 * A[0][i1][i2]*A[1][i1][i2]*A[2][i1][i2];
			s += 25256 * A[0][i1][i2]*A[1][i1][i1]*A[1][i1][i2]*A[1][i1][i2];
			s += 19712 * A[0][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2];
			s += -2640 * A[0][i1][i2]*A[1][i1][i2]*A[1][i1][i1]*A[1][i1][i1]*A[1][i2][i2];
			s += -792 * A[0][i1][i2]*A[2][i2][i2]*A[1][i1][i1]*A[1][i1][i1];
			s += -1914 * A[1][i1][i2]*A[1][i1][i1]*A[2][i1][i1];
			s += -297 * A[2][i2][i2]*A[2][i1][i2];
			s += -12716 * A[0][i1][i2]*A[1][i1][i2]*A[1][i1][i1]*A[2][i1][i2];
			s += -1584 * A[0][i1][i2]*A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i2]*A[1][i1][i2];
			s += -1738 * A[3][i1][i2]*A[0][i1][i2]*A[1][i1][i2];
			s += -1364 * A[2][i1][i2]*A[1][i1][i2]*A[1][i1][i2];
			s += -880 * A[0][i1][i2]*A[2][i2][i2]*A[1][i1][i2]*A[1][i1][i1];
			s += -704 * A[1][i1][i1]*A[0][i1][i2]*A[1][i2][i2]*A[1][i1][i2]*A[1][i1][i2];
			s += -88 * A[0][i1][i2]*A[2][i2][i2]*A[2][i1][i1];
			s += -7920 * A[0][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[2][i1][i1];
			s += -6468 * A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i1]*A[0][i1][i2];
			s += -1848 * A[2][i1][i2]*A[0][i1][i2]*A[1][i1][i2]*A[1][i1][i2];
			s += -616 * A[0][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2];
			s += 132 * A[0][i1][i2]*A[1][i2][i2]*A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i2];
			s += 66 * A[0][i1][i2]*A[2][i2][i2]*A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i1];
			s += 198 * A[1][i1][i1]*A[1][i1][i1]*A[2][i1][i1]*A[1][i1][i2];
			s += 330 * A[1][i1][i1]*A[0][i1][i2]*A[1][i2][i2]*A[3][i1][i2];
			s += 231 * A[1][i1][i2]*A[4][i2][i2];
			s += 231 * A[1][i1][i1]*A[2][i1][i2]*A[1][i2][i2]*A[1][i1][i2];
			s += 44 * A[1][i1][i1]*A[1][i1][i1]*A[0][i1][i2]*A[1][i2][i2]*A[1][i2][i2]*A[1][i1][i2];
			s += 88 * A[2][i2][i2]*A[1][i1][i1]*A[1][i1][i1]*A[0][i1][i2]*A[1][i2][i2];
			s += 22 * A[2][i2][i2]*A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i2];
			s += 44 * A[1][i1][i1]*A[2][i1][i2]*A[2][i1][i1];
			s += 11 * A[2][i2][i2]*A[3][i1][i2];
			s += 1188 * A[2][i1][i2]*A[0][i1][i2]*A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i2];
			s += 847 * A[0][i1][i2]*A[4][i1][i2]*A[1][i1][i2];
			s += 902 * A[2][i1][i2]*A[0][i1][i2]*A[3][i1][i2];
			s += 792 * A[1][i1][i1]*A[2][i1][i2]*A[2][i2][i2]*A[0][i1][i2];
			s += 792 * A[1][i1][i1]*A[3][i2][i2]*A[0][i1][i2]*A[1][i1][i2];
			s += 297 * A[1][i1][i1]*A[2][i2][i2]*A[1][i1][i2]*A[1][i1][i2];
			s += 528 * A[2][i1][i2]*A[0][i1][i2]*A[1][i1][i1]*A[1][i1][i2]*A[1][i2][i2];
			s += 352 * A[1][i1][i1]*A[0][i1][i2]*A[3][i1][i2]*A[1][i1][i2];
			s += 352 * A[1][i1][i1]*A[2][i1][i2]*A[1][i1][i2]*A[1][i1][i2];
			s += 297 * A[2][i1][i1]*A[0][i1][i2]*A[3][i2][i2];
			s += 55 * A[1][i1][i2]*A[2][i1][i2]*A[2][i1][i2];
			s += 1188 * A[1][i1][i1]*A[1][i1][i2]*A[1][i1][i2]*A[2][i1][i1]*A[0][i1][i2];
			s += 396 * A[0][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i1]*A[1][i1][i1];
			s += 528 * A[1][i1][i1]*A[2][i2][i2]*A[1][i1][i2]*A[1][i1][i2]*A[0][i1][i2];
			s += 1298 * A[1][i1][i2]*A[1][i1][i2]*A[0][i1][i2]*A[3][i1][i2];
			s += 1298 * A[1][i1][i2]*A[2][i1][i2]*A[2][i1][i2]*A[0][i1][i2];
			s += 462 * A[2][i2][i2]*A[2][i1][i1]*A[0][i1][i2]*A[1][i1][i2];
			s += 352 * A[2][i1][i2]*A[2][i1][i1]*A[0][i1][i2]*A[1][i1][i2];
			s += 176 * A[2][i1][i1]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2];
			s += 176 * A[0][i1][i2]*A[1][i1][i1]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[1][i2][i2];
			s += 363 * A[2][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2];
			s += 352 * A[3][i1][i1]*A[1][i1][i2]*A[1][i1][i2]*A[0][i1][i2];
			s += 440 * A[2][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[0][i1][i2];
			s += 44 * A[0][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2];
			s += -44 * A[1][i1][i1]*A[1][i1][i1]*A[0][i1][i2]*A[3][i1][i2]*A[1][i2][i2];
			s += -22 * A[1][i1][i1]*A[1][i1][i1]*A[0][i1][i2]*A[4][i2][i2];
			s += -44 * A[1][i2][i2]*A[2][i1][i2]*A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i2];
			s += -44 * A[1][i1][i1]*A[4][i1][i1]*A[1][i1][i2];
			s += -11 * A[4][i2][i2]*A[2][i1][i2];
			s += -264 * A[1][i1][i1]*A[4][i1][i2]*A[1][i1][i2]*A[0][i1][i2];
			s += -264 * A[1][i1][i1]*A[2][i1][i2]*A[0][i1][i2]*A[3][i1][i2];
			s += -44 * A[1][i1][i1]*A[1][i1][i1]*A[0][i1][i2]*A[2][i1][i2]*A[2][i2][i2];
			s += -44 * A[1][i1][i1]*A[1][i1][i1]*A[3][i2][i2]*A[1][i1][i2]*A[0][i1][i2];
			s += -22 * A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i1]*A[1][i1][i1]*A[2][i2][i2];
			s += -88 * A[1][i1][i1]*A[2][i1][i1]*A[1][i2][i2]*A[2][i1][i2]*A[0][i1][i2];
			s += -44 * A[1][i1][i1]*A[2][i1][i1]*A[0][i1][i2]*A[3][i2][i2];
			s += -44 * A[1][i1][i1]*A[1][i2][i2]*A[2][i1][i1]*A[1][i1][i2]*A[1][i1][i2];
			s += -88 * A[1][i1][i1]*A[1][i1][i2]*A[1][i2][i2]*A[3][i1][i1]*A[0][i1][i2];
			s += -44 * A[1][i1][i1]*A[2][i2][i2]*A[3][i1][i1]*A[0][i1][i2];
			s += -44 * A[0][i1][i2]*A[5][i1][i2]*A[1][i1][i2];
			s += -44 * A[4][i1][i2]*A[1][i1][i2]*A[1][i1][i2];
			s += -44 * A[1][i1][i2]*A[2][i1][i2]*A[3][i1][i2];
			s += -44 * A[2][i2][i2]*A[3][i2][i2]*A[1][i1][i2];
			s += -11 * A[3][i2][i2]*A[1][i1][i2]*A[2][i1][i1];
			s += -264 * A[3][i1][i2]*A[2][i1][i1]*A[1][i1][i2]*A[0][i1][i2];
			s += -132 * A[2][i1][i2]*A[2][i1][i2]*A[2][i1][i1]*A[0][i1][i2];
			s += -264 * A[1][i1][i1]*A[0][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[3][i1][i2];
			s += -264 * A[1][i1][i1]*A[0][i1][i2]*A[1][i1][i2]*A[2][i1][i2]*A[2][i1][i2];
			s += -88 * A[1][i1][i1]*A[1][i1][i2]*A[2][i2][i2]*A[0][i1][i2]*A[2][i1][i1];
			s += -132 * A[1][i1][i2]*A[1][i1][i2]*A[4][i1][i1]*A[0][i1][i2];
			s += -264 * A[3][i1][i1]*A[1][i1][i2]*A[0][i1][i2]*A[2][i1][i2];
			s += -88 * A[1][i1][i1]*A[2][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2];
			s += -44 * A[1][i1][i1]*A[0][i1][i2]*A[1][i1][i2]*A[2][i2][i2]*A[2][i2][i2];
			s += -22 * A[2][i2][i2]*A[2][i1][i1]*A[2][i1][i1]*A[0][i1][i2];
			s += -264 * A[1][i1][i2]*A[1][i1][i2]*A[2][i1][i1]*A[0][i1][i2]*A[2][i1][i2];
			s += -88 * A[3][i1][i1]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[0][i1][i2];
			s += -22 * A[2][i1][i1]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2];
			s += 11 * A[1][i1][i1]*A[5][i1][i2]*A[1][i2][i2]*A[0][i1][i2];
			s += 11 * A[6][i2][i2]*A[1][i1][i2];
			s += 11 * A[4][i1][i2]*A[1][i1][i2]*A[1][i2][i2]*A[1][i1][i1];
			s += 11 * A[1][i1][i1]*A[2][i1][i2]*A[3][i1][i2]*A[1][i2][i2];
			s += 33 * A[6][i1][i2]*A[1][i1][i2]*A[0][i1][i2];
			s += 33 * A[0][i1][i2]*A[2][i1][i2]*A[5][i1][i2];
			s += 33 * A[3][i1][i2]*A[0][i1][i2]*A[4][i1][i2];
			s += 22 * A[1][i1][i1]*A[0][i1][i2]*A[2][i2][i2]*A[4][i1][i2];
			s += 22 * A[1][i1][i1]*A[0][i1][i2]*A[3][i2][i2]*A[3][i1][i2];
			s += 22 * A[1][i1][i1]*A[0][i1][i2]*A[4][i2][i2]*A[2][i1][i2];
			s += 22 * A[5][i2][i2]*A[1][i1][i2]*A[1][i1][i1]*A[0][i1][i2];
			s += 22 * A[1][i1][i1]*A[3][i1][i2]*A[2][i2][i2]*A[1][i1][i2];
			s += 22 * A[1][i1][i1]*A[3][i2][i2]*A[2][i1][i2]*A[1][i1][i2];
			s += 11 * A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i1]*A[4][i2][i2];
			s += 11 * A[2][i1][i2]*A[2][i1][i2]*A[1][i1][i1]*A[2][i2][i2];
			s += 11 * A[5][i2][i2]*A[2][i1][i1]*A[0][i1][i2];
			s += 11 * A[4][i2][i2]*A[3][i1][i1]*A[0][i1][i2];
			s += 33 * A[0][i1][i2]*A[5][i1][i2]*A[1][i1][i2]*A[1][i1][i2];
			s += 66 * A[1][i1][i2]*A[0][i1][i2]*A[2][i1][i2]*A[4][i1][i2];
			s += 33 * A[3][i1][i2]*A[3][i1][i2]*A[1][i1][i2]*A[0][i1][i2];
			s += 11 * A[2][i1][i1]*A[0][i1][i2]*A[3][i1][i2]*A[2][i2][i2];
			s += 22 * A[2][i1][i1]*A[0][i1][i2]*A[3][i2][i2]*A[2][i1][i2];
			s += 22 * A[2][i1][i1]*A[0][i1][i2]*A[4][i2][i2]*A[1][i1][i2];
			s += 11 * A[2][i1][i1]*A[1][i1][i2]*A[2][i1][i2]*A[2][i2][i2];
			s += 11 * A[2][i1][i1]*A[3][i2][i2]*A[1][i1][i2]*A[1][i1][i2];
			s += 33 * A[2][i1][i2]*A[2][i1][i2]*A[3][i1][i2]*A[0][i1][i2];
			s += 11 * A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[4][i1][i2];
			s += 33 * A[3][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[2][i1][i2];
			s += 11 * A[3][i1][i1]*A[3][i2][i2]*A[1][i1][i2]*A[0][i1][i2];
			s += 11 * A[1][i1][i2]*A[2][i1][i2]*A[2][i1][i2]*A[2][i1][i2];
		}
		s += 38016 * A[2][i1][i1];
		s += -58960 * A[1][i1][i1]*A[2][i1][i1];
		s += 20614 * A[2][i1][i1]*A[1][i1][i1]*A[1][i1][i1];
		s += 1496 * A[4][i1][i1];
		s += 5060 * A[2][i1][i1]*A[2][i1][i1];
		s += -3762 * A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i1]*A[2][i1][i1];
		s += -2541 * A[1][i1][i1]*A[4][i1][i1];
		s += -5324 * A[2][i1][i1]*A[3][i1][i1];
		s += -792 * A[1][i1][i1]*A[2][i1][i1]*A[2][i1][i1];
		s += 264 * A[2][i1][i1]*A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i1];
		s += 660 * A[1][i1][i1]*A[1][i1][i1]*A[4][i1][i1];
		s += 110 * A[6][i1][i1];
		s += 1914 * A[1][i1][i1]*A[3][i1][i1]*A[2][i1][i1];
		s += 88 * A[2][i1][i1]*A[4][i1][i1];
		s += 418 * A[2][i1][i1]*A[2][i1][i1]*A[2][i1][i1];
		s += -66 * A[4][i1][i1]*A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i1];
		s += -165 * A[1][i1][i1]*A[6][i1][i1];
		s += -198 * A[2][i1][i1]*A[1][i1][i1]*A[1][i1][i1]*A[3][i1][i1];
		s += -231 * A[2][i1][i1]*A[5][i1][i1];
		s += -231 * A[4][i1][i1]*A[3][i1][i1];
		s += -66 * A[1][i1][i1]*A[2][i1][i1]*A[2][i1][i1]*A[2][i1][i1];
		s += 22 * A[6][i1][i1]*A[1][i1][i1]*A[1][i1][i1];
		s += 11 * A[8][i1][i1];
		s += 44 * A[5][i1][i1]*A[2][i1][i1]*A[1][i1][i1];
		s += 44 * A[4][i1][i1]*A[3][i1][i1]*A[1][i1][i1];
		s += 22 * A[4][i1][i1]*A[2][i1][i1]*A[2][i1][i1];
		s += 22 * A[2][i1][i1]*A[3][i1][i1]*A[3][i1][i1];
		s += -11 * A[1][i1][i1]*A[8][i1][i1];
		s += -11 * A[2][i1][i1]*A[7][i1][i1];
		s += -11 * A[3][i1][i1]*A[6][i1][i1];
		s += -11 * A[4][i1][i1]*A[5][i1][i1];
		s += A[10][i1][i1];
	} 
	return s /= 22;
}
