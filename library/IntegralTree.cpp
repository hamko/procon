//////////////////
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//                  なんかバグってる！！！！！！！！！！！！！！！！！！！！
//
//
//
//
//
//
//
//
//
//
//
//
//
//
/////////////////////////
#include <bits/stdc++.h>
#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
const int B = 7; // バケットサイズ
const int MAXBIT = 32; // <10^9
struct IntegralTree {
    struct Node {
        Node *child[(1<<B)];
        int S;
        Node() : S(0) { fill(child, child+(1<<B), (Node*)0); }
    } root;
    void insert(Node *n, int x, int R) {
        int h = (x >> (R-B)) & ((1 << B)-1);
        n->S |= (1 << h);
        if (R > B) {
            if (!n->child[h]) n->child[h] = new Node;
            insert(n->child[h], x, R-B);
        }
    }
    void remove(Node *n, int x, int R) {
        int h = (x >> (R-B)) & ((1 << B)-1);
        if (!(n->S & (1 << h))) return;
        bool cond = true;
        if (R > B) {
            remove(n->child[h], x, R-B);
            if (n->child[h]->S != 0) cond = false;
        }
        if (cond) n->S &= ~(1 << h);
    }
    bool find(Node *n, int x, int R) {
        int h = (x >> (R-B)) & ((1 << B)-1);
        if (!(n->S & (1 << h))) return false;
        if (R > B) return find(n->child[h], x, R-B);
        else       return true;
    }
    void insert(int x) { insert(&root, x, MAXBIT); }
    void remove(int x) { remove(&root, x, MAXBIT); }
    bool find(int x) { return find(&root, x, MAXBIT); } 
};

int main(void) {
    {
        cout << "integral tree" << endl;
        IntegralTree it;
        rep(i, 1e7) {
            it.insert(i);
        }
    }
    rep(i, 1e7) {
        cout << "unordered_set" << endl;
        unordered_set<int> s;
        s.insert(i);
        rep(i, 1e7) {
            s.insert(i);
        }
    }
    return 0;
}

