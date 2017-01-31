#include <bits/stdc++.h>
using namespace std;

struct node {
    node *next[2] = {};
    int sub = 0;
};

node *root = new node();

int sub(node *x) {
    return x ? x->sub : 0;
}

void add(int x) {
    node *curr = root;
    for (int i = 30; i >= 0; i--) {
        int j = x >> i & 1; // xのi bit目
        if (!curr->next[j]) curr->next[j] = new node();
        curr = curr->next[j];
        curr->sub++;
    }
}

void remove(int x) {
    node *curr = root;
    for (int i = 30; i >= 0; i--) {
        int j = x >> i & 1;
        curr = curr->next[j];
        curr->sub--;
    }
}

int query(int x) {
    int res = x;
    node *curr = root;
    for (int i = 30; i >= 0; i--) {
        int j = ~x >> i & 1;
        if (sub(curr->next[j]) == 0) j ^= 1;
        res ^= j << i;
        curr = curr->next[j];
    }
    return res;
}

void print(void) {
}
int main() {
    int n;
    scanf("%d", &n);

    add(0);

    for (int ii = 0; ii < n; ii++) {
        char c;
        int x;
        scanf(" %c %d", &c, &x);

        if (c == '+') {
            add(x);
        } else if (c == '-') {
            remove(x);
        } else {
            int res = query(x);
            printf("%d\n", res);
        }
    }
}
