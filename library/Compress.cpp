#include <bits/stdc++.h>
using namespace std;

#define MAP 100010
map<int,int> zip;
int unzip[MAP];

int compress(vector<int> &x) {
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(),x.end()),x.end());
    for(int i = 0; i < x.size(); i++){
        zip[x[i]] = i;
        unzip[i] = x[i];
    }
    return x.size();
}

int main(void)
{
    vector<int> ary = {1000, 300, 100, 300, 500};
    compress(ary); // aryの重複成分を副作用で削除するので注意！！
    for(auto x : ary) cout << x << " "; cout << endl;
    for(auto x : ary) cout << zip[x] << " "; cout << endl;

    return 0;
}
