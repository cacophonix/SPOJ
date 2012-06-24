/*
USER: zobayer
TASK: CHICAGO
ALGO: warshall
*/

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

double grid[101][101];

int main()
{
	int n, e, u, v, i, j, k;
	double d;
	while(scanf("%d", &n)==1 && n)
	{
		scanf("%d", &e);
		memset(grid, 0, sizeof(grid));
		for(i=0; i<e; i++)
		{
			scanf("%d%d%lf", &u, &v, &d);
			grid[u][v] = grid[v][u] = d/100.0;
		}
		for(k=1; k<=n; k++)
			for(i=1; i<=n; i++)
				for(j=1; j<=n; j++)
					grid[i][j] = max(grid[i][j], grid[i][k]*grid[k][j]);
		printf("%.6lf percent\n", grid[1][n]*100.0 + 1e-10);
	}
	return 0;
}

