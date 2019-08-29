#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

struct comb {
    double t;
    double d;
    double h;
};

double calh(double d,double t) {
    double e=6.11*exp(5417.7530*((1/273.16)-(1/(d+273.16))));
    double h=0.5555*(e-10);
    return t+h;
}

double calt(double d,double h) {
    double e=6.11*exp(5417.7530*((1/273.16)-(1/(d+273.16))));
    double H=0.5555*(e-10);
    return h-H;
}

double cald(double t,double h) {
     double H=h-t;
     double e=H/0.5555+10;
     double d=1/((1/273.16)-((log(e/6.11)/5417.7530)))-273.16;
     return d;
}

int main() {
    char c1,c2;
    double d1,d2,d3;
    while(cin>>c1) {
        if(c1=='E') break;
        cin>>d1>>c2>>d2;
        comb B;
        if(c1=='D'&&c2=='T') {B.d=d1;B.t=d2;B.h=calh(B.d,B.t);}
        else if(c1=='T'&&c2=='D') {B.d=d2;B.t=d1;B.h=calh(B.d,B.t);}
        else if(c1=='D'&&c2=='H') {B.d=d1;B.h=d2;B.t=calt(B.d,B.h);}
        else if(c1=='H'&&c2=='D') {B.d=d2;B.h=d1;B.t=calt(B.d,B.h);}
        else if(c1=='T'&&c2=='H') {B.t=d1;B.h=d2;B.d=cald(B.t,B.h);}
        else if(c1=='H'&&c2=='T') {B.t=d2;B.h=d1;B.d=cald(B.t,B.h);}
        printf("T %.1f D %.1f H %.1f\n",B.t,B.d,B.h);
    }
    return 0;
}
