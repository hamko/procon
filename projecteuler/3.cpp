#include <iostream>
#include <cmath>
using namespace std;

#define NUMM 600851475143LL

int main(void)
{
    int nprime[1000000] = {};
    nprime[0] = nprime[1] = 1;
    for (int i = 2; i < 1000000; i++) {
        if (!nprime[i]) {
            for (int j = i * 2; j < 1000000; j += i) {
                nprime[j] = 1;
            }
        }
    }

    long long num = NUMM;
    for (int i = 1; i < 1000000; i++) {
        if (nprime[i])
            continue;
        cout << num << " " << i << " "  << (num % i) << endl;
        while (!(num % i)) {
            num /= i;
            cout << num << endl;
        }
        if (num == 1) {
            cout << i << endl;
            break;
        }
    }
}
