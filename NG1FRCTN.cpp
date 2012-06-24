/*
USER: zobayer
TASK: NG1FRCTN
ALGO: math, gcd, recursion
*/

#include <stdio.h>

#define i64 long long

i64 gcd(i64 a, i64 b)
{
	if(!b) return a;
	return gcd(b, a%b);
}

void swap(i64 &a, i64 &b)
{
	i64 t = a;
	a = b;
	b = t;
}

void f(i64 n, i64 &l, i64 &h)
{
	if(n==1) l = h = 1;
	else
	{
		f(n>>1, l, h);
		(n&1)? l += h : h += l;
	}
}

int main()
{
	i64 a, b, l1, l2, h1, h2, g;
	while(scanf("%lld%lld", &a, &b)==2 && (a+b))
	{
		if(a > b) swap(a, b);
		f(a, l1, h1);
		f(b, l2, h2);
		g = gcd(l1, h2);
		printf("%lld/%lld\n", l1/g, h2/g);
	}
	return 0;
}

