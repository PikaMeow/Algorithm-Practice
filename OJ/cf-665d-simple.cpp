/*------------------------------------
 * @Created Time : 2016/5/22 17:53:57
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
const int MAXN=1010;
int n;
int a[MAXN];
int cnt;

bool is_prime(int n) {
    if(!(n&1)) return false;
    for(int i=2;i*i<=n;i++) {
        if(n%i==0) return false;
    }
    return n!=1;
}

void solve() {
    cnt=0;
    for(int i=1;i<=n;i++) if(a[i]==1) cnt++;
    if(cnt>1) {
        for(int i=1;i<=n;i++) {
            if(!(a[i]&1)) {
                if(is_prime(a[i]+1)) {
                    printf("%d\n",cnt+1);
                    for(int j=1;j<=cnt;j++) printf("1 ");
                    printf("%d\n",a[i]);
                    return;
                }
            }
        }
                 printf("%d\n",cnt);
                 for(int j=1;j<=cnt;j++) printf("1 ");
                 printf("\n");
                 return;


    } else {
        for(int i=1;i<=n;i++) {
            for(int j=i+1;j<=n;j++) {
                if(is_prime(a[i]+a[j])) {
                    printf("2\n%d %d\n",a[i],a[j]);
                    return;
                }
            }
        }
    }
    printf("1\n%d\n",a[1]);
}

int main() {
#ifdef LOCAL
    freopen("in","r",stdin);
#endif
    while(~scanf("%d",&n)) {
         for (int i=1;i<=n;i++) scanf("%d",&a[i]);
         solve();
    }
    return 0;
}
