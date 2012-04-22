/*
USER: zobayer
TASK: NY10E
ALGO: dynamic programming
*/

#include <cstdio>
using namespace std;

long long dp[65][10];

int main() {
	int test, cs, n, i, j, k;
	for(i = 0; i < 10; i++) dp[0][i] = 1;
	for(i = 1; i < 65; i++) {
		for(j = 0; j < 10; j++) {
			for(k = 0; k <= j; k++) {
				dp[i][j] += dp[i-1][k];
			}
		}
	}
	scanf("%d", &test);
	while(test--) {
		scanf("%d %d", &cs, &n);
		printf("%d %lld\n", cs, dp[n][9]);
	}
	return 0;
}