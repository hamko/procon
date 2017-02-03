struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) { }
    // x, yをマージ, O(A^-1)
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    // x, yが同じ集合なら1, O(A^-1)
    bool find(int x, int y) {
        return root(x) == root(y);
    }
    // xの根を探す。同じ集合なら同じ根が帰る, O(A^-1)
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    // xが含まれる集合の大きさを返す, O(A^-1)
    int size(int x) {
        return -data[root(x)];
    }
    // 分離されている集合の数を返す, O(n)
    int getSetNum(void) {
        unordered_map<int, int> c;
        rep(i, data.size()) {
            c[root(i)]++;
        }
        return c.size();
    }
    // 頂点vと連結な集合を返す, O(n)
    vector<int> getContainingSet(int v) {
        vector<int> ret;
        for (int i = 0; i < data.size(); i++) 
            if (root(i) == root(v))
                ret.push_back(i);
        return ret;
    }

    // 集合ごとに全部の要素を出力, O(n)
    vector<vector<int>> getUnionList(void) {
        map<int, vector<int>> c;
        for (int i = 0; i < data.size(); i++) 
            c[root(i)].pb(i);
        vector<vector<int>> v;
        for (auto x : c) 
            v.push_back(x.second);
        return v;
    }
};
ostream &operator<<(ostream &o, struct UnionFind v) {  v.getUnionList(); int i = 0; for (auto x : v.getUnionList()) { o << i << "\t"; for (auto y : x) o << y << " "; o << endl; i++;} return o; }


