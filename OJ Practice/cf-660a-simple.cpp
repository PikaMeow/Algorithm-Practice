/*------------------------------------
 * @Created Time : 2016/5/21 15:43:32
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
int n;
const int MAXN=1010;
int a[MAXN];
int b[MAXN];
bool is_ins[MAXN];
int c[]={999999937,999999929,999999893};
int gcd(int a,int b) {
    if(b==0) return a;
    return gcd(b,a%b);
}
//在两数之间插入最大的质数或者1即可
int insert(int n) {
    if(a[n]!=c[0]&&a[n+1]!=c[0]) return c[0];
    if(a[n]!=c[1]&&a[n+1]!=c[1]) return c[1];
    if(a[n]!=c[2]&&a[n+1]!=c[2]) return c[2];
}
int main() {
#ifdef LOCAL
    freopen("in","r",stdin);
#endif
    while(~scanf("%d",&n)) {
        int cnt=0;
        memset(is_ins,0,sizeof(is_ins));
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<n;i++) {
            if(gcd(a[i],a[i+1])>1)  {
            b[i]=insert(i);
            is_ins[i]=true;
            cnt++;
            }
        }
        printf("%d\n",cnt);
        for(int i=1;i<=n;i++) {
            printf("%d ",a[i]);
            if(is_ins[i]) printf("%d ",b[i]);
        }
        printf("\n");
    }
        return 0;
}
