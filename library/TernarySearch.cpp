template<class Function>
double ternarySearch(double l, double r, Function f){
    for(int i = 0; i < 200; i++){
        double a = (l+l+r) / 3;
        double b = (l+r+r) / 3;
        if(f(a) > f(b)) l = a;
        else r = b;
    }
    return l;
}
