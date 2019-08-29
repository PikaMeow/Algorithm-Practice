//uva201
/*
*/
#include <stdio.h>
#define MAXN 10+5
int a[MAXN][MAXN]={0};
void printa(int a[][MAXN]) {
	for(int i=0;i<MAXN;i++) {
		for(int j=0;j<MAXN;j++) {
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
void inita(char ch) {
	int i,j;
	scanf("%d%d",&i,&j);
	a[i][j]++;
	if(ch=='H') { a[i][j+1]++; }
	if(ch=='V') { a[i+1][j]++; }
}
int main () {
	// freopen("squares.in","r",stdin);
	// freopen("squares.out","w",stdout);
	int n,m;
	while(scanf("%d%d",&n,&m)==2 && n) {
		int p=m,i=0,j=0;
		char ch;
		while(p--) {
			scanf("%c%d%d",&ch,&i,&j);
			printf("%d %c %d %d\n",p,ch,i,j);
			a[i][j]++;
			if(ch=='H') { a[i][j+1]++; }
			else if(ch=='V') { a[i+1][j]++; }
		}
		printa(a);
	}
	
}