/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: oscar
 *
 * Created on 3 de julio de 2020, 18:20
 */

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Simpson {
public:
    long double integral(long double a, long double b, int n, int m) {
        long double h = (b - a) / (2.0 * n);
        long double J1 = 0.0, J2 = 0.0, J3 = 0.0;
        long double x, y;
        long double HX, K1, K2, K3, Q, L;
        for (int i = 0; i <= 2 * n; i++) {
            x = a + i * h;
            HX = (d(x) - c(x)) / (2.0 * m);
            K1 = f(x, c(x)) + f(x, d(x));
            K2 = 0.0;
            K3 = 0.0;
            for (int j = 1; j <= 2 * m - 1; j++) {
                y = c(x) + j * HX;
                Q = f(x, y);
                if (j % 2 == 0) K2 += Q;
                else K3 += Q;
            }
            L = (K1 + 2 * K2 + 4 * K3) * HX / 3;
            if (i == 0 || i == 2 * n) J1 += L;
            else {
                if (i % 2 == 0) J2 += L;
                else J3 += L;
            }
        }
        long double J = h * (J1 + 2 * J2 + 4 * J3) / 3;
        return J;
    }

    virtual long double f(long double x, long double y) = 0;

    virtual long double c(long double x) = 0;

    virtual long double d(long double x) = 0;
};

class Funcion : public Simpson {
    
public:
    long double f(long double x, long double y) {
        //return x*pow(y,2);
        return log(x*y);
    }

    long double c(long double x)  {
        return (1);
    }

    long double d(long double x) {
        return (x);
    }

};

int main(int argc, char** argv) {
    
    Funcion resultado;
    
    cout<< setprecision(15)<<resultado.integral(1,2.71828182845904523536028747135266249775724709,3,3);

    return 0;
}

