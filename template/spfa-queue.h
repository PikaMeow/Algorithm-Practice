#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define MAXN 1010
#define INF 0x3f3f3f3f
struct Edge
{
    int v;
    int cost;
    Edge(int _v=0,int _cost=0):v(_v),cost(_cost){}
};

vector<Edge> E[MAXN];

void addEdge(int u,int v,int w)
{
    E[u].push_back(Edge(v,w));
}

bool visited[MAXN];//保存各节点是否已被访问过的信息
int cnt[MAXN];//保存每个节点入队列的次数的信息
int path[MAXN];//保存源点到各节点的最短路径的长度
int pre[MAXN];//保存各顶点在最短路径上的前驱节点的编号

bool SPFA(int n,int beg)
{
     memset(visited,0,sizeof(visited));
     memset(path,0x3f,sizeof(path));
     memset(cnt,0,sizeof(cnt));
     memset(pre,0,sizeof(pre));
     //visited[beg]=true;
     path[beg]=0;
     queue<int> que;
     que.push(beg);
     cnt[beg]=1;
     while(!que.empty()) {
          int u=que.front();
          que.pop();
          visited[u]=false;
          for(int i=0;i<E[u].size();i++) {
              int v=E[u][i].v;
              if(path[v]>path[u]+E[u][i].cost) {
                  path[v]=path[u]+E[u][i].cost;
                  pre[v]=u;
                  if(!visited[v]) {
                      visited[v]=true;
                      que.push(v);
                      if(++cnt[v]>n) return false;
                  }
              }
          }
     }
     return true;
}
