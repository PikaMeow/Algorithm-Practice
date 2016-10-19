#include <cstdio>
#define MAXN 1000010
const int MOD=1000000000;
int dp[MAXN];
int n;
/*
 * 1.如果i为奇数，那么只有可能在i-1的每种分解后面加一个1，因此dp[i]=dp[i-1]
 * 2.如果i为偶数，分两种情况
 *   如果i的分解中含有1,那么一定有偶数个1,相当于在i-2的每种分解后加了两个1
 *   如果i的分解中没有1,那么其种数相当于i/2的分解种数
 *   因此dp[i]=dp[i-2]+dp[i/2]
 */
void solve() {
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++) {
        if(i&1) dp[i]=dp[i-1];
        else dp[i]=(dp[i-2]+dp[i/2])%MOD;
    }
}

int main() {
    scanf("%d",&n);
    solve();
    printf("%d\n",dp[n]);
}
