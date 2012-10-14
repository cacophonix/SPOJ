/*
USER: zobayer
TASK: WPC4F
ALGO: dynamic programming
*/

#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

int dp[20][3], cost[20][3];

int solve(int pos, int state, int n) {
	if(pos == n) return 0;
	if(dp[pos][state] != -1) return dp[pos][state];
	int &ret = dp[pos][state]; ret = INT_MAX;
	for(int i = 0; i < 3; i++) {
		if(i != state) {
			ret = min(ret, solve(pos + 1, i, n) + cost[pos][state]);
		}
	}
	return ret;
}

int main() {
	int test, n, i, ans;
	scanf("%d", &test);
	while(test--) {
		scanf("%d", &n);
		for(i = 0; i < n; i++) scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
		memset(dp, -1, sizeof dp);
		for(ans = INT_MAX, i = 0; i < 3; i++) ans = min(ans, solve(0, i, n));
		printf("%d\n", ans);
	}
	return 0;
}