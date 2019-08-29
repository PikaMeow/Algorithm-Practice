#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 1010
int dp[35][MAXN];
int s[MAXN];
int a[MAXN];
int n,w,cnt;
void printa(int a[],int n) {
    for(int i=1;i<=n;i++) printf("%d ",a[i]);
    printf("\n");
}
void state() {
    for(int i=1;i<=n;i++) s[i]=1;
    cnt=1;
    for(int i=2;i<=n;i++) {
        if(a[i]==a[i-1]) s[cnt]++;
        else cnt++;
    }
    //printa(s,cnt);
}
/*
 * 首先将树的序号合并，按照连续掉苹果的个数分离开来,记作若干个状态
 * 然后分第1个树是1号树还是2号树进行讨论
 * 只是2号树在第1个时需要花费一次跑步时间才能到2号树下
 * dp[i][j]表示在跑了i次后处于状态j时所获得的最多的苹果数目
 * 则对于到达每一个状态都有两个选择：
 *      1.前一个状态在另一棵树下，花费一次跑步转移过来
 *      2.前一个状态就在这棵树下，获得了两个状态前的苹果
 * 即：dp[i][j]=max(dp[i][j-2],dp[i-1][j-1])+s[j]
 */
void solve1() {
    memset(dp,0,sizeof(dp));
    dp[0][1]=s[1];
    dp[1][2]=dp[0][1]+s[2];
    for(int i=3;i<=cnt;i+=2) dp[0][i]=dp[0][i-2]+s[i];
    for(int i=4;i<=cnt;i+=2) dp[1][i]=max(dp[0][i-1],dp[1][i-2])+s[i];
    for(int i=2;i<=w;i++) {
        for(int j=i+1;j<=cnt;j+=2) {
            dp[i][j]=max(dp[i-1][j-1],dp[i][j-2])+s[j];
        }
    }
/*
    for(int i=0;i<=w;i++) {
        for(int j=0;j<=cnt;j++) {
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }*/
}

void solve2() {
     memset(dp,0,sizeof(dp));
     dp[0][2]=s[2];
     dp[1][1]=s[1];
     for(int i=4;i<=cnt;i+=2) dp[0][i]=dp[0][i-2]+s[i];
     for(int i=3;i<=cnt;i+=2) dp[1][i]=max(dp[0][i-1],dp[1][i-2])+s[i];
     for(int i=2;i<=w;i++) {
         for(int j=i;j<=cnt;j+=2) {
             dp[i][j]=max(dp[i-1][j-1],dp[i][j-2])+s[j];
         }
     }
/*
     for(int i=0;i<=w;i++) {
        for(int j=0;j<=cnt;j++) {
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }*/

}

int main() {
#ifdef LOCAL
    freopen("in","r",stdin);
#endif
     while(scanf("%d %d",&n,&w)!=EOF) {
     for(int i=1;i<=n;i++) scanf("%d",&a[i]);
     state();
     if(a[1]==1) solve1();
     else solve2();
     int ans=-1;
     for(int i=0;i<=w;i++) {
         for(int j=i;j<=cnt;j++) {
            ans=max(ans,dp[i][j]);
         }
     }
     printf("%d\n",ans);
    }
}
