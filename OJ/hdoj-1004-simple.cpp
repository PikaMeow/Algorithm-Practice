#include <map>
#include <cstdio>
#include <iostream>
using namespace std;
map<string,int> m;
#define MAXN 1010

int main() {
    int n;
    while(scanf("%d",&n)&&n!=0) {
        string s[MAXN];
        for(int i=1;i<=n;i++) {
            cin>>s[i];
            m[s[i]]=0;
        }
        for(int i=1;i<=n;i++) {
            m[s[i]]++;
        }
        int max=-1;
        int index=0;
        for(int i=1;i<=m.size();i++) {
            if(max<m[s[i]]) {
                max=m[s[i]];
                index=i;
            }
        }
        cout<<s[index]<<endl;
    }
    return 0;
}
