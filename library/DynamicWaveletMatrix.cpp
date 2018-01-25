#include <iostream>
#include <algorithm>
#include <array>
#include <cstdint>
#include <climits>
#include <functional>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <utility>
#include <vector>

using int32 = std::int_fast32_t;
using int64 = std::int_fast64_t;
using uint32 = std::uint_fast32_t;
using uint64 = std::uint_fast64_t;

template<typename T>
class dynamic_wavelet_matrix {
	class dynamic_FID {
		struct node_t {
			uint32 size, sum, ch[2];
			bool color, bit;
		};
		std::vector<node_t> tree;
		uint32 root;
		bool data, balance;
		inline uint32 recalc(uint32 &node) {
			tree[node].size = tree[tree[node].ch[0]].size + tree[tree[node].ch[1]].size + 1;
			tree[node].sum = tree[tree[node].ch[0]].sum + tree[tree[node].ch[1]].sum + tree[node].bit;
			return node;
		}
		uint32 rotate(uint32 node, uint32 dir) {
			uint32 t = tree[node].ch[dir ^ 1];
			tree[t].color = tree[node].color;
			tree[node].ch[dir ^ 1] = tree[t].ch[dir];
			tree[node].color = 0;
			tree[t].ch[dir] = recalc(node);
			return recalc(t);
		}
		uint32 subins(uint32 node, uint32 pos) {
			if (!node) {
				balance = 1;
				return tree.size() - 1;
			}
			++tree[node].size;
			tree[node].sum += data;
			if (tree[tree[node].ch[0]].size < pos) {
				tree[node].ch[1] = subins(tree[node].ch[1], pos - tree[tree[node].ch[0]].size - 1);
				if (balance) return insadj(node, 1);
			}
			else {
				tree[node].ch[0] = subins(tree[node].ch[0], pos);
				if (balance) return insadj(node, 0);
			}
			return node;
		}
		uint32 insadj(uint32 node, bool dir) {
			if (!tree[node].color) return node;
			if (tree[tree[tree[node].ch[dir]].ch[0]].color&&tree[tree[tree[node].ch[dir]].ch[1]].color) {
				balance = 0;
				return node;
			}
			if (!tree[tree[node].ch[dir ^ 1]].color) {
				tree[tree[node].ch[0]].color = 1;
				tree[tree[node].ch[1]].color = 1;
				tree[node].color = 0;
				return node;
			}
			balance = 0;
			if (!tree[tree[tree[node].ch[dir]].ch[dir ^ 1]].color) tree[node].ch[dir] = rotate(tree[node].ch[dir], dir);
			return rotate(node, dir ^ 1);
		}
		uint32 subera(uint32 node, uint32 pos) {
			--tree[node].size;
			if (tree[tree[node].ch[0]].size < pos) {
				tree[node].ch[1] = subera(tree[node].ch[1], pos - tree[tree[node].ch[0]].size - 1);
				tree[node].sum -= data;
				if (balance) return eraadj(node, 1);
				return node;
			}
			if (tree[tree[node].ch[0]].size > pos) {
				tree[node].ch[0] = subera(tree[node].ch[0], pos);
				tree[node].sum -= data;
				if (balance) return eraadj(node, 0);
				return node;
			}
			data = tree[node].bit;
			if (tree[node].ch[0]) {
				if (tree[node].ch[1]) {
					tree[node].ch[1] = subera(tree[node].ch[1], 0);
					std::swap(data, tree[node].bit);
					tree[node].sum -= data;
					if (balance) return eraadj(node, 1);
					return node;
				}
				tree[tree[node].ch[0]].color = 1;
				balance = 0;
				return tree[node].ch[0];
			}
			if (tree[node].ch[1]) {
				tree[tree[node].ch[1]].color = 1;
				balance = 0;
				return tree[node].ch[1];
			}
			balance = tree[node].color;
			return 0;
		}
		uint32 eraadj(uint32 node, bool dir) {
			if (tree[tree[tree[node].ch[dir ^ 1]].ch[0]].color&&tree[tree[tree[node].ch[dir ^ 1]].ch[1]].color) {
				if (tree[tree[node].ch[dir ^ 1]].color) {
					tree[tree[node].ch[dir ^ 1]].color = 0;
					balance = tree[node].color;
					tree[node].color = 1;
					return node;
				}
				node = rotate(node, dir);
				tree[node].ch[dir] = eraadj(tree[node].ch[dir], dir);
				return node;
			}
			balance = 0;
			if (tree[tree[tree[node].ch[dir ^ 1]].ch[dir ^ 1]].color) {
				tree[node].ch[dir ^ 1] = rotate(tree[node].ch[dir ^ 1], dir ^ 1);
			}
			node = rotate(node, dir);
			tree[tree[node].ch[0]].color = 1;
			tree[tree[node].ch[1]].color = 1;
			return node;
		}

