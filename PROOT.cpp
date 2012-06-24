/*
USER: zobayer
TASK: PROOT
ALGO: math, euler phi, sieve
*/

#define _CRT_SECURE_NO_WARNINGS 1
#define MAX 46656
#define LMT 216
#define PRLEN 4830
#define u64 long long

#include <iostream>
#include <cmath>
using namespace std;

int flag[MAX>>6];
int primes[PRLEN];
int total;
#define ifC(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isC(x) (flag[x>>6]|=(1<<((x>>1)&31)))

void sieve()
{
	int i, j, k;
	for(i=3; i<LMT; i+=2)
		if(!ifC(i))
			for(j=i*i,k=i<<1; j<MAX; j+=k)
				isC(j);
	primes[0] = 2;
	for(i=3, j=1; i<MAX; i+=2)
		if(!ifC(i))
			primes[j++] = i;
	total = j;
}

int ephi(int n, int *factor)
{
	int i, lmt = (int)sqrt(n), k = 0;
	for(i = 0; primes[i] <= lmt; i++)
	{
		if(n % primes[i]==0)
		{
			factor[k++] = primes[i];
			while(n % primes[i]==0) n /= primes[i];
			lmt = (int)sqrt(n);
		}
	}
	if(n>1) factor[k++] = n;
	return k;
}

int mod_exp(u64 b, int e, int m)
{
	u64 r = 1;
	while(e>0)
	{
		if(e&1) r = (r*b)%m;
		e >>= 1;
		b = (b*b)%m;
	}
	return (int)r;
}

int main()
{
	int m, n, t, i, j, p, phi, sz, factor[50];
	sieve();
	while(scanf("%d %d", &n, &t)==2 && n)
	{
		sz = ephi(phi=n-1, factor);
		for(i=0; i<t; i++)
		{
			scanf("%d", &m);
			for(j=0; j<sz; j++)
			{
				p = phi / factor[j];
				if(mod_exp(m, p, n)==1) break;
			}
			if(j==sz) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
