#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

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

using ll = long long; using vll = vector<ll>; using vvll = vector<vll>; using P = pair<ll, ll>;
using ld = long double;  using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>; vll conv(vi& v) { vll r(v.size()); rep(i, v.size()) r[i] = v[i]; return r; }

inline void input(int &v){ v=0;char c=0;int p=1; while(c<'0' || c>'9'){if(c=='-')p=-1;c=getchar();} while(c>='0' && c<='9'){v=(v<<3)+(v<<1)+c-'0';c=getchar();} v*=p; }
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template<size_t...> struct seq{}; template<size_t N, size_t... Is> struct gen_seq : gen_seq<N-1, N-1, Is...>{}; template<size_t... Is> struct gen_seq<0, Is...> : seq<Is...>{};
template<class Ch, class Tr, class Tuple, size_t... Is>
void print_tuple(basic_ostream<Ch,Tr>& os, Tuple const& t, seq<Is...>){ using s = int[]; (void)s{0, (void(os << (Is == 0? "" : ", ") << get<Is>(t)), 0)...}; }
template<class Ch, class Tr, class... Args> 
auto operator<<(basic_ostream<Ch, Tr>& os, tuple<Args...> const& t) -> basic_ostream<Ch, Tr>& { os << "("; print_tuple(os, t, gen_seq<sizeof...(Args)>()); return os << ")"; }
ostream &operator<<(ostream &o, const vvll &v) { rep(i, v.size()) { rep(j, v[i].size()) o << v[i][j] << " "; o << endl; } return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T> ostream &operator<<(ostream &o, const deque<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const unordered_set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U, typename V>  ostream &operator<<(ostream &o, const unordered_map<T, U, V> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it; o << "]";  return o; }
vector<int> range(const int x, const int y) { vector<int> v(y - x + 1); iota(v.begin(), v.end(), x); return v; }
template <typename T> istream& operator>>(istream& i, vector<T>& o) { rep(j, o.size()) i >> o[j]; return i;}
template <typename T, typename S, typename U> ostream &operator<<(ostream &o, const priority_queue<T, S, U> &v) { auto tmp = v; while (tmp.size()) { auto x = tmp.top(); tmp.pop(); o << x << " ";} return o; }
template <typename T> ostream &operator<<(ostream &o, const queue<T> &v) { auto tmp = v; while (tmp.size()) { auto x = tmp.front(); tmp.pop(); o << x << " ";} return o; }
template <typename T> ostream &operator<<(ostream &o, const stack<T> &v) { auto tmp = v; while (tmp.size()) { auto x = tmp.top(); tmp.pop(); o << x << " ";} return o; }
template <typename T> unordered_map<T, ll> counter(vector<T> vec){unordered_map<T, ll> ret; for (auto&& x : vec) ret[x]++; return ret;};
string substr(string s, P x) {return s.substr(x.fi, x.se - x.fi); }
void vizGraph(vvll& g, int mode = 0, string filename = "out.png") { ofstream ofs("./out.dot"); ofs << "digraph graph_name {" << endl; set<P> memo; rep(i, g.size())  rep(j, g[i].size()) { if (mode && (memo.count(P(i, g[i][j])) || memo.count(P(g[i][j], i)))) continue; memo.insert(P(i, g[i][j])); ofs << "    " << i << " -> " << g[i][j] << (mode ? " [arrowhead = none]" : "")<< endl;  } ofs << "}" << endl; ofs.close(); system(((string)"dot -T png out.dot >" + filename).c_str()); }
size_t random_seed; namespace std { using argument_type = P; template<> struct hash<argument_type> { size_t operator()(argument_type const& x) const { size_t seed = random_seed; seed ^= hash<ll>{}(x.fi); seed ^= (hash<ll>{}(x.se) << 1); return seed; } }; }; // hash for various class
struct timeval start; double sec() { struct timeval tv; gettimeofday(&tv, NULL); return (tv.tv_sec - start.tv_sec) + (tv.tv_usec - start.tv_usec) * 1e-6; }
struct init_{init_(){ ios::sync_with_stdio(false); cin.tie(0); gettimeofday(&start, NULL); struct timeval myTime; struct tm *time_st; gettimeofday(&myTime, NULL); time_st = localtime(&myTime.tv_sec); srand(myTime.tv_usec); random_seed = RAND_MAX / 2 + rand() / 2; }} init__;
uint32_t randxor() { static uint32_t x=1+(uint32_t)random_seed,y=362436069,z=521288629,w=88675123; uint32_t t; t=(x^(x<<11));x=y;y=z;z=w; return( w=(w^(w>>19))^(t^(t>>8)) ); }
#define rand randxor
#define ldout fixed << setprecision(40) 

#define EPS (double)1e-14
#define INF (ll)1e18
#define mo  (ll)(1e9+7)

// Double.cpp
// 多倍長小数クラス
//============================================================================//
// 更新：02/12/26(木)
// 概要：なし。
// 補足：なし。
//============================================================================//

class Double
{
	double	dblMantissa ;	// 仮数
	int	intExponent ;	// 指数

public:
// コンストラクタおよびデストラクタ
	Double( double = 0) ;
	Double( const Double&) ;
	~Double() ;

// 設定
	void SetDouble( double) ;
private:
	void Validate( double) ;


// 演算
	friend ostream &operator<<(ostream &, const Double &);
	friend istream &operator>>(istream &, Double &);
	friend const Double operator+(const Double &, const Double &) ;
	friend const Double operator-(const Double &, const Double &) ;
	friend const Double operator*(const Double &, const Double &) ;
	friend const Double operator/(const Double &, const Double &) ;
	friend bool operator==(const Double &, const Double &);
	friend bool operator==(const Double &, double);
	friend bool operator==(double, const Double &);
	friend bool operator!=(const Double &, const Double &);
	friend bool operator!=(const Double &, double);
	friend bool operator!=(double, const Double &);

public:
	Double& operator=( const Double&);
    Double& operator=( const int&);
	Double& operator+=(const Double&);
	Double& operator-=(const Double&);
	Double& operator*=(const Double&);
	Double& operator/=(const Double&);
	operator double() const ;
} ;



/******************************************************************************/
//		コンストラクタおよびデストラクタ
/******************************************************************************/
// コンストラクタ
//============================================================================//
// 更新：02/12/25(水)
// 概要：なし。
// 補足：なし。
//============================================================================//

Double::Double( double d) 
{
	SetDouble( d) ;
}


/******************************************************************************/
// コピーコンストラクタ
//============================================================================//
// 更新：02/12/26(木)
// 概要：なし。
// 補足：なし。
//============================================================================//

Double::Double( const Double& d)
: dblMantissa( d.dblMantissa), intExponent( d.intExponent)
{
}


/******************************************************************************/
// デストラクタ
//============================================================================//
// 更新：02/12/25(水)
// 概要：なし。
// 補足：なし。
//============================================================================//

Double::~Double() 
{
}



/******************************************************************************/
//		設定
/******************************************************************************/
// double から設定
//============================================================================//
// 更新：02/12/25(水)
// 概要：なし。
// 補足：なし。
//============================================================================//

void Double::SetDouble( double d)
{
	intExponent = 0 ;
	Validate( d) ;
}


/******************************************************************************/
// 仮数部を正当な値にする
//============================================================================//
// 更新：02/12/26(木)
// 概要：1.0 <= 仮数部 < 10.0 を満たすようにする。
// 補足：なし。
//============================================================================//

void Double::Validate( double d)
{
	// d が 0 の時は特別扱い
	if( d == 0)
	{
		dblMantissa = 0 ;
		intExponent = 0 ;
		return ;
	}

	double dblAbs = ( d > 0 ? d : -d) ;
	if( dblAbs >= 10.0)
	{
		while( dblAbs > 10.0)
		{
			dblAbs /= 10.0 ;
			intExponent++ ;
		}
	}
	else if( dblAbs < 1.0)
	{
		while( dblAbs < 1.0)
		{
			dblAbs *= 10.0 ;
			intExponent-- ;
		}
	}

	dblMantissa = ( d > 0 ? dblAbs : -dblAbs) ;
}


/******************************************************************************/
//		演算子
/******************************************************************************/
// 出力
//============================================================================//
// 更新：02/12/25(水)
// 概要：なし。
// 補足：なし。
//============================================================================//

ostream &operator<<(ostream& stream, const Double& d)
{
	ios_base::fmtflags iosOldSetting = cout.flags() ;
	cout.setf( ios::showpoint) ;
	cout.setf(ios::fixed) ;
	cout.precision(40) ;
	cout.width( 8) ;
	stream << d.dblMantissa << "e" << d.intExponent ;
	cout.flags( iosOldSetting) ;
	return stream ;
}


/******************************************************************************/
// 入力
//============================================================================//
// 更新：02/12/25(水)
// 概要：なし。
// 補足：とりあえずは一端 double で取り込む。
//============================================================================//

istream &operator>>(istream& stream, Double& dbl)
{
	double d ;
	stream >> d ;
	dbl.SetDouble( d) ;
	return stream ;
}


/******************************************************************************/
// 加算
//============================================================================//
// 更新：02/12/26(木)
// 概要：なし。
// 補足：なし。
//============================================================================//

const Double operator+(const Double& left, const Double& right)
{
	Double d = left ;
	d += right ;

	return d ;
}


/******************************************************************************/
// 減算
//============================================================================//
// 更新：02/12/26(木)
// 概要：なし。
// 補足：なし。
//============================================================================//

const Double operator-(const Double& left, const Double& right)
{
	Double d = left ;
	d -= right ;

	return d ;
}


/******************************************************************************/
// 乗算
//============================================================================//
// 更新：02/12/25(水)
// 概要：なし。
// 補足：*= を使って実装。
//============================================================================//

const Double operator*(const Double& left, const Double& right)
{
	Double dblRet = left ;
	dblRet *= right ;
	return dblRet ;
}


/******************************************************************************/
// 除算
//============================================================================//
// 更新：02/12/25(水)
// 概要：なし。
// 補足：*= を使って実装。
//============================================================================//

const Double operator/(const Double& left, const Double& right)
{
	Double dblRet = left ;
	dblRet /= right ;
	return dblRet ;
}


/******************************************************************************/
// 等しいか
//============================================================================//
// 更新：02/12/26(木)
// 概要：なし。
// 補足：なし。
//============================================================================//

bool operator==( const Double& left, const Double& right)
{
	if( left.dblMantissa == 0)
	{
		return right.dblMantissa == 0 ;
	}
	else
	{
		return left.intExponent == right.intExponent && left.dblMantissa == right.dblMantissa ;
	}
}

bool operator==( const Double& left, double right)
{
	return left == Double( right) ;
}

bool operator==( double& left, const Double& right)
{
	return Double( left) == right ;
}


/******************************************************************************/
// 等しくないか
//============================================================================//
// 更新：02/12/26(木)
// 概要：なし。
// 補足：なし。
//============================================================================//

bool operator!=( const Double& left, const Double& right)
{
	return !( left == right) ;
}

bool operator!=( const Double& left, double right)
{
	return left != Double( right) ;
}

bool operator!=( double left, const Double& right)
{
	return Double( left) != right ;
}


/******************************************************************************/
//		メンバ関数の演算子オーバーロード
/******************************************************************************/
// 代入演算子
//============================================================================//
// 更新：02/12/26(木)
// 概要：なし。
// 補足：なし。
//============================================================================//

Double& Double::operator=( const Double& d)
{
	dblMantissa = d.dblMantissa ;
	intExponent = d.intExponent ;

	return *this ;
}
Double& Double::operator=( const int& n)
{
    Double d = (Double)n;
	dblMantissa = d.dblMantissa ;
	intExponent = d.intExponent ;

	return *this ;
}



/******************************************************************************/
// 加算代入
//============================================================================//
// 更新：02/12/26(木)
// 概要：なし。
// 補足：加算時は大きい方にあわせるべし。
//============================================================================//

Double& Double::operator+=( const Double& right)
{
	// どちらかが 0 の時は特別
	if( dblMantissa == 0)
	{
		intExponent = right.intExponent ;
		dblMantissa = right.dblMantissa ;
		return *this ;
	}
	else if( right.dblMantissa == 0)
	{
		return *this ;
	}

	// 左辺が大きいとき
	if( intExponent >= right.intExponent)
	{
		double dblRightMantissa = right.dblMantissa ;
		for( int i = 0; i < intExponent - right.intExponent; i++)
		{
			dblRightMantissa /= 10.0 ;
		}

		dblMantissa += dblRightMantissa ;
	}
	// 右辺が大きいとき
	else
	{
		for( int i = 0; i < right.intExponent - intExponent; i++)
		{
			dblMantissa /= 10.0 ;
		}
		intExponent = right.intExponent ;
		dblMantissa += right.dblMantissa ;
	}

	Validate( dblMantissa) ;

	return *this ;
}


/******************************************************************************/
// 減算代入
//============================================================================//
// 更新：02/12/26(木)
// 概要：なし。
// 補足：なし。
//============================================================================//

Double& Double::operator-=(const Double& d)
{
	dblMantissa *= -1.0 ;
	*this += d ;
	dblMantissa *= -1.0 ;

	return *this ;
}


/******************************************************************************/
// 乗算代入
//============================================================================//
// 更新：02/12/26(木)
// 概要：なし。
// 補足：なし。
//============================================================================//

Double& Double::operator*=( const Double& right)
{
	intExponent += right.intExponent ;
	Validate( dblMantissa * right.dblMantissa) ;

	return *this ;
}


/******************************************************************************/
// 除算代入
//============================================================================//
// 更新：02/12/26(木)
// 概要：なし。
// 補足：ごめんやる気ない（藁。
//============================================================================//

Double& Double::operator/=( const Double& right)
{
	if( right.dblMantissa == 0)
	{
		cout << "Double : 0 divide exception.\n" ;
		abort() ;
	}

	intExponent -= right.intExponent ;
	Validate( dblMantissa / right.dblMantissa) ;

	return *this ;
}


/******************************************************************************/
// キャスト演算子
//============================================================================//
// 更新：02/12/26(木)
// 概要：なし。
// 補足：なし。
//============================================================================//

Double::operator double() const
{
	double d = dblMantissa ;
	int i = intExponent ;

	while( i != 0)
	{
		if( i > 0)
		{
			d *= 10.0 ;
			i-- ;
		}
		else
		{
			d /= 10.0 ;
			i++ ;
		}
	}

	return d ;
}





int main(void) {
    Double a = 300;
    cout << a << endl;

    Double b = 10;
    cout << b / a << endl;
    cout << b * a << endl;
    cout << b - a << endl;
    cout << b + a << endl;

    double x = 10;
    Double c;
    c = x;
    cout << c << endl;

    vll Ncands = {100, 100000};
    ll cyc = 100;
    for (auto N : Ncands) {
        {
            vector<Double> v(N); 
            rep(i, v.size() / 2) {
                Double tmp = (Double)(rand() + 1) / (Double)100;
                v[2*i] = tmp;
                v[2*i+1] = (Double)1 / tmp;
            }
            Double ret = 1;
            rep(_, cyc) {
                random_shuffle(all(v));
                for (auto x : v) {
                    ret *= x;
                }
            }
            cout << ret << endl;
        }
        {
            vector<double> v(N); 
            rep(i, v.size() / 2) {
                double tmp = (double)(rand() + 1) / (double)100;
                v[2*i] = tmp;
                v[2*i+1] = (double)1 / tmp;
            }
            double ret = 1;
            rep(_, cyc) {
                random_shuffle(all(v));
                for (auto x : v) {
                    ret *= x;
                }
            }
            cout << ldout << endl;
            cout << ret << endl;
        }
    }




    return 0;
}
