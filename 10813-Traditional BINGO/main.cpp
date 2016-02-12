#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int n;
	cin >> n;

	while (n--) {
		int num, counter = 1;
		int cards[5][5];
		int scores[5][5];

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (i == 2 && j == 2) {
					cards[i][j] = 0;
					scores[i][j] = 1;
				}
				else {
					cin >> cards[i][j];
					scores[i][j] = 0;
				}
			}
		}

		int c = 75, flag = 1;
		while (c--) {
			cin >> num;
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (num == cards[i][j]) {
						scores[i][j] = 1;
					}
				}
			}
			int sumh = 0, sumv = 0, sumd1 = 0, sumd2 = 0;
			for (int i = 0; i < 5 && flag; i++) {
				for (int j = 0; j < 5 && flag; j++) {
					sumh += scores[i][j];
					sumv += scores[j][i];
					if (i == j) sumd1 += scores[i][j];
					if (i == 4 - j) sumd2 += scores[i][j];
				}
				if (flag && (sumh == 5 || sumv == 5)) {
					printf("BINGO after %d numbers announced\n", counter);
					flag = 0;
				}
				sumh = 0; 
				sumv = 0;
			}
			if (flag && (sumd1 == 5 || sumd2 == 5)) {
				printf("BINGO after %d numbers announced\n", counter);
				flag = 0;
			}
			sumd1 = 0;
			sumd2 = 0;

			counter++;
		}
	}
	return 0;
}