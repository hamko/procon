#include <bits/stdc++.h>
using namespace std;

static const double EPS = 1e-5;
#define EQ(a,b) (abs((a)-(b))<EPS)

#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define all(x) begin(x), end(x)
#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<string> vs;

int main(void) {
    string s;
    int a, b, c, d;
    cin >> s >> a >> b >> c >> d;
    int l = s.length();
    string r;
    rep(i, l) {
        if (i == a || i == b || i == c || i == d)  
            r += "\"";
        r += s[i];
    }
    if (a == l || b == l || c == l || d == l) {
            r += "\"";
    }
    cout << r << endl;
    return 0;
}
