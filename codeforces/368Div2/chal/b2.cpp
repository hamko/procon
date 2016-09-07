#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class edge1{
    public:
        int s,e,l;

        edge1(int a, int b, int c){
            s=a;
            e=b;
            l=c;

        }

};

bool cmp(edge1* a, edge1* b){
    return a->l<=b->l;
}

int main(){
    int n,m,k;
    cin>>n>>m>>k;

    vector<edge1*> v(m);


    v.clear();
    for (int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v.push_back(new edge1(a,b,c));
    }

    unordered_map<int,bool> m1;
    m1.clear();
    for (int i=0;i<k;i++){
        int x;
        cin>>x;
        m1[x]=true;
    }

    if (k==0){
        cout<<-1;
        return 0;
    }


    sort(v.begin(),v.end(),cmp);
    for (int i=0;i<m;i++){

        if ((m1.find(v[i]->s)==m1.end()) ^ (m1.find(v[i]->e)==m1.end())){
            cout<<v[i]->l;
            return 0;
        }

    }
    cout<<-1;






    return 0;

}


