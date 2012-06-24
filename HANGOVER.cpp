/*
USER: zobayer
TASK: HANGOVER
ALGO: dynamic programming
*/

#include <cstdio>
using namespace std;

int main()
{
	double len, val[300] = {0.0};
	int i, n;
	for(i=2; val[i-2] <= 5.20; i++)
	{
		val[i-1] = val[i-2] + 1.0 / (double)i;
	}
	n = i-2;
	while(scanf("%lf", &len)==1 && len > 0.00)
	{
		for(i=1; i<=n; i++)
		{
			if(val[i]>=len)
			{
				printf("%d card(s)\n", i);
				break;
			}
		}
	}
	return 0;
}
