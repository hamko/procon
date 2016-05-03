#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)

int main(void) {
    int n; cin >> n;
    vector<int> c; c.push_back(0);
    int m = -1; 
    rep(i, n) {
        int tmp; cin >> tmp;
        if (m < tmp) {
            c.push_back(tmp);
            m = tmp;
        }
    }

    int count = 0;
    rep(i, c.size()-1) 
        count += c[i+1] - c[i] - 1;
    cout << count << endl;

    return 0;
}
