//输入n，输出H(n),保留3位小数
#include <stdio.h>
int main () {
 freopen("harmony.in","r",stdin);
 freopen("harmony.out","w",stdout);
 int n;
 double h=0.0,i;
 scanf("%d",&n);
 for (i=1; i<=n; i++) {
  h = h+1/i;
 }
 printf("%.3lf\n",h);
 return 0;
}
