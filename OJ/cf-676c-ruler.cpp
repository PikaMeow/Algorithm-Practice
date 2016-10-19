/*------------------------------------
 * @Created Time : 2016/5/22 12:23:29
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
int s,t,Time;
char str[MAXN];
int a[MAXN];
int n,k,res;

int ruler0() {
    int cnt=0;
    for(int i=1;i<=n;i++) if(!a[i]) cnt++;
    if(cnt<=k) {
        return n;
    }
    s=t=1;
    Time=0;
    res=0;
    for(;;) {
        while(t<=n&&Time<k) {
            while(a[t]) t++;
            Time++;
            t++;
            while(t<=n&&a[t]) t++;
        }
        if(Time<k) break;
        if(res<t-s) {
            res=t-s;
        }
        Time--;
        //printf("%d %d %d\n",res,s,t);
        if(a[s]) {
            while(a[s]) s++;
        }
        s++;
    }
    return res;
}
int ruler1() {
    int cnt=0;
    for(int i=1;i<=n;i++) if(a[i]) cnt++;
    if(cnt<=k) {
        return n;
    }
    s=t=1;
    Time=0;
    res=0;
    for(;;) {
        while(t<=n&&Time<k) {
            while(!a[t]) t++;
            Time++;
            t++;
            while(t<=n&&(!a[t])) t++;
        }
        if(Time<k) break;
        if(res<t-s) {
            res=t-s;
        }
        Time--;
        //printf("%d %d %d\n",res,s,t);
        if(!a[s]) {
            while(!a[s]) s++;
        }
        s++;
    }
    return res;
}
int main() {
#ifdef LOCAL
    freopen("in","r",stdin);
#endif
    while(~scanf("%d%d",&n,&k)) {
        scanf("%s",str+1);
        for(int i=1;i<=n;i++) {
            if(str[i]=='a') a[i]=0;
            else a[i]=1;
        }
        printf("%d\n",max(ruler0(),ruler1()));
    }
    return 0;
}
