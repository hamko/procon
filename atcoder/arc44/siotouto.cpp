#include <bits/stdc++.h>
typedef long long LL;
#define SORT(c) sort((c).begin(),(c).end())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

using namespace std;
const LL prime = 1000000007;
LL pow2(LL x){
    if(x==0) return 1;
    LL tmp=pow2(x/2);
    tmp*=tmp;
    tmp%=prime;
    if(x%2) return tmp*2%prime;
    else return tmp;
}
int main(void)
{
    int n;
    LL buc[131072]={};
    cin >> n;
    REP(i,n){
        int tmp;
        cin >> tmp;
        ++buc[tmp];
        if(i==0&&tmp!=0){
            cout << 0 << endl;
            return 0;
        }
    }
    if(buc[0]!=1){
        cout << 0 << endl;
        return 0;
    }
    LL answer=1;
    REP(i,n){
        if(buc[i+1]){
            REP(j,buc[i+1]){
                answer*=pow2(buc[i])-1;
                answer%=prime;
            }
            answer*=pow2(buc[i+1]*(buc[i+1]-1)/2);
            answer%=prime;
            cout << i << " " << answer << endl;
        }
    }
    cout << "#" << endl;
    cout << answer << endl;
    return 0;
}
