/*
USER: zobayer
TASK: NSTEPS
ALGO: ad-hoc
*/

#include <ios>

int main()
{
	int n, x, y, t;
	for(scanf("%d", &t); t; t--)
	{
		scanf("%d %d", &x, &y);
		if(x==y || x==y+2) printf("%d\n", x + y - (int)(x&1));
		else printf("No Number\n");
	}
	return 0;
}
