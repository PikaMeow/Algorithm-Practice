/*------------------------------------
 * @Created Time : 2016/5/22 16:09:42
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
const int MAXN=2010;
struct Point{
    int x,y;
};
bool cmp(Point a,Point b) {
    if(a.x!=b.x) return a.x<b.x;
    else return a.y<b.y;
}

Point node[MAXN];
Point vec[MAXN*MAXN];
int n,tot;

void solve() {
    tot=0;
    for(int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if(i!=j) {
                tot++;
                vec[tot].x=node[i].x-node[j].x;
                vec[tot].y=node[i].y-node[j].y;
            }
        }
    }
    sort(vec+1,vec+tot+1,cmp);
    ll ans=0;
    int s=1;
    for(int i=2;i<=tot;i++) {
        if(vec[i].x==vec[i-1].x&&vec[i].y==vec[i-1].y) {
            ans+=s;
            s++;
        }
        else s=1;
    }
    printf("%I64d\n",ans/4);
}

int main() {
#ifdef LOCAL
    freopen("in","r",stdin);
#endif
    while(~scanf("%d",&n)) {
        for(int i=1;i<=n;i++) {
             scanf("%d%d",&node[i].x,&node[i].y);
        }
        solve();
    }
    return 0;
}
