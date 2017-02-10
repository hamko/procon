#include <bits/stdc++.h>
using namespace std;
static const double EPS = 1e-5;
#define EQ(a,b) (abs((a)-(b))<EPS)

#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define MOD 1000000007
template <class T, class LAMBDA> bool forall(T b, T e, LAMBDA l) { int faf = 1; for (T it = b; it != e; it++) { if (!l(it)) { faf = 0; break; } } return faf; }
template <class T, class LAMBDA> bool thereexists(T b, T e, LAMBDA l) { return !forall(b, e, [l](T it) {return !l(it);}); }

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<string> vs;

class BalancedStrings {
  public:
    vector<string> findAny(int n) {
        vector<string> ret(n);
        if (n <= 26) {
            rep(i, n) {
                ret[i] = "";
                ret[i] += (char)('a' + i);
            }
            return ret;
        }
        rep(i, n-2) {
            ret[i] = "";
            ret[i] += (char)('a' + (i % 22));
        }
        ll sim = 0;
        rep(i, n-2) rep(j, n-2) if (i > j) 
            if (ret[i] == ret[j])
                sim++;
        ll sim_org = sim;
        cout << sim << endl;

        ret[n-2] = "w";
        for (int i = 1; i < 100; i++) {
            if (sim == 0) break;
            if (i % 2) {
                ret[n-2] += "x";
            } else {
                ret[n-2] += "w";
            }
            sim--;
        }
        ret[n-1] = "y";
        for (int i = 1; i < 100; i++) {
            if (sim == 0) break;
            if (i % 2) {
                ret[n-1] += "z";
            } else {
                ret[n-1] += "y";
            }
            sim--;
        }

        ll ins = 0;
        rep(i, n) {
            rep(j, ret[i].size()-1) {
                if (ret[i][j] != ret[i][j+1])
                    ins++;
            }

        }
        assert(sim_org == ins);

        return ret;
    }
};

// CUT begin
ifstream data("BalancedStrings.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

template <typename T> string to_string(vector<T> ts) {
    stringstream s;
    s << "[ ";
    for (int i = 0; i < ts.size(); ++i) {
        if (i > 0) s << ", ";
        s << to_string(ts[i]);
    }
    s << " ]";
    return s.str();
}

bool do_test(int N, vector<string> __expected) {
    time_t startClock = clock();
    BalancedStrings *instance = new BalancedStrings();
    vector<string> __result = instance->findAny(N);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        int N;
        from_stream(N);
        next_line();
        vector<string> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(N, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1486641933;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    rep(i, 101) if (i) {
        BalancedStrings *instance = new BalancedStrings();
        vector<string> __result = instance->findAny(i);
    }
    /*
       cout.setf(ios::fixed, ios::floatfield);
       cout.precision(2);
       set<int> cases;
       bool mainProcess = true;
       for (int i = 1; i < argc; ++i) {
       if ( string(argv[i]) == "-") {
       mainProcess = false;
       } else {
       cases.insert(atoi(argv[i]));
       }
       }
       if (mainProcess) {
       cout << "BalancedStrings (250 Points)" << endl << endl;
       }
       return run_test(mainProcess, cases, argv[0]);
       */
    return 0;
}
// CUT end
