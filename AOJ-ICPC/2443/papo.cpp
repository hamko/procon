#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int N;
vector<int> A, B;

map<vector<int>, int> bfs(vector<int> start) {
    map<vector<int>, int> memo;
    queue< vector<int> > Q;
    Q.push(start);
    memo[start] = 0;

    while(!Q.empty()) {
        vector<int> vi = Q.front();
        Q.pop();

        int cost = memo[vi];

        if(cost >= (N - 1) / 2) continue;

        for(int i = 0; i < N; i++) {
            for(int j = i + 2; j <= N; j++) {
                vector<int> tmp = vi;
                reverse(tmp.begin() + i, tmp.begin() + j);
                if(memo.find(tmp) == memo.end()) {
                    memo[tmp] = cost + 1;
                    Q.push(tmp);
                }
            }
        }
    }

    return memo;
}

int solve() {
    int ans = N - 1;
    map<vector<int>, int> memo_A = bfs(A);
    map<vector<int>, int> memo_B = bfs(B);
    if(memo_A.find(B) != memo_A.end()) ans = memo_A[B];
    else {
        do {
            if(memo_A.find(B) == memo_A.end()) continue;
            if(memo_B.find(B) == memo_B.end()) continue;
            ans = min(ans, memo_A[B] + memo_B[B]);
        } while(next_permutation(B.begin(), B.end()));
    }
    return ans;
}

int main() {
    cin >> N;
    rep(i, N) {
        int a;
        cin >> a;
        A.push_back(a);
    }
    B = A;
    sort(B.begin(), B.end());
    cout << solve() << endl;
    return 0;
}
