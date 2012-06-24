/*
USER: zobayer
TASK: FCTRL
ALGO: math
*/

#include <stdio.h>

int main()
{
	int t, n, count;
	for(scanf("%d",&t);t;t--)
	{
		scanf("%d",&n);
		count = 0;
		while(n)
		{
			count += n/5;
			n /= 5;
		}
		printf("%d\n",count);
	}
	return 0;
}

