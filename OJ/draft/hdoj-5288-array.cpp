/*------------------------------------
 * @Created Time : 2016/6/3 19:56:50
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
const int MAXM=10010;
int a[MAXN];
int b[MAXM][MAXM/2];
int n;
int one;
void initB() {
    memset(b,0,sizeof(b));
    printf("%d\n",n);
    for(int i=1;i<=n;i++) {
        if(a[i]!=1) {
    for(int j=a[i];j<=MAXM;j+=a[i]) {
    printf("%d %d\n",i,n);
         b[j][++b[j][0]]=i;

        }
        } else one=i;
    }
    printf("---\n");
}

int l[MAXN];
int r[MAXN];
void findLR() {
    for(int i=1;i<=n;i++) {
        if(i==one) {l[i]=0;r[i]=n+1;}
        else {
            int low,high,mid;
            low=b[a[i]][1];
            high=b[a[i]][b[a[i]][0]];
            while(low<=high) {
                 mid=(low+high)>>1;
                 printf("%d %d %d\n",low,mid,high);
                 if(b[a[i]][mid]==i) break;
                 else if(b[a[i]][mid]>i) {
                     high=mid-1;
                 } else {
                     low=mid+1;
                 }
            }
            if(mid==1) l[i]=0; else l[i]=b[a[i]][mid-1];
            if(mid==b[a[i]][0]) r[i]=n+1; else r[i]=b[a[i]][mid+1];
            if(one>i) r[i]=min(one,r[i]);
            else l[i]=max(one,l[i]);
        }
    }
}

ll solve() {
     ll ans=0;
     for(int i=1;i<=n;i++) {
        ans+=(i-l[i])*(r[i]-i);
     }
     return ans;
}

int main() {
#ifdef LOCAL
    freopen("in","r",stdin);
#endif
    while(~scanf("%d",&n)) {
         for(int i=1;i<=n;i++) scanf("%d",&a[i]);
         initB();
         findLR();
         printf("%lld\n",solve());
    }
    return 0;
}
