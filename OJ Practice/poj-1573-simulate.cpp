#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int r,c,e;
int flag=0;
char a[15][15];
struct Point{
    int x,y;
}p[105];

int move(int i,char d) {
    int tmp=i;
    if(d=='N'&&p[i].x>1) {
        p[i+1].x=p[i].x-1;
        p[i+1].y=p[i].y;
        i++;
    }
    if(d=='S'&&p[i].x<r) {
        p[i+1].x=p[i].x+1;
        p[i+1].y=p[i].y;
        i++;
    }
    if(d=='E'&&p[i].y<c) {
        p[i+1].x=p[i].x;
        p[i+1].y=p[i].y+1;
        i++;
    }
    if(d=='W'&&p[i].y>1) {
         p[i+1].x=p[i].x;
         p[i+1].y=p[i].y-1;
         i++;
    }
    if(tmp==i) {
        flag=1;
        return i;
    }
    for(int j=1;j<i;j++) {
        if(p[i].x==p[j].x&&p[i].y==p[j].y) {
            flag=2;
            return i-j;
        }
    }
    return 1;
}

int main() {
    while(scanf("%d%d%d",&r,&c,&e)&&r+c+e!=0) {
        memset(a,0,sizeof(a));
        memset(p,0,sizeof(p));
        for(int i=1;i<=r;i++) {
            for(int j=1;j<=c;j++) {
                cin>>a[i][j];
            }
        }
        p[1].x=1;
        p[1].y=e;
        int i=1;
        while(1) {
             int res=move(i,a[p[i].x][p[i].y]);
             //printf("%d %d\n",p[i].x,p[i].y);
             if(flag==1) {
                  printf("%d step(s) to exit\n",res);
                  break;
             }
             if(flag==2) {
                 printf("%d step(s) before a loop of %d step(s)\n",i-res,res);
                 break;
             }
             i++;
        }
        flag=0;
/*
        for(int i=1;i<=r;i++) {
            for(int j=1;j<=c;j++) {
                printf("%c ",a[i][j]);
            }
            printf("\n");
        }
*/
    }
    return 0;
}
