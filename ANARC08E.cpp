/*
USER: zobayer
TASK: ANARC08E
ALGO: math
*/

#include <cstdio>
#include <algorithm>
using namespace std;

// logic (a+b)! / (a!*b!)

int main()
{
	int a, b, d, m, h, l, i, j;
	while(scanf("%d %d", &a, &b)==2 && a+b>=0)
	{
		d = max(a, b);
		m = min(a, b);
		h = l = 1;
		for(i=d+1, j=1; i<=a+b; i++, j++)
		{
			l *= i;
			h *= j;
			if(l % h == 0)
			{
				l /= h;
				h = 1;
			}
		}
		//printf("%d\n", l);
		if(l == a+b) printf("%d+%d=%d\n", a, b, a+b);
		else printf("%d+%d!=%d\n", a, b, a+b);
	}
	return 0;
}
