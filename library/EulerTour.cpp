#include <vector>
using namespace std;
#define pb push_back
#define MAX_N 100100
vector<int> g[MAX_N];
vector<int> euler_tour;
int begin[2*MAX_N],end[2*MAX_N];
int k=0,root=0;
void dfs(int v,int p)
{
    begin[v]=k;
    euler_tour.pb(v);
    k++;
    for(int i=0;i<g[v].size();i++) {
        if(g[v][i]!=p) {
            dfs(g[v][i],v);
            euler_tour.pb(v);
            k++;
        }
    }
    end[v]=k;
}
int main()
{
    dfs(root,-1);
}
