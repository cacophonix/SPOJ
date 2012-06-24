/*
USER: zobayer
TASK: TREX
ALGO: ad-hoc
*/

#include <stdio.h>

int main()
{
	int t, I, D, C, i, m, v;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d%d", &I, &D, &C);
		if(I <= D) printf("0\n");
		else if(I <= C) printf("%d\n", I-D);
		else
		{
			for(i=1; i<=D; i++)
			{
				if(I <= C)
				{
					I = I - D + i - 1;
					break;
				}
				else
				{
					m = I % C;
					v = I / C;
					if(m < 2) I = v*C - 2*v + 1;
					else I = v*C - 2*v + m - 1;
				}
			}
			if(I < 0) I = 0;
			printf("%d\n", I);
		}
	}
	return 0;
}
