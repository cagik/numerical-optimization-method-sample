#include <iostream>
#include <cmath>

using namespace std;

double calE(double x){
    double ex = 0, item = 1, i = 0;
    while(item>1.0e-7){
        ex += item;
        i++;
        item *= (x/i);
    }
    return ex;
}

double fun(double x){
    return calE(-x) + x*x;
    //return 3*pow(x,2) - 2 * tan(x);
}

int main(){

    double a,b,h,p,q,phia,phib,phip,phiq;
    double t = (sqrt(5) - 1) * 0.5;
    double end_fun, end_h;

    a = 0;
    b = 1;
    end_fun = 0.2;
    end_h = 1.0e-4;

    h = b - a;
    p = a + (1 - t) * h;
    q = a + t * h;
    phia = fun(a);
    phib = fun(b);
    phip = fun(p);
    phiq = fun(q);


    int count = 0;
    while(abs(phib - phia) > end_fun || b - a > h){
        count++ ;
        if(phip <= phiq){
            b = q;
            phib = phiq;
            q = p;
            phiq = phip;
            h = b - a;
            p = a + (1 - t)*h;
            phip = fun(p);
        }
        else{
            a = p;
            phia = phip;
            p = q;
            phip = phiq;
            h = b -a;
            q = a + t*h;
            phiq = fun(q);
        }
    }

    double s = phip <= phiq ? p : q;
    double phis = phip <= phiq ? phip : phiq;

    cout << "迭代次数:" << count << endl;
    cout << "s:" << s << endl;
    cout << "phis:" << phis << endl;
    cout << "区间差值" << abs(b-a) << endl;
    cout << "fun差值" << abs(phia - phib) << endl;

    return 0;
}