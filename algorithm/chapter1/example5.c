//三整数排序（顺序从小到大）
#include <stdio.h>
int main () {
 int a,b,c,t;
 scanf("%d%d%d",&a,&b,&c);
 if (a>b) {
 t = a;
 a = b;
 b = t;
} else if (a>c) {
 t = a;
 a = c;
 c = t;
} else if (b>c) {
 t = b;
 b = c;
 c = t;
}
 printf("%d %d %d\n",a,b,c);
 
 return 0;
}
