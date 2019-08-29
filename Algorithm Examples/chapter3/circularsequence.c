//输入一个长度为n(n<=100)的环状DNA串，输出该环状串的最小表示
//uva1584	字典序
#include <stdio.h>
#include <string.h>
#define MAXN 100+10
int less(const char*s, int p, int q) {
	int n=strlen(s);
	for (int i=0;i<n;i++) {
		if (s[(p+i)%n] != s[(q+i)/n])
			return s[(p+i)%n]<s[(q+i)%n];
	}
	return 0;//相等
}
int main () {
	int T;
	char s[MAXN];
	scanf("%d",&T);
	while(T--) {
		scanf("%s",s);
		int ans=0;
		int n=strlen(s);
		for (int i=0;i<n;i++)//找到最小表示的第一个字符所在位置
			if(less(s,i,ans)) ans=i;
		for (int i=0;i<n;i++)//按最小表示重新排列字符串
			putchar(s[(i+ans)%n]);
		putchar('\n'); 

	}
	printf("%s\n",s);
	return 0;
}