#include <cstdio>
#include <cstring>
//#include "next-da.h"
#include "next-dc3.h"
char str[MAXN];

void printa(int a[],int n) {
    for(int i=0;i<=n;i++) printf("%d ",a[i]);
    printf("\n");
}

int main() {
    FILE* fp=fopen("next-in","r");
    while(fscanf(fp,"%s",str)!=EOF) {
        int n=strlen(str);
        for(int i=0;i<n;i++) r[i]=str[i];
        r[n]=0;
        da(r,sa,rank,height,n,128);
        printa(sa,n);
        printa(rank,n);
        printa(height,n);
    }
    fclose(fp);
}
