#include <cstdio>
#include <cstring>
using namespace std;
#define MAXN 1010
#define MAXM 110
int n,m;
int s[MAXN];//存放每个房间的s值
int con[MAXN][5];//存放每个房间与哪些房间联通
int sum=0;//存放s值总和
int chos[MAXN];//存放第i个房间放置wifi后可以得到的s值总和

//计算在布置第pos个wifi时放在各房间所得到的s值总和，存放在chos数组中
void calS(int pos) {
    memset(chos,0,sizeof(chos));
    for(int i=1;i<=n;i++) {
        chos[i]+=s[i];
        for(int j=1;j<=con[i][0];j++) {
            chos[i]+=s[con[i][j]];
        }
    }
}

//放置第pos个wifi所能得到的最大s值和，记录下来，修正对应房间的s值，继续布置下一个
void search(int pos) {
    if(pos>m) {
        return;
    }
    int tmp=0;
    for(int i=1;i<=n;i++) {
        tmp+=s[i];
    }
    if(tmp==0) return;

    calS(pos);
    int ind=0;
    int max=-1;
    for(int i=1;i<=n;i++) {
        if(max<chos[i]) {
            max=chos[i];
            ind=i;
        }
    }
    s[ind]=0;
    for(int i=1;i<con[ind][0];i++) {
        s[con[ind][i]]=0;
    }
    sum+=max;
    search(pos+1);
}

int main() {
    #ifdef LOCAL
        freopen("in2","r",stdin);
    #endif

    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%d",&s[i]);
    }
    memset(con,0,sizeof(con));
    for(int i=1;i<n;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        con[a][++con[a][0]]=b;
        con[b][++con[b][0]]=a;
    }

    // 如果m数量比较多，可以覆盖所有房间，直接打印出结果
    if(m>=n/3+(n/3?1:0)) {
        for(int i=1;i<=n;i++) {
            sum+=s[i];
        }
        printf("%d\n",sum);
        return 0;
    }
    //放置第1个wifi
    search(1);
    printf("%d\n",sum);
}