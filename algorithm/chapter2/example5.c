//输入一些整数，求出最大值、最小值、平均值（保留3位小数）
#include <stdio.h>
#define LOCAL
#define INF  100000000
int main() {
 int x,n=0,max=-INF,min=INF,s=0;
 while(scanf("%d",&x)==1) {
  s = s+x;
  if (min > x) min = x;
  if (max < x) max = x;

//  printf("x=%d,min=%d,max=%d\n",x,min,max); 

 n++;
}
 printf("%d %d %.3lf\n",min,max,(double)s/n);
 return 0;
}
