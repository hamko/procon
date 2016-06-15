// pekempeyさん、ありがとうございます
//
// このコードは
//     http://pekempey.hatenablog.com/entry/2016/06/14/102537
// にコメントを加えて、スコープを直したコードです
//
// ----------------
// 計算量
//      O(n sqrt(n))
//
// 方針
//      まず、クエリが少ない場合を考える。
//      クエリをj個まで処理し終えた時に、係数集合Sだったとする。
//
//      j+1個目のクエリで、クエリタイプ3が来たとする。
//      係数集合Sの中で、x*q+yが最大となるような(x, y)を探したい。
//      前処理なしで、愚直に計算するには、すべてのSの要素に対してx*q+yを計算するので、計算O(n)でクエリが処理できる。
//      
//
//      他のクエリタイプ3の処理方法はないだろうか？
//      ここで、事前にクエリをソートO(n log n) 凸包構築O(n) 最大値取得O(log n)で、x*q+yの最大値を計算することができる、Convex Hull Trickを紹介する。
//      （クエリ毎にこれを使うとすると、クエリタイプ1, 2のたびに構築しなおさなければならないので、計算量は変わらないものの間違いなく定数倍が重くなる）
//
//      図などあるので、こちらを参照するとわかりやすい。
//      http://pekempey.hatenablog.com/entry/2016/03/04/202648
//
//      Convex Hull Trick
//          3つの直線、
//              L0: x0 * q + y0
//              L1: x1 * q + y1
//              L2: x2 * q + y2
//              (a1 < a1 < a2)
//          を考える。すると、
//              左側では L0(q) >= L1(q) >= L2(q)
//              中央では L0(q) <= L1(q) >= L2(q)
//              右側では L0(q) <= L1(q) <= L2(q)
//          となるような3つの直線が存在する。
//
//          これはnつの直線になると、>=と<=が入れ替わる位置が、aiに対して単調となる。
//          従って、どの直線上で最大値を取るかは、二分探索可能である。
//          このような直線群を抽出できれば、計算O(log n)でx*q+yの最大値が求まる
//
//          例えばb1が-infとかだと、L1は最大値の候補になりえなさそうである。
//          どうやって、上記のような直線群を抽出すればいいのだろうか？
//
//          天下り的に、L1が最大値の候補とならないのは、以下の条件が満たされる時である。
//              L1が最も下側と成り得ない = (x1−x0)*(y2−y1) >= (y1−y0)*(x2−x1)
//
//          一方、更に天下り的に、上式は以下にも同値である。
//              (a0, b0), (a1, b1), (a2, b2)の上側凸包の中に、(a1, b1)が含まれない
//
//          従って、(ai, bi) (i = 0..n)が与えられた時、
//              上側凸包として選ばれる集合が、x*q+yの最大値を二分探索できる直線を表す
//
//          上側凸包は、例えばAndrew's Monotone Chainを用いることで、ソートO(n log n) 凸包構築O(n)で計算できる。
//          以上をまとめると、
//              事前にクエリをソートO(n log n) 凸包構築O(n) 最大値取得O(log n)でx*q+yの最大値を求めることができる。
//
//
//
//      次に、クエリが多い場合を考える。
//      クエリをk個のクエリ群に分割して、i番目のクエリ群を処理することを考える。
//      i-1番目のクエリ群を処理し終えたあとに、係数集合に残っているクエリは、i番目のクエリ群によって以下のどれかに分類される。
//          a)  i番目のクエリ群によって削除されないので、絶対残り続ける
//          b)  i番目のクエリ群によって削除されてるかもしれないので、残っているかどうかはその時々で確認しなければならない
//          c)  i番目のクエリ群で追加されるものは、残っているかどうかはその時々で確認しなければならない
//
//      a)の構築は、i番目のクエリ群を処理している間は再度行う必要はない。
//      上側凸包の構築にO(n)が一回だけかかる。
//
//      各クエリに対して、求めるべき答えはmax(a, b, c)となる。
//
//          ここで、i番目のクエリ群のクエリ数をmとすると、
//          b)に分類されるクエリはm個以下である（すべて削除クエリだと最大でm個となる）
//          c)に分類されるクエリはm個以下である（すべて挿入クエリだと最大でm個となる）
//          従って、b), c)による最大値走査は、最悪計算量O(m)である。
//      
//          a)に分類されるクエリはn個以下である。Andrew's Monotone Chainを用いると、
//              最大値計算クエリの処理O(log n)
//          従って、a)による最大値計算は、最悪計算量O(log n)である。
//      
//      以上から、1つのクエリのmax(a, b, c)の計算は、計算量O(m + log n)となる。
//      mつのクエリのmax(a, b, c)の計算は、上側凸包の構築も考慮すると、計算量O(n + m^2 + m log n)となる。
//      k個のクエリ群に分割したので、全体では、計算量O(k n + k m^2 + k m log n)となる。
//
//      ここで、mをsqrt(n)と選ぶこととする。kもsqrt(n)である。
//      全体の計算量はO(n^(3/2))となる。
//
// 感想
//      一般的にクエリが多い時、
//      ある範囲のクエリによって、今まで処理したクエリの結果がそんなに変わらなさそうなときに、クエリの平方分割が有効なのだろうか
//
//      Convex hull trickたのしい
//



