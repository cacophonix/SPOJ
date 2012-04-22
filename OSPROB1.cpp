/*
USER: zobayer
TASK: OSPROB1
ALGO: dynamic programming
*/

#include <stdio.h>
#include <string.h>

int dp[101], sum[101], n;

int solve(int pos) {
	int i, j, ret, tmp;
	if(pos > n) return 0;
	if(dp[pos] != -1) return dp[pos];
	for(ret = 0, i = pos; i <= n; i++)
		for(j = i; j <= n && sum[j]+sum[pos-1] < sum[i]<<1; j++)
			if(ret < (tmp = sum[j]-sum[i]+solve(j+1)))
				ret = tmp;
	return dp[pos] = ret;
}

int main() {
	int t, i, ret, job;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(i = 1; i <= n; i++) {
			scanf("%d", &job);
			sum[i] = sum[i-1] + job;
		}
		memset(dp, -1, sizeof dp);
		ret = solve(1);
		printf("%d %d\n", sum[n]-ret, ret);
	}
	return 0;
}