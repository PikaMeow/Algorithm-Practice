#include <cstdio>
#include <cmath>
using namespace std;
int main() {
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    double pi=acos(-1);
    double s1=sqrt(2)*a*a*a/12;
    double s2=sqrt(2)*b*b*b/6;
    double l=c/sin(pi/5)/2;
    double h=sqrt(c*c-l*l);
    double s=5*l*l*sin(2*pi/5)/2;
    double s3=h*s/3;
    //printf("%.12f %.12f %.12f\n",l,h,s);
    //printf("%.12f %.12f %.12f\n",s1,s2,s3);
    printf("%.12f\n",s1+s2+s3);
}
