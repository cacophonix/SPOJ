/*
USER: zobayer
TASK: DANGER
ALGO: math, josephus
*/

#include <stdio.h>

int f(int n)
{
	if((n & (n-1)) == 0) return 1;
	if((n & 1) == 0) return (f(n>>1)<<1)-1;
	return (f((n-1)>>1)<<1)+1;
}

int main()
{
	int n, t[7] = {1,10,100,1000,10000,100000,1000000};
	char str[10];
	while(scanf("%s", str)==1)
	{
		n = ((str[0]-'0')*10 + str[1]-'0')*t[str[3]-'0'];
		if(!n) break;
		printf("%d\n", f(n));
	}
	return 0;
}