#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mt make_tuple
using ll = long long; using ld = long double; using vll = vector<ll>; using vvll = vector<vll>; using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>;

template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
void printbits(ll mask, ll n) { rep(i, n) { cout << !!(mask & (1ll << i)); } cout << endl; }


struct P {
    long long x, y;

    P() : x(0), y(0) {}
    P(long long x, long long y) : x(x), y(y) {}

    P operator-() const {
        return P(-x, -y);
    }

    P operator-(const P &r) const {
        return P(x - r.x, y - r.y);
    }

    bool operator<(const P &r) const {
        return x != r.x ? x < r.x : y < r.y;
    }

};
ostream &operator<<(ostream &o, const P &v) {  o << "(" << v.x << ", " << v.y<< ")"; return o; }

long long cross(P a, P b) {
    return a.x * b.y - a.y * b.x;
}

// Andrew's Monotone Chain
// O(n)
// ps   xについてソートされている点群
// 
// 点群から上側凸包のみ
// もとのAndrew's Monotone Chainでは、上側と下側を統合するので完全な凸包が得られる
const long long NIL = LLONG_MIN;
vector<P> upper_hull(vector<P> &ps) {
    if (ps.size() <= 1) return ps;
    vector<P> a(ps.size());
    int s = 0;
    for (auto p : ps) {
        if (p.x == NIL) continue;
        while (s >= 2 && cross(a[s - 2] - a[s - 1], p - a[s - 1]) <= 0) s--;
        a[s++] = p;
    }
    a.resize(s);
    return a;
}

// 上側凸包から、q*x+yの最大値を求める
// O(log n)
//
// Upper convex hullを左から見ていくと、yも山形だが、q*x+yも山形になっている！（要証明）
// 1 2 3 4 5 4 3 2 1みたいな感じ
// ここで、5を探したいので微分値を二分探索する
long long maximum(vector<P> &hull, long long q) {
    if (hull.empty()) return NIL;
    long long pass = hull.size() - 1;
    long long fail = -1;

    while (pass - fail > 1) {
        long long mid = (pass + fail) / 2;
        if (hull[mid].x * q + hull[mid].y > hull[mid + 1].x * q + hull[mid + 1].y) {
            pass = mid;
        } else {
            fail = mid;
        }
    }

    return hull[pass].x * q + hull[pass].y;
}

