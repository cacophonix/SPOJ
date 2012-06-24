/*
USER: zobayer
TASK: CZ_PROB1
ALGO: dynamic programming, math
*/

#include <cstdio>
using namespace std;

#define MAX 8100
#define LMT 90

bool flag[MAX];
int sp2[MAX];
int dp[MAX][4];

void generate()
{
	int i, j, k;
	flag[0] = flag[1] = 1;
	for(i=3; i<LMT; i+=2)
		if(!flag[i])
			for(j=i*i,k=i<<1; j<MAX; j+=k)
				flag[j] = 1;
	sp2[1] = 2;
	for(i=3,j=2; i<MAX; i+=2)
		if(!flag[i] && ((i-3)&3))
			sp2[j++] = i;
}

int solve(int n, int k)
{
	if(n==0) return (dp[n][k] = 1);
	if(dp[n][k]) return dp[n][k];
	int i, temp = 0;
	for(i=k; i>0; i--)
		if(n-i>=0)
			temp += solve(n-i, i);
	return (dp[n][k] = temp);
}

int main()
{
	generate();
	int t, n, k;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &k);
		printf("%d\n", solve(sp2[n], k));
	}
	return 0;
}
