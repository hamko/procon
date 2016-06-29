#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define repi(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mt make_tuple
#define mp make_pair

using ll = long long; using ld = long double; using vll = vector<ll>; using vvll = vector<vll>; using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>;
vll conv(vi& v) { vll r(v.size()); rep(i, v.size()) r[i] = v[i]; return r; }
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template<size_t...> struct seq{}; template<size_t N, size_t... Is> struct gen_seq : gen_seq<N-1, N-1, Is...>{}; template<size_t... Is> struct gen_seq<0, Is...> : seq<Is...>{};
template<class Ch, class Tr, class Tuple, size_t... Is>
void print_tuple(basic_ostream<Ch,Tr>& os, Tuple const& t, seq<Is...>){ using s = int[]; (void)s{0, (void(os << (Is == 0? "" : ", ") << get<Is>(t)), 0)...}; }
template<class Ch, class Tr, class... Args> 
auto operator<<(basic_ostream<Ch, Tr>& os, tuple<Args...> const& t) -> basic_ostream<Ch, Tr>& { os << "("; print_tuple(os, t, gen_seq<sizeof...(Args)>()); return os << ")"; }
ostream &operator<<(ostream &o, const vvll &v) { rep(i, v.size()) { rep(j, v[i].size()) o << v[i][j] << " "; cout << endl; } return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const unordered_map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it; o << "]";  return o; }
void printbits(ll mask, ll n) { rep(i, n) { cout << !!(mask & (1ll << i)); } cout << endl; }
#define ldout fixed << setprecision(40) 

vector<int> G[100000],euler;
int dbl[100000][18],ff[100000],ss[100000],bit[200001],n,q;
int sum(int i){
	int s=0;
	while(i>0){
		s+=bit[i];
		i-= i&-i;
	}
	return s;
}
void add(int i,int x){
	while(i<=2*n){
		bit[i]+=x;
		i+= i&-i;
	}
}
void dfs(int v){
	ff[v]=euler.size();
	euler.push_back(v);
	rep(i,G[v].size()) dfs(G[v][i]);
	ss[v]=euler.size();
	euler.push_back(v);
}
int main(){
	while(true){
		cin >> n >> q;
		if(n==0) break;
		euler.clear();
		rep(i,n) G[i].clear();
		rep(i,2*n+1) bit[i]=0;

		rep(i,n) rep(j,18) dbl[i][j]=-1;
		rep(i,n-1){
			int p;
			cin >> p;
			G[p-1].push_back(i+1);
			dbl[i+1][0]=p-1;
		}
		rep(i,17){
			rep(j,n){
				if(dbl[j][i]==-1) dbl[j][i+1]=-1;
				else dbl[j][i+1]=dbl[dbl[j][i]][i];
			}
		}
		rep(i,n) {
            rep(j,18) 
                cout << dbl[i][j] << " ";
            cout << endl;
        }

		dfs(0);
		add(ff[0]+1,1);
		add(ss[0]+1,-1);
        
        cout << euler << endl;
		long long ans=0;
		rep(i,q){
			char c;
			int v;
			cin >> c >> v;
			v--;
			if(c=='M'){
				add(ff[v]+1,1);
				add(ss[v]+1,-1);
			}else{
				int x=sum(ff[v]+1);
				for(int j=17;j>=0;j--){
					if(dbl[v][j]!=-1 && sum(ff[dbl[v][j]]+1)>=x) v=dbl[v][j];
				}
				ans+=(v+1);
			}
		}
		cout << ans << endl;
	}
}
