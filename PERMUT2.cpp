/*
USER: zobayer
TASK: PERMUT2
ALGO: ad-hoc
*/

#include <stdio.h>

#define MAX 100001

int main()
{
	int a[MAX], n, i, cnt;
	while(scanf("%d", &n)==1 && n)
	{
		for(i=0; i<n; i++) scanf("%d", &a[i]);
		for(i=0, cnt=0; i<n; i++)
			if(a[a[i]-1]==i+1)
				cnt++;
		if(cnt==n) printf("ambiguous\n");
		else printf("not ambiguous\n");
	}
	return 0;
}
