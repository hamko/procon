// not yet 
// 点位置決定 (スラブ地図)
// 線分アレンジメント





// 単純多角形の三角形分割 (耳分解)
// O(n^2)
typedef vector<point> triangle;
triangle make_triangle(const point& a, const point& b, const point& c) {
    triangle ret(3);
    ret[0] = a; ret[1] = b; ret[2] = c;
    return ret;
}
bool triangle_contains(const triangle& tri, const point& p) {
    return ccw(tri[0], tri[1], p) >= 0 &&
        ccw(tri[1], tri[2], p) >= 0 &&
        ccw(tri[2], tri[0], p) >= 0;
}
bool ear_Q(int i, int j, int k, const polygon& P) {
    triangle tri = make_triangle(P[i], P[j], P[k]);
    if (ccw(tri[0], tri[1], tri[2]) <= 0) return false;
    for (int m = 0; m < P.size(); ++m)
        if (m != i && m != j && m != k)
            if (triangle_contains(tri, P[m]))
                return false;
    return true;
}
void triangulate(const polygon& P, vector<triangle>& t) {
    const int n = P.size();
    vector<int> l, r;
    for (int i = 0; i < n; ++i) {
        l.push_back( (i-1+n) % n );
        r.push_back( (i+1+n) % n );
    }
    int i = n-1;
    while (t.size() < n-2) {
        i = r[i];
        if (ear_Q(l[i], i, r[i], P)) {
            t.push_back(make_triangle(P[l[i]], P[i], P[r[i]]));
            l[ r[i] ] = l[i];
            r[ l[i] ] = r[i];
        }
    }
}





// O(n + m) 凸多角形の共通部分 
bool intersect_1pt(const point& a, const point& b,
        const point& c, const point& d, point &r) {
    number D =  cross(b - a, d - c);
    if (EQ(D, 0)) return false;
    number t =  cross(c - a, d - c) / D;
    number s = -cross(a - c, b - a) / D;
    r = a + t * (b - a);
    return GE(t, 0) && LE(t, 1) && GE(s, 0) && LE(s, 1);
}
polygon convex_intersect(const polygon &P, const polygon &Q) {
    const int n = P.size(), m = Q.size();
    int a = 0, b = 0, aa = 0, ba = 0;
    enum { Pin, Qin, Unknown } in = Unknown;
    polygon R;
    do {
        int a1 = (a+n-1) % n, b1 = (b+m-1) % m;
        number C = cross(P[a] - P[a1], Q[b] - Q[b1]);
        number A = cross(P[a1] - Q[b], P[a] - Q[b]);
        number B = cross(Q[b1] - P[a], Q[b] - P[a]);
        point r;
        if (intersect_1pt(P[a1], P[a], Q[b1], Q[b], r)) {
            if (in == Unknown) aa = ba = 0;
            R.push_back( r );
            in = B > 0 ? Pin : A > 0 ? Qin : in;
        }
        if (C == 0 && B == 0 && A == 0) {
            if (in == Pin) { b = (b + 1) % m; ++ba; }
            else           { a = (a + 1) % m; ++aa; }
        } else if (C >= 0) {
            if (A > 0) { if (in == Pin) R.push_back(P[a]); a = (a+1)%n; ++aa; }
            else       { if (in == Qin) R.push_back(Q[b]); b = (b+1)%m; ++ba; }
        } else {
            if (B > 0) { if (in == Qin) R.push_back(Q[b]); b = (b+1)%m; ++ba; }
            else       { if (in == Pin) R.push_back(P[a]); a = (a+1)%n; ++aa; }
        }
    } while ( (aa < n || ba < m) && aa < 2*n && ba < 2*m );
    if (in == Unknown) {
        if (convex_contains(Q, P[0])) return P;
        if (convex_contains(P, Q[0])) return Q;
    }
    return R;
}


