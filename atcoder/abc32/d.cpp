#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define all(x) begin(x), end(x)

typedef long long ll;
typedef pair<ll, ll> LP; // int, intでオーバーフロー

const ll INF = 1e18; // LLONG_MAXにしたらオーバーフロー。defineしたらlong longとみなされなくて死。
int n, W;

#define MAX_N 205
ll v[MAX_N], w[MAX_N];

#define MAX_NV 200005
void solve_small_weight_problem()
{
    ll dp[2][MAX_NV] = {};
    rep(i, 2) rep(j, MAX_NV) dp[i][j] = 0; 

    rep(i, n) rep(j, MAX_NV) {
        int next = (i+1)%2, prev = i%2;
        dp[next][j] = max(dp[prev][j], j-w[i]<0 ? 0 : dp[prev][j-w[i]]+v[i]);
    }

    ll m = 0;
    rep(i, W+1) 
        m = max(m, dp[n%2][i]);
    cout << m << endl;
}

#define MAX_NW 200005
void solve_small_value_problem()
{
    ll dp[2][MAX_NV]; 
    rep(i, 2) rep(j, MAX_NV) dp[i][j] = INF; dp[0][0] = 0;

    rep(i, n) rep(j, MAX_NV) {
        int next = (i+1)%2, prev = i%2;
        dp[next][j] = min(dp[prev][j], j-v[i]<0 ? INF : dp[prev][j-v[i]]+w[i]);
    }

    ll m = 0;
    rep(i, MAX_NV) 
        if (dp[n%2][i] <= W)
            m = max(m, (ll)i);
    cout << m << endl;
}

void get_pruned_all_combination(vector<LP>& bag_pruned, int bag_n, int start_point) 
{
    // 全列挙
    vector<LP> bag; bag.reserve(1 << bag_n);
    rep(i, 1 << bag_n) {
        ll v_tmp = 0, w_tmp = 0;
        for (int j = 0; j < bag_n; j++) {
            if (i & (1 << j)) {
                v_tmp += v[start_point+j];
                w_tmp += w[start_point+j];
            }
        }
        if (w_tmp > W) 
            continue;
        bag.push_back(LP(w_tmp, v_tmp));
    }
    sort(all(bag));

    // いらないものを排除（今思えばここでやらなくても良かったな。upper_boundのところに1行追加すればこれと同等のことができるはず）
    ll last_v = -1; 
    rep(i, bag.size()) {
        while (i != bag.size() - 1 && bag[i].first == bag[i+1].first) i++;
        if (last_v < bag[i].second) {
            bag_pruned.push_back(bag[i]);
            last_v = bag[i].second; // これを2行下に書いてたせいで昇順になってなかった。昇順になっていなかったことに長い間気づかなかった。プロコンでもassertを使うべきだろうか
        }
    }
}

void solve_small_n_problem()
{
    // bagAとbagBに二分する。
    int bagA_n = n / 2, bagB_n = n - bagA_n;

    // 両方のbagで、重さでソートかつ重さが大なら価値の大なる組み合わせを全列挙
    vector<LP> bagA_pruned; bagA_pruned.reserve(1 << bagA_n);
    get_pruned_all_combination(bagA_pruned, bagA_n, 0);
    vector<LP> bagB_pruned; bagB_pruned.reserve(1 << bagB_n);
    get_pruned_all_combination(bagB_pruned, bagB_n, bagA_n);

    // bagAのそれぞれに対応する、最大のbagBの荷物を二分探索で探す
    ll m = 0;
    rep(i, bagA_pruned.size()) {
        LP f = bagA_pruned[i];
        if (f.first > W)
            break;
        vector<LP>::iterator s = upper_bound(all(bagB_pruned), LP(W-f.first, INF)) - 1; // W-f.first以下の最大のbagBを、二分探索で探す。探しものがbagBのmin以上なら、upper_boundは必ず1以上になるので、必ず1が引ける！
        m = max(m, f.second + s->second);
    }
    cout << m << endl;
}

int main(void) {
    cin >> n >> W;

    bool small_weight_problem = false;
    rep(i, n) {
        cin >> v[i] >> w[i];
        if (v[i] > 1000) 
            small_weight_problem = true;
    }

    if (n <= 30) 
        solve_small_n_problem();
    else if (small_weight_problem) 
        solve_small_weight_problem();
    else
        solve_small_value_problem();

    return 0;
}
