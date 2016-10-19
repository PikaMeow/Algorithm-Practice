//输入正整数n(n<360),输出n的正弦余弦值
#include <stdio.h>
#include <math.h>

int main () {
 const double pi = 4.0 * atan(1.0);
 int n;
 double m;
 scanf("%d",&n);
 m = n*pi/180;
 printf("%lf %lf\n",sin(m),cos(m));
 return 0;
}
