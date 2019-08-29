/*------------------------------------
 * @Created Time : 2016/6/4 19:43:25
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
const int INF=0x3f3f3f3f;
int n,m;
const int MAXN=100010;
int d[MAXN];

bool query(int mid) {
    int pos=1;
    int num=1;
    for(int i=2;i<=n;i++) {
        if(d[i]-d[pos]>=mid) {
            pos=i;
            num++;
        }
    }
    return num>=m;
}

int bisearch() {
     int low=0,high=INF,mid,ans;
     while(1) {
         if(low>high) break;
         mid=(low+high)>>1;
         //printf("%d %d %d\n",low,mid,high);
         if(query(mid)) {
             ans=mid;
             low=mid+1;
         } else {
             high=mid-1;
         }
     }
     return ans;
}

int main() {
#ifdef LOCAL
    freopen("in","r",stdin);
#endif
    while(~scanf("%d %d",&n,&m)) {
         for(int i=1;i<=n;i++) scanf("%d",&d[i]);
         sort(d+1,d+n+1);
         printf("%d\n",bisearch());
    }
    return 0;
}
