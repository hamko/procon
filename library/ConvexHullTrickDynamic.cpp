#include <bits/stdc++.h>
using namespace std;

const long long NIL = 1e18;

// Overmars & van Leeuwen, 1981 
// https://cw.fel.cvut.cz/wiki/_media/misc/projects/oppa_oi_english/courses/ae4m39vg/presentations/ko-overmars-fuksa.pdf
//
// これら、どういう意味？
//  Query: O(log n)
//  Update: O(log^2 n)
//  Build: O(n loglog n)
//  Space: O(n)
//
namespace {
    struct P {
        long long x, y;
        P() : x(0), y(0) {}
        P(long long x, long long y) : x(x), y(y) {}

        P operator-() const {
            return P(-x, -y);
        }

        bool operator==(const P &r) const {
            return x == r.x && y == r.y;
        }

        bool operator!=(const P &r) const {
            return !(*this == r);
        }

        bool operator<(const P &r) const {
            if (x != r.x) return x < r.x;
            return y < r.y;
        }

        P operator-(const P &r) const {
            return P(x - r.x, y - r.y);
        }
    };

    const P NIL_P(NIL, NIL);

    P subtract(const P &a, const P &b) {
        return P(a.x - b.x, a.y - b.y);
    }

    long long dot(const P &a, const P &b) {
        return a.x * b.x + a.y * b.y;
    }

    long long cross(const P &a, const P &b) {
        return a.x * b.y - a.y * b.x;
    }

    int ccw(P a, P b, P c) {
        b = b - a;
        c = c - a;
        if (cross(b, c) > 0) return 1;
        if (cross(b, c) < 0) return -1;
        return 0;
    }

    bool is_convex(vector<P> &ps) {
        for (int i = 0; i < ps.size(); i++) {
            int j = (i + 1) % ps.size();
            int k = (i + 2) % ps.size();
            if (cross(ps[j] - ps[i], ps[k] - ps[i]) > 0) return false;
        }
        return true;
    }
}

namespace {
    enum { RED, BLACK };

    struct node {
        node *lch, *rch;
        int color, height;
        int size, id;

        long long area = 0;

        P lp, rp;
        P next_lp, prev_rp;
    };

    const int N = 6e5;
    node nodes[N * 2];
    int free_stack[N * 2];
    int sp = 0;

    void init_tree(int n) {
        sp = 0;
        for (int i = n * 2 - 1; i >= 0; i--) {
            free_stack[i] = i;
        }
        sp = n * 2;
    }

    int size(node *x) {
        if (x == nullptr) return 0;
        return x->size;
    }

    bool is_leaf(node *x) {
        return x->lch == nullptr;
    }

    long long area(node *x) {
        if (x == nullptr) return 0;
        return x->area;
    }

    node *update(node *x) {
        if (x == nullptr) return x;
        if (is_leaf(x)) return x;

        x->size = x->lch->size + x->rch->size;
        x->height = max(x->lch->height + (x->lch->color == BLACK), x->rch->height + (x->rch->color == BLACK));

        x->lp = x->lch->lp;
        x->rp = x->rch->rp;

        x->area = x->lch->area + x->rch->area + cross(x->lch->rp, x->rch->lp);

        if (is_leaf(x->lch)) {
            x->next_lp = x->rch->lp;
        } else {
            x->next_lp = x->lch->next_lp;
        }
        if (is_leaf(x->rch)) {
            x->prev_rp = x->lch->rp;
        } else {
            x->prev_rp = x->rch->prev_rp;
        }

        return x;
    }

    node *create() {
        int id = free_stack[--sp];
        node *x = &nodes[id];
        x->id = id;
        return x;
    }

    node *create(node *lch, node *rch) {
        node *x = create();
        x->color = RED;
        x->lch = lch;
        x->rch = rch;
        return update(x);
    }

    node *create(P p) {
        node *x = create();
        x->color = BLACK;
        x->lch = x->rch = nullptr;
        x->lp = x->rp = x->prev_rp = x->next_lp = p;
        x->height = 0;
        x->size = 1;
        return x;
    }

