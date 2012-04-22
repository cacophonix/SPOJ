/*
USER: zobayer
TASK: LABYR1
ALGO: depth first search
*/

#include <cstdio>
#include <utility>
using namespace std;

#define MAX 1111
#define I first
#define J second

char grid[MAX][MAX];
int R, C, best;
pair <int, int> next;

void dfs(int i, int j, int d)
{
	if(i<0 || i>=R || j<0 || j>=C || grid[i][j]!='.') return;
	grid[i][j] = 'v';
	dfs(i+1, j, d+1);
	dfs(i, j+1, d+1);
	dfs(i, j-1, d+1);
	dfs(i-1, j, d+1);
	grid[i][j] = '.';
	if(d > best)
	{
		best = d;
		next.I = i;
		next.J = j;
	}
}

int find()
{
	int maxlen = 0;
	if(grid[next.I][next.J]!='.') return 0;
	while(true)
	{
		best = 0;
		dfs(next.I, next.J, 0);
		if(best <= maxlen) break;
		else maxlen = best;
	}
	return maxlen;
}

int main()
{
	int t, i, j;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &C, &R);
		for(i=0; i<R; i++)
			scanf("%s", grid[i]);
		next.I = next.J = 0;
		for(i=0; i<R; i++)
			for(j=0; j<C; j++)
				if(grid[i][j]=='.')
				{
					next.I = i;
					next.J = j;
					break;
				}
		printf("Maximum rope length is %d.\n", find());
	}
	return 0;
}
