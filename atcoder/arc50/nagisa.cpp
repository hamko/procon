#include <bits/stdc++.h>
using namespace std;
long long R, B, x, y;

int main(){
    cin >> R >> B >> x >> y;
    long long hi = min(R,B)+1;
    long long lo = 0;

    while(hi-lo>1){
        long long mi = (hi+lo)/2;
        (R-mi)/(x-1)+(B-mi)/(y-1)>=mi?lo=mi:hi=mi;
    }
    cout << lo << endl;
    return 0;
}
