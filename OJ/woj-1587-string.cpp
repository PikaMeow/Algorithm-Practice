#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        string s;
        cin>>s;
        int n=s.length();
        int d=n/3;
        int cnt=0;
        for(int i=d;i>=1;i--) {
            for(int j=0;j<=i;j++) {
                if(j==i) {
                    for(int k=0;k<=n-3*i;k++) {
                        for(int p=0;p<=i;p++) {
                            if(p==i) {
                                cnt+=i;
                                break;
                            }
                            if(s[p]!=s[k+p+i]) break;
                        }
                        if(cnt!=0) break;
                    }
                    break;
                }
                if(s[j]!=s[n-i+j]) break;
            }
            if(cnt!=0) break;
        }
        if(cnt==0) printf("Naive Music\n");
        else {
            for(int i=0;i<cnt;i++) {
                printf("%c",s[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
