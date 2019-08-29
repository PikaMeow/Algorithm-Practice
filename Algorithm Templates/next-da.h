#define MAXN 1010
int rank[MAXN];//名次数组,[0~n-1]为有效值
int sa[MAXN];//后缀数组[1~n]为有效值
int height[MAXN];//最长公共前缀数组,[2~n]为有效值
int r[MAXN];//字符串int值数组
int cmp(int r[],int a,int b,int l)
{
    return r[a]==r[b]&&r[a+l]==r[b+l];
}
int t1[MAXN],t2[MAXN],c[MAXN];
void da(int str[],int sa[],int rank[],int height[],int n,int m)
{
    n++;
    int i,j,p,*x=t1,*y=t2,*t;
    for(i=0;i<m;i++) c[i]=0;
    for(i=0;i<n;i++) c[x[i]=str[i]]++;
    for(i=1;i<m;i++) c[i]+=c[i-1];
    for(i=n-1;i>=0;i--) sa[--c[x[i]]]=i;
    for(j=1;j<=n;j<<=1) {
        p=0;
        for(i=n-j;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0;i<m;i++) c[i]=0;
        for(i=0;i<n;i++) c[x[y[i]]]++;
        for(i=1;i<m;i++) c[i]+=c[i-1];
        for(i=n-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
        t=x;
        x=y;
        y=t;
        p=1;
        x[sa[0]]=0;
        for(i=1;i<n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
        if(p>=n) break;
        m=p;
    }
    int k=0;
    n--;
    for(i=0;i<=n;i++) rank[sa[i]]=i;
    for(i=0;i<n;i++) {
         if(k) k--;
         j=sa[rank[i]-1];
         while(str[i+k]==str[j+k]) k++;
         height[rank[i]]=k;
    }
}

