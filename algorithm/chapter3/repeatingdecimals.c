//uva202
#include <stdio.h>
#include <string.h>
#define MAXN 3500
int main() {
	//freopen("repeat.in","r",stdin);
	//freopen("repeat.out","w",stdout);
	int a,b,t=0;
	while(scanf("%d%d",&a,&b)==2) {
		if(a==0) {
			printf("%d/%d = %d.(0)\n   1 = number of digits in repeating cycle\n",a,b,a/b);
			continue;
		}	
		if(t++) printf("\n");
	int c[MAXN],d[MAXN];
	int s=a;
	if(a>=b) s=a%b;
	memset(d,0,sizeof(d));
	int p=0,q=1;
	d[s]=q;
	while(1) {
		s*=10;
		c[p]=s/b;
		s%=b;
		q+=1;		
		if(s==0 || d[s]) break;
		p+=1;
		d[s]=q;
	} 
	if(s==0) {
		printf("%d/%d = %d.",a,b,a/b);
		for (int i=0;i<p+1;i++)
			printf("%d",c[i]);
		printf("(0)\n   1 = number of digits in repeating cycle\n");
		} else {
		int circle=q-d[s];
		printf("%d/%d = %d.",a,b,a/b);
		for(int i=0;i<p+1-circle;i++)
		printf("%d",c[i]);
		printf("(");
		if(circle>50) {
			for(int i=p+1-circle;i<p+1-circle+50;i++)
			printf("%d",c[i]);
		printf("...");
		} else {
		for(int i=p+1-circle;i<p+1;i++)
		printf("%d",c[i]);
		}
		printf(")\n");
		printf("   %d = number of digits in repeating cycle\n",circle);
		}
	}
	return 0;
}