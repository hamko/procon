#include <bits/stdc++.h>
using namespace std;
 
struct EulerTourTree {
    struct node {
        node *lch = nullptr;
        node *rch = nullptr;
        node *parent = nullptr;
        int size = 1;
 
        int vid;
        bool active = false;
        int sub = 0;
 
        node(int vid) : vid(vid) {}
    };
 
    unsigned long long xor_shift() {
        static unsigned long long x = time(NULL);
        x ^= x << 13; x ^= x >> 7; x ^= x << 17;
        return x;
    }
 
    int size(node *x) {
        return x != nullptr ? x->size : 0;
    }
 
    int sub(node *x) {
        return x != nullptr ? x->sub : 0;
    }
 
    node *update(node *x) {
        if (x == nullptr) return x;
        x->size = 1 + size(x->lch) + size(x->rch);
        x->sub = sub(x->lch) + sub(x->rch);
        if (x->active) x->sub++;
        return x;
    }
 
    void update_ancestor(node *x) {
        if (x == nullptr) return;
        x = update(x);
        update_ancestor(x->parent);
    }
 
    void activate(node *x, bool value) {
        if (x == nullptr) return;
        x->active = value;
        update_ancestor(x);
    }
 
    node *merge(node *x, node *y) {
        if (x == nullptr) return y;
        if (y == nullptr) return x;
        if (xor_shift() % (size(x) + size(y)) < size(x)) {
            x->rch = merge(x->rch, y);
            if (x->rch != nullptr) x->rch->parent = x;
            return update(x);
        } else {
            y->lch = merge(x, y->lch);
            if (y->lch != nullptr) y->lch->parent = y;
            return update(y);
        }
    }
 
    pair<node *, node *> split(node *x, int k) {
        if (x == nullptr) return make_pair(nullptr, nullptr);
        if (k <= size(x->lch)) {
            auto p = split(x->lch, k);
            x->lch = p.second;
            if (p.first != nullptr) p.first->parent = nullptr;
            if (p.second != nullptr) p.second->parent = x;
            return make_pair(p.first, update(x));
        } else {
            auto p = split(x->rch, k - size(x->lch) - 1);
            x->rch = p.first;
            if (p.first != nullptr) p.first->parent = x;
            if (p.second != nullptr) p.second->parent = nullptr;
            return make_pair(update(x), p.second);
        }
    }
 
    node *root(node *x) {
        if (x == nullptr) return x;
        if (x->parent == nullptr) return x;
        return root(x->parent);
    }
 
    int index_of(node *x) {
        if (x == nullptr) return 0;
        int result = -1;
        bool l = true;
        while (x != nullptr) {
            if (l) result += 1 + size(x->lch);
            if (x->parent == nullptr) break;
            l = x->parent->rch == x;
            x = x->parent;
        }
        return result;
    }
 
    void connected_component(node *x, vector<int> &res) {
        if (x == nullptr) return;
        if (x->active) res.push_back(x->vid);
        connected_component(x->lch, res);
        connected_component(x->rch, res);
    }
 
    vector<int> connected_component(int u) {
        node *x = root(any_node(u));
        if (x == nullptr) return{ u };
        vector<int> res;
        connected_component(x, res);
        return res;
    }
 
    vector<map<int, node *>> tr;
 
    EulerTourTree(int n) : tr(n) {}
 
    node *any_node(int u) {
        return tr[u].empty() ? nullptr : tr[u].begin()->second;
    }
 
    bool link(int u, int v) {
        node *x = any_node(u);
        node *y = any_node(v);
 
        node *root_x = root(x);
        node *root_y = root(y);
 
        if (root_x != nullptr && root_x == root_y) return false;
 
        node *A, *B, *C, *D;
        tie(A, B) = split(root_x, index_of(x));
        tie(C, D) = split(root_y, index_of(y));
 
        // AB, CD => A (u->v) D C (v->u) B
 
        node *uv = new node(u);
        node *vu = new node(v);
 
        if (tr[u].empty()) activate(uv, true);
        if (tr[v].empty()) activate(vu, true);
 
        tr[u][v] = uv;
        tr[v][u] = vu;
 
        A = merge(A, uv);
        A = merge(A, D);
        A = merge(A, C);
        A = merge(A, vu);
        A = merge(A, B);
 
        return true;
    }
 
