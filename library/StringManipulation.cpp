#include <bits/stdc++.h>
using namespace std;

#ifdef _WIN32
#define scanfll(x) scanf("%I64d", x)
#define printfll(x) printf("%I64d", x)
#else
#define scanfll(x) scanf("%lld", x)
#define printfll(x) printf("%lld", x)
#endif
#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define repi(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mt make_tuple
#define mp make_pair
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

using ll = long long; using ld = long double; using vll = vector<ll>; using vvll = vector<vll>; using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>;
vll conv(vi& v) { vll r(v.size()); rep(i, v.size()) r[i] = v[i]; return r; }
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
void printbits(ll mask, ll n) { rep(i, n) { cout << !!(mask & (1ll << i)); } cout << endl; }
#define ldout fixed << setprecision(40) 

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;

// Z Algorithm
// オリジナル：各iについて「S と S[i:|S|-1] の最長共通接頭辞の長さ」を計算
// 構築 O(s)
// 0-index LCP O(1)
//
// しかしこれだけで使ってもあまり嬉しくない。
// マッチングする文字列tが一個だけの場合、t+sに対してZ Algorithmを構築することで、
// 各iについて「T と S[i:|S|-1] の最長共通接頭辞の長さ」を計算できる
// 構築 O(s+t)
// 最長共通Suffix計算 O(1)
class ZAlgorithm {
public:
    string s;
    vector<int> z;
    int s_length = 0;
    int t_length = 0;
    bool m_matching_flag = true;
    
    // 構築
    // 事前にsに代入されていることが前提
    //
    // O(|s|)
    void construct(void) {
        ll n = s.size();
        z.assign(n, 0);

        z[0] = n;
        int i = 1, j = 0;
        while (i < n) {
            while (i+j < n && s[j] == s[i+j]) ++j;
            z[i] = j;
            if (j == 0) { ++i; continue;}
            int k = 1;
            while (i+k < n && k+z[k] < j) z[i+k] = z[k], ++k;
            i += k; j -= k;
        }
    }
    // SとS[i:end]のマッチング
    ZAlgorithm(string& s_) : s_length(s_.length()) {
        s = s_;
        construct();
    }
    // TとS[i:end]のマッチング
    ZAlgorithm(string& s_, string& t_) : s_length(s_.length()), t_length(t_.length()) {
        m_matching_flag = true;
        s = t_ + s_;
        construct();
    }
    // SとS[i:end]のマッチング、もしくはTとS[i:end]の最長マッチング数を返す
    ll lcp(ll i) {
        if (!m_matching_flag) {
            return z[i];
        } else {
            return min(z[i + t_length], t_length);
        }
    }
};

// SA-IS
// マッチングする文字列t1, t2...の場合、t1+t2+...+tn+sに対してSA-ISを構築する
//
// 構築 O(n), 
// i-index LCP O(log n) (本来O(log log n)だがこの実装ではRMQのメモリ削減のためSegment Treeを使っているので)
// contain O(log n)
class SuffixArray{
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

