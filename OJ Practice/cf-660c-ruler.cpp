/*------------------------------------
 * @Created Time : 2016/5/22 12:23:29
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
const int MAXN=300010;
int s,t,Time;
int a[MAXN];
int n,k,res;

void ruler() {
    int cnt=0;
    for(int i=1;i<=n;i++) if(!a[i]) cnt++;
    if(cnt<=k) {
        printf("%d\n",n);
        for(int i=1;i<=n;i++) printf("1 ");
        printf("\n");
        return;
    }
    int ss,tt;
    s=t=1;
    ss=tt=0;
    Time=0;
    res=0;
    for(;;) {
        while(t<=n&&Time<k) {
            while(a[t]) t++;
            Time++;
            t++;
            while(t<=n&&a[t]) t++;
        }
        if(Time<k) break;
        if(res<t-s) {
            res=t-s;
            ss=s;
            tt=t;
        }
        Time--;
        //printf("%d %d %d\n",res,s,t);
        if(a[s]) {
            while(a[s]) s++;
        }
        s++;
    }
    for(int i=ss;i<tt;i++) a[i]=1;
    printf("%d\n",res);
    for(int i=1;i<=n;i++) printf("%d ",a[i]);
    printf("\n");
}
int main() {
#ifdef LOCAL
    freopen("in","r",stdin);
#endif
    while(~scanf("%d%d",&n,&k)) {
        for(int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
        }
        ruler();
    }
    return 0;
}
