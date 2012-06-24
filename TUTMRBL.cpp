/*
USER: zobayer
TASK: TUTMRBL
ALGO: math, prime
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>
using namespace std;

#define MAX 10036224
#define LMT 3168
#define LEN 666842

unsigned flag[MAX>>6];
unsigned primes[LEN], prlen;
unsigned fact[100][2];

#define ifc(n) (flag[n>>6]&(1<<((n>>1)&31)))
#define isc(n) (flag[n>>6]|=(1<<((n>>1)&31)))

void sieve()
{
	unsigned i, j, k;
	for(i=3; i<LMT; i+=2)
		if(!ifc(i))
			for(j=i*i,k=i<<1; j<MAX; j+=k)
				isc(j);
	primes[0] = 2;
	for(i=3,j=1; i<MAX; i+=2)
		if(!ifc(i))
			primes[j++] = i;
	prlen = j;
}

unsigned factor(unsigned n)
{
	unsigned i, k;
	for(i=k=0; i<prlen && primes[i]*primes[i]<=n; i++)
	{
		if(n % primes[i] == 0)
		{
			fact[k][0] = primes[i];
			fact[k][1] = 0;
			while(n % primes[i] == 0)
			{
				n /= primes[i];
				fact[k][1]++;
			}
			k++;
		}
	}
	if(n>1)
	{
		fact[k][0] = n;
		fact[k][1] = 1;
		k++;
	}
	return k;
}

unsigned nways(unsigned factorlen)
{
	unsigned res = 1, i;
	for(i=0; i<factorlen; i++)
		res *= (fact[i][1]+1);
	return ((res+1) >> 1);
}

int main()
{
	unsigned n, factorlen, ways, i, j, f;
	sieve();
	while(scanf("%u", &n)==1 && n)
	{
		factorlen = factor(n);
		ways = nways(factorlen);
		printf("%u", n);
		for(i=f=0; i<factorlen; i++)
			for(j=0; j<fact[i][1]; j++,f++)
				printf(" %c %u", (f?'*':'='),fact[i][0]);
		printf("\n");
		printf("With %u marbles, %u different rectangles can be constructed.\n", n, ways);
	}
	return 0;
}
