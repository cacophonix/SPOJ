/*
USER: zobayer
TASK: PHIDIAS
ALGO: dynamic programming
*/

#include <cstdio>
#include <cstring>

const int MAXS = 601, MAXN = 200;

int dp[MAXS][MAXS], h[MAXN], w[MAXN];

int solve(int w, int h) {
	if(dp[w][h] > -1) return dp[w][h];
	int &res = dp[w][h] = w * h, tmp;
	for(int i = 1; i <= (w >> 1); i++) {
		tmp = solve(i, h);
		if(tmp < res) tmp += solve(w - i, h);
		if(tmp < res) res = tmp;
	}
	for(int i = 1; i <= (h >> 1); i++) {
		tmp = solve(w, i);
		if(tmp < res) tmp += solve(w, h - i);
		if(tmp < res) res = tmp;
	}
	return res;
}

int main() {
	int test, i, H, W, n;
	scanf("%d", &test);
	while(test--) {
		scanf("%d %d %d", &W, &H, &n);
		memset(dp, -1, sizeof dp);
		for(i = 0; i < n; i++) {
			scanf("%d %d", &w[i], &h[i]);
			dp[w[i]][h[i]] = 0;
		}
		printf("%d\n", solve(W, H));
	}
	return 0;
}