    node *rotL(node *x) {
        node *y = x->rch;
        x->rch = y->lch;
        y->lch = update(x);
        return update(y);
    }

    node *rotR(node *x) {
        node *y = x->lch;
        x->lch = y->rch;
        y->rch = update(x);
        return update(y);
    }

    node *merge_sub(node *u, node *v) {
        if (u->height == v->height) {
            return create(u, v);
        } else if (u->height < v->height) {
            v->lch = merge_sub(u, v->lch);
            if (v->lch->color == RED && v->lch->lch->color == RED && v->color == BLACK) {
                if (v->rch->color == BLACK) {
                    v->color = RED;
                    v->rch->color = BLACK;
                    return rotR(v);
                } else {
                    v->color = RED;
                    v->lch->color = BLACK;
                    v->rch->color = BLACK;
                }
            }
            return update(v);
        } else {
            u->rch = merge_sub(u->rch, v);
            if (u->rch->color == RED && u->rch->rch->color == RED && u->color == BLACK) {
                if (u->lch->color == BLACK) {
                    u->color = RED;
                    u->rch->color = BLACK;
                    return rotL(u);
                } else {
                    u->color = RED;
                    u->lch->color = BLACK;
                    u->rch->color = BLACK;
                }
            }
            return update(u);
        }
    }

    node *merge(node *u, node *v) {
        if (u == nullptr) return v;
        if (v == nullptr) return u;
        node *w = merge_sub(u, v);
        if (w->color == RED) w->color = BLACK;
        return w;
    }

    pair<node *, node *> split(node *v, int k) {
        if (k == 0) return make_pair(nullptr, v);
        if (k == v->size) return make_pair(v, nullptr);

        free_stack[sp++] = v->id;
        if (k < v->lch->size) {
            auto p = split(v->lch, k);
            return make_pair(p.first, merge(p.second, v->rch));
        } else if (k > v->lch->size) {
            auto p = split(v->rch, k - v->lch->size);
            return make_pair(merge(v->lch, p.first), p.second);
        } else {
            return make_pair(v->lch, v->rch);
        }
    }

    int index_of(node *x, P p) {
        if (is_leaf(x)) return 0;
        if (p < x->rch->lp) {
            return index_of(x->lch, p);
        } else {
            return x->lch->size + index_of(x->rch, p);
        }
    }

    bool containsR(P p, P t, P d1, P d2) {
        p = subtract(p, t);
        return cross(d1, p) < 0 && cross(p, d2) <= 0;
    }

    bool containsL(P p, P t, P d1, P d2) {
        p = subtract(p, t);
        return cross(d1, p) > 0 && cross(p, d2) >= 0;
    }

    bool checkL(const P &p, node *x) {
        return containsR(p, x->lp, subtract(x->next_lp, x->lp), subtract(x->rp, x->lp)) || containsR(p, x->rp, subtract(x->rp, x->lp), subtract(x->rp, x->prev_rp));
    }

    bool checkR(const P &p, node *x) {
        return containsL(p, x->lp, subtract(x->lp, x->rp), subtract(x->lp, x->next_lp)) || containsL(p, x->rp, subtract(x->prev_rp, x->rp), subtract(x->lp, x->rp));
    }

    void inorder(node *x, vector<P> &res) {
        if (x == nullptr) return;
        inorder(x->lch, res);
        if (is_leaf(x)) res.push_back(x->lp);
        inorder(x->rch, res);
    }

    bool is_convex(node *x) {
        vector<P> pts;
        inorder(x, pts);
        return is_convex(pts);
    }

