#include <iostream>
using namespace std;

int main(void)
{
    long long sum = 0;
    for (int i = 0; i < 1000; i++) 
        sum += (!(i % 3) || !(i % 5) ? i : 0);

    cout << sum << endl;

    return 0;
}
