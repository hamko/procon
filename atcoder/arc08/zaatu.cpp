#include <iostream>
#include <map>
#include <vector>
#define ll long long
using namespace std;
int main(void){
    ll N, order = 0; 
    cin >> N;
    vector<ll> ary(N);
    map<ll, ll> map;

    for(ll &i : ary) {
        cin >> i;
        map[i] = 0;
    }
    for(auto &x : map) x.second = order++;
    for(ll i : ary) cout << map[i] << endl;
}
