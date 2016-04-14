#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll;

#define MAX_N 2005
static const double EPS = 1e-14; 

int main(int argc, char * argv[])
{
    int n; cin >> n;
    int x[MAX_N], y[MAX_N];
    rep(i, n) scanf("%d %d", x+i, y+i);

    ll acute = 0, right = 0;
    rep(i, n) {
        vector<double> angle;
        rep(j, n) 
            if (i != j) 
                angle.push_back(atan2(x[i] - x[j], y[i] - y[j]));
        sort(begin(angle), end(angle));
        rep(j, n-1) 
            angle.push_back(angle[j]+2*M_PI); 

        rep(j, n-1) {
            int acute_max_index = j;
            while (angle[acute_max_index+1] - angle[j] < M_PI / 2 - EPS) 
                acute_max_index++;
            acute += (acute_max_index - j);
            if (angle[acute_max_index+1] - angle[j] < M_PI / 2 + EPS) 
                right++;
        }
    }

    ll all_triangle_num = (ll)n * (n-1) * (n-2) / 6; 
    cout << (ll)acute - 2 * all_triangle_num << " " 
        << (ll)right << " "
        << (ll)3 * all_triangle_num - right - acute << endl;

    return 0;
}
