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
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
#define exists find_if
#define forall all_of

using ll = long long; using vll = vector<ll>; using vvll = vector<vll>; using P = pair<ll, ll>;
using ld = long double;  using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>; vll conv(vi& v) { vll r(v.size()); rep(i, v.size()) r[i] = v[i]; return r; }
using Pos = complex<double>;

namespace std{ namespace { template <class T> inline void hash_combine(size_t& seed, T const& v) { seed ^= hash<T>()(v) + 0x9e3779b9 + (seed<<6) + (seed>>2); } template <class Tuple, size_t Index = tuple_size<Tuple>::value - 1> struct HashValueImpl { static void apply(size_t& seed, Tuple const& tuple) { HashValueImpl<Tuple, Index-1>::apply(seed, tuple); hash_combine(seed, get<Index>(tuple)); } }; template <class Tuple> struct HashValueImpl<Tuple,0> { static void apply(size_t& seed, Tuple const& tuple) { hash_combine(seed, get<0>(tuple)); } }; } template <typename ... TT> struct hash<tuple<TT...>> { size_t operator()(tuple<TT...> const& tt) const { size_t seed = 0; HashValueImpl<tuple<TT...> >::apply(seed, tt); return seed; } }; } 
namespace std { template<typename U, typename V> struct hash<pair<U, V>> { size_t operator()(pair<U, V> const& v) const { return v.first ^ v.second; } }; } struct pairhash { public: template <typename T, typename U> size_t operator()(const pair<T, U> &x) const { return hash<T>()(x.first) ^ hash<U>()(x.second); } };

template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template<size_t...> struct seq{}; template<size_t N, size_t... Is> struct gen_seq : gen_seq<N-1, N-1, Is...>{}; template<size_t... Is> struct gen_seq<0, Is...> : seq<Is...>{};
template<class Ch, class Tr, class Tuple, size_t... Is>
void print_tuple(basic_ostream<Ch,Tr>& os, Tuple const& t, seq<Is...>){ using s = int[]; (void)s{0, (void(os << (Is == 0? "" : ", ") << get<Is>(t)), 0)...}; }
template<class Ch, class Tr, class... Args> 
auto operator<<(basic_ostream<Ch, Tr>& os, tuple<Args...> const& t) -> basic_ostream<Ch, Tr>& { os << "("; print_tuple(os, t, gen_seq<sizeof...(Args)>()); return os << ")"; }
ostream &operator<<(ostream &o, const vvll &v) { rep(i, v.size()) { rep(j, v[i].size()) o << v[i][j] << " "; o << endl; } return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const unordered_map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it; o << "]";  return o; }
vector<int> range(const int x, const int y) { vector<int> v(y - x + 1); iota(v.begin(), v.end(), x); return v; }
template <typename T> istream& operator>>(istream& i, vector<T>& o) { rep(j, o.size()) i >> o[j]; return i;}
string bits_to_string(ll input, ll n=64) { string s; rep(i, n) s += '0' + !!(input & (1ll << i)); return s; }
template <typename T> unordered_map<T, ll> counter(vector<T> vec){unordered_map<T, ll> ret; for (auto&& x : vec) ret[x]++; return ret;};
string substr(string s, P x) {return s.substr(x.fi, x.se - x.fi); }
struct ci : public iterator<forward_iterator_tag, ll> { ll n; ci(const ll n) : n(n) { } bool operator==(const ci& x) { return n == x.n; } bool operator!=(const ci& x) { return !(*this == x); } ci &operator++() { n++; return *this; } ll operator*() const { return n; } };

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;
#define ldout fixed << setprecision(40) 

// https://github.com/togasakih/Togasat
namespace togasat {
using Var = int;
using CRef = int;
using lbool = int;
const CRef CRef_Undef = INT32_MAX;
class Solver {

private:
  const lbool l_True = 0;
  const lbool l_False = 1;
  const lbool l_Undef = 2;

  const int var_Undef = -1;

