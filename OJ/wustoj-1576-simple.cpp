#include <cstdio>
#define ll long long
ll fac(int n) {
    ll sum=1;
    while(n!=0) {sum*=n;n-=1;}
    return sum;
}
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        int n;
        scanf("%d",&n);
        if(n==1||n==2) printf("1\n");
        else {
        ll res=fac(n-1)/2;
        printf("%lld\n",res);
        }
    }
    return 0;
}
