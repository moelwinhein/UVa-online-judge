#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
using namespace std;

int board[8][8] = {0};

void K(int r, int c) {
	if(c+1<8 && board[r][c+1]<=0) board[r][c+1] = 1;
	if(c-1>=0 && board[r][c-1]<=0) board[r][c-1] = 1;
	if(r+1<8 && board[r+1][c]<=0) board[r+1][c] = 1;
	if(r-1>=0 && board[r-1][c]<=0) board[r-1][c] = 1;
	if(r-1>=0 && c-1>=0 && board[r-1][c-1]<=0) board[r-1][c-1] = 1;
	if(r+1<8 && c+1<8 && board[r+1][c+1]<=0) board[r+1][c+1] = 1;
	if(r-1>=0 && c+1<8 && board[r-1][c+1]<=0) board[r-1][c+1] = 1;
	if(r+1<8 && c-1>=0 && board[r+1][c-1]<=0) board[r+1][c-1] = 1;
}

void R(int r, int c) {
	int m=r, n=c;
	while(c-1>=0 && board[r][c-1]<=1) board[r][(c--)-1]=1; c=n;
	while(c+1<8 && board[r][c+1]<=1) board[r][(c++)+1]=1; c=n;
	while(r+1<8 && board[r+1][c]<=1) board[(r++)+1][c]=1; r=m;
	while(r-1>=0 && board[r-1][c]<=1) board[(r--)-1][c]=1; r=m;
}

void B(int r, int c) {
	int m=r, n=c;
	while(r+1<8 && c+1<8 && board[r+1][c+1]<=1) board[(r++)+1][(c++)+1]=1; r=m; c=n;
	while(r+1<8 && c-1>=0 && board[r+1][c-1]<=1) board[(r++)+1][(c--)-1]=1; r=m; c=n;
	while(r-1>=0 && c+1<8 && board[r-1][c+1]<=1) board[(r--)-1][(c++)+1]=1; r=m; c=n;
	while(r-1>=0 && c-1>=0 && board[r-1][c-1]<=1) board[(r--)-1][(c--)-1]=1; r=m; c=n;
}

void Q(int r, int c) {
	R(r,c);
	B(r,c);
}

void N(int r, int c) {
	if(r-2>=0 && c+1<8 && board[r-2][c+1]<=0) board[r-2][c+1] = 1;
	if(r-2>=0 && c-1>=0 && board[r-2][c-1]<=0) board[r-2][c-1] = 1;
	if(r-1>=0 && c+2<8 && board[r-1][c+2]<=0) board[r-1][c+2] = 1;
	if(r-1>=0 && c-2>=0 && board[r-1][c-2]<=0) board[r-1][c-2] = 1;
	if(r+1<8 && c+2<8 && board[r+1][c+2]<=0) board[r+1][c+2] = 1;
	if(r+1<8 && c-2>=0 && board[r+1][c-2]<=0) board[r+1][c-2] = 1;
	if(r+2<8 && c+1<8 && board[r+2][c+1]<=0) board[r+2][c+1] = 1;
	if(r+2<8 && c-1>=0 && board[r+2][c-1]<=0) board[r+2][c-1] = 1;
	
}

void p(int r, int c) {
	if(r+1<8 && c+1<8 && board[r+1][c+1]<=0) board[r+1][c+1] = 1;
	if(r+1<8 && c-1>=0 && board[r+1][c-1]<=0) board[r+1][c-1] = 1;
}

void P(int r, int c) {
	if(r-1>=0 && c-1>=0 && board[r-1][c-1]<=0) board[r-1][c-1] = 1;
	if(r-1>=0 && c+1<8 && board[r-1][c+1]<=0) board[r-1][c+1] = 1;
}

void print_board() {
	for(int i=0;i<8;i++) {
		for(int j=0;j<8;j++) {
			printf("%d\t", board[i][j]);
			if(j==7) printf("\n");
		}
	}
}

int main() {
	int r=0, c=0, count=0;
	char chr[80];
	char ch;
	memset(chr, '0', sizeof(chr));
	while(scanf("%s", chr) != EOF) {
		for(int i=0;i<sizeof(chr);i++) {
			ch=chr[i];
			if(ch=='0') break;
			if(ch=='/') {
				r++; c=0;
			}
			if(isalpha(ch)) {
				if(c<8) {
					if(ch!='p') board[r][c] = (int)toupper(ch);
					else board[r][c] = (int)ch;
					c++;
				}
			}
			else if(isdigit(ch)) {
				c += (int)(ch-'0');
			}
		}
		for(int i=0;i<8;i++) {
			for(int j=0;j<8;j++) {
				switch(board[i][j]) {
					case 75: K(i,j); break;
					case 81: Q(i,j); break;
					case 82: R(i,j); break;
					case 66: B(i,j); break;
					case 78: N(i,j); break;
					case 80: P(i,j); break;
					case 112: p(i,j); break;
					default: break;
				}
			}
		}
		for(int i=0;i<8;i++) {
			for(int j=0;j<8;j++) {
				if(board[i][j]==0) count++;
				board[i][j]=0;
			}
		}
		printf("%d\n", count);
		count=0; r=0; c=0;
		memset(chr, '0', sizeof(chr));
	}
	return 0;
}