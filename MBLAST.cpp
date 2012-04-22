/*
USER: zobayer
TASK: MBLAST
ALGO: dynamic programming
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define min(a,b) ((a<b)?a:b)

int dp[2][2048], gap;
char s[2048], t[2048];

int main() {
	int i, j, ns, nt;
	char tmp[8];
	ns = strlen(gets(s));
	nt = strlen(gets(t));
	gap = atoi(gets(tmp));
	dp[0][0] = 0;
	for(j = 1; j <= ns; j++) dp[0][j] = j*gap;
	for(i = 1; i <= nt; i++) {
		dp[i&1][0] = i*gap;
		for(j = 1; j <= ns; j++) {
			dp[i&1][j] = min(
				dp[(i-1)&1][j-1]+abs(t[i-1]-s[j-1]),
				min(dp[i&1][j-1]+gap, dp[(i-1)&1][j]+gap)
			);
		}
	}
	printf("%d\n", dp[nt&1][ns]);
	return 0;
}