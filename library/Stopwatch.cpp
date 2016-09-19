#include <sys/time.h>
#include <bits/stdc++.h>
using namespace std;

// これを{}でくくる初めに置くと、{}の終わりで呼ばれたデストラクタでかかった時間を表示する
struct stop_watch {
    chrono::high_resolution_clock::time_point start;
    stop_watch() 
        : start(chrono::high_resolution_clock::now()) {}
    ~stop_watch() {
        chrono::duration<double> duration = chrono::high_resolution_clock::now() - start;
        cout << duration.count() << " ";
    }  
};


#define rep(i,n) for(int i = 0; i < n; i++)
#define ll long long
int main(void) {
    for (ll cycle = 1; cycle <= 10000000; cycle *= 10) {
        cout << cycle << " ";

        {
            stop_watch sw;
            vector<ll> a;
            rep(i, cycle) {
                a.push_back(i);
            }
        }

        {
            stop_watch sw;
            vector<ll> b;
            b.reserve(cycle);
            rep(i, cycle) {
                b.push_back(i);
            }
        }
        cout << endl;
    }

    return 0;
}
