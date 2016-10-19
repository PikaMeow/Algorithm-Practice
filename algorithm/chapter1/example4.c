//鸡兔同笼：总数为n,总腿数m,求鸡兔数目
#include <stdio.h>
int main () {
 int m,n,x,y;
 scanf("%d%d",&n,&m);
 x = (4*n-m)/2;
 y = (m-2*n)/2;
 if (m%2==0 && x>=0 && y>=0) 
 printf("%d %d\n",x,y);
 else 
 printf("No answer\n");
 return 0;
}
