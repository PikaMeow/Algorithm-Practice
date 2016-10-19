//一件衣服95元，满300打85折，输入件数，输出金额，两位小数
#include <stdio.h>
int main () {
 int n;
 scanf("%d",&n);
 if ( n>3 ) 
 printf("%.2lf\n",95*n*0.85); 
 else if (n>=0 && n<=3) 
 printf("%.2lf\n",95.0*n);
 else 
 printf("Wrong number!\n");
 return 0;
}
