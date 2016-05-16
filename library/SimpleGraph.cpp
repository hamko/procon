vector<vector<ll>> g(N);
rep(i, A.size()) { g[A[i]].pb(B[i]); g[B[i]].pb(A[i]); }

bool ret = 0;
rep(i, N) { // start from i
    vll r;
    function<bool(ll)> f = [&](ll curr) {
        r.pb(curr);
        if (r.size() >= 5) 
            return true;
        bool ret = 0;
        rep(j, g[curr].size()) 
            if (find(all(r), g[curr][j]) == r.end())
                ret |= f(g[curr][j]);
        r.pop_back();
        return ret;
    };
    ret |= f(i);
}
return (ret ? "Yay!" : ":(");

