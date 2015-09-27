#include <cstdio>

int main() {
	char ch[3];
	int tc, count=0;

	scanf("%d", &tc);
	while(tc--) {
		count++;
		for(int i=0;i<52;i++) {
			scanf("%s", ch);
			if(i==32) printf("Case %d: %s\n", count, ch);
		}
	}
	return 0;
}