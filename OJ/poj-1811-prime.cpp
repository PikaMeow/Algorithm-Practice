#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
typedef long long ll;
using namespace std;
//Miller_Rabin随机素数测试

//位运算 (a*b)%c
ll mul_mod(ll a,ll b,ll c) {
     a%=c;
     b%=c;
     ll ret=0;
     ll tmp=a;
     while(b) {
         if(b&1) {
              ret+=tmp;
              if(ret>c) ret-=c;
         }
         tmp<<=1;
         if(tmp>c) tmp-=c;
         b>>=1;
     }
     return ret;
}

//位运算 (a^n)%c
ll pow_mod(ll a,ll n,ll c) {
     ll ret=1;
     ll tmp=a%c;
     while(n) {
          if(n&1) ret=mul_mod(ret,tmp,c);
          tmp=mul_mod(tmp,tmp,c);
          n>>=1;
     }
     return ret;
}

//witness 进行 a^(n-1)=1( mod n) 判定是否为合数
bool witness(ll a,ll u,ll t,ll n) {
     ll x0=pow_mod(a,u,n);
     ll last=x0;
     for(int i=0;i<t;i++) {
         x0=mul_mod(x0,x0,n);
         if(x0==1&&last!=1&&last!=n-1) return true;
         last=x0;
     }
     if(x0!=1) return true;
     return false;
}

const int s=7;//选取基数的次数
//主函数，分解 a^(n-1) 并做判断
bool miller_rabin(ll n) {
     if(n<2) return false;
     if(n==2) return true;
     if(!(n&1)) return false;
     ll u=n-1;
     ll t=0;
     while(!(u&1)) {t++;u>>=1;}
     //srand((int)time(NULL));
     for(int i=0;i<s;i++) {
         ll a=rand()%(n-1)+1;
         if(witness(a,u,t,n)) return false;
     }
     return true;
}

//Pillard-rho 质因数分解

//求最大公约数
ll gcd(ll a,ll b) {
    ll t;
    while(b) {
        t=a;
        a=b;
        b=t%b;
    }
    if(a>=0) return a;
    else return -a;
}

//找到n的一个因数
ll pollard_rho(ll n,ll c) {
    ll i=1,k=2;
    //srand((int) time(NULL));
    ll x0=rand()%(n-1)+1;
    ll y=x0;
    while(1) {
         i++;
         x0=(mul_mod(x0,x0,n)+c)%n;
         ll d=gcd(y-x0,n);
         if(d!=1&&d!=n) return d;
         if(y==x0) return n;
         if(i==k) {y=x0;k<<=1;}
    }
}

//调用函数，存储n的所有因子在数组factor[]中
ll factor[100];
int tol;
void findfac(ll n,int k) {
    if(n==1) return;
    if(miller_rabin(n)) {factor[tol++]=n;return;}
    ll p=n;
    int c=k;
    while(p>=n) p=pollard_rho(p,c--);
    findfac(p,k);
    findfac(n/p,k);
}



int main() {
#ifdef LOCAL
    freopen("in","r",stdin);
#endif
    ll n;
    int t;
    scanf("%d",&t);
    while(t--) {
         scanf("%lld",&n);
         if(miller_rabin(n)) printf("Prime\n");
         else {
              tol=0;
              findfac(n,107);
              ll ans=factor[0];
              for(int i=1;i<tol;i++) ans=min(ans,factor[i]);
              printf("%lld\n",ans);
         }
    }

}
