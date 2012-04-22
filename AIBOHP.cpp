/*
USER: zobayer
TASK: AIBOHP
ALGO: dynamic programming
*/

#include <stdio.h>
#include <string.h>

#define MAX 6116
#define _max(x,y) ((x>y)?x:y)

char str[MAX];
short dp[2][MAX];
int len;

int solve()
{
	int i, j, k;
	for(i=0;i<=len;i++) dp[0][i] = 0;
	dp[1][0] = 0;
	for(i=1; i<=len; i++)
	{
		for(j=1, k=len; k>0; k--, j++)
		{
			if(str[i-1] == str[k-1]) dp[(i&1)][j] = 1 + dp[!(i&1)][j-1];
			else dp[(i&1)][j] = _max( dp[!(i&1)][j], dp[(i&1)][j-1] );
		}
	}
	return len - dp[len&1][len];
}

int main(int t)
{
	for(scanf("%d", &t); t; t--)
	{
		scanf("%s", str);
		len = strlen(str);
		printf("%d\n", solve());
	}
	return 0;
}
