#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n; cin >> n;

    int a[100010]; for (int i=0; i<n; i++) cin >>a[i];

    int plus=0;
    int count=0;

    for (int i=0; i<n-1; i++){
        if (a[i]<a[i+1]){
            plus++; count++;
            if (plus > 1)
                count += plus-1;
        }
        else
            plus=0;
        cout << i << " " << plus << endl;
    }

    cout << n+count <<endl;

    return 0;

}
