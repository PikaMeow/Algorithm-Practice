/*------------------------------------
 * @Created Time : 2016/5/25 23:18:41
 *-----------------------------------*/
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <iomanip>
using namespace std;
const double eps(1e-8);
typedef long long ll;
int n,t;
double dp[15][15];
void solve() {
    memset(dp,0,sizeof(dp));
    dp[1][1]=t;
    for(int i=1;i<=n-1;i++) {
        for(int j=1;j<=i;j++) {
            if(dp[i][j]>=1.0) {
                dp[i+1][j]+=(dp[i][j]-1)/2;
                dp[i+1][j+1]+=(dp[i][j]-1)/2;
            }
        }
    }
}
int main() {
#ifdef LOCAL
    freopen("in","r",stdin);
#endif

        while(~scanf("%d%d",&n,&t)) {
        solve();
        int ans=0;
        bool flag=false;
        /*
for(int i=1;i<=10;i++) {
        for(int j=1;j<=i;j++) {
            printf("%.6f ",dp[i][j]);
        }
        printf("\n");
    }
*/
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=i;j++) {
                if(dp[i][j]>=1) ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
