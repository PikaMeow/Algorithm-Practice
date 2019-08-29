//输入浮点数，输出绝对值，保留两位
#include <stdio.h>
int main () {
 double d;
 scanf("%lf",&d);
 if ( d < 0) 
 printf("%.2lf\n",-d);
 else 
 printf("%.2lf\n",d);
 return 0;
}