	public:
		uint32 border;
		dynamic_FID() {
			tree.push_back((node_t){ 0,0,{0,0},1,0 });
			root = 0;
			border = 0;
			return;
		}
		bool insert(bool bit, uint32 pos) {
			border += !bit;
			data = bit;
			tree.push_back((node_t){ 1,bit,{0,0},0,bit });
			root = subins(root, pos);
			tree[root].color = 1;
			return bit;
		}
		bool erase(uint32 pos) {
			root = subera(root, pos);
			border -= !data;
			return data;
		}
		uint32 rank(uint32 pos) {
			uint32 ret = 0, node = root;
			while (node) {
				if (tree[tree[node].ch[0]].size < pos) {
					pos -= tree[tree[node].ch[0]].size + 1;
					ret += tree[tree[node].ch[0]].sum + tree[node].bit;
					node = tree[node].ch[1];
				}
				else node = tree[node].ch[0];
			}
			return ret;
		}
		bool access(uint32 pos) {
			uint32 node = root;
			while (tree[tree[node].ch[0]].size != pos) {
				if (tree[tree[node].ch[0]].size < pos) {
					pos -= tree[tree[node].ch[0]].size + 1;
					node = tree[node].ch[1];
				}
				else node = tree[node].ch[0];
			}
			return tree[node].bit;
		}
	};

#define bitsize std::numeric_limits<T>::digits
	std::vector<dynamic_FID> tree;
	uint32 length = 0;

public:
	dynamic_wavelet_matrix() :tree(bitsize) {};
	// 挿入
    // a = a[0, index) + a[index, n)を
    // a = a[0, index) + data + a[index, n)にする
	void insert(uint32 index, const T &data) {
		++length;
		uint32 i = bitsize;
		while (~(--i)) {
			if (tree[i].insert(data >> i & 1, index)) index = tree[i].border + tree[i].rank(index);
			else index -= tree[i].rank(index);
		}
		return;
	}
	// 削除
    // a = a[0, index) + a[index, n)を
    // a = a[0, index) + a(index, n)にする
	void erase(uint32 index) {
		--length;
		uint32 i = bitsize;
		while (~(--i)) {
			if (tree[i].erase(index)) index = tree[i].border + tree[i].rank(index);
			else index -= tree[i].rank(index);
		}
		return;
	}
	// 代入
    // a[i] = data
	void set(uint32 index, const T &data) {
        erase(index);
        insert(index, data);
	}
	// return a[i]
	T access(uint32 index) {
		T ret = 0;
		uint32 i = bitsize;
		while (~(--i)) {
			if (tree[i].access(index)) {
				ret |= (T)1 << i;
				index = tree[i].border + tree[i].rank(index);
			}
			else index -= tree[i].rank(index);
		}
		return ret;
	}
	// [begin,end)でdataの出現する回数
	T rank(uint32 begin, uint32 end, const T &data) {
		uint32 i = bitsize;
		while (~(--i)) {
			if (data >> i & 1) {
				begin = tree[i].border + tree[i].rank(begin);
				end = tree[i].border + tree[i].rank(end);
			}
			else {
				begin -= tree[i].rank(begin);
				end -= tree[i].rank(end);
			}
		}
		return end - begin;
	}
	// [begin,end)のrank番目に大きい値(rankは0-indexed)
    // 大きい値であることに注意！！
	T quantile(uint32 begin, uint32 end, uint32 rank) {
		T ret = 0;
		uint32 a, b;
		uint32 i = bitsize;
		while (~(--i)) {
			a = tree[i].rank(begin);
			b = tree[i].rank(end);
			if (b > a + rank) {
				ret |= (T)1 << i;
				begin = a + tree[i].border;
				end = b + tree[i].border;
			}
			else {
				begin -= a;
				end -= b;
				rank -= b - a;
			}
        }
        return ret;
    }
    long long size(void) {
        return length;
    }
    void show(void) {
        for (uint32 i = 0;i < length;++i) {
            std::cout << access(i) << " ";
        }
        std::cout << "\n";
        return;
    }
};
int main(void) {

	dynamic_wavelet_matrix<uint64> T;

	T.insert(0, 4);
	T.insert(0, 3);
	T.insert(0, 2);
	T.insert(0, 1);
    T.show();
    // k番目に**大きい**値であることに注意！
	std::cout << T.quantile(0, 3, 0) << "\n";

	T.erase(1);
    T.show();
	std::cout << T.quantile(0, 3, 0) << "\n";

	T.set(1, 30);
	T.set(2, 20);
    T.show();
	std::cout << T.quantile(0, 3, 1) << "\n";

	return 0;
}
