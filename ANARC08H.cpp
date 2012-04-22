/*
USER: zobayer
TASK: ANARC08H
ALGO: simulation
*/

#include <stdio.h>

int solve(int n, int d)
{
	register int i, a = 0;
	for(i=2; i<=n; i++)
		a = (a+d)%i;
	return a;
}

int main()
{
	int n, d;
	while(scanf("%d%d", &n, &d)==2 && n+d)
		printf("%d %d %d\n", n, d, solve(n, d) + 1);
	return 0;
}
