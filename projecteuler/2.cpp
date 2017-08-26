#include <iostream>
using namespace std;

int main(void)
{
    long long sum = 2;
    int num = 2;
    int pre = 1;
    while (1) {
        int tmp = num;
        num += pre;
        pre = tmp;
        if (num < 4000001) 
            sum += (!(num % 2) ? num : 0);
        else 
            break;
    }
    cout << sum << endl;
}
