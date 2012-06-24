/*
USER: zobayer
TASK: MDIGITS
ALGO: recursion
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

int p10[] = {1,10,100,1000,10000,100000,1000000,10000000,100000000};

void calc(int num, int p, int cnt[], int f)
{
	int n, i;
	n = num / p10[p];
	for(i=0;i<n;i++)
		cnt[i] += p10[p];
	cnt[i] += num % p10[p] + 1;
	if(f) cnt[0] -= p10[p];
	if(p==0) return;
	for(i=0;i<10;i++)
		cnt[i] += n*p*p10[p-1];
	if(f) cnt[0] -= (p10[p]-1)/9;
	calc(num % p10[p], p-1, cnt, 0);
}

int main()
{
	int p1, p2, i, a, b, c;
	while(scanf("%d%d",&a,&b)==2 && a+b)
	{
		if(a>b)
		{
			c = a;
			a = b;
			b = c;
		}
		a--;
		int cnt1[10] = {1};
		int cnt2[10] = {1};
		if(a)
		{
			p1 = (int)floor(log10(a));
			calc(a, p1, cnt1, 1);
		}
		p2 = (int)floor(log10(b));
		calc(b, p2, cnt2, 1);
		printf("%d",cnt2[0]-cnt1[0]);
		for(i=1; i<10; i++) printf(" %d",cnt2[i]-cnt1[i]);
		printf("\n");
	}
	return 0;
}
