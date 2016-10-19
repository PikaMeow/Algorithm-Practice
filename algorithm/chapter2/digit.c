//输入一个不超过10^9的正整数，输出它的位数
#include <stdio.h>
int main () {
 freopen("digit.in","r",stdin);
 freopen("digit.out","w",stdout);
 int n,i=0;
 scanf("%d",&n);
 while ( n != 0) {
  n = n/10;
  i = i + 1;
 }
 printf("%d\n",i);
}
