#include <bits/stdc++.h>
using namespace std;

template<class T>
class B {
public:
    B(void) { }
    T T0; 
};

template<class T>
class C : public B<T> {
public:
    C(void) { T0 = 1; }
};

template<class T>
struct A {
    A(B<T>* op)  {
        cout << op->T0 << "#in" << endl;
    }
};

int main(void) {
    auto ptr = new C<int>;
    cout << ptr->T0 << "#out" << endl;
    A<int> s(ptr);
    
    return 0;
}
