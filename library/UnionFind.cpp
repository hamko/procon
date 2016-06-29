struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) { }
    // x, yをマージ
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    // x, yが同じ集合なら1
    bool find(int x, int y) {
        return root(x) == root(y);
    }
    // xの根を探す。同じ集合なら同じ根が帰る
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    // xが含まれる集合の大きさを返す
    int size(int x) {
        return -data[root(x)];
    }
    // 分離されている集合の数を返す
    int setNum(void) {
        map<int, int> c;
        rep(i, data.size()) {
            c[root(i)]++;
        }
        return c.size();
    }
    // O(n)
    // 集合ごとに全部の要素を出力
    vector<vector<int>> getUnionList(void) {
        map<int, vector<int>> c;
        for (int i = 0; i < data.size(); i++) 
            c[root(i)].pb(i);
        vector<vector<int>> v;
        for (auto x : c) 
            v.push_back(x.second);
        return v;
    }
    void print(void) {
        auto c = getUnionList();
        for (auto x : c) {
            for (auto y : x) 
                cout << y << " ";
            cout << endl;
        }
    }
};

