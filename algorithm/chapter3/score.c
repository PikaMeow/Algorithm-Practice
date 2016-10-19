//uva1585
/*
There is an objective test result such as ``OOXXOXXOOO". An `O' means a correct answer of a problem and an `X' means a wrong answer. The score of each problem of this test is calculated by itself and its just previous consecutive `O's only when the answer is correct. For example, the score of the 10th problem is 3 that is obtained by itself and its two previous consecutive `O's.
Therefore, the score of ``OOXXOXXOOO" is 10 which is calculated by ``1+2+0+0+1+0+0+1+2+3".
You are to write a program calculating the scores of test results.

Input 
Your program is to read from standard input. The input consists of T test cases. The number of test cases T is given in the first line of the input. Each test case starts with a line containing a string composed by `O' and `X' and the length of the string is more than 0 and less than 80. There is no spaces between `O' and `X'.

Output 
Your program is to write to standard output. Print exactly one line for each test case. The line is to contain the score of the test case.The following shows sample input and output for five test cases.

Sample Input 
5 
OOXXOXXOOO 
OOXXOOXXOO 
OXOXOXOXOXOXOX 
OOOOOOOOOO 
OOOOXOOOOXOOOOX

Sample Output 
10 
9 
7 
55 
30
*/
#include <stdio.h>
#include <string.h>
#define MAXN 80+5
int main () {
	int T;
	scanf("%d",&T);
	while (T--) {
		char s[MAXN];
		scanf("%s",s);
		int sum=0,n=strlen(s);
		for (int i=0;i<n;i++) {
			int j=1,subsum=0;
			while(s[i]=='O') {
				subsum += j;
				sum += subsum;
				i++;
			}
		}
	printf("%d\n",sum);
	}

	return 0;
} 