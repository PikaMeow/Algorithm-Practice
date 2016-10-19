//uva227
/*
SampleInput
TRGSJ
XDOKI
M VLN
WPABE
UQHCF
ARRBBL0
ABCDE
FGHIJ
KLMNO
PQRS
TUVWX
AAA
LLLL0
ABCDE
FGHIJ
KLMNO
PQRS
TUVWX
AAAAABBRRRLL0
Z

SampleOutput
Puzzle #1:
T R G S J
X O K L I
M D V B N
W P   A E
U Q H C F
Puzzle #2:
A B C D
F G H I E
K L M N J
P Q R S O
T U V W X
Puzzle #3:
This puzzle has no final configuration.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
void swap(char *a,char *b) {
	char t=*a;
	*a=*b;
	*b=t;
}
int main() {
	//freopen("puzzle.in","r",stdin);
	//freopen("puzzle.out","w",stdout);
    int kase=0,line=0;
    char init;
	while ((init=getchar())!='Z') {
        char a[5][6];
        /*if(init !='Z') */a[0][0]=init;
        //else break; 
		int p,q;
		for (int i=0;i<5;i++) {
			for (int j=0;j<6;j++) {
                if(j==0&&i==0) continue;
				scanf("%c",&a[i][j]);
				if(a[i][j]==' ') {p=i;q=j;}
			}
		}
	   char ch;
		int valid=1,exit=0;
		while(scanf("%c",&ch) == 1 && !exit) {
			
			if(ch=='0'|| !valid) {exit=1;break;}
			switch(ch) {
				case 'A':
					if(p>0) {swap(&a[p][q],&a[p-1][q]);p--;}
					else valid=0;
					break;
			    case 'B':
					if(p<4) {swap(&a[p][q],&a[p+1][q]);p++;}
					else valid=0;
					break;			
				case 'L':
					if(q>0) {swap(&a[p][q],&a[p][q-1]); q--;}
					else valid=0;
					break;					
				case 'R':
					if(q<4) {swap(&a[p][q],&a[p][q+1]); q++;}
					else valid=0;
					break;
			}
		}					
		if(line) printf("\n");
		line = 1;
		printf("Puzzle #%d:\n",++kase); 
		if(valid){	
			for(int i=0;i<5;i++) {
				for(int j=0;j<5;j++) {
					if(j!=0) printf(" %c",a[i][j]);
					else printf("%c",a[i][j]);
				}
				printf("\n");
			}
		} else printf("This puzzle has no final configuration.\n");	
	}
	return 0;
}
/*
#include <stdio.h>
#include <string.h>

int main () {
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
    int cases = 0;
    int line = 0;
    char initial [5] [7];

    while ( gets (initial [0]) ) {

        if ( strcmp (initial [0], "Z") == 0 )
            return 0;

        gets (initial [1]);
        gets (initial [2]);
        gets (initial [3]);
        gets (initial [4]);

        int blank_x;
        int blank_y;

        for ( int i = 0; i < 5; i++ ) {
            for ( int j = 0; j < 5; j++ ) {
                if ( initial [i] [j] == ' ' ) {
                    blank_x = i;
                    blank_y = j;
                    i = j = 5;
                }
            }
        }

        char command [1000];
        int valid =1;
        int exit_koro = 0;

        while ( !exit_koro && gets (command)) {

            for ( int i = 0; command [i] != 0; i++ ) {

                if ( command [i] == '0' || !valid ) {
                    exit_koro = 1;
                    break;
                }

                switch (command [i]) {
                case 'A' :
                    if ( blank_x == 0 )
                        valid = 0;
                    else {
                        initial [blank_x] [blank_y] = initial [blank_x - 1] [blank_y];
                        initial [blank_x - 1] [blank_y] = ' ';
                        blank_x--;
                    }
                    break;

                case 'B' :
                    if ( blank_x == 4 )
                        valid = 0;
                    else {
                        initial [blank_x] [blank_y] = initial [blank_x + 1] [blank_y];
                        initial [blank_x + 1] [blank_y] = ' ';
                        blank_x++;
                    }
                    break;

                case 'R' :
                    if ( blank_y == 4 )
                        valid = 0;
                    else {
                        initial [blank_x] [blank_y] = initial [blank_x] [blank_y + 1];
                        initial [blank_x] [blank_y + 1] = ' ';
                        blank_y++;
                    }
                    break;

                case 'L' :
                    if ( blank_y == 0 )
                        valid = 0;
                    else {
                        initial [blank_x] [blank_y] = initial [blank_x] [blank_y - 1];
                        initial [blank_x] [blank_y - 1] = ' ';
                        blank_y--;
                    }
                    break;
                }
            }
        }

        if ( line )
            printf ("\n");
        line = 1;

        printf ("Puzzle #%d:\n", ++cases);

        if ( valid ) {
            for ( int i = 0; i < 5; i++ ) {
                printf ("%c %c %c %c %c\n", initial [i] [0], initial [i] [1],
                        initial [i] [2], initial [i] [3], initial [i] [4]);
            }
        }

        else
            printf ("This puzzle has no final configuration.\n");

    }

    return 0;
}
*/