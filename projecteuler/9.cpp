#include <iostream>
using namespace std;

int main(void)
{
    for (int a = 0; a < 1000; a++) {
        for (int b = a + 1; b < 1000 - a; b++) {
            int c = 1000 - a - b;
            if (a * a + b * b == c * c) {
                cout << a << " " << b << " " << c << endl;
                cout << a * b * c << endl;
            }
        }
    }
}
