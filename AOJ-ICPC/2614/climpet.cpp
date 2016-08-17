#include <bits/stdc++.h>

using namespace std;

vector<int> calc_z(string s){
    int n = s.size();
    vector<int> z(n);
    z[0] = n;
    int i = 1, j = 0;
    while(i < n){
        while(i + j < n && s[j] == s[i + j]){ ++j; }
        z[i] = j;
        if(j == 0){
            ++i;
            continue;
        }
        int k = 1;
        while(i + k < n && k + z[k] < j){
            z[i + k] = z[k];
            ++k;
        }
        i += k;
        j -= k;
    }
    return z;
}

int main(){
    ios::sync_with_stdio(false);

    string s, t;
    getline(cin, s);
    getline(cin, t);

    string tmp = s + t;
    reverse(tmp.begin(), tmp.end());
    int ls = s.size(), lt = t.size();
    vector<int> z1 = calc_z(t + s);
    vector<int> z2 = calc_z(tmp);

    int ans = 0;
    for(int i = 0; i + lt <= ls; ++i){
        ans += z1[i + lt] + z2[ls - i] + 1 == lt;
    }
    cout << ans << '\n';
}
