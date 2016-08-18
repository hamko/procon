// http://yukicoder.me/submissions/109015
#include <bits/stdc++.h>
using namespace std;

// aに単調性があると、計算量がlog n落ちたり、
// http://d.hatena.ne.jp/sune2/20140310/1394440369
//
// 削除が楽になるらしい
// http://pekempey.hatenablog.com/entry/2016/03/04/202648

template<class T>
struct ConvexHullTrick {
    vector<pair<T, T>> ls;

    bool need(pair<T, T> l1, pair<T, T> l2, pair<T, T> l3) {
        return -(l2.second - l1.second) * (l3.first - l2.first) < -(l3.second - l2.second) * (l2.first - l1.first);
    }

    void add(T a, T b) {
        pair<T, T> l(-a, -b);
        while (ls.size() >= 2 && !need(ls[ls.size() - 2], ls[ls.size() - 1], l)) ls.pop_back();
        ls.emplace_back(l);
    }

    T f(int k, T x) {
        return ls[k].first * x + ls[k].second;
    }

    T maximum(T x) {
        int pass = ls.size() - 1, fail = -1;
        while (pass - fail > 1) {
            int mid = (pass + fail) / 2;
            (f(mid, x) >= f(mid + 1, x) ? pass : fail) = mid;
        }
        return f(pass, x);
    }
};

