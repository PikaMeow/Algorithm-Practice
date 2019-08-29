/*------------------------------------
 * @Created Time : 2016/5/21 15:16:04
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
int n,m;
int row[5][MAXN];


int main() {
#ifdef LOCAL
    freopen("in","r",stdin);
#endif
    while(~scanf("%d%d",&n,&m)) {
        int cnt=1;
        memset(row,0,sizeof(row));
        for(int i=1;i<=m&&i<=2*n;cnt++) {
            row[2][cnt]=i++;
            row[2][0]++;
            if(i>m||i>2*n) break;
            row[4][cnt]=i++;
            row[4][0]++;

        }
        cnt=1;
        if(m>2*n) {
            for(int i=2*n+1;i<=m;cnt++) {
                row[1][cnt]=i++;
                row[1][0]++;
                if(i>m) break;
                row[3][cnt]=i++;
                row[3][0]++;
            }
        }
        int r1=1,r2=1,r3=1,r4=1;
        cnt=1;
        while(cnt<=m) {
             if(r1<=row[1][0]) {printf("%d ",row[1][r1]);r1++;cnt++;}
             if(r2<=row[2][0]) {printf("%d ",row[2][r2]);r2++;cnt++;}
             if(r3<=row[3][0]) {printf("%d ",row[3][r3]);r3++;cnt++;}
             if(r4<=row[4][0]) {printf("%d ",row[4][r4]);r4++;cnt++;}
        }
        printf("\n");
    }
    return 0;
}