// 凸多角形直径
number convex_diameter(const polygon &pt) {
    const int n = pt.size();
    int is = 0, js = 0;
    for (int i = 1; i < n; ++i) {
        if (imag(pt[i]) > imag(pt[is])) is = i;
        if (imag(pt[i]) < imag(pt[js])) js = i;
    }
    number maxd = norm(pt[is]-pt[js]);

    int i, maxi, j, maxj;
    i = maxi = is;
    j = maxj = js;
    do {
        if (cross(diff(pt,i), diff(pt,j)) >= 0) j = (j+1) % n;
        else i = (i+1) % n;
        if (norm(pt[i]-pt[j]) > maxd) {
            maxd = norm(pt[i]-pt[j]);
            maxi = i; maxj = j;
        }
    } while (i != is || j != js);
    return maxd; /* farthest pair is (maxi, maxj). */
}


// O(log n) 
#define d(k) (dot(P[k], l[1] - l[0]))
point convex_extreme(const polygon &P, const line &l) {
    const int n = P.size();
    int a = 0, b = n;
    if (d(0) >= d(n-1) && d(0) >= d(1)) return P[0];
    while (a < b) {
        int c = (a + b) / 2;
        if (d(c) >= d(c-1) && d(c) >= d(c+1)) return P[c];
        if (d(a+1) > d(a)) {
            if (d(c+1) <= d(c) || d(a) > d(c)) b = c;
            else                               a = c;
        } else {
            if (d(c+1) > d(c) || d(a) >= d(c)) a = c;
            else                               b = c;
        }
    }
}


// O(log n)
enum { OUT, ON, IN };
int convex_contains(const polygon &P, const point &p) {
    const int n = P.size();
    point g = (P[0] + P[n/3] + P[2*n/3]) / 3.0; // inner-point
    int a = 0, b = n;
    while (a+1 < b) { // invariant: c is in fan g-P[a]-P[b]
        int c = (a + b) / 2;
        if (cross(P[a]-g, P[c]-g) > 0) { // angle < 180 deg
            if (cross(P[a]-g, p-g) > 0 && cross(P[c]-g, p-g) < 0) b = c;
            else                                                  a = c;
        } else {
            if (cross(P[a]-g, p-g) < 0 && cross(P[c]-g, p-g) > 0) a = c;
            else                                                  b = c;
        }
    }
    b %= n;
    if (cross(P[a] - p, P[b] - p) < 0) return 0;
    if (cross(P[a] - p, P[b] - p) > 0) return 2;
    return 1;
}



// O(n^2) ドロネー三角形分割
// 三角形分割木を構成すれば計算量が O(n log n) になるはずだが．
bool incircle(point a, point b, point c, point p) {
    a -= p; b -= p; c -= p;
    return norm(a) * cross(b, c)
        + norm(b) * cross(c, a)
        + norm(c) * cross(a, b) >= 0; // < : inside, = cocircular, > outside
}
#define SET_TRIANGLE(i, j, r) \
    E[i].insert(j); em[i][j] = r; \
E[j].insert(r); em[j][r] = i; \
E[r].insert(i); em[r][i] = j; \
S.push(pair<int,int>(i, j));
#define REMOVE_EDGE(i, j) \
    E[i].erase(j); em[i][j] = -1; \
E[j].erase(i); em[j][i] = -1;
#define DECOMPOSE_ON(i,j,k,r) { \
    int m = em[j][i]; REMOVE_EDGE(j,i); \
    SET_TRIANGLE(i,m,r); SET_TRIANGLE(m,j,r); \
    SET_TRIANGLE(j,k,r); SET_TRIANGLE(k,i,r); }
#define DECOMPOSE_IN(i,j,k,r) { \
    SET_TRIANGLE(i,j,r); SET_TRIANGLE(j,k,r); \
    SET_TRIANGLE(k,i,r); }
#define FLIP_EDGE(i,j) { \
    int k = em[j][i]; REMOVE_EDGE(i,j); \
    SET_TRIANGLE(i,k,r); SET_TRIANGLE(k,j,r); }
#define IS_LEGAL(i, j) \
    (em[i][j] < 0 || em[j][i] < 0 || \
     !incircle(P[i],P[j],P[em[i][j]],P[em[j][i]]))
