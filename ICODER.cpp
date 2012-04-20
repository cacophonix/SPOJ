/*
USER: zobayer
TASK: ICODER
ALGO: math
*/

#include <stdio.h>

const unsigned m = 65536;
const unsigned M = 65535;

unsigned gcd(unsigned a, unsigned b)
{
	while(b) b ^= a ^= b ^= a %= b;
	return a;
}

int main()
{
	register int n;
	unsigned g, v, a;
	char str[10];
	while(scanf("%d", &n)==1 && n)
	{
		a = 1;
		while(n--)
		{
			scanf("%s%u", str, &v);
			if(str[0]=='M')
			{
				a *= v;
				if(a >= m) a &= M;
			}
		}
		g = gcd(a, m);
		printf("%u\n", m/g);
	}
	return 0;
}
