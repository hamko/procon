#include <bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<long long, long long> s;
    // super slow over 60000
    for(int i = 0; i < 100000; ++i){
        s[i*126271LL] = i;
        cout << i << endl;
    }
    for(int i = 0; i < 100000; ++i){
        cout << s[i] << endl;
    }
}
