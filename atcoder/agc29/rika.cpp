#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>

using namespace std;

#define ll long long
#define ld long double
#define EPS 0.0000000001
#define INF 1e9
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<(n);i++)
#define loop(i,a,n) for(i=a;i<(n);i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
#define int ll
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int lcm(int a, int b){
    return a*b/gcd(a,b);
}


vector<int> seg;

class SegTree{

private:

    int n;
    int init = 0; //初期化の値（単位元）
    int combine(int a, int b){
        return a+b;
    }

public:

    SegTree(int size){
		n=1;
		while(n<size)n<<=1;
		seg=vector<int>(2*n,init);
	}

	SegTree(const vector<int> &in){
		n=1;
		while(n<in.size())n<<=1;
		seg=vector<int>(2*n,init);
		for(int i=n-1+in.size()-1;i>=0;i--){
			if(n-1<=i)seg[i]=in[i-(n-1)];
			else seg[i]=combine(seg[i*2+1],seg[i*2+2]);
		}
	}


    //k-th(0-indexd) を aにする
    void update(int k,int a){
      k+=n-1;
      seg[k]=a;
      while(k>0){
        k=(k-1)/2;
        seg[k]=combine(seg[k*2+1],seg[k*2+2]);
      }
    }

    //[a,b)について調べる
    int query(int a,int b,int k=0,int l=0,int r=-1){
        if(r==-1)r=n;
        if(r<=a || b<=l)return init;
        if(a<=l &&r<=b)return seg[k];

        int vl=query(a,b,k*2+1,l,(l+r)/2);
        int vr=query(a,b,k*2+2,(l+r)/2,r);

        return combine(vl,vr);
    }
};



signed main(void) {
    int i,j;
    int n;
    cin >> n;
    vi a(n);
    SegTree s(1e5);
    rep(i,n) cin >> a[i];
    vector<pii> ans;
    ans.push_back(pii(a[0],0));
    s.update(0,a[0]);
    int ret = 0;
    rep(i,n-1){
        if(a[i] < a[i+1]){
            int t = ans.size()-1;
            if(ans[t].second){
                ans.push_back(pii(1,0));
                s.update(t+1,1);
            }else{
                ans[t].first += a[i+1]-a[i];
                s.update(t, ans[t].first);
            }
        }else{
            int ok = 0, ng = 1e5;
            while((ng-ok) > 1){
                int mid = (ok+ng)/2;
                int sum = s.query(0,mid);
                //cout << "! " << ok << " " << ng << " " << mid << " " << sum << endl;
                if(sum < a[i+1])ok = mid;
                else ng = mid;
            }
            int num = a[i+1] - s.query(0,ok) - 1;
            //cout << ok << " " << num << endl;
            int t = ans[ok].second;
            if(num){
                ans[ok].first = num;
                s.update(ok,num);
            }else{
                ok--;
            }
            while(ans.size() > ok+1){
                ans.pop_back();
                s.update(ans.size(),0);
            }
            ans.push_back(pii(1,t+1));
            ret = max(ret,t+1);
            s.update(ans.size()-1,1);
        }
        //cout << i << endl;
        //rep(j,ans.size())cout << " " <<  j << " " << ans[j].first << " " << ans[j].second << endl;

    }
    cout << ret+1 << endl;
}