  // Literal
  struct Lit {
    int x;
    inline bool operator==(Lit p) const { return x == p.x; }
    inline bool operator!=(Lit p) const { return x != p.x; }
    inline bool operator<(Lit p) const { return x < p.x; }
    inline Lit operator~() {
      Lit q;
      q.x = x ^ 1;
      return q;
    }
  };

  inline Lit mkLit(Var var, bool sign) {
    Lit p;
    p.x = var + var + sign;
    return p;
  };
  inline bool sign(Lit p) const { return p.x & 1; }
  inline int var(Lit p) const { return p.x >> 1; }
  inline int toInt(Var v) { return v; }
  inline int toInt(Lit p) { return p.x; }
  inline Lit toLit(int x) {
    Lit p;
    p.x = x;
    return p;
  }
  const Lit lit_Undef = {-2};
  const Lit lit_Error = {-1};

  // lifted boolean
  // VarData
  struct VarData {
    CRef reason;
    int level;
  };
  inline VarData mkVarData(CRef cr, int l) {
    VarData d = {cr, l};
    return d;
  }
  // Watcher
  struct Watcher {
    CRef cref;
    Lit blocker;
    Watcher() {}
    Watcher(CRef cr, Lit p) : cref(cr), blocker(p) {}
    bool operator==(const Watcher &w) const { return cref == w.cref; }
    bool operator!=(const Watcher &w) const { return cref != w.cref; }
  };

  // Clause
  class Clause {
  public:
    struct {
      bool learnt;
      int size;
    } header;
    std::vector<Lit> data; //(x1 v x2 v not x3)
    Clause() {}
    Clause(const std::vector<Lit> &ps, bool learnt) {
      header.learnt = learnt;
      header.size = ps.size();
      for (int i = 0; i < ps.size(); i++) {
        data.push_back(ps[i]);
      }
    }

    int size() const { return header.size; }
    bool learnt() const { return header.learnt; }
    Lit &operator[](int i) { return data[i]; }
    Lit operator[](int i) const { return data[i]; }
  };

  CRef alloc_clause(const std::vector<Lit> &ps, bool learnt = false) {
    static CRef res = 0;
    ca[res] = Clause(ps, learnt);
    return res++;
  }

  Var newVar(bool sign = true, bool dvar = true) {
    int v = nVars();

    assigns.push_back(l_Undef);
    vardata.push_back(mkVarData(CRef_Undef, 0));
    activity.push_back(0.0);
    seen.push_back(false);
    polarity.push_back(sign);
    decision.push_back(0);
    setDecisionVar(v, dvar);
    return v;
  }

  bool addClause_(std::vector<Lit> &ps) {
    std::sort(ps.begin(), ps.end());
    // empty clause
    if (ps.size() == 0) {
      return false;
    } else if (ps.size() == 1) {
      uncheckedEnqueue(ps[0]);
    } else {
      CRef cr = alloc_clause(ps, false);
      clauses.insert(cr);
      attachClause(cr);
    }

    return true;
  }
  void attachClause(CRef cr) {
    const Clause &c = ca[cr];

    assert(c.size() > 1);

    watches[(~c[0]).x].push_back(Watcher(cr, c[1]));
    watches[(~c[1]).x].push_back(Watcher(cr, c[0]));
  }

  // Input
  void readClause(const std::string &line, std::vector<Lit> &lits) {
    lits.clear();
    int parsed_lit, var;
    parsed_lit = var = 0;
    bool neg = false;
    std::stringstream ss(line);
    while (ss) {
      int val;
      ss >> val;
      if (val == 0)
        break;
      var = abs(val) - 1;
      while (var >= nVars()) {
        newVar();
      }
      lits.push_back(val > 0 ? mkLit(var, false) : mkLit(var, true));
    }
  }

  std::unordered_map<CRef, Clause> ca; // store clauses
  std::unordered_set<CRef> clauses;    // original problem;
  std::unordered_set<CRef> learnts;
  std::unordered_map<int, std::vector<Watcher>> watches;
  std::vector<VarData> vardata; // store reason and level for each variable
  std::vector<bool> polarity;   // The preferred polarity of each variable
  std::vector<bool> decision;
  std::vector<bool> seen;
  // Todo
  int qhead = 0;
  std::vector<Lit> trail;
  std::vector<int> trail_lim;
  // Todo rename(not heap)
  std::set<std::pair<double, Var>> order_heap;
  std::vector<double> activity;
  double var_inc;
  std::vector<Lit> model;
  std::vector<Lit> conflict;
  int nVars() const { return vardata.size(); }
  int decisionLevel() const { return trail_lim.size(); }
  void newDecisionLevel() { trail_lim.push_back(trail.size()); }