    pair<int, P> tangentL(P p, node *x) {
        int pos = 0;
        while (!is_leaf(x)) {
            node *l = x->lch;
            node *r = x->rch;

            bool left = false;
            if (!is_leaf(l) && checkL(p, l)) {
                left = true;
            } else if (!is_leaf(r) && checkL(p, r)) {
                left = false;
            } else {
                if (is_leaf(l)) {
                    if (containsR(p, l->lp, subtract(l->lp, r->rp), subtract(r->lp, l->lp))) left = true;
                } else {
                    if (containsR(p, l->rp, subtract(l->rp, l->prev_rp), subtract(r->lp, l->rp)) ||
                            containsR(p, l->lp, subtract(l->lp, r->rp), subtract(l->next_lp, l->lp))) left = true;
                }
            }

            if (left) {
                x = x->lch;
            } else {
                pos += x->lch->size;
                x = x->rch;
            }
        }
        return make_pair(pos, x->lp);
    }

    pair<int, P> tangentR(P p, node *x) {
        int pos = 0;
        while (!is_leaf(x)) {
            node *l = x->lch;
            node *r = x->rch;

            bool left = false;
            if (!is_leaf(l) && checkR(p, l)) {
                left = true;
            } else if (!is_leaf(r) && checkR(p, r)) {
                left = false;
            } else {
                if (is_leaf(l)) {
                    if (containsL(p, l->lp, subtract(l->lp, r->lp), subtract(r->rp, l->lp))) left = true;
                } else {
                    if (containsL(p, l->rp, subtract(l->rp, r->lp), subtract(l->prev_rp, l->rp)) ||
                            containsL(p, l->lp, subtract(l->lp, l->next_lp), subtract(r->rp, l->lp))) left = true;
                }
            }

            if (left) {
                x = x->lch;
            } else {
                pos += x->lch->size;
                x = x->rch;
            }
        }
        return make_pair(pos, x->lp);
    }

    pair<pair<int, P>, pair<int, P>> common_tangent(node *l, node *r) {
        pair<pair<int, P>, pair<int, P>> p;
        p.first = make_pair(-1, l->rp);
        p.second = make_pair(-1, r->lp);

        for (int i = 0; i < 100; i++) {
            auto prev = p;
            p.second = tangentR(p.first.second, r);
            p.first = tangentL(p.second.second, l);
            if (prev.first.second == p.first.second && prev.second.second == p.second.second) return p;
        }

        assert(is_convex(l));
        assert(is_convex(r));

        return make_pair(make_pair(0, l->lp), make_pair(0, r->lp));
    }

    long long maximum(node *x, long long q) {
        if (is_leaf(x)) return x->lp.x * q + x->lp.y;

        node *l = x->lch;
        node *r = x->rch;

        if (l->rp.x * q + l->rp.y > r->lp.x * q + r->lp.y) {
            return maximum(l, q);
        } else {
            return maximum(r, q);
        }
    }

    long long minimum(node *x, long long q) {
        if (is_leaf(x)) return x->lp.x * q + x->lp.y;

        node *l = x->lch;
        node *r = x->rch;

        if (l->rp.x * q + l->rp.y < r->lp.x * q + r->lp.y) {
            return minimum(l, q);
        } else {
            return minimum(r, q);
        }
    }
}

struct SegmentTree {
    int N;

    vector<P> pts;
    vector<node *> hull;
    vector<node *> leaf;
    vector<int> pos;
    vector<pair<P, P>> tangent;

    SegmentTree(vector<P> pts) {
        int n = pts.size();
        N = 1;
        while (N < n) N *= 2;
        hull.resize(N * 2, nullptr);
        pos.resize(N * 2, -1);
        tangent.resize(N * 2, make_pair(NIL_P, NIL_P));

        leaf.resize(n);
        for (int i = 0; i < n; i++) {
            leaf[i] = create(pts[i]);
        }
    }

