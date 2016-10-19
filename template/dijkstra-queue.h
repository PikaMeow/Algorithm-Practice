#include <queue>
#include <vector>
#include <cstring>
#define MAXN 1010
#define INF 0x3f3f3f3f
using namespace std;
bool visited[MAXN];//保存节点是否被访问过的信息
int path[MAXN];//保存从源点到各点的最短路径长度
int pre[MAXN];//保存到某节点的最短路径中其前驱节点的值
struct qnode
//保存节点v和从源点到节点的最短路径长度c
{
    int v;
    int c;
    qnode(int _v=0,int _c=0):v(_v),c(_c){}
    bool operator < (const qnode &r) const
        {return c>r.c;}
};

struct Edge
//保存以某个节点为起点的边中，终点v和边权cost
{
    int v,cost;
    Edge(int _v=0,int _cost=0):v(_v),cost(_cost){}
};

vector<Edge>E[MAXN];

void addEdge(int u,int v,int w) {
    E[u].push_back(Edge(v,w));
}


void Dijkstra(int n,int beg)
//n为节点个数，beg为源点编号，这里编号为1-n
{
    memset(visited,0,sizeof(visited));
    memset(path,0x3f,sizeof(path));
    memset(pre,0,sizeof(pre));
    priority_queue<qnode> que;
    while(!que.empty()) que.pop();
    path[beg]=0;
    que.push(qnode(beg,0));
    qnode tmp;
    while(!que.empty()) {
         tmp=que.top();
         que.pop();
         int u=tmp.v;
         if(visited[u]) continue;
         visited[u]=true;
         for(int i=0;i<E[u].size();i++) {
              int v=E[tmp.v][i].v;
              int cost=E[u][i].cost;
              if(!visited[v]&&path[v]>path[u]+cost) {
                  path[v]=path[u]+cost;
                  pre[v]=u;
                  que.push(qnode(v,path[v]));
              }
         }
    }
}
