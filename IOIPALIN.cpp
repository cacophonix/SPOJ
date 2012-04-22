/*
USER: zobayer
TASK: IOIPALIN
ALGO: dynamic programming
*/

#include <stdio.h>
#include <stdlib.h>

const int MAX = 5005;
char str[MAX];
short dp[2][MAX];

inline int _max(const int &a, const int &b) {
	return ((a > b) ? a : b);
}

int solve(const int &len) {
	int i, j, k;
	for(i=1; i<=len; i++) {
		for(j=1, k=len; k; k--, j++) {
			if(str[i-1] == str[k-1]) dp[(i&1)][j] = 1 + dp[!(i&1)][j-1];
			else dp[(i&1)][j] = _max( dp[!(i&1)][j], dp[(i&1)][j-1] );
		}
	}
	return len - dp[len&1][len];
}

int main() {
	int len = atoi(fgets(str, MAX, stdin));
	fgets(str, MAX, stdin);
	printf("%d\n", solve(len));
	return 0;
}
