//uva1588
#include <stdio.h>
#include <string.h>
#define MAXN 100+10
int main () {
	char a[MAXN],b[MAXN];
	
	while(scanf("%s%s",a,b)==2) {
		int k=0;
		int lena=strlen(a),lenb=strlen(b);
		//printf("%s%s\n",a,b);
		//printf("%d%d\n",lena,lenb);
		for (int i=0,j=0;i<lena && j<lenb;) {
			// printf("%d %d %d %d %d\n",k,i,j,a[i]-48,a[j]-48);
			 if((j!=0) && a[i]=='2'&&b[j]=='2') {
				 k+=j;
				 j=0;
			 }
			// printf("%d %d %d %d %d\n",k,i,j,a[i]-48,a[j]-48);
			if(a[i]=='2'&&b[j]=='2') {
				i++;
				k++;
			}
			// printf("%d %d %d %d %d\n",k,i,j,a[i]-48,a[j]-48);
			if(a[i]=='1' || b[j]=='1') {
				i++;
				j++;				
			}	
		}

		if(k+lenb>lena) printf("%d\n",k+lenb);
		else printf("%d\n",lena);
	}
	return 0;
}