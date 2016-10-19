//开灯问题，第一个人开全部，第二个人关2的倍数的灯，n个灯，k个人，输出开着的灯的编号
#include <stdio.h>
#include <string.h>
#define MAXN  1000+10
int a[MAXN];
int main () {
 memset(a,0,sizeof(a));
 int i,j,k,n,first=1;
 scanf("%d%d",&n,&k);
 for ( i=1; i<=k; i++)
  for (j=1; j<=n; j++)
   if(j%i == 0) a[j]=!a[j];
 for(i=1;i<=n;i++) {
  if(a[i]) {
  if(first) {
  first=0;
 } else {
  printf(" ");
 }
 printf("%d",i);
}
}
 printf("\n");
 return 0;
}
