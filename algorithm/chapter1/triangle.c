//输入三边值，判断能否作为直角三角形三边长
#include <stdio.h>
int main () {
 int a,b,c,x,y,z;
 scanf("%d%d%d",&a,&b,&c);
 x = a;
 if (x > b) x = b;
 if (x > c) x = c;
 z = a;
 if (z < b) z = b;
 if (z < c) z = c;
 y = a + b + c - x - z;
 if ( x<=0 || y<=0 || z<=0 || x + y <= z)
 printf("not a triangle\n");
 else if ( x*x + y*y == z*z)
 printf("yes\n");
 else 
 printf("no\n");
 return 0;

}
