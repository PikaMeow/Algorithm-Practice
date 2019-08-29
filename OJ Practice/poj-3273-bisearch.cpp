/*------------------------------------
 * @Created Time : 2016/6/4 12:59:08
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
int n,m;
int a[MAXN];

bool query(int mid) {
    int g=1,sum=0;
    for(int i=1;i<=n;i++) {
        if(sum+a[i]<=mid) {
            sum+=a[i];
        } else {
            sum=a[i];
            g++;
        }
    }
    if(g>m) return false;
    else return true;
}

int solve() {
    int mid,high=0,low=0;
    for(int i=1;i<=n;i++) {
        high+=a[i];
        if(low<a[i]) low=a[i];
    }
    if(n==m) return low;
    int ans;
    while(1) {
        if(low>high) break;
        mid=(low+high)>>1;
        //printf("%d %d %d\n",low,mid,high);
        if(query(mid)) {
            ans=mid;
            high=mid-1;
        } else {
            low=mid+1;
        }
    }
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("in","r",stdin);
#endif
    while(~scanf("%d%d",&n,&m)) {
         for(int i=1;i<=n;i++) {
             scanf("%d",&a[i]);
         }
         printf("%d\n",solve());
    }
    return 0;
}
