#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
 
// 見た目はコピーが高速なUnion-Find
// Arrayは配列に見えるが、実態はint h, node* rootのたったの64bitなのでコピーが早い。
// 動的に作るノードはArrayの管理下ではあるが、Array自体が持っているわけではない

// mutable_getのたびにノードが動的に一個ずつ増えていく。
// 変更クエリでないなら、変にノード作ってもしょうがないので、immutable_getを使うこと。
// コピーの時には、rootが適切な位置に来るから永続になる。

// memory: O(Q loglogN logN)
// mutable_get: O(loglogN logN)
// immutable_get: O(loglogN)

template<class T>
class Array {
public:
	Array() {}
 
	Array(int n) {
		h = 0;
		for (int i = 1; i < n; i *= 16) h += 4;
	}
 
	T *mutable_get(int k) {
		auto p = mutable_get(k, root, 0, h);
		root = p.first;
		return &p.second->value;
	}
 
    // 存在しないとランタイムエラーを吐く！デフォルト値を定義したい
	T immutable_get(int k) {
        auto p = immutable_get(k, root, 0, h); 
		return !p ? 0 : p->value; // 0はデフォルト値！
	}
 
//private:
	struct node {
		node *ch[16] = {};
		T value;
 
		node() {}
		node(T value) : value(value) {}
	};
 
	int h;
	node *root = nullptr;
 
	node *immutable_get(int a, node *x, int l, int d) {
        if (!x) return nullptr; // 頂点がなければヌルポインタを返す
		if (d == 0) return x;
		int id = (a - l) >> (d - 4);
		return immutable_get(a, x->ch[id], l + (id << (d - 4)), d - 4);
	}
 
	pair<node *, node *> mutable_get(int a, node *x, int l, int d) {
		x = x != nullptr ? new node(*x) : new node();
		if (d == 0) return make_pair(x, x);
		int id = (a - l) >> (d - 4);
		auto p = mutable_get(a, x->ch[id], l + (id << (d - 4)), d - 4);
		x->ch[id] = p.first;
		return make_pair(x, p.second);
	}
};
 
using ll = long long;
#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
int main() {
    {
        cout << "######" << endl;
        ll n = 4;
        Array<ll> a(n);
        rep(i, n) cout << a.immutable_get(i) << " "; cout << endl;
        *(a.mutable_get(1)) = 1;
        cout << a.immutable_get(1) << endl;

        Array<ll> b;
        b = a;
        *(b.mutable_get(1)) = 3;
        cout << a.root << endl;
        cout << b.root << endl;
        cout << a.immutable_get(1) << endl;
        cout << b.immutable_get(1) << endl;

    }

    {
        cout << "######" << endl;
        // 見た目はコピーが早いArray
        Array<ll> a(2); 
        vector<Array<ll>> his(4);
        ll* p;
        p = a.mutable_get(1); *p = 8;
        his[0] = a;

        p = a.mutable_get(1); *p = 5;
        his[1] = a;

        cout << his[0].immutable_get(1) << endl;
        cout << his[1].immutable_get(1) << endl;

        *his[0].mutable_get(1) = 2;
        *his[1].mutable_get(1) = 3;

        cout << his[0].immutable_get(1) << endl;
        cout << his[1].immutable_get(1) << endl;
    }

    return 0;
}
