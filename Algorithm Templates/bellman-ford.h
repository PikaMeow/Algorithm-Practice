#include <vector>
#include <cstring>
using namespace std;
#define MAXN 1010
#define INF 0x3f3f3f3f
int path[MAXN];//记录从源点到各节点的最短路径
int pre[MAXN];//记录某节点在最短路径上的前驱节点
struct Edge
{
    int u,v;
    int cost;
    Edge(int _u=0,int _v=0,int _cost=0):u(_u),v(_v),cost(_cost) {}
};
vector<Edge> E;
bool Bellman_Ford(int n,int beg)
//顶点编号为1-n
{
    memset(path,0x3f,sizeof(path));
    memset(pre,0,sizeof(pre));
    path[beg]=0;
    for(int i=1;i<n;i++) {
        bool flag=false;
        for(int j=0;j<E.size();j++) {
            int u=E[j].u;
            int v=E[j].v;
            int cost=E[j].cost;
            if(path[v]>path[u]+cost) {
                path[v]=path[u]+cost;
                pre[v]=u;
                flag=true;
            }
        }
        if(!flag) return true;
    }
    for(int j=0;j<E.size();j++) {
         if(path[E[j].v]>path[E[j].u]+E[j].cost)
             return false;
    }
    return true;
}
