#include <cstring>
#define MAXN 1010
#define INF 0x3f3f3f3f;
bool visited[MAXN];//保存节点是否已被访问过的信息
int path[MAXN];//保存从源点到其余各点的最短路径长度
int pre[MAXN];//保存在最短路径中当前结点的前驱结点编号
int cost[MAXN][MAXN];//保存相邻顶点之间边的权值,初始值为INF
void Dijkstra(int n,int beg)
//n为节点个数，beg为源点编号,设编号为 1-n
{
    memset(path,0x3f,sizeof(path));
    memset(visited,0,sizeof(visited));
    memset(pre,0,sizeof(pre));
    path[beg]=0;
    //visited[beg]=true;
    for(int i=0;i<n;i++) {
        int k=-1;
        int min=INF;
        for(int j=1;j<=n;j++) {
            if(!visited[j]&&path[j]<min) {
                min=path[j];
                k=j;
            }
        }
        if(k==-1) break;
        visited[k]=true;
        for(int w=1;w<=n;w++) {
            if(!visited[w]&&path[w]>path[k]+cost[k][w]) {
                path[w]=path[k]+cost[k][w];
                pre[w]=k;
            }
        }
    }
}
