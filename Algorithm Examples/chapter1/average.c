//输入3个整数，输出他们的平均值,保留3位小数
#include <stdio.h> 
int main () 
{
 int a,b,c;
 double avg;
 scanf("%d%d%d",&a,&b,&c);
 avg = (a+b+c)/3;
 printf("%.3lf\n",avg);
 return 0;
}
