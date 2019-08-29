//uva 10340
#include <iostream>
#include <string>

using namespace std;
int main() {
	//char s[MAXN],t[MAXN];
	string s,t;
	char ch;
	while(cin>>s>>t) {
		//if(s[0]==EOF) break;
		int flag=0,lens=s.length(),lent=t.length();
		//printf("%d%d\n",lens,lent);
		for(int i=0,j=0;i<lens;i++) {
			for(;j<lent;j++) {
				if(s[i]==t[j]) {
					flag++;
					j++;
					break;
				} 
			}
		}
		if(flag==lens) cout<<"Yes\n";
		else cout<<"No\n";
	}
	//printf("%s\n%s\n",a,b);
	return 0;
}