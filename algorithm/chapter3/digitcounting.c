//uva1225
/*
Input 
The input file consists of several data sets. The first line of the input file contains the number of data sets which is a positive integer and is not bigger than 20. The following lines describe the data sets.
For each test case, there is one single line containing the number N .

Output 
For each test case, write sequentially in one line the number of digit 0, 1,...9 separated by a space.

Sample Input 
2 
3 
13

Sample Output 
0 1 1 1 0 0 0 0 0 0 
1 6 2 2 1 1 1 1 1 1
*/
#include <stdio.h>
#include <string.h>
#define MAXN 10000+10

int main () {
	int T;
	scanf("%d",&T);
	while(T--) {
		int b[MAXN],a[10]={0};
		int num;
		scanf("%d",&num);
		for (int i=1;i<=num;i++) {
			b[i]=i;
		}
		for(int i=1;i<=num;i++) {
			while(b[i] > 0) {
				for(int j=0;j<=9;j++) {
					if(b[i]%10==j){
						a[j]++;
						break;
					}
				}
				b[i]/=10;
			}
		}
		for(int i=0;i<10;i++){
			if(i==0) printf("%d",a[i]);
			else printf(" %d",a[i]);
		}
		printf("\n");
	}

	return 0;
}