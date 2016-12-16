// pekempeyさんのLCTree
// iwiwi先生のLCTree解説 http://www.slideshare.net/iwiwi/2-12188845
// Masaki HaraのSpaceship解説 http://www.slideshare.net/qnighy/2013-spaceships2
// もうちょっと厳密な資料 http://www.lab2.kuis.kyoto-u.ac.jp/fswikiout/wiki.cgi?action=ATTACH&page=2009%C7%AF%C5%D9%B7%D7%BB%BB%CE%CC%CD%FD%CF%C0&file=lecture4.pdf


// LCTreeは根付き森を表す。

// 用語定義
//
// Splay木の根    Splay木内部での根
// 真の根         根を含むSplay木内部での根。この親はNULL
// 木の根         真の根を含むSplay木内部での最も左の頂点

// Splay木
// 平衡二分探索木（ランダムに入力されることを前提としてO(log n), 昇順でO(n)）
//
// 理解のポイント
//
// まず、「木をたくさんの列に分解することで表現している」
// 同じ列であることは、強連結であることで特徴付けている

// 「列を平衡二分探索木で表現している」
// 左が根に近く右が根から遠くなるように、列を平衡二分探索木で表現する。
// 
// 平行二分探索木を使って、ハイローゲームをしていると思うとわかりやすい。
// 長さnの列の順番を確定させるには、n-1個の情報（=大きさnの木の辺の数）があれば十分である。
//
// 木の根に近いほうが「小さい」ノードであると定義すると、列は平衡二分探索木で表現できる
// 
// 例えば、
//   5 - 3 - 2 - 1
// という列を二分探索木で表すとする。
// まず、どこを基準にするかを決める。
// ここでは3を基準とすると、この列を再現するには、「3より5が左側」「3より{1, 2}が右側」「1より2が左側」という情報が必要
// これを表したSplay木は以下のようになる。
//     3
//   /   |
//  5    1
//      /
//     2
// どんな情報であっても、このようなSplay木が構成可能である。

// 「木の根」について
// 二分探索木が、親がNULLの頂点を有するならば、その二分探索木は「木の根」を有する。
// 二分探索木は、「左が根に近く右が根から遠くなる」の定義から、最も左が根の候補である。
// 以上から、「親がNULLの頂点を有するSplay木の最も左の頂点が木の根」である。
//
// ここで勘違いしないでほしいのは、親がNULLの頂点は、木の根では一般的にはない！
// Splay木はあくまで左にあるやつが根に近いことを忘れないように。

// 二分探索木が与えられた時、二分探索木が表す順序は一意に定まる！
// 具体的には、二分探索木の根から、「左が終わってないなら左に移動、左が終わってるなら自分を取る、自分も左も終わってるなら右に移動、全部終わってるなら親に戻る」を繰り返せば、列を復元できる

// splay(x)すると何が嬉しいか？
// splay(x)後は、
// xの右の子以降が絶対に自分より葉側であり、xの左の子以降が絶対に自分より根側である！
// だから、
// exposeでは右だけ張り替えればよいし、
// cutでは左だけ切ればよい。

// expose(x)すると何が嬉しいか？
// xの右側が全部ぶった切られるので、xがxの属するSplay木の中で最も葉側であることが保証される！（重要）
// 別の木ならば、Splay木をそのまま貼り付けることができるようになる


// updateは子側から、pushは根側から。

// splay木の部分木は必ず連続した列になっている
// TODO
// raiseは列でいうとどういう操作をしているの？？？？

// 典型的なlazyに、「あとで値をsetする」というのがある
// if (x->lazy != none) x->val = x->lazy;

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
 
//**************************************************************
//	link-cut tree
//**************************************************************
struct node {
    // 重要なのは
    // 「Splay木内では、自分の親は自分を子だと思ってくれている」
    // 「Splay木間では、自分の親は知っているが、
    // 　親は自分を子だと認識してくれていない！」
    //
    // 上記の違いによって、いわゆる
    //      Solid edgeとDashed edge
    //      Preferred edgeとNormal edge
    // の区別ができている。
    //
    // 要するに、Splay木間では片方向のリンクしか張られない、ということ
    //
    // http://www.slideshare.net/iwiwi/2-12188845 (p.22参照)
	node *parent;

    // これらはparentとは異なり、平衡二分探索木内での左右のノード、という一意な意味
    // lchが根に近く、rchが根から遠い
	node *lch;
	node *rch;

	bool reversed;
	int id;
	node(int id) : id(id) {
		parent = lch = rch = nullptr;
	}
};
node *tr[1000100];
unordered_map<node*, int> tr_inv;

