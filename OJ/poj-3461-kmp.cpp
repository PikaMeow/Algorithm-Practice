#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define MAXN 10010
#define MAXM 1000010
int P[MAXN];
char s[MAXM];
char p[MAXN];
int Match() {
    int cnt=0;
    int n=strlen(s);
    int m=strlen(p);
    int k=-1;
    for(int i=0;i<n;i++) {
        while(k>=0&&p[k+1]!=s[i]) k=P[k]-1;
        if(p[k+1]==s[i]) k=k+1;
        if(k+1==m) {
            cnt++;
            k=P[k]-1;
        }
    }
    return cnt;
}

void PreMatch() {
    memset(P,0,sizeof(P));
    int m=strlen(p);
    int k=-1;
    for(int i=1;i<m;i++) {
        while(k>=0&&p[k+1]!=p[i]) k=P[k]-1;
        if(p[k+1]==p[i]) k=k+1;
        P[i]=k+1;
    }
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%s",p);
        scanf("%s",s);
        PreMatch();
        int res=Match();
        printf("%d\n",res);
    }
    return 0;
}
