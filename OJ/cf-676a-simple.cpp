/*------------------------------------
 * @Created Time : 2016/5/25 23:18:41
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
int n;
int a[MAXN];

void solve() {
    int t1,t2;
    for(int i=1;i<=n;i++) {
        if(a[i]==n) {
            t1=max(i-1,n-i);
        }
        if(a[i]==1) {
            t2=max(i-1,n-i);
        }
    }
    printf("%d\n",max(t1,t2));
}

int main() {
#ifdef LOCAL
    freopen("in","r",stdin);
#endif
    while(~scanf("%d",&n)) {
         for(int i=1;i<=n;i++) scanf("%d",&a[i]);
         solve();
    }
    return 0;

}
