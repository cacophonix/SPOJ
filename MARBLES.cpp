/*
USER: zobayer
TASK: MARBLES
ALGO: math, combinatorics
*/

#include <stdio.h>

#define i64 unsigned long long

i64 gcd(i64 a, i64 b)
{
	i64 k;
	while(b)
	{
		a %= b;
		k = a;
		a = b;
		b = k;
	}
	return a;
}

i64 nCr(i64 n, i64 r)
{
	i64 i, j, g, k = (r > n-r)? r : n-r, m = n-k, hor = 1, lob = 1;
	for(i=k+1, j=m; i<=n && j>0; i++, j--)
	{
		hor *= j;
		lob *= i;
		g = gcd(lob, hor);
		lob /= g;
		hor /= g;
	}
	return lob;
}

int main()
{
	int t;
	i64 n, r;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%llu %llu", &n, &r);
		printf("%llu\n", nCr(n-1, r-1));
	}
	return 0;
}
