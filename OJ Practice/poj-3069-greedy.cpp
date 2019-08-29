#include <cstdio>
#define MAXN 1010
#include <algorithm>
using namespace std;
int r,n;
int a[MAXN];
int solve() {
    sort(a+1,a+n+1);
    int i=1,cnt=0;
    while(1) {
        int j=1;
        while(i+j<=n&&a[i+j]<=a[i]+r) j++;
        cnt++;
        if(i+j>n) break;
        i=i+j-1;
        j=1;
        while(i+j<=n&&a[i+j]<=a[i]+r) j++;
        if(i+j>n) break;
        i=i+j;
    }
    return cnt;
}
int main() {
#ifdef LOCAL
    freopen("in","r",stdin);
#endif
    while(scanf("%d%d",&r,&n)) {
        if(r==-1&&n==-1) break;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int ans=solve();
        printf("%d\n",ans);
    }
    return 0;
}


