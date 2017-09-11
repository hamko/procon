#include <iostream>
using namespace std;

int main(void)
{
    int amin[10000] = {};
    for (int i = 2; i < 10000; i++) {
        for (int j = 1; j < i; j++)
            if (!(i % j))
                amin[i] += j;
    }
    cout << amin[1] << endl;
    int am[10000] = {};
    long long sum = 0;
    for (int i = 1; i < 10000; i++) {
        for (int j = i + 1; j < 10000; j++) {
            if (i == amin[j] && j == amin[i]) {
                sum += (i + j);
                cout << i << " " << j << endl;
                am[i] = 1;
                am[j] = 1;
            }
        }
    }
    /*
    for (int i = 1; i < 10000; i++) {
        sum += (am[i] ? i : 0);
    }
    */
    cout << sum << endl;
}
