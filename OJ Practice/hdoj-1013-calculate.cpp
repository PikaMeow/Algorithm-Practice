#include <cstdio>
#include <cstring>
#define MAXN 10010
char c[MAXN];

int dg(int sum) {
    int res=0;
    while(sum!=0) {
        res+=(sum%10);
        sum/=10;
    }
    return res;
}

int main() {
    while(scanf("%s",c)&&c[0]!='0') {
        int sum=0,l=strlen(c);
        for(int i=0;i<l;i++) {
            sum+=(c[i]-48);
        }
        while(sum>=10) {
            sum=dg(sum);
        }
        /*
        do {
            sum=dg(sum);
        } while(sum>=0&&sum<=9);
        */
        printf("%d\n",sum);
        memset(c,0,sizeof(c));
    }
}
