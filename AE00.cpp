/*
USER: zobayer
TASK: AE00
ALGO: math
*/

#include <cstdio>

#define MAX 10000
#define LMT 100
#define LEN 1230

unsigned flag[MAX>>6];
unsigned primes[LEN], total;

#define ifc(n) (flag[n>>6]&(1<<((n>>1)&31)))
#define isc(n) (flag[n>>6]|=(1<<((n>>1)&31)))

void sieve()
{
	unsigned i, j, k;
	for(i=3; i<LMT; i+=2)
		if(!ifc(i))
			for(j=i*i, k=i<<1; j<MAX; j+=k)
				isc(j);
	for(i=3, j=0; i<MAX; i+=2)
		if(!ifc(i))
			primes[j++] = i;
	total = j;
}

unsigned res(unsigned n)
{
	unsigned i, cnt, ret = 1;
	if(n==1) return 1;
	if(n==2) return 1;
	if(!(n&1))
	{
		cnt = 0;
		while(!(n&1))
		{
			cnt++;
			n >>= 1;
		}
		ret *= cnt+1;
	}
	else if(!ifc(n)) return 1;
	for(i=0; i < total && primes[i]*primes[i] <= n; i++)
	{
		if(n % primes[i] == 0)
		{
			cnt = 0;
			while(n % primes[i] == 0)
			{
				n /= primes[i];
				cnt++;
			}
			ret *= cnt+1;
		}
	}
	if(n>1) ret <<= 1;
	return ((ret+1)>>1);
}

int main()
{
	unsigned n, i, ans = 0;
	sieve();
	scanf("%u", &n);
	for(i=1; i<=n; i++)
		ans += res(i);
	printf("%u\n", ans);
	return 0;
}
