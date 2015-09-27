#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int r, c, k=0, mn, mx, d;
	while(scanf("%d %d", &r, &c) && (r || c)) {
		mn = min(r,c);
		mx = max(r,c);
		if(r<=0 || c<=0) k = 0;
		else if(mn==1) k = mx;
		else if(mn==2) {
			d = mx/4;
			if(mx==(ceil(mx/4.0)*4)-1) k = (mx-((d*2)+1))*2;
			else k = (mx-(d*2))*2;
		}
		else k = ((r/2)*(c/2)) + (ceil(r/2.0)*ceil(c/2.0));

		printf("%d knights may be placed on a %d row %d column board.\n", k, r, c);
	}
	return 0;
}