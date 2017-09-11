#include <iostream>
using namespace std;

int main(void)
{
    int p[2000000] = {};
    int sum = 0;
    for (int i = 2; i < 2000001;i ++) {
        if (!p[i]) {
            cout << i << endl;
            sum += i;
            for (int j = i; j < 2000000; j += i) {
                p[j] = 1;
            }
        }
    }
    cout << sum << endl;
    return 0;
}
