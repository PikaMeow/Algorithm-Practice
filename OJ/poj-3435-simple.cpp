/*------------------------------------
 * @Created Time : 2016/6/4 15:51:22
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
int a[110][110];

bool row(int r,int c) {
    //printf("r%d %d\n",r,c);
    for(int i=1;i<=n*n;i++) {
        if(i!=c) {
            if(a[r][i]==a[r][c]) return false;
        }
    }
    return true;
}

bool col(int r,int c) {
    //printf("c%d %d\n",r,c);
    for(int i=1;i<=n*n;i++) {
        if(i!=r) {
            if(a[i][c]==a[r][c]) return false;
        }
    }
    return true;
}

bool squ(int r,int c) {
    //printf("s%d %d\n",r,c);
     int i=r/n+((r%n)?1:0);
     int j=c/n+((c%n)?1:0);
     //printf("%d %d\n",i,j);
     for(int I=(i-1)*n+1;I<=i*n;I++) {
         for(int J=(j-1)*n+1;J<=j*n;J++) {
             if(r!=I&&c!=J) {
                 if(a[r][c]==a[I][J]) return false;
             }
         }
     }
     return true;
}

bool compare(int r,int c) {
    if(row(r,c)&&col(r,c)&&squ(r,c)) return true;
    else return false;
}

int main() {
#ifdef LOCAL
    freopen("in","r",stdin);
#endif
    while(~scanf("%d",&n)) {
        for(int i=1;i<=n*n;i++) {
            for(int j=1;j<=n*n;j++) {
                scanf("%d",&a[i][j]);
            }
        }
        /*
        for(int i=1;i<=n*n;i++) {
            for(int j=1;j<=n*n;j++) {
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }*/
        bool flag=1;
        for(int i=1;i<=n*n;i++) {
            for(int j=1;j<=n*n;j++) {
                if(a[i][j]!=0) {
                    if(!compare(i,j)) {
                         flag=0;
                         break;
                    }
                }
            }
            if(!flag) break;
        }
        if(flag) printf("CORRECT\n");
        else printf("INCORRECT\n");
    }
    return 0;
}
