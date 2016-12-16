#include <bits/stdc++.h>
#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;

// 根ノードを1としているので、
// 左の子：k*2
// 右の子：k*2+1
// 親：floor(k/2)
// となる。
// 根ノードを1とすると非再帰が書きやすい（二進数的性質が優れているため）のだが、
// 再帰的に書くのであればどちらでも問題ない。

const int N = 1 << 3;  // 葉の個数
const int NIL = INT_MAX;

int maxi[N * 2]; // ノードkに対応する区間の最大値
int lazy[N * 2]; // lazy[k]はノードkの配下全体をlazy[k]で塗りつぶすという命令を表す。lazy[k]=NILのときは何もしないと約束する

// 「頂点kを最新に更新する」を定義する。
// 
// 「頂点kの最大値データを正しい状態にする。
// でも、頂点kよりも子供側は、まだ正しい状態にしない。
// その代わり、頂点kの子供を最新の状態にするための情報lazyを持っておく。」

// 頂点kを最新の状態にする
void setLazy(int k, int v) {
    lazy[k] = v;

    // このノードの配下全体を v で塗りつぶす予定なのだから、当然、ノードkの最大値はvである
    maxi[k] = v;

    // *** 余談 ***
    // この発想が遅延セグメント木ではもっとも重要。
    // 命令がO(1)のメモリで表現でき、命令のマージが高速にできるのであれば遅延セグメント木で対処できる。
    // たとえば、区間加算と区間塗りつぶしの機能を両方備えたセグメント木を作るのであれば、
    // 
    // fill v := v で塗りつぶせ
    // add v := v を加算しろ
    //
    // という二種類の命令が必要になるだろう。
    // add u をした後に fill v をすることを (fill v) . (add u) と書くことにしよう。
    // このとき以下の関係式が成り立つ。
    // 
    // (add v) . (add u) = (add v+u)
    // (add v) . (fill u) = (fill v+u)
    // (fill v) . (add u) = (fill v)
    // (fill v) . (fill u) = (fill v)
    // 
    // つまり、add u と fill u 同士の演算は (add or fill, Int) で閉じている。
    // よって、命令は add であるか fill であるかという二値の情報と、加算/塗りつぶす値の 2 つの情報によって表現できる。
    // 複数の命令を、等価な単一の命令に置き換えられるか？、と考えると分かりやすいかもしれない。
    //
    // 遅延セグメント木はかならず時系列順にマージすることになる。
    // これが遅延伝搬セグメント木の最大の利点といえる。
    // 要するに、非可換の命令を扱うのに適している。
    // 
    // 誤解を生まないように一応書いておくが、塗りつぶしを遅延伝搬なしに書くことは不可能ではない。
    // 塗りつぶした時間も保持しておけば、
    //  (timeS, valueS) . (timeT, valueT) = max((timeS, valueS), (timeT, valueT))
    // として可換操作に変形できる。
}

// 頂点kの子供を最新の状態にする。
// push(x)すると、xのlazyがなくなる。
// 
// lazyがないならば、子供が最新である。
// 子を最新にし終えたので、lazyを解消する。
//
// lazyを持つ頂点の子供は全員、maxiが最新の状態に更新されていない。なので、maxiを見ても意味がない。
// 子供が正しい状態にするための情報は、親が握っている。
// なので、子供のmaxiにアクセスするためには、その頂点の親全てを上からpushしていかなければならない。
void push(int k/*node_id*/) {
    // 遅延命令がなにもなければ何もしない
    if (lazy[k] == NIL) {
        return;
    }
    // 子に伝播して
    setLazy(k * 2 + 0, lazy[k]);
    setLazy(k * 2 + 1, lazy[k]);
    
    // 子に命令を伝搬させたので、命令を空にする
    lazy[k] = NIL;
}

void fix(int k) {
    // ノードkに対応する区間の最大値は、「左の子の最大値」と「右の子の最大値」の最大値
    maxi[k] = max(maxi[k * 2], maxi[k * 2 + 1]);
}

// 区間[queryL,queryR)をvalで塗りつぶす
// kはノード番号で、[nodeL, nodeR)の区間を表す（本当は情報的にはkのみで良いが、簡便のためにnodeL, nodeRも関数に渡している）
void fill(int queryL, int queryR, int val, int k = 1 /*node_id*/, int nodeL = 0, int nodeR = N) {
    cout << queryL << " " << queryR << " " << val << " " << k << " " << nodeL << " " << nodeR << endl;
    // クエリ区間とノード区間が交差していないなら、これ以上、処理する意味はない
    if (nodeR <= queryL || queryR <= nodeL) {
        return;
    }
    // ノード区間がクエリ区間に完全に覆われたら、遅延命令をセットして、さっさと帰る
    if (queryL <= nodeL && nodeR <= queryR) {
        setLazy(k, val);
        return;
    }
    // ノードが下がるときには命令をpushする
    push(k); // 子を最新の状態にしないと下がれないのでpush
    int nodeM = (nodeL + nodeR) / 2;
    fill(queryL, queryR, val, k * 2 + 0, nodeL, nodeM);
    fill(queryL, queryR, val, k * 2 + 1, nodeM, nodeR);

    // ノードが上がるときには情報をfixする
    fix(k);
}

// 区間[queryL, queryR)の最大値を求める
int maximum(int queryL, int queryR, int k = 1, int nodeL = 0, int nodeR = N) {
    // クエリ区間とノード区間が交差していない
    if (nodeR <= queryL || queryR <= nodeL) {
        return INT_MIN;
    }
    // ノード区間がクエリ区間に完全に覆われた
    if (queryL <= nodeL && nodeR <= queryR) {
        return maxi[k];
    }
    // ノードが下がるときには命令をpushする
    push(k); // 子を最新の状態にしないと下がれないのでpush
    int nodeM = (nodeL + nodeR) / 2;
    int vl = maximum(queryL, queryR, k * 2 + 0, nodeL, nodeM);
    int vr = maximum(queryL, queryR, k * 2 + 1, nodeM, nodeR);
    return max(vl, vr);
}

void print(int n) {
    rep(i, (1ll<<(n+1))) {
        if (i) cout << maxi[i] << " "; 
    }
    cout << endl;
    rep(i, (1ll<<(n+1))) {
        if (i) cout << (lazy[i] == NIL ? "nil" : to_string(lazy[i])) << " "; 
    }
    cout << endl;
}

int main() {
    for (int i = 0; i < N * 2; i++) {
        lazy[i] = NIL;
    }

    // 0---
    // 0-0-
    // 0000

    fill(0, 6, 5);
    
    // 5      -     -      -
    // 5(5)   -     5(5)   -
    // (w)    (w)   (w)    0


    print(3);
}
