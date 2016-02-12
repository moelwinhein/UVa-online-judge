#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int t;

	scanf("%d", &t);
	while (t--) {
		int r, c, n;

		scanf("%d %d %d", &r, &c, &n);
		char grid[r][c];
		memset(grid, 0, sizeof(grid[0][0]) * r * c);

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				char ch;
				scanf("%c", &ch);
				if (ch == '\n' || ch == ' ') j--;
				else grid[i][j] = ch;
			}
		}

		char new_grid[r][c];
		memset(new_grid, 0, sizeof(new_grid[0][0]) * r * c);
		new_grid[0][0] = grid[0][0];

		for(int k = 0; k < n; k++) {
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (grid[i][j] == 'R') {
						int ii = 0, nr, nc;

						nr = i - 1; 
						nc = j;
						if (nr >= 0 && grid[nr][nc] == 'P') ii = 1;

						nr = i + 1;
						nc = j;
						if (nr < r && grid[nr][nc] == 'P') ii = 1;

						nr = i; 
						nc = j - 1;
						if (nc >= 0 && grid[nr][nc] == 'P') ii = 1;

						nr = i;
						nc = j + 1;
						if (nc < c && grid[nr][nc] == 'P') ii = 1;
						
						if (ii)
							new_grid[i][j] = 'P';
						else
							new_grid[i][j] = 'R';
					}
					else if (grid[i][j] == 'S') {
						int ii = 0, nr, nc;

						nr = i - 1; 
						nc = j;
						if (nr >= 0 && grid[nr][nc] == 'R') ii = 1;

						nr = i + 1;
						nc = j;
						if (nr < r && grid[nr][nc] == 'R') ii = 1;

						nr = i; 
						nc = j - 1;
						if (nc >= 0 && grid[nr][nc] == 'R') ii = 1;

						nr = i;
						nc = j + 1;
						if (nc < c && grid[nr][nc] == 'R') ii = 1;
						
						if (ii)
							new_grid[i][j] = 'R';
						else
							new_grid[i][j] = 'S';
					}
					else {
						int ii = 0, nr, nc;

						nr = i - 1; 
						nc = j;
						if (nr >= 0 && grid[nr][nc] == 'S') ii = 1;

						nr = i + 1;
						nc = j;
						if (nr < r && grid[nr][nc] == 'S') ii = 1;

						nr = i; 
						nc = j - 1;
						if (nc >= 0 && grid[nr][nc] == 'S') ii = 1;

						nr = i;
						nc = j + 1;
						if (nc < c && grid[nr][nc] == 'S') ii = 1;
						
						if (ii)
							new_grid[i][j] = 'S';
						else
							new_grid[i][j] = 'P';
					}
				}
			}

			if (k != n - 1) {
				for (int m = 0; m < r; m++) {
					for (int mm = 0; mm < c; mm++) {
						grid[m][mm] = new_grid[m][mm];
					}
				}	
				memset(new_grid, 0, sizeof(new_grid[0][0]) * r * c);
			}
		}

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				printf("%c", new_grid[i][j]);
			}
			printf("\n");
		}
		if (t > 0)
			printf("\n");
	}
	return 0;
}