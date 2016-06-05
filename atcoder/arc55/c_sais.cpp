#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mt make_tuple
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

using ll = long long; using ld = long double; using vll = vector<ll>; using vvll = vector<vll>; using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>;
using P = pair<ll, ll>;

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
#define VN(v) # v
#define print(a) cout << a << "#" << VN(a) << endl;
#define ldout fixed << setprecision(40) 

class suffix_array{
    void create_begin_bucket(vector<int>&v,vector<int>&bucket){
        fill(bucket.begin(),bucket.end(),0);
        for(int i=0;i<v.size();i++)bucket[v[i]]++;
        int sum=0;
        for(int i=0;i<bucket.size();i++){bucket[i]+=sum;swap(sum,bucket[i]);}
    }

    void create_end_bucket(vector<int>&v,vector<int>&bucket){
        fill(bucket.begin(),bucket.end(),0);
        for(int i=0;i<v.size();i++)bucket[v[i]]++;
        for(int i=1;i<bucket.size();i++)bucket[i]+=bucket[i-1];
    }

    void induced_sort(vector<int>&v,vector<int>&sa,int mv,vector<int>&bucket,vector<int>&is_l){
        create_begin_bucket(v,bucket);
        for(int i=0;i<v.size();i++)if(sa[i]>0&&is_l[sa[i]-1])sa[bucket[v[sa[i]-1]]++]=sa[i]-1;
    }

    void invert_induced_sort(vector<int>&v,vector<int>&sa,int mv,vector<int>&bucket,vector<int>&is_l){
        create_end_bucket(v,bucket);
        for(int i=v.size()-1;i>=0;i--)if(sa[i]>0&&!is_l[sa[i]-1])sa[--bucket[v[sa[i]-1]]]=sa[i]-1;
    }

    vector<int>sa_is(vector<int>v,int mv){
        if(v.size()==1)return vector<int>(1,0);

        vector<int>is_l(v.size());
        vector<int>bucket(mv+1);
        vector<int>sa(v.size(),-1);
        auto is_lms=[&](int x)->bool{return x>0&&is_l[x-1]&&!is_l[x];};

        is_l[v.size()-1]=0;
        for(int i=v.size()-2;i>=0;i--)is_l[i]=v[i]>v[i+1]||(v[i]==v[i+1]&&is_l[i+1]);
        create_end_bucket(v,bucket);
        for(int i=0;i<v.size();i++)if(is_lms(i))sa[--bucket[v[i]]]=i;
        induced_sort(v,sa,mv,bucket,is_l);
        invert_induced_sort(v,sa,mv,bucket,is_l);

        int cur=0;
        vector<int>order(v.size());
        for(int i=0;i<v.size();i++)if(is_lms(i))order[i]=cur++;

        vector<int>next_v(cur);
        cur=-1;
        int prev=-1;
        for(int i=0;i<v.size();i++){
            if(!is_lms(sa[i]))continue;
            bool diff=false;
            for(int d=0;d<v.size();d++){
                if(prev==-1||v[sa[i]+d]!=v[prev+d]||is_l[sa[i]+d]!=is_l[prev+d]){
                    diff=true;
                    break;
                }
                else if(d>0&&is_lms(sa[i]+d))break;
            }
            if(diff){cur++;prev=sa[i];}
            next_v[order[sa[i]]]=cur;
        }

        vector<int>re_order(next_v.size());
        for(int i=0;i<v.size();i++)if(is_lms(i))re_order[order[i]]=i;
        vector<int>next_sa=sa_is(next_v,cur);
        create_end_bucket(v,bucket);
        for(int i=0;i<sa.size();i++)sa[i]=-1;
        for(int i=next_sa.size()-1;i>=0;i--)sa[--bucket[v[re_order[next_sa[i]]]]]=re_order[next_sa[i]];
        induced_sort(v,sa,mv,bucket,is_l);
        invert_induced_sort(v,sa,mv,bucket,is_l);
        return sa;
    }

    void sa_is(string &s){
        vector<int>v(s.size()+1);
        for(int i=0;i<s.size();i++)v[i]=s[i];
        sa=sa_is(v,*max_element(v.begin(),v.end()));
    }

    void construct_lcp(){
        lcp.resize(s.size());
        rank.resize(s.size()+1);
        int n=s.size();
        for(int i=0;i<=n;i++)rank[sa[i]]=i;
        int h=0;
        lcp[0]=0;
        for(int i=0;i<n;i++){
            int j=sa[rank[i]-1];

            if(h>0)h--;
            for(;j+h<n&&i+h<n;h++){
                if(s[j+h]!=s[i+h])break;
            }
            lcp[rank[i]-1]=h;
        }
    }

    struct segtree{
        int N;
        vector<int>dat;
        void init(vector<int> &v){
            for(N=1;N<v.size();N<<=1);
            dat.resize(N*2,1001001001);
            for(int i=0;i<v.size();i++)dat[i+N-1]=v[i];
            for(int i=N-2;i>=0;i--)dat[i]=min(dat[i*2+1],dat[i*2+2]);
        }
        int get_min(int a,int b,int k,int l,int r){
            if(r<=a||b<=l)return 1001001001;
            if(a<=l&&r<=b)return dat[k];
            return min(get_min(a,b,k*2+1,l,(l+r)/2),get_min(a,b,k*2+2,(l+r)/2,r));
        }
        int get_min(int a,int b){return get_min(a,b,0,0,N);}
    };
    public:
    segtree st;
    string s;
    vector<int>sa,lcp,rank;
    void init(string &t){
        s=t;
        sa_is(s);
        construct_lcp();
        st.init(lcp);
    }
    suffix_array(string &t){init(t);}
    suffix_array(){}

    bool contain(string &t){
        int lb=0,ub=s.size();
        while(ub-lb>1){
            int mid=(lb+ub)/2;
            if(s.compare(sa[mid],t.size(),t)<0)lb=mid;
            else ub=mid;
        }
        return s.compare(sa[ub],t.size(),t)==0;
    }

    int get_lcp(int i,int j){
        if(rank[i]>rank[j])swap(i,j);
        return st.get_min(rank[i],rank[j]);
    }
    int operator[](const int idx)const{
        return sa[idx];
    }
};


int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    string s; cin >> s;
    ll n = s.size();

    suffix_array rolling(s);
    reverse(s.begin(), s.end());
    suffix_array invroll(s);

    int64_t ans = 0;
    for (int i = 0; i < n + 1; i++) {
        ll xn = i, yn = n-i;
        if (xn <= yn) continue;
        if (xn < 3) continue;
        if (yn < 2) continue;

        int pref = min<ll>(rolling.get_lcp(0, i), yn-1);
        int suff = min<ll>(invroll.get_lcp(0, n-i), yn-1);

        ll diff = max<ll>(suff + pref - yn + 1, 0);
        ans += diff;
    }

    cout << ans << endl;
}
