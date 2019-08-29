//输入含双引号的语句，将其转换成左“``”，右“‘’”的形式
//uva272	输入输出函数详解
#include <stdio.h>
int main () {
	int c,q=1;
	while((c=getchar())!=EOF) {
		if(c=='"') {
			printf("%s",q?"``":"‘’");
			q=!q;
		}
		else 
		printf("%c",c);
	}
	return 0;
}