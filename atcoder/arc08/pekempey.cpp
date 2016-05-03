#include <bits/stdc++.h>
using namespace std;

template<class T>
vector<int> compress(T first, T last) {
    vector<typename iterator_traits<T>::value_type> cv(first, last);
    vector<int> ret(cv.size());
    sort(cv.begin(), cv.end());
    cv.erase(unique(cv.begin(), cv.end()), cv.end());
    for (int i = 0; first != last; first++, i++)
        ret[i] = lower_bound(cv.begin(), cv.end(), *first) - cv.begin();
    return ret;
}

const int N = 1 << 18;
typedef pair<long double, long double> P;
P seg[N * 2];
// cx+d . ax+b -> c(ax+b)+d = (ac)x+(bc+d)

P merge(P a, P b) {
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

int main() {
    for (int i = 0; i < N * 2; i++) {
        seg[i].first = 1;
    }

    long long n, m;
    cin >> n >> m;

    vector<long long> p(m);
    vector<double> a(m);
    vector<double> b(m);

    for (int i = 0; i < m; i++) {
        scanf("%lld %lf %lf", &p[i], &a[i], &b[i]);
    }

    vector<int> cp = compress(p.begin(), p.end());

    long double mn = 1;
    long double mx = 1;
    for (int i = 0; i < m; i++) {
        update(cp[i], a[i], b[i]);
        mn = min(mn, seg[0].first + seg[0].second);
        mx = max(mx, seg[0].first + seg[0].second);
    }

    printf("%.20f\n", (double)mn);
    printf("%.20f\n", (double)mx);
}

