#include <cstdio>
#include <cstring>
#define MAXN 1010
char c1[MAXN];
char c2[MAXN];
int sum[MAXN];
int main() {
    int t,cnt=1;
    scanf("%d",&t);
    while(t--) {
        scanf("%s %s",c1,c2);
        int ls=0,l1=strlen(c1),l2=strlen(c2);
        memset(sum,0,sizeof(sum));
        for(int i=l1-1,j=l2-1;i>=0&&j>=0;i--,j--,ls++) {
            int tmp=(c1[i]-48)+(c2[j]-48)+sum[ls];
            if(tmp>=10) {
                sum[ls]=tmp%10;
                sum[ls+1]=tmp/10;
            } else sum[ls]=tmp;
        }
        if(l1>l2) {
            for(int i=l1-l2-1;i>=0;i--,ls++) {
                int tmp=(c1[i]-48)+sum[ls];
                if(tmp>=10) {
                     sum[ls]=tmp%10;
                     sum[ls+1]=tmp/10;
                } else sum[ls]=tmp;
            }
        }
        if(l1<l2) {
            for(int i=l2-l1-1;i>=0;i--,ls++) {
                int tmp=(c2[i]-48)+sum[ls];
                if(tmp>=10) {
                    sum[ls]=tmp/10;
                    sum[ls+1]=tmp%10;
                } else sum[ls]=tmp;
            }
        }
        if(sum[ls]!=0) ls++;
        printf("Case %d:\n",cnt++);
        for(int i=0;i<l1;i++) printf("%c",c1[i]);
        printf(" + ");
        for(int i=0;i<l2;i++) printf("%c",c2[i]);
        printf(" = ");
        for(int i=ls-1;i>=0;i--) printf("%d",sum[i]);
        printf("\n");
        if(t!=0) printf("\n");
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
    }
    return 0;
}
