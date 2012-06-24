/*
USER: zobayer
TASK: MKLABELS
ALGO: counting
*/

#include <stdio.h>

int ans[] = {0,1,1,3,16,125,1296,16807,262144,4782969,100000000};

int main()
{
	int n, test=1;
	while(scanf("%d", &n)==1 && n)
		printf("Case %d, N = %d, # of different labelings = %d\n",test++,n,ans[n]);
	return 0;
}
