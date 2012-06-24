/*
USER: zobayer
TASK: MRECAMAN
ALGO: ad-hoc
*/

#include <stdio.h>

const int MAX = 500000, RNG = 5000000;

bool flag[RNG+1];
int a[MAX+1];

int main()
{
	int i, n, p;
	for(i=1; i<=MAX; i++)
	{
		p = a[i-1];
		if(p > i && !flag[p-i]) a[i] = p - i;
		else a[i] = p + i;
		flag[a[i]] = 1;
	}
	while(scanf("%d", &n)==1 && n!=-1) printf("%d\n", a[n]);
	return 0;
}
