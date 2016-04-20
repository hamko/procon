// +は加群=結合・可換・可逆
template <class T>
struct fenwick_tree {
    vector<T> x;
    fenwick_tree(int n) : x(n, 0) { }
    // O(log n)
    T sum(int i, int j) {
        if (i == 0) {
            T S = 0;
            for (j; j >= 0; j = (j & (j + 1)) - 1) S += x[j];
            return S;
        } else return sum(0, j) - sum(0, i-1);
    }
    // O(log n)
    void add(int k, T a) {
        for (; k < x.size(); k |= k+1) x[k] += a;
    }
};
