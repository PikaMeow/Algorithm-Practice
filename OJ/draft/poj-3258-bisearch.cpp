/*------------------------------------
 * @Created Time : 2016/6/4 22:45:31
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
const int MAXN=50010;
int l,n,m;
int a[MAXN];

bool query(int mid) {
    int pos=0;
    int num=0;
        for(int i=2;i<=n+2;i++) {
            if(a[i]-a[pos]>=mid) {
                pos=i;
                num++;
            }
        }
    num--;
    return num>=n-m;
}

int bisearch() {
     int low=0,high=l,mid,ans;
     while(1) {
         if(low>high) break;
         mid=(low+high)>>1;
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
    while(~scanf("%d %d %d",&l,&n,&m)) {
         a[1]=0;
         for (int i=2;i<=n+1;i++) scanf("%d",&a[i]);
         a[n+2]=l;
         sort(a+1,a+n+3);
         printf("%d\n",bisearch());
    }
    return 0;
}
