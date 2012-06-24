/*
USER: zobayer
TASK: NG0FRCTN
ALGO: binary search
*/

#define u64 unsigned long long
#define _CRT_SECURE_NO_WARNINGS 1
#define DEBUG if(0)

#include <iostream>
using namespace std;

void search(u64 L, u64 R, u64 T, u64 &p, u64 &q)
{
	u64 M;
	while(L<R)
	{
		M = (L+R) >> 1;
		if(T<=M)
		{
			q = p + q;
			R = M;
		}
		else
		{
			p = p + q;
			L = M + 1;
		}
	}
}

int main()
{
	u64 n, a[40] = {1}, total, target, p, q;
	int k, i;
	for(k=1; a[k-1] < 10000000000ULL; k++)
		a[k] = a[k-1] + (1ULL << k);
	DEBUG for(i=0; i<k; i++) printf("%llu\n", a[i]);
	while(scanf("%llu", &n)==1 && n)
	{
		for(i=0; i<k && a[i]<n; i++);
		DEBUG printf("At level %d\n", i);
		total = 1ULL << i;
		DEBUG printf("total pints %llu\n", total);
		target = total - a[i] + n;
		DEBUG printf("Target position %llu\n", target);
		p = q = 1ULL;
		search(1, total, target, p, q);
		printf("%llu/%llu\n", p, q);
	}
	return 0;
}
