/*
USER: zobayer
TASK: CANDY
ALGO: ad-hoc
*/

#include <ios>

int main()
{
	int a[10001], n, i, avr, sum, total;
	while(scanf("%d", &n) == 1 && n > 0)
	{
		for(i=sum=0; i < n; i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
		}
		if(sum % n == 0)
		{
			avr = sum / n;
			for(i=total=0; i < n; i++)
				if(a[i] < avr)
					total += avr - a[i];
			printf("%d\n", total);
		}
		else printf("-1\n");
	}
	return 0;
}

