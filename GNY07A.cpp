/*
USER: zobayer
TASK: GNY07A
ALGO: ad-hoc
*/

#include <stdio.h>

int main()
{
	char word[100];
	int t, n, x;
	for(scanf("%d", &t), x=1; x<=t; x++)
	{
		scanf("%d%s", &n, word);
		word[n-1] = 0;
		printf("%d %s%s\n",x,word,&word[n]);
	}
	return 0;
}
