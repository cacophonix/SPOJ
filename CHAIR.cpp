/*
USER: zobayer
TASK: CHAIR
ALGO: dynamic programming
*/

#include <cstdio>
#include <cstring>
using namespace std;

const int mod = 1000000003;
int dp[2][1001][501];
int K, N;

int solve(int f, int n, int k) {
	if(k == K) return 1;
	if(n > N) return 0;
	if(n == N && f) return 0;
	if(dp[f][n][k] != -1) return dp[f][n][k];
	int &ret = dp[f][n][k];
	if(n==1) ret = solve(1, n+2, k+1);
	else ret = solve(f, n+2, k+1);
	ret += solve(f, n+1, k);
	return ret = ret % mod;
}

int main() {
	int ret;
	scanf("%d %d", &N, &K);
	if(K > (N >> 1)) {
		printf("0\n");
		return 0;
	}
	memset(dp, -1, sizeof dp);
	printf("%d\n", solve(0, 1, 0));
	return 0;
}