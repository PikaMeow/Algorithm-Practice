//输入两个正整数n<m<10^6,输出..,保留5位小数
#include <stdio.h>
#include <time.h>
int main() {
 FILE *fin,*fout;
 fin = fopen("subsequence.in","rb");
 fout = fopen("subsequence.out","wb");
 int n,m;
 double sum;
 fscanf(fin,"%d%d",&n,&m);
 for ( ; n <=m ; n++ ) {
  sum += 1.0/(n*n);
 }
 fprintf(fout,"%.5lf\n",sum);
 fprintf(fout,"Time = %.3lf\n",(double)clock()/CLOCKS_PER_SEC);
 fclose(fin);
 fclose(fout);
 return 0;
}
