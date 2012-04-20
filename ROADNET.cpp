/*
USER: zobayer
TASK: ROADNET
ALGO: warshall
*/

#include <cstdio>
using namespace std;

int g[202][202], p[202][202];

int main()
{
	int t, n, i, j, k;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
			{
				scanf("%d", &g[i][j]);
				p[i][j] = i;
			}
		for(k=0; k<n; k++)
			for(i=0; i<n; i++) if(i!=k)
				for(j=0; j<n; j++) if(i!=k && j!=k)
					if(g[i][j] >= g[i][k] + g[k][j])
					{
						g[i][j] = g[i][k] + g[k][j];
						p[i][j] = k;
					}
		for(i=0; i<n-1; i++)
			for(j=i+1; j<n; j++)
				if(p[i][j]==i)
					printf("%d %d\n", i+1, j+1);
	}
	return 0;
}
