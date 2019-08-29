/*------------------------------------
 * @Created Time : 2016/5/19 19:23:07
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

int a,b,c;

int main() {
#ifdef LOCAL
    freopen("in","r",stdin);
#endif
    while(~scanf("%d %d %d",&a,&b,&c)) {
         if(c==0) {
             if(b==a) printf("YES\n");
             else printf("NO\n");
            continue;
         }
         int t=b-a;
         if((t>0&&c<0)||(t<0&&c>0)) {printf("NO\n");continue;}
         if(!(t%c)) {printf("YES\n");continue;}
         printf("NO\n");

    }
    return 0;
}
