//uva 1587
#include <stdio.h>
#include <ctype.h>
int main() {
	int a[6][2];
	int count=0;
	for (int i=0;i<6;i++) {
		int j=0;
		for (;j<2;j++) {
			if(isdigit) {
				scanf("%d",&a[i][j]);
			}
		}
		/*if(a[i][j-1]>=a[i][j]){
			int t=a[i][j-1];
			a[i][j-1]=a[i][j];
			a[i][j]=t;
		}*/
	}
/*	for (int i=0;i<5;i++) {
		for (int j=i+1;j<6;j++) {
			if(a[i][0]>=a[j][0]) {
				int t=a[i][0]; a[i][0]=a[j][0]; a[j][0]=t;
				int s=a[i][1]; a[i][1]=a[j][1]; a[j][1]=t;
			}
		}
	}
	*/
	for (int i=0;i<6;i++) {
		for (int j=0;j<2;j++) {
			printf("%d ",a[i][j]);
		}
	}
	if((a[0][0]==a[1][0]==a[2][0]==a[3][0])&&(a[0][1]==a[1][1]==a[4][0]==a[5][0])&&(a[2][1]==a[3][1]==a[4][1]==a[5][1]))
	printf("POSSIBLE\n");
	else printf("IMPOSSIBLE\n"); 
	return 0;
}