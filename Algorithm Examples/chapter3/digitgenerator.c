//若x加上x的各个数字之和为y，就说x是y的生成元，给出n（1<=n<=100000），求最小生成元,无解输出0
//uva1583	预处理，查表
#include <stdio.h>
#include <string.h>
#define MAXN 1000+5
int a[MAXN];
int main () {
	int T,n;
	memset(a,0,sizeof(a));
	for (int m=1; m < MAXN; m++) {
		int x=m,y=m;
		while(x>0) {
			y+=x%10;
			x/=10;
		}
		if(a[y]==0||m<a[y]) a[y]=m;//或之后的判断条件不需要？
	}
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		printf("%d\n",a[n]);
	}
	return 0;
}
