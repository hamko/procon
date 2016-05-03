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

class UnionFind {
public:
    vector<int> data;
    UnionFind(int size) : data(size, -1) { }
    // x, yをマージ
    bool unionSet(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    // x, yが同じ集合なら1
    bool findSet(int x, int y) {
        return root(x) == root(y);
    }
    // xの根を探す。同じ集合なら同じ根が帰る
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    // xが含まれる集合の大きさを返す
    int size(int x) {
        return -data[root(x)];
    }
    // 分離されている集合の数を返す
    int setNum(void) {
        map<int, int> c;
        rep(i, data.size()) {
            c[root(i)]++;
        }
        return c.size();
    }
};

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;

    string s, t; cin >> s >> t;
    map<char, int> c;
    map<int, char> cinv;
    int counter = 0;
    int numcounter = 0;
    rep(i, n) {
        if (c.count(s[i]))
            continue;
        c[s[i]] = counter;
        cinv[counter] = s[i];
        counter++;
        if ('0' <= s[i] && s[i] <= '9') 
            numcounter++;
    }
    rep(i, n) {
        if (c.count(t[i]))
            continue;
        c[t[i]] = counter;
        cinv[counter] = t[i];
        counter++;
        if ('0' <= t[i] && t[i] <= '9') 
            numcounter++;
    }

    UnionFind u(counter);
    rep(i, n) {
        u.unionSet(c[s[i]], c[t[i]]);
    }

    int nine_num = 0;
    int faf;
    if (!('0' <= s[0] && s[0] <= '9')) {
        faf = 1; 
        rep(j, 10) { 
            if (!c.count('0'+j))
                continue;
            if (u.findSet(c[s[0]], c['0'+j])) { 
                faf = 0; 
                break; 
            }
        }
        if (faf) nine_num++;
    }
    if (!('0' <= t[0] && t[0] <= '9')) {
        faf = 1; 
        rep(j, 10) { 
            if (!c.count('0'+j))
                continue;
            if (u.findSet(c[t[0]], c['0'+j])) { 
                faf = 0; 
                break; 
            }
        }
        if (faf) nine_num++;
    }

    if (nine_num == 2 && u.findSet(s[0], t[0])) {
        nine_num--;
    }

    // 数字が入っていない集合を全列挙し、先頭文字が入ってれば9, 入ってなければ10をかける。
    ll ret = 1;
    for (int i = 0; i < u.setNum() - numcounter; i++) {
        if (nine_num) 
            ret *= 9, nine_num--;
        else
            ret *= 10;
    }
    cout << ret << endl;

    return 0;
}
