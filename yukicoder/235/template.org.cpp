#include<bits/stdc++.h>

using namespace std;
#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
typedef long long LL;
typedef vector<int> vll;
typedef vector<vll> vvll;
typedef vector<vll> Graph;

template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template<size_t...> struct seq{}; template<size_t N, size_t... Is> struct gen_seq : gen_seq<N-1, N-1, Is...>{}; template<size_t... Is> struct gen_seq<0, Is...> : seq<Is...>{};
template<class Ch, class Tr, class Tuple, size_t... Is>
void print_tuple(basic_ostream<Ch,Tr>& os, Tuple const& t, seq<Is...>){ using s = int[]; (void)s{0, (void(os << (Is == 0? "" : ", ") << get<Is>(t)), 0)...}; }
template<class Ch, class Tr, class... Args> 
auto operator<<(basic_ostream<Ch, Tr>& os, tuple<Args...> const& t) -> basic_ostream<Ch, Tr>& { os << "("; print_tuple(os, t, gen_seq<sizeof...(Args)>()); return os << ")"; }
ostream &operator<<(ostream &o, const vvll &v) { rep(i, v.size()) { rep(j, v[i].size()) o << v[i][j] << " "; cout << endl; } return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const unordered_map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it; o << "]";  return o; }

struct INIT {INIT() {ios::sync_with_stdio(false);cin.tie(0);}}init;

// heavy light decomposition
// 番号は付け替えられてしまう！
namespace hld {
#define SZ 200010
    int mem[4][SZ]; // [4] = {id, group, parent, bg}
};
class HLD {
    private:
        int *treesize; // 子の数
        Graph *tree;
    public:
        // i: ノードの添字
        // j: Heavy pathの添字
        int size; // Heavy pathの数
        int *group; // tree->size(): ノードiが属するグループj
        int *id; // tree->size(): ノードiに再割り振りされた新ノード番号id in [0, tree->size())
        int *par; // size: Heavy path jの根の親のノードi
        int *bg; //  size: Heavy path jの根のノードi
    private:
        void setTreeSize(int v) {
            treesize[v]=1;
            for (auto &u:(*tree)[v]) {
                setTreeSize(u);
                treesize[v]+=treesize[u];
            }
        }
        void build(int v, int g, int& i) {
            group[v]=g;
            id[v]=i++;
            Graph &gr=(*tree);
            if (!gr[v].size()) return;

            // 最大サイズの子hを求める
            int h=gr[v][0]; 
            for (auto &u:gr[v])
                if(treesize[h]<treesize[u])h=u;

            // Heavy
            build(h, g, i);

            // Light
            for (auto &u:gr[v]) if(h != u) { 
                par[size]=v;
                bg[size]=i;
                build(u, size++, i);
            }
        }
    public:
        HLD(Graph *tree, int root=0) :treesize(hld::mem[0]), tree(tree), size(0), group(hld::mem[1]), id(hld::mem[0]), par(hld::mem[2]), bg(hld::mem[3]) {
            setTreeSize(root);
            int i=0;
            par[size]=-1;
            bg[size]=i;
            build(root, size++, i);
        }
        // O(log n)
        //
        // [r, c]の再割り振りされた添字区間を返す。
        //
        // rがcより根側である必要がある
        // c側から、以下の漸化式によってパスを分解する
        //      ret += {groupの根, c}, c = groupの根の親
        using P=pair<int, int>;
        vector<P> decomposition(int r, int c) {
            vector<P> res;
            while (group[c]!=group[r]) {
                res.push_back(P(bg[group[c]], id[c]));
                c=par[group[c]];
            }
            res.push_back(P(id[r], id[c]));
            return res;
        }
        void print(void) {
            rep(i, tree->size()) {
                cout << group[i] << " " << id[i] << endl;
            }
            cout << "####" << endl;
            rep(i, size) {
                cout << par[i] << " " << bg[i] << endl;
            }
        }

};

void make_tree(int v, Graph& G, vll& Par, vll& D,  Graph& C) {
    for (auto &e:G[v]) {
        if(e!=Par[v]) {
            C[v].push_back(e);
            D[e]=D[v]+1;
            Par[e]=v;
            make_tree(e, G, Par, D, C);
        }
    }
}


//lcaの準備
void build_PP(vll& P, vector<vll>& PP) {
    int N = P.size();
    for (int i = 0; i < N; i++)PP[0][i] = P[i];
    for (int k = 0, f=1;f; k++) {
        f=0;
        for (int i = 0; i < N; i++) {
            if(PP[k][i]<0)PP[k+1][i]=-1;
            else  {PP[k+1][i]=PP[k][PP[k][i]];f=1;}
        }
    }
}
int lca(int u, int v, vll& D, vector<vll> &PP) {
    if(D[u] > D[v])swap(u, v);
    for (int k = 0, d;(d=D[v]-D[u]); k++)if((d  >>  k) & 1)v=PP[k][v];
    if(u==v)return v;
    for (int k = PP.size() - 1; k >=0 ; k--) {
        if(PP[k][u]!=PP[k][v]) {
            u=PP[k][u];
            v=PP[k][v];
        }
    }
    return PP[0][u];
}


