//uva1586
/*
Input
Your program is to read from standard input. The input consists of T test cases. The number of test cases T is given in the rst line of the input. Each test case is given in a single line, which contains
a molecular formula as a string. The chemical symbol is given by a capital letter and the length of the string is greater than 0 and less than 80. The quantity number n which is represented after the
chemical symbol would be omitted when the number is 1 (2<=n<=99).

Output
Your program is to write to standard output. Print exactly one line for each test case. The line should
contain the molar mass of the given molecular formula.

SampleInput
4
C
C6H5OH
NH2CH2COOH
C12H22O11

SampleOutput
12.010
94.108
75.070
342.296
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXN 80+5
int main() {
	int T;
	scanf("%d",&T);
	while (T--) {
	char s[MAXN];
	int a[MAXN];
	scanf("%s",s);
	int n=strlen(s);
	double sum=0;
	for (int i=0; i<n; i++) {
		if (isalpha(s[i])) {
			if(isdigit(s[i+1])) 
				if (isdigit(s[i+2])) a[i]=(int)(s[i+1]-'0')*10+(int)(s[i+2]-'0');
				else a[i]=(int)(s[i+1]-'0');
			else a[i]=1;
			if(s[i]=='C') sum = sum+12.01*a[i];
			if(s[i]=='H') sum = sum+1.008*a[i];
			if(s[i]=='O') sum = sum+16.00*a[i];
			if(s[i]=='N') sum = sum+14.01*a[i];
		}
	}
	printf("%.3lf\n",sum);
	}
	return 0;
}
