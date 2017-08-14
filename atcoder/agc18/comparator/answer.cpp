#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
 
int arr[300][300] = {};
int tmp[310] = {};
 
int main(void){
    
    int n,m;
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    
    int res = n;
    
    for(int i = 0; i < m; i++){
        
        /*
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout <<  arr[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        */
        for(int j = 0; j < 301; j++){
            tmp[j] = 0;
        }
        for(int j = 0; j < n; j++){
            tmp[arr[j][0]]++;
        }
        int t = 0;
        for(int j = 0; j < 301; j++){
            if(tmp[j] > tmp[t]){
                t = j;
            }
        }
        
        res = min(tmp[t],res);
        
        for(int j = 0; j < n; j++){
            bool f = false;
            for(int k = 0; k < m; k++){
                if(arr[j][k] == t){
                    arr[j][k] = 0;
                    f = true;
                }
                if(f){
                    arr[j][k] = arr[j][k+1];
                }
            }
        }
    }
    
    cout << res << endl;
    
}
