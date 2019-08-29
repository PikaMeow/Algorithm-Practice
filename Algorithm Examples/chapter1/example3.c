//交换变量
#include <stdio.h>
int main () {
 int a,b,temp;
 scanf("%d%d",&a,&b);
 temp = a;
 a = b;
 b = temp;
 printf("%d %d\n",a,b);
}
