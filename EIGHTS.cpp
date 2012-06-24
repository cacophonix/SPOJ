/*
USER: zobayer
TASK: EIGHTS
ALGO: math
*/

#include <stdio.h>

#define i64 long long

int main()
{
	int t; i64 k;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%lld", &k);
		printf("%lld\n", 250*(k-1) + 192);
	}
	return 0;
}
