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

template <class BidirectionalIterator>
bool next_combination (BidirectionalIterator first1,
        BidirectionalIterator last1,
        BidirectionalIterator first2,
        BidirectionalIterator last2)
{
    if ((first1 == last1) || (first2 == last2)) {
        return false;
    }
    BidirectionalIterator m1 = last1;
    BidirectionalIterator m2 = last2; --m2;
    while (--m1 != first1 && !(*m1 <*m2)){
    }
    bool result = (m1 == first1) && !(*first1 <*m2);
    if (!result) {
        while (first2 != m2 && !(*m1 <*first2)) {
            ++first2;
        }
        first1 = m1;
        std::iter_swap(first1, first2);
        ++first1;
        ++first2;
    }
    if ((first1 != last1) && (first2 != last2)) {
        m1 = last1; m2 = first2;
        while ((m1 != first1) && (m2 != last2)) {
            std::iter_swap(--m1, m2);
            ++m2;
        }
        std::reverse(first1, m1);
        std::reverse(first1, last1);
        std::reverse(m2, last2);
        std::reverse(first2, last2);
    }
    return !result;
}

template <class BidirectionalIterator>
bool next_combination (BidirectionalIterator first,
        BidirectionalIterator middle,
        BidirectionalIterator last)
{
    return next_combination (first, middle, middle, last);
}
template <class BidirectionalIterator>
    inline
bool prev_combination (BidirectionalIterator first,
        BidirectionalIterator middle,
        BidirectionalIterator last)
{
    return next_combination (middle, last, first, middle);
}


/*
    const int n = 6, r = 3;
    std::vector<int> data(n);

    // Next Permutation
    for(int i=0; i<n; i++){ data[i]=i; }
    while (1) {
        for(unsigned int i=0; i<n; ++i)
            cout <<data[i]<<" ";
        cout << endl;
        if (!next_permutation(data.begin(), data.end()))
            break;
    }
    cout << endl;


    // Next Combination
    for(int i=0; i<n; i++){ data[i]=i; }
    while (1) {
        for(unsigned int i=0; i<r; ++i)
            cout <<data[i]<<" ";
        cout << endl;
        if (!next_combination(data.begin(), data.begin()+r, data.end()))
            break;
    }
    cout << endl;

    */

ll n_, m_;
bool f(vll& h, ll lnum) {
    ll dh = 0;
    rep(i, lnum) 
        dh += h[i] * pow(7, i);
    ll dm = 0;
    for (int i = lnum; i < h.size(); i++) 
        dm += h[i] * pow(7, i-lnum);

//    cout << dh << " " << dm << endl;
    return dh < n_ && dm < m_;

}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n, m; cin >> n >> m;
    n_ = n; m_ = m;

    n--, m--;
    ll lnum = 0;
    ll rnum = 0;
    while(n) n/=7, lnum++;
    while(m) m/=7, rnum++;
    chmax(lnum, 1);
    chmax(rnum, 1);
    
    if (lnum+rnum>7) {
        cout << 0 << endl; 
        return 0;
    }
    // Next Combination
    vll data(7);
    ll ret = 0;
    for(int i=0; i<data.size(); i++){ data[i]=i; }
    while (1) {
        // s: 使う数字
        vll s(lnum+rnum);
        rep(i, s.size()) s[i] = data[i];

        // Next Permutation
        while (1) {
            /*
            cout << s;
            if (f(s, lnum))
                cout << "#hit";
            cout << endl;
            */
            ret += f(s, lnum);
            if (!next_permutation(s.begin(), s.end()))
                break;
        }

        /*
        for(unsigned int i=0; i<(lnum+rnum); ++i)
            cout <<data[i]<<" ";
        cout << endl;
        */
        if (!next_combination(data.begin(), data.begin()+(lnum+rnum), data.end()))
            break;
    }
    cout << ret << endl;


    return 0;
}
