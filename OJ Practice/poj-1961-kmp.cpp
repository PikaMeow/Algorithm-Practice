#include <cstdio>
#include <cstring>
#define MAXN 1000010

char c[MAXN];
int next[MAXN];

void pre(int m) {
    memset(next,0,sizeof(next));
    next[0]=-1;
    next[1]=0;
    int k=0;
    for(int i=2;i<=m;i++) {
        while(k>0&&c[k]!=c[i-1])  k=next[k];
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
/*
int kmp(int n,int m) {
    int k=0,cnt=0;
    for(int i=0;i<n;i++) {
         while(k>0&&c[k]!=c[i]) k=next[k];
         if(c[k]==c[i]) k++;
         if(k==m) {
             cnt++;
             k=0;
         }
    }
    return cnt;
}
*/

bool kmp(int n) {
    if((n%(n-next[n]))==0&&next[n]!=0) return true;
    return false;
}
int main() {
    int n,cnt=0;
    while(scanf("%d",&n)&&n!=0) {
        memset(c,0,sizeof(c));
        scanf("%s",c);
        pre(n);
        printf("Test case #%d\n",++cnt);
        for(int i=2;i<=n;i++) {
            /*
            for(int j=1;j<=i/2;j++) {
                if(i%j==0) {
                    //int res=kmp(i,j);
                    bool r=kmp(i);
                    if(r) {
                         printf("%d %d\n",i,i/j);
                         break;
                    }
            }
            */
            if(kmp(i))
                printf("%d %d\n",i,i/(i-next[i]));
        }
        printf("\n");
    }
}
