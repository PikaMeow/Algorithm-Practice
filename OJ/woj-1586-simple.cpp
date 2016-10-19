/*------------------------------------
 * @Author: Ycoronene
 * @Created Time : 2016/3/6 13:20:03
 *-----------------------------------*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

char s[35];

int main() {
    char c;
    while((c=getchar())!=EOF) {
        memset(s,0,sizeof(s));
        s[0]=c;
        int length=1;
        c=getchar();
        for(int i=1;c!='\n';i++) {
            s[i]=c;
            length++;
            c=getchar();
        }
        int e=s[length-1]-'0';
        if(e==5||(!(e%2))) {
            printf("YES\n");
            continue;
        }
        int sum=0;
        for(int i=0;i<length;i++) {
            sum+=(s[i]-'0');
        }
        if(!(sum%3)) {
            printf("YES\n");
            continue;
        }
        printf("NO\n");
    }

    return 0;
}
