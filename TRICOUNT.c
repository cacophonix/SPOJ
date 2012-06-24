/*
USER: zobayer
TASK: TRICOUNT
ALGO: math
*/

#include <stdio.h>

int main()
{
	long long n;
	int t;
	for(scanf("%d", &t); t; t--)
	{
		scanf("%lld",&n);
		printf("%lld\n", (n * (n+2) * ((n*2)+1))/8);
	}
	return 0;
}
