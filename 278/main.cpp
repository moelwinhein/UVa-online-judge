#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int tc, m, n, c=0, t1, t2;
	char ch;

	scanf("%d", &tc);
	while(tc--) {
		scanf("%c", &ch);
		if(ch=='\n') scanf("%c", &ch);
		scanf("%d %d", &m, &n);
		switch(ch) {
			case 'K':
				c = ceil(m/2.0) * ceil(n/2.0);
				break;
			case 'Q': 
				c = min(m,n);
				break;
			case 'r':
				c = min(m,n);
				break;
			case 'k':
				c = ((m/2) * (n/2)) + (ceil(m/2.0)*ceil(n/2.0));
				break;
			default: break;
		}
		printf("%d\n", c);
	}

	return 0;
}