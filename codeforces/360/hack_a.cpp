#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, d, t=0, l=0,one=0,m=0;cin>>n>>d;
    char a;
    int arr[10001] = {0};
    for(int i = 0; i < d; i++)  {
        for(int j = 0; j < n; j++) 
        {
            cin >> a;
            if (a == '0')
                l++;
            else
                one++;
        }
        if (one == n) {
            arr[m] = t;
            m++;
            t = 0;
        } else 
            t++;
        one = 0;
        l = 0;
    }
    for(int i = 0; i < d; i++)  {
        cout << arr[i] << endl;
    }

    sort(arr, arr+m);
    if (arr[m-1] < t) {
        arr[m] = t;
        m++;
    }
    sort(arr, arr+m);
    cout << arr[m-1] << endl;
}
