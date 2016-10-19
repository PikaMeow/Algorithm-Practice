#include <cstdio>
int main() {
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF) {
        int t1=m>n?n:m;
        int t2=t1>n+m-2?n+m-2:t1;
        printf("%d\n",t2);

    }
    return 0;
}
