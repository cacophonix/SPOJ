/*
USER: zobayer
TASK: DRAWM
ALGO: simulation
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 80, INF = (1<<20);

int main() {
	int c, i, j, n, m, now, seq[MAX];
	char grid[MAX][MAX], p;
	while(scanf("%d", &c)==1 && c > 0) {
		memset(grid, 0x20, sizeof(grid));
		for(i = 0; i <= c; i++) scanf("%d", &seq[i]);
		for(i = p = 0, m = -INF, n = INF, now = 40; i < c; i++) {
			if(seq[i] < seq[i+1]) {
				if(p=='u') now++;
				grid[now][i] = '/', p = 'u';
			}
			else if(seq[i] > seq[i+1]) {
				if(p!='u') now--;
				grid[now][i] = '\\', p = 'd';
			}
			else {
				if(p=='u') now++;
				grid[now][i] = '_', p = 'e';
			}
			n = min(now, n);
			m = max(now, m);
		}
		for(i = m; i >= n; i--) {
			for(j = c; j >= 0; j--) {
				if(grid[i][j]!=' ') break;
				grid[i][j] = 0;
			}
			puts(grid[i]);
		}
		puts("***");
	}
	return 0;
}
