#include <bits/stdc++.h>
using namespace std;

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

#define rep(i,n) for(int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
using vi = vector<int>;

int main(void) {
    int n/*female*/, m/*male*/, p/*female*/, q/*male*/, r; cin >> n >> m >> p >> q >> r;
    vi female(n); rep(i, n) female[i] = i;
    vi x(r), y(r), z(r);
    rep(i, r) { cin >> x[i] >> y[i] >> z[i]; x[i]--; y[i]--; }

    int ret = 0;
    while (1) {
        vi zsum(m, 0);
        rep (i, r) {
            if (find(female.begin(), female.begin() + p, x[i]) == female.begin() + p)
                continue;
            zsum[y[i]] += z[i];
        }
        sort(all(zsum), greater<int>());
        ret = max(ret, accumulate(zsum.begin(), zsum.begin() + q, (int)0));

        if (!next_combination(female.begin(), female.begin() + p, female.end()))
            break;
    }
    cout << ret << endl;
    
    return 0;
}