  inline CRef reason(Var x) const { return vardata[x].reason; }
  inline int level(Var x) const { return vardata[x].level; }
  inline void varBumpActivity(Var v){
    std::pair<double, Var> p = std::make_pair(activity[v], v);
    activity[v] += var_inc;
    if (order_heap.erase(p) == 1){
      order_heap.emplace(std::make_pair(activity[v], v));
    }
    
    if (activity[v] > 1e100){
      //Rescale
      std::set<std::pair<double,Var>> tmp_order;
      tmp_order = order_heap;
      order_heap.clear();
      for (int i = 0; i < nVars(); i++){
  activity[i] *= 1e-100;
      }
      for (auto &val : tmp_order){
  order_heap.emplace(std::make_pair(activity[val.first], val.first));
      }
      var_inc *= 1e-100;
    }

  }
  bool satisfied(const Clause &c) const {
    for (int i = 0; i < c.size(); i++) {
      if (value(c[i]) == l_True) {
        return true;
      }
    }
    return false;
  }
  lbool value(Var p) const { return assigns[p]; }
  lbool value(Lit p) const {
    if (assigns[var(p)] == l_Undef) {
      return l_Undef;
    }
    return assigns[var(p)] ^ sign(p);
  }
  void setDecisionVar(Var v, bool b) {
    decision[v] = b;
    order_heap.emplace(std::make_pair(0.0, v));
  }
  void uncheckedEnqueue(Lit p, CRef from = CRef_Undef) {
    assert(value(p) == l_Undef);
    assigns[var(p)] = sign(p);
    vardata[var(p)] = mkVarData(from, decisionLevel());
    trail.push_back(p);
  }
  // decision
  Lit pickBranchLit() {
    Var next = var_Undef;
    while (next == var_Undef or value(next) != l_Undef) {
      if (order_heap.empty()) {
        next = var_Undef;
        break;
      } else {
  auto p = *order_heap.rbegin();
        next = p.second;
        order_heap.erase(p);
      }
    }
    return next == var_Undef ? lit_Undef : mkLit(next, polarity[next]);
  }
  // clause learning
  void analyze(CRef confl, std::vector<Lit> &out_learnt, int &out_btlevel) {
    int pathC = 0;
    Lit p = lit_Undef;
    int index = trail.size() - 1;
    out_learnt.push_back(mkLit(0, false));
    do {
      assert(confl != CRef_Undef);
      Clause &c = ca[confl];
      for (int j = (p == lit_Undef) ? 0 : 1; j < c.size(); j++) {
        Lit q = c[j];
        if (not seen[var(q)] and level(var(q)) > 0) {
    varBumpActivity(var(q));
          seen[var(q)] = 1;
          if (level(var(q)) >= decisionLevel()) {
            pathC++;
          } else {
            out_learnt.push_back(q);
          }
        }
      }
      while (not seen[var(trail[index--])])
        ;
      p = trail[index + 1];
      confl = reason(var(p));
      seen[var(p)] = 0;
      pathC--;
    } while (pathC > 0);

    out_learnt[0] = ~p;

    // unit clause
    if (out_learnt.size() == 1) {
      out_btlevel = 0;
    } else {
      int max_i = 1;
      for (int i = 2; i < out_learnt.size(); i++) {
        if (level(var(out_learnt[i])) > level(var(out_learnt[max_i]))) {
          max_i = i;
        }
      }

      Lit p = out_learnt[max_i];
      out_learnt[max_i] = out_learnt[1];
      out_learnt[1] = p;
      out_btlevel = level(var(p));
    }

    for (int i = 0; i < out_learnt.size(); i++) {
      seen[var(out_learnt[i])] = false;
    }
  }

