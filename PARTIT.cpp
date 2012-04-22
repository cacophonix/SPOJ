/*
USER: zobayer
TASK: PARTIT
ALGO: dynamic programming
*/

#include <cstdio>
using namespace std;

int dp[222][222][11];

int solve(int start, int total, int len) {
	int ret = 0, i;
	if(dp[start][total][len]) return dp[start][total][len]-1;
	if(len==1) ret = (start==total);
	else
		for(i=start; i*(len-1)+start<=total; i++)
			ret += solve(i, total-start, len-1);
	dp[start][total][len] = ret+1;
	return ret;
}

int main() {
	int t, m, n, k, d, v;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d%d", &m, &n, &k);
		d = 1;
		do {
			while((v=solve(d, m, n))<k) {
				d++;
				k -= v;
			}
			printf("%d", d);
			if(n > 1) printf(" ");
			m -= d;
		} while(--n);
		printf("\n");
	}
	return 0;
}