ostream &operator<<(ostream &o, const node* v) {
    o << (tr_inv[(node*)v]) << " ";
    o << (v->parent ? to_string(v->parent->id) : "-") << " ";
    o << (v->lch ? to_string(v->lch->id) : "-") << " ";
    o << (v->rch ? to_string(v->rch->id) : "-") << " ";
    if (v->reversed) o << "(rev) ";
    return o;
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
    ofs << "graph [ordering=\"out\"];" << endl;
    // start
    rep(i, n) {
        ofs << tr[i]->id;
        ofs << "[label=\""+to_string(tr[i]->id);
        // ここからノードの状態の描画
        if (tr[i]->reversed) 
            ofs << "\n(rev)";
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

string get_filename(void) {
    struct timeval myTime; struct tm *time_st; gettimeofday(&myTime, NULL); time_st = localtime(&myTime.tv_sec);
    return "images/`date \"+\%Y\%m%d_\%H\%M%S\"`_"+to_string(myTime.tv_usec)+".png";
}


// なんだこれ
// 何もやってない
// nodeに対する操作が必要になったら実装される？
void update(node *x) {
	if (x == nullptr) return;
}
 
// reversedは一回だけ左右の子をswapして、フラグを落としている
// reversedを除けば何もしていない
void push(node *x) {
	if (x == nullptr) return;
    // reversedというのは、左右の子を交換するということ。遅延処理。
	if (x->reversed) { 
        swap(x->lch, x->rch); 
        x->reversed = false;
    }

    update(x);
}

//**************************************************************
//	link-cut tree basic operation
//**************************************************************
enum { LEFT, RIGHT };
 
// xが「根」か判定
//
// 「根」とは、「木の根」と「splay木の根」の両方にヒットすることに注意
// 真の根だけを抽出したいなら、x->parent == nullptrで行うこと。
// 更に注意点としては、Link-cut treeは実はTreeというよりForestなので、
// x->parent == nullptrとなるノードは複数存在しうる。
//
// splay木の根を抽出するには、親が自分のことを子だと認知していなければいい
bool is_root(node *x) {
	return x->parent == nullptr ||
        (x->parent->lch != x && x->parent->rch != x);
}
 
// xに取って、親がどっち方向にいるかを判定
// 親が子をどちらにもつか、ではないので注意!
// 親がいなければ-1
int parent_direction(node *x) {
	if (is_root(x)) return -1;
	return x->parent->rch == x ? LEFT : RIGHT;
}
 
// childにとって、parentがdir方向にいるように、parentにつける
void connect(node *child, node *parent, int dir) {
	if (parent != nullptr && dir != -1)
        (dir == RIGHT ? parent->lch : parent->rch) = child;
	if (child != nullptr)
        child->parent = parent;
}
 
// zig-step = xを1つ上に上げるような回転を行う
//     z   
//    /   |
//   y    4 
//  /  |
//  x  3 
// / |
// 1 2 
//
// を、以下のようにする
//
//    z   
//  /    |
//  x    4 
// /  |
// 1  y
//   / |
//   2 3
void raise(node *x) {
	node *y = x->parent; // xの親
	node *z = y->parent; // xの親の親
	int xdir = parent_direction(x);
	int ydir = parent_direction(y);
	connect(xdir == LEFT ? x->lch : x->rch, y, xdir);
	connect(y, x, !xdir);
	connect(x, z, ydir);
	update(y);
	update(x);
	update(z);
}
 
// 頂点xをsplay木の根まで持っていく
void splay(node *x) {
	while (!is_root(x)) {
		push(x->parent->parent);
		push(x->parent);
		push(x);
        // zig-step すぐ上が根の場合は普通に回転
		if (is_root(x->parent)) { 
			raise(x);
        // zig-zig-step 
		} else if (parent_direction(x) == parent_direction(x->parent)) {
			raise(x->parent);
			raise(x);
        // zig-zag-step 
		} else {
			raise(x);
			raise(x);
		}
	}
	push(x);
}
 
// 「木の根からxまでのパス」を何がなんでもくくり出したsplay木を構成する
// このsplay木は、木の根を必ず含み、xの子側がNULLであることが保証される（最後にsplay(x)するので）。
// この関数の考察は、表の木で行ったほうがいい（裏の木だと頭がこんがらがる）
//
// やっていることは、
// 「葉側をぶった切って、次のsplay木に行って、くっつける」を繰り返している
//
// 重要なこととして、exposeの結果は「見た目」一意でない（もちろんsplayの実装見れば一意だが…）。
// デバッグの時は、exposeの結果が同じ木を表現していることを確認するくらいが関の山。
// 
// 英語の意味は「むきだしにする」「掘り出す」
//
// rch : 「前は別のsplay木だったけど、今回マージされるsplay木の根」
// y : 「今、今いるsplay木の最も葉側にしたいノード」
// y->rch : 「今は同じsplay木だけど、今回スプリットされるsplay木の最も根側のノード」
void expose(node *x) {
	for (node *y = x, *rch = nullptr; y != nullptr; 
            y = y->parent) { // splay(y)しているので、このparentは必ず次のsplay木に移動する
		splay(y);
		y->rch = rch; // y == xの時、右を切っている！
		rch = y;
		update(y);
	}
	splay(x);
}
 
// xを真の根、かつ木の根にする。
// そのために、xと、xの根側の親を切断する
void cut(node *x) {
	expose(x);

    // 強連結を切る。
    // つまり、もともと同じSplay木で管理されていたxの親と切断
	x->lch->parent = nullptr; 
	x->lch = nullptr;

	update(x);
}
 
// pの子側にcをつける。
// pとcの両方に木の根があって、どちらかの根は消さなければいけないが、
// 木の根は、pが属する木の根が採用される（cが属する木の根は消失する）
// 
// cとpは、別の木であることを前提としている
// cもpも、exposeで最も葉側となってくれているので、ただくっつけるだけで問題なく列となってくれる
void link(node *c, node *p) {
	expose(c);
	expose(p);

    // 強連結につなぐ。
    // pが根側でcが葉側になるように、同じSplay木の中で管理する
	c->parent = p;
	p->rch = c;

	update(c);
	update(p);
}
 
// xを木の根とする
// 
// reversedは、左右の子が実は逆だよ、という意味。
// これはpushで遅延評価する。
// たまにx->rch, x->lchが両方NULLの時は、意味がないがそれでもrevする。
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
 
// なんでこれで動くんだろう…
node *lca(node *x, node *y) {
	expose(y);
	expose(x);
    // この時点で、
    // (1) 木の根-xのパスにyが含まれていない場合
    //    LCAはyを根に上げていって、xを含むsplay木に入った直後になるはず。
    // (2) 木の根-xのパスにyが含まれている場合
    //    
 
	bool same = false;
 
	node *l = y;
	while (y != nullptr) {
		if (is_root(y) && y->parent != nullptr) l = y->parent; // splay木の根であれば次のsplay木へ
		if (y == x->rch) return x; // 実はyはxの子だった
		if (x == y) same = true;

		y = y->parent;
	}
	if (!same) return nullptr;
	return l;
}
 
/*

6 
link 1 2
link 2 3
link 3 5
link 4 5
expose 1
splay 2
expose 1
expose 2
evert 2

*/

/*

4 
link 1 2
link 2 3
expose 2
evert 2

*/


// expose, splayは、同じ列を表していることを確認するくらいで良い
int main() {
	int n;
	cin >> n;
 
	for (int i = 0; i < n; i++) {
        tr[i] = new node(i);
        tr_inv[tr[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        cout << tr[i] << endl; 
    }
	while (1) {
        cout << "--------" << endl;
        string c; 
        cin >> c;
 
		if (c == "link") {
			int u, v;
			scanf("%d %d", &u, &v);
 
			link(tr[u], tr[v]);
            vizLCTree(tr, n, "link "+to_string(u)+" "+to_string(v));
		} else if (c == "cut") {
			int u;
			scanf("%d", &u);
 
			cut(tr[u]);
            vizLCTree(tr, n, "cut "+to_string(u));
		} else if (c == "splay") {
			int u;
			scanf("%d", &u);
 
			splay(tr[u]);
            vizLCTree(tr, n, "splay "+to_string(u));
		} else if (c == "expose") {
			int u;
			scanf("%d", &u);
 
			expose(tr[u]);
            vizLCTree(tr, n, "expose "+to_string(u));
		} else if (c == "evert") {
			int u;
			scanf("%d", &u);
 
			evert(tr[u]);
            vizLCTree(tr, n, "evert "+to_string(u));
		} else if (c == "lca") {
			int u, v;
			scanf("%d %d", &u, &v);
 
			node *l = lca(tr[u], tr[v]);
			int ans = l == nullptr ? -2 : l->id;
			printf("%d\n", ans + 1);
            vizLCTree(tr, n, "lca "+to_string(u)+" "+to_string(v));
		} else {
            cout << "INVALID" << endl;
            exit(1);
        }
        for (int i = 0; i < n; i++) 
            cout << tr[i] << endl;  // parent, lch, rch
	}
}
