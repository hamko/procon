#include <bits/stdc++.h>
using namespace std;

//**************************************************************
//	link-cut tree
//**************************************************************
struct node {
	node *parent = nullptr;
	node *lch = nullptr;
	node *rch = nullptr;

	int solid_sub = 1;
	int dashed_sub = 0;
};

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

void link(node *x, node *p) {
	expose(x);
	expose(p);
	x->parent = p;

	p->dashed_sub += sub(p->rch);

	p->rch = x;

	update(x);
	update(p);
}

set<int> g[202020];
node *tr[202020];
int depth[202020];

void dfs(int curr, int prev) {
	for (int next : g[curr]) if (next != prev) {
		depth[next] = depth[curr] + 1;
		link(tr[next], tr[curr]);
		dfs(next, curr);
	}
}

void cut(int u, int v) {
	if (depth[u] < depth[v]) swap(u, v);
	cut(tr[u]);
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) tr[i] = new node();

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--; v--;
		g[u].insert(v);
		g[v].insert(u);
	}

	dfs(0, -1);

	int ans = 0;

	int q;
	cin >> q;

	for (int i = 0; i < q; i++) {
		int m;
		scanf("%d", &m);
		int v = (ans ^ m) - 1;

		expose(tr[v]);
		ans = sub(tr[v]);

		for (int u : g[v]) {
			g[u].erase(v);
			cut(u, v);
		}

		printf("%d\n", ans);
	}
}
