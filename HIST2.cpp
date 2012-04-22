/*
USER: zobayer
TASK: HIST2
ALGO: dynamic programming
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef long long i64;
const int MAX = 16;

int dp[1<<MAX][MAX], a[MAX], n;
i64 np[1<<MAX][MAX];

int solve(int mask, int idx)
{
	if(mask==(1<<n)-1)
	{
		np[mask][idx] = 1;
		return a[idx];
	}
	int &ret = dp[mask][idx];
	if(ret != -1) return ret;
	ret = 0;
	for(int i = 0, val; i < n; i++)
	{
		if(!(mask & (1 << i)))
		{
			val = solve(mask | (1 << i), i) + abs(a[i]-a[idx]);
			if(val > ret)
			{
				ret = val;
				np[mask][idx] = 0;
			}
			if(val==ret) np[mask][idx] += np[mask | (1 << i)][i];
		}
	}
	return ret;
}

int main()
{
	int i, val, maxval;
	i64 cnt;
	while(scanf("%d", &n)==1 && n)
	{
		for(i = 0; i < n; i++) scanf("%d", &a[i]);
		maxval = 0;
		memset(dp, -1, sizeof dp);
		for(i = 0; i < n; i++)
		{
			val = solve(1<<i, i) + a[i];
			if(val > maxval)
			{
				maxval = val;
				cnt = 0;
			}
			if(val==maxval) cnt += np[1<<i][i];
		}
		maxval += (n << 1);
		printf("%d %lld\n", maxval, cnt);
	}
	return 0;
}
