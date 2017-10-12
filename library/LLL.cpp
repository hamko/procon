// input:
//      p
//      b
// output:
//      p, bでローリングハッシュが一致する2つの文字列を出力
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <functional>
#include <set>
#include <sstream>
#include <map>
#include <queue>
#include <stack>

using namespace std;
typedef long double ld;

//点は縦ベクトルで表現

//B1のx列目とB2のy列目の内積
ld IP(vector<vector<ld> > &B1, int x, vector<vector<ld> > &B2, int y){
    ld res=0;
    for(int i=0;i<B1.size();i++) res+=B1[i][x]*B2[i][y];
    return res;
}

//グラム･シュミットの直交化法
//https://en.wikipedia.org/wiki/Gram-Schmidt_process
vector<vector<ld> > GS(vector<vector<ld> > &Basis){
    
    const int n=Basis.size();
    
    //直交系
    vector<vector<ld> > Basis_(n,vector<ld>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) Basis_[i][j]=Basis[i][j];
    }
    
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            ld ip=IP(Basis,i,Basis_,j);
            ld ip2=IP(Basis_,j,Basis_,j);
            for(int k=0;k<n;k++) Basis_[k][i]-=ip/ip2*Basis_[k][j];
        }
    }
    
    return Basis_;
}

//グラム･シュミット係数
ld MU(vector<vector<ld> > &Basis,int x,vector<vector<ld> > &Basis_,int y){
    return IP(Basis,x,Basis_,y)/IP(Basis_,y,Basis_,y);
}

// LLLアルゴリズムで簡約基底の近似を求め，0列目を最短格子ベクトルの近似として出力
// https://en.wikipedia.org/wiki/Lenstra–Lenstra–Lovász_lattice_basis_reduction_algorithm
vector<ld> LLL(vector<vector<ld> > Basis){
    const int n=Basis.size();
    const ld delta=3.0L/4.0L;
    
    //最短ベクトル
    vector<ld> sv(n);    
    
    //直交系
    vector<vector<ld> > Basis_=GS(Basis);
    int k=1;
    while(k<n){
 
        for(int j=k-1;j>=0;j--){
            ld mu=MU(Basis,k,Basis_,j);
            if( abs(mu) <= 0.5L ) continue;
            mu=roundl(mu);
            for(int i=0;i<n;i++) Basis[i][k]-=mu*Basis[i][j];
            Basis_=GS(Basis);
        }
        
        ld mu = MU(Basis,k,Basis,k-1);
        if( IP(Basis_,k,Basis_,k) >= (delta-mu*mu)*IP(Basis_,k-1,Basis_,k-1)) k++;
        else{
            for(int i=0;i<n;i++) swap(Basis[i][k],Basis[i][k-1]);
            Basis_=GS(Basis);
            k=max(k-1,1);
        }
    }

    for(int i=0;i<n;i++) sv[i]=Basis[i][0];
    return sv;
}

int main(){

    ld p,b;
    cin>>p>>b;

    vector<ld> tmp;
    vector<long long> coe;
    int n;
    for(n=4;;n++){

        coe.resize(n);
        
        //基底ベクトル
        //解説は点を横ベクトルで表現している(?)ので転置した
        vector<vector<ld> > Basis(n,vector<ld>(n,0));
        for(int i=0;i<n-1;i++){
            Basis[i][i]=-b;
            Basis[i+1][i]=1;
        }
        Basis[0][n-1]=p;
        
        //Bが根となる多項式
        tmp=LLL(Basis);
        reverse(tmp.begin(),tmp.end());
        for(int i=0;i<n;i++) coe[i]=(long long)tmp[i];
        
        //a~zで表現可能ならbreak
        bool ok=true;
        for(int i=0;i<n;i++) ok&=(abs(tmp[i])<=25.0);
        if(ok) break;
    }

    //出力準備
    map<int,pair<char,char> > st;
    for(int i=-25;i<=25;i++){
        bool ok=false;
        for(char s='a';s<='z' && !ok;s++){
            for(char t='a';t<='z' && !ok;t++){
                if(s-t==i){
                    st[i]=make_pair(s,t);
                    ok=true;
                }
            }
        }
    }

    //出力
    string s,t;
    for(int i=0;i<n;i++){
        s+=st[coe[i]].first;
        t+=st[coe[i]].second;
    }
    cout<<s+"\n"<<t<<endl;

    return 0;

}