#define SIZE 900000
#define L(v) (v*2+1)
#define R(v) (v*2+2)
#define SET 0
#define ADD 1
#define GET 2

typedef LL val;
const LL MOD=1e9+7;
struct node {
    int bg, ed;
    val v, add, sum;
    inline val getval() {
        return (v+sum*add%MOD)%MOD;
    }
    inline void init(int b, int e) {
        bg =b, ed=e;
        v=0, add=0, sum=0;
    }
    bool isleaf() {return bg==ed;}
}mem[SIZE];
inline val comb(val l, val r) {
    return (l+r)%MOD;
}
class segTree {
    private:
        node *t;
        val make_tree(int bg, int ed, vector<int> &c, vector<int> &s, int v=0) {
            node *p=t+v;
            p->init(bg, ed);
            if(!p->isleaf()) {
                int m=(bg+ed)/2;
                p->sum+=make_tree(bg, m, c, s, L(v));
                p->sum+=make_tree(m+1, ed, c, s, R(v));
                p->sum%=MOD;
                update(v);
            } else {
                p->sum=c[bg];
                p->v=s[bg];
            }
            return p->sum;
        }
    public:
        using P=pair<int, int>;
        segTree(int bg, int ed, vector<int> &c, vector<int> &s):t(mem) {
            make_tree(bg, ed, c, s);
        }
        inline void lazy_update(int v) {
            node *p=t+v, *l=t+L(v), *r=t+R(v);
            if(p->isleaf())return;
            (l->add+=p->add)%=MOD;
            (r->add+=p->add)%=MOD;
            p->add=0;
        }
        inline void update(int v) {
            node *p=t+v, *l=t+L(v), *r=t+R(v);
            if(p->isleaf()) {
                p->v+=p->add*p->sum%MOD;
                p->v%=MOD;
                p->add=0;
            }
            else {
                p->v=comb(l->getval(), r->getval());
            }
        }
        val treat(int type, int bg, int ed, val x, int v=0) {
            node *p=t+v, *l=t+L(v), *r=t+R(v);
            lazy_update(v);
            if(P(bg, ed)==P(p->bg, p->ed)) {
                if(type==ADD)(p->add+=x)%=MOD;
                update(v);
                return p->getval();
            }
            int m;
            val res=0;
            if(bg<=(m=min(ed, l->ed)))
                res=comb(res, treat(type, bg, m, x, L(v)));
            if((m=max(bg, r->bg))<=ed)
                res=comb(res, treat(type, m, ed, x, R(v)));
            update(v);
            return res;
        }
        val get(int bg, int ed) {
            return treat(GET, bg, ed, val());
        }
        val add(int bg, int ed, val x) {
            return treat(ADD, bg, ed, x);
        }
};
const int root=0;
int main() {
    int N;cin >> N;
    N++;
    vector<int> s(N), S(N), c(N), C(N);
    s[root]=c[root]=0;
    for (int i=1;i<N;i++) cin >> s[i];
    for (int i=1;i<N;i++) cin >> c[i];
    Graph g(N), tree(N);
    g[root].push_back(1);
    vll par(N, -1), depth(N, 0);
    for (int i=2;i<N;i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    make_tree(root, g, par, depth, tree);

    vector<vll> pp(18, vll(N, -1)); // LCA用ダブリング
    build_PP(par, pp);

    HLD hld(&tree, root);
    cout << endl;
    cout << "########" << endl;
    hld.print();
    cout << "########" << endl;
    for (int i=0;i<N;i++) {
        S[hld.id[i]]=s[i];
        C[hld.id[i]]=c[i];
    }
    segTree st(0, N-1, C, S);
    int Q;
    cin >> Q;
    while (Q--) {
        int t;
        cin >> t;
        if(t) {
            int x, y;
            cin >> x >> y;
            int ca=lca(x, y, depth, pp);
            LL ans=0;
            auto p=hld.decomposition(ca, x);
            auto q=hld.decomposition(ca, y);
            auto r=hld.decomposition(ca, ca);
            for (auto &it:p)(ans+=st.get(it.first, it.second))%=MOD;
            for (auto &it:q)(ans+=st.get(it.first, it.second))%=MOD;
            for (auto &it:r)ans+=MOD-st.get(it.first, it.second);
            cout<<ans%MOD<<endl;
        } else {
            int x, y, z;
            cin >> x >> y >> z;
            int ca=lca(x, y, depth, pp);
            auto p=hld.decomposition(ca, x);
            auto q=hld.decomposition(ca, y);
            auto r=hld.decomposition(ca, ca);
            for (auto &it:p)st.add(it.first, it.second, z);
            for (auto &it:q)st.add(it.first, it.second, z);
            for (auto &it:r)st.add(it.first, it.second, MOD-z);
        }
    }
    return 0;
}
