//#include "dijkstra-array.h"
//#include "dijkstra-queue.h"
//#include "bellman-ford.h"
//#include "spfa-queue.h"
#include "spfa-stack.h"
#include <cstdio>


void printArray1(int *a,int n)
//a为一维数组头指针，n为要输出的元素个数
{
    for(int i=1;i<=n;i++) printf("%10d ",a[i]);
    printf("\n\n");
}

void printArray2(int a[][MAXN],int n,int m) {
//a为二维数组头指针，MAXN为数组第二维的大小，n为行数,m为列数
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            printf("%10d ",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    FILE *fp=fopen("shortest_path-in","r");
    int n,m;//n为顶点数,m为边数
    while(fscanf(fp,"%d%d",&n,&m)!=EOF) {

        /*test for dijkstra-array.h
        memset(cost,0x3f,sizeof(cost));
        for(int i=1;i<=n;i++) cost[i][i]=0;
        for(int i=1;i<=m;i++) {
            int u,v,w;
            fscanf(fp,"%d%d%d",&u,&v,&w);
            cost[u][v]=w;
        }
        Dijkstra(n,2);
        printArray1(path,n);
        printArray1(pre,n);
        printArray2(cost,n,n);
        */

        /*test for dijkstra-queue.h
        for(int i=1;i<=n;i++) E[i].clear();
        for(int i=1;i<=m;i++) {
            int u,v,w;
            fscanf(fp,"%d%d%d",&u,&v,&w);
            addEdge(u,v,w);
        }
        Dijkstra(n,1);
        printArray1(path,n);
        printArray1(pre,n);
        */
        /*test for bellman-ford.h
        E.clear();
        for(int i=1;i<=m;i++) {
            int u,v,w;
            fscanf(fp,"%d%d%d",&u,&v,&w);
            E.push_back(Edge(u,v,w));
        }
        if(!Bellman_Ford(n,2)) return 1;
        printArray1(path,n);
        printArray1(pre,n);
        */
        /*test for spfa-queue.h
        for(int i=1;i<=n;i++) E[i].clear();
        for(int i=1;i<=m;i++) {
            int u,v,w;
            fscanf(fp,"%d%d%d",&u,&v,&w);
            addEdge(u,v,w);
        }
        if(!SPFA(n,2)) return 1;
        printArray1(path,n);
        printArray1(pre,n);
        */

        //test for spfa-stack.h
        for(int i=1;i<=n;i++) E[i].clear();
        for(int i=1;i<=m;i++) {
            int u,v,w;
            fscanf(fp,"%d%d%d",&u,&v,&w);
            addEdge(u,v,w);
        }
        if(!SPFA(n,1)) return 1;
        printArray1(path,n);
        printArray1(pre,n);


    }
    fclose(fp);
    return 0;
}
