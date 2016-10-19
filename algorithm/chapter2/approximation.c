//计算pi/4,直到最后一项小于10^-6
#include <stdio.h>
#include <time.h>
int main() {
 FILE *fout;
 fout = fopen("approximation.out","wb");
 int i;
 double pi;
 for ( i = 1 ; i < 1000000 ; i+=2) {
  if(i%4 ==1) pi+=1.0/i;
  else pi -= 1.0/i;
 } 
 fprintf(fout,"%lf\n",pi);
 fprintf(fout,"Time = %.2lf\n",(double)clock()/CLOCKS_PER_SEC);
 fclose(fout);
}
