/*
USER: zobayer
TASK: ETF
ALGO: math, euler totient
*/

#include<stdio.h>

#define MAX 1000001

unsigned phi[MAX];

void ETF()
{
	unsigned i, j;
	phi[1] = 1;
	for(i=2; i<MAX; i++)
	{
		if(!phi[i])
		{
			phi[i] = i-1;
			for(j=(i<<1); j<MAX; j+=i)
			{
				if(!phi[j]) phi[j] = j;
				phi[j] = phi[j]/i*(i-1);
			}
		}
	}
}

int main()
{
	unsigned t, n;
	ETF();
	for(scanf("%d",&t);t;t--)
	{
		scanf("%d",&n);
		printf("%d\n",phi[n]);
	}
	return 0;
}
