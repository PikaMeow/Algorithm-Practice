//uva
/*
Input
Each puzzle solution in the input starts with a line containing two integers r and c (1<=r<=10,1<=c<=10) where
r (the rst number) is the number of rows in the puzzle and c (the second number) is the number of columns. 
The r rows of input which follow each contain c
characters (excluding the end-of-line) which describe the solution.  Each of those c characters is an alphabetic character which is part of a word or the
character `*', which indicates a black square.
The end of input is indicated by a line consisting of the single number `0'.

Output
Output for each puzzle consists of an identier for the puzzle (puzzle #1:,puzzle #2:
, etc.) and the list of across words followed by the list of down words. Words in each list must be output one-per-line in increasing order of the number of their corresponding denitions.
The heading for the list of across words is `Across'. The heading for the list of down words is `Down'.
In the case where the lists are empty (all squares in the grid are black), the `Across' and `Down' headings should still appear.
Separate output for successive input puzzles by a blank line.

SampleInput
2 2
AT
*O
6 7
AIM*DEN
*ME*ONE
UPON*TO
SO*ERIN
*SA*OR*
IES*DEA
0

SampleOutput
puzzle #1:
Across
  1.AT
  3.O
Down
  1.A
  2.TO
puzzle #2:
Across
  1.AIM
  4.DEN
  7.ME
  8.ONE
  9.UPON
 11.TO
 12.SO
 13.ERIN
 15.SA
 17.OR
 18.IES
 19.DEA
Down
  1.A
  2.IMPOSE
  3.MEO
  4.DO
  5.ENTIRE
  6.NEON
  9.US
 10.NE
 14.ROD
 16.AS
 18.I
 20.A
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXN 15
char a[MAXN][MAXN];
int num[MAXN][MAXN];
int main() {
  int r,c,t=1,k;
  char ch;


  while(scanf("%d",&r)==1 && r) {
    scanf("%d",&c);
    memset(num,0,sizeof(num));
    k=1;
    if(t!=1) printf("\n");
  for(int i=0; i<r; i++) {
    for(int j=0;j<c && (ch=getchar())!=EOF;){
    if(isalpha(ch)||ch=='*') {//增强程序的健壮性，以免有非法字符出现混入
      a[i][j]=ch;
    if(i==0 && ch!='*') {
      num[i][j]=k++;
    } else if(j==0 && ch !='*') {
      num[i][j]=k++;
    } else if(ch!='*' && (a[i-1][j]=='*'||a[i][j-1]=='*')) {
      num[i][j]=k++;
    }
    j++;
    }
    }
  }
  printf("puzzle #%d:\n",t++);
  printf("Across\n");
  for (int i=0;i<r;i++) {
    for (int j=0;j<c;) {
      if(a[i][j]!='*') {
        printf("%3d.",num[i][j]);
        char tmp[MAXN];
        int k=0;
        while(j<c && a[i][j]!='*') {
          tmp[k++]=a[i][j++];//读取一个完整的单词
        }
        tmp[k]='\0';
        printf("%s\n",tmp);
      }
      else j++;
    }
  }
  printf("Down\n");//纵向输出的时候也要按数字顺序输出，所以考虑因素更多一些
  for (int i=0;i<r;i++) {
    for (int j=0;j<c;) {
      if(a[i][j]!='*') {
        printf("%3d.",num[i][j]);
        char tmp[MAXN];
        int k=0,p=i;
        while(p<r && a[p][j]!='*') {
          tmp[k++]=a[p][j];
          a[p][j]='*';//按列遍历过之后，还要从第一列重新遍历一遍，但是要排除掉已经找到过的单词，所以要将遍历过的字符变为*
          p++;
        }
        tmp[k]='\0';
        printf("%s\n",tmp);
      }
      else j++;
    }
  }
  }
  return 0;
}