#include <cstdio>
#include <cstring>
struct point {
    int x;
    int y;
}p[50];

int find(point t,point *p,int l) {
    for(int i=1;i<l;i++) {
        if(t.x==p[i].x&&t.y==p[i].y) return i;
    }
    return -1;
}

int main() {
    int a,b,n;
    while(scanf("%d%d%d",&a,&b,&n)&&a+b+n!=0) {
        memset(p,0,sizeof(p));
        a%=7;
        b%=7;
        p[1].x=1;
        p[1].y=1;
        for(int i=2;;i++) {
            p[i].x=p[i-1].y;
            p[i].y=(p[i-1].x*b+p[i-1].y*a)%7;
            int loop,r=find(p[i],p,i);
            if(r==-1) continue;
            loop=i-r;
            if(n>i) {
                int tmp1=n-(r-1);
                int tmp2=tmp1%loop;
                n=(r-1)+tmp2;
                if(tmp2==0) n+=loop;
            }
            printf("%d\n",p[n].x);
            break;
        }
    }

}