  // backtrack
  void cancelUntil(int level) {
    if (decisionLevel() > level) {
      for (int c = trail.size() - 1; c >= trail_lim[level]; c--) {
        Var x = var(trail[c]);
        assigns[x] = l_Undef;
        polarity[x] = sign(trail[c]);
        order_heap.emplace(std::make_pair(activity[x], x));
      }
      qhead = trail_lim[level];
      trail.erase(trail.end() - (trail.size() - trail_lim[level]), trail.end());
      trail_lim.erase(trail_lim.end() - (trail_lim.size() - level),
                      trail_lim.end());
    }
  }
  CRef propagate() {
    CRef confl = CRef_Undef;
    int num_props = 0;
    while (qhead < trail.size()) {
      Lit p = trail[qhead++]; // 'p' is enqueued fact to propagate.
      std::vector<Watcher> &ws = watches[p.x];
      std::vector<Watcher>::iterator i, j, end;
      num_props++;

      for (i = j = ws.begin(), end = i + ws.size(); i != end;) {
        // Try to avoid inspecting the clause:
        Lit blocker = i->blocker;
        if (value(blocker) == l_True) {
          *j++ = *i++;
          continue;
        }

        CRef cr = i->cref;
        Clause &c = ca[cr];
        Lit false_lit = ~p;
        if (c[0] == false_lit)
          c[0] = c[1], c[1] = false_lit;
        assert(c[1] == false_lit);
        i++;

        Lit first = c[0];
        Watcher w = Watcher(cr, first);
        if (first != blocker && value(first) == l_True) {
          *j++ = w;
          continue;
        }

        // Look for new watch:
        for (int k = 2; k < c.size(); k++)
          if (value(c[k]) != l_False) {
            c[1] = c[k];
            c[k] = false_lit;
            watches[(~c[1]).x].push_back(w);
            goto NextClause;
          }
        *j++ = w;
        if (value(first) == l_False) { // conflict
          confl = cr;
          qhead = trail.size();
          while (i < end)
            *j++ = *i++;
        } else {
          uncheckedEnqueue(first, cr);
        }
      NextClause:;
      }
      int size = i - j;
      ws.erase(ws.end() - size, ws.end());
    }
    return confl;
  }

  static double luby(double y, int x) {

    // Find the finite subsequence that contains index 'x', and the
    // size of that subsequence:
    int size, seq;
    for (size = 1, seq = 0; size < x + 1; seq++, size = 2 * size + 1)
      ;

    while (size - 1 != x) {
      size = (size - 1) >> 1;
      seq--;
      x = x % size;
    }

    return pow(y, seq);
  }

  lbool search(int nof_conflicts) {
    int backtrack_level;
    std::vector<Lit> learnt_clause;
    learnt_clause.push_back(mkLit(-1, false));
    int conflictC = 0;
    while (true) {
      CRef confl = propagate();

      if (confl != CRef_Undef) {
        // CONFLICT
        conflictC++;
        if (decisionLevel() == 0)
          return l_False;
        learnt_clause.clear();
        analyze(confl, learnt_clause, backtrack_level);
        cancelUntil(backtrack_level);
        if (learnt_clause.size() == 1) {
          uncheckedEnqueue(learnt_clause[0]);
        } else {
          CRef cr = alloc_clause(learnt_clause, true);
          learnts.insert(cr);
          attachClause(cr);
          uncheckedEnqueue(learnt_clause[0], cr);
        }
  //varDecay
  var_inc *= 1.05;
      } else {
        // NO CONFLICT
        if ((nof_conflicts >= 0 and conflictC >= nof_conflicts)) {
          cancelUntil(0);
          return l_Undef;
        }
        Lit next = pickBranchLit();

        if (next == lit_Undef) {
          return l_True;
        }
        newDecisionLevel();
        uncheckedEnqueue(next);
      }
    }
  };

public:
  std::vector<lbool> assigns; // The current assignments (ex assigns[0] = 0 ->
                              // X1 = True, assigns[1] = 1 -> X2 = False)
  lbool answer;               // SATISFIBLE 0 UNSATISFIBLE 1 UNKNOWN 2
  Solver() { }
  Solver(int n) { for (int i = 0; i < n; i++) { vector<int> tmp = {i+1, -(i+1)}; addClause(tmp); } }
  void parse_dimacs_problem(std::string problem_name) {
    std::vector<Lit> lits;
    int vars = 0;
    int clauses = 0;
    std::string line;
    std::ifstream ifs(problem_name, std::ios_base::in);
    while (ifs.good()) {
      getline(ifs, line);
      if (line.size() > 0) {
        if (line[0] == 'p') {
          sscanf(line.c_str(), "p cnf %d %d", &vars, &clauses);
        } else if (line[0] == 'c' or line[0] == 'p') {
          continue;
        } else {
          readClause(line, lits);
          if (lits.size() > 0)
            addClause_(lits);
        }
      }
    }
    ifs.close();
  }
  lbool solve() {
    model.clear();
    conflict.clear();
    lbool status = l_Undef;
    answer = l_Undef;
    var_inc = 1.01;
    int curr_restarts = 0;
    double restart_inc = 2;
    double restart_first = 100;
    while (status == l_Undef) {
      double rest_base = luby(restart_inc, curr_restarts);
      status = search(rest_base * restart_first);
      curr_restarts++;
    }
    answer = status;
    return status;
  };

