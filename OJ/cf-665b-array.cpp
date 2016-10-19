/*------------------------------------
 * @Created Time : 2016/5/22 16:34:04
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
const int MAXN=110;
int cost[MAXN*MAXN];
int a[MAXN];
int n,m,k;
int ans;

void solve() {
    ans=0;
    for(int i=1;i<=n*m;i++) {
        int t1;
        for(int j=1;j<=k;j++) if(a[j]==cost[i]) {t1=j;break;}
        ans+=t1;
        for(int j=t1;j>1;j--) a[j]=a[j-1];
        a[1]=cost[i];
    }
    printf("%d\n",ans);
}

int main() {
#ifdef LOCAL
    freopen("in","r",stdin);
#endif
    while(~scanf("%d%d%d",&n,&m,&k)) {
         for(int i=1;i<=k;i++) scanf("%d",&a[i]);
         for(int i=1;i<=n*m;i++) scanf("%d",&cost[i]);
         solve();
    }
    return 0;
}
