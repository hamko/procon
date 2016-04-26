// Point assign
const int N = 1 << 18; // 大きくとってごまかす

typedef pair<long double, long double> P;
P seg[N * 2]; // 0が総和。実際にはN*2-1は使っていない。

P merge(P a, P b) { // associative op
    return{ a.first * b.first, a.second * b.first + b.second };
}

void update(int k, long double a, long double b) {
    k += N - 1;
    seg[k] = { a, b };
    while (k > 0) {
        k = (k - 1) / 2;
        seg[k] = merge(seg[k * 2 + 1], seg[k * 2 + 2]);
    }
}


/*
   seg[0].first + seg[0].second
   vector<int> cp = compress(p.begin(), p.end());
   */

