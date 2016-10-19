#include <cstdio>
#include <cstring>
#define MAXN 1000010
char c[MAXN];
int next[MAXN];
void get_next(int m) {
    memset(next,0,sizeof(next));
    next[0]=-1;
    next[1]=0;
    int k=0;
    for(int i=2;i<=m;i++) {
        while(k>0&&c[k]!=c[i-1]) k=next[k];
        if(c[k]==c[i-1]) k++;
        next[i]=k;
    }
    /*
    for(int i=0;i<=m;i++) {
        printf("%d ",next[i]);
    }
    printf("\n");
    */
}

int main() {
    scanf("%s",c);
    while(c[0]!='.') {
        int m=strlen(c);
        get_next(m);
        int res=m-next[m];
        if(m%res) res=1;
        else res=m/res;
        printf("%d\n",res);
        scanf("%s",c);
    }
    return 0;
}
