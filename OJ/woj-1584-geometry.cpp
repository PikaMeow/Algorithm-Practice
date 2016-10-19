/*------------------------------------
 * @Author: Ycoronene
 * @Created Time : 2016/3/6 14:43:47
 *-----------------------------------*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        int x,y,X,Y,d;
        scanf("%d%d%d%d%d",&x,&y,&X,&Y,&d);
        double r=acos(-1)/180*d;
        double l=sqrt((x-X)*(x-X)+(y-Y)*(y-Y));
        double a=atan2(y-Y,x-X);
        double rx=X+l*cos(r+a);
        double ry=Y+l*sin(r+a);
        printf("%.3f %.3f\n",rx,ry);
    }

    return 0;
}
