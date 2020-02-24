struct SlideMin {
    ll dl = 0, dr = 0;
    deque<P> d;

    ll query(ll l, ll r) {
        assert(dl <= l);
        assert(dr <= r);
        while (dr < r) {
            while (d.size() && d.back().fi <= a[dr]) {
                d.pop_back();
            }
            d.push_back(P(a[dr], dr));
            dr++;
        }
        while (dl < l) {
            if (d.size() && d.front().se <= dl) {
                d.pop_front();
            }
            dl++;
        }
        return d.size() ? d[0].fi : -INF;
    }
};