    bool cut(int u, int v) {
        if (tr[u].count(v) == 0) return false;
        node *uv = tr[u][v];
        node *vu = tr[v][u];
        tr[u].erase(v);
        tr[v].erase(u);
 
        if (uv->active) {
            activate(uv, false);
            activate(any_node(u), true);
        }
        if (vu->active) {
            activate(vu, false);
            activate(any_node(v), true);
        }
 
        node *rt = root(uv);
 
        int index_uv = index_of(uv);
        int index_vu = index_of(vu);
 
        if (index_uv > index_vu) swap(index_uv, index_vu);
 
        node *A, *DC, *B;
        auto p = split(rt, index_vu);
        B = split(p.second, 1).second;
        auto q = split(p.first, index_uv);
        A = q.first;
        auto r = split(q.second, 1);
        merge(B, A);
 
        return true;
    }
 
    bool is_connected(int u, int v) {
        if (u == v) return true;
        node *x = any_node(u);
        node *y = any_node(v);
        return x != nullptr && root(x) == root(y);
    }
 
    int sub(int u) {
        node *x = any_node(u);
        if (x == nullptr) return 1;
        return sub(root(x));
    }
};
 
struct DynamicConnectivity {
    static const int L = 20;
    vector<EulerTourTree> et;
    vector<vector<set<int>>> g;
    vector<vector<set<int>>> gg;
 
    DynamicConnectivity(int n) :
        et(L, EulerTourTree(n)), 
        g(L, vector<set<int>>(n)),
        gg(L, vector<set<int>>(n)) {}
 
    bool insert(int u, int v) {
        if (!et[0].is_connected(u, v)) {
            assert(et[0].link(u, v));
            gg[0][u].insert(v);
            gg[0][v].insert(u);
            return true;
        } else {
            g[0][u].insert(v);
            g[0][v].insert(u);
            return false;
        }
    }
 
    bool erase(int u, int v) {
        bool is_tree = false;
        int level = -1;
        for (int i = 0; i < L && level == -1; i++) {
            et[i].cut(u, v);
            if (gg[i][u].count(v) == 1) {
                gg[i][u].erase(v);
                gg[i][v].erase(u);
                level = i;
                is_tree = true;
            }
            if (g[i][u].count(v) == 1) {
                g[i][u].erase(v);
                g[i][v].erase(u);
                level = i;
            }
        }
        assert(level != -1);
        if (!is_tree) return false;
        return reconnect(level, u, v);
    }
    
    bool reconnect(int level, int u, int v) {
        if (level == -1) return true;
 
        int size_u = et[level].sub(u);
        int size_v = et[level].sub(v);
 
        if (size_u > size_v) swap(u, v);
 
        vector<int> cc = et[level].connected_component(u);
        for (int x : cc) {
            auto &st = gg[level][x];
            for (auto it = st.begin(); it != st.end();) {
                int y = *it;
 
                st.erase(it++);
                gg[level][y].erase(x);
                gg[level + 1][x].insert(y);
                gg[level + 1][y].insert(x);
                assert(et[level + 1].link(x, y));
            }
        }
 
        for (int x : cc) {
            auto &st = g[level][x];
            for (auto it = st.begin(); it != st.end();) {
                int y = *it;
 
                if (et[level].is_connected(y, v)) {
                    st.erase(it++);
                    g[level][y].erase(x);
                    gg[level][x].insert(y);
                    gg[level][y].insert(x);
                    for (int i = 0; i <= level; i++) {
                        assert(et[i].link(x, y));
                    }
                    return false;
                } else {
                    st.erase(it++);
                    g[level][y].erase(x);
                    g[level + 1][x].insert(y);
                    g[level + 1][y].insert(x);
                }
            }
        }
 
        return reconnect(level - 1, u, v);
    }
 
    bool is_connected(int u, int v) {
        return et[0].is_connected(u, v);
    }
 
    int size_connected_component(int u) {
        return et[0].sub(u);
    }
};

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mt make_tuple
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

using ll = long long; using ld = long double; using vll = vector<ll>; using vvll = vector<vll>; using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>;
vll conv(vi& v) { vll r(v.size()); rep(i, v.size()) r[i] = v[i]; return r; }
using P = pair<ll, ll>;


int main() {
    ll n, m, s; scanf("%Ld %Ld %Ld", &n, &m, &s); s--;

    static DynamicConnectivity dc(n);
    static vector<vector<P>> edges(n);
    static set<P> unique;
    rep(i, m) {
        ll u, v;
        scanf("%Ld %Ld", &u, &v); u--, v--;

        if (unique.count(P(u, v)) || unique.count(P(v, u))) 
            continue;
        edges[min(u, v)].pb(P(u, v));
        dc.insert(u, v);
        unique.insert(P(u, v));
    }
 
    vll ret;
    rep(i, n) {
        if (dc.is_connected(s, i))
            ret.pb(i);
        rep(j, edges[i].size()) {
            dc.erase(edges[i][j].fi, edges[i][j].se);
        }
    }
    
    rep(i, ret.size()) {
        printf("%Ld\n", ret[i] + 1);
    }
}

