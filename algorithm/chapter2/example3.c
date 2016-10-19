//输入大于1的自然数n，若为奇，变为3n+1,若为偶，变为n/2，输出变换次数
#include <stdio.h>
int main () {
 int n2,count=0;
 scanf("%d",&n2); 
 long long n=n2;

 while (n>1) {
/* if (n%2!=0) n = n/2;
 else */if (n%2==0) n = n/2;
 else n = 3*n+1;
 count++;
}
 printf("%d\n",count);
 
 return 0;
}
