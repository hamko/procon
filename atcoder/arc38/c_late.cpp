#include<bits/stdc++.h>
using namespace std;
 
//#define int long long
 
typedef pair<int,int>pint;
typedef vector<int>vint;
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}
 
const int SIZE=100000;
 
struct segtree{
    int N;
    vint dat;
    void init(int n){
        for(N=1;N<n;N*=2);
        dat.assign(N*2,-1);
    }
    void update(int k,int x){
        k+=N-1;
        dat[k]=x;
        while(k){
            k=(k-1)/2;
            dat[k]=min(dat[k*2+1],dat[k*2+2]);
        }
    }
    int get(int a,int b){return get(a,b,0,0,N);}
    int get(int a,int b,int k,int l,int r){
        if(r<=a||b<=l)return 1001001001;
        if(a<=l&&r<=b)return dat[k];
        return min(get(a,b,k*2+1,l,(l+r)/2),get(a,b,k*2+2,(l+r)/2,r));
    }
    void print(void) {
        rep(i, N) {
            cout << dat[N-1+i] << " ";
        }
        cout << endl;
    }
};
 
int N;
int C[SIZE],A[SIZE];
segtree seg;
signed main(){
    cin>>N;
    rep(i,N-1)cin>>C[i+1]>>A[i+1];
    seg.init(N);
    seg.update(0,0);
    int X=0;
    seg.print();
    reps(i,1,N){
        int lb=0,ub=N+1;
        while(ub-lb>1){
            int mid=(ub+lb)/2;
            if(seg.get(0,mid)<i-C[i])ub=mid;
            else lb=mid;
        }
        seg.update(lb,i);
        seg.print();
        if(A[i]&1)X^=lb;
    }
    if(X)cout<<"First"<<endl;
    else cout<<"Second"<<endl;
 
    return 0;
}
