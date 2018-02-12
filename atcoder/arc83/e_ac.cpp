#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
#include <cmath>  
#include <complex>  
#include <deque>  
#include <functional>  
#include <iostream>  
#include <limits.h>  
#include <map>  
#include <math.h>  
#include <queue>  
#include <set>  
#include <stdlib.h>  
#include <string.h>  
#include <string>  
#include <time.h>  
#include <unordered_map>  
#include <unordered_set>  
#include <vector>

#pragma warning(disable:4996)  
#pragma comment(linker, "/STACK:336777216")  
using namespace std;

#define mp make_pair  
#define Fi first  
#define Se second  
#define pb(x) push_back(x)  
#define szz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()  
#define ldb ldouble  

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 19;
const ll MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

vector <int> son[1050];
int dp[5050];
int in[5050];

bool tdp[1050][5050];
bool tdp2[5050];
void DFS(int n) {

	tdp[n][0] = true;
	int s = 0, i;
	for (auto it : son[n]) {
		DFS(it);
		s += in[it] + dp[it];
		
		for (i = 0; i <= in[n]; i++) tdp2[i] = false;
		for (i = 0; i <= in[n]; i++) {
			if (!tdp[n][i]) continue;
			if (i + in[it] <= in[n]) tdp2[i + in[it]] = true;
			if (i + dp[it] <= in[n]) tdp2[i + dp[it]] = true;
		}
		for (i = 0; i <= in[n]; i++) tdp[n][i] = tdp2[i];
	}
	
	for (i = in[n]; i >= 0; i--) if (tdp[n][i]) break;
	if (i < 0) {
		printf("IMPOSSIBLE\n");
		exit(0);
	}
	dp[n] = min(5001, s - i);
}
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 2; i <= N; i++) {
		int t;
		scanf("%d", &t);
		son[t].push_back(i);
	}
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);

	DFS(1);
	return !printf("POSSIBLE\n");
}

