//快速排序的C语言实现
#include <stdio.h>
#define MAXN 100
int a[MAXN];
void quicksort(int *a,int p,int r) {
 if (p<r) {
   int q=partition(a,p,r);
   quicksort(a,p,q-1);
   quicksort(a,q+1,r);
 }
}
int partition(int *a,int p,int r) {
 int x=a[p];
 int i=p,j;
 for (j=p+1;j<=r;j++) {
  if(a[j]<=x) {
   i+=1;
   int t=a[i];
   a[i]=a[j];
   a[j]=t;
  }
 }
 int t=a[p];
 a[p]=a[i];
 a[i]=t;
 return i;
}
int main() {
 freopen("quicksort.in","r",stdin);
 freopen("quicksort.out","w",stdout);
 int x,i=0,j;
 while(scanf("%d",&x)!=EOF) {
  a[i]=x;
  i++;
 }
 quicksort(a,0,i-1);
 for(j=0;j<i;j++) {
  printf("%d ",a[j]);
 } 
 printf("\n");
 return 0;
}
