#include <bits/stdc++.h>
using namespace std;

static const double EPS = 1e-14;
static const long long INF = 1e18;

#define rep(i,n) for(int i = 0; i < n; i++)
#define all(x) begin(x), end(x)
using ll = long long; using vll = vector<ll>; using vi = vector<int>;

int K, N;
vector<vi> orders;
vector<string> strs;

bool check(vi& lens) {
    vector<string> w(K, "");
    rep(i, strs.size()) {
        string str = strs[i];
        int h = 0;
        rep(j, orders[i].size()) {
            int order = orders[i][j]; // ごちゃごちゃしててつらい。こういう時は図示するのと、代入したほうがいい。
            if (h + lens[order] > str.length()) 
                return false;
            string w_tobe = str.substr(h, lens[order]);
            h += lens[order];
            if (w[order] == "") 
                w[order] = w_tobe;
            else 
                if (w[order] != w_tobe) 
                    return false;
        }
        if (h != str.length())  // 忘れてた
            return false;
    }

    rep(i, K) cout << w[i] << endl;
    return true;
}

int main(void) {
    cin >> K >> N;
    rep(i, N) {
        int n; cin >> n;
        vi order;
        for (; n > 0; n /= 10) 
            order.push_back(n%10-1);
        std::reverse(all(order)); // reverseを上のfor文の中に入れてた
        orders.push_back(order);

        string str; cin >> str;
        strs.push_back(str);
    }

    stack<vi> s;
    s.push(vi()); // 初期値忘れた
    while (!s.empty()) {
        vi lens = s.top(); s.pop();
        if (lens.size() == K) {
            if (check(lens))
                return 0;
        } else {
            for (int i : {1, 2, 3}) {
                vi lens_added = lens; 
                lens_added.push_back(i);
                s.push(lens_added);
            }
        }
    }

    return 0;
}
