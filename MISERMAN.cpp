/*
USER: zobayer
TASK: MISERMAN
ALGO: dynamic programming
*/

#include <stdio.h>

const int MAX = 128;
const int INF = 0x7fffffff;

int dp[MAX][MAX];

inline int min(int a, int b) {
	return (a < b ? a : b);
}

int main() {
	int m, n, i, j, ans;
	scanf("%d%d", &n, &m);
	for(i = 0; i < n; i++) {
		for(j = 1; j <= m; j++)
			scanf("%d", &dp[i][j]);
		dp[i][0] = dp[i][j] = INF;
	}
	for(i = 1; i < n; i++)
		for(j = 1; j <= m; j++)
			dp[i][j] += min(dp[i-1][j], min(dp[i-1][j-1], dp[i-1][j+1]));
	for(i = n-1, ans = INF, j = 1; j <= m; j++) 
		ans = min(ans, dp[i][j]);
	printf("%d\n", ans);
	return 0;
}