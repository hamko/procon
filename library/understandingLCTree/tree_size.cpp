#include <bits/stdc++.h>
#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back
using namespace std;
void printLCTree(string s);

// 要するに、
// x->lchあるいはx->rchをいじったら、xの頂点に載っているデータを更新しなければならない！！！ということ。
// parentをいじっても、別に何もしない。
// 
// また、このソースコードは部分木の可換モノイドのreductionをする典型例と言えるだろう。


// 重要！！！！！！！！
// 頂点xに載せるパスクエリの情報は、
/*
void fix(node *x) {
    x->w = 1 + x->l->w + x->r->w;
    Tuple t = { x->val, x->val, x->val, x->val };
    x->t = x->l->t * t * x->r->t;
}
*/
// のように、結合順序を決めて、左の子・自分・右の子のマージとなっている！
// 
// 実は、部分木のsolid_subも同様のことをしている（splay木のサイズを持っていると言えるので。）

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

// この関数は、x->parentに依存しない形で書かなければならない！
// なぜなら、raise関数内でx->?ch->parentを書き換えるが、updateはx->?chに対して行っていないので。
// 
// じゃあraise関数内でx->?chも更新すればどうなる？？
// 
// また、この関数はsolid_subだけを変更していて、dashedの更新はしないことに注意
// つまり「splay木内部のことしか考えていない」！
// 
// じゃあ、dashedの更新いつやるの？というと、
// splay木をマージするlink, cut, exposeのときにやる。
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

// 子から見て親がどっち方向か
int parent_direction(node *x) {
	if (is_root(x)) return -1;
	return x->parent->rch == x ? LEFT : RIGHT;
}

// childから見てparentがdir方向になるように接続
// この操作で重要なのは、副作用がchildとparentに限定されていること！
// 
// 特にchildは、副作用は親のみである。
// したがって、「自分より子供の」といった子供方向を見る条件であれば、updateする必要はない
void connect(node *child, node *parent, int dir) {
	if (parent != nullptr && dir != -1) (dir == RIGHT ? parent->lch : parent->rch) = child;
	if (child != nullptr) child->parent = parent;
}

// xとx->parentの深さを逆転させる。
//
//        z           z
//       /           /
//      y           x
//    /  |   ->    / |
//   x   c        a  y
//  / |             / |
// a  b            b  c
// 
// x->pの方向xdirを覚える。その後、xのxdirの逆の子を、dirの方向でyにくっつける！
// その後、yを子としてxを逆向きにつけ、xを子としてzにydirの方向につける。
//
// この操作で重要なのは、
//     x, y, zのparent, lch, rch
//     xの子のどちらかのparentのみ
// に副作用を起こす点である。
// 
void raise(node *x) {
	node *y = x->parent;
	node *z = y->parent;
	int xdir = parent_direction(x);
	int ydir = parent_direction(y);
	connect(xdir == LEFT ? x->lch : x->rch, y, xdir);
	connect(y, x, !xdir);
	connect(x, z, ydir);
    // この順番は、子から親へと向かう方向
    // 上記の操作で、必ずxとyの深さのみが逆転する。
	update(y);
	update(x);
	update(z);
}

void splay(node *x) {
	if (x == nullptr) return;
	while (!is_root(x)) {
        // 親から子への方向でpushする。
        // pushは子への伝播なので、親のほうからやらないといけない。
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

		y->dashed_sub += sub(y->rch); // y->rchはぶったぎられるので、次はdashedになる
		y->dashed_sub -= sub(rch); // rchはくっつけられるので、今までdashedだったものがdashedではなくなる
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

    assert(sub(p->rch) == 0);
	p->dashed_sub += sub(p->rch); // これ本当にいる？？（p->rchは常にNULLのはずなので）そもそもlinkしたらxとpは絶対solidになるはず。

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
struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) { }
    bool unite(int x, int y) { x = root(x); y = root(y); if (x != y) { if (data[y] < data[x]) swap(x, y); data[x] += data[y]; data[y] = x; } return x != y; }
    bool find(int x, int y) { return root(x) == root(y); }
    int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
    vector<vector<int>> getUnionList(void) { map<int, vector<int>> c; for (int i = 0; i < data.size(); i++) c[root(i)].pb(i); vector<vector<int>> v; for (auto x : c) v.push_back(x.second); return v; }
};

#include <unistd.h>
#include <time.h>
#include <sys/time.h>
const string db = "\"";
void vizLCTree(node** tr, int n, string title = "", string filename = "out.png") {
    ofstream ofs("./out.dot");
    ofs << "digraph graph_name {" << endl;
    // start
    rep(i, n) {
        ofs << tr[i]->id;
        ofs << "[label=\""+to_string(tr[i]->id);
        // ここからノードの状態の描画
        ofs << "\n(solid_sub : " << tr[i]->solid_sub << " )";
        ofs << "\n(dashed_sub : " << tr[i]->dashed_sub << " )";
        // ここまでノードの状態の描画
        ofs << "\"]" << endl;
    }

    rep(i, n) {
        if (tr[i]->parent && !(tr[i]->parent->lch == tr[i] || tr[i]->parent->rch == tr[i])) 
            ofs << db << tr[i]->id << db << "->" << db << tr[i]->parent->id << db << "[label=\"p\"]" << endl;
        if (tr[i]->lch) ofs << db << tr[i]->id << db << "->" << db << tr[i]->lch->id << db  << "[label=\"l\"]"  << endl;
        if (tr[i]->rch) ofs << db << tr[i]->id << db << "->" << db << tr[i]->rch->id << db  << "[label=\"r\"]"  << endl;
    }

    // 強連結をくくる
    {
        UnionFind uf(n);
        rep(i, n) if (tr[i]->parent && (tr[i]->parent->lch == tr[i] || tr[i]->parent->rch == tr[i])) 
            uf.unite(i, tr[i]->parent->id);
        auto clusters = uf.getUnionList();
        rep(i, clusters.size()) {
            auto&& cluster = clusters[i];
            ofs << "    subgraph cluster_" << to_string(i) << " {" << endl;
            for (auto&& node : cluster) 
                ofs << "        " << db << node << db << endl;
            ofs << "    }" << endl;
        }
    }

    if (title != "") {
          ofs << "overlap=false" << endl;
          ofs << "label=" << db << title << db << endl;
          ofs << "fontsize=12;" << endl;
    }

    // end
    ofs << "}" << endl;
    ofs.close();
    system(((string)"dot -T png out.dot > " + filename + "&").c_str());
    usleep(1000000);
//    system(((string)"dot -T png out.dot > `date \"+\%Y\%m%d_\%H\%M%S\"`.png").c_str());




    // TODO
    // 実際の木の様子を眺められるようにしたい。
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
            vizLCTree(tr, n, "link "+to_string(u)+" "+to_string(v));
        } else if (s == "cut") {
            int u; cin >> u;
            cut(tr[u]);
            vizLCTree(tr, n, "cut "+to_string(u));
        } else if (s == "expose") {
            int u; cin >> u;
            expose(tr[u]);
            vizLCTree(tr, n, "expose "+to_string(u));
        } else if (s == "splay") {
            int u; cin >> u;
            splay(tr[u]);
            vizLCTree(tr, n, "splay "+to_string(u));
        }  else {
            cerr << "INVALID" << endl;
            return 1;
        }
        printLCTree();
	}
}
