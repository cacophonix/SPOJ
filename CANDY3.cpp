/*
USER: zobayer
TASK: CANDY3
ALGO: ad-hoc
*/

#include <stdio.h>

#define i64 long long
#define FS "%lld"

int main()
{
	int t, n, i;
	i64 s, a;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		s = 0;
		for(i=0;i<n;i++)
		{
			scanf(FS,&a);
			s += a;
			if(s >= n) s %= (i64)n;
		}
		if(s == 0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
