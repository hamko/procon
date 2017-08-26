#include <iostream>
using namespace std;

int main(void)
{
    int nprime[1000000] = {};
    nprime[0] = nprime[1] = 1;
    for (int i = 0; i < 1000000; i++) {
        if (!nprime[i]) {
            for (int j = i * 2; j < 1000000; j += i) {
                nprime[j] = 1;
            }
        }
    }
    int n = 0;
    for (int i = 0; i < 1000000; i++) {
        if (!nprime[i]) {
            n++;
            if (n == 10001) {
                cout << i << endl;
            }
        }
    }
}