double Delaunay(vector<point> P) {
    const int n = P.size();
    P.push_back( point(-inf,-inf) );
    P.push_back( point(+inf,-inf) );
    P.push_back( point(  0 ,+inf) );
    int em[n+3][n+3]; memset(em, -1, sizeof(em));
    set<int> E[n+3];
    stack< pair<int,int> > S;
    SET_TRIANGLE(n+0, n+1, n+2);
    for (int r = 0; r < n; ++r) {
        int i = n, j = n+1, k;
        while (1) {
            k = em[i][j];
            if      (ccw(P[i], P[em[i][j]], P[r]) == +1) j = k;
            else if (ccw(P[j], P[em[i][j]], P[r]) == -1) i = k;
            else break;
        }
        if      (ccw(P[i], P[j], P[r]) != +1) { DECOMPOSE_ON(i,j,k,r); }
        else if (ccw(P[j], P[k], P[r]) != +1) { DECOMPOSE_ON(j,k,i,r); }
        else if (ccw(P[k], P[i], P[r]) != +1) { DECOMPOSE_ON(k,i,j,r); }
        else                                  { DECOMPOSE_IN(i,j,k,r); }
        while (!S.empty()) {
            int u = S.top().first, v = S.top().second; S.pop();
            if (!IS_LEGAL(u, v)) FLIP_EDGE(u, v);
        }
    }
    double minarg = 1e5;
    for (int a = 0; a < n; ++a) {
        for (set<int>::iterator itr = E[a].begin(); itr != E[a].end(); ++itr) {
            int b = *itr, c = em[a][b];
            if (b < n && c < n) {
                point p = P[a] - P[b], q = P[c] - P[b];
                minarg = min(minarg, acos(dot(p,q)/abs(p)/abs(q)));
            }
        }
    }
    return minarg;
}





// 可視グラフ
// O(n^3)
bool block_off(const point &a, const point &b, const polygon &obj) {
    point m = (a+b)/2.0;
    bool on = false, in = false;
    for (int j = 0; j < obj.size(); ++j) {
        point c = curr(obj,j), d = next(obj,j);
        if (imag(d) < imag(c)) swap(c, d);
        if (cross(a-c,b-c) * cross(a-d,b-d) < 0 &&    // strictly intersect.
                cross(c-a,d-a) * cross(c-b,d-b) < 0) return true;
        if (cross(a-c,b-c) == 0 && dot(a-c,b-c) < 0) return true;
        if (imag(c) <= imag(m) && imag(m) < imag(d))  // strictly contain.
            if (cross(c-m,d-m) < 0) in = !in;
        if (cross(c-m,d-m) == 0 && dot(c-m,d-m) <= 0) on = true;
    }
    return !on && in;
}
graph visibility_graph(const vector<point> &pt,
        const vector<polygon> &objs) {
    graph g(pt.size());
    for (int i = 0; i < pt.size(); ++i) {
        for (int j = i+1; j < pt.size(); ++j) {
            for (int k = 0; k < objs.size(); ++k)
                if (block_off(pt[i], pt[j], objs[k])) goto SKIP;
            g[i].push_back( edge(i, j, abs(pt[i]-pt[j])) );
            g[j].push_back( edge(j, i, abs(pt[i]-pt[j])) );
SKIP:;
        }
    }
    return g;
}


// 線分併合, sを副作用でマージして返す
// O(n^2)
bool merge_if_able(segment &s, segment t) {
    if (abs(cross(s[1]-s[0], t[1]-t[0])) > EPS) return false;
    if (ccw(s[0], t[0], s[1]) == +1 ||
            ccw(s[0], t[0], s[1]) == -1) return false; // not on the same line
    if (ccw(s[0], s[1], t[0]) == -2 ||
            ccw(t[0], t[1], s[0]) == -2) return false; // separated
    s = segment(min(s[0], t[0]), max(s[1], t[1]));
    return true;
}
void merge_segments(vector<segment>& segs) {
    for (int i = 0; i < segs.size(); ++i)
        if (segs[i][1] < segs[i][0])
            swap(segs[i][1], segs[i][0]);
    for (int i = 0; i < segs.size(); ++i)
        for (int j = i+1; j < segs.size(); ++j)
            if (merge_if_able(segs[i], segs[j]))
                segs[j--] = segs.back(), segs.pop_back();
}


