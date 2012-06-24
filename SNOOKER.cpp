/*
USER: zobayer
TASK: SNOOKER
ALGO: math, gcd
*/

#include <stdio.h>

unsigned gcd(unsigned a, unsigned b)
{
	while(b) b ^= a ^= b ^= a %= b;
	return a;
}

int main()
{
	unsigned g, m, n;
	while(scanf("%u %u", &m, &n)==2 && m)
	{
		g = gcd(m, n);
		m /= g; n /= g;
		printf("%u\n", (m + n - 2) << 2);
	}
	return 0;
}
