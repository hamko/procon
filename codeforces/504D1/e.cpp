#include <string>
#include <iostream>
#include <assert.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n); i++)

int main(void) {
    int n;
    fflush(stdout); scanf("%d", &n); fflush(stdout);
    int i = 0, j = 0;
    string ret;
    while (1) {
        if (i == n-1 && j == n-1) {
            fflush(stdout); printf("! %s", ret.c_str()); fflush(stdout);
            return 0;
        }
        char c = 'D';
        int ii = i + 1, jj = j;
        if (ii >= n) {
            ii = i, jj = j + 1;
            c = 'R';
        }
        assert(ii+1 <= n);
        assert(jj+1 <= n);
        if (ii+1==n&&jj+1==n) {
            if (c == 'D') {
                ret += 'D';
                i++;
            } else {
                ret += 'R';
                j++;
            }
            continue;
        }
        assert(1<=ii+1&&ii+1<=n);
        assert(1<=jj+1&&jj+1<=n);
        fflush(stdout); printf("? %d %d %d %d", ii+1, jj+1, n, n); fflush(stdout);
        char res_c[10]; 
        fflush(stdout); scanf("%s", res_c); fflush(stdout);
        string res(res_c);
        if (res == "YES") {
            if (c == 'D') {
                ret += 'D';
                i++;
            } else {
                ret += 'R';
                j++;
            }
        } else if (res == "NO") {
            if (c == 'D') {
                ret += 'R';
                j++;
            } else {
                ret += 'D';
                i++;
            }
        } else if (res == "BAD") {
        }
    }

    return 0;
}
