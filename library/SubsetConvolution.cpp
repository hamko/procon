void FZT(vll& f) {
    rep(i, round(log(f.size())/log(2))) rep(j, f.size()) if(!(j & 1 << i)) f[j] += f[j | 1 << i];
}
void FMT(vll& f) {
    rep(i, round(log(f.size())/log(2))) rep(j, f.size()) if(j & 1 << i) f[j] -= f[j ^ 1 << i];
}


