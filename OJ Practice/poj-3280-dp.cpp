#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 1010
int dp[MAXN][MAXN];
char str[MAXN];
int add[30],del[30];
int n,m;

/*
 * dp[i][j]表示把字符串str的子串s[i...j]变成回文串的最小花费
 * 如果str[i]==str[j],那么dp[i][j]=dp[i+1][j-1]
 * 否则，由于对字符的增删可在任何位置进行，所以不需要考虑位置因素，只要考虑花费即可
 * 考虑比s[i...j]少一位的子串，
 *      1.s[i+1...j] 对str[i]有增删两种操作：dp[i][j]=dp[i+1][j]+min(add[i],del[i])
 *      2.s[i...j-1] 同理，dp[i][j]=dp[i][j-1]+min(add[j],del[j])
 * 实际的花费要取两者的最小值
 * 最后要注意计算顺序，首先计算长度为2的子串，之后按子串长度递增来计算
 */
void solve() {
    memset(dp,0,sizeof(dp));
    for(int k=1;k<=m-1;k++) {
        int i=0,j=k;
        for(;j<m;i++,j++) {
            dp[i][j]=min(
                    dp[i+1][j]+min(add[str[i]-'a'],del[str[i]-'a']),
                    dp[i][j-1]+min(add[str[j]-'a'],del[str[j]-'a'])
                    );
            if(str[i]==str[j]) dp[i][j]=dp[i+1][j-1];
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in","r",stdin);
#endif
    while(~scanf("%d%d",&n,&m)) {
        scanf("%s",str);
        char tmp;
        for(int i=1;i<=n;i++) {
            getchar();
            scanf("%c",&tmp);
            scanf("%d %d",&add[tmp-'a'],&del[tmp-'a']);
            //printf("%c %d %d\n",tmp,add[tmp-'a'],del[tmp-'a']);
        }
        solve();
        /*
        for(int i=0;i<m;i++) {
            for(int j=0;j<m;j++) {
                printf("%4d ",dp[i][j]);
            }
            printf("\n");
        }
        */
        printf("%d\n",dp[0][m-1]);
    }
}
