#include <bits/stdc++.h>
using namespace std;

// データ型T, 単位元T0, 可換二項演算子opが与えられた時、
//
// 点更新opをO(log n)、0-indexの範囲sum(int j)をO(log n)で実現
// もしopに逆演算が定義できるならば、i-indexの範囲sum(int i, int j)が実現可能。

// 0-indexed, sumは閉区間なので注意！！

void printBit(int a) {cout << a << " "; for(; a > 0; a >>= 1) cout << (a & 1); cout << "#bit" << endl;}
template <class T>
struct fenwick_tree {
    /**********************/
    // 実装箇所
    /**********************/
    T T0 = 0;
    T op(T a, T b) { return a + b; }
    /**********************/
    // 実装終わり
    /**********************/

    // xのデータ構造。op=+, invop=1, T=int, T0=0の場合
    // iが最右添字な数字列をs[i]として、x[i] = s[i]の総和 (例: i=5, s[i]="45", x[i]=9)
    // 0123456789ABCDEF
    // 01234567--------
    // 0123----89AB----
    // 01--23--89--CD--
    // 0-2-4-6-8-A-C-E-
    int n_org;
    vector<T> x;
    fenwick_tree(int n_)  { 
        n_org = n_;
        int n = 1; while (n <= n_) n *= 2;
        x = vector<T>(n, T0);
    }

    // 範囲クエリ: [0, j]のreduceを行う。閉区間に注意
    // O(log n)
    T query(int j) {
        T S = T0;
        for (j; j >= 0; j = (j & (j + 1)) - 1)  // jは、C->B->7と遷移する。0からCをカバーするための数字列の添字へ飛ぶ
            S = op(S, x[j]); 
        return S;
    }

    // 更新クエリ: #kにaを演算する
    // O(log n)
    void update(int k, T a) {
        for (; k < x.size(); k |= k+1) // kは、C->D->Fと遷移する。Cをカバーする数字列全てに飛ぶ
            x[k] = op(x[k], a); 
    }

    // #kにアクセスする
    // O(log n)
    T access(int k) {
        return query(k) - (k ? query(k-1) : 0);
    }
    void print(void) {
        for (int i = 0; i < n_org; i++) 
            cout << access(i) << " ";
        cout << endl;
    }
    void print_raw(void) {
        for (int i = 0; i < x.size(); i++) 
            cout << x[i] << " ";
        cout << endl;
    }
};


int main(void) {
    int n = 16;
    fenwick_tree<int> f(n);
    for (int i = 0; i < n; i++)
        f.update(i, i);

    // 生を見てみる
    for (int i = 0; i < n; i++)
        cout << f.x[i] << endl;

    cout << f.query(0, n-1) << endl; 

    return 0;
}
