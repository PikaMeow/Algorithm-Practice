#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAXN 1010
struct time{
    int b;
    int e;
    int f;
    bool operator < (const time & a) const{
        return b<a.b;
    }
};
time t[MAXN];
int dp[MAXN];
int n,m,r;
/*
 * 首先将所有的时间区间按照开始时间排序
 * dp[i]表示经过前i个时间段所能得到的最大的牛奶量
 * dp[i]=max(dp[j])+t[i].f  j=1,...,i-1但要满足两个时间区间相差r小时
 */
void solve() {
    memset(dp,0,sizeof(dp));
    dp[1]=t[1].f;
    for(int i=2;i<=m;i++) {
        dp[i]=t[i].f;
        for(int j=1;j<i;j++) {
            //这里不能用 if(t[i].b-t[j].e<r) 因为排序时并没有顾及到结束时间
            if(t[i].b-t[j].e>=r)
                dp[i]=max(dp[i],dp[j]+t[i].f);
        }
    }
    //for(int i=1;i<=m;i++) printf("%d ",dp[i]);
    //printf("\n");
}
int main() {
#ifdef LOCAL
    freopen("in","r",stdin);
#endif
    while(~scanf("%d%d%d",&n,&m,&r)) {
        for(int i=1;i<=m;i++) scanf("%d%d%d",&t[i].b,&t[i].e,&t[i].f);
        sort(t+1,t+m+1);
        //for(int i=1;i<=m;i++) printf("%d %d %d\n",t[i].b,t[i].e,t[i].f);
        solve();
        int ans=-1;
        for(int i=1;i<=m;i++) ans=max(ans,dp[i]);
        printf("%d\n",ans);
    }
}
