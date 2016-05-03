#include <iostream>
#include <algorithm>
using namespace std;
int D[51][51];
int S[51][51];
int main( void )
{
    ios::sync_with_stdio(false);
    int N, Q, P;
    cin >> N;
    for( int i=1; i<=N; i++ ){
        for( int j=1; j<=N; j++ ){
            cin >> D[i][j];
        }
    }
    for( int i=1; i<=N; i++ ){
        for( int j=1; j<=N; j++ ){
            S[i][j] = S[i][j-1] + D[i][j];
        }
    }
    for( int j=1; j<=N; j++ ){
        for( int i=1; i<=N; i++ ){
            S[i][j] += S[i-1][j];
        }
    }
    cin >> Q;
    for( int i=0; i<Q; i++ ){
        cin >> P;
        int ret = 0;
        for( int j=1; j<=P; j++ ){
            int H = min( j, N );
            int W = min( P/j, N );
            for( int y=0; y<=N-H; y++ ){
                for( int x=0; x<=N-W; x++ ){
                    ret = max( ret, S[y+H][x+W]-S[y][x+W]-S[y+H][x]+S[y][x] );
                }
            }
        }
        cout << ret << endl;
    }
}

