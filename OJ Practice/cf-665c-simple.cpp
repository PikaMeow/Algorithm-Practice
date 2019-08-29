/*------------------------------------
 * @Created Time : 2016/5/21 12:29:33
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
const int MAXN=200010;
char s[MAXN];
char c[]={'a','b','c'};
void change(int p) {
    if(s[p-1]!=c[0]&&s[p+1]!=c[0]) s[p]=c[0];
    else if(s[p-1]!=c[1]&&s[p+1]!=c[1]) s[p]=c[1];
    else if(s[p-1]!=c[2]&&s[p+1]!=c[2]) s[p]=c[2];
}
void solve() {
    int len=strlen(s);
    for(int i=0;i<len-1;i++) {
        if(s[i]!=s[i+1]) continue;
        change(i+1);
    }
}
int main() {
#ifdef LOCAL
    freopen("in","r",stdin);
#endif
    while(~scanf("%s",s)) {
         solve();
         printf("%s\n",s);
    }
    return 0;
}
