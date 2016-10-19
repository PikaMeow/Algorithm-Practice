#include <cstdio>
#include <cstring>
#define MAXN 105

char c[MAXN][MAXN];
int l[MAXN];
int ans=0;
char t1[MAXN];
char t2[MAXN];

int P[MAXN];

void pre(char *p,int m) {
    memset(P,0,sizeof(P));
    int k=-1;
    for(int i=1;i<m;i++) {
        while(k>=0&&p[k+1]!=p[i]) k=P[k]-1;
        if(p[k+1]==p[i]) k++;
        P[i]=k+1;
    }
}

bool kmp(char *t,char *p,int n,int m) {
    pre(p,m);
    int k=-1;
    for(int i=0;i<n;i++) {
         while(k>=0&&p[k+1]!=t[i]) k=P[k]-1;
         if(p[k+1]==t[i]) k++;
         if(k+1==m) return true;
    }
    return false;
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        int n;
        int ans=0;
        memset(c,0,sizeof(c));
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {
            scanf("%s",c[i]);
        }
        memset(l,0,sizeof(l));
        int min=200;
        int flag=0;
        for(int i=1;i<=n;i++) {
            l[i]=strlen(c[i]);
            if(min>l[i]) {
                min=l[i];
                flag=i;
            }
        }
        /*
        for(int i=1;i<=n;i++) {
             printf("%s %d\n",c[i],l[i]);
        }
        */
        for(int i=min;i>0;i--) {
            for(int j=0;i+j<=min;j++) {
                memset(t1,0,sizeof(t1));
                memset(t2,0,sizeof(t2));
                for(int k=0;k<i;k++) {
                    t1[k]=c[flag][j+k];
                    t2[k]=c[flag][i+j-k-1];
                }
                //printf("%s %s\n",t1,t2);
                int cnt=0;
                for(int p=1;p<=n;p++) {
                    if(p!=flag) {
                        if(kmp(c[p],t1,l[p],i)||kmp(c[p],t2,l[p],i)) {
                            cnt++;
                        }
                    }
                }
                //printf("%d %d\n",cnt,ans);
                if(cnt==n-1) ans=i;
                if(ans!=0) break;
            }
            if(ans!=0) break;
        }
        printf("%d\n",ans);
    }
    return 0;
}
