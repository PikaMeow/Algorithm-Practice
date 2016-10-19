#include <algorithm>
#include <cstdio>
using namespace std;
#define MAXN 1000010
#define INF 0x3f3f3f3f
int l,n;
int a[MAXN];
int Min,Max;

void solve() {
    Min=0;
    Max=0;
    for(int i=1;i<=n;i++) {
        Min=max(Min,min(a[i],l-a[i]));
        Max=max(Max,max(a[i],l-a[i]));
    }
}
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&l,&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        solve();
        printf("%d %d\n",Min,Max);
    }
    return 0;
}
