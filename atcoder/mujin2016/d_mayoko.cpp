#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mt make_tuple
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }

using ll = long long; using ld = long double; using vll = vector<ll>; using vvll = vector<vll>; using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>;
using P = pair<ll, ll>;

// セグメント木(RMQ 対応)
// update: k 番目の値を a に変更
// query: [l, r) の区間の最大値を求める
template<typename T>
struct ST {
    vector<T> seg;
    int size;
    ST(int n) {
        size = 1;
        while (size < n) size *= 2;
        seg.resize(2*size-1, numeric_limits<T>::max());
    }
    inline T merge(T x, T y) {
        return min<T>(x, y);
    }
    void update(int k, T a) {
        k += size-1;
        seg[k] = a;
        while (k > 0) {
            k = (k-1)/2;
            seg[k] = merge(seg[k*2+1], seg[k*2+2]);
        }
    }
    T query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return numeric_limits<T>::max();
        if (a <= l && r <= b) return seg[k];
        T vl = query(a, b, k*2+1, l, (l+r)/2);
        T vr = query(a, b, k*2+2, (l+r)/2, r);
        return merge(vl, vr);
    }
    T query(int a, int b) {
        return query(a, b, 0, 0, size);
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    string s;
    cin >> s;
    // seg1: ? を ( に変える
    // seg2: ? を ) に変える
    ST<int> segl(N+2), segr(N+2);
    vector<int> lp(N+2), rp(N+2), qp(N+2);
    int lt = 0, rt = 0;
    segl.update(0, 0); segr.update(0, 0);
    for (int i = 0; i < N; i++) {
        lp[i+1] = lp[i], rp[i+1] = rp[i], qp[i+1] = qp[i];
        if (s[i] == '(') lp[i+1]++, lt++, rt++;
        if (s[i] == ')') rp[i+1]++, lt--, rt--;
        if (s[i] == '?') qp[i+1]++, lt++, rt--;
        segl.update(i+1, lt); segr.update(i+1, rt);
    }
    auto f = [&] (int l, int r) {
        int num = r-l;
        if (num%2) return false;
        int ln = num/2 - (lp[r]-lp[l]), rn = num/2 - (rp[r]-rp[l]); // 足りない(, )の数。
        if (ln < 0 || rn < 0) return false; // 余ってるのはむりぽ
        if (ln == 0) { // (はちょうど。?を全部)にして、どこかがマイナスにならなければOK
            if (segr.query(l, r+1) >= segr.query(r, r+1))  // 数が同じかつ最後が最小ならOK, 途中だとシフトしてる可能性があるので、0でなく最後
                return true;
            else 
                return false;
        }
        // l以上で、lnをまかなえる最小の?の位置を求める(rh)
        int lh = l, rh = N/*文字列長*/;
        while (rh-lh > 1) {
            const int med = (lh+rh)/2;
            if (qp[med] - qp[l] >= ln) 
                rh = med;
            else 
                lh = med;
        }
        // この時点で、((??とか(((?とか)))?とかは含まれていない！
        if (rh == N) { // ?だけではlnが賄えない=)の数がピッタリ？
            if (segl.query(l, r+1) >= segl.query(l, l+1)) return true;
            else return false;
        }
        if (segl.query(l, rh+1) >= segl.query(l, l+1) && segr.query(rh+1, r+1) >= segr.query(r, r+1)) return true;
        return false;
    };
    int Q;
    cin >> Q;
    while (Q--) {
        int l, r;
        cin >> l >> r;
        if (f(l-1, r)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
