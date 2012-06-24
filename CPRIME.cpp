/*
USER: zobayer
TASK: CPRIME
ALGO: math, prime
*/

#include <stdio.h>
#include <math.h>

#define MAX 100000000
#define LMT 10000
#define LEN 5761456

unsigned flag[MAX/64];
int a[LEN+10], total;

#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31)))

void sieve()
{
	int i, j, k;
	for(i=3; i<LMT; i+=2)
		if(!ifc(i))
			for(j=i*i,k=i<<1; j<MAX; j+=k)
				isc(j);
	a[0] = -1;
	a[1] = 2;
	for(i=3,j=2; i<MAX; i+=2)
		if(!ifc(i))
			a[j++] = i;
	total = j;
}

int BS(int st, int fn, int val)
{
    int mid;
    while(st <= fn)
    {
        if(val < a[st]) return st-1;
        if(val > a[fn]) return fn;
        mid = (st+fn) / 2;
        if(val == a[mid]) return mid;
        else if(val < a[mid]) fn = mid-1;
        else st = mid+1;
    }
    return total-1;
}

int main()
{
	sieve();
	int i, n;
	double x, p, r;
	while(scanf("%d", &n)==1 && n)
	{
		p = BS(0, total-1, n);
		x = n;
		r = ( fabs(p - x/log(x)) / p ) * 100.0;
		printf("%.1lf\n", r);
	}
	return 0;
}
