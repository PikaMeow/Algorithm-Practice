//输入年份，判断是否为闰年
#include <stdio.h>
 int main () {
 int n;
 scanf("%d",&n);
 if (n%100==0) {
 if (n%400==0) printf("yes\n");
 else printf("no\n");
} else {
 if (n%4==0) printf("yes\n");
 else printf("no\n");
}
 return 0;
}

//or

/*if(n%400==0 || n%100!=0 && n%4==0)
  printf("yes\n");
 else 
 printf("no\n");
*/
