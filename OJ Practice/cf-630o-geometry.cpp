#include <cstdio>
#include <cmath>
using namespace std;
struct point {
    double x;
    double y;
};
int main() {
    int px,py,vx,vy,a,b,c,d;
    point A,B,C,D,E,F,G;
    scanf("%d%d%d%d%d%d%d%d",&px,&py,&vx,&vy,&a,&b,&c,&d);
    double Cos=vx*1.0/(sqrt(vx*vx+vy*vy));
    double Sin=vy*1.0/(sqrt(vx*vx+vy*vy));
   // printf("%.12f %.12f\n",Cos,Sin);
    A.x=px+b*Cos;
    A.y=py+b*Sin;
    B.x=px-a*Sin/2;
    B.y=py+a*Cos/2;
    C.x=px-c*Sin/2;
    C.y=py+c*Cos/2;
    D.x=C.x-d*Cos;
    D.y=C.y-d*Sin;
    E.x=D.x+c*Sin;
    E.y=D.y-c*Cos;
    F.x=E.x+d*Cos;
    F.y=E.y+d*Sin;
    G.x=px+a*Sin/2;
    G.y=py-a*Cos/2;
    printf("%.12f %.12f\n",A.x,A.y);
    printf("%.12f %.12f\n",B.x,B.y);
    printf("%.12f %.12f\n",C.x,C.y);
    printf("%.12f %.12f\n",D.x,D.y);
    printf("%.12f %.12f\n",E.x,E.y);
    printf("%.12f %.12f\n",F.x,F.y);
    printf("%.12f %.12f\n",G.x,G.y);
}
