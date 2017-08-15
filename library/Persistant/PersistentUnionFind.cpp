#include <bits/stdc++.h>
using namespace std;
 
// 見た目はコピーが高速なUnion-Find

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
 
	T immutable_get(int k) {
		return immutable_get(k, root, 0, h)->value;
	}
 
private:
	struct node {
		node *ch[16] = {};
		T value;
 
		node() {}
		node(T value) : value(value) {}
	};
 
	int h;
	node *root = nullptr;
 
	node *immutable_get(int a, node *x, int l, int d) {
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
 
// root: O(logN loglogN)
// merge: O(logN loglogN)
struct UnionFind {
	struct node {
		int parent;
		int size;
	};
 
	Array<node> uf;
 
	UnionFind() : uf(0) {}
 
	UnionFind(int n) : uf(n) {
		for (int i = 0; i < n; i++) {
			node *nd = uf.mutable_get(i);
			nd->parent = i;
			nd->size = 1;
		}
	}
 
	int root(int x) {
		node nd = uf.immutable_get(x);
		if (nd.parent == x) return x;
		return root(nd.parent);
	}
 
	UnionFind merge(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y) return *this;
 
		node *u = uf.mutable_get(x);
		node *v = uf.mutable_get(y);
 
		u->parent = v->parent = u->size > v->size ? x : y;
		u->size = v->size = u->size + v->size;
		return *this;
	}
 
	bool same(int x, int y) {
        return root(x) == root(y);
    }

	int size(int x) {
        return uf.immutable_get(root(x)).size;
    }

	int query(int x, int y) {
        // Something
        /*
		x = root(x);
		y = root(y);
		if (x != y) {
			return uf.immutable_get(x).size + uf.immutable_get(y).size;
		} else {
			return uf.immutable_get(x).size;
		}
        */
        return 0;
	}
};
 
#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
int main() {
    int hisnum = 4;
    int nodenum = 4;
	vector<UnionFind> his(hisnum);
	UnionFind uf(4); 
 
    his[0] = uf; // 何もmergeしていない
    his[1] = uf.merge(0, 1);
    his[2] = uf.merge(2, 3);
    his[3] = uf.merge(0, 2);

    rep(i, hisnum) {
        rep(j, nodenum) {
            cout << his[i].size(j) << " ";
        }
        cout << endl;
    }

    return 0;
}
