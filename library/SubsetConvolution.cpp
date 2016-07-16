// 高速ゼータ変換
// O(n 2^n)
//
// fは2^nでなければならない
// fに集合での計算結果を入れてこれを呼び出すと、fが部分集合の計算結果の総和になる。
void FZT(vll& f) {
    rep(i, round(log(f.size())/log(2))) rep(j, f.size()) if(!(j & 1 << i)) f[j] += f[j | 1 << i];
}
// 高速メビウス変換
// O(n 2^n)
//
// fは2^nでなければならない
// fに積集合の計算結果を入れてこれを呼び出すと、fが和集合の計算結果になる。
void FMT(vll& f) {
    rep(i, round(log(f.size())/log(2))) rep(j, f.size()) if(j & 1 << i) f[j] -= f[j ^ 1 << i];
}


