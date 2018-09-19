// 区間更新、区間最小の遅延セグメントツリー
struct RMQRUQ {
  ll n;
  vector<ll> dat, lazy;
 
  RMQRUQ(){}
  RMQRUQ(ll n_) {
    n = 1; while(n < n_) n *= 2;
    dat.assign(n*2, INF);
    lazy.assign(n*2, INF);
  }
 
  void eval(ll len, ll k) {
    if(lazy[k] == INF) return;
    if(k*2+1 < n*2-1) {
      lazy[2*k+1] = lazy[k];
      lazy[2*k+2] = lazy[k];
    }
    dat[k] = lazy[k];
    lazy[k] = INF;
  }
 
  // [a, b)
  ll update(ll a, ll b, ll x, ll k, ll l, ll r) {
    eval(r-l, k);
    if(b <= l || r <= a) return dat[k];
    if(a <= l && r <= b) {
      lazy[k] = x;
      return lazy[k];
    }
    return dat[k] = min(update(a, b, x, 2*k+1, l, (l+r)/2), update(a, b, x, 2*k+2, (l+r)/2, r));
  }
  ll update(ll a, ll b, ll x) { return update(a, b, x, 0, 0, n); }
 
  // [a, b)
  ll query(ll a, ll b, ll k, ll l, ll r) {
    eval(r-l, k);
    if(b <= l || r <= a) return INF;
    if(a <= l && r <= b) return dat[k];
    ll vl = query(a, b, 2*k+1, l, (l+r)/2);
    ll vr = query(a, b, 2*k+2, (l+r)/2, r);
    return min(vl, vr);
  }
  ll query(ll a, ll b) { return query(a, b, 0, 0, n); }
};


