/*
USER: zobayer
TASK: ANARC05I
ALGO: simulation
*/

#include <stdio.h>

#define MAX 2002

int grid[MAX][MAX];
char str[MAX/2];

int main()
{
	int t = 1, i, cnt, x, y;
	while(scanf("%s", str)==1)
	{
		if(str[0]=='Q') break;
		for(i=cnt=0,x=y=1001,grid[x][y]=t; str[i]!='Q'; i++)
		{
			switch(str[i])
			{
			case 'U': y += 1; break;
			case 'D': y -= 1; break;
			case 'R': x += 1; break;
			case 'L': x -= 1; break;
			}
			if(grid[x][y]==t) cnt++;
			else grid[x][y] = t;
		}
		printf("%d\n", cnt);
		t++;
	}
	return 0;
}
