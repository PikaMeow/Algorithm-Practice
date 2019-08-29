/*
#include <cstdio>
#include <iostream>
using namespace std;

#define MAXN 110
char a[MAXN][MAXN];
int visited[MAXN][MAXN];

void visit(int i,int j,int &cnt) {

}

int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                cin>>a[i][j];
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(!visited[i][j]) visit(i,j,cnt);
            }
        }

    }
}
*/

#include<cstdio>
#include<queue>
#include<string.h>
using namespace std;
const int maxn=100+5;
bool grid[maxn][maxn];
char farm[maxn][maxn];
int n,m;
int dr[4]={0,1,0,-1};
int dc[4]={1,0,-1,0};
struct node{
    int r,c;
    node(int ir,int ic){
        r=ir;c=ic;
    }
};
void init(){
    memset(grid,0,maxn*maxn);
}
bool read(){
    scanf("%d%d",&n,&m);
    if(m*n==0)return 0;
    int tn=n,count=0;
    while(tn--){
        scanf("%s",farm[count]);
        count++;
    }
    return 1;
}
bool inner(int r,int c){
    if(r<0||r>=n||c<0||c>=m)return false;
    else return true;
}
bool bfs(int r,int c){
    queue<node> qn;
    qn.push(node(r,c));
    while(!qn.empty()){
        node n1=qn.front();
        qn.pop();
        if(grid[n1.r][n1.c])continue;
        else grid[n1.r][n1.c]=1;
        for(int i=0;i<4;i++){
            int tr=n1.r+dr[i],tc=n1.c+dc[i];
            if(inner(tr,tc)&&farm[tr][tc]=='Y'&&!grid[tr][tc]){
                qn.push(node(tr,tc));
            }
        }
    }
    return 1;
}
int full_fill(){
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(farm[i][j]=='Y'&&!grid[i][j]){
                if(bfs(i,j))sum++;
            }
        }
    }
    return sum;
}
long long num_of_way(int all,int cho){
    if(all==1)return 1;
    if(cho>all/2)cho=all-cho;
    if(cho==0)return 1;
    long long ans=all;
    for(int i=0;i<cho;i++){
        ans*=--all;
        ans/=(i+1);
    }
    ans/=all;
    return ans;
}

long long pow(long long x,int n) {
    long long res=1;
    while(n>0)
    {
        if(n & 1)
        res=(res*x)%1000000007;
        x=(x*x)%1000000007;
        n >>= 1;
    }
    return res;
}
/*
long long cal(int n) {
    long long res=pow(2,n-1);
    if(n%2) return res+1;
    else return res;
}
*/
int main(){
    int ca;
    scanf("%d",&ca);
    while(ca--){
        //int n;

        init();
        if(!read()){
            printf("0\n");
            continue;
        };
        int nfarm=full_fill();
        //printf("hehe%d\n",nfarm);
        long long sum=pow(2,nfarm-1);

        //scanf("%d",&n);
        //long long sum=pow(2,n-1);
        printf("%lld\n",sum);
        /*
        for(int i=1;i<=nfarm;i+=2){
            sum+=num_of_way(nfarm,i);
        }
        */
//        printf("%lld\n",num_of_way(1,1));
//        printf("%lld\n",num_of_way(2,1));
//        printf("%lld\n",num_of_way(5000,2501));

        //printf("%lld\n",sum%1000000007);
    }
}
