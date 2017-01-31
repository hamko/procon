#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
struct edge{
    int d, w;
};
vector <edge> graph[10010];
bool sto[10010];
vector <int> stor;
int main(){
    ios::sync_with_stdio(false);
    int n, m,k;
    cin>>n>>m>>k;

    long long ans=1e9 +300;
    for(int i=0; i<m; i++){//USES 1 BASED
        int s;
        cin>>s;
        edge temp;
        cin>>temp.d;
        cin>>temp.w;
        graph[s].push_back(temp);
        edge temp2;
        int s2=temp.d;
        temp2.d=s;
        temp2.w=temp.w;
        graph[s2].push_back(temp2);

    }
    for(int i=0; i<k; i++){
        int x;
        cin>>x;
        sto[x]=true;
        stor.push_back(x);
    }
    for(int i=0; i<k; i++){
        int curSto=stor[i];
        for(int b=0; b<graph[curSto].size(); b++){
            if(!sto[graph[curSto][b].d]){
                int abc=graph[curSto][b].w;
                if(abc<ans) ans=abc;
            }
        }
    }
    if(ans==1e9+300) cout<<-1<<endl;
    else cout<<ans<<endl;
}