    vector<int> sa_is(string &s){
        vector<int> v(s.size()+1);
        for(int i=0;i<s.size();i++)v[i]=s[i];
        return sa=sa_is(v,*max_element(v.begin(),v.end()));
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

#define INT_INF 1001001001
    struct segtree{
        int N;
        vector<int>dat;
        void init(vector<int> &v){
            for(N=1;N<v.size();N<<=1);
            dat.resize(N*2,INT_INF);
            for(int i=0;i<v.size();i++)dat[i+N-1]=v[i];
            for(int i=N-2;i>=0;i--)dat[i]=min(dat[i*2+1],dat[i*2+2]);
        }
        int get_min(int a,int b,int k,int l,int r){
            if(r<=a||b<=l)return INT_INF;
            if(a<=l&&r<=b)return dat[k];
            return min(get_min(a,b,k*2+1,l,(l+r)/2),get_min(a,b,k*2+2,(l+r)/2,r));
        }
        int get_min(int a,int b){return get_min(a,b,0,0,N);}
    };
    public:
    segtree st;
    string s;
    vector<int>sa,lcp,rank;
    void init(const string &t){
        s=t;
        sa_is(s);
        construct_lcp();
        st.init(lcp);
    }
    SuffixArray(const string &t){init(t);}
    SuffixArray(){}

    // s[0:end]に文字列tが含まれているかを判定
    //
    // O(log n)
    bool contain(const string &t){
        int lb=0,ub=s.size();
        while(ub-lb>1){
            int mid=(lb+ub)/2;
            if(s.compare(sa[mid],t.size(),t)<0)lb=mid;
            else ub=mid;
        }
        return s.compare(sa[ub],t.size(),t)==0;
    }

    // s[i:end]とs[j:end]の最長共通文字列長を返す
    //
    // sa.getLcp(i, j) == sa.getLcp(j, i)
    // sa.getLcp(i, i) == INT_INF
    //
    // O(log n), seg木実装では、この実装はこっち
    // O(log log n), Sparse Table実装では (MLEするので非推奨)
    int getLcp(int i,int j){
        if(rank[i]>rank[j])swap(i,j);
        return st.get_min(rank[i],rank[j]);
    }

    // sa[idx]: 辞書順でidx番目の接頭辞文字列
    // つまり、|s|個の[sa[idx]:end]を辞書順ソートしたidx番目
    int operator[](const int idx)const{
        return sa[idx];
    }
};

vll manacher(string S) {
    vll R(S.length());
    int i = 0, j = 0;
    while (i < S.size()) {
        while(i-j >= 0 && i+j < S.size() && S[i-j] == S[i+j]) ++j;
        R[i] = j;
        int k = 1;
        while(i-k >= 0 && i+k < S.size() && k+R[i-k] < j) R[i+k] = R[i-k], ++k;
        i += k; j -= k;
    }
    return R;
}

// ローリングハッシュ
// 構築 O(n)
// ハッシュ計算 O(1)
// 最長共通Suffix計算 O(log n)
//
// 文字列を、hs[i+1] = hs[i] * b + s[i] (mod m)によってハッシュする。
class RollingHash {
    private:
        vector<long long> mod; // ハッシュなので、複数種類のmodで強化する
        void init() {
            rep(i, 1) 
                mod.push_back(1000000009LL + (i != 0) * (rand() % 100000ll));
        }
        const long long b = 1000000007LL; // 素数が望ましい
        int n;

        // hs: 文字列のローリングハッシュ値
        // hs: hs[i+1] = hs[i] * b + s[i] (mod m)
        // s = "xyzw"
        // ""     hs[0] = 0 
        // "x"    hs[1] = x * b^0 
        // "xy"   hs[2] = x * b^1 + y * b^0
        // "xyz"  hs[3] = x * b^2 + y * b^1 + z * b^0
        // "xyzw" hs[4] = x * b^3 + y * b^2 + z * b^1 + w * b^0
        // "yz"   y * b^1 + z * b^0 = hs[3] - hs[1] * b^2
        vector<vector<long long>> hs;
        // pw: b^n (mod m)
        vector<vector<long long>> pw;

    public:
        // ローリングハッシュ構築
        // O(n)
        RollingHash(const string &s) : n(s.size()) {
            init();
            hs.resize(mod.size()), pw.resize(mod.size());
            for (int m = 0; m < mod.size(); m++) {
                hs[m].assign(n + 1, 0), pw[m].assign(n + 1, 0);
                hs[m][0] = 0, pw[m][0] = 1;
                for (int j = 0; j < n; j++) {
                    pw[m][j + 1] = pw[m][j] * b % mod[m];
                    hs[m][j + 1] = (hs[m][j] * b + s[j]) % mod[m];
                }
            }
        }

        // 部分文字列[l, r)のローリングハッシュ値計算
        // O(1)
        inline long long hash(int l, int r, int m) {
            return ((hs[m][r] - hs[m][l] * pw[m][r - l]) % mod[m] + mod[m]) % mod[m];
        }

