#include <bits/stdc++.h>
using namespace std;
int main(void)
{

    double l,x,y,s,d;
    cin >> l >> x >> y >> s >> d ;

    if (s < d){
        if ((d-s)<l/2)
            cout << (d-s)/(x+y) <<endl;
        else {
            if (y > x) 
                cout << min ((d-s)/(x+y) ,(s+l-d)/(-x+y)) <<endl;
            else
                cout << (d-s)/(x+y) <<endl;
        }
    }

    else {
        if ((s-d)<l/2) {
            if (y > x) 
                cout << min ((l-s+d)/(x+y) ,(s-d)/(-x+y)) <<endl;
            else
                cout << (l-s+d)/(x+y) <<endl;
        }
        else 
            cout << (d+l-s)/(x+y) <<endl;
    }

    return 0;
}
