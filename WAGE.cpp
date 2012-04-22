/*
USER: zobayer
TASK: WAGE
ALGO: ad-hoc
*/

#include <cstdio>
#include <cstring>
using namespace std;

char grid[128][128];
char temp[128][128];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
int r, c;

void fill(char a, char b, int i, int j) {
	int ii, jj, k;
	for(k = 0; k < 4; k++) {
		ii = i + dr[k];
		jj = j + dc[k];
		if(ii>=0 && ii < r && jj >= 0 && jj < c) {
			if(grid[ii][jj] == b) {
				temp[ii][jj] = a;
			}
		}
	}
}

int main() {
	int test, n, i, j;
	scanf("%d", &test);
	while(test--) {
		scanf("%d %d %d", &r, &c, &n);
		for(i = 0; i < r; i++) scanf("%s", grid[i]);
		while(n--) {
			memcpy(temp, grid, sizeof grid);
			for(i = 0; i < r; i++) {
				for(j = 0; j < c; j++) {
					switch(grid[i][j]) {
					case 'W': fill('W', 'A', i, j);
					break;
					case 'A': fill('A', 'G', i, j);
					break;
					case 'G': fill('G', 'W', i, j);
					break;
					}
				}
			}
			memcpy(grid, temp, sizeof grid);
		}
		for(i = 0; i < r; i++) {
			grid[i][c] = 0;
			puts(grid[i]);
		}
	}
	return 0;
}