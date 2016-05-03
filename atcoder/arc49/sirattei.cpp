#include <bits/stdc++.h>
using namespace std;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FORR(x,arr) for(auto&& x:arr)
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define REP(i,n) for (int i = 0; i < (n); i++)
#define RREP(i,n) for (int i = (n)-1; i >= 0; i--)
#define ALL(x) (x).begin(), (x).end()
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define BIT(n) (1LL<<(n))
#define SZ(x) ((int)(x).size())
typedef long long ll;
// -------------------------------------

template<class T> inline bool amax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }

int N, A, B;
int X[100], Y[100];
int U[10], V[10];

vector<int> E[100];
bool unuse[100];
bool painted[100];

void Main() {
    cin >> N >> A;

    REP(i, A) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        X[i] = x;
        Y[i] = y;
    }
    cin >> B;
    REP(i, B) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        U[i] = u;
        V[i] = v;
    }

    int ans = 0;

    REP(i, BIT(B)) {
        memset(unuse, 0, sizeof(unuse));
        memset(painted, 0, sizeof(painted));
        REP(i, N) E[i].clear();
        REP(j, B) {
            int u = U[j];
            int v = V[j];
            // ある頂点 u に色を塗るとき、既に頂点 v に色が塗られていてはいけない

            if (i & BIT(j)) {
                // v の前に u を塗るという制約 に読み替えるか
                E[v].push_back(u);
            }
            else {
                // u は塗らないという制約 に読み替えるか
                unuse[u] = true;
            }
        }

        REP(i, A) {
            // ある頂点 x に色を塗るとき、既に頂点 y に色が塗られてなければならない。
            // x の前に y を塗るという制約
            E[X[i]].push_back(Y[i]);
        }

        bool changed;
        int cnt = 0;
        do {
            changed = false;
            REP(j, N) {
                if (unuse[j]) continue;  // 塗らない頂点は飛ばす
                if (painted[j]) continue;  // 塗られた頂点も飛ばす
                bool can_paint_j = true;
                FORR(nex, E[j]) {
                    // j の前に nex を塗るという制約がある
                    if (!painted[nex]) {
                        // j を塗りたいが nex も塗られていないので制約違反
                        can_paint_j = false;
                        break;
                    }
                }
                if (can_paint_j) {
                    // j を塗る前に... の制約を全部チェックした結果、j を塗れる
                    painted[j] = true;
                    changed = true;
                    cnt++;
                }
            }
        } while (changed);
        amax(ans, cnt);
    }
    cout << ans << endl;
}

int main() { cin.tie(0); ios::sync_with_stdio(false); Main(); return 0; }
