/*
USER: zobayer
TASK: TRAVERSE
ALGO: dynamic programming
*/

#include <cstdio>
using namespace std;

char grid[16][16];
int dp[16][16];

int main() {
	int n, i, j, d;
	scanf("%d", &n);
	for(i = 0; i < n; i++) scanf("%s", grid[i]);
	dp[n-1][n-1] = 1;
	for(i = n-1; i>=0; i--) {
		for(j = n-1; j >= 0; j--) {
			if(grid[i][j] != '0') {
				d = grid[i][j]-'0';
				if(j + d < n) dp[i][j] += dp[i][j+d];
				if(i + d < n) dp[i][j] += dp[i+d][j];
			}
		}
	}
	printf("%d", dp[0][0]);
	return 0;
}