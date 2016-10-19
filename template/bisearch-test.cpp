#include <cstdio>
#include "BiSearch.h"
#define MAXN 100
int a[MAXN];
int main() {
    freopen("bisearch-in","r",stdin);
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF) {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int t,pos;
        for(int i=1;i<=m;i++) {
            scanf("%d",&t);
            pos=BS_e(a,1,n,t);
            printf("%d\n",pos);
        }
    }
}