    enum { DELETE = 0, ADD = 1 };
    void update(int a, int type, int k = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (r - l == 1) {
            if (type == DELETE) {
                hull[k] = nullptr;
            } else {
                hull[k] = leaf[l];
            }
            return;
        }

        if (hull[k] == nullptr) {
            if (a < (l + r) / 2) {
                update(a, type, k * 2 + 1, l, (l + r) / 2);
            } else {
                update(a, type, k * 2 + 2, (l + r) / 2, r);
            }
        } else {
            node *L, *R;
            tie(L, R) = split(hull[k], pos[k]);

            if (a < (l + r) / 2) {
                hull[k * 2 + 1] = merge(L, hull[k * 2 + 1]);
                update(a, type, k * 2 + 1, l, (l + r) / 2);
                if (tangent[k].first.x != NIL) {
                    if (leaf[a]->lp != tangent[k].first) {
                        if (ccw(tangent[k].second, tangent[k].first, leaf[a]->lp) >= 0) {
                            pos[k] = index_of(hull[k * 2 + 1], tangent[k].first) + 1;
                            auto pp = split(hull[k * 2 + 1], pos[k]);
                            hull[k * 2 + 1] = pp.second;
                            pos[k] = size(pp.first);
                            hull[k] = merge(pp.first, R);
                            return;
                        }
                    }
                }
                hull[k * 2 + 2] = merge(hull[k * 2 + 2], R);
            } else {
                hull[k * 2 + 2] = merge(hull[k * 2 + 2], R);
                update(a, type, k * 2 + 2, (l + r) / 2, r);
                if (tangent[k].first.x != NIL) {
                    if (leaf[a]->lp != tangent[k].second) {
                        if (ccw(tangent[k].first, tangent[k].second, leaf[a]->lp) <= 0) {
                            int id = index_of(hull[k * 2 + 2], tangent[k].second);
                            auto pp = split(hull[k * 2 + 2], id);
                            hull[k * 2 + 2] = pp.first;
                            pos[k] = size(L);
                            hull[k] = merge(L, pp.second);
                            return;
                        }
                    }
                }
                hull[k * 2 + 1] = merge(L, hull[k * 2 + 1]);
            }
        }

        if (hull[k * 2 + 1] == nullptr) {
            pos[k] = size(hull[k * 2 + 1]);
            hull[k] = hull[k * 2 + 2];
            hull[k * 2 + 2] = nullptr;
            tangent[k] = make_pair(NIL_P, NIL_P);
        } else if (hull[k * 2 + 2] == nullptr) {
            pos[k] = size(hull[k * 2 + 1]);
            hull[k] = hull[k * 2 + 1];
            hull[k * 2 + 1] = nullptr;
            tangent[k] = make_pair(NIL_P, NIL_P);
        } else {
            auto p = common_tangent(hull[k * 2 + 1], hull[k * 2 + 2]);
            tangent[k] = make_pair(p.first.second, p.second.second);
            auto ll = split(hull[k * 2 + 1], p.first.first + 1);
            auto rr = split(hull[k * 2 + 2], p.second.first);
            hull[k * 2 + 1] = ll.second;
            hull[k * 2 + 2] = rr.first;
            pos[k] = size(ll.first);
            hull[k] = merge(ll.first, rr.second);
        }
    }
};

int main() {
    int n;
    cin >> n;

    init_tree(n * 2);

    vector<int> t(n), x(n), y(n);
    vector<pair<P, int>> psi;
    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
        if (t[i] == 1) {
            scanf("%d %d", &x[i], &y[i]);
            psi.emplace_back(P(x[i], y[i]), i);
            x[i] = i;
        } else if (t[i] == 2) {
            scanf("%d", &x[i]);
            x[i]--;
        } else {
            scanf("%d", &x[i]);
        }
    }

    sort(psi.begin(), psi.end());
    vector<int> inv(n);
    for (int i = 0; i < psi.size(); i++) {
        inv[psi[i].second] = i;
    }

    vector<P> ps(psi.size());
    for (int i = 0; i < psi.size(); i++) {
        ps[i] = psi[i].first;
    }
    SegmentTree upper(ps);

    for (int i = 0; i < n; i++) {
        if (t[i] == 1) {
            upper.update(inv[x[i]], 1);
        } else if (t[i] == 2) {
            upper.update(inv[x[i]], 0);
        } else {
            if (size(upper.hull[0]) == 0) {
                puts("EMPTY SET");
            } else {
                long long ans = maximum(upper.hull[0], x[i]);
                printf("%lld\n", ans);
            }
        }
    }

