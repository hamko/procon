#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>
#include<string>
#include<map>
#include<list>
#include<queue>
#include<utility>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<math.h>
#include<set>
#include<stack>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<iterator>
#include<unordered_map>
using namespace std;
#define ll long long
#define ld long double
#define llu unsigned long long
#define inf 99194853094755497
#define pf printf
#define sf scanf
#define sf1(x) scanf("%lld",&x)
#define sf2(x,y) scanf("%lld %lld",&x,&y)
#define sf3(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define sf4(x,y,z,w) scanf("%lld %lld %lld %lld",&x,&y,&z,&w)
#define pii pair<long long,long long>
#define sq(x) ((x)*(x))
#define MAX 100009
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
#define mod 1000000007
#define PI acos(-1.0)
const double INF = 1e100;
const double EPS = 1e-9;
/*struct debugger
{
    template<typename T> debugger& operator, (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
}dbg;
#define deb(args...){dbg, args; cerr<<endl;}*/


template<class T1> void deb(T1 e1)
{
    cout<<e1<<endl;
}
template<class T1,class T2> void deb(T1 e1,T2 e2)
{
    cout<<e1<<" "<<e2<<endl;
}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3)
{
    cout<<e1<<" "<<e2<<" "<<e3<<endl;
}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;
}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;
}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;
}

template< class T > T gcd(const T a, const T b) { return (b ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(const T a, const T b) { return (a / gcd<T>(a, b) * b); }

///Link List
/*
struct node
{
	int roll;
	node *next, *prev;
};
node *root, *tail;
void append(int roll)
{
	if(root==NULL) ///If the list is empty
	{
		root=new node();
		root->roll=roll;
		root->next=NULL;
		tail=root;
	}
	else
	{
		node *newnode=new node();
		newnode->roll=roll;
		newnode->next=NULL;
		tail->next=newnode; ///add the new node after tail node
		tail=tail->next; ///move tail pointer forward
		///by using tail we can add a new element at O(1) comlexity
	}
}

void delete_node(int roll)
{
	node *current_node=root;
	node *previous_node=NULL;
	while(current_node->roll!=roll) ///Searching node
	{
		previous_node=current_node; ///Save the previous node
		current_node=current_node->next;
	}
	if(current_node==root) ///Delete root
	{
		node *temp=root; ///save root in temporary variable
		root=root->next; ///move root forward
		delete(temp); ///free memory
	}
	else ///delete non-root node
	{
		previous_node->next=current_node->next; ///previous node points the current node's next node
		delete(current_node); ///free current node
	}

}
*/


/*int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}
int flip(int N,int pos){return N= N ^ (1<<pos);}
int Least_Significant_Bit(int N){return N= N & (-N);}*/
// moves
//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//ios_base::sync_with_stdio(0); cin.tie(0);
struct node{
    ll x,y;
    node(){}
    node(ll x,ll y):x(x),y(y){}
    bool operator < (const node & p) const
    {
        return x<p.x;
    }
};
vector<ll>v,v1,v2;
unordered_map<ll,ll>mp;
ll a[5006];
int main()
{
    ll i,j,k,l,x,y,z,t,m=0,n,l1,l2;
    sf1(n);
    for(i=0;i<n;i++){
        sf1(x);
        a[i]=x;
        if(!mp[x]){
            v.pb(x);
            v1.pb(x);
        }
        mp[x]++;
    }
    sort(a,a+n);
    sort(v.begin(),v.end());
    sort(v1.begin(),v1.end());
    for(i=0;i<n;i++){
        if(mp[a[i]]>0){
            l=0;
            y=a[i];
            while(1){
                x=upper_bound(v1.begin(),v1.end(),y)-v1.begin();
                if(mp[y]){
                    mp[y]--;
                }
                if(x==v1.size()){
                    m++;
                    break;
                }
                y=v1[x];
            }
        }
        v1.clear();
        for(j=0;j<v.size();j++){
            if(mp[v[j]]){
                v1.pb(v[j]);
            }
        }
    }
    deb(m);

    return 0;
}


