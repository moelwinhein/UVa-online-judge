#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int tc, num_players, num_snala, num_rolls, from, to, move, run=1;
	vector<int> pos(1000001, 1);
	vector<int> snala(1000001, 0);
	scanf("%d", &tc);
	while(tc--) {
		scanf("%d %d %d", &num_players, &num_snala, &num_rolls);
		while(num_snala--) {
			scanf("%d %d", &from, &to);
			snala[from] = to;
		}
		for(int i=0;i<num_rolls;i++) {
			scanf("%d", &move);
			if(run) {
				pos[(i%num_players)+1] += move;
				if(pos[(i%num_players)+1] >=100) {
					pos[(i%num_players)+1] = 100;
					run=0;
				}
				else if(snala[pos[(i%num_players)+1]]>0) {
					pos[(i%num_players)+1] = snala[pos[(i%num_players)+1]];
					if(pos[(i%num_players)+1] >=100) {
						pos[(i%num_players)+1] = 100;
						run=0;
					}
				}
			}
		}
		for(int i=0;i<num_players;i++) {
			printf("Position of player %d is %d.\n", i+1, pos[i+1]);
		}
		fill(pos.begin(), pos.end(), 1);
		fill(snala.begin(), snala.end(), 0);
		run = 1;
	}
	return 0;
}