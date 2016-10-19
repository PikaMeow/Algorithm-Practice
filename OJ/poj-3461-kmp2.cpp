#include <cstdio>
#include <cstring>
#define MAXN 10010
#define MAXM 1000010



char t[MAXM];
char p[MAXN];
int next[MAXN];

void pre(int m) {
    memset(next,0,sizeof(next));
    next[0]=-1;
    next[1]=0;
    int k=0;
    for(int i=2;i<=m;i++) {
        while(k>0&&p[k]!=p[i-1]) k=next[k];
        if(p[k]==p[i-1]) k++;
        next[i]=k;
    }
}

int kmp() {
    int m=strlen(p);
    int n=strlen(t);
    pre(m);
    int k=0,cnt=0;
    for(int i=0;i<n;i++) {
        while(k>0&&p[k]!=t[i]) k=next[k];
        if(p[k]==t[i]) k++;
        if(k==m) {
             cnt++;
             k=next[k];
        }
    }
    return cnt;
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        memset(t,0,sizeof(t));
        memset(p,0,sizeof(p));
        scanf("%s",p);
        scanf("%s",t);
        int ans=kmp();
        printf("%d\n",ans);
    }
}
