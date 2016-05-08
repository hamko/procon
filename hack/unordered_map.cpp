#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i,n) for(int i = 0; i < n; i++)

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    
//    ll n = 30000; // 1e9max
    ll n = 100000; 

    unordered_map<ll, ll> a;
//    a.reserve(n);

    rep(i, n) {
        ll bcount = a.bucket_count();
        ll hack_index = bcount*i;
        a[hack_index] = 1; // SUPER SLOW
//        a[rand()%100] = 1; // this is fast
        cout << hack_index << endl;
    }

    cout << "end" << endl;

    return 0;
}


