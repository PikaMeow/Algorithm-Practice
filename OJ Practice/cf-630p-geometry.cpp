#include <cstdio>
#include <cmath>
using namespace std;
int main() {
    int n,r;
    scanf("%d%d",&n,&r);
    double pi=acos(-1);
    double sita=(n-1)*pi/(2*n);
    double a=r*cos(sita)/cos(sita-pi/n);
    double s=a*r*sin(pi/n)*n;
    printf("%.12f\n",s);
}
