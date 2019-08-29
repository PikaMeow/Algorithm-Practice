//输入华氏温度f，输出对应的摄氏温度c，保留3位小数
#include <stdio.h>
int main (){
 double f,c;
 scanf("%lf",&f);
 c = 5*(f-32)/9;
 printf("%.3lf\n",c);
 return 0;
}
