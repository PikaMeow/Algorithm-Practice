//输出100-999的所有水仙花数
#include <stdio.h>
#include <time.h>
int main () {
 FILE *fout;
 fout = fopen("daffodil.out","wb");
 int i,j,k,n;
 for ( i=1 ;i<10; i++) {
  for (j=0;j<10;j++) {
   for (k=0;k<10;k++) {
    n = 100*i+10*j+k;
    if (n==i*i*i+j*j*j+k*k*k)
    fprintf(fout,"%d\n",n);
  }
 }
}
 fclose(fout);
 printf("Time used =%.2lf\n",(double)clock()/CLOCKS_PER_SEC);
 return 0;

}
