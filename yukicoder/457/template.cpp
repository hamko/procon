#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define repi(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
using ll = long long; 

int main(void) {
    string s; cin >> s; 
    ll n = s.length();
    assert(n >= 1); assert(n <= 10000);
    rep(i, n) assert(s[i] == '(' || s[i] == '*' || s[i] == '^' || s[i] == ')');

    auto f = [&](string target) {
        ll ret = 0;
        rep(i, n) if (s[i] == '(') {
            ll state = 0;
            repi(j, i+1, n) {
                if (state < target.size() && target[state] == s[j]) 
                    state++;
                if (state == target.size() && s[j] == ')') 
                    ret++;
            }
        }
        return ret;
    };
    cout << f("^^*") << " " << f("*^^") << endl;

    return 0;
}
