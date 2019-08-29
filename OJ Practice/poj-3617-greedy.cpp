#include <cstdio>
#include <cstring>
#define MAXN 2010
int n;
char str[MAXN];
char t[MAXN];

void solve() {
    memset(t,0,sizeof(t));
    int b=1,e=n,k=1;
    while(k<=n) {
        bool left=false;
        for(int i=0;b+i<=e;i++) {//若两个字符相同，则比较分别向前进一个的字符的顺序
            if(str[b+i]<str[e-i]) {
                left=true;
                break;
            }
            else if(str[b+i]>str[e-i]) {
                left=false;
                break;
            }
        }
        if(left) t[k]=str[b++];
        else t[k]=str[e--];
        k++;
    }
}

int main() {
#ifdef LOCAL
    freopen("in","r",stdin);
#endif
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        getchar();
        scanf("%c",&str[i]);
    }
    solve();
    int offset=1;
    while(n>80) {
        for(int i=1;i<=80;i++) {printf("%c",t[offset++]);}
        printf("\n");
        n-=80;
    }
    for(int i=1;i<=n;i++) printf("%c",t[offset++]);
    printf("\n");
    /*
    printf("%s\n",str+1);
    printf("%s\n",str2+1);
    */
}
