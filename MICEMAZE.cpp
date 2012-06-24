/*
USER: zobayer
TASK: MICEMAZE
ALGO: warshall
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX 111

int main()
{
	int n, u, v, w, i, j, k, t, e, m, grid[MAX][MAX];
	scanf("%d%d%d%d", &n, &e, &t, &m);
	memset(grid, 32, sizeof(grid));
	for(i=grid[e][e]=0; i<m; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		grid[u][v] = w;
	}
	for(k=1; k<=n; k++)
		for(i=1; i<=n; i++)
			for(j=1; j<=n; j++)
				grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
	for(i=1,k=0; i<=n; i++)
		if(grid[i][e] <= t)
			k++;
	printf("%d\n", k);
	return 0;
}

