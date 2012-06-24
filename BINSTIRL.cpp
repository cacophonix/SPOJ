/*
USER: zobayer
TASK: BINSTIRL
ALGO: math
*/

#include <stdio.h>

int main()
{
	int t, n, m;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &n, &m);
		printf("%d\n", !((n-m)&((m-1)>>1)));
	}
	return 0;
}
