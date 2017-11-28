#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
#include<cassert>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=500000004;
const double EPS=1e-6;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
double dp[1100][1100];
int v[1100][1100];
int n;
double calc(int a,int b){
	if(v[a][b])return dp[a][b];
	v[a][b]=1;
 
	if(a==b)return dp[a][b]=1;
	if(b==0)return dp[a][b]=0;
	int bb=n-a+1;
	dp[a][b]=max((1.0/a)+(1.0-1.0/a)*(1.0/bb*calc(a-1,b-1)+(1.0-1.0/bb)*calc(a-1,b)),(1.0-1.0/a)*calc(a-1,b));
	//printf("%d %d: %f\n",a,b,dp[a][b]);
	return dp[a][b];
}
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	n=a;
	printf("%.12f\n",calc(a,b));
}

