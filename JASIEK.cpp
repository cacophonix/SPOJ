/*
USER: zobayer
TASK: JASIEK
ALGO: simulation
*/

#include <stdio.h>

#define MAX 22222

int step[MAX], points, steps;
struct point { int x, y; } P[MAX];

void process()
{
	int x = 1, y = 1, i, prev = step[steps-1];
	for(i=points=0; i<steps; i++)
	{
		switch(step[i]+4*prev)
		{
		case 0: y += 2; break;
		case 1: P[points].x = x+1; P[points].y = y+1; points++;
			x -= 2; break;
		case 2: P[points].x = x+1; P[points].y = y+1; points++;
			P[points].x = x-1; P[points].y = y+1; points++;
			y -= 2; break;
		case 3: P[points].x = x+1; P[points].y = y-1; points++;
			x += 2; break;
		case 4: P[points].x = x+1; P[points].y = y+1; points++;
			y += 2; break;
		case 5: x -= 2; break;
		case 6: P[points].x = x-1; P[points].y = y+1; points++;
			y -= 2; break;
		case 7: P[points].x = x-1; P[points].y = y+1; points++;
			P[points].x = x-1; P[points].y = y-1; points++;
			x += 2; break;
		case 8: P[points].x = x-1; P[points].y = y-1; points++;
			P[points].x = x+1; P[points].y = y-1; points++;
			y += 2; break;
		case 9: P[points].x = x-1; P[points].y = y+1; points++;
			x -= 2; break;
		case 10:y -= 2; break;
		case 11:P[points].x = x-1; P[points].y = y-1; points++;
			x += 2; break;
		case 12:P[points].x = x+1; P[points].y = y-1; points++;
			y += 2; break;
		case 13:P[points].x = x+1; P[points].y = y-1; points++;
			P[points].x = x+1; P[points].y = y+1; points++;
			x -= 2; break;
		case 14:P[points].x = x-1; P[points].y = y-1; points++;
			y -= 2; break;
		case 15:x += 2; break;
		}
		prev = step[i];
	}
}

int getarea()
{
	int a = 0, i;
	P[points] = P[0];
	for(i=0; i<points; i++) a += P[i].x * P[i+1].y - P[i+1].x * P[i].y;
	return a/8;
}

int main()
{
	char str[5];
	while(scanf("%s", str)==1)
	{
		steps = 0;
		while(scanf("%s", str)==1 && str[0]!='K')
		{
			switch(str[0])
			{
			case 'N': step[steps] = 0; break;
			case 'W': step[steps] = 1; break;
			case 'S': step[steps] = 2; break;
			case 'E': step[steps] = 3; break;
			}
			steps++;
		}
		if(!steps) printf("1\n");
		else
		{
			process();
			printf("%d\n", getarea());
		}
	}
	return 0;
}
