/*
USER: zobayer
TASK: UJ
ALGO: ad-hoc
*/

#include <ios>
#define i64 unsigned long long

int main()
{
	int d, i, j, k;
	i64 n, c, r[555], a, m=1000000000000000LL, t;
	while(scanf("%llu%d",&n,&d)==2&&(n||d))
	{
		for(i=k=r[0]=1;i<=d;i++)
		{
			for(j=c=0;j<k||c;j++)
			{
				t = ((j<k)?r[j]:0)*n;
				r[j] = (t+c)%m;
				c = (t+c)/m;
			}
			k = j;
		}
		printf("%llu",r[--k]);
		for(--k;k>=0;k--) printf("%015llu",r[k]);
		printf("\n");
	}
	return 0;
}
