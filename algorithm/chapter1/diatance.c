//输入4个浮点数，求平面中两点距离
#include <stdio.h>
#include <math.h>
int main () {
 double x1,y1,x2,y2,d;
 scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
 d = sqrt(pow(x2-x1,2)+pow(y2-y1,2));
 printf("%lf\n",d);
 return 0;
}
