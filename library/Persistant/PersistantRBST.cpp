#include <bits/stdc++.h>
using namespace std;

// pekempeyさん実装
// 使い方すらよくわからない

// ***************************************************************
// persistent RBST
// ***************************************************************
struct rbst {
	int size = 1;
	int key;
	rbst *lch = nullptr;
	rbst *rch = nullptr;
	rbst(int key) : key(key) {}
};
void print(rbst *x) {
	if (x == nullptr) return;
	print(x->lch);
	cout << x->key << " ";
	print(x->rch);
}
unsigned xor32() {
	static unsigned z = time(NULL);
	z ^= z << 13; z ^= z >> 17; z ^= z << 5;
	return z;
}
int size(rbst *x) {
	return x == nullptr ? 0 : x->size;
}
rbst *push(rbst *x) {
	x = new rbst(*x);
	x->size = 1 + size(x->lch) + size(x->rch);
	return x;
}
rbst *merge(rbst *x, rbst *y) {
	if (x == nullptr) return y;
	if (y == nullptr) return x;
	if (xor32() % (size(x) + size(y)) < size(x)) {
		x = push(x);
		x->rch = merge(x->rch, y);
		return push(x);
	} else {
		y = push(y);
		y->lch = merge(x, y->lch);
		return push(y);
	}
}
pair<rbst *, rbst *> split(rbst *x, int k) {
	if (!x) return{ nullptr, nullptr };
	x = push(x);
	if (k <= size(x->lch)) {
		auto tmp = split(x->lch, k);
		x->lch = tmp.second;
		return make_pair(tmp.first, push(x));
	} else {
		auto tmp = split(x->rch, k - size(x->lch) - 1);
		x->rch = tmp.first;
		return make_pair(push(x), tmp.second);
	}
}
int lower_bound(rbst *x, int key) {
	if (!x) return 0;
	if (key <= x->key) return lower_bound(x->lch, key);
	return lower_bound(x->rch, key) + size(x->lch) + 1;
}
bool contains(rbst *x, int key) {
	if (!x) return false;
	if (key == x->key) return true;
	if (key < x->key) return contains(x->lch, key);
	return contains(x->rch, key);
}
rbst *insert(rbst *x, int key) {
	int lb = lower_bound(x, key);
	auto p = split(x, lb);

	if (contains(x, key)) {
		x = merge(p.first, p.second);
	} else {
		rbst *n = new rbst(key);
		x = merge(merge(p.first, n), p.second);
	}
	return x;
}
rbst *inorder(rbst *x, rbst *y) {
	if (x == nullptr) return y;
	y = inorder(x->lch, y);
	y = insert(y, x->key);
	y = inorder(x->rch, y);
	return y;
}

int main(void) {
    rbst* tree0 = new rbst(0); // 根
    rbst* tree1 = new rbst(1); // 根
    print(tree0); cout << endl;
    rbst* result = merge(tree0, tree1);
    print(result); cout << endl;
    return 0;
}
