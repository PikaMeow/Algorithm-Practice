/*------------------------------------
 * @Created Time : 2016/6/4 12:24:54
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
int value[15],amount[15];
int cash,n;
int f[MAXN];
void zero_one_pack(int v) {
    for(int i=cash;i>=v;i--) {
        f[i]=max(f[i],f[i-v]+v);
    }
}

void complete_pack(int v) {
    for(int i=v;i<=cash;i++) {
        f[i]=max(f[i],f[i-v]+v);
    }
}

void multi_pack(int v,int a) {
    if(v*a>=cash) {
         complete_pack(v);
         return;
    }
    int k=1;
    while(k<a) {
        zero_one_pack(k*v);
        a-=k;
        k*=2;
    }
    zero_one_pack(a*v);
}

int main() {
#ifdef LOCAL
    freopen("in","r",stdin);
#endif
    while(~scanf("%d %d",&cash,&n)) {
         for(int i=1;i<=n;i++) scanf("%d %d",&amount[i],&value[i]);
         memset(f,0,sizeof(f));
         for(int i=1;i<=n;i++) {
              multi_pack(value[i],amount[i]);
         }
         printf("%d\n",f[cash]);
    }
    return 0;
}
