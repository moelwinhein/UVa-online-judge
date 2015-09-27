#include <cstdio>
using namespace std;

struct {
	int pts, count;
	bool a, k, q, j, s;
} suit[4];

void init() {
	for(int i=0;i<4;i++) {
		suit[i].pts=suit[i].count=0;
		suit[i].a=suit[i].k=suit[i].q=suit[i].j=suit[i].s=false;
	}
}

int calculate_pts() {
	int total=0;
	for(int i=0;i<4;i++) {
		if(suit[i].a) {
			suit[i].s = true;
		}
		if(suit[i].k) {
			if(suit[i].count<=1) {
				suit[i].pts-=1;
			}
			else suit[i].s = true;
		}
		if(suit[i].q) {
			if(suit[i].count<=2) {
				suit[i].pts-=1;
			}
			else suit[i].s = true;
		}
		if(suit[i].j) {
			if(suit[i].count<=3) {
				suit[i].pts-=1;
			}
		}
		total+=suit[i].pts;
	}
	return total;
}

int calculate_bonus() {
	int total=0;
	for(int i=0;i<4;i++) {
		if(suit[i].count<=1) suit[i].pts+=2;
		else if(suit[i].count==2) suit[i].pts+=1;
		total+=suit[i].pts;
	}
	return total;
}

bool all_stopped() {
	return suit[0].s && suit[1].s && suit[2].s && suit[3].s;
}

int max() {
	int max = -100;
	int ret=-1;
	for(int i=0;i<4;i++) {
		if(suit[i].count > max) {
			max = suit[i].count;
			ret = i;
		}
	}
	return ret;
}

int main() {
	char input[3], ch;
	int si, points;

	init();
	for(int i=0;i<13;i++) {
		if(scanf("%s", input)==EOF) break;
		switch(input[1]) {
			case 'S': si = 0; break;
			case 'H': si = 1; break;
			case 'D': si = 2; break;
			case 'C': si = 3; break;
			default : break;
		}
		suit[si].count+=1;
		switch(input[0]) {
			case 'A': 
			suit[si].a = true;
			suit[si].pts+=4;
			break;
			case 'K': 
			suit[si].k = true;
			suit[si].pts+=3;
			break;
			case 'Q': 
			suit[si].q = true;
			suit[si].pts+=2;
			break;
			case 'J': 
			suit[si].j = true;
			suit[si].pts+=1;
			break;
			default: break;
		}
		if(i==12) {
			points = calculate_pts();
			if(points >= 16 && all_stopped()) printf("BID NO-TRUMP\n");
			else if(points >= 14) {
				switch(max()) {
					case 0: ch='S'; break;
					case 1: ch='H'; break;
					case 2: ch='D'; break;
					case 3: ch='C'; break;
					default: break;
				}
				printf("BID %c\n", ch);
			}
			else {
				points = calculate_bonus();
				if(points >= 14) {
					switch(max()) {
						case 0: ch='S'; break;
						case 1: ch='H'; break;
						case 2: ch='D'; break;
						case 3: ch='C'; break;
						default: break;
					}
					printf("BID %c\n", ch);
				}
				else printf("PASS\n");
			}
			si=points=-1;
			ch='O';
			i=-1;
			init();
		}
	}

	return 0;
}