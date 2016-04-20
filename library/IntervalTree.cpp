typedef int position;
typedef int contents;
struct interval {
    position low, high;
    interval(position low, position high) :
        low(low), high(high) { }
};

struct interval_tree {
    vector<position> pos;
    struct node {
        vector<contents> values;
        position B, E, M;
        node *left, *right;
    } *root;

    template <class IN>
        interval_tree(IN begin, IN end) : pos(begin, end) {
            root = build_tree(0, pos.size()-1);
        }
    ~interval_tree() { release(root); }

    node *build_tree(int i, int j) {
        int m = (i+j)/2;
        node *t = new node;
        t->B = pos[i]; t->E = pos[j]; t->M = pos[m];
        t->left  = (i+1 < j ? build_tree(i, m) : NULL);
        t->right = (i+1 < j ? build_tree(m, j) : NULL);
        return t;
    }
    void insert(const interval& I, contents c) { insert(root, I, c); }
    void insert(node *v, const interval& I, contents c) {
        if (I.low <= v->B && v->E <= I.high) {
            v->values.push_back( c );
        } else {
            if (I.low  < v->M) insert(v->left , I, c);
            if (I.high > v->M) insert(v->right, I, c);
        }
    }
    template <class OUT>
        void query(position p, OUT out) { query(root, p, out); }
    template <class OUT>
        void query(node *t, position p, OUT out) {
            if (!t || p < t->B || p >= t->E) return;
            copy(t->values.begin(), t->values.end(), out);
            if (p < t->M) query(t->left, p, out);   // 半開区間の探索になる
            else          query(t->right, p, out);
        }
    void release(node *t) {
        if (t->left) release(t->left);
        if (t->right) release(t->right);
        delete t;
    }
};
