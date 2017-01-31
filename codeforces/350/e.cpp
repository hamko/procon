#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { if (!v.empty()) { o << '['; copy(v.begin(), v.end(), ostream_iterator<T>(o, ", ")); o << "\b\b]"; } return o; }
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;
typedef pair<ll, ll> P;

static const double EPS = 1e-14;
static const long long INF = 1e18;
#define MAX_N 100005


map<ll, ll> di;
map<ll, ll> di_inv;

class node {
public:
    node* p = NULL;
    map<ll, node*, greater<ll>> c; // l -> children
    ll l = 0, r = 0;
    node* find(ll index) {
        if (index == l || index == (r-1)) 
            return this;
        return (c.lower_bound(index))->second;
    }
    void erase(ll index) {
        auto it = c.lower_bound(index);
        if (index == it->second->l || index == it->second->r-1 ) {
            c.erase(it->first);
            delete it->second;
            return;
        }
        it->second->erase(index);
    }
    void print(void) {
        if (p)
            cout << "(";
        map<ll, node*, greater<ll>>::reverse_iterator rit = c.rbegin();   // 逆イテレータ
        while( rit != c.rend() ) { // 先頭まで
            rit->second->print();
            rit++;
        }
        if (p)
            cout << ")";
    }

    node(){}
};

ll n, k, p;
string s;
string command;
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> n >> k >> p; p--;
    cin >> s;
    cin >> command;

    node* root = new node(); root->p = NULL;

    node* tmpnode = root;
    rep(i, s.length()) {
        if (s[i] == '(') {
            node* nextnode = new node();
            nextnode->p = tmpnode;
            nextnode->l = i;
            tmpnode->c[i] = nextnode;
            tmpnode = nextnode;
        } else {
            tmpnode->r = i + 1;
            tmpnode = tmpnode->p;
        }
    }


    rep(i, n-1) {
        di[i] = i+1;
        di_inv[n-i-1] = n-i-2;
    }

    rep(i, k) {
        char ch = command[i];
        if (ch == 'R') {
            p = di[p];
        } else if (ch == 'L') {
            p = di_inv[p];
        } else {
            // 対応ノードを探し出し、
            node* tmp = root->find(p);
            // indexを覚えて
            int tmpp = tmp->r;
            // ダンシングインデックスも変えて
            di[tmp->l-1] = tmp->r;
            di_inv[tmp->r] = tmp->l-1;
            // ノード削除
            root->erase(p);
            // index更新
            p = tmpp;
        }
    }

    root->print(); cout << endl;
    return 0;
}
