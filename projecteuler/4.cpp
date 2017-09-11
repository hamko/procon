#include <iostream>
using namespace std;
#define NUM 10000

int main(void)
{
    int nums[NUM] = {};
    int n = 0;
    for (int i = 999; i > 900; i--) {
        for (int j = 999; j > 900; j--) {
            nums[n++] = i * j;
        }
    }
    for (int i = 0; i < NUM - 1; i++) {
        for (int j = i; j < NUM - i - 1; j++) {
            int tmp = nums[j];
            nums[j] = nums[j+1];
            nums[j+1] = tmp;
        }
    }

    for (int i = 0; i < NUM; i++) {
        if (nums[i] % 10== 9)
            cout << nums[i] << endl;;
    }
}
