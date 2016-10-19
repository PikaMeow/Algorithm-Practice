/*------------------------------------
 * @Created Time : 2016/6/5 11:46:49
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
int n,k;
priority_queue<int> pq;
int base,Time;

void greedy() {
    base=0;
    Time=0;
    int front;
    while(1) {
        front=pq.top();
        if(front<=base) break;
        pq.pop();
        front-=(k-1);
        if(front<base) front=base;
        base++;
        Time++;
        pq.push(front);
    }
}


int main() {
#ifdef LOCAL
    freopen("in","r",stdin);
#endif
    while(~scanf("%d",&n)) {
        while(!pq.empty()) pq.pop();
        for(int i=1;i<=n;i++) {
             scanf("%d",&k);
             pq.push(k);
        }
         scanf("%d",&k);
        greedy();
        printf("%d\n",Time);
    }
    return 0;
}
