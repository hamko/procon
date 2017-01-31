#include<stdio.h>
#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>

using namespace std;

int main(void) {
    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
        int n;
        cin >> n;
        vector<int> w(n);
        for(int j=0;j<n;j++) cin >> w[j];
        sort(w.begin(),w.end(),greater<int>());
        int pos=0; int count = 0; int ans = 0;
        while(count < n){
            count += (50+w[pos]-1)/w[pos];
            if(count <= n){
                pos++;
                ans++;
            }
        }

        cout << "Case #" << i+1 << ": ";
        cout << ans << endl;
    }
    return 0;
}