int INSERT = 1;
int ERASE = 2;
int GET = 3;
int main() {
    // n:   クエリ数
    int n; cin >> n;

    // クエリを先読み
    //
    // t:   クエリのタイプ
    //      クエリ1      追加クエリ
    //      クエリ2      削除クエリ
    //      クエリ3      参照クエリ
    // x:   追加クエリ   a
    //      削除クエリ   削除すべきindex (0-index)
    //      参照クエリ   q
    // y:   追加クエリ   b
    //      その他クエリ NIL
    //
    // ps:  ((x, y), t)
    vector<long long> t(n), x(n), y(n);
    vector<pair<P, int>> ps(n, make_pair(P(NIL, NIL), -1));
    for (int i = 0; i < n; i++) {
        scanf("%lld", &t[i]);
        ps[i].second = i;
        if (t[i] == INSERT) {
            scanf("%lld %lld", &x[i], &y[i]);
            ps[i] = make_pair(P(x[i], y[i]), i);
        } else if (t[i] == ERASE) {
            scanf("%lld", &x[i]);
            x[i]--;
        } else { // GET
            scanf("%lld", &x[i]);
        }
    }

    // 凸包計算 (Andrew's Monotone Chain) のために、xでソートしておく
    sort(ps.begin(), ps.end());

    // クエリが生きているかのフラグ
    vector<bool> activated(n);

    // 平方分割のサイズ
    const int B = 1000;

    for (int i = 0; i < n; i += B) {
        // 今やる区間＝平方分割の区間 [i, R)
        int R = min(n, i + B); 

        // 今やる区間で変化するクエリjをbucket[j]=1としてチェック
        vector<bool> bucket(n);
        for (int j = i; j < R; j++) {
            if (t[j] == INSERT) {
                bucket[j] = true;
            } else if (t[j] == ERASE) {
                bucket[x[j]] = true;
            }
        }

        // curr:    生きているかよくわからないので確認しないといけないクエリ
        //          つまり、以下のどちらか
        //              今までやった区間では生きていたけど、今やる区間で削除クエリが来たので、生きているかどうかよくわからないクエリの添字
        //              今やる区間でやるクエリ
        // prev:    今までやった区間で生きていて、今やる区間で削除クエリが来ないので、絶対生きているクエリ
        vector<int> curr;
        vector<P> prev;
        for (auto p : ps) {
            int j = p.second;
            if (j >= R) continue;
            if (t[j] == INSERT && activated[j]) { // 今やる区間直前の段階では、生きてるクエリjが、
                if (bucket[j]) { // 今回少なくとも1回は削除されてて、生きてるかどうか怪しいなら
                    curr.push_back(j);
                } else { // 今回なんの操作も加えられないので、今やる区間でも絶対に生き続けているなら
                    prev.emplace_back(p.first);
                }
            } else if (j >= i && t[j] == INSERT) { // 今やる区間でやるクエリ
                curr.push_back(j);
            }
        }

        // 少なくとも絶対生きてるクエリの上側凸包を求めておく
        auto prev_upper = upper_hull(prev);
        /*
        cout << activated<< "#activated" << endl;
        cout << curr << "#curr" << endl;
        cout << prev << "#prev" << endl;
        cout << prev_upper << "#prev_upper" << endl;
        */

        for (int j = i; j < R; j++) {
            if (t[j] == INSERT) {
                activated[j] = true;
            } else if (t[j] == ERASE) {
                activated[x[j]] = false;
            } else { // GET
                // 今までで最大のx*q+yを計算する
                //
                // 今までで最大= max(
                //      絶対生きてるクエリの最大値,
                //      生きてるかよくわからないクエリの中で生きてたクエリたち)

                // 絶対生きてるクエリの最大値
                long long mx = NIL;
                mx = max(mx, maximum(prev_upper, x[j]));

                // 生きてるかよくわからないクエリの中で生きてたクエリたち
                for (int l = 0; l < curr.size(); l++) {
                    int id = curr[l];
                    if (activated[id]) 
                        mx = max(mx, x[id] * x[j] + y[id]);
                }

                if (mx == NIL) {
                    puts("EMPTY SET");
                } else {
                    printf("%lld\n", mx);
                }
            }
        }
    }
}
