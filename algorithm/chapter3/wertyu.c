//输入一个向右错一位输入的字符串，输出正确的字符串
//uva10082	常量数组的妙用
#include <stdio.h>
char s[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int main () {
	int i,c;
	while ((c=getchar())!=EOF) {
		for(i=1; s[i]!=c;i++);
			if(s[i]) {
				putchar(s[i-1]);
			}
			else {
				putchar(c);
		}
	}
	return 0;
}