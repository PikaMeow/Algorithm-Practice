#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#define MAXN 1010
#define MAXM 100010
#define INF 100010
using namespace std;
/*
int cost[MAXN][MAXN];
bool visited[MAXN];
int path[MAXN];
void Dijkstra(int n,int b) {
    for(int i=1;i<=n;i++) {
        visited[i]=false;
        path[i]=cost[b][i];
    }
    visited[b]=true;
    for(int i=0;i<n;i++) {
        int j;
        int min=INF;
        for(int k=1;k<=n;k++) {
            if(!visited[k]&&min>path[k]) {min=path[k];j=k;}
        }
        visited[j]=true;
        for(int w=1;w<=n;w++) {
            if(!visited[w]&&path[w]>path[j]+cost[j][w]) {
                path[w]=path[j]+cost[j][w];
            }
        }
    }
}
*/

struct EdgeNode{
    int v,cost;
    EdgeNode(int _v,int _cost):v(_v),cost(_cost){}
};

vector<EdgeNode> E[MAXM];
bool visited[MAXN];
int path[MAXN];

void addEdge(int u,int v,int cost) {
    E[u].push_back(EdgeNode(v,cost));
}

void spfa(int n,int b) {
    for(int i=1;i<=n;i++) {
        visited[i]=false;
        path[i]=INF;
}
    path[b]=0;
    visited[b]=true;
    queue<int> q;
    while(!q.empty()) q.pop();
    q.push(b);
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        visited[u]=false;
        for(int i=0;i<E[u].size();i++) {
            int v=E[u][i].v;
            if(path[v]>path[u]+E[u][i].cost) {
                path[v]=path[u]+E[u][i].cost;
                if(!visited[v]) {
                visited[v]=true;
                q.push(v);
            }
            }
    }
}
}

int main() {
    int n,m,c,d,k;
    while(scanf("%d%d%d%d%d",&n,&m,&c,&d,&k)!=EOF) {
        /*
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(i==j) cost[i][j]=0;
                else cost[i][j]=INF;
            }
        }
        */
        for(int i=1;i<=n;i++) E[i].clear();
        while(m--) {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            addEdge(u,v,w);
        }
        //Dijkstra(n,c);
        spfa(n,c);
        if(k>=path[d]) printf("%d\n",path[d]);
        else printf("Sorry\n");
    }
    return 0;
}