// void insert(const point &p)
// kd 木に新しい点 p を挿入する．
// void search(const point &ld, const point &ru, OUT out)
// 左下点 ld, 右上点 ru で張られる四角形内に入る点を out に出力する．
struct kdtree {
    struct node {
        point p;
        node *l, *r;
        node(const point &p)
            : p(p), l(NULL), r(NULL) { }
    } *root;
    kdtree() : root(NULL) { }

#define compare(d, p, q) (d ? real(p) < real(q) : imag(p) < imag(q))
    // O(log n)
    void insert(const point &p) {
        root = insert(root, 0, p);
    }
    node *insert(node *t, int d, const point &p) {
        if (t == NULL) return new node(p);
        if (compare(d,p,t->p)) t->l = insert(t->l, !d, p);
        else                   t->r = insert(t->r, !d, p);
        return t;
    }
    // O(log n + k), kは範囲内の点数
    template <class OUT>
        void search(const point &ld, const point &ru, OUT out) {
            search(root, 0, ld, ru, out);
        }
    template <class OUT>
        void search(node *t, int d, const point &ld, const point &ru, OUT out) {
            if (t == NULL) return;
            const point &p = t->p;
            if (real(ld) <= real(p) && real(p) <= real(ru) &&
                    imag(ld) <= imag(p) && imag(p) <= imag(ru)) *out++ = p;
            if (!compare(d,p,ld)) search(t->l, !d, ld, ru, out);
            if (!compare(d,ru,p)) search(t->r, !d, ld, ru, out);
        }
};



// 最近点対（嘘だけど速度は劣らない）
// O(n log n), 横一列の時最悪O(n^2)
pair<P,P> closestPair(vector<P> p) {
      int n = p.size(), s = 0, t = 1, m = 2, S[n]; S[0] = 0, S[1] = 1;
        sort(ALL(p)); // "p < q" <=> "p.x < q.x"
          double d = norm(p[s]-p[t]);
            for (int i = 2; i < n; S[m++] = i++) REP(j, m) {
                    if (norm(p[S[j]]-p[i])<d) d = norm(p[s = S[j]]-p[t = i]);
                        if (real(p[S[j]]) < real(p[i]) - d) S[j--] = S[--m];
                          }
              return make_pair( p[s], p[t] );
}


// 双対変換
// point p = (a,b)  <---> line l = { (x,y) | y = a x - b }
line dual(const point &p) {
      return line( point(0, -imag(p)), point(1, real(p) - imag(p)) );
}
point dual(const line &l) {
      const point &p = l[0], &q = l[1];
        return point( imag(p-q)/real(p-q), cross(p,q)/real(q-p) );
}



// 線分串刺し直線問題
segment shrink(const segment &s) {
      point d = s[1] - s[0]; d /= abs(d); d *= 10;
        return segment(s[0]-eps*d, s[1]+eps*d);
}
bool stabbing_line(const vector<segment> &segs) {
      vector<polygon> regions(1);
        regions[0].push_back( point(-inf,-inf) );
          regions[0].push_back( point(+inf,-inf) );
            regions[0].push_back( point(+inf,+inf) );
              regions[0].push_back( point(-inf,+inf) );
                for (int i = 0; i < segs.size(); ++i) {
                        vector<polygon> next;
                            segment s = shrink(segs[i]);
                                line l = dual(s[0]), m = dual(s[1]);
                                    line la(l[0], l[1]), lb(l[1], l[0]);
                                        line ma(m[0], m[1]), mb(m[1], m[0]);
                                            for (int k = 0; k < regions.size(); ++k) {
                                                      polygon Rab = convex_cut(convex_cut(regions[k], la), mb);
                                                            polygon Rba = convex_cut(convex_cut(regions[k], lb), ma);
                                                                  if (Rab.size() > 0) next.push_back( Rab );
                                                                        if (Rba.size() > 0) next.push_back( Rba );
                                                                            }
                                                regions.swap( next );
                                                  }
                  return regions.size() > 0; // (a,b) \in region -> (a,b)* is stabber
}



