#include <bits/stdc++.h>
using namespace std;
void printLCTree(string s);

//**************************************************************
//	link-cut tree
//**************************************************************
struct node {
	node *parent = nullptr;
	node *lch = nullptr;
	node *rch = nullptr;

    int id = -1;
	int dashed_sub = 0; // まさにこのノードへdashedでつながっているsplay木のサイズ合計
	int solid_sub = 1; // splay木で考えた時、このノードを根とする部分木のサイズから、dashedでつながっているものを抜いたもの。
};
ostream &operator<<(ostream &o, const node* v) {
    o << v->id << " ";
    o << (v->parent ? to_string(v->parent->id) : "-") << " ";
    o << (v->lch ? to_string(v->lch->id) : "-") << " ";
    o << (v->rch ? to_string(v->rch->id) : "-") << " ";
    o << "(solid = " << v->solid_sub << ", dashed = " << v->dashed_sub<< ")";
    return o;
}


int sub(node *x) {
	return x == nullptr ? 0 : x->solid_sub + x->dashed_sub;
}

void update(node *x) {
	if (x == nullptr) return;
	x->solid_sub = 1 + sub(x->lch) + sub(x->rch);
}

void push(node *x) {
	if (x == nullptr) return;
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
	if (x == nullptr) return;
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

		y->dashed_sub += sub(y->rch);
		y->dashed_sub -= sub(rch);
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


int n;
void link(node *x, node *p) {
	expose(x);
	expose(p);
	x->parent = p;
    printLCTree("link bef");

	p->dashed_sub += sub(p->rch); // これ本当にいる？？（p->rchは常にNULLのはずなので）

	p->rch = x;
    printLCTree("link aft");

	update(x);
	update(p);
}

set<int> g[202020];
node *tr[202020];
int depth[202020];

void printLCTree(string s = "") {
    cout << "##### " << s << endl;
    for (int i = 0; i < n; i++) cout << tr[i] << endl;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
        tr[i] = new node();
        tr[i]->id = i;
    }

    printLCTree();
    while (1) {
        string s; cin >> s;
        if (s == "link") {
            int u, v; cin >> u >> v;
            link(tr[u], tr[v]);
        } else if (s == "cut") {
            int u; cin >> u;
            cut(tr[u]);
        } else {
            cerr << "INVALID" << endl;
            return 1;
        }
        printLCTree();
	}
}
