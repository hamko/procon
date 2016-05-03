#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define Max(x) *max_element(all(x))
typedef pair<int, int> P;

static const double EPS = 1e-14;
static const long long INF = 1e18;
#define MAX_N 100005

int main(void) {
    int n; cin >> n;
    vector<int> x;
    rep (i, n) { 
        if (!i) { x.push_back(0); continue; }
        cout << "? 1 " << i+1 << endl; 
        int res; cin >> res; x.push_back(res); 
    }
    int index = max_element(all(x)) - x.begin();
    x.clear();
    rep (i, n) {
        if (i == index) { x.push_back(0); continue; } 
        cout << "? " << index+1 << " " << i+1 << endl; 
        int res; cin >> res; x.push_back(res); 
    }

    cout << "! " << Max(x) << endl;
    

    return 0;
}
