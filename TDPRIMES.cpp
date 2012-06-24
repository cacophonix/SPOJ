/*
USER: zobayer
TASK: TDPRIMES
ALGO: math, prime
*/

#include <cstdio>

#define MAX 100000000
#define LMT 10000

int flag[MAX>>6];

#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31)))

void sieve()
{
	int i, j, k;
	for(i=3; i<LMT; i+=2)
		if(!ifc(i))
			for(j=i*i,k=i<<1; j<MAX; j+=k)
				isc(j);
	j = k = 1;
	printf("2\n");
	for(i=3; i<MAX; i+=2)
	{
		if(!ifc(i))
		{
			j++;
			if(j-k==100)
			{
				printf("%d\n", i);
				k = j;
			}
		}
	}
}

int main()
{
	sieve();
	return 0;
}
