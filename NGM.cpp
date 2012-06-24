/*
USER: zobayer
TASK: NGM
ALGO: ad-hoc
*/

#include <ios>

int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		if(n%10) printf("1\n%d\n",n%10);
		else printf("2\n");
	}
	return 0;
}
