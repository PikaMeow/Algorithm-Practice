#include <cstdio>
#include <cstring>
typedef long long ll;
#define INF 0x3f3f3f3f3f3f
ll gcd(ll a,ll b) {
    if(b==0) return a;
    else return gcd(b,a%b);
}

char str[20];
ll num;

int main() {
#ifdef LOCAL
    freopen("in","r",stdin);
#endif
    while(scanf("%s",str)) {
        int len=strlen(str);
        if(str[len-1]!='.') break;
        num=0;
        for(int i=2;i<len-3;i++) num=num*10+str[i]-'0';
        ll tmp=num;
        ll fz,fm=INF;
        for(int i=1;i<=len-5;i++) {
            tmp/=10;
            ll a=num-tmp;
            ll b=0;
            for(int j=1;j<=i;j++) b=b*10+9;
            for(int j=1;j<=len-5-i;j++) b*=10;
            //printf("%lld %lld\n",a,b);
            ll res=gcd(a,b);
            if(fm>b/res) {
                 fm=b/res;
                 fz=a/res;
            }

        }
        printf("%lld/%lld\n",fz,fm);
        //printf("%d %lld\n",len,num);
    }

}
