
//归并排序的C语言实现
#include <stdio.h>
#include <math.h>
#define MAXN 100
#define INF 100000000
int a[MAXN];
void merge(int*a,int p,int q,int r) {
 int i,j,k,n1=q-p+1,n2=r-q;
 int L[MAXN],R[MAXN];
 for (i=0;i<n1;i++) {
  L[i]=a[p+i];
 }
 for (j=0;j<n2;j++) {
  R[j]=a[q+j+1];
 }
 L[n1]=R[n2]=INF;
 i=j=0;
 for (k=p;k<=r;k++) {
  if (L[i]<=R[j]) {
    a[k]=L[i];
    i+=1;
   } else {
    a[k]=R[j];
    j+=1;
   }
 }
}

void mergesort(int *a,int p,int r) {
 if(p<r) {
  int q=floor((p+r)/2);
  mergesort(a,p,q);
  mergesort(a,q+1,r);
  merge(a,p,q,r);
 }
} 
int main () {
 freopen("mergesort.in","r",stdin);
 freopen("mergesort.out","w",stdout);
 int x,i=0,j;
 while(scanf("%d",&x)!=EOF) {
  a[i]=x;
  i++;
 }
 mergesort(a,0,i-1);
 for (j=0;j<i;j++) {
  printf("%d ",a[j]);
 }
 printf("\n");
 return 0;
}
