//输入正整数n<=20，输出一个n层倒三角形
#include <stdio.h>
int main () {
 FILE *fin,*fout;
 fin = fopen("triangle.in","rb");
 fout = fopen("triangle.out","wb");
 int n,i,j,k;
 fscanf(fin,"%d",&n);
 for ( i = 0; i < n; i++) {
  for (j = 0; j < i; j++) 
   fprintf(fout," ");
  for (k = i; k < 2*n-1-i;k++) 
   fprintf(fout,"#");
 fprintf(fout,"\n");
}
 fclose(fin);
 fclose(fout);
 return 0;
}
