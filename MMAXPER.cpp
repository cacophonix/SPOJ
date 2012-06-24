/*
USER: zobayer
TASK: MMAXPER
ALGO: dynamic programming
*/

#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define MAX 1001

struct Rect {
	int x, y;
} R[MAX];

int dp[MAX][2];

int solve(int i, int s, int n)
{
	if(i+1==n) return dp[i][s] = (s ? R[i].y : R[i].x);
	if(dp[i][s]) return dp[i][s];
	int temp1 = abs((s ? R[i].x : R[i].y) - R[i+1].x) + solve(i+1, 1, n);
	int temp2 = abs((s ? R[i].x : R[i].y) - R[i+1].y) + solve(i+1, 0, n);
	return dp[i][s] = (s ? R[i].y : R[i].x) + max(temp1, temp2);
}

int main()
{
	int i, n;
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%d%d", &R[i].x, &R[i].y);
	printf("%d\n", max(solve(0, 0, n), solve(0, 1, n)));
	return 0;
}
