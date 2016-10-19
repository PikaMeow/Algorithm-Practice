//输入3个非负整数a,b,a.表示每种队形排尾的人数，输出总人数的最小值（或无解），总人数不小于10，不超过100
#include <stdio.h>
//#include <time.h>
int main () {
 freopen("hanxin.in","r",stdin);
 freopen("hanxin.out","w",stdout);
 int a,b,c,n;
 scanf("%d%d%d",&a,&b,&c);
 for ( n = 10; n <=100 ;n++) {
 if (n%3 == a && n%5 == b && n%7 == c) 
 printf("%d\n",n);
 else if ( n == 100)
 printf("No answer");
}
// printf("Time used=%.2lf\n",(double)clock()/CLOCKS_PER_SEC);
 return 0;
}
