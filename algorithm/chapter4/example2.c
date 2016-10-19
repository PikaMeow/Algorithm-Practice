//输入m，输出两个数均不超过m的最大孪生素数
#include <stdio.h>
#include <math.h>
#include <assert.h>
int is_prime ( int x) {
 int i,m;
 assert(x>=0);
 if (x == 1) return 0;
 m=floor(sqrt(x)+0.5);
 for ( i=2; i*i<=x; i++)
  if (x%i==0) return 0;
 return 1;
}
int main() {
 int i,m;
 scanf("%d",&m);
 for (i=m-2; i >=3; i--)
 if(is_prime(i) && is_prime(i+2)) {
  printf("%d %d\n",i,i+2);
  break;
 }
 return 0;
}
