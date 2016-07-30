/***************************************************************

  ****          ****
  **   *********  **   I N T   1 2 8
  **  **     **   **   `````````````
  **        **    **   128 bit integer without assembler
  **       **     **   ( rather slow )
  **   ********   **
  **     **       **
  **    **        **
  **   **     **  **
  **  *********   **
  ****          ****

  [FILE]    Int128.h
  [AUTHOR]  Artem M. Karavaev
  [E-MAIL]  karavaev@flowproblem.ru
  [CREATED] 26.09.2009
  [VERSION] 1.00 from 26.09.2009

  [HISTORY]
  ==== v1.00 == 26.09.2009 ====
  Created by author.
  
***************************************************************/

#ifndef ZEAL_INT128
#define ZEAL_INT128

#include <stdio.h>

typedef long long int64;
typedef unsigned long long int64u;
#define ONE64U ( ( int64u ) ( 1 ) )

namespace Zeal {

	class Int128 {
		
		public:
			
			Int128 ( ) : h ( 0 ), l ( 0 ) { }
			Int128 ( int x ) : h ( 0 ), l ( ( int64u ) x ) { 
				if ( l & ( ONE64U << 63 ) )
					h --;
			}
			Int128 ( int64u x ) : h ( 0 ), l ( x ) { }
			~ Int128 ( ) { }

			const Int128 & operator = ( const Int128 & x ) {
				if ( this == & x )
					return * this;
				h = x . h;
				l = x . l;
				return * this;
			}
      
			const int operator == ( const Int128 & x ) {
				return int ( h == x . h && l == x . l );
			}

			const int operator != ( const Int128 & x ) {
				return int ( h != x . h || l != x . l );
			}
      
			const Int128 & operator += ( const Int128 & x ) {				
				int64u z = l + x . l;
        h += x . h + ( int64 ) ( ( ( l & x . l ) | ( ( l | x . l ) & ( ~ z )  ) ) >> 63 );
        l = z;
				return * this;
			}			
            
			const Int128 & operator /= ( int x ) {				
				int a3;
				unsigned int a0, a1, a2;
				int64 w;				
				a0 = ( unsigned int ) ( l & 0xFFFFFFFF );
				a1 = ( unsigned int ) ( l >> 32 );
				a2 = ( unsigned int ) ( h & 0xFFFFFFFF );
				a3 = ( int ) ( h >> 32 );
				
				w = a3;
				a3 = ( int ) ( w / x );
				w = ( ( w % x ) << 32 ) + a2;          
				a2 = ( unsigned int ) ( w / x );
				w = ( ( w % x ) << 32 ) + a1;
				a1 = ( unsigned int ) ( w / x );
				w = ( ( w % x ) << 32 ) + a0;
				a0 = ( unsigned int ) ( w / x );
				// reminder w %= 10;
				l = ( ( ( ( ( int64u ) ( a1 ) ) ) << 32 ) | a0 );
        h = ( int64 ) ( ( ( ( ( int64u ) ( a3 ) ) ) << 32 ) | a2 );
				return * this;
			}
      

			void print ( FILE * out = stdout ) const {
				Int128 x = * this;
				char str [ 64 ];
				int a3, p = 0;
				unsigned int a0, a1, a2;
				int64 w;
				if ( x . h == 0 && x . l == 0 ) {
					fputc ( '0', out );
					return;
				}
				if ( x . h < 0 ) {
					fputc ( '-', out );
					x = - x;
				}
				a0 = ( unsigned int ) ( x . l & 0xFFFFFFFF );
				a1 = ( unsigned int ) ( x . l >> 32 );
				a2 = ( unsigned int ) ( x . h & 0xFFFFFFFF );
				a3 = ( int ) ( x . h >> 32 );
				
				while ( ! ( a0 == 0 && a1 == 0 && a2 == 0 && a3 == 0 ) ) {
					w = a3;
					a3 = ( int ) ( w / 10 );
					w = ( ( w % 10 ) << 32 ) + a2;          
          a2 = ( unsigned int ) ( w / 10 );
          w = ( ( w % 10 ) << 32 ) + a1;
          a1 = ( unsigned int ) ( w / 10 );
          w = ( ( w % 10 ) << 32 ) + a0;
          a0 = ( unsigned int ) ( w / 10 );
          w %= 10;
          str [ p ++ ] = ( char ) ( w ) + '0';
				}
				while ( -- p >= 0 )
					fputc ( str [ p ], out );
			}

		//private:
		int64  h;
		int64u l;

		friend const Int128 operator - ( const Int128 & );
		
	};

	const Int128 operator - ( const Int128 & a ) {  	
  	Int128 res;
  	res . l = ( ~ a . l );
  	res . h = ( ~ a . h );
  	if ( ++ res . l == 0 )
  		res . h ++;
		return res;
	}
  
	const Int128 operator + ( const Int128 & a, const Int128 & b ) {				
		Int128 res;
  	res . l = a . l + b . l;
		res . h = a . h + b . h + ( int64 ) ( ( ( a . l & b . l ) | ( ( a . l | b . l ) & ( ~ res . l )  ) ) >> 63 );		
		return res;
	}
  
	const Int128 operator * ( const Int128 & a, const Int128 & b ) {				
  	Int128 res;
  	int64u u0, v0, w0;
  	int64 u1, v1, w1, w2, t;
  	if ( a . h < 0 )
  		return - ( ( - a ) * b );
		if ( b . h < 0 )
    	return - ( a * ( - b ) );
		res . l = a . l * b . l;
		u0 = ( a . l & 0xFFFFFFFF );
		u1 = ( a . l >> 32 );
		v0 = ( b . l & 0xFFFFFFFF );
		v1 = ( b . l >> 32 );
		w0 = u0 * v0;
		t = u1 * v0 + ( w0 >> 32 );
		w1 = ( t & 0xFFFFFFFF );
		w2 = ( t >> 32 );
		w1 = u0 * v1 + w1;        
    res . h = u1 * v1 + w2 + ( w1 >> 32 ) + a . l * b . h + a . h * b . l;
		return res;
	}			
  
}

#endif

/* ==== END of Int128.h ==== */
