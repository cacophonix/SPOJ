/*
USER: zobayer
TASL: CANTON
ALGO: math
*/

#include <stdio.h>
#include <math.h>

int main()
{
	int n, p, d, t;
	for(scanf("%d",&t);t;t--)
	{
		scanf("%d",&n);
		d = (int)(ceil((sqrt(8*n+1)-1)/2)+10e-8);
		p = d*(d+1)/2 - n;
		printf("TERM %d IS ",n);
		if(d&1) printf("%d/%d\n",1+p,d-p);
		else printf("%d/%d\n",d-p,1+p);
	}
	return 0;
}


