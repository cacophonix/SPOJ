/*
USER: zobayer
TASK: ACT
ALGO: ad-hoc
*/

#include <stdio.h>
#include <string.h>

int main()
{
	char str[50005];
	int t, n;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %s", &n, str);
		printf("%c\n", str[strlen(str)-1]);
	}
	return 0;
}
