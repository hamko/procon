#include <bits/stdc++.h>
using namespace std;

int i;
int three;
int five;
int main(void) {
    int n; cin >> n;
    i++;
    three++; three++; three++;
    five++; five++; five++; five++; five++;
    while (i <= n) {
        if (!(i % three)) {
            cout << "Fizz";
        } 
        if (!(i % five)) {
            cout << "Buzz";
        }

        if (i % three && i % five)
            cout << i;
        cout << endl;
        i++;
    }
    return false;
}
