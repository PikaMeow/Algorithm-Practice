//uva 213
#include <stdio.h>
#include <string.h>//使用memset
int readchar() {//实现跨行读字符
	for (;;) {
		int ch=getchar();
		if(ch!='\n'&&ch!='\r') return ch;//读取并返回一个字符，读到换行符时跳过
	}
}
int readint( int c) {//将输入的c位二进制数转换为十进制数
	int v=0;
	while(c--) {
		v=v*2+readchar()-'0';//逐位读取这个二进制数，并将其加到v上
	}
	return v;
}
int code[8][1<<8];
int readcodes() {
	memset(code,0,sizeof(code));
	code[1][0]=readchar();//直接调到下一行开始读取，如果输入已结束，会读到EOF
	for (int len=2;len<=7;len++) {
		for (int i=0;i<(1<<len)-1;i++) {//长度为len的编码最多容纳2^len-1个编码头
			int ch=getchar();
			if(ch==EOF) return 0;
			if(ch=='\n' || ch=='\r') return 1;//换行说明编码头已读取完毕，开始while循环，读取编码
			code[len][i]=ch;
		}
	}
	return 1;
}
/*样例：
!@#$%
code[1][0]=!	0
code[2][0]=@	00
code[2][1]=#	01
code[2][2]=$	10
code[3][0]=%	000

0100000101101100011100101000
首先解析为 010 00 00 10 11 011 000 111 001 0 1 000
分别表示：长度为2 @ @ $ 小节结束 长度为3 % 小节结束 长度为1 ! 小节结束 编码结束
*/
void printcodes() {
	for (int len=1;len<=7;len++) {
		for (int i=0;i<(1<<len)-1;i++) {
			if(code[len][i]==0) return;
			printf("code[%d][%d]=%c\n",len,i,code[len][i]);
		}
	}
}

int main() {
	while(readcodes()) {
		//printcodes();
		for(;;) {
			int len=readint(3);//每个小节的前三个数字表示小节中每个编码的长度，
			if(len==0) break;		
			//printf("len=%d\n",len);
			for(;;) {
				int v=readint(len);//根据编码位数读取之后的二进制数
				//printf("v=%d\n",v);
				if(v==(1<<len)-1) break;//以若干个1的二进制数指示小节结束
				putchar(code[len][v]);//将某个二进制数转换为对应编码头
			}
		}
	putchar('\n');//读取多段编码，中间要换行
	}
	return 0;
}