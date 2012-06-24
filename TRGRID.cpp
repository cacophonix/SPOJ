/*
USER: zobayer
TASK: TRGRID
ALGO: ad-hoc
*/

#include <stdio.h>

int main()
{
	int t, r, c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&r,&c);
		if(c>=r && r&1) printf("R\n");
		else if(c>=r && !(r&1)) printf("L\n");
		else if(c&1) printf("D\n");
		else printf("U\n");
	}
	return 0;
}
