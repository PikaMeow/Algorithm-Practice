//圆柱体的表面积
#include <stdio.h>
#include <math.h>
int main () {
 double r,h,s1,s2,s;
 const double pi = 4.0 * atan(1.0);

 scanf("%lf%lf",&r,&h);
 s1 = pi * r * r;
 s2 = 2 * pi * r * h;
 s = 2 * s1 + s2;
 printf("Area=%.3lf\n",s);
 return 0;
} 
