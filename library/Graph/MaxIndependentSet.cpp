    int s[40][40]; // 隣接行列
    long long S[40]; // 隣接行列をbitwiseで詰め込んだもの
    int v[40]; // 頂点の利用状況
    int val; // 最大独立集合の数
    int n; // 頂点数
    long long uk=0; // v[i]=0のiを詰め込んだもの

    // (1) 隣接行列としてsを埋める
    // (2) initを呼んで全部初期化
    // (3) calcを呼ぶ
    // (4) valに最大独立集合の大きさが入っている
    void calc(){
        int nm=0;
        rep(i, n) if(v[i] == 1) nm++;
        val = max(val, nm);

        rep(i, n) {
            if (v[i] == 0 && __builtin_popcountll(uk & S[i]) < 2){
                v[i] = 1;
                uk -= 1ll << i;
                long long ch=0;
                rep(j, n) if (v[j] == 0 && s[i][j]) {
                    v[j] = 2;
                    ch += 1ll << j;
                    uk -= 1ll << j;
                }
                calc();
                v[i] = 0;
                uk += 1ll<<i;
                rep(j, n) if (ch & (1ll << j)) v[j] = 0, uk += 1LL<<j;
                return;
            }
        }
        int dm = 1;
        int at = -1;
        rep(i, n) if(v[i] == 0 && __builtin_popcountll(uk & S[i]) >= dm){
            dm = __builtin_popcountll(uk & S[i]);
            at = i;
        }
        if(at == -1) return;
        v[at] = 2;
        uk -= 1LL<<at;
        calc();
        v[at] = 0;
        uk += 1LL<<at;

        v[at] = 1;
        uk -= 1LL<<at;
        long long ch=0;
        rep(j, n) if(v[j] == 0 && s[at][j]) {
            v[j] = 2;
            uk -= 1ll << j;
            ch += 1ll << j ;
        }
