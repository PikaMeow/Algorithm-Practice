#include <cstdio>


int gcd(int a,int b) {
    if(b==0) return a;
    else return gcd(b,a%b);
}

int main() {
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF) {
        int g=gcd(a,b);
        int l=a/g*b;
        printf("%d %d\n",g,l);
    }
}
