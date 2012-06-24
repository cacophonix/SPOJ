/*
USER: zobayer
TASK: BEADS
ALGO: ad-hoc
*/

#include <stdio.h>
#include <string.h>

char str[10001];

int mycmp(int i, int j, int len)
{
	int k;
	for(k=0; k<len; k++, i++, j++)
	{
		if(i==len) i = 0;
		if(j==len) j = 0;
		if(str[i]!=str[j]) return str[i]-str[j];
	}
	return 0;
}

int main()
{
	int t, i, p, best, len;
	scanf("%d", &t);
	while(t--)
	{
		best = 0;
		scanf("%s", str);
		len = strlen(str);
		for(i=1; i<len; i++)
		{
			p = mycmp(best, i, len);
			if(p > 0) best = i;
		}
		printf("%d\n", best+1);
	}
	return 0;
}

