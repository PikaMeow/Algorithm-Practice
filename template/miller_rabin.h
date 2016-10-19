//Miller_Rabin随机素数测试
//POJ不允许使用srand(),提交时注释掉即可

#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long ll;

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

const int s=7;//选取基数进行测试的次数
//主函数，分解 a^(n-1) 并做判断，返回true说明为素数
//没有对Carmichael数进一步排除处理
bool miller_rabin(ll n) {
     if(n<2) return false;
     if(n==2) return true;
     if(!(n&1)) return false;
     ll u=n-1;
     ll t=0;
     while(!(u&1)) {t++;u>>=1;}
     srand((int)time(NULL));
     for(int i=0;i<s;i++) {
         ll a=rand()%(n-1)+1;
         if(witness(a,u,t,n)) return false;
     }
     return true;
}

