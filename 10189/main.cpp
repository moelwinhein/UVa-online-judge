#include <cstdio>
#include <vector>
using namespace std;
vector< vector<int> > field;
int r, c;

void read() {
	char ch;
	field.resize(r);
	for(int i=0;i<r;i++) {
		field[i].resize(c);
		for(int j=0;j<c;j++) {
			scanf("%c", &ch);
			if(ch=='\n') scanf("%c", &ch);
			if(ch=='*') field[i][j]=-1;
			else field[i][j]=0;
		}
	}
}

void process() {
	for(int m=0;m<r;m++) {
		for(int n=0;n<c;n++) {
			if(field[m][n]==-1) {
				if(n+1<c && field[m][n+1]!=-1) field[m][n+1]+=1;
				if(n-1>=0 && field[m][n-1]!=-1) field[m][n-1]+=1;
				if(m+1<r && field[m+1][n]!=-1) field[m+1][n]+=1;
				if(m-1>=0 && field[m-1][n]!=-1) field[m-1][n]+=1;
				if(m+1<r && n+1<c && field[m+1][n+1]!=-1) field[m+1][n+1]+=1;
				if(m+1<r && n-1>=0 && field[m+1][n-1]!=-1) field[m+1][n-1]+=1;
				if(m-1>=0 && n+1<c && field[m-1][n+1]!=-1) field[m-1][n+1]+=1;
				if(m-1>=0 && n-1>=0 && field[m-1][n-1]!=-1) field[m-1][n-1]+=1;

			}
		}
	}
}

void print(int num) {
	if(num!=1) printf("\n");
	printf("Field #%d:\n", num);
	for(int i=0;i<r;i++) {
		for(int j=0;j<c;j++) {
			if(field[i][j]==-1) printf("*");
			else printf("%d", field[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int num=1;
	while(scanf("%d %d", &r, &c) && (r && c)) {
		read();
		process();
		print(num++);
	}
	return 0;
}