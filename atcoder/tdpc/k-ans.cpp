#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(long long i = 0; i < (long long)(n); i++)
int N;
pair<int,int> P[1000001];

vector<int> LIS(vector<int>& v) {
	int i;
	vector<int> dp(N,1<<30),id(N);
	FOR(i,v.size()) {
		id[i] = lower_bound(dp.begin(),dp.end(),v[i]) - dp.begin();
		dp[id[i]] = v[i];
	}
	int nl = *max_element(id.begin(),id.end());
	vector<int> ret(nl+1);
	FOR(i,N) if(id[N-1-i] == nl) ret[nl--] = v[N-1-i];
	return ret;
}

void solve() {
	int f,r,i,j,k,l, x,y,z;
	
	cin>>N;
	FOR(i,N) {
		cin>>x>>y;
		P[i]=make_pair((x+y),(x-y));
	}
	sort(P,P+N);
	vector<int> V;
	FOR(i,N) V.push_back(-P[i].second);
	FOR(i,N) {
        cout << P[i].first << " " << P[i].second << endl;
    }
    FOR(i, V.size()) {
        cout << V[i] << endl;
    }

	vector<int> L=LIS(V);
    cout << L.size() << endl;
}
int main(void) {
    solve();
    return 0;
}
