#include <cstdio>
#include <cstring>
#define MAXN 100010
#define INF 0x3f3f3f3f
int a[MAXN];
int s[MAXN];
int main() {
    int t,cnt=0;
    scanf("%d",&t);
    while(t--) {
        int n;
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        memset(s,0,sizeof(s));
        for(int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
        }
        s[1]=a[1];
        for(int i=2;i<=n;i++) {
            if(s[i-1]>0) s[i]=s[i-1]+a[i];
            else s[i]=a[i];
        }
        int sum=-INF;
        int begin,end=0;
        for(int i=1;i<=n;i++) {
            if(sum<s[i]) {
                sum=s[i];
                end=i;
            }
        }
        begin=end;
        for(int i=end-1;i>=1;i--) {
            if(s[i]<0||s[end]<0) break;
            begin=i;
        }
        printf("Case %d:\n%d %d %d\n",++cnt,sum,begin,end);
        if(t!=0)  printf("\n");
    }
}
