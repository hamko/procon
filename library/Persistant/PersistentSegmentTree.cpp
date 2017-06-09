#include <bits/stdc++.h>
using namespace std;
 
const int N = 1 << 17;
const int D = 17;
int n;
int v[N];
 
//*****************************************************************
//    persistent segment tree (range-sum)
//*****************************************************************
struct node {
	node *lch = nullptr;
	node *rch = nullptr;
	int sum;
	node() {}
	node(int sum) : sum(sum) {}
};
node *seg[D + 1][N];
 
int sum(node *x) { return x == nullptr ? 0 : x->sum; }
 
node *update_seg(int a, int v, node *x, int l = 0, int r = N) {
	x = x == nullptr ? new node() : new node(*x);
	if (r - l == 1) {
		x->sum = v;
		return x;
	}
	if (a < (l + r) / 2) {
		x->lch = update_seg(a, v, x->lch, l, (l + r) / 2);
	} else {
		x->rch = update_seg(a, v, x->rch, (l + r) / 2, r);
	}
	x->sum = sum(x->lch) + sum(x->rch);
	return x;
}
 
int query_seg(int a, int b, node *x, int l = 0, int r = N) {
	if (a >= b) return 0;
	if (x == nullptr) return 0;
	if (r <= a || b <= l) return 0;
	if (a <= l && r <= b) return sum(x);
	return query_seg(a, b, x->lch, l, (l + r) / 2) + query_seg(a, b, x->rch, (l + r) / 2, r);
}
 
//*****************************************************************
//    wavelet matrix
//*****************************************************************
int w[D + 1][N];
int wsum[D + 1][N];
 
int wsum1(int d, int l, int r) { return l >= r ? 0 : wsum[d][r] - wsum[d][l]; }
int wsum0(int d, int l, int r) { return l >= r ? 0 : (r - l) - wsum1(d, l, r); }
 
void rec_wavelet_matrix(int d, int l, int r) {
	if (d == -1) return;
	vector<int> L, R;
	for (int i = l; i < r; i++) {
		w[d][i] = v[i] >> d & 1;
		(w[d][i] == 0 ? L : R).push_back(v[i]);
	}
	for (int i = 0; i < L.size(); i++) v[l + i] = L[i];
	for (int i = 0; i < R.size(); i++) v[l + L.size() + i] = R[i];
	rec_wavelet_matrix(d - 1, l, l + L.size());
	rec_wavelet_matrix(d - 1, l + L.size(), r);
}
 
void build_wavelet_matrix() {
	rec_wavelet_matrix(D, 0, n);
	for (int i = 0; i <= D; i++) {
		for (int j = 0; j < n; j++) {
			wsum[i][j + 1] = wsum[i][j] + w[i][j];
		}
	}
}
 
// [a,b]
int quantile(int a, int b, int k, int t, int d = D, int l = 0, int r = -100) {
	if (r == -100) r = n - 1;
	if (d == -1) return 0 <= a && a < n ? v[a] : -1;
	int n0 = wsum0(d, l, r + 1);
	int cnt = query_seg(a, b + 1, seg[d][t]);
	if (k < cnt) {
		int na = wsum0(d, l, a);
		int nb = wsum0(d, l, b) - (w[d][b] == 1);
		return quantile(l + na, l + nb, k, t, d - 1, l, l + n0 - 1);
	} else {
		int na = wsum1(d, l, a);
		int nb = wsum1(d, l, b) - (w[d][b] == 0);
		return quantile(l + n0 + na, l + n0 + nb, k - cnt, t, d - 1, l + n0, r);
	}
}
 
void set_value(int a, int t, int x, int d = D, int l = 0, int r = -100) {
	if (r == -100) r = n - 1;
	if (d == -1) return;
	int n0 = wsum0(d, l, r + 1);
	if (w[d][a] == 0) {
		seg[d][t] = update_seg(a, x, seg[d][t]);
		int na = wsum0(d, l, a);
		set_value(l + na, t, x, d - 1, l, l + n0 - 1);
	} else {
		int na = wsum1(d, l, a);
		set_value(l + n0 + na, t, x, d - 1, l + n0, r);
	}
}
 
void clone(int t) {
	if (t == 0) return;
	for (int i = 0; i <= D; i++) {
		seg[i][t] = seg[i][t - 1];
	}
}
 
//*****************************************************************
//    main
//*****************************************************************
int main() {
	int q;
	cin >> n >> q;
 
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);
 
	vector<int> cp(v, v + n);
	sort(cp.begin(), cp.end());
	cp.erase(unique(cp.begin(), cp.end()), cp.end());
 
	for (int i = 0; i < n; i++)
		v[i] = lower_bound(cp.begin(), cp.end(), v[i]) - cp.begin();
	vector<int> vv(v, v + n);
 
	build_wavelet_matrix();
 
	vector<int> pos(100100, -1);
	for (int i = 0; i < n; i++) {
		clone(i);
		if (pos[vv[i]] != -1) {
			set_value(pos[vv[i]], i, 0);
		}
		pos[vv[i]] = i;
		set_value(i, i, 1);
	}
 
	long long ans = 0;
 
	for (int ii = 0; ii < q; ii++) {
		long long A, B, C, D, K;
		scanf("%lld %lld %lld %lld %lld", &A, &B, &C, &D, &K);
 
		int l = (A * max(0ll, ans) + B) % n;
		int r = (C * max(0ll, ans) + D) % n;
 
		int tmp = quantile(l, r, K - 1, r);
		if (tmp != -1) tmp = cp[tmp];
		ans = tmp;
		printf("%lld\n", ans);
	}
} 
