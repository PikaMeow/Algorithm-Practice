/*------------------------------------
 * @Created Time : 2016/5/21 12:51:43
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
int a,ta,b,tb;
int h,m;
int tl,tr;

int solve() {
    tl=(h-5)*60+m;
    tr=tl+ta;
    int l,r;
    if(tl-tb<0) l=0;
    else l=(tl-tb)/b+1;
    if(tr>1140) tr=1140;
    r=tr/b;
    if(r*b==tr) r--;
    return r-l+1;
}

int main() {
#ifdef LOCAL
    freopen("in","r",stdin);
#endif
    while(~scanf("%d%d%d%d",&a,&ta,&b,&tb)) {
         scanf("%d:%d",&h,&m);
         //printf("%d %d\n",h,m);
         int ans=solve();
         printf("%d\n",ans);

    }
    return 0;
}
