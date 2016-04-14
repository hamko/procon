#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define all(x) begin(x), end(x)

typedef long long ll;
typedef pair<ll, ll> LP; // int, intでオーバーフロー

int main() {
    std::vector<int> v = {3, 1, 4, 6, 5};
    auto comp = greater<int>();

    /**********************************************/
    // 以下sortの向きが正しいケース
    /**********************************************/
    // 3以上の最小の数字
    sort(all(v)); // 1, 3, 4, 5, 6
    cout << *(lower_bound(all(v), 3)) << endl;
    if (lower_bound(all(v), 7) == v.end()) 
        cout << "Nothing" << endl;

    // 3より大きい最小の数字
    sort(all(v)); // 1, 3, 4, 5, 6
    cout << *(upper_bound(all(v), 3)) << endl;
    if (lower_bound(all(v), 7) == v.end()) 
        cout << "Nothing" << endl;

    // 3以下の最大の数字
    sort(all(v), comp); // 6, 5, 4, 3, 1
    cout << *(lower_bound(all(v), 3, comp)) << endl;
    if (lower_bound(all(v), 0, comp) == v.end()) 
        cout << "Nothing" << endl;

    // 3より小さい最大の数字
    sort(all(v), comp); // 6, 5, 4, 3, 1
    cout << *(upper_bound(all(v), 3, comp)) << endl;
    if (lower_bound(all(v), 0, comp) == v.end()) 
        cout << "Nothing" << endl;

    /**********************************************/
    // 以下sortの向きが逆なのに無理やりやるケース
    /**********************************************/
    // 3以下の最大の数字
    sort(all(v)); // 1, 3, 4, 5, 6
    cout << *(upper_bound(all(v), 3) - 1) << endl;
    if (lower_bound(all(v), 0) - 1 == v.begin() - 1) 
        cout << "Nothing" << endl;

    // 3より小さい最大の数字
    sort(all(v)); // 1, 3, 4, 5, 6
    cout << *(lower_bound(all(v), 3) - 1) << endl;
    if (lower_bound(all(v), 0) - 1 == v.begin() - 1) 
        cout << "Nothing" << endl;

    // 3以上の最大の数字
    sort(all(v), comp); // 6, 5, 4, 3, 1
    cout << *(lower_bound(all(v), 3, comp) - 1) << endl;
    if (lower_bound(all(v), 7, comp) - 1 == v.begin() - 1) 
        cout << "Nothing" << endl;

    // 3より大きい最大の数字
    sort(all(v), comp); // 6, 5, 4, 3, 1
    cout << *(upper_bound(all(v), 3, comp) - 1) << endl;
    if (lower_bound(all(v), 7, comp) - 1 == v.begin() - 1) 
        cout << "Nothing" << endl;


    return 0;
}
