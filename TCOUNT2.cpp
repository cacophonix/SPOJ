/*
USER: zobayer
TASK: TCOUNT2
ALGO: math
*/

#include <stdio.h>

int main()
{
	int t;
	long double n;
	for(scanf("%d", &t); t; t--)
	{
		scanf("%Lf", &n);
		printf("%.0Lf\n", n/2.0 * (7.0*n*n + 4.5*n + 1.0));
	}
	return 0;
}
