//uva1363
/*
Input:n and r
Output:the sequence of the leaving people
Sample
Input:
10 5
Output:
5 10 6 2 9 8 1 4 7 3
*/
#include <stdio.h>
#define MAXN 100//设置最大可以计算的人数
int n,r,a[MAXN];//设置全局变量方便在多个函数中使用
int go(int p,int r){//执行count的操作，遇到为0的元素则跳过
	while(r--) {
		do {
		 p=(p+n)%n+1;
		}
		while(a[p]==0);
	}
	return p;
}
int main () {
	while(scanf("%d %d",&n,&r) == 2 && n) {//保证接收到两个参数，且输入0退出
		for (int i=1;i<=n;i++) {
			a[i]=i;
		}
		int left=n,p=0;
		while(left) {
			p=go(p,r);
			printf("%d ",p); 
			left--;
			a[p]=0;//为了不修改数组长度，将数到的元素值设为0
		}
		printf("\n");
	}	 
	return 0;
}
