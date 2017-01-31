#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define Min(x) *min_element(all(x))
#define Max(x) *max_element(all(x))
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { if (!v.empty()) { o << '['; copy(v.begin(), v.end(), ostream_iterator<T>(o, ", ")); o << "\b\b]"; } return o; }
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;
typedef pair<int, int> P;

static const double EPS = 1e-14;
static const long long INF = 1e18;
#define MAX_N 100005

int n;
string s;
map<string, int> m;

/*
void rec(int index, string prev) {
    if (index - 1 >= 5) {
        string s2 = s.substr(index-1, 2);
        if (prev != s2) {
            m[s2] = 1;
            rec(index-2, s2);
        }
    }
    if (index - 2 >= 5) {
        string s3 = s.substr(index-2, 3);
        if (prev != s3) {
            m[s3] = 1;
            rec(index-3, s3);
        }
    }
}
*/
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> s;
    n = s.length();
    /*
    rec(n-1, "");
    */
    int ini = 5;
    for (int i = ini; i < n-4; i++) {
        if (
                s[i+0] == s[i+1] && 
                s[i+1] == s[i+2] && 
                s[i+2] == s[i+3] && 
                s[i+3] == s[i+4]
                )
            ini = i;
    }
    
    for (int i = ini; i < n-1; i++) {
        if (i != n - 3) 
            m[s.substr(i, 2)] = 1;
        if (i != n - 4) 
            m[s.substr(i, 3)] = 1;
    }
    cout << m.size() << endl;
    for (auto x : m) {
        cout << x.first << endl;
    }

    return 0;
}
