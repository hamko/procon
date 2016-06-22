#include <bits/stdc++.h>
using namespace std;
 
//**************************************************************
//	link-cut tree
//**************************************************************
struct node {
	// node *parent = nullptr;
	// node *lch = nullptr;
	// node *rch = nullptr;
	// bool reversed = false;
	node *parent;
	node *lch;
	node *rch;
	bool reversed;
 
	int id;
	node(int id) : id(id) {
		parent = lch = rch = nullptr;
	}
};
ostream &operator<<(ostream &o, const node* v) {
    o << (v->parent ? to_string(v->parent->id) : "-") << " ";
    o << (v->lch ? to_string(v->lch->id) : "-") << " ";
    o << (v->rch ? to_string(v->rch->id) : "-") << " ";
    return o;
}

void update(node *x) {
	if (x == nullptr) return;
}
 
void push(node *x) {
	if (x == nullptr) return;
	// for (node *y : { x->lch, x->rch }) if (y != nullptr) {
		// y->reversed ^= x->reversed;
	// }
	if (x->reversed) swap(x->lch, x->rch);
 
	x->reversed = false;
 
	update(x);
}
 
//**************************************************************
//	link-cut tree basic operation
//**************************************************************
enum { LEFT, RIGHT };
 
bool is_root(node *x) {
	return x->parent == nullptr || (x->parent->lch != x && x->parent->rch != x);
}
 
int parent_direction(node *x) {
	if (is_root(x)) return -1;
	return x->parent->rch == x ? LEFT : RIGHT;
}
 
void connect(node *child, node *parent, int dir) {
	if (parent != nullptr && dir != -1) (dir == RIGHT ? parent->lch : parent->rch) = child;
	if (child != nullptr) child->parent = parent;
}
 
void raise(node *x) {
	node *y = x->parent;
	node *z = y->parent;
	int xdir = parent_direction(x);
	int ydir = parent_direction(y);
	connect(xdir == LEFT ? x->lch : x->rch, y, xdir);
	connect(y, x, !xdir);
	connect(x, z, ydir);
	update(y);
	update(x);
	update(z);
}
 
void splay(node *x) {
	while (!is_root(x)) {
		push(x->parent->parent);
		push(x->parent);
		push(x);
		if (is_root(x->parent)) {
			raise(x);
		} else if (parent_direction(x) == parent_direction(x->parent)) {
			raise(x->parent);
			raise(x);
		} else {
			raise(x);
			raise(x);
		}
	}
	push(x);
}
 
void expose(node *x) {
	for (node *y = x, *rch = nullptr; y != nullptr; y = y->parent) {
		splay(y);
		y->rch = rch;
		rch = y;
		update(y);
	}
	splay(x);
}
 
void cut(node *x) {
	expose(x);
	x->lch->parent = nullptr;
	x->lch = nullptr;
	update(x);
}
 
void link(node *x, node *p) {
	expose(x);
	expose(p);
	x->parent = p;
	p->rch = x;
	update(x);
	update(p);
}
 
void evert(node *x) {
	expose(x);
	x->rch = x->lch;
	x->lch = nullptr;
	if (x->rch != nullptr) x->rch->reversed ^= 1;
	update(x);
}
 
//**************************************************************
//	main
//**************************************************************
 
node *lca(node *x, node *y) {
	expose(y);
	expose(x);
 
	bool same = false;
 
	node *l = y;
	while (y != nullptr) {
		if (is_root(y) && y->parent != nullptr) {
			l = y->parent;
		}
		if (y == x->rch) return x;
		if (x == y) same = true;
		y = y->parent;
	}
	if (!same) return nullptr;
	return l;
}
 
node *tr[1000100];
 
int main() {
    /*
	int n, q;
	cin >> n >> q;
    */
	int n;
	cin >> n;
 
	for (int i = 0; i < n; i++) 
        tr[i] = new node(i);

    for (int i = 0; i < n; i++) 
        cout << tr[i] << endl; 
	while (1) {
        cout << "--------" << endl;
		int t;
		scanf("%d", &t);
 
		if (t == 1) {
			int u, v;
			scanf("%d %d", &u, &v);
			u--; v--;
 
			link(tr[u], tr[v]);
		} else if (t == 2) {
			int u;
			scanf("%d", &u);
			u--;
 
			cut(tr[u]);
		} else {
			int u, v;
			scanf("%d %d", &u, &v);
			u--; v--;
 
			node *l = lca(tr[u], tr[v]);
			int ans = l == nullptr ? -2 : l->id;
//			printf("%d\n", ans + 1);
		}
        for (int i = 0; i < n; i++) 
            cout << tr[i] << endl; 
	}
}
