#include <cstdio>
#include <cstring>
#define MAXN 1010
int a[MAXN][MAXN];
int b[MAXN][MAXN];
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        int n,m;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {
            scanf("%d",&m);
            for(int j=1;j<=m;j++) {
                scanf("%d",&a[i][j]);
            }
        }
        memset(b,0,sizeof(b));
        int flag=0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<m;j++) {
                int beg=a[i][j];
                int end=a[i][j+1];
                if(b[beg][end]==0)
                    b[beg][end]=i;
                else if(b[beg][end]==i) continue;
                else {
                     flag=1;
                     break;
                }
            }
            if(flag==1) break;
        }
        if(flag==1) printf("Boom!\n");
        else printf("Good Job!\n");
    }
    return 0;
}

