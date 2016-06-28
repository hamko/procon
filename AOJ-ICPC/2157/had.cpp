#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
int N;
string s, t;
map<string,int> dist;

int solve(){
    dist.clear();
    queue<string> que;
    que.push(s);
    dist[s] = 0;
    int queue_max = 0;
    while(!que.empty()){
        queue_max = max(queue_max, (int)que.size());
        string v = que.front(); que.pop();
        int d = dist[v];
        if(v == t) { 
            cout << queue_max << "#MAX SIZE" << endl;
            return d;
        }
        int nl = 0;
        while(nl < N and v[nl] == t[nl]) nl++;
        int c = (t[nl]-v[nl]+10)%10;
        repi(l,nl,N) {
            v[l] = (v[l]+c-'0') %10 + '0';
            if(dist.find(v) == end(dist)) {
                dist[v] = d+1;
                que.push(v);
            }
        }
    }
}

bool input(){
    cin >> N;
    if(!N) return 0;
    cin >> s >> t;
    return 1;
}

signed main(){
    cout << "STARTED" << endl;
    while(input()) cout << solve() << endl;
    return 0;
}
