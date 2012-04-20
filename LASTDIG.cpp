/*
USER: zobayer
TASK: LASTDIG
ALGO: pre-calculation
*/

#include <ios>

int main()
{
	int b, p, t, i, j, table[10][4];
	for(i=0; i<10; i++)
		for(j=table[i][0]=1; j<=4; j++)
			table[i][j&3] = (table[i][j-1]*i)%10;
	for(scanf("%d",&t); t; t--)
	{
		scanf("%d %d", &b, &p);
		if(!p) printf("1\n");
		else printf("%d\n", table[b%10][p&3]);
	}
	return 0;
}
