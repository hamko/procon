#include <bits/stdc++.h>
using namespace std;

static const double EPS = 1e-5;
#define EQ(a,b) (abs((a)-(b))<EPS)

#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define all(x) begin(x), end(x)
#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<string> vs;

int main(void) {
    int nx, ny, sx, sy, gx, gy;
    cin >> nx >> ny;
    cin >> sx >> sy; sx--; sy--;
    cin >> gx >> gy; gx--; gy--;
    int state[100][100];
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            char c;
            cin >> c;
            if (c == '.')
                state[i][j] = -2;
            else 
                state[i][j] = -1;
        }
    }

    queue<pair<int, int> > q;
    q.push(pair<int, int>(sx, sy));
    state[sx][sy] = 0;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    while (!q.empty()) {
        pair<int, int> tmp = q.front(); q.pop();
        int x = tmp.first; int y = tmp.second;
        for (int d = 0; d < 4; d++) {
            if (state[x+dx[d]][y+dy[d]] == -2 && state[x+dx[d]][y+dy[d]] != -1 && 
                    x+dx[d]>=0 && x+dx[d]<nx && y+dy[d]>=0 && y+dy[d]<ny) {
                q.push(pair<int, int>(x+dx[d], y+dy[d]));
                state[x+dx[d]][y+dy[d]] = state[x][y] + 1;
            }
        }
    }

    cout << (int)state[gx][gy] << endl;
    return 0;
}
