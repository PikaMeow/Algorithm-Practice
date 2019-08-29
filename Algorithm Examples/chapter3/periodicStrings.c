//uva455
/*
Input
The first line oif the input file will contain a single integer N indicating how many test case that your program will test followed by a blank line. Each test case will contain a single character string of up to 80 non-blank characters. Two consecutive input will separated by a blank line.

Output
An integer denoting the smallest period of the input string for each input. Two consecutive output are separated by a blank line.

Sample Input
1

HoHoHo

Sample Output

2
*/

#include <stdio.h>
#include <string.h>
#define max 80+20
int main() {
	freopen("periodstrings.in","r",stdin);
	freopen("periodstrings.out","w",stdout);
    int n;
	scanf("%d",&n);
	while(n--) {

		char s[max];
		scanf("%s",s);
		int len=strlen(s);
		int t,flag=0;
		for (t=1;t<len;t++) {
			if(len%t == 0) {
				for (int j=t;j<len;j++) {
					if(s[j]==s[j%t]) {
						flag++;
					} else break;
				}
				if(flag==len-t) {
					printf("%d\n",t);
					break;
				} 
				
			}
		}
		if(t == len)
		printf("%d\n",t);
        if(n)
		printf("\n");
	}
	return 0;
}

/*
#include<stdio.h>  
#include<string.h>  
#include<ctype.h>  
#define max 100+10  
char s[max];  
int main()  
{  
    int n, len;  
    scanf("%d", &n);  
    getchar();  
    while (n--)  
    {  
        getchar();  
        gets(s);  
        len = strlen(s);  
        for (int i = 1; i <= len;i++)  
        if (len%i == 0)  
        {  
            int ok = 1;  
            for (int j = i; j < len;j++)  
            if (s[j] != s[j%i])  
            {  
                ok = 0;  
                break;  
            }  
            if (ok)  
            {  
                printf("%d\n", i);  
                if (n)  
                    putchar('\n');  
                break;  
            }  
        }  
    }  
    return 0;  
}  
*/