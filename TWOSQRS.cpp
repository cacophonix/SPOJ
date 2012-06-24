/*
USER: zobayer
TASK: TWOSQRS
ALGO: math, prime
*/

#include <cstdio>
using namespace std;

#define i64 long long
#define MAXPR 78500
#define MAX 1000000
#define LMT 1000
#define sq(x) ((x)*(x))

unsigned flag[MAX/64], total;
i64 primes[MAXPR];

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

int isPossible(i64 n)
{
	int i, cnt;
	for(i=0; sq(primes[i]) <= n; i++)
	{
		if(n%primes[i]==0)
		{
			cnt = 0;
			while(n%primes[i]==0)
			{
				n /= primes[i];
				cnt++;
			}
			if((primes[i]-3)%4==0 && (cnt&1)) return 0;
		}
	}
	if(n>1 && (n-3)%4==0) return 0;
	return 1;
}

int main()
{
	int test;
	i64 n;
	char stat[2][5] = {"No","Yes"};
	sieve();
	for(scanf("%d", &test); test; test--)
	{
		scanf("%lld", &n);
		printf("%s\n",stat[isPossible(n)]);
	}
	return 0;
}
