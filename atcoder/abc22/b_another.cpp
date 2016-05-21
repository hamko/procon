#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n; cin >> n;
    vector<int> a(n); 
    for (int i = 0; i < n; i++) 
        cin >> a[i];

    vector<int> memo(100001);
    int ret = 0;
    for (int i = 0; i < n; i++) 
        if (memo[a[i]] == 1)
            ret++;
        else 
            memo[a[i]] = 1;
    cout << ret << endl;
    
    return 0;
}
