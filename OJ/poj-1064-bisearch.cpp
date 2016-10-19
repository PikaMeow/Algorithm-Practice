/*------------------------------------
 * @Created Time : 2016/6/4 18:58:57
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
int n,k;
double a[10010];
bool query(double mid) {
    int group=0;
    for(int i=1;i<=n;i++) {
         group+=(int)(a[i]/mid);
    }
    if(group>=k) return true;
    return false;
}

double bisearch() {
    double low=0,high=100010,mid;
    int t=100;
    while(t--) {
        mid=(low+high)/2;
        //printf("%.2f %.2f %.2f\n",low,mid,high);
        if(query(mid)) {
            low=mid;
        } else {
            high=mid;
        }
    }
    return high;
}

int main() {
#ifdef LOCAL
    freopen("in","r",stdin);
#endif
    while(~scanf("%d%d",&n,&k)) {
         for(int i=1;i<=n;i++) scanf("%lf",&a[i]);
    }
    //for(int i=1;i<=n;i++) printf("%.2f\n",a[i]);
    printf("%.2f\n",floor(bisearch()*100)/100);
    return 0;
}
