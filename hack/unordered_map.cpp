#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i,n) for(int i = 0; i < n; i++)

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n = 46794; // 1e9max
//    ll n = 100000; 

    unordered_map<ll, ll> a;
//    a.reserve(n);

#if 0
    int j = 1;
    ll pbcount = a.bucket_count();
    rep(i, n) {
        ll bcount = a.bucket_count();
        if (bcount != pbcount) { pbcount = bcount; j = 1; /*cout << i << " " << bcount << endl;*/}
        ll hack_index = bcount*j;
        a[hack_index] = 1; // SUPER SLOW
//        a[rand()%100] = 1; // this is fast
        cout << i << " " << hack_index << endl;
        j++;
    }

    cout << "end" << endl;

#else
    rep(i, n) {
        ll hack_index = 0;
        if (a.bucket_count() < 30000) {
            hack_index = i;
        } else {
            hack_index = a.bucket_count() * max(0, min(i, 20000));
        }
        a[hack_index] = 1;
        cout << i << " " << a.bucket_count() << " " <<  hack_index << endl;
    }
#endif

    return 0;
}