        // 文字列の一致判定
        // O(1)
        // l1から始まるk文字の文字列と、l2から始まるk文字の文字列が一致すればtrue
        inline bool match(int l1, int l2, int k) {
            for (int m = 0; m < mod.size(); m++) 
                if (hash(l1, l1 + k, m) != hash(l2, l2 + k, m))
                    return false;
            return true;
        }

        // 最長共通Prefix
        // O(log n)
        // s[i]から始まる文字列と、s[j]から始まる文字列で、連続文字列長を計算
        // ハッシュ値の一致は、1111100000という単調性があるので、二分探索可能
        int lcp(int i, int j) {
            int l = 0, r = min(n - i, n - j) + 1;
            while (l + 1 < r) {
                int m = (l + r) / 2;
                (match(i, j, m) ? l : r) = m;
            }
            return l;
        }
};



vll MP(string S) {
    vll A(S.length());
    A[0] = -1;
    int j = -1;
    for (int i = 0; i < S.size(); i++) {
        while (j >= 0 && S[i] != S[j]) j = A[j];
        j++;
        A[i+1] = j;
    }
    return A;
}

const ll NO_INPUT = -1;
const ll LEADING_ZERO = -2;
const ll OVERFLOW_DETECTED = -3;
const ll NOT_A_NUMBER = -4;
// stollで、オーバーフローと入力なしとリーディング0を許容しないもの。
ll stoll_no_leading_zero(string s) {
    if (!s.size()) return NO_INPUT;
    if (!all_of(all(s), [&](ll x){return '0'<=x&&x<='9';})) return NOT_A_NUMBER;
    if (s.size() > 1 && s[0] == '0') return LEADING_ZERO;
    if (stod(s) > LLONG_MAX) return OVERFLOW_DETECTED;
    return stoll(s);
}
// stollで、オーバーフローと入力なしを許容しないもの。
ll stoll_permitting_leading_zero(string s) {
    if (!s.size()) return NO_INPUT;
    if (!all_of(all(s), [&](ll x){return '0'<=x&&x<='9';})) return NOT_A_NUMBER;
    if (stod(s) > LLONG_MAX) return OVERFLOW_DETECTED;
    return stoll(s);
}

int main(void) {
    // ZAlgorithm
    {
        cin.tie(0); ios::sync_with_stdio(false);
        string s = "aaaabssss";
        string t = "abs";
        ZAlgorithm z(s, t);
        rep(i, s.length()) {
            cout << z.lcp(i) << endl;
        }
    }


    // SA-IS
    {
        string s = "aabsababaaa";

        SuffixArray sa(s);
        rep(i, s.length()) {
            rep(j, s.length()) {
                cout << sa.getLcp(i, j) << " "; 
            }
            cout << endl;
        }

        string t;
        t = "abs"; cout << sa.contain(t) << endl;
        t = "axs"; cout << sa.contain(t) << endl;

        rep(i, sa.sa.size()) {
            cout << s.substr(sa[i]) << endl;
        } 

    }

    // Rolling Hash
    {
        string s = "aaabaabaaaaaaaa";
        RollingHash rolling(s);

        vector<P> input = {P(0, 3), P(7, 10), P(2, 4), P(5, 7)};
        rep(i, input.size()) {
            ll l = input[i].fi, r = input[i].se;
            cout << rolling.hash(l, r, 0) << endl; 
        }
    }

    // stoll
    {
        cout << "####" << endl;
        cout << stoll_no_leading_zero("") << endl;
        cout << stoll_no_leading_zero("12a854321") << endl;
        cout << stoll_no_leading_zero("12") << endl;
        cout << stoll_no_leading_zero("012") << endl;
        cout << stoll_no_leading_zero("0") << endl;
        cout << stoll_no_leading_zero("39857893275") << endl;
        cout << stoll_no_leading_zero("9869048328802353780942329058340") << endl;
        cout << stoll("9869048328802353780942329058340") << endl;;
    }

    return 0;
}