  void addClause(std::vector<int> &clause) {
    std::vector<Lit> lits;
    for (int i = 0; i < clause.size(); i++) {
      int var = abs(clause[i]) - 1;
      while (var >= nVars())
        newVar();
      lits.push_back(clause[i] > 0 ? mkLit(var, false) : mkLit(var, true));
    }
    addClause_(lits);
  }
  void print_answer() {
    if (answer == 0) {
      std::cout << "SAT" << std::endl;
      for (int i = 0; i < assigns.size(); i++) {
        if (assigns[i] == 0) {
          std::cout << (i + 1) << " ";
        } else {
          std::cout << -(i + 1) << " ";
        }
      }
      std::cout << "0" << std::endl;
    } else {
      std::cout << "UNSAT" << std::endl;
    }
  }
};
}

class Family {
    public:
        string isFamily(vector <int> a, vector <int> b) {
            ll n = a.size();
            togasat::Solver sat(n);
            rep(i, n) {
                vector<int> tmp;
                tmp = {1+a[i], 1+b[i]};
                sat.addClause(tmp);
                tmp = {-(1+a[i]), -(1+b[i])};
                sat.addClause(tmp);
            }
            ll ret = sat.solve();
            if (ret == 0) {
                sat.print_answer();
                return "Possible";
            } else {
                return "Impossible";
            }
        }
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit-pf 2.3.0
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, bool hasAnswer, string p2) {
    cout << "Test " << testNum << ": [" << "{";
    for (int i = 0; int(p0.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << p0[i];
    }
    cout << "}" << "," << "{";
    for (int i = 0; int(p1.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << p1[i];
    }
    cout << "}";
    cout << "]" << endl;
    Family *obj;
    string answer;
    obj = new Family();
    clock_t startTime = clock();
    answer = obj->isFamily(p0, p1);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << "\"" << p2 << "\"" << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << "\"" << answer << "\"" << endl;
    if (hasAnswer) {
        res = answer == p2;
    }
    if (!res) {
        cout << "DOESN'T MATCH!!!!" << endl;
    } else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
        cout << "FAIL the timeout" << endl;
        res = false;
    } else if (hasAnswer) {
        cout << "Match :-)" << endl;
    } else {
        cout << "OK, but is it right?" << endl;
    }
    cout << "" << endl;
    return res;
}
int main() {
    bool all_right;
    bool disabled;
    bool tests_disabled;
    all_right = true;
    tests_disabled = false;

    vector <int> p0;
    vector <int> p1;
    string p2;

    // ----- test 0 -----
    disabled = false;
    p0 = {-1,-1,0};
    p1 = {-1,-1,1};
    p2 = "Possible";
    all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, true, p2) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 1 -----
    disabled = false;
    p0 = {-1,-1,-1,-1,-1};
    p1 = {-1,-1,-1,-1,-1};
    p2 = "Possible";
    all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, true, p2) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 2 -----
    disabled = false;
    p0 = {-1,-1,0,0,1};
	p1 = {-1,-1,1,2,2};
	p2 = "Impossible";
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {-1,-1,-1,-1,1,-1,0,5,6,-1,0,3,8,6};
	p1 = {-1,-1,-1,-1,3,-1,4,6,5,-1,5,4,6,1};
	p2 = "Possible";
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {-1,-1,-1,2,2,-1,5,6,4,6,2,1,8,0,2,4,6,9,-1,16,-1,11};
	p1 = {-1,-1,-1,1,0,-1,1,4,2,0,4,8,2,3,0,5,14,14,-1,7,-1,13};
	p2 = "Impossible";
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	if (all_right) {
		if (tests_disabled) {
			cout << "You're a stud (but some test cases were disabled)!" << endl;
		} else {
			cout << "You're a stud (at least on given cases)!" << endl;
		}
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// PROBLEM STATEMENT
// A directed acyclic graph is a family graph if the following constraints are all satisfied:
// 
// The nodes of the graph are numbered 0 through N-1, for some positive N.
// Each node is either male or female.
// Each node either has no parents, or it has precisely two parents. (A parent of the node x is a node y such that there is an edge from y to x.)
// If a node has parents, their numbers are strictly smaller than the number of the node.
// If a node has parents, one of them must be male and the other female.
// 
// 
// You are given two vector <int>s parent1 and parent2 with N elements each.
// These describe one directed graph that resembles a family graph:
// For each i, node i has either two parents (in which case parent1[i] and parent2[i] are their numbers, and both of them are smaller than i), or it has no parents (in which case parent1[i] and parent2[i] are both -1).
// 
// Return "Possible" (quotes for clarity) if the given graph can be a family graph, and "Impossible" otherwise.
// 
// DEFINITION
// Class:Family
// Method:isFamily
// Parameters:vector <int>, vector <int>
// Returns:string
// Method signature:string isFamily(vector <int> parent1, vector <int> parent2)
// 
// 
// CONSTRAINTS
// -parent1 will contain between 1 and 100 elements, inclusive.
// -parent1 and parent2 will contain the same number of elements.
// -For each i, the i-th element (0-based) of parent1 will be between -1 and i-1, inclusive.
// -For each i, the i-th element (0-based) of parent2 will be between -1 and i-1, inclusive.
// -For each i, the i-th element of parent1 will be -1 if and only if the i-th element of parent2 is -1.
// -For each i, if the i-th element of parent1 is not -1, then the i-th element of parent1 and the i-th element of parent2 will be different.
// 
// 
// EXAMPLES
// 
// 0)
// {-1,-1,0}
// {-1,-1,1}
// 
// Returns: "Possible"
// 
// The parents of node 2 are nodes 0 and 1. Nodes 0 and 1 have no parents.
// 
// 1)
// {-1,-1,-1,-1,-1}
// {-1,-1,-1,-1,-1}
// 
// Returns: "Possible"
// 
// Nobody has any parents.
// 
// 2)
// {-1,-1,0,0,1}
// {-1,-1,1,2,2}
// 
// Returns: "Impossible"
// 
// Given that 0 and 1 have a child, their genders must be different. Given that 0 and 2 have a child, their genders must be different, too. Then, 1 and 2 must have the same gender, hence they cannot have a child together. Therefore, this cannot be a valid family graph.
// 
// 3)
// {-1,-1,-1,-1,1,-1,0,5,6,-1,0,3,8,6}
// 
// {-1,-1,-1,-1,3,-1,4,6,5,-1,5,4,6,1}
// 
// 
// Returns: "Possible"
// 
// 
// 
// 4)
// {-1,-1,-1,2,2,-1,5,6,4,6,2,1,8,0,2,4,6,9,-1,16,-1,11}
// {-1,-1,-1,1,0,-1,1,4,2,0,4,8,2,3,0,5,14,14,-1,7,-1,13}
// 
// Returns: "Impossible"
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
