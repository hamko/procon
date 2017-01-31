#include<iostream>
#include<math.h>
#include<cstring>
#define EPS 1e-7
using namespace std;

int getDistance(int x, int y){
    return (x-50)*(x-50)+(y-50)*(y-50);
}

double getTheta(int x, int y){
    if (x >= 50) {
        return atan2((double)(x-50), (double)(y-50));
    }else{
        return atan2((double)(50-x), (double)(50-y))+M_PI;
    }
}

double getP(int p){
    return M_PI*(double)p*2.0/100.0;
}

string solve(int p, int x, int y){
    int d = getDistance(x, y);
    if (d > 2500) {
        return "white";
    }
    double theta = getTheta(x, y);
    double progress = getP(p);
    //cout << theta << "    " << progress << endl;
    if (fabs(theta-progress) <= EPS || theta < progress) {
        return "black";
    }else{
        return "white";
    }
}


int main(){
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int p, x, y;
        cin >> p >> x >> y;
        cout << "Case #" << t+1 << ": " << solve(p, x, y) << endl;
    }
    return 0;
}
