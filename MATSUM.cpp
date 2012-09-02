/*
USER: zobayer
TASK: MATSUM
ALGO: binary indexed tree
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <ios>
#include <cstring>
using namespace std;

#define MAX 1025

int bit[MAX][MAX];

void update(int n, int x, int y, int v)
{
	int y1;
	while(x <= n)
	{
		y1 = y;
		while(y1 <= n)
		{
			bit[x][y1] += v;
			y1 += (y1 & -y1);
		}
		x += (x & -x);
	}
}

int readsum(int n, int x, int y)
{
	int v = 0, y1;
	while(x > 0)
	{
		y1 = y;
		while(y1 > 0)
		{
			v += bit[x][y1];
			y1 -= (y1 & -y1);
		}
		x -= (x & -x);
	}
	return v;
}

void process(int n)
{
	int x1, x2, y1, y2;
	int v1, v2, v3, v4, val;
	memset(bit, 0, sizeof bit);
	char com[5];
	while(scanf("%s", com)==1)
	{
		if(!strcmp(com,"END")) break;
		if(!strcmp(com,"SUM"))
		{
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			v1 = readsum(n, x1, y1);
			v2 = readsum(n, x2+1, y2+1);
			v3 = readsum(n, x2+1, y1);
			v4 = readsum(n, x1, y2+1);
			printf("%d\n", v1-v3-v4+v2);
		}
		else
		{
			scanf("%d %d %d", &x1, &y1, &val);
			v1 = readsum(n, x1+1, y1+1);
			v2 = readsum(n, x1, y1);
			v3 = readsum(n, x1, y1+1);
			v4 = readsum(n, x1+1, y1);
			update(n, x1+1, y1+1, val-(v1-v3-v4+v2));
		}
	}
}

int main()
{
	int n, t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		process(n);
		printf("\n");
	}
	return 0;
}

