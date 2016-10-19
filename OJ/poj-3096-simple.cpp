/*------------------------------------
 * @Created Time : 2016/6/4 14:27:45
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
char str[85];
int len;
char dp[85][85][3];

bool equal(char *a,char *b) {
    if(a[1]==b[1]&&a[2]==b[2]) return true;
    else return false;
}

bool judge() {
    memset(dp,0,sizeof(dp));
    for(int i=0;i<len-1;i++) {
            dp[1][i+1][1]=str[i];
            dp[1][i+1][2]=str[i+1];
    }
    int depth=1;
    while(depth<=len-1) {
        for(int i=1;i<=len-depth-1;i++) {
            for(int j=i+1;j<=len-depth;j++) {
                if(equal(dp[depth][i],dp[depth][j])) {
                    return false;
                }
            }
        }
        for(int i=1;i<=len-depth-1;i++) {
             dp[depth+1][i][1]=dp[depth][i][1];
             dp[depth+1][i][2]=dp[depth][i+1][2];
        }
        depth++;
    }
    return true;
}

int main() {
#ifdef LOCAL
    freopen("in","r",stdin);
#endif
    while(scanf("%s",str)&&str[0]!='*') {
         len=strlen(str);
         if(len<=2) printf("%s is surprising.\n");
         else {
             if(judge()) printf("%s is surprising.\n");
             else printf("%s is NOT surprising.\n");
         }
    }
    return 0;
}