// 直線アレンジメント問題
// O(n^2 log n)だが、直線走査ではなく位相走査すればO(n^2)になる
// -infinity での順序
struct CompareMinusInfinity {
      const vector<L> &ls;
        CompareMinusInfinity(const vector<L> &ls) : ls(ls) { }
          bool vertical(int i) const {
                  return abs(real(ls[i][0] - ls[i][1])) < EPS;
                    }
            pair<double, double> ab(int i) const {
                    double D = real(ls[i][0] - ls[i][1]);
                        double A = imag(ls[i][0] - ls[i][1]);
                            double B = cross(ls[i][0], ls[i][1]);
                                return pair<double, double>(-A/D, B/D); // y = -infty * A/D + B
                                  }
              bool operator() (int i, int j) const {
                      if (vertical(i) && vertical(j)) // compare x coordinate
                                return real(ls[i][0]) > real(ls[j][0]);
                          else if (vertical(i)) return true;
                              else if (vertical(j)) return false;
                                  else return ab(i) < ab(j); // both lines are non-vertical
                                    }
};
void walkArrangement(const vector<L> &ls) {
      const int n = ls.size();
        CompareMinusInfinity compare(ls);
          map< P, set<int> > cs;
            for (int i = 0; i < n; ++i)
                    for (int j = 0; j < n; ++j)
                              if (intersectLL(ls[i], ls[j]))
                                          cs[ crosspoint(ls[i], ls[j]) ].insert(i);

              vector<int> order(n);
                REP(i, n) order[i] = i;
                  sort(order.begin(), order.end(), compare);

                    vector<int> index(n);
                      REP(i, n) index[order[i]] = i;

                        for (int i = -1; i < n; ++i) {
                                // ls[ ord[i] ] と ls[ ord[i+1] ] に挟まれた領域が発生
                                // ただし i < 0 は -infinity, i+1 >= n は +infinity
                              }
                          FOR(itr, cs) {
                                  const set<int> &S = itr->second;
                                      int low  = index[*min_element(S.begin(), S.end(), compare)];
                                          int high = index[*max_element(S.begin(), S.end(), compare)];

                                              for (int i = low, j = high; i < j; ++i, --j) {
                                                        swap(order[i], order[j]);
                                                              index[order[i]] = i;
                                                                    index[order[j]] = j;
                                                                        }
                                                  for (int i = low; i < high; ++i) {
                                                            // ls[ ord[i] ] と ls[ ord[i+1] ] に挟まれた領域が発生
                                                          }
                                                    }
}





bool intriangle(point a, point b, point c, point p) {
    a -= p; b -= p; c -= p;
    return cross(a, b) >= 0 &&
        cross(b, c) >= 0 &&
        cross(c, a) >= 0;
}
bool incircle(point a, point b, point c, point p) {
    a -= p; b -= p; c -= p;
    return norm(a) * cross(b, c)
        + norm(b) * cross(c, a)
        + norm(c) * cross(a, b) >= 0; // < : inside, = cocircular, > outside
}
point three_point_circle(const point& a, const point& b, const point& c) {
    point x = 1.0/conj(b - a), y = 1.0/conj(c - a);
    return (y-x)/(conj(x)*y - x*conj(y)) + a;
}
pair<point, point> circle_circle_intersect(
        const point& c1, const double& r1, const point& c2, const double& r2) {
    point A = conj(c2-c1), B = (r2*r2-r1*r1-(c2-c1)*conj(c2-c1)), C = r1*r1*(c2-c1);
    point D = B*B-4.0*A*C;
    point z1 = (-B+sqrt(D))/(2.0*A)+c1, z2 = (-B-sqrt(D))/(2.0*A)+c1;
    return pair<point, point>(z1, z2);
}
