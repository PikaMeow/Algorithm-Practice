#include <cstdio>

#define MAXN 110
int n,m;
char c[MAXN][MAXN];
void dfs(int x,int y) {
    int dx,dy;
    for(dx=-1;dx<=1;dx++) {
        for(dy=-1;dy<=1;dy++) {
            if(x+dx>=0&&x+dx<=n&&y+dy>=0&&y+dy<=m)
                if(c[x+dx][y+dy]=='W') {
                    c[x+dx][y+dy]='.';
                    dfs(x+dx,y+dy);
                }
        }
    }
}
int main() {
#ifdef LOCAL
    freopen("in","r",stdin);
#endif
    scanf("%d%d",&n,&m);
    getchar();
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
             scanf("%c",&c[i][j]);
        }
        getchar();
    }
    /*
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            printf("%c",c[i][j]);
        }
        printf("\n");
    }
    */
    int cnt=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(c[i][j]=='W') {
                 c[i][j]='.';
                 dfs(i,j);
                 cnt++;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}
