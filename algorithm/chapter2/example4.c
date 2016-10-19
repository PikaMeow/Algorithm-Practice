//输入n,计算阶乘之和的末六位（不含前导0），n<=10^6
#include <stdio.h>
#include <time.h>
int main () {
 const int MOD=1000000;
 int n,i,j,s=0;
 scanf("%d",&n);
 if (n>25) n=25;
 for ( i=1; i <=n; i++) {
 int f=1;
  for (j=1; j<=i;j++)
  f=f*j%MOD;
 s=(s+f)%MOD; 
 }
 printf("%d\n",s);
 printf("Time used = %.2lf\n",(double)clock()/CLOCKS_PER_SEC);
 return 0;
 
}
