#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { if (!v.empty()) { o << '['; copy(v.begin(), v.end(), ostream_iterator<T>(o, ", ")); o << "\b\b]"; } return o; }
using ll = long long; using ld = long double; using vll = vector<ll>; using vld = vector<ld>;
typedef pair<ll, ll> P;

static const double EPS = 1e-14;
static const long long INF = 1e18;
#define MAX_N 100005

// 正しい括弧列について、開き括弧に対応する閉じ括弧の位置を出力する。
// O(n)
vector<ll> correspondingParentheses(string& s) {
    ll n = s.length();
    ll h = 0;
    unordered_map<ll, ll> m;
    vll ret(n, -1);
    rep(i, n) {
        if (s[i] == '(') {
            m[h] = i;
            h++;
        } else {
            h--;
            if (m.count(h)) {
                ret[m[h]] = i;
                m.erase(h);
            }
        }
    }
    rep(i, n) if (ret[i] != -1) {
        ret[ret[i]] = i;
    }
    return ret;
}

// sが正しい括弧列かを判別する
// O(n)
bool isValidParentheses(string& s) {
    ll counter = 0; 
    rep(i, s.length()) 
        if ((counter += (s[i] == '(' ? 1 : -1)) < 0)
            return false;
    return counter == 0;
}
// sの括弧数を求める
// O(n)
ll countOpenParentheses(string& s) { ll sum = 0; rep(i, s.length()) sum += s[i] == ')'; return sum; }
ll countClosingParentheses(string& s) { ll sum = 0; rep(i, s.length()) sum += s[i] == '('; return sum; }

// sの括弧列の全列挙
// O(2^n), n = 32までは現実的な時間で終わる
// 0 1 // 2 1 // 4 2 // 6 5 // 8 14 // 10 42 // 12 132 // 14 429 // 16 1430 // 18 4862 // 20 16796
// 22 58786 // 24 208012 // 26 742900 // 28 2674440 // 30 9694845 // 32 35357670 // 34 129644790
void numerateParentheses(int n, vector<ll>& q_next) {
    q_next.clear();
    if (n < 0 || n % 2) return;
    vector<ll> q;
    q_next.pb(0);
    ll t = 0;
    while (t < n && !q_next.empty()) {
        q.swap(q_next);
        while (!q.empty()) {
            ll tmp = q.back(); q.pop_back();
            if (__builtin_popcount(tmp) > t / 2) // if 011->2,3/2=1 ->OK, 0011->2, 4/2=2->NG
                q_next.pb(tmp); // Down
            if (__builtin_popcount(tmp) < n / 2)
                q_next.pb(tmp | (1ll << t)); // Up
        }
        t++;
    }
}

P getNeededParentheseNum(string& t) {
    ll balance = 0;
    ll open = 0, close = 0;
    rep(i, t.size()) {
        if (t[i] == '(') {
            if (balance + i >= t.size() - 1)  // (では降りきれない
                close++, balance--;
            else 
                balance++;
        } else {
            if (balance <= 0)  // )ではもう降りれない
                open++, balance++;
            else 
                balance--;
        }
    }
    return P(open, close);
}

int main(void) {
    string s = "))()())(()";
    cout << s << endl;
    cout << countOpenParentheses(s) << endl;
    cout << countClosingParentheses(s) << endl;
    cout << isValidParentheses(s) << endl;

    s = "((())()())";
    cout << s << endl;
    cout << isValidParentheses(s) << endl;
    cout << correspondingParentheses(s) << endl;

    rep(i, 20) {
        vector<ll> p;
        numerateParentheses(i * 2, p);
        cout << i * 2 << " " << p.size() << endl;
    }

    return 0;
}
