/*
USER: zobayer
TASK: PALACE
ALGO: math
*/

#include <stdio.h>

int main()
{
	int t, power[250], i, n;
	power[0] = 1;
	for(i=1; i<204; i++)
		power[i] = (power[i-1]<<1) % 98777;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n); n--;
		printf("%d\n", power[((n%204)*(n%204))%204]);
	}
	return 0;
}
