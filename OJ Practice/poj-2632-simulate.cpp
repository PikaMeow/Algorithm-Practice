#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
struct Point{
    int x;
    int y;
    char dir;
}p[105];

struct Mv{
    int d;
    char c;
    int e;
}mt[105];

int a,b,n,m;

char chd(char c,int t,char d) {
    if(d=='R') t=4-t;
    while(t--) {
        if(c=='N') c='W';
        else if(c=='W') c='S';
        else if(c=='S') c='E';
        else if(c=='E') c='N';
    }
    return c;
}

int crash(int d,int t) {
    char dir=p[d].dir;
    if(dir=='N') {
        int e=(p[d].y+t)>b?b:(p[d].y+t);
        int min=b,pos=0;
        for(int i=1;i<=n;i++) {
            if(p[i].y>p[d].y&&p[i].y<=e&&p[i].x==p[d].x) {
                if(min>p[i].y-p[d].y) {
                    min=p[i].y-p[d].y;
                    pos=i;
                }
            }
        }
        if(pos!=0) return pos;
    }
    else if(dir=='E') {
        int e=(p[d].x)+t>a?a:(p[d].x+t);
        int min=a,pos=0;
        for(int i=1;i<=n;i++) {
            if(p[i].x>p[d].x&&p[i].x<=e&&p[i].y==p[d].y) {
            if(min>p[i].x-p[d].x) {
                 min=p[i].x-p[d].x;
                 pos=i;
                }
            }
        }
        if(pos!=0) return pos;
    }
    else if(dir=='S') {
        int e=(p[d].y-t)<1?1:(p[d].y-t);
        int min=b,pos=0;
        for(int i=1;i<=n;i++) {
            if(p[i].y<p[d].y&&p[i].y>=e&&p[i].x==p[d].x) {
            if(min>p[d].y-p[i].y) {
                 min=p[d].y-p[i].y;
                 pos=i;
                }
            }
        }
        if(pos!=0) return pos;
    }
    else if(dir=='W') {
        int e=(p[d].x-t)<1?1:(p[d].x-t);
        int min=a,pos=0;
        for(int i=1;i<=n;i++) {
            if(p[i].x<p[d].x&&p[i].x>=e&&p[i].y==p[d].y) {
            if(min>p[d].x-p[i].x) {
                 min=p[d].x-p[i].x;
                 pos=i;
                }
            }
        }
        if(pos!=0) return pos;
    }
    return 0;
}

bool forward(int d,int t) {
    int i=crash(d,t);
    if(i!=0) {
        printf("Robot %d crashes into robot %d\n",d,i);
        return false;
    }
    int flag=0;
    if(p[d].dir=='E'&&p[d].x+t<=a) {
        p[d].x+=t;
        flag=1;
    }
    if(p[d].dir=='N'&&p[d].y+t<=b) {
         p[d].y+=t;
         flag=1;
    }
    if(p[d].dir=='W'&&p[d].x-t>=1) {
        p[d].x-=t;
        flag=1;
    }
    if(p[d].dir=='S'&&p[d].y-t>=1) {
         p[d].y-=t;
         flag=1;
    }
    if(!flag) {
        printf("Robot %d crashes into the wall\n",d);
        return false;
    }
    return true;
}

bool move(int d,char c,int e) {
    if(c=='L'||c=='R') {
        int t=e%4;
        p[d].dir=chd(p[d].dir,t,c);
    }
    if(c=='F') {
        if(!forward(d,e)) {
            return false;
        }
        //printf("%d %d %c\n",p[d].x,p[d].y,p[d].dir);
    }
    return true;
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d%d%d",&a,&b,&n,&m);
        for(int i=1;i<=n;i++) {
            int x,y;
            char c;
            cin>>x>>y>>c;
            p[i].x=x;
            p[i].y=y;
            p[i].dir=c;
            //printf("%d %d %c\n",x,y,c);
        }
        for(int i=1;i<=m;i++) {
            int d,e;
            char c;
            cin>>d>>c>>e;
            mt[i].d=d;
            mt[i].c=c;
            mt[i].e=e;
            //printf("%d %c %d\n",d,c,e);
        }
        for(int i=1;i<=m+1;i++) {
            if(i==m+1) {
                printf("OK\n");
                break;
            }
            if(!move(mt[i].d,mt[i].c,mt[i].e)) {
                break;
            }
        }
    }
    return 0;
}
