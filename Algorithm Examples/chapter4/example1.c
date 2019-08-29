//输入非负整数n和m，输出组合数，m<=n<=20
#include <stdio.h>
int f( int n) {
 int i,m=1;
 for (i=1; i <=n; i++) 
  m *=i;
  return m;
}
int main () {
 int n,m,j,k=1;
 scanf("%d%d",&n,&m);
 int i= m>=n-m?m:n-m;
 for (j=i+1;j<=n;j++)
  k *= j;
 printf("%d\n",k/f(n-i));
 return 0;
}
