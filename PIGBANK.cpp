/*
USER: zobayer
TASK: PIGBANK
ALGO: dynamic programming
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int E, F, t, T, n, i, j, a[10001], v, w, INF=1<<28;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &E, &F);
		T = F-E;
		fill(&a[1], &a[1]+T, INF);
		a[0] = 0;
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &v, &w);
			for(j=0; j+w<=T; j++)
				if(a[j]!=INF && a[j+w] > a[j]+v)
					a[j+w] = a[j] + v;
		}
		if(a[T]!=INF) printf("The minimum amount of money in the piggy-bank is %d.\n", a[T]);
		else printf("This is impossible.\n");
	}
	return 0;
}
