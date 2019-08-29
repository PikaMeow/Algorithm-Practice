//输出所有形如aabb的四位完全平方数
#include <stdio.h>
#include <math.h>
/*
int main () {
 int a,b,n;
 double m;
 for( a = 1; a < 10;a++) {
  for ( b = 0; b < 10; b++) {
   n = 1100 * a + 11 * b;
   m = sqrt(n);
   if(floor(m+0.5) == m)
   printf("%d\n",n);
}
}
 return 0;
}
*/
//or

int main () {
 int n,x,hi,lo;
 for ( x = 1 ; ; x++) {
 n = x*x;
  if (n<1000) continue;
  if (n>9999) break;
 hi = n/100;
 lo = n%100;
 if (hi/10 == hi%10 && lo/10 == lo%10) 
 printf("%d\n",n);
 }
 return 0;
}
