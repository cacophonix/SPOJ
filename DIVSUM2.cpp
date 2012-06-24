/*
USER: zobayer
TASK: DIVSUM2
ALGO: math, prime
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>
#include <cmath>
using namespace std;

#define sq(x) ((x)*(x))
#define i64 unsigned long long
#define MAX 100000000
#define LMT 10000

unsigned flag[MAX/64];
unsigned primes[5761460], total;

#define chkC(n) (flag[n>>6]&(1<<((n>>1)&31)))
#define setC(n) (flag[n>>6]|=(1<<((n>>1)&31)))

void sieve()
{
	unsigned i, j, k;
	flag[0]|=0;
	for(i=3;i<LMT;i+=2)
		if(!chkC(i))
			for(j=i*i,k=i<<1;j<MAX;j+=k)
				setC(j);
	primes[(j=0)++] = 2;
	for(i=3;i<MAX;i+=2)
		if(!chkC(i))
			primes[j++] = i;
	total = j;
}

i64 power(i64 n, unsigned p)
{
	i64 x=1, y=n;
	while(p > 0)
	{
		if(p&1) x *= y;
		y *= y;
		p >>= 1;
	}
	return x;
}

inline void update(i64 &phi1, i64 n, unsigned p)
{
	if(p==1) phi1 *= (n+1);
	else phi1 *= ((power(n,p+1)-1)/(n-1));
}

void factor(i64 n, i64 &phi1)
{
	unsigned i, v;
	i64 t;
	phi1 = 1;
	for(i=0, t=primes[i]; i<total && t*t <= n; t = primes[++i])
	{
		if(n % t == 0)
		{
			v = 0;
			while(n % t == 0)
			{
				v++;
				n /= t;
			}
			update(phi1, primes[i], v);
		}
	}
	if(n>1) update(phi1, n, 1);
}

int main()
{
	int t, x;
	i64 n, phi1;
	sieve();
	scanf("%d", &t);
	for(x=1; x<=t; x++)
	{
		scanf("%llu", &n);
		factor(n, phi1);
		printf("%llu\n",phi1-n);
	}
	return 0;
}

