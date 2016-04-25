#include <iostream>
#include <map>
#include <vector>
#define ll long long
using namespace std;

long long compress(vector<ll>& ary)
{
    map<ll, int> m;
    for(ll x : ary) m[x] = 0;
    int order = 0; 
    for(auto &x : m) x.second = order++;
    for(auto &x : ary) x = m[x];
    return m.size();
}

// Uを座標圧縮 {(100, P(11, 10)), (200, P(10, 38)), (50, P(2, 20) }など
template<class T, class U>
long long compress(vector<pair<U, T>>& ary)
{
    map<U, ll> m;
    for(auto x : ary) m[x.first] = 0;
    ll order = 0;
    for(auto &x : m) x.second = order++;
    for(auto &x : ary) x.first = m[x.first];
    return m.size();
}


int main(void)
{
    vector<ll> ary = {1000, 200, 100, 300, 500};
    compress(ary);
    for(auto x : ary) cout << x << endl;

    return 0;
}
