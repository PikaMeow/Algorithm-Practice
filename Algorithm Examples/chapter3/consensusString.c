//uva 1368
#include <stdio.h>
#include <ctype.h>
#define MAXN 55000
int main() {
	//freopen("consensus.in","r",stdin);
	//freopen("consensus.out","w",stdout);
	int t;
	scanf("%d",&t);
	while (t--) {
		int m,n,k=0;		
		scanf("%d%d",&m,&n);
		int p=m;
		char a[MAXN],b[n+10];
		
		while(p+1) {
			char ch;
			scanf("%c",&ch);
			if(isalpha(ch)) a[k++]=ch;
			else if(ch=='\n') p--;
		}
		
		
		int sum=0;
		for (int i=0;i<n;i++) {
			int x=0,y=0,z=0,w=0,t=0;
			for (int j=i;j<m*n;j+=n) {
				switch(a[j]) {
					case 'A':
					x++;
					break;
					case 'C':
					y++;
					break;
					case 'G':
					z++;
					break;
					case 'T':
					w++;
					break;
				}
			}
			//printf("%d%d%d%d\n",x,y,z,w);
			if(w>=t) {t=w;b[i]='T';}
			if(z>=t) {t=z;b[i]='G';}
			if(y>=t) {t=y;b[i]='C';}
			if(x>=t) {t=x;b[i]='A';}
			sum = sum+m-t;
		}
		b[n]='\0';
		printf("%s\n%d\n",b,sum);
		/*
		a[m*n]='\0';
		printf("%s\n",a);
		*/
	}
	return 0;
}