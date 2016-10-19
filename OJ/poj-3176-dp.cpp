#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAXN 360
int a[MAXN][MAXN];
int dp[MAXN][MAXN];
int n;
/*
 * 从上往下，到达某个位置的和的最大值等于其上方的两个位置的和的最大值
 * 加上当前位置的值，即dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]+a[i][j])
 */
void solve() {
    memset(dp,0,sizeof(dp));
    dp[1][1]=a[1][1];
    for(int i=2;i<=n;i++) {
        for(int j=1;j<=i;j++) {
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+a[i][j];
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in","r",stdin);
#endif
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=i;j++) {
            scanf("%d",&a[i][j]);
        }
    }
    solve();
    int ans=-1;
    for(int i=1;i<=n;i++) {
         ans=max(ans,dp[n][i]);
    }
    printf("%d\n",ans);
}
