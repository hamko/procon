#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define print(v) for(auto x:(v)){cout<<x<<" ";}cout<<endl;
#define printi(b,e) for(auto x=(b); x!=(e); x++)cout<<*x<<" ";cout<<endl;
#define printa(a,n) rep(i,n)cout<<a[i]<<" ";cout<<endl;
#define all(x) x.begin(), x.end()
#define Min(x) *min_element(all(x))
#define Max(x) *max_element(all(x))
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;
typedef pair<int, int> P;

static const double EPS = 1e-14;
static const long long INF = 1e18;
#define MAX_N 100005

int main(void) {
    int n; cin >> n;
    int arr[1000] = {};
    rep(i, n) {
        int a, b;
        scanf("%d-%d", &a, &b);
//        cout << a << " " << b << endl;
        int h, m;
        h = a / 100; m = a % 100;
        int x = h * 12 + m / 5;
        h = b / 100; m = b % 100;
        int y = h * 12 + (m + 4) / 5;
        arr[x]++, arr[y]--;
    }
    rep(i, 300) {
//        cout << arr[i] << " ";
    }
//    cout << endl;
    rep(i, 300) {
        arr[i+1] += arr[i];
//        cout << arr[i+1] << " ";
    }
//    cout << endl;
    rep(i, 300) {
        if (i == 0) {
            if (arr[0])
                cout << "0000-";
            continue;
        }
        if (!arr[i-1] && arr[i]) {
            int t = i * 5; int h = t / 60; int m = t % 60;
            cout << (h<10?"0":"") << h << (m<10?"0":"") << m << "-";
        }
        if (arr[i-1] && !arr[i]) {
            int t = i * 5; int h = t / 60; int m = t % 60;
            cout << (h<10?"0":"") << h << (m<10?"0":"") << m << endl;
        }
    }
    return 0;
}
