/*
USER: zobayer
TASK: QUALITY
ALGO: ad-hoc
*/

#include <stdio.h>

int main()
{
	int tp1, tp2, tp3, ap1, ap2, ap3, team = 1, total, cnt;
	while(scanf("%d %d %d %d %d %d", &tp1, &tp2, &tp3, &ap1, &ap2, &ap3)==6)
	{
		total = cnt = 0;
		if(tp1)
		{
			total += tp1 + 1200*(ap1-1);
			cnt++;
		}
		if(tp2)
		{
			total += tp2 + 1200*(ap2-1);
			cnt++;
		}
		if(tp3)
		{
			total += tp3 + 1200*(ap3-1);
			cnt++;
		}
		printf("team %d: %d, %d\n", team++, cnt, total);
	}
	return 0;
}
