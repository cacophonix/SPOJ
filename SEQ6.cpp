/*
USER: zobayer
TASK: SEQ6
ALGO: math
*/

#include <cstdio>
#include <cmath>
using namespace std;

#define LEN 480
#define MAX 3364
#define LMT 58
#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31)))

int flag[MAX>>6], primes[LEN], total;

void sieve()
{
	int i, j, k;
	for(i=3; i<LMT; i+=2)
		if(!ifc(i))
			for(j=i*i,k=i<<1; j<MAX; j+=k)
				isc(j);
	for(i=3,j=0; i<MAX; i+=2)
		if(!ifc(i))
			primes[j++] = i;
	total = j;
}

int d(int n)
{
	int ret, root, cnt, i;
	while(!(n&1)) n >>= 1;
	root = (int)sqrt((double)n);
	for(i=0,ret=1; primes[i]<=root; i++)
	{
		if(n % primes[i] == 0)
		{
			cnt = 0;
			while(n % primes[i] == 0)
			{
				n /= primes[i];
				cnt++;
			}
			ret *= ++cnt;
			root = (int)sqrt((double)n);
		}
	}
	if(n>2) ret <<= 1;
	return ret;
}

int main()
{
	int n;
	sieve();
	while(scanf("%d", &n)==1 && n) printf("%d\n", d(n)<<1);
	return 0;
}
