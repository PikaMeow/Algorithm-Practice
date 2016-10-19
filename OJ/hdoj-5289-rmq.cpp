/*------------------------------------
 * @Created Time : 2016/6/3 10:48:51
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
const int MAXN=100010;
int dp1[MAXN][20];
int dp2[MAXN][20];
int mm[MAXN];
void initRMQ(int n,int b[] ) {
    mm[0]=-1;
    //memset(dp1,0,sizeof(dp1));
    //memset(dp2,0,sizeof(dp2));
    for(int i=1;i<=n;i++) {
        mm[i]=((i&(i-1))==0)?mm[i-1]+1:mm[i-1];
        dp1[i][0]=dp2[i][0]=b[i];
    }
    for(int j=1;j<=mm[n];j++) {
        for(int i=1;i+(1<<j)-1<=n;i++) {
            dp1[i][j]=max(dp1[i][j-1],dp1[i+(1<<(j-1))][j-1]);
            dp2[i][j]=min(dp2[i][j-1],dp2[i+(1<<(j-1))][j-1]);
        }
    }
}

int rmq(int x,int y) {
     int k=mm[y-x+1];
     return max(dp1[x][k],dp1[y-(1<<k)+1][k])-min(dp2[x][k],dp2[y-(1<<k)+1][k]);
}

int t,n,k;
int a[MAXN];
int main() {
#ifdef LOCAL
    freopen("in","r",stdin);
#endif
    scanf("%d",&t);
    while(t--) {
         scanf("%d %d",&n,&k);
         for(int i=1;i<=n;i++) scanf("%d",&a[i]);
         initRMQ(n,a);
         /*
         for(int i=1;i<=n;i++) {
              printf("%d\n",rmq(1,i));
         }
         */
         int s=1;
         ll ans=0;
         for(int i=1;i<=n;i++) {
              while(s<i&&rmq(s,i)>=k) s++;
              ans+=(i-s+1);
         }
         printf("%lld\n",ans);
    }
    return 0;
}
