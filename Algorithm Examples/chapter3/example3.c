//蛇形填数，在n*n方阵中填入数字，要求为蛇形
#include <stdio.h>
#include <string.h>
#define MAXM 10
int a[MAXM][MAXM];
int main ()  {
 int n,x,y,tot=0;
 scanf("%d",&n);
 memset(a,0,sizeof(a));
/* tot = a[x=0][y=n-1] =1;
 while ( tot < n*n) {
  while (x+1<n && !a[x+1][y]) a[++x][y]=++tot;
  while (y-1>=0 && !a[x][y-1]) a[x][--y]=++tot;
  while (x-1>=0 && !a[x-1][y]) a[--x][y]=++tot;
  while (y+1<n && !a[x][y+1]) a[x][++y]=++tot;
 }
*/
 tot = a[x=0][y=0] =1;
 while ( tot < n*n) {
  while (y+1<n && !a[x][y+1]) a[x][++y]=++tot;
  while (x+1<n && !a[x+1][y]) a[++x][y]=++tot;
  while (y-1>=0 && !a[x][y-1]) a[x][--y]=++tot;
  while (x-1>=0 && !a[x-1][y]) a[--x][y]=++tot;
 }
 for (x=0; x<n; x++) {
  for(y=0; y<n; y++) {
   printf("%3d",a[x][y]);
   }
  printf("\n");
 }
 return 0;
}
