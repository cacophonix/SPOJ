/*
USER: zobayer
TASK: LCMSUM
ALGO: math
*/

#include <cstdio>
using namespace std;

#define MAX 1000000
#define LMT 1000

int pfactor[MAX+10];
long long int mcount[MAX+10], mval[MAX+10];

int main() 
{
	mval[1] = mcount[1] = 1;
	for(int i=1; i<=MAX; i++) pfactor[i] = i;
	for(int i=2; i<=LMT; i++)
		if(pfactor[i]==i)
			for(int j=i<<1; j<=MAX; j+=i)
				if(pfactor[j]==j)
					pfactor[j] = i;
	for(int i=2, k; i<=MAX; i++)
	{
		k = i;
		mcount[i] = 1;
		while(k%pfactor[i]==0)
		{
			mcount[i] *= pfactor[i];
			k /= pfactor[i];
		}
	}
	for(int i=2; i<=MAX; i++)
		mval[i] = mval[i/pfactor[i]]+mcount[i]*(mcount[i]-mcount[i]/pfactor[i])*mval[i/mcount[i]];
	int t, n;
	long long res;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		res = mval[n]-1;
		if(res&1) res *= (n>>1);
		else res>>=1, res*=n;
		res += n;
		printf("%lld\n", res);
	}
	return 0;
}
