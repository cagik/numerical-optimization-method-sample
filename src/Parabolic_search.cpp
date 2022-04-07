#include <iostream>
#include <cmath>

using namespace std;

double fun(double x){
    return 3*pow(x,2) - 2 * tan(x);
}


//unfinished work, this method is suck. forget it
int main(){

    double a,b;
    double end_fun, end_h;

    double s0, s1, s2, bars;
    double phi0, phi1, phi2, phibars;

    double ds = 1.0e-5;
    double h = 1;
    double big = 1.0e6;

    double err = 1;
    double cond = 0;
    int i =1, maxi = 30;

    double f1;
	
    cout << "unfinished work, this method is suck. forget it" << endl;

    while(i < maxi && err > end_fun && cond != 5){
        f1 = (fun(s0 + ds) - fun(s0 - ds)) / (2 * ds);
        if(f1 > 0){
            h = - abs(h);
        }

        s1 = s0 + h;
        s2 = s0 + 2 * h;
        bars = s0;

        phi0 = fun(s0);
        phi1 = fun(s1);
        phi2 = fun(s2);
        phibars = phi0;
        cond = 0;
        
        int j = 0, maxj = 20;

        while(j < maxj && abs(h)> end_h && cond==0){
            if(phi0 <= phi1){
                s2 = s1;
                phi2 = phi1;
                h = 0.5 * h;
                s1 = s0 + h;
                phi1 = fun(s1);
            }
            else if(phi2 < phi1){
                s1 = s2;
                phi1 = phi2;
                h = 2 * h;
                s2 = s0 + 2 * h;
                phi2 = fun(s2);
            }
            else{
                cond = -1;
            }
            j = j + 1;
            if(abs(h) > big || abs(s0) > big){
                cond = 5;
            }
            if(cond == 5){
                bars = s1;
                phibars = fun(s1);
            }
            else{
                double d = 2 * (2 * phi1 - phi0 - phi2);
                if(d < 0){
                    //barre
                    return 0;
                }
            }

        }
        
    }

    return 0;
}
