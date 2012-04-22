/*
USER: zobayer
TASK: TEMPTISL
ALGO: dynamic programming
*/

#include <cstdio>
#include <cstring>
using namespace std;

typedef long long i64;

i64 dp[64][64];
int N, K, S, D;

i64 solve(int n, int k) {
	if(k == K) return n == D;
	if(dp[n][k] != -1) return dp[n][k];
	i64 &ret = dp[n][k]; ret = 0;
	int u = n + 1, v = n - 1;
	if(u == N) u = 0;
	if(v == -1) v = N-1;
	ret = solve(u, k+1) + solve(v, k+1);
	return ret;
}

int main() {
	while(scanf("%d %d", &N, &K) == 2) {
		if(N == -1 || K == -1) break;
		scanf("%d %d", &S, &D);
		S--, D--;
		memset(dp, -1, sizeof dp);
		printf("%lld\n", solve(S, 0));
	}
	return 0;
}