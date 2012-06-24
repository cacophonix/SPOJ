/*
USER: zobayer
TASK: SAMER08C
ALGO: dynamic programming
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

#define MAX 100001

using namespace std;

int dp[MAX], col[MAX], row[MAX], r, c;

int solve(int i, int n, int *a)
{
	if(i >= n) return 0;
	if(dp[i]) return dp[i];
	return dp[i] = max(a[i]+solve(i+2,n,a), solve(i+1,n,a));
}

int main()
{
	int i, j;
	while(scanf("%d%d", &r, &c)==2 && (r || c))
	{
		for(i=0; i<r; i++)
		{
			for(j=0; j<c; j++) scanf("%d", &row[j]);
			fill(dp, dp+c, 0);
			col[i] = solve(0, c, row);
		}
		fill(dp, dp+r, 0);
		printf("%d\n", solve(0,r,col));
	}
	return 0;
}
