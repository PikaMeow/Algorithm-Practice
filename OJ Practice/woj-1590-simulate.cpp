/*------------------------------------
 * @Author: Ycoronene
 * @Created Time : 2016/3/6 12:37:51
 *-----------------------------------*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAXN 1010
#define MAXM 100010
char c[MAXN][MAXN];
char s[MAXM];
int length;
int n,m,x,y;
void Move() {
    for(int i=0;i<length;i++) {
        if(s[i]=='N') {
            while(x>1&&c[x-1][y]!='#') x--;
        }
        if(s[i]=='S') {
            while(x<n&&c[x+1][y]!='#') x++;
        }
        if(s[i]=='W') {
            while(y>1&&c[x][y-1]!='#') y--;
        }
        if(s[i]=='E') {
            while(y<m&&c[x][y+1]!='#') y++;
        }
    }
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d%d%d",&n,&m,&x,&y);
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                cin>>c[i][j];
            }
        }
        char ch;
        cin>>ch;
        length=0;
        do {
            s[length++]=ch;
        } while ((ch=getchar())!='\n');
       
        Move();
        printf("%d %d\n",x,y);
    }
    return 0;
}
