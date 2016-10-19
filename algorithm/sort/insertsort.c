//插入排序的C语言实现
#include <stdio.h>
#define MAXN 100
int a[100];
void insertsort(int *a,int length) {
 int j;
 for (j=1;j<length;j++) {
  int key=a[j];
  int i=j-1;
  while ( i>=0 && a[i]>key) {
   a[i+1]=a[i];
   i-=1;
  }
  a[i+1]=key;
 }
}
int main() {
 FILE *fin,*fout;
 fin = fopen("insertsort.in","rb");
 fout = fopen("insertsort.out","wb");
 int x,i=0,j;
 while(fscanf(fin,"%d",&x)!=EOF) {
  a[i]=x;
  i++;
 }
 insertsort(a,i);
 for(j=0;j<i;j++) {
  fprintf(fout,"%d ",a[j]);
 }
 fprintf(fout,"\n");
 fclose(fin);
 fclose(fout);
 return 0;
}
