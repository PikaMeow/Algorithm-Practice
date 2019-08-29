//Pillard-rho 质因数分解
//POJ中不允许使用srand()函数，提交时注释掉即可
#include "miller_rabin.h"

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

//找到n的一个因数,
ll pollard_rho(ll n,ll c) {
    ll i=1,k=2;
    srand((int) time(NULL));
    ll x0=rand()%(n-1)+1;
    ll y=x0;
    while(1) {
         i++;
         x0=(mul_mod(x0,x0,n)+c)%n;//f(x)=x^2+c
         ll d=gcd(y-x0,n);
         if(d!=1&&d!=n) return d;
         if(y==x0) return n;
         if(i==k) {y=x0;k<<=1;}
    }
}

//调用函数，k值需要设置为107
//存储n的所有因子在数组factor[]中(顺序不确定)
//因子的个数存储在tol中，每找一个数之前要先初始化为0
ll factor[100];
int tol;

void findfac(ll n,int k) {
    if(n==1) return;
    if(miller_rabin(n)) {factor[tol++]=n;return;}
    ll p=n;
    int c=k;
    while(p>=n) p=pollard_rho(p,c--);//改变c的值，防止死循环
    findfac(p,k);
    findfac(n/p,k);
}


